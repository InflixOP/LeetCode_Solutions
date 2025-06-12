class Solution {
public:
    int hammingWeight(int n) {
        int counter=0;
        for(int i=0;i<32;++i){
            counter+=(n&1);
            n=n>>1;
        }
        return counter;
    }
};