/*
https://leetcode.com/problems/different-ways-to-add-parentheses/description/
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

https://www.youtube.com/watch?v=gxYV8eZY0eQ&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=53

*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if( mp.count(input) == 1 )
            return mp[input];
        vector<int> res;
        for( int i = 0; i < input.size(); i++ ){
            if( input[i] == '+'  || input[i] == '-' || input[i] == '*' )
            {
                vector<int> v1 = diffWaysToCompute( input.substr( 0, i ) );
                vector<int> v2 = diffWaysToCompute( input.substr( i + 1 ) );
                vector<int> tmp = append( v1, v2, input[i] );
                res.insert( res.end(), tmp.begin(), tmp.end() );
            }
        }
        if( res.empty() )
            res.push_back( stoi( input ) );
        mp[input] = res;
        return res;       
    }
    vector<int> append( vector<int>& v1, vector<int>& v2, char op )
    {
        vector<int> res;
        if( op == '+' )
            for( auto& l : v1 )
                for( auto& r : v2 )
                    res.push_back( l + r );
        else if( op == '-' )
            for( auto& l : v1 )
                for( auto& r : v2 )
                    res.push_back( l - r );
        else
            for( auto& l : v1 )
                for( auto& r : v2 )
                    res.push_back( l * r );
        return res;
            
    }
    
    unordered_map<string, vector<int>> mp;
};