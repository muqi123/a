https://www.youtube.com/watch?v=86fQQ7rVGxA

/* version 1 */
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

/*version 2*/
/* 巧妙运用 vector 是否相等省掉了记录size，删除以记录元素的操作 */
vector<int> findAnagrams(string s, string p) {
    int sz = p.size();
    vector<int> res;
    if( s.empty() || p.empty() || s.size() < sz )
        return res;
    
    vector<int> vc( 128, 0 );
    vector<int> cvc( 128, 0 );

    for( auto c : p ) vc[c]++;
    for( int i = 0; i < s.size(); i++ )
    {
        if( i >= sz ) cvc[s[i-sz]]--;
        cvc[s[i]]++;
        if( cvc == vc )
            res.push_back( i - sz + 1 );
    }
    return res;
}
