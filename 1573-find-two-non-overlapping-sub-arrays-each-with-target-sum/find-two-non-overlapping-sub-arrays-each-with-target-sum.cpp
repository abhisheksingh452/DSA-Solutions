

class Solution {
  public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        
      
        std::vector<int> min_len(n, INT_MAX);

        int left = 0;
        int current_sum = 0;
        int ans = INT_MAX;
        int min_so_far = INT_MAX; 
        for (int right = 0; right < n; right++) {
            current_sum += arr[right];

           
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

          
            if (current_sum == target) {
                int current_len = right - left + 1;

              
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = std::min(ans, current_len + min_len[left - 1]);
                }

               
                min_so_far = std::min(min_so_far, current_len);
            }

          
            if (right > 0) {
                min_len[right] = std::min(min_len[right - 1], min_so_far);
            } else {
                min_len[right] = min_so_far;
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};