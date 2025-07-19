class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        string str=folder[0];
        ans.push_back(str);
        for(int i=1;i<folder.size();i++) {
            string s=folder[i];
            if(s.size()>str.size()&&s.substr(0,str.size())==str&&s[str.size()]=='/') {
                continue; 
            } else {
                ans.push_back(s);
                str=s; 
            }
        }
        return ans;
    }
};