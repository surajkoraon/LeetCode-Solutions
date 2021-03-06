class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        long long int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            dp[i]=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(i>=coins[j])
                {
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};
