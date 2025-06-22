class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
      int i=0;
      int rem=s.size()%k;
      int add=k-rem;
      while(rem!=0&&add--)s+=fill;
      vector<string> ans;
      while(i<s.size()){
        int start=i;
        int end=i+k-1;
        string str;
        for(int j=start;j<=end;j++)str+=s[j];
        ans.push_back(str);
        i=i+k;
      }  
      return ans;
    }
};