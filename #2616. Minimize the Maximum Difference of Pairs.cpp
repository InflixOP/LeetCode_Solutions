class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)
        return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int m=l+(r-l)/2,pair=0;
            for(int i=1;i<n;i++){
                if(m>=nums[i]-nums[i-1])
                pair++,i++;
            }
            if(pair>=p)
            r=m;
            else 
            l=m+1;
        }
        return l;
    }
};