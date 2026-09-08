class Solution {
public:
    int countCommas(int n) {
        if(n<=3)return 0;
        long long threshold=1000;
        long long count=0;
        while(n>=threshold){
            count+=(n-threshold+1);
            threshold*=1000;
        }
        return count;
    }
};