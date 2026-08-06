class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>visited;
        queue<string>q;
        visited.insert(startGene);
        q.push(startGene);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endGene){
                    return level;
                }
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.size();i++){
                        string next=curr;
                        next[i]=ch;
                        if(visited.find(next)==visited.end() && bankset.find(next)!=bankset.end()){
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
        
    }
};