#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm> // for std::sort
using namespace std;

// Definition of a tree node
typedef struct Node 
{
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
} Node;

// Random number generator setup
typedef mt19937 RNG;
static RNG rng(random_device{}());

// Return true with probability p
bool randomChance(double p) 
{
    uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng) < p;
}

// Generate a random integer in [minVal, maxVal]
int randomInt(int minVal, int maxVal) 
{
    uniform_int_distribution<int> dist(minVal, maxVal);
    return dist(rng);
}

// Recursively build a binary tree with random values up to maxHeight.
Node* generateTree(int currentLevel, int maxHeight, double leafProb,
    int minVal, int maxVal) {
    if (currentLevel > maxHeight) return nullptr;
    if (currentLevel == maxHeight && !randomChance(leafProb)) return nullptr;
    int randValue = randomInt(minVal, maxVal);
    Node* node = new Node(randValue);
    node->left = generateTree(currentLevel + 1, maxHeight, leafProb, minVal, maxVal);
    node->right = generateTree(currentLevel + 1, maxHeight, leafProb, minVal, maxVal);
    return node;
}

// Count total nodes in the tree
int countNodes(Node* root) 
{
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Store inorder traversal in an array
void storeInorder(Node* root, int* arr, int& idx) 
{
    if (!root) return;
    storeInorder(root->left, arr, idx);
    arr[idx++] = root->value;
    storeInorder(root->right, arr, idx);
}

// Assign sorted values back into tree using inorder traversal
void arrayToBST(Node* root, int* arr, int& idx) 
{
    if (!root) return;
    arrayToBST(root->left, arr, idx);
    root->value = arr[idx++];
    arrayToBST(root->right, arr, idx);
}

// Convert arbitrary binary tree to BST (preserve structure)
void convertToBST(Node* root) 
{
    int n = countNodes(root);
    if (n <= 0) return;
    int* arr = new int[n];
    int idx = 0;
    storeInorder(root, arr, idx);
    sort(arr, arr + n);
    idx = 0;
    arrayToBST(root, arr, idx);
    delete[] arr;
}

// Find minimum node in BST (used for deletion)
Node* findMin(Node* root) 
{
    while (root && root->left)
        root = root->left;
    return root;
}

// BST deletion
Node* deleteBST(Node* root, int val) 
{
    if (!root) return nullptr;
    if (val < root->value) 
    {
        root->left = deleteBST(root->left, val);
    }
    else if (val > root->value) 
    {
        root->right = deleteBST(root->right, val);
    }
    else 
    {
        // Node to delete found
        if (!root->left) 
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) 
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Two children: find inorder successor
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteBST(root->right, temp->value);
    }
    return root;
}

// Recursively place node values into the C-style grid
void fillGrid(Node* root, char** grid, int row, int left, int right,
    int totalRows, int totalCols) 
{
    if (!root || row >= totalRows || left > right) return;
    int mid = (left + right) / 2;
    string val = std::to_string(root->value);
    int start = mid - static_cast<int>(val.length() / 2);
    for (size_t i = 0; i < val.length(); ++i) 
    {
        int c = start + static_cast<int>(i);
        if (c >= 0 && c < totalCols)
            grid[row][c] = val[i];
    }
    fillGrid(root->left, grid, row + 1, left, mid - 1, totalRows, totalCols);
    fillGrid(root->right, grid, row + 1, mid + 1, right, totalRows, totalCols);
}

// Print the tree in a true "binary tree" layout without std::vector
void printTree(Node* root, int height) 
{
    if (!root || height <= 0) return;
    int rows = height;
    int cols = static_cast<int>(std::pow(2, height)) * 3;

    // Allocate C-style 2D grid
    char** grid = new char* [rows];
    for (int r = 0; r < rows; ++r) 
    {
        grid[r] = new char[cols + 1];
        memset(grid[r], ' ', cols);
        grid[r][cols] = '\0';
    }

    fillGrid(root, grid, 0, 0, cols - 1, rows, cols);

    // Print each row
    for (int r = 0; r < rows; ++r) {
        cout << grid[r] << std::endl;
        delete[] grid[r];
    }
    delete[] grid;
}

// Clean up allocated nodes
void deleteTree(Node* root) 
{
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() 
{
    int height;
    double leafProb;
    int minVal, maxVal;

    cout << "Enter desired tree height: ";
    cin >> height;
    cout << "Enter leaf existence probability (0.0 - 1.0): ";
    cin >> leafProb;
    cout << "Enter minimum node value: ";
    cin >> minVal;
    cout << "Enter maximum node value: ";
    cin >> maxVal;

    Node* root = generateTree(1, height, leafProb, minVal, maxVal);
    cout << "\nGenerated binary tree:\n";
    printTree(root, height);

    // Convert to BST and print
    convertToBST(root);
    cout << "\nConverted to binary search tree:\n";
    printTree(root, height);

    // Delete a value from BST
    int deleteVal;
    cout << "\nEnter value to delete from BST: ";
    cin >> deleteVal;
    root = deleteBST(root, deleteVal);
    cout << "\nBST after deletion of " << deleteVal << ":\n";
    printTree(root, height);

    deleteTree(root);
    return 0;
}