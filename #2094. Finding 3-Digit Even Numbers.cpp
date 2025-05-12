class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        int arr[10]={0};
        for(int i:digits){
            arr[i]++;
        }
        for(int i=100;i<999;i+=2){
            int f=i%10,s=(i/10)%10,th=(i/100)%10;
            if(arr[f]){
                arr[f]--;
                if(arr[s]){
                    arr[s]--;
                    if(arr[th]){
                        arr[th]--;
                        ans.push_back(i);
                        arr[th]++;
                    }
                    arr[s]++;
                }
                arr[f]++;
            }
        }
        return ans;
    }
};