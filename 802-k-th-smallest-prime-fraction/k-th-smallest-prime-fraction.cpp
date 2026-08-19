class Solution {
public:
    typedef pair<double,pair<int,int>>p;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        set<pair<int,int>>st;
        pq.push({(double)arr[0]/arr[n-1],{0,n-1}});
        st.insert({0,n-1});
        int cnt=0;
        while(!pq.empty()){
            p curr=pq.top();
            pq.pop();
            double fraction=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            cnt++;
            if(cnt==k){
                return {arr[i],arr[j]};
            }
            if(i+1<j && st.find({i+1,j})==st.end()){
                st.insert({i+1,j});
                pq.push({(double)arr[i+1]/arr[j],{i+1,j}});
            }
            if(i<j-1 && st.find({i,j-1})==st.end()){
                st.insert({i,j-1});
                pq.push({(double)arr[i]/arr[j-1],{i,j-1}});
            }

        }
        return {};

        
    }
};