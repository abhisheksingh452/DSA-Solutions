class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int>mp;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        int ans=0;
        for(int num:mp){
            if(mp.find(num-1)==mp.end()){
            int curr= num;
            int length =1;
            
            while(mp.find(curr+1)!=mp.end()){
                curr++;
                length++;
                
            }
            
            ans = max(ans,length);
            }

        }
        return ans;
    }
};