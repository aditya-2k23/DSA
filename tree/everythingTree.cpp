#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int data) {
    if (root == nullptr) {
        TreeNode *newNode = new TreeNode(data);
        root = newNode;
        return root;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

TreeNode *search(TreeNode *root, int data) {
    if (root == nullptr || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int findMinValue(TreeNode *root) {
    TreeNode *current = root;

    while (current && current->left)
        current = current->left;

    return current->data;
}

int findMaxValue(TreeNode *root) {
    TreeNode *current = root;

    while (current && current->right)
        current = current->right;

    return current->data;
}

TreeNode *deleteNode(TreeNode *root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == nullptr) {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *temp = root->right;
        while (temp->left)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void preOrder(TreeNode *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int n;
    cin >> n;

    TreeNode *root = nullptr;
    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        root = insert(root, el);
    }

    cout << "In-Order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << endl;

    cout << "Min Value: " << findMinValue(root) << endl;
    cout << "Max Value: " << findMaxValue(root) << endl;

    cout << "Enter a value to search: ";
    int x;
    cin >> x;

    TreeNode *result = search(root, x);
    if (result != nullptr)
        cout << "Found!\n";
    else
        cout << "Not Found!\n";

    cout << "Enter a value to delete: ";
    int y;
    cin >> y;

    root = deleteNode(root, y);

    cout << "In-Order Traversal: ";
    inOrder(root);

    return 0;
}
