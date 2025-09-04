class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res = 0;
        vector<bool> arr(n, false);
        arr[0] = true;

        vector<vector<int>> m(n);
        for(const auto& val: connections){
            m[val[0]].push_back(-1*val[1]);
            m[val[1]].push_back(val[0]);
        }

        stack<int> stk;
        stk.push(0);

        while(!stk.empty()){
            int curr = stk.top();
            stk.pop();
            for(const auto& elem: m[curr]){
                if(!arr[abs(elem)]){
                    if(elem < 0) res++;
                    arr[abs(elem)] = true;
                    stk.push(abs(elem));
                }
            }
        }

        return res;
    }
};