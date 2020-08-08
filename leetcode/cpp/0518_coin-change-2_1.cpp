
int coin_change(int amount, int firstcoin, vector<int>& memo, const vector<int>& coins) {
    if (amount <= 0) {
        return 0;
    }

    int idx = amount * coins.size() + firstcoin;
    int result = 0;

    if (idx < (int)memo.size() && memo[idx] != 0) {
        return memo[idx];
    }

    for (int k = firstcoin; k < (int)coins.size(); ++k) {
        int v = coins[k];

        if (amount == v) {
            result++;
        } else {
            result += coin_change(amount - v, k, memo, coins);
        }
    }

    memo[idx] = result;
    return result;
}

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<int> memo;
        memo.resize(coins.size() * (amount + 1));
        return coin_change(amount, 0, memo, coins);
    }
};