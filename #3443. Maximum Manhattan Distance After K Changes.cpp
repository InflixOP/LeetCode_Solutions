class Solution {
public:
    int maxDistance(string s, int k) {
        pair<int,int>p={0,0};
        int manh=0;
        for(auto i:{'N','S'}){
            for(auto j:{'E','W'}){
                int t=k;int x=0;int y=0;
                for(auto c:s){
                   if(!(c==i||c==j)&&t>0){
                    int dx1=x,dy1=y;
                    if(i=='N')dy1++;
                    else dy1--;
                   int dx2=x,dy2=y;
                    if(j=='E')dx2++;
                    else dx2--;
                    int d1=abs(dx1)+abs(dy1);
                    int d2=abs(dx2)+abs(dy2);
                    if(d1>d2)c=i;
                    else c=j;
                    t--;
                   }
                   if(c=='N')y++;
                   else if(c=='S')y--;
                   else if(c=='E')x++;
                   else if(c=='W')x--;
                   manh=max(manh,abs(x)+abs(y));
                }      
            }
        }
        return manh;
    }
};