class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char,int> mp;
            for(int i=0;i<t.length();i++){
                mp[t[i]]++;
            }
            int l=0,r=0;
            int c=0,mini=INT_MAX,si=-1;
            while(r<s.length()){
                if(mp[s[r]]>0) 
                c++;
                mp[s[r]]--;
                while(c==t.length()){
                    if(r-l+1<mini){
                        mini=r-l+1;
                        si=l;
                    }
                    mp[s[l]]++;
                        if(mp[s[l]]>0)
                        c--;
                        l++;
                }
                r++;
            }   
            if(si==-1)
            return "";
            else
            return s.substr(si,mini);
        }
    };