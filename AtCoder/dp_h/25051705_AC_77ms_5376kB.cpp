#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>	
using namespace std;
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
typedef long long         ll;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
#define pb					push_back
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
void GOAT()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("output.txt", "w	", stdout);
#else
#endif

}
int r, c;
char grid[1007][1007];
int mem[1007][1007];
bool valid(int i, int j)
{
	return (i < r && j < c);
}
const int m = 1e9 + 7;
int solve(int i, int j)
{
	if (i == r - 1 && j == c - 1)return 1;
	int& ret = mem[i][j];
	if (~ret)return ret;
	ret = 0;
	if (valid(i, j + 1) && grid[i][j + 1] != '#')ret=((ret%m)+(solve(i, j + 1)%m))%m;
	if (valid(i + 1, j) && grid[i + 1][j] != '#')ret = ((ret % m) + (solve(i+1, j) % m)) % m;
	return ret%m;
}
int main() {
	//GOAT();
	
		clr(mem, -1);
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin>>grid[i][j];
			}
		}
		cout << solve(0, 0) << endl;
}