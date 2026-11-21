class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = __builtin_popcount(a);
        int s2 = __builtin_popcount(b);

        int ans;

        if (s1 >= s2) {
            ans = s1 * s2;
        } else {
            ans = s2 / s1;
        }

        return ans;
    }
};