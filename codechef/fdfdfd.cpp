#include<iostream> 
using namespace std; 

void print(int n) 
{ 
	int sp = n / 2, st = 1;  
	for (int i = 1; i <= n; i++) 
	{
	for (int j = 1; j <= sp; j++) 
		cout << " "; 
		int count = st / 2 + 1; 
		for (int k = 1; k <= st; k++) 
		{ 
			cout << " "<<count; 
			if (k <= st / 2) 
				count++; 
			else
				count--; 
		} 
		cout << endl; 
		if (i <= n / 2) 
		{ 
			sp = sp - 1; 
			st = st + 2; 
		} 
		else
		{ 
			sp = sp + 1; 
			st = st - 2; 
		} 
	} 
} 
int main() 
{ 
	int n;
	cin>>n;
	print(n); 
}
