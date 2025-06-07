class Solution {
    public:
    char dfs(unordered_map<char,vector<char>>& mpp,char x,vector<int>& visited){
        visited[x-'a']=1;
        char y=x;
        for(auto it:mpp[x]){
            if((visited[it-'a'])==0)
            y=min(y,dfs(mpp,it,visited));
        }
        return y;
    }
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            unordered_map<char,vector<char>> mpp;
            string res;
            for(int i=0;i<s1.length();i++){
                char u=s1[i];
                char v=s2[i];
                mpp[v].push_back(u);
                mpp[u].push_back(v);
            }
            for(int i=0;i<baseStr.size();i++){
                vector<int> visited(26,0);
                char x=baseStr[i];
                char y=dfs(mpp,x,visited);
                res.push_back(y);
            }
            return res;
        }
    };