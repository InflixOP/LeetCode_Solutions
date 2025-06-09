class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> de;
        queue<int> re;
        for(int i=0;i<n;i++){
            if(senate[i]=='R')
            re.push(i);
            else
            de.push(i);
        }
        while(!de.empty()&&!re.empty()){
            int di=de.front();
            int ri=re.front();
            if(ri>di)
            de.push(di+n);
            else
            re.push(ri+n);
            de.pop();
            re.pop();
        }
        return de.empty()?"Radiant":"Dire";
    }
};