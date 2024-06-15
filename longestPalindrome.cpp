//Ref: https://www.youtube.com/watch?v=fxwvVnBMN6I
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return ""; // Handle empty string case
    
    int maxlength = 0;
    string ans;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Fill the dp table
    for (int diff = 0; diff < n; diff++) {
        for (int i = 0, j = i + diff; j < n; i++, j++) {
            if (i == j) {
                dp[i][j] = 1; // Substring of length 1 is always a palindrome
            } else if (diff == 1) {
                dp[i][j] = (s[i] == s[j]) ? 2 : 0; // Substring of length 2
            } else {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2; // Use previously computed results
                }
            }
            
            // Update the longest palindromic substring
            if (dp[i][j]) {
                if (j - i + 1 > maxlength) {
                    maxlength = j - i + 1;
                    ans = s.substr(i, maxlength);
                }
            }
        }
    }
    
    return ans;
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl; // Output: "bab" or "aba"
    return 0;
}
