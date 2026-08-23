class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mp;
       for(auto x:nums){
        mp[x]++;
       }
       
       int p =n/2;
       for(auto x:mp){
        if(x.second>p)
        return x.first;
       
       }
       return 0;
    }
};