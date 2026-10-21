class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
       unordered_map<char,int>mp;
       unordered_map<char,int>st;
       for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        st[t[i]]++;

       }
       if(mp==st)return true;

       return false;

    }
};