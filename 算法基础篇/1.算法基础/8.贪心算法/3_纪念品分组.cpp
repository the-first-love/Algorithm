#include <iostream>
#include <algorithm>
using namespace std;
const int N=3e4+10;
int a[N];
int w,n;

int main(int argc, char const *argv[])
{
cin>>w>>n;
for(int i = 1; i <= n; i++) cin >> a[i];
sort(a+1,a+1+n);
int l=1,r=n,ret=0;
while(l<=r)
{
	if(a[l]+a[r]<=w) l++,r--;
	else r--;
    ret++;
}
cout<<ret<<endl;
return 0;
}