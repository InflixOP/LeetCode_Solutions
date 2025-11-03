class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int pointer1 = 0,pointer2 = 1;
        int n = colors.size();
        while(pointer2<n) {
            if(colors[pointer1] == colors[pointer2]){
                if(neededTime[pointer1]<=neededTime[pointer2]) {
                    ans+=neededTime[pointer1];
                    pointer1=pointer2;
                    pointer2++;
                }
                else{
                    ans+=neededTime[pointer2];
                    pointer2++;
                }
            }
            else{
                pointer1=pointer2;
                pointer2++;
            }
        }
        return ans;
    }
};