/*
https://www.youtube.com/watch?v=JqOIRBC0_9c&index=54&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st( wordDict.begin(), wordDict.end() );
        return help( s, st );
    }
    
    vector<string> append( vector<string> vec, string str )
    {
        vector<string> res;
        for( auto& st : vec)
            res.push_back( st + " " + str );
        return res;
    }
    vector<string> help( string s, unordered_set<string> st ){
        if( s == "" ) return vector<string>();
        if( m_word.count( s ) ) return m_word[s];
        
        vector<string> res;
        if( st.count( s ) )
            res.push_back( s );
        for( int i = 1; i < s.size(); i++ ){
            string end = s.substr( i );
            if( st.count( end ) != 1 ) continue;
            vector<string> tmp = append( help( s.substr( 0, i), st), end );
            res.insert( res.end(), tmp.begin(), tmp.end() );
        }
        
        return m_word[s] = res;
    }
private:
    unordered_map<string, vector<string>> m_word; 
};




// word break I
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st( wordDict.begin(), wordDict.end() );
        s = " " + s ;
        int n = s.size();
        unordered_set<int> st1;
        st1.insert( 0 );
        
        for( int l = 1; l < n; l++ )
            for( auto idx : st1  )
            {
                string tmpS = s.substr( idx + 1, l - idx );
                if( st.count(  tmpS ) )
                {
                    st1.insert( l );
                    break;
                }
            }
        return st1.count( n - 1 ) == 1;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st( wordDict.begin(), wordDict.end() );
        return wordBreak( s, st );
    }
    
    bool wordBreak( string s, unordered_set<string>& st ){
        if( mp.count( s ) ) return mp[s];
        if( st.count( s ) ) return true;
        
        for( int i = 1; i < s.size(); i++ ){
            string tmp = s.substr( i );
            if( st.count( tmp ) == 0 ) continue;
            if( wordBreak( s.substr( 0, i ), st ) )
                return mp[s] = true;
        }
        
        return mp[s] = false;
    }
private:
    unordered_map< string, bool> mp;
};