#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl                         '\n'
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define vi                    vector<int>
#define pii                 pair<int,int>
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define forr(i, n) for (int i = 0; i < int(n); i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y)) * y); }
void _Sectumsempra_()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
int main()
{
	int n;
	cin >> n;
	vector<int>tal(n);
	for (int i = 0; i < n; i++)cin >> tal[i];
	sort(all(tal));
	int q;
	cin >> q;
	while (q--)
	{   int x, mn, mx;
		cin >> x;
		mn = lower_bound(all(tal),x) - tal.begin() - 1;
		mx = upper_bound(all(tal), x) - tal.begin();
		if (mn > 0 && mx >= n)
		{
			printf("%d X\n", tal[mn]);
		}
		else if (mn >= 0 && mn < n && mx >= 0 && mn < n)
		{
			cout << tal[mn] << " " << tal[mx] << endl;
		}
		else if (mn < 0 && mx < n)
		{
			printf("X %d\n", tal[mx]);
		}
		else
		{
			printf("X X\n");
		}
	}
}