class Solution {
public:
int findParent(int node , vector<int>& parent){
    if(parent[node]==node){
        return node;
    }

    return parent[node] = findParent(parent[node] , parent);
}
void Union(int u , int v , vector<int>& parent , vector<int>& rank){
    int pu = findParent(u,parent);
    int pv = findParent(v,parent);

    if(pu == pv){
        return;
    }
    else if ( rank[pu]<rank[pv] ){
        parent[pu] = pv;
    }
    else if (rank[pu]>rank[pv]){
        parent[pv] = pu;
    }
    else{
        parent[pv] = pu;
        rank[pu]++;
    }

}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        unordered_map<string , int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail]=i;
                }
                else{
                    Union(i,mapMailNode[mail],parent ,rank);
                }
            }
        }

        vector<vector<string>>mergedMail(n);
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = findParent(it.second,parent);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
       for(int i=0;i<n;i++){
        if(mergedMail[i].size()==0)continue;

        sort(mergedMail[i].begin() , mergedMail[i].end());
        vector<string>temp;
        temp.push_back(accounts[i][0]);
        for(auto  it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
       }

        return ans;
        
    }
};