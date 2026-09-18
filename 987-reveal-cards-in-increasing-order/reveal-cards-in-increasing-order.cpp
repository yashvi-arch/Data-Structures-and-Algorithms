class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>result(n,0);
        int i=0;
        int j=0;
        bool skip=false;
        sort(deck.begin(),deck.end());
        while(i<n){
            if(result[j]==0){ //potential filling position
                if(skip==false){ //skip nhi krna iss wale ko
                    result[j]=deck[i]; //to fill krdo
                    i++; //move on to the next element
                }
                skip=!skip; //switch skip polarity
            }
            j=(j+1)%n; //wrap around the result array's j pointer 
        }
        return result;
        
    }
};