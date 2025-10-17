using u16=unsigned short;
struct Data
{
    u16 segCnt=0;
    bitset<26> hasC=0;
    u16 cnt;
    Data(u16 segCnt=0, bitset<26> hasC=0, u16 cnt=0): segCnt(segCnt), hasC(hasC), cnt(cnt){}
};
class Solution 
{
public:
    static int maxPartitionsAfterOperations(string& s, int k) 
    {
        const int n=s.size();
        vector<Data> pref(n), suff(n);
        int seg=0, cnt=0;
        bitset<26> mask=0;
        for(int i=0; i<n-1; i++)
        {
            const int idx=s[i]-'a';
            if (mask[idx]==0)
            {
                if (++cnt>k)
                {
                    seg++;
                    cnt=1;
                    mask=0;
                }
                mask[idx]=1;
            }
            pref[i+1]=Data(seg, mask, cnt);
        }
        seg=cnt=0;
        mask=0;
        for (int i=n-1; i>0; i--)
        {
            const int idx=s[i]-'a';
            if (mask[idx]==0){
                if (++cnt>k)
                {
                    seg++;
                    cnt=1;
                    mask=0;
                }
                mask[idx]=1;
            }
            suff[i-1]=Data(seg, mask, cnt);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            auto& [segL, Lmask, Lcnt]=pref[i];
            auto& [segR, Rmask, Rcnt]=suff[i];
            int seg=segL+segR+1;
            int bz=(Lmask|Rmask).count();
            int add=(min(bz+1, 26)<=k)?0:((Lcnt==k && Rcnt==k && bz<26)?2:1);
            ans=max(ans, seg+add);
        }
        return ans;
    }
};