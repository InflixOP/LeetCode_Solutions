class Solution {
    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            int N = colors.size();
            unordered_map<int,vector<int>> adj;
            int countNodes = 0;
            vector<int> indegree(N,0);
            for(auto& edge:edges){
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                indegree[v]++;
            }
            vector<vector<int>> table(N,vector<int>(26,0));
            queue<int> que;
            for(int i=0;i<N;i++){
                if(indegree[i]==0){
                  que.push(i);
                  table[i][colors[i]-'a'] = 1;
                }
            }
            int answer = 0;
            while(!que.empty()){
                int U = que.front();
                que.pop();
                countNodes++;
                answer = max(answer,table[U][colors[U]-'a']);
                for(auto neigh:adj[U]){
                    for(int i=0;i<26;i++){
                    table[neigh][i] = max(table[neigh][i],table[U][i] + ((colors[neigh]-'a')==i));
                    }
                     indegree[neigh]--;
                   if(indegree[neigh]==0) que.push(neigh);
                }
            }
            if(countNodes<N) return -1;
            return answer;
        }
    };