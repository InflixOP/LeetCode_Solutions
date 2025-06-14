class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans(2,0);
        ans[0]=1;
        for(int i=0;i<s.length();i++){
            if(ans[1]+widths[s[i]-'a']>100){
                ans[1]=widths[s[i]-'a'];
                ans[0]++;
            }else{
                ans[1]+=widths[s[i]-'a'];
            }
        }
        return ans;
    }
};