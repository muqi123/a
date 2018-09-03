/*https://leetcode.com/problems/reconstruct-itinerary/description/

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/

//这题是一道变相到postOrderTraversal的题目，用 deque 去remove最前面到元素

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, deque<string>> mp;
        for( auto pair : tickets ){
            mp[pair.first].push_back( pair.second);
        }
        for( auto& pair : mp )
            sort( pair.second.begin(), pair.second.end());
        vector<string> res;
        traversal( mp, "JFK", res );
        reverse( res.begin(), res.end());
        return res;
        
    }
    void traversal( unordered_map<string, deque<string>>& mp, string curNode , vector<string>& res )
    {
        while( mp[curNode].size() != 0 )
        {
            string tmp = mp[curNode].front();
            mp[curNode].pop_front();
            traversal( mp, tmp, res );
        }
        res.push_back( curNode );
        return;
    }
};