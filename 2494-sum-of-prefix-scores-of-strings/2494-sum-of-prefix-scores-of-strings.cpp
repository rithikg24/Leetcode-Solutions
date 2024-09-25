class TrieNode{
public:
    TrieNode* child[26];
    int countChild;

    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        countChild=0;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void insert(string word){
        TrieNode* node=root;
        for(auto c:word){
            int index=c-'a';
            if(node->child[index]==nullptr){
                node->child[index]=new TrieNode();
            }
            node=node->child[index];
            node->countChild++;
        }
    }

    int getScore(string word){
        int count=0;
        TrieNode* node=root;
        for(auto c:word){
            int index=c-'a';
            node=node->child[index];
            count+=node->countChild;
        }
        return count;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;

        for(auto word:words){
            trie.insert(word);
        }

        for(auto word:words){
           int count=trie.getScore(word);
           ans.push_back(count);
        }

        return ans;
    }
};