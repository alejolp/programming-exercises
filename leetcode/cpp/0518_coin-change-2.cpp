class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> memo;
        memo.resize((amount + 1));
        memo[0] = 1;
        
        for (size_t i = 0; i < coins.size(); ++i) {
            int v = coins[i];
            for (int k = v; k <= amount; ++k) {
                memo[k] += memo[k - v];
            }
        }
        
        return memo[amount];
    }
};
