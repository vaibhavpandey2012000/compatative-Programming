// C program for Left Rotation and Right 
// Rotation of a String 
#include<bits/stdc++.h> 
using namespace std; 

void leftrotate(string &s, int d) 
{ 
	reverse(s.begin(), s.begin()+d); 
	reverse(s.begin()+d, s.end()); 
	reverse(s.begin(), s.end()); 
} 

void rightrotate(string &s, int d) 
{ 
leftrotate(s, s.length()-d); 
} 

// Driver code 
int main() 
{ 
	int n;
	cin>>n;
	string str1 = "";
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		str1+=('0'+temp);
	} 
	cout<<str1<<endl;
	int k;
	cin>>k;
	if(k<0)
	{
		leftrotate(str1, -k-1);	
	} 
	else{
		rightrotate(str1, k+1); 
	} 
	cout << str1 << endl; 
	return 0; 
} 

