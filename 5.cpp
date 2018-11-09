#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
} nodes[65535];
int S = 0;

node *buildTree(const int *inOrder, int inStart, int inEnd, int *postOrder, int rootIndex) {
    node *rootNode = &nodes[S++];
    rootNode->data = postOrder[rootIndex];
    if (inStart == inEnd) {
        return rootNode;
    } else {
        int middle = inStart;
        for (; middle <= inEnd; middle++) {
            if (inOrder[middle] == rootNode->data) break;
        }

        int rightNodeNum = inEnd - middle;
        if (middle > inStart) {
            rootNode->left = buildTree(inOrder, inStart, middle - 1, postOrder, rootIndex - rightNodeNum - 1);
        }
        if (middle < inEnd) {
            rootNode->right = buildTree(inOrder, middle + 1, inEnd, postOrder, rootIndex - 1);
        }
        return rootNode;
    }
}

void preOrder(node *root) {
    if (root != NULL) {
        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main5() {
    int inOrder[65535], postOrder[65535];
    node *root;
    int n = 0;

    while (true) {
        cin >> inOrder[n];
        n++;
        if (cin.get() != ' ') break;
    }

    n = 0;
    while (true) {
        cin >> postOrder[n];
        n++;
        if (cin.get() != ' ') break;
    }

    root = buildTree(inOrder, 0, n - 1, postOrder, n - 1);
    preOrder(root);
}