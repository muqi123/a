/*
https://leetcode.com/problems/bus-routes/description/
https://www.youtube.com/watch?v=vEcm5farBls&list=PLLuMmzMTgVK5gFVMpryw0LkJp4l9WTtdM&index=10


We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.
*/

// 只要记录那一条route被走过了， 不用记录每个bus visited的情况


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if( S == T ) return 0;
        unordered_map<int, vector<int>> mp;
        for( int i = 0; i < routes.size(); i++ )
            for( int j = 0; j < routes[i].size(); j++ )
                mp[routes[i][j]].push_back( i );
        vector<bool> visitedRoute( 500, false );
        queue<int> q;
        q.push( S );
        int k = 1;
        while( !q.empty() )
        {
            int s = q.size();
            while( s-- )
            {
                int cur = q.front();
                q.pop();
                for( auto route : mp[cur] )
                {
                    if( visitedRoute[route] )
                        continue;
                    visitedRoute[route] = true;
                    for( auto bus : routes[route] )
                    {
                        if( bus == T )
                            return k;
                        q.push( bus );
                    }
                }
            }
            k++;
        }
        return -1;
    }
};