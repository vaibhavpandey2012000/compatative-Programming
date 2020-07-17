#include<bits/stdc++.h>
using namespace std;
bool isodd(int n)
{
	if(n&1==1)
		return true;
	return false;
}
int find_ith_bit(int n,int i)
{
	if( (n & (1<<i) )>0)
		return 1;
	return 0;
}
int set_a_particular_bit(int n,int i)
{
	return n | (1<<i);
}

int clear_ith_bit(int n,int i)//indexing from 0,1,2,3
{
	int mask=~(1<<i);
	return n&mask;
}
int update_bit(int n,int i)//indexing from 0,1,2,3
{
	int mask=clear_ith_bit( n, i);
	return n|(1<<i);
}
int clear_last_i_bit(int n,int i)
{
	int mask=(-1)<<i;
	return n&mask;
}
int clear_range_bit_i_to_j(int n,int i,int j)
{
	int mask=(-1<<(j+1))|((1<<i)-1);
	return n&mask;
}
int main()
{
	cout<<clear_range_bit_i_to_j(63,0,2)<<endl;
}