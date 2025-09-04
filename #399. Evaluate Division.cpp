class Solution {
public:
    double dfs(vector<vector<double>>& mat, int source, int target, double prod, vector<bool>& visited)
    {
        if(source==target)
            return prod;
        visited[source] = true;
        double ans = -1;
        for(int i=0; i<mat.size(); i++)
        {
            if(i==source)
                continue;
            if(mat[source][i]>0 && !visited[i])
            {
                double product = (double)prod * (double)mat[source][i];
                double curr = dfs(mat,i,target,product,visited);
                if(curr!=-1.0)
                    ans = curr;
            }
        }
        return ans;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int i=0;
        for(auto equation: equations)
        {
            if(mp.find(equation[0])==mp.end())
            {
                mp[equation[0]]=i++;
            }
            if(mp.find(equation[1])==mp.end())
            {
                mp[equation[1]]=i++;
            }
        }
        int n = mp.size();
        vector<vector<double>> mat(n,vector<double>(n,0));
        for(int i=0; i<n; i++)
        {
            mat[i][i] = 1;
        }
        for(int i=0; i<equations.size(); i++)
        {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            mat[u][v] = values[i];
            mat[v][u] = 1/values[i];
        }
        int m = queries.size();
        vector<double> ans(m);
        for(int i=0; i<queries.size(); i++)
        {
            string u = queries[i][0];
            string v = queries[i][1];
            if(mp.find(u)==mp.end())
            {
                ans[i] = -1;
                continue;
            }
            if(mp.find(v)==mp.end())
            {
                ans[i] = -1;
                continue;
            }
            vector<bool> visited(mat.size(),false);
            ans[i] = dfs(mat,mp[u],mp[v],1.0,visited);
        }
        
        return ans;
    }
};