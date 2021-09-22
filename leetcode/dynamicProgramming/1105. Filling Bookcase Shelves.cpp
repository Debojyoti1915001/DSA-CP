// Step 1: Init DP. where dp[i] represents the min height of book up to i (1-index for padding to prevent SEGV)

// Step 2: Do DP, for each new book i (for book [0, n) and dp [1, n + 1)) we have 2 chioces

// Step 2-1: Put on the new layer of shelf, and the total height till book i will be dp[i - 1] + books[i][1]
// Step 2-2: Yet, we may try to squeeze the book as many as possible on the same layer on the condition that sum of their width < shift_width. So we go back from book i to book 0, checking all the possibilities that can be squeezed to the same layer. And if(sum > sw) the sum of width exceeds the shift width, unable to squeeze, then we quit finding the previous combinations.
// Analysis:

// Time complexity: O(N ^ 2)
// Space complexity: O(N) for storing the results

class Solution {
public:
    void print_dp(vector<int>& dp)
    {
        for(auto &x : dp)
        {
            printf("%d ", x);
        }
        printf("\n");
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) 
    {
        int n = books.size();
		// init
        vector<int> dp(n + 1, 0);  // min height for book up to i (starting from 0)
        dp[0] = 0;
        
        // doing dp
        for(int i = 0; i < n; i++)
        {
            dp[i + 1] = dp[i] + books[i][1]; // Step 2- 1: on the new layer
            int sum = 0, h = 0;
            for(int j = i; j >= 0; j--)
            {
                sum += books[j][0]; // try to put on current layer, rather than the new one
                if(sum > sw) // the sum of width exceeds the shift width, unable to squeeze
                {
                    break;
                }
                else // Step 2- 2: keep squeezing
                {
                    h = max(h, books[j][1]); // get the tallest book for this layer
                    dp[i + 1] = min(dp[j] + h, dp[i + 1]); // for i + 1 th book it can either be the next layer, or this layer(try the combination to make 'one layer' as short as possible)
                    // printf("sum %d booksj_h %d h %d j %d dp[j] %d i %d dp[i + 1] %d\n", sum, books[j][1], h, j, dp[j], i, dp[i + 1]);
                }
            }
            // print_dp(dp);
        }
        // print_dp(dp);
        return dp[n];
    }
};