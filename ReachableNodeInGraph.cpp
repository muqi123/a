/*https://www.youtube.com/watch?v=SGki2XeWBEo&list=PLLuMmzMTgVK5gFVMpryw0LkJp4l9WTtdM&index=2
882. Reachable Nodes In Subdivided Graph
Starting with an undirected graph (the "original graph") with nodes from 0 to N-1, subdivisions are made to some of the edges.

The graph is given as follows: edges[k] is a list of integer pairs (i, j, n) such that (i, j) is an edge of the original graph,

and n is the total number of new nodes on that edge. 

Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1, x_2, ..., x_n) are added to the original graph,

and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j) are added to the original graph.

Now, you start at node 0 from the original graph, and in each move, you travel along one edge. 

Return how many nodes you can reach in at most M moves.
*/

// 这题是一题很好的dijkstra的题目，build weight图一般用 unordered_map<int, unordered_map<int, int>>
// priority_queue 在 c++中是max heap，每次by default返回最大的数值，priority queue用的是template，所以不能直接用lambda
/* sturct comp{
    operator()( T& t1, T& t2 )
    {
        return t1 > t2;
    }
}
priority_queue<int, vector<int>, comp>
*/


class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> g;
        for( int i = 0; i < edges.size(); i++)
            g[edges[i][0]][edges[i][1]] = g[edges[i][1]][edges[i][0]] = edges[i][2];
        priority_queue<pair<int,int>> pq; // {HP, nodeId}
        unordered_map<int, int> nodeHp; //{nodeId, Hp}
        pq.push({M,0});
        while( !pq.empty()){
            int curNode = pq.top().second;
            int curHp = pq.top().first;
            pq.pop();
            if( nodeHp.count(curNode) ) continue;
            nodeHp[curNode] = curHp;
            for( auto it = g[curNode].begin(); it != g[curNode].end();it++)
            {
                int nxtNode = it->first;
                int nxtHp = curHp - it->second - 1;
                if( nxtHp >= 0 && nodeHp.count( nxtNode ) != 1)
                    pq.push( { nxtHp, nxtNode});
            }
        }
        int res = nodeHp.size();
        for( int i = 0; i < edges.size(); i++ ){
            int left = nodeHp.count(edges[i][0]) ? nodeHp[edges[i][0]] : 0;
            int right = nodeHp.count(edges[i][1]) ? nodeHp[edges[i][1]] : 0;
            res += min( left + right, edges[i][2] );
        }
        return res;      
    }
};