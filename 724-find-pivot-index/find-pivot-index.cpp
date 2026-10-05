class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0, right=0,sum=0;
        for(int x:nums){
            sum+=x;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0)left+=nums[i-1];
            right=sum-nums[i]-left;
            if(left==right)return i;
        }
        return -1;
    }
};