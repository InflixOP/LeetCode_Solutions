class Solution {
    public:
    static bool cmp(vector<int> a,vector<int> b){
                if(a[1]>b[1])
                return true;
                return false;
            }
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            int n=boxTypes.size();
            sort(boxTypes.begin(),boxTypes.end(),cmp);
            int i=0;
            int ans=0;
            while(truckSize>0&&i<n)
        {
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                ans+=boxTypes[i][0]*boxTypes[i][1];
            }else{
                ans+=boxTypes[i][1]*truckSize;
                truckSize=0;
            }
            i++;
        }
        return ans;
        }
    };