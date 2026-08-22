class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+2,0);
        for(auto &b:bookings){
            int L=b[0];
            int R=b[1];
            int seats=b[2];

            diff[L]+=seats;
            diff[R+1]-=seats;


        }
        for(int i=1;i<diff.size();i++){
            diff[i]+=diff[i-1];
        }
        return vector<int>(diff.begin()+1,diff.end()-1);
        
    }
};