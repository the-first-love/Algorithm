#include<iostream>
#include<cstring>

using namespace std;

const int N=20;

int n;
int a[N];
int t[N];

int check(int a,int b)
{
int sum=0;
for(int i=0;i<n;i++)
{
	if(((a>>i)&1)==1&&((b>>i)&1)==0) return -1;
	if(((a>>i)&1)==0&&((b>>i)&1)==1) sum++;
}
return sum;
}

int solve()
{
int ret=0x3f3f3f3f;
for(int st=0;st < (1<<n);st++)
{
   memcpy(t,a,sizeof a);

   int change=st;
   int cnt=0;
   bool flag=1;

for(int i=1;i<=n;i++)
{

if(check(t[i],change)>=0)
{
cnt +=check(t[i],change);
t[i]=change;
change = t[i - 1] ^ (t[i] << 1) ^ (t[i] >> 1);
change &=(1<<n)-1;

}
else
{
flag=0;
break;
}
}
if(flag) ret=min(ret,cnt);
}

if(ret==0x3f3f3f3f) return -1;
return ret;
}


int main()
{
	int T;cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;	
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		{
		for(int j=0;j<n;j++)
		{
        int x;cin>>x;
        if(x) a[i]|=(1<<j);
		}
		}

	printf("Case %d: %d\n",i,solve());
	}
	return 0;
}