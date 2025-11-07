class Solution {
public:

void backtrack(int val,int k,int n,vector<int>&current,vector<vector<int>>&result){
    if(n==0 && current.size() == k){
        result.push_back(current);
        return ;
    }
    if (n < 0 || current.size() > k) return;

     for (int i = val; i <= 9; i++) {
        current.push_back(i);
        backtrack(i+1,k,n-i,current,result);
        current.pop_back();
    }


}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        vector<vector<int>>result;

        backtrack(1,k,n,current,result);
        return result;
        
    }
};