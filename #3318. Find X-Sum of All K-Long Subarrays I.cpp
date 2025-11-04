#define PII pair<int,int>

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> freq(51,0);
        for(int i=0;i<k;i++)
            freq[nums[i]]++;
        priority_queue<PII> pq;
        for(int i=0;i<=50;i++)
            if(freq[i])
                pq.push({freq[i],i});
        vector<int> ans;
        int tmp=0;
        for(int i=0;i<x && !pq.empty();i++){
            auto t = pq.top();
            //cout<<t.first<<" ";
            tmp+=t.first*t.second;
            pq.pop();
        }
        while(!pq.empty())
            pq.pop();
        ans.push_back(tmp);
        int p=0,q=k;
        while(q<nums.size())
        {
            freq[nums[p]]--;
            freq[nums[q]]++;
            for(int i=0;i<=50;i++)
                if(freq[i])
                    pq.push({freq[i],i});
            tmp=0;
            for(int i=0;i<x && !pq.empty();i++){
                auto t = pq.top();
                //cout<<t.first<<" ";
                tmp+=t.first*t.second;
                pq.pop();
            }
            while(!pq.empty())
                pq.pop();
            ans.push_back(tmp);
            p++,q++;
        }
        return ans;
    }
};