struct TrieNode {
    TrieNode* children[26] = {};
    string* word;
    void addWord(string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = &word;
    }
};