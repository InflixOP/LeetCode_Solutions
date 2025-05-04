class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        map<vector<int>,int>m;
        int ans=0;
        for(int i=0; i<dominoes.size();i++)
        {
            sort(dominoes[i].begin(),dominoes[i].end());
            ans+=m[dominoes[i]];
            m[dominoes[i]]++;
        }
        return ans;
        
        
    }
};