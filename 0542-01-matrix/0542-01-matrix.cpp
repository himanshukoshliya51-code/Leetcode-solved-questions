class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       
        queue<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;  // distance of 0 is 0
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int i = 0; i < 4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && dist[nrow][ncol] == -1){
                       
                    dist[nrow][ncol] = dist[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return dist;
    }
};