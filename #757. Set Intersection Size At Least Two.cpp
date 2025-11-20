#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){
                if(a[1] == b[1]) return a[0] > b[0];
                return a[1] < b[1];
             });

        vector<int> nums;  

        for(auto &it : intervals){
            int start = it[0], end = it[1];

            
            int countInside = nums.end() - lower_bound(nums.begin(), nums.end(), start);

           
            countInside -= (nums.end() - upper_bound(nums.begin(), nums.end(), end));

           
            while(countInside < 2){
                nums.push_back(end - (1 - countInside)); 
                countInside++;
            }

            sort(nums.begin(), nums.end()); 
        }

        return nums.size();
    }
};