class Trie {
public:
struct Trie1{
    Trie1* child[26]={}; 
    string word="";
};
Trie1* root;
    Trie() {
        root = new Trie1();
    }
    
    void insert(string word1) {
        Trie1* root1=root;
        for(auto i:word1){
        if(!root1->child[i-'a']){root1->child[i-'a']=new Trie1();}
        root1=root1->child[i-'a'];
        }
        root1->word=word1;
    }
    
    bool search(string word1) {
         Trie1* root1=root;
        for(auto i:word1){
            if(!root1->child[i-'a']){return false;}
            else{root1=root1->child[i-'a'];}
        }
      if(root1->word!=word1){return false;}
      return true;
    }
    
    bool startsWith(string word1) {
         Trie1* root1=root;
        for(auto i:word1){
            if(!root1->child[i-'a']){return false;}
            else{root1=root1->child[i-'a'];}
        }
      return true;
    }
};