class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        string s1=s;
        while(s.length()<k){
            int n=s.length();
            for(int i=0;i<n;i++){
                s+='a'+((s[i]-'a')%26+1);
            }
        }
        return s[k-1];
    }
};