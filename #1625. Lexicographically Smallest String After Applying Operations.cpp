class Solution {
public:
    string addfunction(string s, int a) {
        string p = "";

        for (int i = 0; i < s.size(); i++){
            if (i%2 == 1){
                p += ((s[i]-'0')+a)%10 + '0';
            } else {
                p += s[i];
            }
        }

        return p;
    }

    string rotatefunction(string s, int b) {
        b = b%s.size();

        string x = s.substr(b);

        string y = s.substr(0,b);

        return x + y;
    }

    string findLexSmallestString(string s, int a, int b) {
        string p = s;

        queue<string> q;
        set<string> visited;

        q.push(s);
        visited.insert(s);

        while (!q.empty()){
            auto node = q.front();
            q.pop();

            p = min(p,node);

            string newfirsts = addfunction(node,a);
            string newseconds = rotatefunction(node,b);

            if (!visited.contains(newfirsts)){
                q.push(newfirsts);
                visited.insert(newfirsts);
            }

            if (!visited.contains(newseconds)){
                q.push(newseconds);
                visited.insert(newseconds);
            }
        }

        return p;
    }
};