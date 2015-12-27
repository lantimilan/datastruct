# datastruct
Treap

Each node has (key, priority) pair, and the tree has the following structure:
1. parent.priority < child.priority
2. left.key < parent.key < right.key

Property:
1. Given a set of node with distinct key, distinct priority, then the treap is
unique.
Proof: n = 1 is easy. Now consider n = k nodes, the root is the node with
minimum priority, and the remaining nodes are partitioned into two sets, the
ones with smaller key forming left subtree and the one with larger key forming
right subtree. And we apply induction hypothesis on them to complete the proof.

Operations:
1. insert(int val)
First we do normal BST insertion to find the parent that will have newnode as
its child. Now we have three cases:
1.1 newnode.priority > parent.priority. We are done.
1.2 newnode.priority < parent.priority
1.2.1 newnode.priority < grandparent.priority, right rotation, and recurse.
1.2.2 newnode.priority > grandparent.priority, left rotation, and done.

Because of property 1, we know that as long as the final treap is a valid treap,
we have constructed the only treap that is valid. In other words, there is no
valid treap that is better.

