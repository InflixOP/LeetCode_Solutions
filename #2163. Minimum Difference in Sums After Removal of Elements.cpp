class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int l=nums.size();
        vector<long long> prefix_min(l,1e15);
        vector<long long> suffix_max(l,-1e15);
        long long ans=1e15;
        priority_queue<long long,vector<long long>,greater<long long>> min_pq;
        priority_queue<long long> pq;
        long long sum=0;
        for(int i=0;i<l/3;i++)
        {
            pq.push((long long)nums[i]);
            sum+=(long long)nums[i];
        }
        prefix_min[(l/3)-1]=sum;
        for(int i=l/3;i<(2*l)/3;i++)
        {
            if(pq.top()>nums[i])
            {
                sum-=pq.top();
                sum+=nums[i];
                pq.pop();
                pq.push(nums[i]);
            }
            prefix_min[i]=sum;
        }
        sum=0;
        for(int i=l-1;i>=(2*l)/3;i--)
        {
            min_pq.push((long long)nums[i]);
            sum+=(long long)nums[i];
        }
        suffix_max[(2*l)/3]=sum;
        for(int i=((2*l)/3)-1;i>=l/3;i--)
        {
            if(min_pq.top()<nums[i])
            {
                sum-=min_pq.top();
                sum+=nums[i];
                min_pq.pop();
                min_pq.push(nums[i]);
            }
            suffix_max[i]=sum;
        }   
        for(int i=(l/3)-1;i<((2*l)/3)+1;i++)
        {
            if(i+1<l and ans>prefix_min[i]-suffix_max[i+1]) ans=prefix_min[i]-suffix_max[i+1];
        }
        return ans;

    }
};