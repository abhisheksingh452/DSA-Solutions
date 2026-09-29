class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int currentdepth=0;
        for(char st:s){
            if(st=='('){
                currentdepth++;
                maxdepth=max(maxdepth,currentdepth);
            }else if(st==')'){
                currentdepth--;
            }
    }
    return maxdepth;
    }
};