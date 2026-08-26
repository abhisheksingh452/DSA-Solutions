class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int currentsum =0;
     int maxsum =nums[0];
     for(auto x:nums){
        currentsum+=x;
        maxsum= max(maxsum,currentsum);

        if(currentsum<0)
        currentsum=0;
     }
     return maxsum;
    }
};