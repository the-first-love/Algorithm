#include<iostream>
#include<cstring>
using namespace std;

int a[10],t[10];
int n;

int count(int x)
{
int cnt=0;
while(x)
{
	cnt++;
	x&=x-1;
}
return cnt;
}

void init()
{
	memset(a,0,sizeof a);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
        char x;cin>>x;
        if(x=='0') a[i]|=(1<<j);
		}
	}
}

int main()
{
cin>>n;	
while(n--)
{
init();
int ret=0x3f3f3f3f;

for(int st=0;st < (1<<5);st++)
{
    memcpy(t,a,sizeof a);
    int push=st;
    int cnt=0;

    for(int i=0;i<5;i++)
    {
    cnt+=count(push);
    t[i]=t[i]^push^(push>>1)^(push<<1)&((1<<5)-1);
    t[i+1]^=push;
    push=t[i];
    }
if(t[4]==0) 
{
	ret=min(ret,cnt);
}
}

if(ret>6) ret=-1; 
cout<<ret<<endl;
}

return 0;
}