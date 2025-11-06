class Solution {
public:
  vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    vector<int> id(c+1, -1), ans;
    vector<vector<int>> g(c+1);
    for(auto &c: connections) g[c[0]].push_back(c[1]), g[c[1]].push_back(c[0]);

    vector<set<int>> t;
    for(int i = 1, idx = 0; i <= c; ++i)
      if(id[i] == -1){
        set<int>st; 
        queue<int>q;
        q.push(i);
        while(!q.empty()){
          int n = q.front(); q.pop();
          if(id[n] != -1) continue;
          id[n] = idx;
          st.insert(n);
          for(int next: g[n]) q.push(next);
        }
        ++idx;
        t.push_back(st);
      }

    for(auto &q: queries){
      set<int> *st = &t[id[q[1]]]; 

      if(q[0] == 2) st->erase(q[1]);
      else if(st->count(q[1])) ans.push_back(q[1]); 
      else if(st->empty())     ans.push_back(-1);
      else                     ans.push_back(*st->begin());
    }

    return ans;  
  }
};