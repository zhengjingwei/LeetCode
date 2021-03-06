#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 动态规划
 * 时间复杂度O(mn) 空间复杂度O(mn)
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int >> dp(rows, vector<int>(cols,0));     // dp[i][j]表示以坐标i,j作为右下角的最大矩形边长
        int maxLen = 0;
        // 初始化第一行
        for (int i = 0; i < rows; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxLen = max(maxLen,dp[i][0]);
        }
        // 初始化第一列
        for (int j = 0; j < cols; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            maxLen = max(maxLen,dp[0][j]);
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j]=='0') continue;  // 面积为0
                int len1 = dp[i-1][j];
                int len2 = dp[i][j-1];
                int len3 = dp[i-1][j-1];
                dp[i][j] = min(min(len1,len2),len3) + 1;    // 满足条件的最大边长
                maxLen = max(dp[i][j], maxLen);
            }
        }
        return maxLen*maxLen;
    }
};

int main(){
    vector<vector<char >> nums = {{'1' ,'0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    Solution sol;
    cout << sol.maximalSquare(nums) << endl;
    return 0;
}

