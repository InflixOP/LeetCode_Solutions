class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int c=0;
            while(low<=high){
                string m=to_string(low);
                if(m.length()%2==0){
                    int sum=0;
                    for(int i=0;i<m.length()/2;i++)
                    sum+=m[i]-'0';
                    for(int i=m.length()/2;i<m.length();i++)
                    sum-=m[i]-'0';
                    if(sum==0)
                    c++;
                }
                low++;
            }
            return c;
        }
    };