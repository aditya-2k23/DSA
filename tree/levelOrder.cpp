#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

void reverseLevelOrder(TreeNode *root) {
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    stack<TreeNode *> s;

    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        s.push(node);
        if (node->right)
            q.push(node->right);
        if (node->left)
            q.push(node->left);
    }

    while (!s.empty()) {
        cout << s.top()->val << " ";
        s.pop();
    }
}

TreeNode *buildTree(TreeNode *root) {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new TreeNode(data);

    cout << "Enter left child of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

int main() {
    TreeNode *root = NULL;

    root = buildTree(root);

    cout << "Level Order Traversal: \n";
    levelOrder(root);

    cout << "\nReverse Level Order Traversal: \n";
    reverseLevelOrder(root);

    return 0;
}
