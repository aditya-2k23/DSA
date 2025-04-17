// #include <iostream>
// using namespace std;

// // Circular Linked List

// struct Node {
//     int data;
//     Node *next;
// };

// Node *createNode(int data) {
//     Node *newNode = new Node();
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// void insert(Node **head, int data, int pos) {
//     Node *newNode = createNode(data);
//     if (*head == NULL) {
//         *head = newNode;
//         newNode->next = *head;
//     } else {
//         Node *temp = *head;
//         if (pos == 0) {
//             while (temp->next != *head) {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//             newNode->next = *head;
//             *head = newNode;
//         } else {
//             for (int i = 1; i < pos; i++) {
//                 temp = temp->next;
//             }
//             newNode->next = temp->next;
//             temp->next = newNode;
//         }
//     }
// }

// void printList(Node *head) {
//     Node *temp = head;

//     while (temp->next != head) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << temp->data << endl;
// }

// int main() {
//     int n;
//     cin >> n;

//     Node *head = NULL;

//     int data;
//     for (int i = 1; i <= n; i++) {
//         cin >> data;
//         insert(&head, data, i - 1);
//     }

//     int pos;
//     cin >> pos >> data;

//     insert(&head, data, pos);

//     printList(head);

//     return 0;
// }

#include <iostream>
using namespace std;

// Define the structure of a BST node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a value into the BST
Node *insert(Node *root, int value) {
    if (!root)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void printAsciiInOrder(Node *root) {
    if (root != nullptr) {
        printAsciiInOrder(root->left);
        cout << (char)root->data << " ";
        printAsciiInOrder(root->right);
    }
}

int main() {
    Node *root = nullptr;

    root = insert(root, 65);
    root = insert(root, 66);
    root = insert(root, 67);
    root = insert(root, 97);
    root = insert(root, 100);

    inorder(root);
    cout << endl;
    printAsciiInOrder(root);

    return 0;
}
