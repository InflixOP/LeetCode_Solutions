class Solution {
    public:
        string robotWithString(string s) {
            unordered_map<char,int> mp;
            for(char ch:s){
                mp[ch]++;
            }
            string res="";
            char mini='a';
            stack<char> st;
            for(char ch:s){
                st.push(ch);
                mp[ch]--;
                while(mini!='z'&&mp[mini]==0) mini++;
                while(!st.empty()&&st.top()<=mini){
                    res+=st.top();
                    st.pop();
                }
            }
            return res;
        }
    };