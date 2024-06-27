#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCostToMergeFiles(vector<int>& file_sizes) {
    // Create a min-heap (priority queue) from the list of file sizes
    priority_queue<int, vector<int>, greater<int>> min_heap(file_sizes.begin(), file_sizes.end());
    
    int total_cost = 0;
    
    // Continue merging until we have only one file left
    while (min_heap.size() > 1) {
        // Extract the two smallest files
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();
        
        // Merge them
        int cost = first + second;
        total_cost += cost;
        
        // Add the merged file back to the heap
        min_heap.push(cost);
    }
    
    return total_cost;
}

int main() {
    vector<int> file_sizes = {4, 3, 2, 6};
    cout << "Minimum Cost = " << minCostToMergeFiles(file_sizes) << endl;
    return 0;
}
