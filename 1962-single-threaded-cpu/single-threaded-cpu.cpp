class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedTasks;
        for(int i=0;i<n;i++){
            int start_time=tasks[i][0];
            int processing_time=tasks[i][1];
            sortedTasks.push_back({start_time,processing_time,i});

        }
        sort(begin(sortedTasks),end(sortedTasks));

        vector<int>result;

        long long current_time=0;
        int idx=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //minheap
        while(idx<n || !pq.empty()){ //jabtak limit me h
            if(pq.empty() && current_time<sortedTasks[idx][0]){ //start kro first element ke starttime se
                current_time=sortedTasks[idx][0]; //banado usko time
            }
            while(idx<n && sortedTasks[idx][0]<=current_time){ //within the range aarha h agar
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]}); //pq me daalo
                idx++; //aage badho
            }
            pair<int,int>current_task=pq.top(); //currently yahi kiya perform cpu ne
            pq.pop();
            current_time+=current_task.first;
            result.push_back(current_task.second);

        }
        return result;
        
    }
};