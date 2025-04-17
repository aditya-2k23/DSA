// ! What is avl tree
// * AVL tree is a self-balancing binary search tree in which each node maintains an extra information called balance factor whose value is either -1, 0 or +1.

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val, height;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), height(1), left(NULL), right(NULL) {}
};

int height(TreeNode *root) {
    return root ? root->height : 0;
}

int balanceFactor(TreeNode *root) {
    return height(root->left) - height(root->right);
}

void updateHeight(TreeNode *root) {
    root->height = 1 + max(height(root->left), height(root->right));
}

TreeNode *rotateRight(TreeNode *root) {
    TreeNode *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

TreeNode *rotateLeft(TreeNode *root) {
    TreeNode *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

TreeNode *rebalance(TreeNode *root) {
    updateHeight(root);

    if (balanceFactor(root) == 2) {
        if (balanceFactor(root->left) == -1)
            root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balanceFactor(root) == -2) {
        if (balanceFactor(root->right) == 1)
            root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

TreeNode *insert(TreeNode *root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return rebalance(root);
}

void levelOrder(TreeNode *root) {
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == NULL) {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        } else {
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

int main() {
    TreeNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 70);
    root = insert(root, 5);

    levelOrder(root);

    return 0;
}
