class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>need(26,0);
       vector<int>window(26,0);
       vector<int>ans;
       int k=p.size();
       if(k>s.size())return ans;

       for(char c:p){
        need[c-'a']++;
       }
       for(int i=0;i<k;i++){
        window[s[i]-'a']++;
       }
       if(need==window)ans.push_back(0);

        for(int i=k;i<s.size();i++){
            window[s[i]-'a']++;
            window[s[i-k]-'a']--;

            if(window==need)ans.push_back(i-k+1);
        }
        return ans;
    }
};