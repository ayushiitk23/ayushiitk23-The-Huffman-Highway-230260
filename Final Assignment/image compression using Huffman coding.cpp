#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>

using namespace std;

// Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

// Comparison object to be used in the priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return (left->freq > right->freq);
    }
};

// Traverse the Huffman tree and store Huffman codes in a map
void storeCodes(struct Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

// Function to build the Huffman tree and store the codes
void HuffmanCodes(vector<char> data, vector<int> freq, unordered_map<char, string> &huffmanCode) {
    struct Node *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for (size_t i = 0; i < data.size(); ++i)
        minHeap.push(new Node(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies.
        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Store Huffman codes in a map
    storeCodes(minHeap.top(), "", huffmanCode);
}

// Utility function to read file content
string readFile(const string& filename) {
    ifstream file(filename, ios::in | ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

// Utility function to write file content
void writeFile(const string& filename, const string& content) {
    ofstream file(filename, ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    file << content;
}

// Compresses the input file using Huffman coding
void compressFile(const string& inputFilename, const string& outputFilename) {
    string data = readFile(inputFilename);

    unordered_map<char, int> freq;
    for (char ch : data)
        freq[ch]++;

    vector<char> chars;
    vector<int> freqs;
    for (auto pair : freq) {
        chars.push_back(pair.first);
        freqs.push_back(pair.second);
    }

    unordered_map<char, string> huffmanCode;
    HuffmanCodes(chars, freqs, huffmanCode);

    string encodedStr;
    for (char ch : data)
        encodedStr += huffmanCode[ch];

    writeFile(outputFilename, encodedStr);
}

int main() {
    string inputFilename = "input.bmp";   // Path to the input image file
    string compressedFilename = "compressed.bin";

    // Compress the file
    compressFile(inputFilename, compressedFilename);

    cout << "Compression completed successfully." << endl;

    return 0;
}
