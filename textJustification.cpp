https://leetcode.com/problems/text-justification/description/
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> res;
	int i = 0;
	while( i < words.size() )
	{
		vector<string> tmp;
		int sz = 0;
		bool isLast = false;
		while( i < words.size() && sz + words[i].size() + tmp.size() <= maxWidth )
		{
			tmp.push_back( words[i] );
			sz += words[i].size();
			i++;
		}
		if( i >= words.size() )
			isLast = true;
		res.push_back( GetWords( tmp, maxWidth, isLast, sz ) );
	}
	return res;
}

string GetWords( vector<string>& words, int maxWidth, bool isLast, int sz )
{
	string res = words[0];
	// word size part is important, 1 word case does not work in else logic
	if( isLast || words.size() == 1 )
	{
		for( int i = 1; i < words.size(); i++ )
			res = res + " " + words[i];
		// This part also important
		res += string( maxWidth - ( sz + words.size() - 1 ) , ' ' );
		return res;
	}
	int avgSpace = ( maxWidth - sz ) / ( words.size() - 1 );
	int numMoreSpace = ( maxWidth - sz ) % ( words.size() - 1 );
	for( int i = 1; i < words.size(); i++ )
	{
		if( i <= numMoreSpace )
			res = res + string( avgSpace + 1, ' ' ) + words[i];
		else
			res = res + string( avgSpace, ' ' ) + words[i];
	}
	return res;
}