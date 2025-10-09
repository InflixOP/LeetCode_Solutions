class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        
        int n =skill.size();
        int m =mana.size();

        vector<long long> ans(n+1,0);


        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
              
              ans[i+1]= max(ans[i],ans[1+i])+1LL*skill[i]*mana[j];

            }


            for(int i=n-1;i>0;i--){
                ans[i]=ans[i+1]-(1LL*skill[i]*mana[j]);
            }
        }



        return ans[n];

    }
};