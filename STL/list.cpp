/*
	1.push_back
	2.push_front
	3.insert(itrator,element)

	4.erase(itrator)
	5.remove(element)
	6.pop_back()
	7.pop_front()

	8.sort
	9.reverse
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	list<int> l1{1,6,2,9,11,15};
	for(auto e:l1)
	cout<<e<<" ";
	cout<<endl;
	l1.push_back(13);
	l1.push_back(21);
	l1.push_front(-11);
	for(auto e:l1)
	cout<<e<<" ";
	cout<<endl;
	int d1=l1.front();
	l1.pop_front();
	int d2=l1.front();
	l1.pop_back();
	cout<<d1<<" "<<d2<<endl;
	auto e=l1.begin();
	e++;
	l1.insert(e,7);
	for(auto e:l1)
	cout<<e<<" ";
	cout<<endl;
	e=l1.begin();
	e++;
	e++;
	l1.erase(e);
	
	for(auto e:l1)
	cout<<e<<" ";
	cout<<endl;
	
	l1.reverse();
	
	for(auto e:l1)
	cout<<e<<" ";
	cout<<endl;
}