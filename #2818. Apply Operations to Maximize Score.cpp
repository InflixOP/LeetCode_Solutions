const int N=sqrt(100000);
vector<bool> isPrime(N+1, 1);
vector<int> prime;
class Solution {
public:
    const int mod=1e9+7;
    //Use Eratosthenes' sieve method
    void Sieve(){
        if (prime.size()>0) return ;
        isPrime[0]=isPrime[1]=0;
        const int n_sqrt=int(sqrt(N));
        for(int i=2; i<=n_sqrt; i++){
            if (isPrime[i]){
                prime.push_back(i);
                for(int j=i*i ; j<=N; j+=i)
                    isPrime[j]=0;
            }
        }
        for(int i=n_sqrt+1; i<=N; i++)
            if (isPrime[i]) prime.push_back(i);
    }

    //computing prime score
    int prime_score(int x){
        if (x<=N && isPrime[x]) return 1;
        int xsqrt=sqrt(x);
        int cnt=0;
        for(int p: prime){
            if (p>xsqrt) break;
            if (x%p!=0) continue;
            while (x%p==0){
                x/=p;
            }
            cnt++;
        }
        cnt+=(x>1);
        return cnt;
    }

    long long modPow(long long x, int exp) {
        if (x == 0) return 0;
        if (exp == 0) return 1;
        long long a = (exp % 2 == 1) ? x : 1;
        return modPow(x * x % mod, exp / 2) * a % mod;
    }

    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        Sieve();

        vector<int> score(n), left(n), right(n);
        for (int i = 0; i < n; i++) {
            score[i] = prime_score(nums[i]);
        }

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[i] > score[st.top()]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[i] >= score[st.top()]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<pair<int, int>> num_idx(n);
        for(int i=0; i<n; i++)
            num_idx[i]={nums[i], i};
        sort(num_idx.begin(), num_idx.end(), greater<pair<int, int>>());

        long long ans=1;
        for(int i=0; i<n && k>0; i++){
            auto [x, idx]=num_idx[i];
            int exp=min((long long)(idx-left[idx])*(right[idx]-idx), (long long)k);
            ans=(ans*modPow(x, exp)%mod);
            k-=exp;
        }
    //    cout<<"k="<<k<<endl;
        return ans; 
    }
};