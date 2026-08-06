class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset(wordList.begin(),wordList.end());
        unordered_set<string>visited;
        queue<string>que;
        visited.insert(beginWord);
        que.push(beginWord);
        int level=1;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();
                if(curr==endWord){
                    return level;
                }
                for(char ch='a';ch<='z';ch++){
                    for(int i=0;i<curr.size();i++){
                        string next=curr;
                        next[i]=ch;
                        if(visited.find(next)==visited.end() && wordset.find(next)!=wordset.end()){
                            visited.insert(next);
                            que.push(next);
                        }
                    }
                }

            }
            level++;
        }
        return 0;
        
    }
};