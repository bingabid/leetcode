//leetcode: https://leetcode.com/problems/minimum-cost-to-merge-stones/
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1) != 0) return -1;
        
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++) prefix[i+1] = stones[i] + prefix[i];
        
        //opt(i,j) = minimum cost of piling i to j stones.
        vector<vector<int>> dp(n,vector<int>(n));
        for(int window=k;window<=n;window++){
            for(int i=0;i+window<=n;i++){
                int j = i + window -1;
                dp[i][j] = INT_MAX;
                for(int mid=i;mid<j;mid+=k-1){
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
                if((j-i+1-1)%(k-1) == 0) dp[i][j] += prefix[j+1] -prefix[i]; 
            }
        }
        return dp[0][n-1];
    }
};
