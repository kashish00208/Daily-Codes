class Solution {
public:
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;
    vector<vector<string>> findLadders(string beginWord , string endWord , vector<string>&wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        b = beginWord;
        queue<string>q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        int size = beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word==endWord)break;
            for(int i=0;i<size;i++){
                char original = word[i];
                for(char ch='a'; ch<='z';ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps +1;
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
    void dfs(string word,vector<string>seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }   
        int steps = mpp[word];
        int size = word.size();
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
};

vector<int>dfs(int node , vector<vector<int>>adj,vector<int>&visited,vector<int>&ans){
    visited[node] = 1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,ans);
        }
    }

}
