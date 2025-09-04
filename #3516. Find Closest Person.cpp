class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x-z)>abs(y-z))
        return 2;
        else if(abs(x-z)<abs(y-z))
        return 1;
        else
         return 0;
    }
};