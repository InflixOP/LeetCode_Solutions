class Solution {
public:
    int ksize(int n){
        int k = -1;
        while(n){ 
            n >>= 1;
            ++k; 
        }
        return k;
    }

    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        int k = ksize(n);
        int Gx = (1 << (k + 1)) - 1;
        return Gx - minimumOneBitOperations(n ^ (1 << k));
    }
};