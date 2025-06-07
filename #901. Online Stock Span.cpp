class StockSpanner {    
    public:
        StockSpanner() {
        }
        stack<pair<int,int>> stk;
        int next(int price) {
            int idx = 1;
            while(!stk.empty() && stk.top().first<=price) {
                idx += stk.top().second;
                stk.pop();
            }
            stk.push({price,idx});
            return idx;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */