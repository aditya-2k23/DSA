#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL)
        return new TreeNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inOrder(TreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }
}

void preOrder(TreeNode *root) {
    if (root != NULL) {
        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
}

int main() {
    int n;
    cin >> n;

    TreeNode *root = NULL;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}
