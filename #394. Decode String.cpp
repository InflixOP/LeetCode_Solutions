class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;
        string curr="";
        int c=0;
        for(char ele:s){
            if(isdigit(ele))
            c=c*10+(ele-'0');
            else if(ele=='['){
                str.push(curr);
                num.push(c);
                curr="";
                c=0;
            }
            else if(ele==']'){
                string prev=str.top();
                str.pop();
                int rep=num.top();
                num.pop();
                string temp="";
                for(int i=0;i<rep;i++)
                temp+=curr;
                curr=prev+temp;
            }
            else
            curr+=ele;
        }    
        return curr;
    }
};