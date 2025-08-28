class Solution {
public: 
   int t[1001][1001]; 
   bool solve(string& s,int i,int j){
    if(i>=j)return true;
    if(t[i][j]!=-1)return t[i][j];
    if(s[i]==s[j]){
        return t[i][j] = solve(s,i+1,j-1);
    }else{
        return t[i][j]=false;
    }

   }
    string longestPalindrome(string s) {
        int sp=0;
        int maxLen = 0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxLen){
                        maxLen = j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};