#include<bits/stdc++.h>
using namespace std;
int money_change(int money,int *coin,int n)
{
	int cnt=0;
	while(money){
		int idx=upper_bound(coin,coin+n,money)-coin-1;
		money=money-coin[idx];
		cout<<coin[idx]<<"+";
		cnt++;
	}
return cnt;
}
int main()
{
	int money;
	cin>>money;
	
	int coin[]={1,2,5,10,20,50,100,200,500,1000,2000};
	
	int coine=money_change(money,coin,11);
	cout<<"coine:"<<coine<<endl;
}