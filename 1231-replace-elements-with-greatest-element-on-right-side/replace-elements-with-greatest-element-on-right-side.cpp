class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int index=0;
        for(int i=0;i<n-1;i++){
            int pvt=*max_element(arr.begin()+i+1,arr.end());
            arr[i]=pvt;
        }
        arr[n-1]=-1;
        return arr;
        // int maxright= -1;
        // for(int i=n-1;i>=0;i--){
        //     int current = arr[i];
        //     arr[i]=maxright;
        //     maxright=max(current,maxright);
        // }
        // return arr;
    }
};