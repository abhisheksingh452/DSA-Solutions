class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxdiff=0;
        long long  leftmax=nums[0];
        long long ans =0;
        for(int k=1;k<nums.size();k++){
            ans = max(ans,maxdiff*nums[k]);
            maxdiff= max(maxdiff,leftmax-nums[k]);
            leftmax=max(leftmax,(long long)nums[k]);
        }

if(ans<0)return 0;
return ans;
    }
};