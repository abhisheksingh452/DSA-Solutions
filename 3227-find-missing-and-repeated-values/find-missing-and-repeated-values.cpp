class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n = grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        int a=0;
        vector<int>ans;
        for(auto x:mp){
            if(x.second==2)
            a=x.first;
            

        }
        ans.push_back(a);
        int sum =0;
        for(auto x:mp){
            sum+=x.first;
        }
       int total = (n * n) * (n * n + 1) / 2;
        int b = total-sum+a-(a);
       
        ans.push_back(b);
        return ans;
        
    }
};