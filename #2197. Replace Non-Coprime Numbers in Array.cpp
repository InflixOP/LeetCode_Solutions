class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            int t=nums[i];
            while(!st.empty() && __gcd(st.top(),t)>1){
                t=(t/(__gcd(st.top(),t)))*st.top();
                st.pop();
            }
            st.push(t); 
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};