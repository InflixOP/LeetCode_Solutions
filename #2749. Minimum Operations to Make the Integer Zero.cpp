class Solution {
public:
    bool pos(long long mid,long long num1,long long num2){
        if((mid*1LL*num2)>num1)return false;
        num1-=(mid*1LL*num2);
        if(num1<0)return false;
        if(num1<mid)return false;
        long long setbits=0;
        while(num1>0){
            if(num1&1)setbits++;
            num1>>=1;
        }
        return mid>=setbits;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(long long i=1;i<=60;i++){
            if(pos(i,num1,num2))return i;
        }
        return -1;
    }
};