class Solution {
    bool bs(vector<int>& nums,vector<int>& temp,int k,int n){
        for(int i=k-1;i<n-k;i++){
            int j=i;
            int l=i+1;
            if(((temp[j]-temp[j-(k-1)]) == k-1) && ((temp[l+(k-1)]-temp[l])== k-1 ) ){
                return true;
            }
        }
        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int r=(n/2)+1;
        vector<int> temp(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                temp[i]=temp[i-1]+1;
            }
        }
        int ans=INT_MIN;
        while(l<=r){
            int m=(l+r)/2;
            if(bs(nums,temp,m,n)){
                ans=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
};