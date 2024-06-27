#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the Huffman Tree
class HuffmanNode {
public:
    char data;            // Character stored in this node
    int freq;             // Frequency of the character
    HuffmanNode* left;    // Pointer to the left child
    HuffmanNode* right;   // Pointer to the right child

    // Constructor to initialize a node with character and frequency
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator class for priority queue to compare HuffmanNode pointers based on frequency
class Compare {
public:
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;  // Min-heap based on frequency
    }
};

// Class to handle Huffman Decoding
class HuffmanDecoding {
private:
    HuffmanNode* root;                      // Root of the Huffman Tree
    unordered_map<char, int> freqMap;       // Frequency map for characters
    string encodedData;                     // Encoded data string

    // Function to build frequency map from the provided string
    void buildFrequencyMap(const string& freqMapStr);
    
    // Function to build the Huffman Tree from the frequency map
    void buildHuffmanTree();
    
    // Function to decode the encoded data using the Huffman Tree
    string decodeData();

public:
    // Constructor to initialize HuffmanDecoding with frequency map string and encoded data
    HuffmanDecoding(const string& freqMapStr, const string& encodedData) : root(nullptr), encodedData(encodedData) {
        buildFrequencyMap(freqMapStr);
        buildHuffmanTree();
    }

    // Destructor to free allocated memory
    ~HuffmanDecoding();
    
    // Function to decode the encoded data
    string decode();
};

// Function to build the frequency map from the provided string
void HuffmanDecoding::buildFrequencyMap(const string& freqMapStr) {
    stringstream ss(freqMapStr);
    char ch;
    int freq;

    // Parse the frequency map string and build the frequency map
    while (ss >> ch >> freq) {
        freqMap[ch] = freq;
    }
}

// Function to build the Huffman Tree using the frequency map
void HuffmanDecoding::buildHuffmanTree() {
    // Min-heap (priority queue) to store HuffmanNodes based on frequency
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Create a leaf node for each character and push it to the min-heap
    for (auto pair : freqMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Iterate until the heap size reduces to one
    while (minHeap.size() != 1) {
        // Extract the two nodes with the lowest frequency
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        int sum = left->freq + right->freq;
        HuffmanNode* node = new HuffmanNode('\0', sum);  // '\0' means this node is not a leaf node
        node->left = left;
        node->right = right;

        // Push the new node to the min-heap
        minHeap.push(node);
    }

    // The remaining node in the heap is the root of the Huffman Tree
    root = minHeap.top();
}

// Function to decode the encoded data using the Huffman Tree
string HuffmanDecoding::decodeData() {
    string decodedString;
    HuffmanNode* currentNode = root;

    // Traverse the encoded data bit by bit
    for (char bit : encodedData) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        // If we reach a leaf node, append the character to the decoded string
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            decodedString += currentNode->data;
            currentNode = root;  // Reset to the root for the next character
        }
    }
    return decodedString;
}

// Destructor to free the allocated memory for the Huffman Tree
HuffmanDecoding::~HuffmanDecoding() {
    // Lambda function to delete the tree recursively
    function<void(HuffmanNode*)> deleteTree = [&](HuffmanNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    };
    deleteTree(root);  // Call the function on the root node
}

// Function to decode the encoded data
string HuffmanDecoding::decode() {
    return decodeData();
}

// Function to decompress data from compressed.txt and write the result to decompressed.txt
void decompressData(const string& inputFileName, const string& outputFileName) {
    string freqMapStr;
    string encodedData;

    // Read frequency map and encoded data from file
    ifstream inputFile(inputFileName, ios::in);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    // Read frequency map
    getline(inputFile, freqMapStr);

    // Read encoded data
    getline(inputFile, encodedData);
    inputFile.close();

    // Create an instance of HuffmanDecoding
    HuffmanDecoding huffman(freqMapStr, encodedData);
    
    // Decode the encoded data
    string decodedData = huffman.decode();
    cout << "Decoded Data: " << decodedData << endl;

    // Write decoded data to output file
    ofstream outputFile(outputFileName, ios::out);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    outputFile << decodedData;
    outputFile.close();
}

int main() {
    decompressData("compressed.txt", "decompressed.txt");
    cout << "Decompression complete." << endl;

    return 0;
}
