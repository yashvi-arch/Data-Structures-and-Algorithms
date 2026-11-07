class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int till_max=0;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>mat[till_max][mid]){
                    till_max=i;
                }
            }
            if(mid>0 && mat[till_max][mid]<mat[till_max][mid-1]){
                high=mid-1;
            }else if(mid<n-1 && mat[till_max][mid]<mat[till_max][mid+1]){
                low=mid+1;
            }else{
                return {till_max,mid};
            }
        }
        return {};
        
    }
};