class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
       int left = *max_element(nums.begin(),nums.end());
       int right=accumulate(nums.begin(),nums.end(),0);
       while(left<=right){
        int mid=left+(right-left)/2;
        int subarray=1;
        int sum=0;
        for(auto num:nums){
            if(sum+num>mid){
                subarray++;
                sum=0;
            }
            sum+=num;
        }
        if(subarray<=k){
            right=mid-1;
        }else{
            left=mid+1;
        }
       } 
       return left;
    }
};