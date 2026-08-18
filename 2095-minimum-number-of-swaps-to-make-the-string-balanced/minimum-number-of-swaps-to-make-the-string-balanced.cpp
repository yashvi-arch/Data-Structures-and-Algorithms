class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int swaps=0;
        for(char ch:s){
            if(ch=='['){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    swaps++;
                }
            }
        }
        return (swaps+1)/2;
        
    }
};