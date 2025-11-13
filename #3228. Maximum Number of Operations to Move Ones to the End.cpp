class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, c1 = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                if(i > 0 && s[i-1] == '0') ans += c1;
                c1++;
            }
        }
        return ans + (s[s.size()-1] == '0' ? c1 : 0);
    }
};