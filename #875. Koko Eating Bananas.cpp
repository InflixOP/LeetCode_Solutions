class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int m=l+(r-l)/2;
            int hrs=0;
            for(int pile:piles)
            hrs+=(pile+m-1)/m;
            if(hrs<=h)
            r=m;
            else
            l=m+1;
        }
        return l;
    }
};