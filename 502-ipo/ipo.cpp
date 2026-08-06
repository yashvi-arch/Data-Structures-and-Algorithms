class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        priority_queue<int>maxheap;
        for(int i=0;i<profits.size();i++){
            minheap.push({capital[i],profits[i]});
        }
        while(k>0){
            while(!minheap.empty() && minheap.top().first<=w){
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
            if(maxheap.empty()){
                break;
            }
            w+=maxheap.top();
            maxheap.pop();
            k--;

        }
        return w;

        
    }
};