#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
typedef long long LL;
int n,q;
LL a[N];

int binary_search(int x,int y)
{
int left=1,right=n,begin=0,end=0;
while(left<right)
{
int mid=(left+right)/2;
if(a[mid]>=x) right=mid;
else left=mid+1;
}
if(a[left]>=x) begin=left;
else return 0;

left=1,right=n;
while(left<right)
{
int mid=(left+right+1)/2;
if(a[mid]<=y) left=mid;
else right=mid-1;
}
if(a[right]<=y) end=right;
else return 0;

return end-begin+1;
}

int main(int argc, char const *argv[])
{
cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];
cin>>q;
while(q--)
{
LL x,y;cin>>x>>y;
cout << binary_search(x, y) << endl;
}
	return 0;
}