class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mindif = INT_MAX;
        vector<vector<int>>ans;

        for(int i=0;i<n-1;i++){
            int diff = arr[i+1]-arr[i];
            mindif = min(mindif,diff);
        }

        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==mindif){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
        
    }
};