class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0){
            int s=0-n/2;
            while(n>0){
                ans.push_back(s);
                s++;
                n--;
            }
        }else{
            int s=0-n/2;
            while(n>0){
                ans.push_back(s);
                s++;
                if(s==0)
                s++;
                n--;
            }
        }
        return ans;
    }
};