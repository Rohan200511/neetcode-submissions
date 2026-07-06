class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        int m = endWord.length();
        int p = wordList.size();

        unordered_set<string>st(wordList.begin() , wordList.end());
        
        queue<pair<string , int>>q;
        q.push({beginWord , 1});
        if(st.contains(beginWord)) st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i = 0 ; i < word.length() ; i++){
                char ch = word[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    word[i] = c;

                    if(st.contains(word)){
                        q.push({word , steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};
