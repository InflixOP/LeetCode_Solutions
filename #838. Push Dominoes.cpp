class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string res;
        int prev = 0;
        for (int curr = 1; curr < dominoes.size(); ++curr) {
            if (dominoes[curr] == '.') {
                continue;
            }
            int sp = curr - prev - 1;
            if (prev > 0) 
                res += dominoes[prev];

            if (dominoes[prev] == dominoes[curr]) {
                res += string(sp, dominoes[prev]);
            }
            else if (dominoes[prev] == 'L' && dominoes[curr] == 'R') {
                res += string(sp, '.');
            }
            else { 
                res += string(sp / 2, 'R')
                     + string(sp % 2, '.')
                     + string(sp / 2, 'L');
            }
            prev = curr;
        }
        return res;   
    }
};