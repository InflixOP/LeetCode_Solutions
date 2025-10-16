class Solution {
    struct TrieNode{
        bool end;
        vector<TrieNode*> children=vector<TrieNode*>(26);
        TrieNode(){
            end = false;
            for(int i=0;i<26;++i){
                children[i] = nullptr;
            }
        }
    };
    
    void buildTrie(TrieNode* root, vector<string> &words){
        for(auto & word: words){
            TrieNode* front = root;
            for(auto &c: word){
                int idx = c-'a';
                if(front->children[idx]==nullptr){
                    front->children[idx] = new TrieNode();
                }
                front = front->children[idx];
            }
            front->end = true;
        }
    }

    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void search(vector<vector<char>>& board, vector<vector<bool>>& vis, TrieNode* root, vector<string> &ans, int x, int y, string & res){
        if(vis[x][y])return;
        TrieNode* front = root->children[board[x][y]-'a'];
        if(front==nullptr)return;
        vis[x][y]=true;
        res.push_back(board[x][y]);
        if(front->end == true){
            ans.push_back(res);
            front->end = false;
        }
        for(int i =0;i<4;++i){
            int xx = x+dir[i][0], yy = y+dir[i][1];
            if(xx<0||xx==board.size()||yy<0||yy==board[0].size()){
                continue;
            }
            search(board, vis, front, ans, xx, yy, res);
        }
        vis[x][y]=false;
        res.pop_back();
        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<string> ans;
        buildTrie(root, words);
        string res = "";
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0; i<board.size(); ++i){
            for(int j = 0; j<board[0].size(); ++j){
                search(board, vis, root, ans, i, j, res);
            }
        }
        return ans;
    }
};