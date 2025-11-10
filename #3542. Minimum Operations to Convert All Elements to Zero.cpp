class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int cnt=0;

        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            // if(ele==0) continue;

            while(!st.empty() && st.top()>ele){
                st.pop();
                cnt++;
            }

            if(st.empty() || st.top()!=ele){
                st.push(ele);
            }
        }
        while(!st.empty()){
            int a = st.top();
            st.pop();
            
            if(a!=0) cnt++;
        }

        return cnt;
    }
};