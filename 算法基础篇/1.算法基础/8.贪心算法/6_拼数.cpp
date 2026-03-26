#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N=30;
int n;
string a[N];

bool cmp(string& a,string& b)
{
	return a+b>b+a;
}

int main(int argc, char const *argv[])
{
cin>>n;
for(int i = 1; i <= n; i++) cin>>a[i];

sort(a+1,a+1+n,cmp);

for(int i = 1; i <= n; i++) cout<<a[i];
return 0;
}