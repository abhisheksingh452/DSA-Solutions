class Solution {
public:
    long long countCommas(long long n) {
        if(n<=3)return 0;
        long long reset=1000;
        long long total=0;
        while(n>=reset){
            total+=(n-reset)+1;
            reset*=1000;
        }
        return total;
    }
};