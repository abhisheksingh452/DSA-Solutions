class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>res(n,0);
        if(k==0)return res;

        int left=1,right=k;
        if(k<0){
            left=n-abs(k);
           
            right=n-1;
        }
        int curr_sum=0;
        for(int i=left;i<=right;i++){
            curr_sum+=code[i];
        }
        for(int i=0;i<n;i++){
            res[i]=curr_sum;
            curr_sum -= code[left%n];
            left++;
            right++;
            curr_sum+=code[right%n];
        }
        return res;
    }
};