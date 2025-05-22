class Solution {
    public:
        int maxScore(vector<int>& vec, int k) {
            int l=0;
            int n=vec.size();
            for(int i=0;i<k;i++){
                l+=vec[i];
            }
            int maxi=0;
            int r=0;
            int i=1;
            while(i<=k){
                maxi=max(maxi,l+r);
                l-=vec[k-i];
                r+=vec[n-i];
                i++;
            }
            maxi=max(maxi,l+r);
            return maxi;
        }
    };