class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [current , level] = q.front();
            q.pop();
            for(int i =0;i<current.size();i++){
                string temp = current;
                for(char ch='a';ch<='z';ch++){
                    temp[i] = ch;
                    if(temp==endWord)return level+1;
                    if(words.find(temp)!=words.end()){
                        q.push({temp,level+1});
                        words.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};