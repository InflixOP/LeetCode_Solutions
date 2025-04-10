typedef long long ll;
class Solution {
public:
    ll computePowerfulInteger(string&num,int&limit,string&s){
        if(num.length()<s.length()) return 0;
        if(num.length()==s.length()) return num>=s;
        int prefixLen=num.length()-s.length();
        ll count=0;
        string suffix=num.substr(num.length()-s.length(),s.length());
        for(int i=0;i<prefixLen;++i){
            if(limit<(num[i]-'0')){
                count+=(ll)pow(limit+1,prefixLen-i);
                return count;
            }
            else count+=(ll)(num[i]-'0')*(ll)pow(limit+1,prefixLen-i-1);
        }
        if(suffix>=s) ++count;
        return count;
    }
    ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
        string _start_=to_string(start-1);
        string _finish_=to_string(finish);
        ll hi=computePowerfulInteger(_finish_,limit,s);
        ll lo=computePowerfulInteger(_start_,limit,s);
        return hi-lo;
    }
};