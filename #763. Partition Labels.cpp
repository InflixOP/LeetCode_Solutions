class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> ans;
        vector<int> mp(26,-1);
        for(int i=0;i<n;i++){
            int id=s[i]-'a';
            mp[id]=i;
        }
        int i=0;
        int j=0;
        int end=0;
        while(i<n){
            end=max(end,mp[s[i]-'a']);
            if(i==end){
                ans.push_back(end-j+1);
                j=end+1;
            }
            i++;
        }
        return ans;
    }
};