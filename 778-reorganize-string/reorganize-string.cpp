class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        char prev='#';
        while(!pq.empty()){
            auto [freq,ch]=pq.top();
            pq.pop();

            // Same character ko immediately dobara use nahi kar sakte
            if(ch==prev){
                // Koi doosra character available nahi hai
                if(pq.empty()){
                    return "";
                }

                // Doosra character nikalo
                auto [freq2,ch2]=pq.top();
                pq.pop();

                // Doosra character use karo
                ans+=ch2;
                freq2--;

                // Agar ch2 ki frequency bachi hai
                // toh PQ mein wapas daal do
                if(freq2>0){
                    pq.push({freq2,ch2});
                }

                // Pehla character abhi use nahi hua,
                // isliye use wapas PQ mein daal do
                pq.push({freq,ch});

                prev=ch2;
            }
            else{
                // Normal case
                ans+=ch;
                freq--;

                // Frequency bachi hai toh wapas PQ mein
                if(freq>0){
                    pq.push({freq,ch});
                }

                prev=ch;
            }
        }

        return ans;
    }
};