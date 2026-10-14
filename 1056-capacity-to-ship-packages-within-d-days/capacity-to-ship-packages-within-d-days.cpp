class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
       while(left<=right){
        int mid=left+(right-left)/2;
        int reqday=1;
        int sum=0;
        for(auto w:weights){
            if(sum+w>mid){
                reqday++;
                sum=0;
            }
            sum+=w;
        }
        if(reqday<=days){
            right=mid-1;
        }else{
            left=mid+1;
        }
       }
       return left;
    }
};