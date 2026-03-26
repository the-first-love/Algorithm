#include<iostream>
using namespace std;

const int N=1e8;

int days[13]={-1,31,29,31,30,31,30,31,31,30,31,30,31};
int a,b,m=0,count=0;

int main()
{
cin>>a>>b;

for(int i=1;i<=12;i++)
{
for(int j=1;j<=days[i];j++)
{
int ret=(j%10)*1e7+(j/10)*1e6+(i%10)*1e5+(i/10)*1e4+i*100+j;
if(ret>=a&&ret<=b)
		count++;
}
}

cout<<count;
return 0;
}