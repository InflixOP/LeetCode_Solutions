class Solution {
public:
    bool doesAliceWin(string s) { 
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                return true;
            }
        }
        
        return false;
    }
};