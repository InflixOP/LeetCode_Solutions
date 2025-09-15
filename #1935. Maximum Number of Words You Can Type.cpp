class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    stringstream ss(text);
    vector<string> words;
    string word;
    while(ss>>word){ 
        words.push_back(word);
    } 
    int c1=0;
    unordered_set<char> st;
    for(char c:brokenLetters)
    st.insert(c);
    for(auto ele:words){
        for(char c:ele){
            cout<<c<<endl;
            if(st.find(c)!=st.end()){
                c1++;
                break;
            }
        }
    }
    return words.size()-c1;
    }
};