class Solution {
public:
struct TrieNode{
    unordered_map<string,TrieNode*> children;
    bool flag=false;
};
void insert(TrieNode* root,const vector<string>& path){
    TrieNode* node=root;
    for(const string& name:path){
        if(!node->children.count(name))
        node->children[name]=new TrieNode();
    node=node->children[name];
    }
}
string encode(TrieNode* root,unordered_map<string,vector<TrieNode*>> &mp){
    if(root->children.empty()) return "()";
    vector<string> parts;
    for(auto& [key,child]:root->children){
        parts.push_back(key+encode(child,mp));
    }
    sort(parts.begin(),parts.end());
    string str="("+accumulate(parts.begin(),parts.end(),string())+")";
    mp[str].push_back(root);
    return str;
}
void dupli(unordered_map<string,vector<TrieNode*>> &mp){
    for(auto& [root,nodes]:mp){
        if(nodes.size()>1){
            for(auto node:nodes){
                node->flag=true;
            }
        }
    }
}
void collect(TrieNode* root,vector<string> curr,vector<vector<string>>& ans){
    for(auto& [key,child]:root->children){
        if(child->flag==true)
        continue;
        curr.push_back(key);
        ans.push_back(curr);
        collect(child,curr,ans);
        curr.pop_back();
    }
}
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root=new TrieNode();
        for(auto ele:paths){
            insert(root,ele);
        }
        unordered_map<string,vector<TrieNode*>> mp;
        encode(root,mp);
        dupli(mp);
        vector<string> curr;
        vector<vector<string>> ans;
        collect(root,curr,ans);
        return ans;
    }
};