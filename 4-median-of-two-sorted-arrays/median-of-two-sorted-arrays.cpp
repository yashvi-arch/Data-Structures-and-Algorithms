class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        vector<int>merged;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            merged.push_back(nums2[j]);
            j++;
        }
        int k=merged.size();
        double ans;
        if(k%2==1){ //odd length
            ans=merged[k/2];
        }else{ //even length
            ans=(merged[k/2-1]+merged[k/2])/2.0;
        }
        return ans;
    }
};