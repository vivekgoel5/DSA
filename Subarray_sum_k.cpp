/*
To find the number of subarrays having a sum exactly equal to 𝑘
k, we can use a hash map (or dictionary) to keep track of the cumulative sums encountered so far. This approach is efficient and works in linear time. 

Approach:
1) Initialize a Hash Map:
    Use a hash map to store the frequency of cumulative sums encountered so far. Initialize the hash map with a cumulative sum of 0 occurring once. This helps in handling cases where a subarray starting from the       beginning of the array has a sum equal to K
2) Iterate Through the Array:
  a) Maintain a running cumulative sum as you iterate through the array.
  b) For each element in the array, update the cumulative sum.
  c) Check if the difference between the cumulative sum and k (i.e., cumulative_sum - k) is already present in the hash map. If it is, it means there are subarrays that end at the current index and have a sum equal to k.
  d) Add the frequency of cumulative_sum - k to the count of such subarrays.
  e) Update the hash map with the current cumulative sum.
  3) Return the Count:
    After iterating through the array, the count will hold the number of subarrays with a sum exactly equal to k.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    // Dictionary to store the frequency of cumulative sums
    unordered_map<int, int> sum_counts;
    sum_counts[0] = 1;  // Initialize with cumulative sum 0 occurring once
    
    int cumulative_sum = 0;
    int count = 0;

    for (int num : nums) {
        // Update the cumulative sum
        cumulative_sum += num;
        
        // Check if (cumulative_sum - k) exists in the map
        if (sum_counts.find(cumulative_sum - k) != sum_counts.end()) {
            count += sum_counts[cumulative_sum - k];
        }
        
        // Update the frequency of the current cumulative sum in the map
        if (sum_counts.find(cumulative_sum) != sum_counts.end()) {
            sum_counts[cumulative_sum]++;
        } else {
            sum_counts[cumulative_sum] = 1;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Number of subarrays with sum " << k << " is " << subarraySum(nums, k) << endl; // Output: 2

    return 0;
}
