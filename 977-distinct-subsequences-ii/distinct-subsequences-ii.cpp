class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9+7;
        vector<long long>last(26,0);
        long long total =0;
        for(char ch :s){
            int idx=ch-'a';
            long long new_count=(total+1)%MOD;
            total=(total + new_count - last[idx] + MOD) % MOD;
            last[idx] = new_count;
        }
        return total;
    }
};