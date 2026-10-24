class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ansrow;
        long long ans=1;
        ansrow.push_back(1);
        for(int col=1;col<=rowIndex;col++){
            ans=ans*(rowIndex-col+1);
            ans=ans/(col);
            ansrow.push_back(ans);
        }
        return ansrow;
        
    }
};