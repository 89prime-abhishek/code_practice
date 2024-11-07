class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
    
        # Base case: Empty string and empty pattern are a match
        dp[0][0] = True
    
        # Base case: Handle patterns with '*' that can match empty strings
        for j in range(2, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]
    
        # Fill the DP table
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # Case 1: p[j-1] == s[i-1] or p[j-1] == '.'
                if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                # Case 2: p[j-1] == '*', check zero or more of the previous character
                elif p[j - 1] == '*':
                    # Zero occurrences of the character before '*'
                    dp[i][j] = dp[i][j - 2]
                    # One or more occurrences of the character before '*'
                    if p[j - 2] == s[i - 1] or p[j - 2] == '.':
                        dp[i][j] |= dp[i - 1][j]
    
        return dp[m][n]