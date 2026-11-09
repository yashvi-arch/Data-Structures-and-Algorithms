class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a=0;a*a<=c;a++){
            long long target=c-(a*a);
            long long low=0;
            long long high=sqrt(c);
            while(low<=high){
                long long mid=low+(high-low)/2;
                long long sq=mid*mid;

                if(sq==target){
                    return true;
                }else if(sq<target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }

        }
        return false;
        
    }
};