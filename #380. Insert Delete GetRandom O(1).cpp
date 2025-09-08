class RandomizedSet {
public:
    unordered_set<int> set;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (set.count(val)) return false;
        set.insert(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = set.find(val);
        if (it != end(set)) set.erase(it);
        return it != end(set);
    }
    
    int getRandom() {
        int x = rand() % set.size();
        return *next(begin(set), x);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */