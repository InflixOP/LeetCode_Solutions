class Solution {
public:
bool help(int a){
    while(a>0){
        if(a%10==0) return false;
        a/=10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(help(i)&&help(n-i))
            return {i,n-i};
        }
        return {0,0};
    }
};