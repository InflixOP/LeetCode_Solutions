struct SegmentTree {
    vector<int>tree;
    SegmentTree(int size) {
        tree.resize(4*size);
    }

    void buildTree(vector<int>& arr, int treeI, int treeL, int treeR) {
        if (treeL == treeR) {
            tree[treeI] = arr[treeL];
            return;
        }
        int treeM = (treeR-treeL)/2 + treeL;
        buildTree(arr, 2*treeI, treeL, treeM);
        buildTree(arr, 2*treeI+1, treeM+1, treeR);
        tree[treeI] = max(tree[2*treeI],tree[2*treeI+1]);
    }

    int queryMax(int treeI, int treeL, int treeR, int l, int r) {
        if (l > r) return INT_MIN;
        if (l==treeL && r==treeR) return tree[treeI];
        int treeM = (treeR-treeL)/2 + treeL;
        return max(queryMax(2*treeI, treeL, treeM, l, min(treeM, r)), 
                    queryMax(2*treeI+1, treeM+1, treeR, max(treeM+1, l), r));
    }

    void updateMax(int newVal, int arrI, int treeI, int treeL, int treeR) {
        int treeM = (treeR-treeL)/2 + treeL;
        if (treeL==treeR && treeL == arrI) {
            tree[treeI] = newVal;
            return;
        }
        if (arrI <= treeM) {
            updateMax(newVal, arrI, 2*treeI, treeL, treeM);
        } else {
            updateMax(newVal, arrI, 2*treeI+1, treeM+1, treeR);
        }
        tree[treeI] = max(tree[2*treeI], tree[2*treeI+1]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size()-1;
        int res = baskets.size();
        auto s = SegmentTree(baskets.size());
        s.buildTree(baskets, 1, 0, n);
        for (auto f : fruits) {
            // too big
            if (f > s.queryMax(1, 0, n, 0, n)) continue;
            int l = 0, r = n;
            while (l < r) {
                int m = (r-l)/2 + l;
                if (f <= s.queryMax(1, 0, n, l, m)) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            res--;
            s.updateMax(-1, l, 1, 0, n);
        }
        return res;
    }
};