class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        string prev=words[0];
        vector<string> ans;
        vector<int> v1(26,0);
        for(int i=0;i<n;i++){
            string curr=words[i];
            vector<int> v2(26,0);
            for(int i=0;i<curr.size();i++){
                v2[curr[i]-'a']++;
            }

            bool check=false;
            if(i!=0){
            for(int i=0;i<26;i++){
                if(v1[i]!=v2[i]){
                    check=true;
                    break;
                }
            }
            }
            if(check || i==0){
                ans.push_back(curr);
            }
            for(int i=0;i<v2.size();i++){
                v1[i]=v2[i];
            }
        }
        return ans;
    }
};