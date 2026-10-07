class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=nums[0];
        int minprod=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            if(x<0){
                swap(maxprod, minprod);
            }
            maxprod=max(x,maxprod*x);
            minprod=min(x,minprod*x);

            ans= max(ans,maxprod);
        }
        return ans;
    }
};