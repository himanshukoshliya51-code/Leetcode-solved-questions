class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Step 1: Create reverse graph
        vector<vector<int>> revGraph(n);

        // Step 2: Store outdegree
        vector<int> outdegree(n, 0);

        for(int i = 0; i < n; i++){
            outdegree[i] = graph[i].size();
            
            for(int neighbour : graph[i]){
                revGraph[neighbour].push_back(i);  // reverse edge
            }
        }

        // Step 3: Push terminal nodes (outdegree = 0)
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safe;

        // Step 4: BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);

            // Reduce outdegree of parents
            for(int parent : revGraph[node]){
                outdegree[parent]--;
                if(outdegree[parent] == 0){
                    q.push(parent);
                }
            }
        }

        // Step 5: Sort result
        sort(safe.begin(), safe.end());
        return safe;
    }
};