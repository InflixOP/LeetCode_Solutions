class dsu {
    vector<int> rank_arr, parent_arr, size;

public:
    dsu(int n) {
        rank_arr.resize(n + 1, 0);
        parent_arr.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent_arr[i] = i;
            size[i] = 1;
        }
    }

    int findpar(int node) {
        if (node == parent_arr[node])
            return node;
        return parent_arr[node] = findpar(parent_arr[node]);
    }

    void uni_rank(int u, int v) {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank_arr[ulp_u] < rank_arr[ulp_v]) {
            parent_arr[ulp_u] = ulp_v;
        } else if (rank_arr[ulp_v] < rank_arr[ulp_u]) {
            parent_arr[ulp_v] = ulp_u;
        } else {
            parent_arr[ulp_v] = ulp_u;
            rank_arr[ulp_u]++;
        }
    }

    void uni_size(int u, int v) {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent_arr[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent_arr[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        dsu dsu(n);
        
        unordered_map<int, vector<int>> connected_comp;
        unordered_map<int, int> pairs;
        int ans=0;

        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (dsu.findpar(a) != dsu.findpar(b))
                dsu.uni_size(a, b);

            pairs[a]++;
            pairs[b]++;
        }

        for (int i = 0; i < n; i++) {
            connected_comp[dsu.findpar(i)].push_back(i);
        }

        for (auto& [k, v] : connected_comp) {
            if (v.size() <= 2){
                ans++;
                 continue;}
            bool pairwiseconn = true;
            for (auto x : v) {

                if (pairs[x] != connected_comp[dsu.findpar(x)].size() - 1) {
                    pairwiseconn = false;
                    break;
                }
            }
            if (pairwiseconn)
                ans++;
        }

        return ans;
    }
};