class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

       
        for(auto edge : prerequisites) {
            int u = edge[0];   
            int v = edge[1];  
            
            adj[v].push_back(u);   
            indegree[u]++;         
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};