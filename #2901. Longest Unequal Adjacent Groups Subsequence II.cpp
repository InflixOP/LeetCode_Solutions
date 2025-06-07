class Solution {
    public:
        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n=words.size(),maxi,idx,q,len=0;
            vector<vector<int>> dp(n+1,vector<int>(n,0));
            vector<int> v(n);
            vector<string> ans;
            for (int i=0;i<n;i++){
                idx=-1,maxi=0;
                for(int j=0;j<=i;j++) {
                    if(i==j) dp[i][j]=1;
                    else{
                        if(words[i].size()==words[j].size() && groups[i]!=groups[j]){
                            int d=0;
                            for(int k=0;k<words[i].size();k++){
                                if(words[i][k]!=words[j][k]) d++;
                            }
                            if(d==1){
                                dp[i][j]=1+dp[j][v[j]];
                            }
                        }
                    }
                    if(dp[i][j]>=maxi){
                        maxi=dp[i][j];
                        idx=j;
                    }
                }
                v[i]=idx;
                if(dp[i][idx]>=len){
                    len=dp[i][idx];
                    q=i;
                }
            }
            while(q!=v[q]){
                ans.push_back(words[q]);
                q=v[q];
            }
            ans.push_back(words[q]);
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };