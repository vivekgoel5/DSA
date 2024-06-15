#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        if (v.empty()) return ans;  // Edge case: empty input vector

        // Sort the vector of strings
        sort(v.begin(), v.end());

        // Get the first and last strings after sorting
        string first = v.front();
        string last = v.back();
        
        // Compare the characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans;  // Return the current common prefix if there's a mismatch
            }
            ans += first[i];  // Append matching character to the result
        }

        return ans;  // Return the common prefix
    }
};

// Example usage
int main() {
    Solution solution;
    vector<string> input = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(input);
    cout << "Longest Common Prefix: " << result << endl;  // Output: "fl"
    return 0;
}
