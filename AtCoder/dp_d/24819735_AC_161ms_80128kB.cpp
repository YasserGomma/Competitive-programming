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
ll v[100007],w[100007],we, n;
ll mem[101][100007];
ll knap(int i, int rem)
{
	if (i == n)
		return 0;
	ll& ret = mem[i][rem];
	if (~ret)return ret;
	ll choice1 = knap(i + 1, rem); // LEAVE
	ll choice2 = 0;

	if (rem>=w[i])
		choice2 = knap(i + 1, rem-w[i])+v[i];

	return ret= max(choice1, choice2);
}
int main()
{
	//GOAT();
	clr(mem, -1);
	cin >> n >> we;
	for (int i = 0; i < n; i++)
		cin >>w[i]>> v[i];
	cout << knap(0,we) << endl;




}