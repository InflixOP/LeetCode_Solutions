class Solution {
public:
static bool cmp(int a,int b){
    if(a%2==0&&b%2!=0)
    return true;
    else 
    return false;
}
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        return nums;
    }
};