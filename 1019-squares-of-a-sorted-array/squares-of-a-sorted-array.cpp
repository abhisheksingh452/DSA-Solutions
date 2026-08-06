class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>arr(n);
        // for(int i=0;i<n;i++){
        //     arr[i]=nums[i]*nums[i];
        // }
        // sort(arr.begin(),arr.end());
        // return arr;

        int left =0;
        int right = nums.size()-1;
         int index = nums.size()-1;
         vector<int>ans(nums.size());

         while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans[index--] = nums[left]*nums[left];

                left++;

            }
            else{
            ans[index--] = nums[right]*nums[right];
            right--;
            }

         }
         return ans;

    }
    
};