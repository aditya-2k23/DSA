#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(TreeNode *root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderASCII(TreeNode *root) {
    // print the ascii values of the int data in the root
    if (root == nullptr)
        return;

    inorderASCII(root->left);
    if (root->data >= 0 && root->data <= 127) {
        cout << (char)root->data << " ";
    } else {
        cout << "? ";
    }
    inorderASCII(root->right);
}

void levelOrder(TreeNode *root) {
    if (root == nullptr)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        } else {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

int main() {
    TreeNode *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // levelOrder(root);

    inorder(root);
    cout << endl;
    inorderASCII(root);

    return 0;
}
