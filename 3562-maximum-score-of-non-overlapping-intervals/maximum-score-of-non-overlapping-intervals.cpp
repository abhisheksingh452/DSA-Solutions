#include <vector>
#include <algorithm>

class Solution {
    struct Interval {
        long long l, r, weight;
        int id;
    };

    struct State {
        long long score = 0;
        std::vector<int> indices;

        // Custom comparison: higher score is better; if scores are equal,
        // lexicographically smaller index list is preferred.
        bool isBetterThan(const State& other) const {
            if (score != other.score) {
                return score > other.score;
            }
            return indices < other.indices;
        }
    };

  public:
    std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        std::vector<Interval> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = {(long long)intervals[i][0], (long long)intervals[i][1], (long long)intervals[i][2], i};
        }

        // Sort primarily by start time l
        std::sort(vec.begin(), vec.end(), [](const Interval& a, const Interval& b) {
            return a.l < b.l;
        });

        // Extract left endpoints for binary search
        std::vector<long long> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = vec[i].l;
        }

        // dp[i][k]: best state choosing at most k non-overlapping intervals from vec[i...n-1]
        std::vector<std::vector<State>> dp(n + 1, std::vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            // Binary search for first interval starting strictly after vec[i].r
            int next_idx = std::upper_bound(starts.begin(), starts.end(), vec[i].r) - starts.begin();

            for (int k = 1; k <= 4; k++) {
                // Option 1: Skip interval i
                State best = dp[i + 1][k];

                // Option 2: Include interval i
                State take = dp[next_idx][k - 1];
                take.score += vec[i].weight;
                take.indices.push_back(vec[i].id);
                std::sort(take.indices.begin(), take.indices.end());

                if (take.isBetterThan(best)) {
                    best = take;
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].indices;
    }
};