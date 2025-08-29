class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty(); 
        auto const pchar=p[0];
        if (p.size()>=2&&p[1]=='*') {
            return (s.size()&&(pchar== '.'||s[0]==pchar)&&isMatch(s.substr(1),p))||isMatch(s, p.substr(2)) ; 
        } 
        return s.size()&&(pchar=='.'||s[0]==pchar)&&isMatch(s.substr(1),p.substr(1));
    }
};