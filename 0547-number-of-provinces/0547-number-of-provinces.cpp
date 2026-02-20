class Solution {
public:
    void search(int start, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[start] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[start][j] == 1 && !visited[j]) {
                search(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                search(i, isConnected, visited);
                cnt++;
            }
        }

        return cnt;
    }
};