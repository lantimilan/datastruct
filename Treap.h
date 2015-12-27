// Treap.h
#include <iostream>

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
    TreapNode(T val, int prio) : key(val), priority(prio), left(0), right(0)
        {}
    void print();
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
    // rotate up to fix priority
    if (prev->priority < node->priority) {
        // done
    } else {
        // 1. grandparent is null or grandparent has smaller priority
        // 2. grandparent is not null and grandparent has larger priority
    }
}

template<class T>
bool Treap<T>::erase(T val) {
    return true;
}

template<class T>
void Treap<T>::print() {
    root->print();
}

template<class T>
void TreapNode<T>::print() {
    std::cout << "(" << key << "," << priority << ")" << std::endl;
    if (left) {
        left->print();
    } else {
        std::cout << "null" << std::endl;
    }
    if (right) {
        right->print();
    } else {
        std::cout << "null" << std::endl;
    }
}

template<class T>
int Treap<T>::getPriority() {
    return 100;
}
