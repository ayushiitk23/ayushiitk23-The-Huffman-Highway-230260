Q2. Knapsack Problem 
You are given a list of N items, each with a weight and a value. You have a knapsack that can hold a maximum weight W. 
Addi onally, you have some constraints and addi onal features: 
1. Each item may have a dependency on another item. If you include item i, you must also include its dependent 
item j. 
2. Some items can be grouped into categories, and you can select at most one item from each category. 
3. Each item can be taken mul ple mes, but only up to a maximum limit L[i] for item i. 
Your task is to determine the maximum value you can achieve while respec ng the knapsack's weight limit, the 
dependency constraints, the category constraints, and the item repe on limits. 
Input: 
 An integer N represen ng the number of items. 
 An integer W represen ng the maximum weight the knapsack can hold. 
 An array weights of size N, where weights[i] is the weight of the i-th item. 
 An array values of size N, where values[i] is the value of the i-th item. 
 An array dependencies of size N, where dependencies[i] is the index of the item that i-th item depends on, or -1 if 
there is no dependency. 
 An array categories of size N, where categories[i] is the category of the i-th item. 
 An array limits of size N, where limits[i] is the maximum number of mes the i-th item can be taken. 
Output: 
 The maximum value that can be achieved within the given constraints. 
Example: 
#include <bits/stdc++.h> 
using namespace std; 
int knapsack(int N, int W, vector<int>& weights, vector<int>& values, vector<int>& dependencies, vector<int>& 
categories, vector<int>& limits) { 
// Your dynamic programming solu on goes here 
} 
int main() { 
int N = 10; 
int W = 100; 
vector<int> weights = {10, 20, 30, 40, 15, 25, 35, 45, 55, 50}; 
vector<int> values = {60, 100, 120, 240, 150, 90, 200, 170, 250, 300}; 
vector<int> dependencies = {-1, 0, -1, 2, -1, -1, 1, 4, -1, 7} // Items 1 depends on 0, 3 depends on 2, 6 depends on 1, 7 
depends on 4, 9 depends on 7 
vector<int> categories = {1, 0, 0, 1, 2, 2, 3, 3, 4, 4} // Categories constrain the selec on to at most one item per category            
vector<int> limits = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1} // Maximum mes each item can be taken 
int result = knapsack(N, W, weights, values, dependencies, categories, limits); 
cout << "Maximum Knapsack Value: " << result << endl; 
return 0; 
}