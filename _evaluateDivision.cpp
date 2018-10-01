/*
https://leetcode.com/submissions/detail/179677721/
https://www.youtube.com/watch?v=UwpvInpgFmo&index=16&list=PLLuMmzMTgVK5gFVMpryw0LkJp4l9WTtdM

Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/



class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for( int i = 0; i < equations.size(); i++ )
        {
            mp[equations[i].first].emplace_back( equations[i].second, values[i] );
            if( values[i] != 0 )
                mp[equations[i].second].emplace_back( equations[i].first, 1 / values[i] );
        }
        vector<double> res;
        for( auto pair : queries )
        {
            unordered_set<string> visited;
            res.push_back( dfs( mp, pair.first, pair.second, visited));
        }
        return res;
    }
    double dfs( unordered_map<string, vector<pair<string, double>>>& mp, string in, string out, unordered_set<string>& visited )
    {
        if( mp.count( in ) < 1 || mp.count( out ) < 1 )
            return -1;
        if( in == out )
            return 1;
        if( visited.count( in ) )
            return -1.0;
        visited.insert( in );
        for( auto& pair : mp[in] )
        {
            double tmp = dfs( mp, pair.first, out, visited );
            if( tmp >= 0 )
                return tmp * pair.second;
        }
        return -1.0;
    }
};