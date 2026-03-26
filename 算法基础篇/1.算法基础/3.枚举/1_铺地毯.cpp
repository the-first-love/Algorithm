#include<iostream>
using namespace std;

const int N=1e4+10;
int n;
int a[N],b[N],g[N],k[N];
int x,y;

int find()
{

for(int i=n;i>0;i--)
{
if(x>=a[i]&&y>=b[i]&&x<=a[i]+g[i]&&y<=b[i]+k[i])
return i;
}

return -1;
}


int main()
{

cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i]>>b[i]>>g[i]>>k[i];
}

cin>>x>>y;
cout<<find()<<endl;

	return 0;
}