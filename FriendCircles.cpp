/*
https://www.youtube.com/watch?v=HHiHno66j40&index=25&list=PLLuMmzMTgVK5gFVMpryw0LkJp4l9WTtdM

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
*/


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int m_ = M.size();
        if( m_ == 0 ) return 0;
        int res = 0;
        vector<int> visited( m_, 0);
        for( int i = 0; i < m_; i++ )
        {
            if( dfs( M, visited, i, m_) )
                res++;
        }
        return res;
    }
    bool dfs( vector<vector<int>>& M, vector<int>& visited, int cur, int m_ )
    {
        if( visited[cur] )
            return false;
        visited[cur] = true;
        for( int i = 0; i < m_; i++ )
            if( M[cur][i] == 1 )
                dfs( M, visited, i, m_ );
        return true;
    }
};