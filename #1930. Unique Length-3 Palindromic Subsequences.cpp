class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<bool>> avl(26 , vector<bool> ( 26 , false));
        vector<int> cnt(26);
        for(char ch : s){
            cnt[ch- 'a']++;
        }
        int ans = 0 ;
        vector<int> prevCnt(26 ,  0);
        for(int i = 0 ; i < s.size() ; i++){
            int curr = s[i] - 'a';
            cnt[curr]--;
            for(int j = 0 ; j < 26 ; j++){
                if(prevCnt[j]  > 0 && cnt[j] > 0){
                    avl[curr][j] = true;
                }
            }
            prevCnt[curr]++;
        }
        for(int i = 0; i < 26 ; i++){
            ans += count(avl[i].begin() , avl[i].end() , true);
        }
        return ans ;
    }
};