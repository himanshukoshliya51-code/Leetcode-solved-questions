class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        int mod = k % m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2 == 0){
                if(mat[i][j] != mat[i][(j+mod)%m]) return false;
                }
                else{
                    if(mat[i][j] != mat[i][(j-mod+m)%m]) return false;
                }
            }
        }
        return true;  
    }
};