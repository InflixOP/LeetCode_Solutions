class Solution {
private:
    void dfs(int node, int par, vector<int>& nums, vector<vector<int>>& graph, 
             vector<pair<int, int>>& dfsEdges, vector<int>& subTreeXOR, 
             vector<int>& parent, vector<int>& inTime, vector<int>& outTime, int& time) {
        parent[node] = par;
        subTreeXOR[node] = nums[node];
        inTime[node] = time++;

        for (int neighbor : graph[node]) {
            if (neighbor == par) continue;
            dfsEdges.emplace_back(node, neighbor);
            dfs(neighbor, node, nums, graph, dfsEdges, subTreeXOR, parent, inTime, outTime, time);
            subTreeXOR[node] ^= subTreeXOR[neighbor];
        }

        outTime[node] = time++;
    }

    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        return (inTime[u] < inTime[v] && outTime[v] < outTime[u]);
    }  

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> subTreeXOR(n), parent(n), inTime(n), outTime(n);
        vector<pair<int, int>> dfsEdges;
        int time = 0;
        dfs(0, -1, nums, graph, dfsEdges, subTreeXOR, parent, inTime, outTime, time);

        int totalXOR = subTreeXOR[0];
        int minScore = INT_MAX;

        for (int i = 0; i < dfsEdges.size(); i++) {
            int a = dfsEdges[i].second;
            for (int j = i + 1; j < dfsEdges.size(); j++) {
                int b = dfsEdges[j].second;

                int x, y, z;
                if (isAncestor(a, b, inTime, outTime)) {
                    x = subTreeXOR[b];
                    y = subTreeXOR[a] ^ subTreeXOR[b];
                    z = totalXOR ^ subTreeXOR[a];
                } else if (isAncestor(b, a, inTime, outTime)) {
                    x = subTreeXOR[a];
                    y = subTreeXOR[b] ^ subTreeXOR[a];
                    z = totalXOR ^ subTreeXOR[b];
                } else {
                    x = subTreeXOR[a];
                    y = subTreeXOR[b];
                    z = totalXOR ^ x ^ y;
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});
                minScore = min(minScore, mx - mn);
            }   
        }

        return minScore;
    }
};