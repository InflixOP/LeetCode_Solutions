class Solution {
public:
    void help(int i,int curr,vector<int>& nums,int maxi,int &c){
        if(i==nums.size()){
            if(curr==maxi)
            c++;
            return;
        }
        help(i+1,curr|nums[i],nums,maxi,c);
        help(i+1,curr,nums,maxi,c);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi=maxi|nums[i];
        }
        int c=0;
        help(0,0,nums,maxi,c);
        return c;
    }
};