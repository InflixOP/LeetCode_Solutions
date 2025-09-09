class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            cout<<s[i]<<" "<<s[j]<<endl;
            if(isalnum(s[i])&&isalnum(s[j])){
                s[i]=tolower(s[i]);
            s[j]=tolower(s[j]);
                if(s[i]==s[j]){
                    i++;
                    j--;
                }else
                return false;
            }
            else if(!isalnum(s[i])&&isalnum(s[j])){
                i++;
            }
            else if(isalnum(s[i])&&!isalnum(s[j])){a
                j--;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};