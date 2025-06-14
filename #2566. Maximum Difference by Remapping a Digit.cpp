class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string s2=s;
        char ch=s[0];
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==ch){
                s[i]='0';
            }
        }
        int mini=stoi(s);
        char ch2=s2[0];
        for(int i=0;i<n;i++){
            if(s2[i]!='9'){
                ch2=s2[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(s2[i]==ch2){
                s2[i]='9';
            }
        }
        int maxi=stoi(s2);
        cout<<maxi<<" "<<mini<<endl;
        return maxi-mini;
    }
};