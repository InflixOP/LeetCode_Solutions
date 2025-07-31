class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;
        for (int i:arr){
            unordered_set<int>nxt;
            nxt.insert(i);
            for(auto it:prev)
            {
                nxt.insert(it|i);
            }
            result.insert(nxt.begin(),nxt.end());
            prev=nxt;
        }
        return result.size();
    }
};