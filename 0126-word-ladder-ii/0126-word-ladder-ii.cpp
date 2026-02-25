class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;

    void dfs(string word, string beginWord, vector<string>& path){
        if(word == beginWord){
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for(string &par : parents[word]){
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return {};

        queue<string> q;
        q.push(beginWord);

        unordered_map<string,int> level;
        level[beginWord] = 0;

        int wordLen = beginWord.size();
        bool found = false;

        while(!q.empty() && !found){

            int size = q.size();
            unordered_set<string> usedThisLevel;

            while(size--){
                string word = q.front();
                q.pop();

                int currLevel = level[word];
                string originalWord = word;

                for(int i=0;i<wordLen;i++){
                    char originalChar = word[i];

                    for(char ch='a'; ch<='z'; ch++){
                        word[i] = ch;

                        if(st.find(word) != st.end()){

                            if(level.find(word) == level.end()){
                                level[word] = currLevel + 1;
                                q.push(word);
                                usedThisLevel.insert(word);
                            }

                            if(level[word] == currLevel + 1){
                                parents[word].push_back(originalWord);
                            }

                            if(word == endWord)
                                found = true;
                        }
                    }

                    word[i] = originalChar;
                }
            }

            for(auto &w : usedThisLevel)
                st.erase(w);
        }

        if(!found) return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return ans;
    }
};