class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> help;
        for(int i=0;i<s.length();i++){
            if(s[i]==c)
            help.push_back(i);
        }
        int n=help.size();
        int i=0;
        vector<int> ans;
        for(int j=0;j<s.length();j++){
            if(i+1<help.size()){
            if(abs(help[i]-j)<abs(help[i+1]-j))
            ans.push_back(abs(help[i]-j));
            else{
                ans.push_back(abs(help[i+1]-j));
                i++;
            }}
            else
            ans.push_back(abs(help[i]-j));
        }
        return ans;
    }
};