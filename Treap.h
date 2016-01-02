// Treap.h
#include <iostream>
#include <string>

int N = 100;

template<class T>
class TreapNode;

template<class T>
class Treap {
    TreapNode<T>* root;
    int getPriority();
public:
    Treap() : root(0) {}
    bool insert(T val);
    bool erase(T val);
    void print();
    bool validate();  // check key property and priority property
};

template<class T>
class TreapNode {
    T key;
    int priority;
    TreapNode<T> *left, *right, *parent;
public:
    TreapNode(T val, int prio) : key(val), priority(prio), left(0),
        right(0), parent(0) {}
    void print(int level);  // level of indentation
    friend class Treap<T>;
};

template<class T>
bool Treap<T>::insert(T val) {
    TreapNode<T> *node = new TreapNode<T>(val, getPriority());
    if (root == 0) {
        root = node;
        return true;
    }
    TreapNode<T> *curr = root;
    TreapNode<T> *prev;
    while (curr != 0) {
        prev = curr;
        if (curr->key < val) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    if (prev->key < val) {
        prev->right = node;
    } else {
        prev->left = node;
    }
    node->parent = prev;
    // rotate up to fix priority
    while (node->parent != 0 && node->priority < node->parent->priority) {
        TreapNode<T>* parent = node->parent;
        if (parent->parent) {
            if (parent == parent->parent->left) {
                parent->parent->left = node;
            } else {
                parent->parent->right = node;
            }
        }
        node->parent = parent->parent;
        parent->parent = node;
        if (node == parent->left) {
            TreapNode<T>* rchild = node->right;
            parent->left = rchild;
            if (rchild) {
                rchild->parent = parent;
            }
            node->right = parent;
        } else {
            TreapNode<T>* lchild = node->left;
            parent->right = lchild;
            if (lchild) {
                lchild->parent = parent;
            }
            node->left = parent;
        }
        /*
        std::cout << std::endl;
        std::cout << "temp\n";
        print();
        std::cout << std::endl;
        */
    }
    if (node->parent == 0) {
        root = node;
    }
}

template<class T>
bool Treap<T>::erase(T val) {
    return true;
}

template<class T>
void Treap<T>::print() {
    root->print(0);
}

template<class T>
void TreapNode<T>::print(int level) {
    std::string prefix = std::string(level*4, ' ');
    std::string nextPrefix = std::string((level+1)*4, ' ');
    std::cout << prefix;
    std::cout << "(" << key << "," << priority << ")" << std::endl;
    if (left) {
        left->print(level+1);
    } else {
        std::cout << nextPrefix << "null" << std::endl;
    }
    if (right) {
        right->print(level+1);
    } else {
        std::cout << nextPrefix << "null" << std::endl;
    }
}

template<class T>
int Treap<T>::getPriority() {
    return N--;
    //return 100;
}
