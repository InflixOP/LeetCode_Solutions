class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> vec(37, 0);
        for(int i=1; i<=n; i++) {
            int temp = i;
            int sum = 0;
            while(temp) {
                sum += temp%10;
                temp /= 10;
            }
            vec[sum]++;
        }
        sort(vec.begin(), vec.end());
        int cnt = 0;
        int ele = vec[36];
        for(int i=36; i>=0; i--) {
            if(ele == vec[i]) {
                cnt++;
            }else break;
        }
        return cnt;
    }
};