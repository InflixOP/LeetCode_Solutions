class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int curr=1;
        int w=1;
        while(n){
            cout<<curr<<endl;
            ans+=curr;
            if(curr-w+1==7){
                curr=w+1;
                w++;
            }else
            curr++;
            n--;
        }
        return ans;
    }
};