class SegmentTree{
    const int mod = 1e9 +7;
    vector<int>nums;
    vector<int>seg;
    
    public:
    SegmentTree(vector<int>& arr){
        nums = arr;
        int n = nums.size();
        seg.resize(4*n);
        build(0 , n-1 , 0);
    }

    void build(int left ,int right , int index){

        if(left == right){
            seg[index] = nums[left];
            return ;
        }

        int mid = (left + right)>>1;

        build(left ,mid, 2*index +1);
        build(mid +1, right, 2*index +2);

        seg[index] = (1LL*seg[2*index +1]* seg[2*index +2])% mod;
    }

    int queryResolve(int l , int r ,int i, int left ,int right){
        //if out of required range

        if(l > right || r < left)return 1;

        if( l>= left && r <= right)return seg[i];

        int m = (l +r)>>1;
        
        return (1LL*queryResolve(l , m, 2*i +1, left ,right) * queryResolve(m +1 , r, 2*i +2, left ,right))% mod;
    }
};

class Solution {
 const int mod = 1e9 +7;   
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powerOfTwo;

        int num = n;
        int pos = 0;

        while(num >0){
            int bit = num %2;
            
            if(bit == 1){
                powerOfTwo.push_back(pow(2, pos));
            }
            num /= 2;
            pos++;
        }

        SegmentTree *sgt = new SegmentTree(powerOfTwo);

        vector<int>ans;
        int m = powerOfTwo.size();

        for(auto q : queries){

            int res = sgt->queryResolve(0 ,m-1,0, q[0],q[1]);
            ans.push_back(res);
        }

        return ans;
    }
};



/*
    
    const int mod = 1e9 +7;   
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powerOfTwo;

        int num = n;
        int pos = 0;

        while(num >0){
            int bit = num %2;
            
            if(bit == 1){
                powerOfTwo.push_back(pow(2, pos));
            }
            num /= 2;
            pos++;
        }
        
        int m = powerOfTwo.size();
        vector<int>prefixProd(m +1, 1);

        for(int i =1; i<= m ;i++){

           prefixProd[i] = (1LL*prefixProd[i-1]*powerOfTwo[i-1])% mod;
        }

        vector<int>ans;
        
        for(auto q : queries){
            
            int numerator = prefixProd[q[1] +1] % mod;
            int denominator = prefixProd[q[0]];
            int inv = modPow(denominator, mod -2);

            ans.push_back((1LL*numerator* inv)%mod);
        }

        return ans;
    }

    private:
    long long modPow(int base ,int exp){

        int b = base;
        int e = exp;
        long long result =1;

        while(e >0){

            if(e %2 ==0){
                b = (1LL*b*b) %mod;
                e /=2;
            }else{
                 result = (1LL*result *b)% mod;
                 e--;
            }
        }

        return result;
    }

*/