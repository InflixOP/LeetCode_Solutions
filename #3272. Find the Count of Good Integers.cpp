class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;

        int d = (n+1)/2;
        int start = pow(10,d-1);
        int end = pow(10,d)-1;

        for(int num = start; num<=end; num++){
            string leftHalf = to_string(num);
            string full = "";

            if(n%2 == 0){
                // n=4 --> 12 21
                string rightHalf = leftHalf; //12
                reverse(rightHalf.begin(), rightHalf.end());//21
                full = leftHalf + rightHalf; //12 21
            }else{
                // 123 21
                string rightHalf = leftHalf.substr(0,d-1);
                reverse(rightHalf.begin(), rightHalf.end());//21
                full = leftHalf + rightHalf; //123 21
            }

            //check div by k then palindrome/good
            long long number = stoll(full); // 123 21
            if(number % k !=0)
                continue;
            
            sort(full.begin(), full.end());
            st.insert(full);
        }

        //factorial precompute
        vector<long long> factorial(11,1);
        for(int i=1;i<11;i++){
            factorial[i] = factorial[i-1] * i;
        }

        long long result = 0;
        //set par jao and saare palindrome ko pakdo
        for(auto &s: st){
            // to store the frequency of all
            vector<int> count(10,0);
            for(auto &ch: s){
                count[ch - '0']++;
            }

            int totalDigits = s.length();
            int zeroDigits = count[0];
            int nonZeroDigits = totalDigits- zeroDigits;

            long long perm = (nonZeroDigits * factorial[totalDigits-1]);

            for(int i=0;i<10;i++){
                perm /= factorial[count[i]];
            }
            result +=  perm;
        }
        return result;

    }
};