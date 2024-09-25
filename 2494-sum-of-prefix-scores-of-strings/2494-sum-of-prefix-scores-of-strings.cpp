class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        int count = 0;
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        // Build the Trie and count the prefixes
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
                node->count++;
            }
        }
        // Calculate the sum of prefix scores for each word
        vector<int> res;
        for (const string& word : words) {
            TrieNode* node = root;
            int total = 0;
            for (char c : word) {
                int idx = c - 'a';
                node = node->children[idx];
                total += node->count;
            }
            res.push_back(total);
        }
        // Clean up the Trie to prevent memory leaks
        deleteTrie(root);
        return res;
    }
    
private:
    void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (TrieNode* child : node->children)
            deleteTrie(child);
        delete node;
    }
};
