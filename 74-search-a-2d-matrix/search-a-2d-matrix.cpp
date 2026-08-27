class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        int left =0;
        int right = n*m-1;

        while(left<=right){
            int mid = left+(right-left)/2;
            int row= mid/m;
            int col=mid%m;
            if(nums[row][col]==target)return true;
            else if(nums[row][col]>target)right=mid-1;
            else left = mid+1;
        }

        return false;


    }
};