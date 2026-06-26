
        vector<vector<unsigned>> dp(n + 1, vector<unsigned>(c + 1, 0));

        // 自顶向下：i 从 n-1 到 0
        for (int i = n - 1; i >= 0; i--) {
            for (int capacity = 0; capacity <= c; capacity++) {
                if (capacity < w[i]) {
                    // 装不下，只能跳过
                    dp[i][capacity] = dp[i + 1][capacity];
                } else {
                    // 装得下：选或不选取最大
                    dp[i][capacity] = max(dp[i + 1][capacity], dp[i + 1][capacity - w[i]] + v[i]);
                }
            }
        }
        printf("%u\n", dp[0][c]); 
   