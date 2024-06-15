//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", 0, 0, n);
        return res;
    }

private:
    void dfs(vector<string>& res, string s, int left, int right, int n) {
        // Base case: if the current string's length is equal to 2*n, it's a valid combination
        if (s.length() == n * 2) {
            res.push_back(s);  // Add the valid combination to the result list
            return;
        }

        // If we can still add a left parenthesis, do so
        if (left < n) {
            dfs(res, s + '(', left + 1, right, n);
        }

        // If we can still add a right parenthesis without breaking the balance, do so
        if (right < left) {
            dfs(res, s + ')', left, right + 1, n);
        }
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);
    
    // Print the result
    for (const string& str : result) {
        cout << str << endl;
    }
    
    return 0;
}
