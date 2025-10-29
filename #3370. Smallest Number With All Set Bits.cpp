class Solution {
public:
    int smallestNumber(int n) {
        int nBit=0;
        int x=n;
        while(x>0){
            
        x=x/2;
        nBit++;
        }
        return pow(2,nBit)-1;
      
      
    }
};