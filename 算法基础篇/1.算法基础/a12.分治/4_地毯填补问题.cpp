#include <iostream>
using namespace std;

void dfs(int a, int b, int x, int y, int k)
{
if(k < 1) return;
int len = 1 << (k - 1);
if(x < a + len && y < b + len) // 障碍物在左上⻆
{
cout << a + len << " " << b + len << " 1" << endl;
dfs(a, b, x, y, k - 1);
dfs(a, b + len, a + len - 1, b + len, k - 1);
dfs(a + len, b, a + len, b + len - 1, k - 1);
dfs(a + len, b + len, a + len, b + len, k - 1);
}
else if(x >= a + len && y >= b + len) // 障碍物在右下⻆
{
cout << a + len - 1 << " " << b + len - 1 << " 4" << endl;
dfs(a, b, a + len - 1, b + len - 1, k - 1);
dfs(a, b + len, a + len - 1, b + len, k - 1);
dfs(a + len, b, a + len, b + len - 1, k - 1);
dfs(a + len, b + len, x, y, k - 1);
}
else if(x >= a + len) // 障碍物在左下⻆
{
cout << a + len - 1 << " " << b + len << " 3" << endl;
dfs(a, b, a + len - 1, b + len - 1, k - 1);
dfs(a, b + len, a + len - 1, b + len, k - 1);
dfs(a + len, b, x, y, k - 1);
dfs(a + len, b + len, a + len, b + len, k - 1);
}
else // 障碍物在右上⻆
{
cout << a + len << " " << b + len - 1 << " 2" << endl;
dfs(a, b, a + len - 1, b + len - 1, k - 1);
dfs(a, b + len, x, y, k - 1);
dfs(a + len, b, a + len, b + len - 1, k - 1);
dfs(a + len, b + len, a + len, b + len, k - 1);
}
}
int main()
{
int k, x, y; cin >> k >> x >> y;
dfs(1, 1, x, y, k);

return 0;
}