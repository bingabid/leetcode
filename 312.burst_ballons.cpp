// leetcode: https://leetcode.com/problems/burst-balloons/ 
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        // keep a cushion of 1 on both ends of the ballons
        vector<int> ballons;ballons.push_back(1);
        ballons.insert(ballons.end(),nums.begin(),nums.end());
        ballons.push_back(1);
        int n = ballons.size();
        
        // opt(k,i) = maximum coin you can collect by bursting ballons between k to i: ans = dp[0][n-1]
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=1;j--){
                for(int k=j-1;k>=0;k--){
                    dp[k][i] = max(dp[k][i], dp[k][j] + dp[j][i] + ballons[k]*ballons[j]*ballons[i]);
                }
            }
        }
        return dp[0][n-1];
    }
};
