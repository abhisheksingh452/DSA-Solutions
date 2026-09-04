class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       int mx=0;
       for(int i=0;i<nums.size();i++){
        mx=max(mx,nums[i]);
        int minele=*min_element(nums.begin()+i,nums.end());
        int si=(mx-minele);
        if(si<=k){
            return i;
        }
       } 
       return -1;
    }
};