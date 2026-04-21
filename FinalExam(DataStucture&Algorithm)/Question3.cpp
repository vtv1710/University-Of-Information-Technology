#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        root = new TreeNode{ value, nullptr, nullptr };
    }
    else if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

TreeNode* findKthLargest(TreeNode* root, int k, int& count) {
    if (!root) return nullptr;
    TreeNode* right = findKthLargest(root->right, k, count);
    if (right) return right;
    if (++count == k) return root;
    return findKthLargest(root->left, k, count);
}

int countLeafNodes(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int value, k;

    while (true) {
        cin >> value;
        if (value == 0) break;
        root = insert(root, value);
    }

    cin >> k;

    inorder(root);
    cout << endl;

    int count = 0;
    TreeNode* kthLargestNode = findKthLargest(root, k, count);
    if (kthLargestNode) {
        inorder(kthLargestNode);
        cout << endl;
        cout << countLeafNodes(kthLargestNode) << endl;
    }
    else {
        cout << "Empty tree" << endl;
    }

    return 0;
}