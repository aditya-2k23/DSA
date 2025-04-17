#include <iostream>
using namespace std;

// ! What is B-Tree?
// * A B-Tree is a self-balancing search tree. In most of the other self-balancing search trees (like AVL and Red-Black Trees), it is assumed that everything is in main memory. To make the discussion simpler, we will consider that the disk is represented as an array of blocks. There is a fixed size B of block. A node of a B-Tree is represented as follows. The block size is kept small enough so that one node is stored in one block.

struct BTreeNode {
    int *keys, t, n;
    BTreeNode **C;
    bool leaf;
};

// ! Properties of B-Tree
// * 1. All leaves are at the same level.
// * 2. A B-Tree is defined by the term minimum degree 't'. The value of t depends upon disk block size.
// * 3. Every node except root must contain at least t-1 keys. Root may contain minimum 1 key.
// * 4. All nodes (including root) may contain at most 2t-1 keys.
// * 5. Number of children of a node is equal to the number of keys in it plus 1.
// * 6. All keys of a node are sorted in increasing order. The child between two keys k1 and k2 contains all keys in the range from k1 and k2.
// * 7. B-Tree grows and shrinks from the root which is unlike Binary Search Tree. Binary Search Trees grow downward and also shrink from downward.

// ! Insertion in B-Tree
BTreeNode *splitChild(BTreeNode *x, int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode;
    z->leaf = y->leaf;
    z->n = x->t - 1;
    z->keys = new int[2 * x->t - 1];
    z->C = new BTreeNode *[2 * x->t];
    for (int j = 0; j < x->t - 1; j++)
        z->keys[j] = y->keys[j + x->t];
    if (!y->leaf) {
        for (int j = 0; j < x->t; j++)
            z->C[j] = y->C[j + x->t];
    }
    y->n = x->t - 1;
    for (int j = x->n; j >= i + 1; j--)
        x->C[j + 1] = x->C[j];
    x->C[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--)
        x->keys[j + 1] = x->keys[j];
    x->keys[i] = y->keys[x->t - 1];
    x->n = x->n + 1;

    return x;
}

void insertNonFull(BTreeNode *x, int k) {
    int i = x->n - 1;
    if (x->leaf) {
        while (i >= 0 && k < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n = x->n + 1;
    } else {
        while (i >= 0 && k < x->keys[i])
            i--;
        i++;
        if (x->C[i]->n == 2 * x->t - 1) {
            x = splitChild(x, i, x->C[i]);
            if (k > x->keys[i])
                i++;
        }
        insertNonFull(x->C[i], k);
    }
}

BTreeNode *insert(BTreeNode *root, int k) {
    if (root == nullptr) {
        root = new BTreeNode;
        root->keys = new int[2 * root->t - 1];
        root->keys[0] = k;
        root->n = 1;
        root->leaf = true;
        root->C = new BTreeNode *[2 * root->t];
        for (int i = 0; i < 2 * root->t; i++)
            root->C[i] = nullptr;
    } else {
        if (root->n == 2 * root->t - 1) {
            BTreeNode *s = new BTreeNode;
            s->keys = new int[2 * root->t - 1];
            s->C = new BTreeNode *[2 * root->t];
            s->leaf = false;
            s->n = 0;
            s->C[0] = root;
            s = splitChild(s, 0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(s->C[i], k);
            root = s;
        } else
            insertNonFull(root, k);
    }

    return root;
}

// TODO: Printing the B-Tree
void printTree(BTreeNode *root) {
    for (int i = 0; i < root->n; i++) {
        if (!root->leaf)
            printTree(root->C[i]);
        cout << root->keys[i] << " ";
    }
    if (!root->leaf)
        printTree(root->C[root->n]);
}

int main() {
    BTreeNode *root = nullptr;
    int n;
    cin >> n;

    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        root = insert(root, el);
    }

    printTree(root);

    return 0;
}
