class Solution {
    public:
        string answerString(string word, int n) {
            if(n==1)
            return word;
            int s=word.size();
            int maxi=s-n+1;
            string ans="";
            for(int i=0;i<n;i++){
                string sample=word.substr(i,maxi);
                if(sample>ans)
                ans=sample;
            }
            return ans;
        }
    };