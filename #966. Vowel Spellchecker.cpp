class Solution {
public:  
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        unordered_set<string> s;

        for (auto it : wordlist) {
            s.insert(it);
        } 

        unordered_set<string> s2;
        map<string,int> mp;

        for (int i = 0; i < wordlist.size(); i++) {
            string curr = wordlist[i];
            transform(curr.begin(), curr.end(), curr.begin(), ::tolower); 
            if (mp.find(curr) == mp.end()) mp[curr] = i;  // store first occurrence
            s2.insert(curr);
        }

        map<string,int> mp2;
        set<string> s3;

        for (int i = 0; i < wordlist.size(); i++) {
            string curr = "";
            for (int j = 0; j < wordlist[i].size(); j++) {
                if (wordlist[i][j]=='a'|| wordlist[i][j]=='A'|| wordlist[i][j]=='e'|| wordlist[i][j]=='E'|| 
                    wordlist[i][j]=='i'|| wordlist[i][j]=='I'|| wordlist[i][j]=='o'|| wordlist[i][j]=='O'|| 
                    wordlist[i][j]=='u'|| wordlist[i][j]=='U') {
                    curr += '*';
                } else {
                    curr += tolower(wordlist[i][j]);
                }
            } 
            if (mp2.find(curr) == mp2.end()) mp2[curr] = i;
            s3.insert(curr);
        }
     
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            string curr = "";
            string temp = queries[i];
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

            string temp3 = "";
            for (int j = 0; j < queries[i].size(); j++) {
                if (queries[i][j]=='a'|| queries[i][j]=='A'|| queries[i][j]=='e'|| queries[i][j]=='E'|| 
                    queries[i][j]=='i'|| queries[i][j]=='I'|| queries[i][j]=='o'|| queries[i][j]=='O'|| 
                    queries[i][j]=='u'|| queries[i][j]=='U') {
                    temp3 += '*';
                } else {
                    temp3 += tolower(queries[i][j]);
                }
            }
        
            if (s.find(queries[i]) != s.end()) {
                curr = queries[i];
            } else if (s2.find(temp) != s2.end()) {
                curr = wordlist[mp[temp]];
            } else if (s3.find(temp3) != s3.end()) {
                curr = wordlist[mp2[temp3]];
            }
            ans.push_back(curr);
        }

        return ans;
    }
};