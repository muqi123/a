/*886. Possible Bipartition
https://leetcode.com/problems/possible-bipartition/description/

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.
*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        g_ = vector<vector<int>>(N);
        for( auto dis : dislikes ){
            g_[dis[0]-1].push_back( dis[1] - 1 );
            g_[dis[1]-1].push_back( dis[0] - 1 );
        }
        
        vector<int> colorV( N, 0);
        for( int i = 0; i < N; i++ ){
            if( colorV[i] == 0 ){
                if( !dfs( i, 1, colorV ) )
                    return false;
            }   
        }
        return true;
    }
    
    bool dfs( int i, int color, vector<int>& colorV ){
        colorV[i] = color;
        for( int j = 0; j < g_[i].size(); j++ ){
            if( color == colorV[g_[i][j]] )
            {
                cout<< g_[i][j]<< endl;
                return false;
            }
            if( colorV[g_[i][j]] == 0 )
                if( !dfs( g_[i][j], -color, colorV))
                    return false;
        }
        return true;
    }
private:
    vector<vector<int>> g_;
};