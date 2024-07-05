class Trienode {
    public:
        unordered_map <char, Trienode*>* children;
        bool isEndofWord;
        Trienode(){
            children = new unordered_map<char, Trienode*>();
            isEndofWord = false;
        }
};

class Trie {
public:
    Trienode *root;

    Trie() {
       root = new Trienode();
    }
    
    void insert(string word) {
        Trienode* currnode = root;

         for (char c : word) {
        if (currnode->children->find(c) == currnode->children->end()) {
            currnode->children->emplace(c, new Trienode());
        }
        currnode = (*currnode->children)[c];
    }
        currnode->isEndofWord = true;
    }
    
    bool search(string word) {
        Trienode* currnode = root;

        for (auto c: word){
            if (currnode->children->find(c) == currnode->children->end())
                return false;
            currnode = (*currnode->children)[c];
        }
        return currnode->isEndofWord;
    }
    
    bool startsWith(string prefix) {
        Trienode* currnode = root;

        for (auto c: prefix){
            if (currnode->children->find(c) == currnode->children->end())
                return false;
            currnode = (*currnode->children)[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
