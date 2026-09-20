class Solution {
public:
    int reverseDegree(string s) {
        int total=0;
        for(int i=0;i<s.length();i++){
            int reversepos=26-(s[i]-'a');

            total+=reversepos*(i+1);
        }
        return total;
    }
};