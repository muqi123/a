/*
https://leetcode.com/problems/network-delay-time/description/
https://zxi.mytechroad.com/blog/graph/leetcode-743-network-delay-time/


There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/


// Bellman-Ford time complexity N*E

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int maxTime = 6000 * 101;
        vector<int> d( N + 1, maxTime );
        d[K] = 0;
        for( int i = 1; i <= N; i++ )
        {
            for( auto& t : times )
            {
                int u = t[0];
                int v = t[1];
                int w = t[2];
                d[v] = min( d[v], d[u] + w );
            }
        }
        d[0] = 0;
        int res = *max_element( d.begin(), d.end() );
        if( res != maxTime )
            return res;
        return -1;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int maxTime = 6000*100;
        vector<int> res( N + 1, maxTime );
        res[K] = 0;
        for( int i = 0; i < N; i++ )
        {
            for( auto e : times ){
                res[e[1]] = min( res[e[1]], res[e[0]] + e[2] );
            }
        }
        int maxNum = *max_element( res.begin() + 1, res.end() );
        return maxNum == maxTime ? -1 : maxNum;
    }
};