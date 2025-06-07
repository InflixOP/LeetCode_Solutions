class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n=recipes.size();
            vector<string> ans;
            unordered_set<string> st(begin(supplies),end(supplies));
            unordered_map<string,vector<int>> adj;
            vector<int> ind(n,0);
            queue<int> q;
            for(int i=0;i<n;i++){
                for(auto ele:ingredients[i]){
                    if(!st.count(ele)){
                        adj[ele].push_back(i);
                        ind[i]++;
                    }
                }
            }
            for(int i=0;i<n;i++){
                if(ind[i]==0)
                q.push(i);
            }
            while(!q.empty()){
                int s=q.front();
                string r=recipes[s];
                q.pop();
                ans.push_back(r);
                for(auto ele:adj[r]){
                    ind[ele]--;
                    if(ind[ele]==0){
                        q.push(ele);
                    }
                }
            }
            return ans;
        }
    };