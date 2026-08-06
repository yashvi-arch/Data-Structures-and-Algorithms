class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>visited;
        queue<string>que;
        que.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();
                if(curr==endGene){
                    return level;
                }
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.size();i++){
                        string next=curr;
                        next[i]=ch;

                        if(visited.find(next)==visited.end() && bankset.find(next)!=bankset.end()){
                            visited.insert(next);
                            que.push(next);
                        }
                    }
                }

            }
            level++;
        }
        return -1;
        
    }
};