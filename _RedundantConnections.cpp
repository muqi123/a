/*
https://leetcode.com/problems/redundant-connection/description/
https://www.youtube.com/watch?v=4hJ721ce010&list=PLLuMmzMTgVK5gFVMpryw0LkJp4l9WTtdM&index=23

In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.
*/


/* 1. DFS */
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //sort( edges.begin(), edges.end() );
        unordered_map< int, vector<int>> graph;
        vector<int> res;
        
        for( auto elem : edges ){
            set<int> st;
            int u = elem[0];
            int v = elem[1];
            if( findPath( u, v, graph, st ) )
                return vector<int>{ u, v };
            graph[u].push_back( v );
            graph[v].push_back( u );
        }
        return res;
    }
    bool findPath( int u, int v, unordered_map< int, vector<int>>& graph, set<int>& st )
    {
        if( u == v )
            return true;
        if( st.count( u ) > 0 )
            return false;
        st.insert( u );
        for( auto elem : graph[u] )
            if( findPath( elem, v, graph, st ) )
                return true;
        return false;
    }
};
/* 2. UnionFind */
class Solution {
public:
    void CreateFindSet( int n )
    {
        pa_ = vector<int>( n + 1, 0 );
        rank_ = vector<int>( n + 1, 0 );
        for( int i = 0; i < n + 1; i++ )
            pa_[i] = i;
    }
    
    int Find( int u ){
        if( pa_[u] != u )
        {
            int newP = Find( pa_[u] );
            pa_[u] = newP;
        }
        return pa_[u];
    }
    
    // return true if they share same parent
    bool Union( int u, int v )
    {
        int pU = Find( u );
        int pV = Find( v );
        if( pU == pV )
            return true;
        if( rank_[pU] > rank_[pV] )
            pa_[pV] = pU;
        else if( rank_[pU] < rank_[pV])
            pa_[pU] = pV;
        else
        {
            pa_[pV] = pU;
            rank_[pU]++;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        CreateFindSet( edges.size() );
        vector<int> res;
        for( auto elem : edges )
            if( Union( elem[0], elem[1] ) )
            {
                //cout<< elem[0] << elem[1]<< endl; 
                return elem;
            }
        return vector<int>();
    }
private:
    vector<int> pa_;
    vector<int> rank_;
};