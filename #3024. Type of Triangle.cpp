class Solution {
    public:
        string triangleType(vector<int>& nums) {
            unordered_set<int> st;
            sort(nums.begin(),nums.end());
            for(int i=0;i<3;i++)
            st.insert(nums[i]);
            if(nums[0]+nums[1]<=nums[2])
            return "none";
            else if(st.size()==1)
            return "equilateral";
            else if(st.size()==2)
            return "isosceles";
            else 
            return "scalene";
        }
    };