struct DSU {
    int n;
    vector<int> parents;
    vector<int> ranks;
    vector<int> weights;
    DSU(int n)
    {
        this->n = n;
        this->parents.assign(n, 0);
        this->weights.assign(n,131071);
        this->ranks.assign(n, 0);
        for (int index = 0; index < n; ++index) {
            this->parents[index] = index;
        }
    }

    int find_set(int v) {
        if (v == this->parents[v]) {
            return v;
        }
        this->parents[v] = find_set(this->parents[v]);
        return this->parents[v];
    }

    void unite(int v1, int v2,int val) {
        int x = find_set(v1);
        int y = find_set(v2);

        if (x == y) {
            weights[x]&=val;
            return;
        }

        if (this->ranks[x] < this->ranks[y]) 
        {
            this->parents[x]=y;
            weights[y]&= (weights[x]&val);
        }
        else if(this->ranks[x] > this->ranks[y]) 
        {
            parents[y]=x;
            weights[x]&= (weights[y]&val);
        }   
        else         
        {
            parents[x]=y;
            weights[y]&= (weights[x]&val);
            this->ranks[y]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        DSU graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph.unite(edges[i][0],edges[i][1],edges[i][2]);
        }    
        vector<int> sol;
        for(int i=0;i<query.size();i++)
        {
            int x=graph.find_set(query[i][0]);
            int y=graph.find_set(query[i][1]);
            sol.push_back(x==y?graph.weights[x]:-1);
        }
        return sol;
    }
};