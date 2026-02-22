class Solution {
public:
void dfs(int sr, int sc, vector<vector<int>>& image,vector<vector<int>>& ans1,int color,int newcolor,int delRow[],int delCol[]){
    ans1[sr][sc] = color;
    int n = image.size();
    int m = image[0].size();
    for(int i=0;i<4;i++){
        int nrow = sr + delRow[i];
        int ncol = sc + delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == newcolor && ans1[nrow][ncol] != color){
            dfs(nrow,ncol,image,ans1,color,newcolor,delRow,delCol);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int newcolor = image[sr][sc];
        vector<vector<int>>ans1 = image;    
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        dfs(sr,sc,image,ans1,color,newcolor,delRow,delCol);
        return ans1;
    }
};