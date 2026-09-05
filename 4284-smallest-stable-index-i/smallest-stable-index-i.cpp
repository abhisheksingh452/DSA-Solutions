class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int n =nums.size();
       vector<int>minel(n);
       minel[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--){
        minel[i]=min(minel[i+1],nums[i]);
       }

       int mx=nums[0];
       for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
        int si=(mx-minel[i]);
        if(si<=k)return i;
       }
       return -1;
    }
};