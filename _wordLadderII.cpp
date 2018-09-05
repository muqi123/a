/*
https://zxi.mytechroad.com/blog/searching/leetcode-126-word-ladder-ii/

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if( beginWord == endWord )
            return vector<vector<string>>( 1, {beginWord});
        unordered_map<string, int> strStep; // min step for the world
        unordered_map<string, set<string>> p; // word parent
        unordered_set<string> st( wordList.begin(), wordList.end());
        st.erase( beginWord );
        bool isLast = false;
        int step = 0;
        queue<string> q1;
        q1.push( beginWord);
        while( !q1.empty() & !isLast )
        {
            queue<string> q2;
            while( !q1.empty() )
            {
                string cur = q1.front();
                q1.pop();
                string cur1 = cur;
                for( int i = 0; i < cur.size(); i++ )
                    for( int j = 0; j < 26; j++ )
                    {
                        cur[i] = 'a'+j;
                        if( cur == endWord && st.count( cur ) )
                        {
                            isLast = true;
                            p[cur].insert( cur1 );
                        }
                        else
                        {
                            if( st.count(cur) && ( strStep.count( cur) == 0 || strStep[cur] == step ) )
                            {
                                strStep[cur] = step;
                                p[cur].insert( cur1 );
                                q2.push( cur );
                            }
                        }
                        
                        cur = cur1;
                        
                    }
            }
            step++;
            q1.swap(q2);
        }
        
        vector<vector<string>> res;
        if( !isLast )
            return res;
        vector<string> vec(1, endWord );
        dfs( p, endWord, vec, beginWord, res);
        
        for( auto& elem : res )
            reverse( elem.begin(), elem.end() );
        return res;
    }
    
    void dfs( unordered_map<string, set<string>>& p, string cur, vector<string>& vec, string beginWord, vector<vector<string>>& res )
    {
        if( cur == beginWord )
        {
            res.push_back( vec );
            return;
        }
        for( auto str : p[cur] )
        {
            vec.push_back( str );
            dfs( p, str, vec, beginWord, res );
            vec.pop_back();
        }
    }
};