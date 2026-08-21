class Solution {
public:
    vector<string> ans;

    void solve(string& curr, int open, int close, int n) {

        // A complete valid combination
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Choose '('
        if (open < n) {
            curr.push_back('(');

            solve(curr, open + 1, close, n);

            // Backtrack
            curr.pop_back();
        }

        // Choose ')'
        if (close < open) {
            curr.push_back(')');

            solve(curr, open, close + 1, n);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string curr = "";

        solve(curr, 0, 0, n);

        return ans;
    }
};