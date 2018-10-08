/*
https://leetcode.com/problems/find-eventual-safe-states/description/
https://zxi.mytechroad.com/blog/graph/leetcode-802-find-eventual-safe-states/
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

*/

//V1
class Solution {
public:
    enum status{ init, visiting, unsafe, safe };
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<status> st( N, init );
        
        for( int i = 0; i < N; i++ )
        {
            vector<status> visited( N, init );
            dfs( graph, st, i, visited );
        }
        vector<int> res;
        for( int i = 0; i < N; i++ )
            if( st[i] == safe )
                res.push_back( i );
        return res;
            
    }
    status dfs( const vector<vector<int>>& graph, vector<status>& st, int node, vector<status>& visited )
    {
        if( st[node] == safe )
            return safe;
        if( st[node] == unsafe )
            return unsafe;
        if( visited[node] == visiting )
        {
            st[node] = unsafe;
            return unsafe;
        }
        visited[node] = visiting;
        for( auto edge : graph[node] )
        {
            if( dfs( graph, st, edge, visited ) == unsafe )
            {
                st[node] = unsafe;
                return unsafe;
            }
        }
        st[node] = safe;
        return safe;
    }
};


//V2 dfs 最开始的node最后得到结果

class Solution {
public:
    enum status{ init, visiting, safe, unsafe };
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<status> st( graph.size(), init );
        vector<int> res;
        for( int i = 0; i < graph.size(); i++ )
            if( dfs( graph, st, i) == safe )
                res.push_back( i );
        return res;
    }
    status dfs( vector<vector<int>>& graph, vector<status>& st, int node )
    {
        if( st[node] == visiting )
            return st[node] = unsafe;
        if( st[node] != init )
            return st[node];
        st[node] = visiting;
        for( auto edge : graph[node] )
            if( dfs( graph, st, edge ) == unsafe )
                return st[node] = unsafe;
        return st[node] = safe;
    }
};