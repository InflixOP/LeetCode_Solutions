class Solution {
public:
    string makeFancyString(string s) {
        string r;
        int c=0;
        for(int i=0;i<s.size();i++) {
            if(i>0&&s[i]==s[i-1]) {
                c++;
            }else{
                c=1;
            }
            if(c<=2)r+=s[i];
        }
        return r;
    }
};