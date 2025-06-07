class Fenwick{
private:
    vector<long long> fenw;
    int n;
public:
    Fenwick(int n) : n(n), fenw(n + 1, 0){}
    void update(int idx, long long val){
        idx++;
        while (idx <= n){
            fenw[idx] += val;
            idx += idx & -idx;
        }
    }
    long long query(int idx) const{
        long long sum = 0;
        idx++;
        while (idx > 0){
            sum += fenw[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    long long countLess(int idx) const{
        return (idx > 0) ? query(idx - 1) : 0;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long res = 0;
        vector<int> idx_map(n);
        for (int i = 0; i < n; i++){
            idx_map[nums1[i]] = i;
        }
        for (int i = 0; i < n; i++){
            nums2[i] = idx_map[nums2[i]];
        }
        Fenwick fenw(n);
        for (int i = 0; i < n; i++){
            int num = nums2[n - 1 - i];
            long long smallerCount = fenw.countLess(num);
            long long biggerCount = i - smallerCount;
            long long diffCount = num - smallerCount;
            res += biggerCount * diffCount;
            fenw.update(num, 1);
        }
        return res;
    }
};