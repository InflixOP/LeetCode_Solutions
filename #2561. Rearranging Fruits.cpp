class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long ans=0;
        int n=basket1.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto ele:basket1){
            mp1[ele]++;
        }
        for(auto ele:basket2){
            mp2[ele]++;
        }
        for(auto ele:basket1){
            if(mp2.find(ele)!=mp1.end()){
            mp2[ele]--;
            if(mp2[ele]==0)
            mp2.erase(ele);
            }
        }
        for(auto ele:basket2){
             if(mp1.find(ele)!=mp1.end()){
            mp1[ele]--;
            if(mp1[ele]==0)
            mp1.erase(ele);
             }
        }
        for(auto& ele:mp1){
            if(ele.second%2!=0)
            return -1;
            else{
            ele.second/=2;
            }
        }
        for(auto& ele:mp2){
            if(ele.second%2!=0)
            return -1;
            else{
            ele.second=ele.second/2;;
            }
        }
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        for(int i=0;i<n;i++){
            if(mp1.find(basket1[i])!=mp1.end()){
                mp1[basket1[i]]--;
                if(mp1[basket1[i]]==0)
                mp1.erase(basket1[i]);
                v1.push_back({basket1[i],i});
            }
        }
         for(int i=0;i<n;i++){
            if(mp2.find(basket2[i])!=mp2.end()){
                 mp2[basket2[i]]--;
                if(mp2[basket2[i]]==0)
                mp2.erase(basket2[i]);
                v2.push_back({basket2[i],i});
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<pair<int,int>>());
        int min1=*min_element(basket1.begin(),basket1.end());
        int min2=*min_element(basket2.begin(),basket2.end());
        int mini=min(min1,min2);
        int i=0;
        while(i<v1.size()){
            cout<<v1[i].first<<" "<<v2[i].first<<endl;
            ans+=min(2*mini,min(v1[i].first,v2[i].first));
            i++;
        }
        return ans;
    }
};