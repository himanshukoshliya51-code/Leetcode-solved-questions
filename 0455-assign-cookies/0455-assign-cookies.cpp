class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = s.size();
        int m = g.size();
        int j=0;
        int i=0;
        while(i<n && j<m){
            if(g[j]<=s[i]){
                j++;
            }
            i++;

        }
        return j;
    }
};