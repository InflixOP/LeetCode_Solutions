class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> f(26,0);
        int del=0,ans=word.length();
        for(char c:word)
        f[c-'a']++;
        sort(f.begin(),f.end());
        for(int i=0;i<f.size();i++){
            int r=del;
            int mini=f[i];
            for(int j=f.size()-1;j>i;j--){
                if(f[j]-mini<=k) break;
                r+=f[j]-mini-k;
            }
            ans=min(ans,r);
            del+=f[i];
        }
        return ans;
    }
};