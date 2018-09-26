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

// II
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> status(numCourses, 0); //0 unvisited, 1 visiting, 2 visited
        
        for( auto p : prerequisites)
            graph[p.first].push_back( p.second);
        
        vector<int> res;
        for( int i = 0; i < numCourses; i++ )
        {
            if( !canF( graph, status, res, i ))
                return vector<int>();
        }
        return res;
    }
    bool canF( vector<vector<int>>& graph, vector<int>& status, vector<int>& res, int in )
    {
        if( status[in] == 2 )
            return true;
        if( status[in] == 1 )
            return false;
        status[in] = 1;
        for( auto elem:graph[in])
            if( !canF( graph, status, res, elem ))
                return false;
        res.push_back( in );
        status[in] = 2;
        return true;
    }
};

