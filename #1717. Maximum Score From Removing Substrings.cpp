class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        if(y>x){
            swap(x,y);
            for(int i=0;i<s.size();i++){
                if(s[i]=='b') s[i]='a';
                else if(s[i]=='a') s[i]='b';
            }
        }
        int ans=0;
        string str="";
        for(auto ele:s){
            if(!st.empty()&&ele=='b'&&st.top()=='a'){
                st.pop();
                ans+=x;
            }else
            st.push(ele);
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        for(auto ele:str){
            if(!st.empty()&&ele=='a'&&st.top()=='b'){
                st.pop();
                ans+=y;
            }else
            st.push(ele);
        }
        return ans;
    }
};