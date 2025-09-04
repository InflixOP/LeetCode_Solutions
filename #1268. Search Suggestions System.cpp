class Node {
public:
    vector<Node*> links;
    bool end;

    Node() {
        links.resize(26, nullptr);
        end = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* next(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->next(ch);
        }
        node->end = true;
    }

    // DFS helper to collect suggestions
    void dfs(Node* node, string& curr, vector<string>& ans) {
        if (!node || ans.size() == 3) return;

        if (node->end) ans.push_back(curr);
        if (ans.size() == 3) return;

        for (int i = 0; i < 26; i++) {
            if (node->links[i]) {
                curr.push_back('a' + i);
                dfs(node->links[i], curr, ans);
                curr.pop_back();  // backtrack
                if (ans.size() == 3) return; // stop early
            }
        }
    }

    vector<string> find(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return {}; // no such prefix
            node = node->next(ch);
        }

        vector<string> ans;
        string curr = prefix;
        dfs(node, curr, ans);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Step 1: Insert all products
        Trie trie;
        for (string& prod : products) {
            trie.insert(prod);
        }

        // Step 2: For each prefix of searchWord, collect top 3 suggestions
        vector<vector<string>> result;
        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;
            result.push_back(trie.find(prefix));
        }
        return result;
    }
};