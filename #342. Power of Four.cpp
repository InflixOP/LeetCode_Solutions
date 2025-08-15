class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1 )return true;
        if(n<=0)return false;
        int cnt=0;
        int ind=0;
         for(int i=0;i<=31;i++){
            if(n>>i & 1){
                cnt++;
                if(cnt>1)return false;
                ind = i;
            }
         }
         return ind % 2 !=1;
    }
};