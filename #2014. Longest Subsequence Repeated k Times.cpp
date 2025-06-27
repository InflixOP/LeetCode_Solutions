class Solution {

private:
bool canMakeSequence(string temp,string s,int k){
    int j=0;
    for(int i=0;i<s.length();i++){

        if(s[i]==temp[j]){
            j++;
        }
        if(j>=temp.length()){
            k--;
            j=0;
            if(k==0)return true;
        }

    }

    return false;
}
void solve(vector<int>arr,string temp,string &ans,int maxLen,string &s,vector<int>freq,int k){
    if(temp.size()>maxLen)return ;
    ///when we cant make a subsequence from a given string then also return

    if(temp.size()>0 && !canMakeSequence(temp,s,k))return ;
    //if ans len greater then repalce a ans;
    if(temp.length()>ans.length())ans=temp;

    //iterate on the arr;
    for(auto i:arr){

        temp.push_back(i+'a');
        freq[i]-=k;
        //solve a question
        solve(arr,temp,ans,maxLen,s,freq,k);

        //backtrack
        temp.pop_back();
        freq[i]+=k;

    }
} 

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        //first make a freq array 
        vector<int>freq(26,0);

        //fill the freq; 
        for(int i=0;i<s.length();i++){
            int val=s[i]-'a';
            freq[val]++;

        }
        
        //now make a array of vallues which have  freq>=k and we have to fill in opposite dorectcion so that we get 
        //larget possible string
        vector<int>arr;
        for(int i=25;i>=0;i--){
            if(freq[i]>=k)arr.push_back(i);
        }
        //return ans;
        string ans;
        int maxLen=s.length()/k;

        solve(arr,"",ans,maxLen,s,freq,k);
        return ans;
    }
};