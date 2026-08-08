class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char ch : s1)
            need[ch]++;

        int k = s1.size();

        // First window
        for (int i = 0; i < k; i++)
            window[s2[i]]++;

        if (need == window)
            return true;

        // Sliding window
        for (int i = k; i < s2.size(); i++) {

            // Add new character
            window[s2[i]]++;

            // Remove old character
            window[s2[i - k]]--;

            // Remove zero-frequency characters
            if (window[s2[i - k]] == 0)
                window.erase(s2[i - k]);

            if (need == window)
                return true;
        }

        return false;
    }
};