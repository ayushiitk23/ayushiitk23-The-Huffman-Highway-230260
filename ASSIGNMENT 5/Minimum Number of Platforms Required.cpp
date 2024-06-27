#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinimumPlatforms(vector<int>& arrivals, vector<int>& departures) {
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    
    int n = arrivals.size();
    int platform_needed = 0;
    int max_platforms = 0;
    
    int i = 0;  // Pointer to traverse arrivals
    int j = 0;  // Pointer to traverse departures
    
    while (i < n && j < n) {
        // If the next event in sorted order is arrival, increment count of platforms needed
        if (arrivals[i] <= departures[j]) {
            platform_needed++;
            i++;
        }
        // Else the next event is departure, decrement count of platforms needed
        else {
            platform_needed--;
            j++;
        }
        
        // Update the maximum platforms needed
        max_platforms = max(max_platforms, platform_needed);
    }
    
    return max_platforms;
}

int main() {
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};
    
    cout << "Minimum Platforms = " << findMinimumPlatforms(arrival, departure) << endl;
    
    return 0;
}
