#include<bits/stdc++.h>
using namespace std;
int main()
{
	//priority_queue<int>pq;
	priority_queue<int,vector<int>,greater<int> >pq;
	pq.push(12);
	pq.push(3);
	pq.push(1);
	pq.push(11);
	pq.push(7);
	while(!pq.empty())
	{
		cout<<pq.top()<<endl;
		pq.pop();
	}
}