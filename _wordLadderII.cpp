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
第二次做，要分成已经记录过，和没有记录过两种，否则会有重复。 记录过之后就把这个词从wordlist当中删掉
*/



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st( wordList.begin(), wordList.end() );
        st.erase( beginWord );
        unordered_map<string, int> mp;
        unordered_map<string, vector<string>> pa;
        
        vector<vector<string>> res;
        
        queue<string> q;
        q.push( beginWord );
        mp[beginWord] = 0;
        int step = 1;
        bool isFound = false;
        while( !q.empty() )
        {
            int sz = q.size();
            while( sz-- )
            {
                
                string c = q.front();
                q.pop();
                for( int i = 0; i < c.size(); i++ )
                {
                    string tc = c;
                    for( int j = 0; j < 26; j++ )
                    {
                        tc[i] = 'a'+ j;
                        // Not a new word
                        if( mp.count(tc) != 0 && mp[tc] == step )
                        {
                            pa[tc].push_back( c );
                            continue;
                        }
                        
                        // New word
                        if( tc == c || st.count(tc) == 0 || mp.count(tc) != 0 )
                            continue;
                        pa[tc].push_back( c );
                        q.push( tc );
                        mp[tc] = step;
                        st.erase( tc );
                        
                        if( tc == endWord )
                            isFound = true;
                    }
                }
            }
            step++;
            if( isFound == true )
                break;
        }
        vector<string> vec;
        if( isFound )
            findPa( pa, endWord, vec, res);
        return res;
        
    }
    
    void findPa( unordered_map<string, vector<string>>& pa, string word, vector<string>& vec, vector<vector<string>>& res )
    {
        if( pa.count( word ) == 0 ){
            res.push_back( vec );
            res.back().push_back( word );
            reverse( res.back().begin(), res.back().end() );
            return;
        }
        vec.push_back( word );
        for( auto elem : pa[word] )
            findPa( pa, elem, vec, res );
        vec.pop_back();
    }
};