class SmallestInfiniteSet {
public:
priority_queue<int,vector<int>,greater<int>> pq;
unordered_set<int> s;
int l;
    SmallestInfiniteSet() {
      pq.push(1);
      s.insert(1);
      l=0;  
    }
    
    int popSmallest() {
        int n=pq.top();
        if(n==l+1){
            l++;
            pq.push(n+1);
        }
        pq.pop();
        s.erase(n);
        return n;
    }
    
    void addBack(int num) {
        if(num<=l&&s.count(num)==0){
            s.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */