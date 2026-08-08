class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())
        return ans;

        unordered_map<char,int>need;
        unordered_map<char,int>window;

        for(char c:p){
            need[c]++;
        }

        int k = p.size();
        for(int i =0;i<k;i++){
            window[s[i]]++;
        }

        if(need==window){
            ans.push_back(0);
        }

        for(int i=k;i<s.size();i++){
            window[s[i]]++;

            window[s[i-k]]--;

            if(window[s[i-k]]==0){
                window.erase(s[i-k]);
            }

            if(need==window)
            ans.push_back(i-k+1);
        }
        return ans;
    }
};