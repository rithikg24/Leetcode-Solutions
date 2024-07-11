class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());

        while(!q.empty()){
            string word = q.front().first;
            int lev = q.front().second;
            q.pop();

            if(word==endWord) return lev;

            for(int i=0;i<word.length();i++){
                char ori = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i]=c;
                    if(word[i]==ori) continue;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,lev+1});
                    }
                }
                word[i]=ori;
            }
        }

        return 0;
    }
};