#include<bits/stdc++.h>
using namespace std;
void fxn(int n)
{
	switch(n)
	{
		case 1:
			cout<<"one ";
			break;
		case 2:
			cout<<"two ";
			break;
		case 3:
			cout<<"three ";
			break;
		case 4:
			cout<<"four ";
			break;
		case 5:
			cout<<"five ";
			break;
		case 6:
			cout<<"six ";
			break;
		case 7:
			cout<<"seven ";
			break;
		case 8:
			cout<<"eight ";
			break;
		case 9:
			cout<<"nine ";
			break;
		default:
			cout<<"zero ";		   
	}
}

void numtostr(int n)
{
	if(n==0)
	return;
	int p=n%10;
	n=n/10;
	numtostr(n);
	fxn(p);
	
}
int main()
{
	int n;
	cin>>n;
	numtostr(n);
}