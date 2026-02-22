class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if(fresh ==0 ){return 0;}
        int minutes = 0;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while(!q.empty()){
            int size = q.size();
            bool rooted = false;
             for(int i = 0; i < size; i++){

            auto it = q.front();
            q.pop();


            int r = it.first;
            int c = it.second;

            for(int i=0;i<4;i++){
              int nrow = r + delRow[i];
               int ncol = c + delCol[i];

               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                grid[nrow][ncol]=2;
                q.push({nrow,ncol});
                fresh--;
                rooted = true;
               } 
            }
        }
        if(rooted)minutes++;
        }
        if(fresh==0)return minutes;
        else return -1;
    }
};