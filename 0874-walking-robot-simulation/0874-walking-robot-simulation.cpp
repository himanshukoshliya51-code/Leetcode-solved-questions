#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>> st;
        for(auto &o : obstacles){
            st.insert({o[0], o[1]});
        }

        int dir = 0; // 0=N,1=E,2=S,3=W
        int posx = 0, posy = 0;
        int maxi = 0;

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        for(int cmd : commands){

            if(cmd == -2){
                dir = (dir + 3) % 4; // left
            }
            else if(cmd == -1){
                dir = (dir + 1) % 4; // right
            }
            else{
                while(cmd--){
                    int nx = posx + dx[dir];
                    int ny = posy + dy[dir];

                    if(st.count({nx, ny})) break;

                    posx = nx;
                    posy = ny;

                    maxi = max(maxi, posx*posx + posy*posy);
                }
            }
        }

        return maxi;
    }
};