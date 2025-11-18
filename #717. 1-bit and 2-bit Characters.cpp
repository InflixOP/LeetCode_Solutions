class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int cur_idx = 0;
        while(cur_idx<n){
            if(cur_idx==n-1) return true;
            else{
                if(bits[cur_idx]==0){
                    cur_idx+=1;
                }else{
                    cur_idx+=2;
                }

            }

        }
        return false;
    }
};