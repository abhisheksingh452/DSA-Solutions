class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        const long long LIMIT = INT_MAX;

        vector<long long> dp(m + 1, 0);

        // Empty t can always be formed in 1 way
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            // Go backwards
            for (int j = min(i, m); j >= 1; j--) {

                if (s[i - 1] == t[j - 1]) {

                    // Use __int128 only for calculation
                    __int128 value = (__int128)dp[j] + dp[j - 1];

                    // Prevent overflow
                    if (value > LIMIT)
                        dp[j] = LIMIT;
                    else
                        dp[j] = (long long)value;
                }
            }
        }

        return (int)dp[m];
    }
};