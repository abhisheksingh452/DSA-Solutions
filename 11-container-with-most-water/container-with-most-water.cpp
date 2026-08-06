class Solution {
public:
    int maxArea(vector<int>& height) {
       int left =0;
       int right = height.size()-1;

       int maxm =0;

       while(left<right){
        int area= min(height[left],height[right])*(right-left);

         maxm = max(maxm,area);

        if(height[left]<height[right])
        left++;
        else
        right--;
       } 
       return maxm;
    }
};