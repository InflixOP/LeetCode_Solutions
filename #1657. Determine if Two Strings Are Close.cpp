class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int frq[26] = {0}, frq2[26] = {0};

        for(auto ch: w1) frq[ch-'a']++;
        for(auto ch: w2) frq2[ch-'a']++;
        
        for(int i=0; i<26; i++){
            if((frq[i] && !frq2[i]) || (!frq[i] && frq2[i])) return false;
            bool f = false;
            for(int j=0; j<26; j++){
                if(frq[i] == frq2[j]){
                    f = true;
                    frq[i] = -1; 
                    frq2[j] = -2;
                }
            }
            if(!f) return false;
        }
        return true;
    }
};