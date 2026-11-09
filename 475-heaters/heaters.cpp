class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());

        int ans=0;

        for(int i=0;i<houses.size();i++){
            int idx=lower_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin();

            int d1=INT_MAX,d2=INT_MAX;

            if(idx<heaters.size())
                d1=abs(heaters[idx]-houses[i]);

            if(idx>0)
                d2=abs(heaters[idx-1]-houses[i]);

            ans=max(ans,min(d1,d2));
        }

        return ans;
    }
};