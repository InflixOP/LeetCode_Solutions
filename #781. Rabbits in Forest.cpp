class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>s;
        int ans=0;
        int zero=0;
        for(int x:answers){
            if(x==0)zero++;
            else if(s.count(x) && s[x]!=0) s[x]--;
             else {
                s[x]=x;
                ans+=x+1;
                }
              }
        
        
        return ans+zero;
    }
};