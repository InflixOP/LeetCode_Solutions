
class Router {
    using Packet = tuple<int,int,int>; 
    queue<Packet> q;
    set<Packet> st;  
    unordered_map<int, vector<int>> dl; 
    int lmt=0;

public:
    Router(int memoryLimit) {
        lmt = memoryLimit;
    }

    bool addPacket(int s, int d, int ts) {
        Packet t = {s,d,ts};
        if(st.count(t)) return false; 

        if(q.size() >= lmt) {
            st.erase(q.front());
            auto [a,b,c] = q.front();
            auto &vec = dl[b];
            if(!vec.empty() && vec.front() == c)
                vec.erase(vec.begin());
            q.pop();
        }
        q.push(t);
        st.insert(t);
        dl[d].push_back(ts); 
        return true;
    }

    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto [a,b,c] = q.front(); q.pop();
        st.erase({a,b,c});
        auto &vec = dl[b];
        auto it = lower_bound(vec.begin(), vec.end(), c);
        if(it != vec.end() && *it == c) vec.erase(it);

        return {a, b, c};
    }

    int getCount(int d, int s, int e) {
        auto &vec = dl[d];
        int l = lower_bound(vec.begin(), vec.end(), s) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), e) - vec.begin();
        return r - l;
    }
};