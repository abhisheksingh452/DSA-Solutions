class Solution {
public:

void solve(int i,string& digits, string& current, vector<string>&ans,vector<string>mp){
     if (i == digits.size()) {
            ans.push_back(current);
            return;
        }

        
        string letters = mp[digits[i] - '0'];

       
        for (char ch : letters) {

        
            current.push_back(ch);

           
            solve(i + 1, digits, current, ans, mp);

            
            current.pop_back();
}
}

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>mp={
             "",    
            "",     
            "abc",  
            "def", 
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };
        vector<string>ans;
        string current;

        solve(0,digits,current,ans,mp);
        return ans;
    }
};