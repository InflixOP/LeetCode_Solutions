class Solution {
public:
    //TC = O(n *logn)    &&   SC = O(k)

    long long sum = 0; //maintains sum of top x elements from main set
    set<pair<int, int>> main; //contains top-x freq, elements
    set<pair<int, int>> second; //contains remaining freq, leements

    void insertIntoSet(const pair<int, int> &p, int x) {
        if(main.size() < x || p > *main.begin()) {
            sum += 1LL * p.first * p.second;
            main.insert(p);

            if(main.size() > x) {
                auto smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second;
                main.erase(smallest);
                second.insert(smallest);
            }
        }
        else {
            second.insert(p);
        }
    }

    void removeIntoSet(const pair<int, int> &p, int x) {
        if(main.count(p)) {
            sum -= 1LL * p.first * p.second;
            main.erase(p);

            if(!second.empty()) {
                auto largest = *second.rbegin();
                second.erase(largest);
                main.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        }
        else {
            second.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> mp;
        vector<long long> ans;

        int i = 0;
        int j = 0;

        //Khandani Sliding Window
        while(j < n) {
            if(mp[nums[j]] > 0) {
                removeIntoSet({mp[nums[j]], nums[j]}, x);
            }

            mp[nums[j]]++;
            insertIntoSet({mp[nums[j]], nums[j]}, x);

            if(j-i+1 == k) { //Shrink The Window
                ans.push_back(sum);

                removeIntoSet({mp[nums[i]], nums[i]}, x);
                mp[nums[i]]--;

                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                else {
                    insertIntoSet({mp[nums[i]], nums[i]}, x);
                }

                i++;
            }

            j++;
        }

        return ans;
    }
};