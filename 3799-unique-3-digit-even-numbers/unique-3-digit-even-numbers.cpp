// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
        
//     }
// };
#include <vector>

class Solution {
  public:
    int totalNumbers(std::vector<int>& digits) {
        // Step 1: Count frequency of available digits
        std::vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Step 2: Iterate through all valid 3-digit even numbers
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;        // Hundreds digit
            int d2 = (num / 10) % 10;  // Tens digit
            int d3 = num % 10;         // Units digit

            // Count digit frequencies needed for current number
            std::vector<int> need(10, 0);
            need[d1]++;
            need[d2]++;
            need[d3]++;

            // Step 3: Check if available digits satisfy requirements
            bool possible = true;
            for (int i = 0; i < 10; i++) {
                if (need[i] > freq[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                count++;
            }
        }

        return count;
    }
};