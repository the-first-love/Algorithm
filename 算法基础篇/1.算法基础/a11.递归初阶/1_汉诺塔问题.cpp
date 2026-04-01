#include <iostream>
#include <algorithm>

using namespace std;

int n;char a,b,c;

void func(int n,char a,char c,char b)
{
if(n==0) return; 
func(n-1,a,b,c);
printf("%c->%d->%c\n",a,n,b);
func(n-1,c,a,b);
}

int main(int argc, char const *argv[])
{
	scanf("%d %c %c %c",&n,&a,&b,&c);
	func(n,a,c,b);
	return 0;
}