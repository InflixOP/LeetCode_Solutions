class Solution {
    public:
        string clearStars(string s) {
            unordered_map<char,priority_queue<int>> mp;
            priority_queue<char,vector<char>,greater<char>> pq;
            int n=s.length();
            for(int i=0;i<n;i++)
            {
                if(s[i]=='*')
                {
                    s[i]='{';
                    int idx=mp[pq.top()].top();
                    if(mp[pq.top()].size())
                    {
                        mp[pq.top()].pop();
                        s[idx]='{';
                    }
                    pq.pop();
                }
                else
                {
                    pq.push(s[i]);
                    mp[s[i]].push(i);
                }
            }
            string ans="";
            for(int i=0;i<n;i++)
                if(s[i]!='{')
                    ans+= s[i];
            return ans;
        }
    };