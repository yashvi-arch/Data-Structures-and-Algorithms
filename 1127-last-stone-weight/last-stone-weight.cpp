class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq; //maxheap

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]); //populate pq
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();

            int y=pq.top();
            pq.pop();

            if(x!=y){
                pq.push(abs(x-y));
            }else{
                continue;
           }
        }
        if(pq.empty()){
            return 0;
        }else{
            return pq.top();
        }
        

        
    }
};