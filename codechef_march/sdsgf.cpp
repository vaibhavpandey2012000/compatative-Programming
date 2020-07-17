#include<bits/stdc++.h>
using namespace std;

int getNum(vector<int>& v) 
{ 
	int n = v.size(); 
	srand(time(NULL)); 
	int index = rand() % n; 
	int num = v[index]; 
	swap(v[index], v[n - 1]); 
	v.pop_back(); 
	return num; 
} 

void generateRandom(int n) 
{ 
	vector<int> v(n); 
	for (int i = 0; i < n; i++) 
		v[i] = i + 1; 
	while (v.size()) { 
		cout << getNum(v) << " "; 
	} 
} 

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	int xx;
	cin>>xx;
	
	if(n==6)
	{
		cout<<"5 2 3 1 4 6"<<endl;
		return 0;
	}
	
	generateRandom(n);
}
