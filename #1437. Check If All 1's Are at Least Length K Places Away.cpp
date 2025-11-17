class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int st = 0;int lst ;
        while(st<nums.size()){
            if(nums[st] == 1){
                lst = st;
                break;
            }
            st+=1;
        }
        st+=1;
        k+=1;
        while(st<nums.size()){
            if(nums[st] ==  1){
                if((st - lst) < k ){
                    return 0;
                }
                lst = st;
            }
            st+=1;
        }
        return 1;
    }
};