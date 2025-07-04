class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lens;
        long long len=1;
        for(int op:operations){
            len*=2;
            lens.push_back(len);
            if(len>=k) break;
        }
        char ch='a';
        for(int i=lens.size()-1;i>=0;--i){
            len/=2;
            if(k>len){
                k-=len;
                if(operations[i]!=0) {
                    ch=(ch=='z')?'a':ch+1;
                }
            }
        }
        return ch;
    }
};