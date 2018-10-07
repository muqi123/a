/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
https://www.youtube.com/watch?v=PLY-lbcxEjg&list=PLLuMmzMTgVK5gFVMpryw0LkJp4l9WTtdM&index=12
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

*/

// 用dfs的办法/bfs在做一遍

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int maxRange = 10000*100*100;
        vector<vector<int>>  vec( K + 2, vector<int>( n, maxRange ) );
        vec[0][src] = 0;
        for( int i = 1; i <= K + 1; i++ )
            for( int j = 0;  j < flights.size(); j++ )
            {
                int m = flights[j][0];
                int v = flights[j][1];
                int val = flights[j][2];
                vec[i][v] = min( min( vec[i-1][m] + val , vec[i-1][v] ), vec[i][v] ); 
            }
        return vec[K+1][dst] == maxRange ? -1 : vec[K+1][dst];
    }
};