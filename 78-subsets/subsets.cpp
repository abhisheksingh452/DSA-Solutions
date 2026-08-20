class Solution {
public:

    void solve(int i, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        if (i == nums.size()) {
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);

        solve(i + 1, nums, current, ans);

        current.pop_back();

        solve(i + 1, nums, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};