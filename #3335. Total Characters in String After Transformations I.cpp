#define mod 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> count(26,0);
        for(char c:s)
        count[c-'a']++;
        for(int i=0;i<t;i++){
            int z=count[25];
            for(int j=24;j>=0;j--){
                count[j+1]=count[j];
            }
            count[1]=(count[1]+z)%mod;
            count[0]=z;
        }
        long long total=0;
        for(int i=0;i<26;i++){
            total=(total+count[i])%mod;
        }
        return total;
    }
};