class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0;
        int b=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){ //can bloom
                cnt++;

            }else{
                b+=(cnt/k); //count b
                cnt=0; //set to 0
            }
        }
        b+=(cnt/k);
        return (b>=m); //t or f

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=((long long)m*(long long)k);
        if(val>bloomDay.size()){ //never ever possible
            return -1;
        }
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        int b=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
        
    }
};