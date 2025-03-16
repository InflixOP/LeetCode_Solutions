class Solution {
public:
    bool check(vector<int>& ranks, int cars,long long mid){
        long long c=0;
    for(int i=0;i<ranks.size();i++){
        c+=sqrt(mid/ranks[i]);
    }
    return c>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
       int n=ranks.size();
        int maxi=*max_element(ranks.begin(),ranks.end());
        long long l=1;
        long long r=1LL*maxi*cars*cars;
        long long result=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(ranks,cars,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};