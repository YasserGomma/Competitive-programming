#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
int ov, nv, n;
int arro[1001], arrn[1001], w[1001];
int mem[1001][22][80];
int solve(int idx, int ox, int ni)
{
	
	if (!ox  && !ni)
		return 0;
	if (idx == n)
		return 1e9;
	int& ret = mem[idx][ox][ni];
	if (~ret)
		return ret;
	int ch1 = solve(idx + 1, ox, ni);
	int ch2 = solve(idx + 1, max(0, ox - arro[idx]), max(0, ni - arrn[idx])) + w[idx];
	return ret = min(ch1, ch2);

}
int main()
{
	//nGu();
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(all(v), [](int a, int b) {return a > b;});
	ll ans = 0;
	for (int i = 2; i < n; i += 3)
		ans += v[i];
	cout << ans << endl;

}