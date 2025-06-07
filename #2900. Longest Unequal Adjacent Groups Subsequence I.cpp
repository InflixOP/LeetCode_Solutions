class Solution {
    public:
        vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
         int n=words.size();
        vector<int> zero;
        vector<int> one;
        int num=1;
        for(int i=0;i<n;i++){
            if(groups[i]==num){
                one.push_back(i);
                num=1-num;
            }
        }
        num=0;
        for(int i=0;i<n;i++){
            if(groups[i]==num){
                zero.push_back(i);
                num=1-num;
            }
        }
        vector<string> ans;
        if(zero.size()>one.size()){
            for(int i:zero)
            ans.push_back(words[i]);
        }else{
            for(int i:one)
            ans.push_back(words[i]);
        }
        return ans;
        }
    };