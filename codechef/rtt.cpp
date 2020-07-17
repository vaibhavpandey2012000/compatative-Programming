#include<bits/stdc++.h>
using namespace std;
int main()
{
	multimap<char,string>mp;
	mp.insert({'b',"banana"});
	mp.insert({'a',"apple"});
	mp.insert({'b',"bansh"});
	mp.insert({'a',"ankur"});
	mp.insert({'p',"papaya"});
	mp.insert({'g',"grapes"});
	
	auto e=mp.find('a');
	cout<<(*e).second<<endl;
	mp.erase(e);
	for(auto e:mp)
	{
		cout<<e.first<<" "<<e.second<<endl;	
	}	
}
