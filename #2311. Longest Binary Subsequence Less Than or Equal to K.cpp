class Solution {
    string binary(long long n) {
        if (n == 0) return "0";  // handle edge case
        string s = "";
        while (n) {
            s += '0' + (n % 2);
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        string t = binary(k);
        cout<<t<<endl;
        int m = t.size();
        if (m > n) {
            return n;
        }
        int start = n - m;
        int ans = 0;
        int cnt = 0;
        for (int i = start; i < n; i++) {
            if (t[i - start] > s[i]) { //if at any position t[i] > s[i] we can take all further chars in s
                cnt += n - i;
                break;
            } else if (s[i] == t[i - start]) {
                cnt++;
                //one more case is that char at s[i] == t[i] we increase our cnt by one
            }
        }
        int ind = m;
        for(int i=0;i<m;i++){
            if(t[i]=='1'){
                ind=i;
                break;
            }
        }
//in the end this might be the case that starting from the first occurance of 1 in t we skip the corresponding occurance in string s and take the whole string t after that
        int c = m-ind-1;
        cnt = max(cnt,c);

        for (int i = 0; i < start; i++) {
            if (s[i] == '0') ans++;
        }

        return ans+cnt;
       
    }
};