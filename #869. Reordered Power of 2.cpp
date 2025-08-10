class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());

        for(int i=0;i<31;i++){
            int pow2=1<<i;
            string t=to_string(pow2);
            sort(t.begin(),t.end());
            if(s==t)return true;
        }
        return false;
    }
};