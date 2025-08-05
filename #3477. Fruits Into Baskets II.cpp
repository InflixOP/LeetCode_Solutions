class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i])
                {
                    baskets[j]=0;
                    c++;
                    break;
                }
            }
        }
        return n-c;
    }
};