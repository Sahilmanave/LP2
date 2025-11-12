#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

// Node class for Huffman tree
class Node {
public:
    int freq;
    char symbol;
    Node *left, *right;
    string huff;

    Node(int f, char s, Node* l = nullptr, Node* r = nullptr) {
        freq = f;
        symbol = s;
        left = l;
        right = r;
        huff = "";
    }
};

// Compare nodes (used for sorting by frequency)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to print Huffman codes
void printNodes(Node* node, string val = "") {
    string newVal = val + node->huff;

    if (node->left)
        printNodes(node->left, newVal);
    if (node->right)
        printNodes(node->right, newVal);

    if (!node->left && !node->right)
        cout << node->symbol << " -> " << newVal << endl;
}

int main() {
    // Characters and their frequencies
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    vector<Node*> nodes;

    // Convert characters and frequencies into nodes
    for (size_t i = 0; i < chars.size(); i++)
        nodes.push_back(new Node(freq[i], chars[i]));

    // Build Huffman tree
    while (nodes.size() > 1) {
        // Sort nodes by frequency
        sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) { return a->freq < b->freq; });

        // Pick 2 smallest nodes
        Node* left = nodes[0];
        Node* right = nodes[1];

        // Assign 0 and 1
        left->huff = "0";
        right->huff = "1";

        // Combine nodes
        Node* newNode = new Node(left->freq + right->freq, '-', left, right);

        // Remove used nodes
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
        nodes.push_back(newNode);
    }

    // Print Huffman codes
    cout << "Huffman Codes:\n";
    printNodes(nodes[0]);

    return 0;
}