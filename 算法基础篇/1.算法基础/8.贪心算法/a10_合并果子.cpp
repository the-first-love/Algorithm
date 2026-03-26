#include <iostream>
#include <algorithm>

#include<queue>
using namespace std;

int n;
typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>> heap;

int main(int argc, char const *argv[])
{
cin>>n;LL a;
for(int i = 1; i <= n; i++) cin>>a,heap.push(a);
LL sum=0;
while(heap.size()>1)
{
LL x=heap.top();heap.pop();
LL y=heap.top();heap.pop();
sum+=x+y;
heap.push(x+y);
}
cout <<sum <<endl;
return 0;
}