#include<bits/stdc++.h>
#define ll long long
using namespace std;

void build(ll temp[],int arr[],int a[], int vic, int timestart, int timeend) {
    if (timestart == timeend) {
        temp[vic] = arr[a[timeend]];
    } else {
        int tt = (timestart + timeend) / 2;
        build(temp, arr, a, vic*2, timestart, tt);
        build(temp, arr, a, vic*2+1, tt+1, timeend);
        temp[vic] = temp[vic*2] + temp[vic*2+1];
    }
}

ll sum(ll temp[],int vic, int timel, int timer, int l, int r) {
    if (l > r) 
        return 0;
    if (l == timel && r == timer) {
        return temp[vic];
    }
    int mid = (timel + timer) / 2;
    int val1=min(r, mid);
    int val2=max(l, mid+1);
    ll s1=sum(temp,vic*2, timel, mid, l, val1);
    ll s2=sum(temp,vic*2+1, mid+1, timer,val2, r);
    return s1+s2;
}

void update(ll temp[],int vic, int timel, int timer, int position, int val) {
    if (timel == timer) {
        temp[vic] = val;
    } else {
        int mid = ( timel +  timer) / 2;
        if (position <= mid)
            update(temp, vic*2, timel, mid, position, val);
        else
            update(temp,vic*2+1, mid+1, timer, position, val);
        temp[vic] = temp[vic*2] + temp[vic*2+1];
    }
}

void buildh(int temp[], int arr[], int vic, int timel, int timer) {
    if (timel == timer) {
        temp[vic] = arr[timel];
    } else {
        int mid = ( timel + timer) / 2;
        buildh(temp,arr, vic*2, timel, mid);
        buildh(temp,arr, vic*2+1, mid+1, timer);
        temp[vic] = max(temp[vic*2] , temp[vic*2+1]);
    }
}

int maxh(int temp[],int vic, int  timel, int  timer, int l, int r) {
    if (l > r) 
        return 0;
    if (l == timel && r == timer) {
        return temp[vic];
    }
    int mid = ( timel + timer) / 2;
    
    int pos1=min(r, mid);
    int f1=maxh(temp,vic*2, timel, mid, l, pos1);
    int pos2=max(l, mid+1);
    int f2=maxh(temp,vic*2+1, mid+1, timer, pos2 , r);
    return max(f1,f2);
}





int main()
{
	
}
