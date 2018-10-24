/*


https://leetcode.com/problems/maximal-square/

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

//这题可以用dp，确定长度，然后每行每列求解，从最大长度开始

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        vector<vector<int>> v( m+1, vector<int>(n+1, 0) );
        
        for( int i = 1; i <= m; i++ )
            for( int j = 1; j <= n; j++ ){
                v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1] + matrix[i-1][j-1] - '0';
            }
        int maxLen = min( m, n );
        for( int l = maxLen; l >= 0; l-- )
            for( int i = 1; i + l - 1<= m; i++ ){
                for( int j = 1; j + l - 1 <= n; j++){
                    int ni = i + l - 1;
                    int nj = j + l - 1;
                    int val = v[ni][nj] - v[i-1][nj] - v[ni][j-1] + v[i-1][j-1];
                    if( val == l * l )
                    {
                        return val;
                    }
                }
            }
        return 1;
    }
};