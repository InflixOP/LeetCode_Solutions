class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            int n2=queries.size();
            vector<int> v(n+1,0);
            for(int i=0;i<n2;i++){
                v[queries[i][0]]++;
                v[queries[i][1]+1]--;
            }
            for(int i=1;i<=n;i++)
            v[i]+=v[i-1];
            for(int i=0;i<n;i++){
                if(v[i]<nums[i])
                return false;
            }
            return true;
        }
    };