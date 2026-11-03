class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int d=1;
            int total=0;
            for(int i=0;i<n;i++){
                if(total+weights[i]<=mid){
                    total+=weights[i];
                }else{
                    d++;
                    total=weights[i];
                }
            }
            if(d<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
        
    }
};