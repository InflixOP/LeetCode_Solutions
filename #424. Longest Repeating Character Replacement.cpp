class Solution {
    public:
        int characterReplacement(string s, int k) {
           int n=s.length();
           int maxi=0;
           int maxf=0;
           unordered_map<int,int> mp;
           int l=0,r=0;
           while(r<n){
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            if((r-l+1)-maxf>k){
                mp[s[l]-'A']--;
                maxf=0;
                l++;
            }else{
                maxi=max(maxi,r-l+1);
            }
            r++;
           } 
           return maxi;
        }
    };