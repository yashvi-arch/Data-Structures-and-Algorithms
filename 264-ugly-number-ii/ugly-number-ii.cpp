class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long>st;
        priority_queue<long long,vector<long long>,greater<long long>>pq;

        st.insert(1);
        pq.push(1);

        for(int count=1;count<n;count++){
            long long x=pq.top();
            pq.pop();

            for(int i:{2,3,5}){
                long long y=x*i;
                if(st.find(y)==st.end()){
                    st.insert(y);
                    pq.push(y);
                }
            }
        }
        return pq.top();
        
    }
};