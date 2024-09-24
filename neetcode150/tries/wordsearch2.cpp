struct TrieNode{
    unordered_map<char, TrieNode*> next;
    bool isEndofWord = false;
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;

        for (char ch: word){
            if(!node->next.count(ch))
                node->next[ch] = new TrieNode();
            node = node->next[ch];
        }

        node->isEndofWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size(), l = words.size();
        unordered_set<string> result;
        
        Trie trie;
        for(string word: words)
            trie.insert(word);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                string s = "";
                dfs(board, trie.root, result, i, j, s);
            }
        return vector<string>(result.begin(), result.end());
    }

private:
    vector<int> coord = {-1,0,1,0,-1};
    void dfs(vector<vector<char>>& board, TrieNode* node, unordered_set<string>& op, int i, int j, string s){
        if (i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || board[i][j] == '#')
            return;

        char ch = board[i][j];
        if (!node->next[ch])
            return;
        
        node = node->next[ch];
        s+=ch;
        if (node->isEndofWord){
            op.insert(s);
            node->isEndofWord = false; // to avoid repetitions
        }
        
        board[i][j] = '#';
        for(int k=0; k<4; k++)
            dfs(board, node, op, i+coord[k], j+coord[k+1], s);
        board[i][j] = ch;
        
    }
};
