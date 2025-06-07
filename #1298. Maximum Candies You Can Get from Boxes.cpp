class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            queue<int> q;
            int ans=0;
            for(int i=0;i<initialBoxes.size();i++)
            q.push(initialBoxes[i]);
            int c=q.size();
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                c--;
                 if(status[curr]==1){
                for(int i=0;i<containedBoxes[curr].size();i++){
                q.push(containedBoxes[curr][i]);
                initialBoxes.push_back(containedBoxes[curr][i]);
                c++;
                }
                for(int i=0;i<keys[curr].size();i++){
                status[keys[curr][i]]=1;
                c++;
                }
                 }
                 else
                 q.push(curr);
                 if(c==0)
                 break;
                 else
                 c=q.size();
            }
            for(int i=0;i<initialBoxes.size();i++){
                if(status[initialBoxes[i]])
                ans+=candies[initialBoxes[i]];
            }
            return ans;
        }
    };