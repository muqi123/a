class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if( s.empty() || p.empty() || s.size() < p.size() )
            return res;
        int first = 0;
        int second = 0;
        int curCount = 0;
        int sz = p.size();
        
        vector<int> vc( 128, 0 );
        vector<int> cvc( 128, 0 );
        for( char element : p )
            vc[element]++;
        for( ; second < s.size(); second++ )
        {
            char cur = s[second];
            if( vc[cur] == 0 )
            {
                first = second + 1;
                curCount = 0;
                cvc = vector<int>(128, 0);
            }
            else
            {
                if( cvc[cur] < vc[cur] )
                {
                    cvc[cur]++;
                    curCount++;
                }
                else
                {
                    while( s[first] != cur )
                    {
                        cvc[s[first]]--;
                        curCount--;
                        first++;
                    }
                    first++;
                }
                if( curCount == sz )
                {
                    res.push_back( first );
                }
            }
        }
        return res;
    }
};