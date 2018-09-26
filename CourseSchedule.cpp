/*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 0 means unvisited, 1 means visiting, 2 means visited
        vector<int> status( numCourses, 0 );
        vector<vector<int>> graph( numCourses, vector<int>());
        for( auto p : prerequisites )
            graph[p.first].push_back( p.second );
        for( int i = 0; i < numCourses; i++ )
            if( !canF( i, status, graph ) )
                return false;
        return true;
    }
    bool canF( int input, vector<int>& status, vector<vector<int>>& graph ){
        if( status[input] == 2 )
            return true;
        if( status[input] == 1 )
            return false;
        status[input] = 1;
        for( auto elem : graph[input] )
            if( !canF( elem, status, graph ) )
                return false;
        status[input] = 2;
        return true;
    }
};

