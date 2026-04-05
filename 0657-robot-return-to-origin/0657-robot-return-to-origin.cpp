class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int l =0;
        int r =0;
        int u = 0;
        int d =0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'L')l++;
            if(moves[i] == 'R')r++;
            if(moves[i] == 'U')u++;
            if(moves[i] == 'D')d++;
        }
        if(l == r && u == d)return true;
        return false;
        
    }
};