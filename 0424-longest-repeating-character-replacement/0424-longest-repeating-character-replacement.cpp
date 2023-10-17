class Solution {
public:
    int characterReplacement(string s, int k) {
         int maxLen = 0;
        int maxCount = 0;
        int start = 0;
       unordered_map<char, int> m;

        for (int end = 0; end < s.length(); ++end) {
            m[s[end]]++;

            maxCount = max(maxCount, m[s[end]]);

            if (end - start + 1 - maxCount > k) {
                m[s[start]]--;
                start++;
            }

            maxLen =max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};