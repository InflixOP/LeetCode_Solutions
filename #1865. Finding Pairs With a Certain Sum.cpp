class FindSumPairs {
private:
    vector<int> num1;
    vector<int> num2;
    unordered_map<int, int> mp; 

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        for (int i = 0; i < num2.size(); i++) {
            mp[num2[i]]++;
        }
    }

    void add(int index, int val) {
        int oldVal = num2[index];
        mp[oldVal]--;
        if (mp[oldVal] == 0) {
            mp.erase(oldVal);
        }

        num2[index] += val;
        mp[num2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (int i = 0; i < num1.size(); i++) {
            int target = tot - num1[i];
            if (mp.find(target) != mp.end()) {
                cnt += mp[target];
            }
        }
        return cnt;
    }
};