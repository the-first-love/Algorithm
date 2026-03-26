#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;

int m,n,k,l,d;
struct table
{
	int x;//交头接耳对数
    int index;//行/列编号
}row[N],col[N];

bool cmp1(table& a,table& b)
{
	return a.x>b.x;
}
bool cmp2(table& a,table& b)
{
	return a.index<b.index;
}

int main(int argc, char const *argv[])
{
cin>>m>>n>>k>>l>>d;
// 初始化结构体数组,i与index对应
for(int i = 1; i <= m; i++) row[i].index = i;
for(int i = 1; i <= n; i++) col[i].index = i;

for(int i = 1; i <= d; i++)
{
	int x,y,p,q;cin>>x>>y>>p>>q;
	if(x==p) col[min(y,q)].x++;
	else row[min(x,p)].x++;
} 
sort(row+1,row+1+m,cmp1);
sort(col+1,col+1+n,cmp1);

sort(row+1,row+1+k,cmp2);
sort(col+1,col+1+l,cmp2);

for(int i = 1; i <= k; i++) cout<<row[i].index<<" ";
cout<<endl;
for(int i = 1; i <= l; i++) cout<<col[i].index<<" ";
cout<<endl;	
return 0;
}