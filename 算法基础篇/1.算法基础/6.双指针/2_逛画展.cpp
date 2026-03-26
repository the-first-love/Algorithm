#include<iostream>
using namespace std;

const int N=1e6+10;
int n,m;
int a[N],mp[N],kind=0;

int main()
{
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];

int left=1,right=1,ret=n,L=1;

while(right<=n)
{

if(mp[a[right]]++==0) kind++;

while(kind==m)
{
if(right-left+1<ret) ret=right-left+1,L=left;
if(mp[a[left]]--==1) kind--;
left++;
}
right++;
}
cout << L << " " << L + ret - 1 << endl;
	return 0;
}