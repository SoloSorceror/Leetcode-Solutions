class Solution {
public:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        auto [word, steps] = q.front();
        q.pop();

        if (word == endWord) return steps;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (dict.find(word) != dict.end()) {
                    q.push({word, steps + 1});
                    dict.erase(word); // mark visited
                }
            }

            word[i] = original; // restore
        }
    }
    return 0;
}

};