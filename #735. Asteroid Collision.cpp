class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
           stack<int> st;
           int n=asteroids.size();
           for(int i=0;i<n;i++){
            bool check=false;
                while(!st.empty()&&asteroids[i]<0&&st.top()>0){
                    if(asteroids[i]+st.top()==0){
                    st.pop();
                    check=true;
                    break;
                    }
                    else if(abs(asteroids[i])>abs(st.top()))
                    {
                        st.pop();
                        continue;
                    }
                    else{
                    check=true;
                    break;
                    }
                }
                if(!check)
                st.push(asteroids[i]);
           } 
           vector<int> ans(st.size());
           for(int i=st.size()-1;i>=0;i--)
           {
            ans[i]=st.top();
            st.pop();
           }
           return ans;
        }
    };