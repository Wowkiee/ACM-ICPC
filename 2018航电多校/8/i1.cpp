#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N = 4e5 + 7;
const int INF=0x7fffffff;
const int mod=1e9+7;
int n;
int r[N],sa[N],rk[N],het[N];
int data[N];
int wa[N],wb[N],wx[N],wv[N];
bool ise(int *r,int a,int b,int len) {
	return r[a]==r[b]&&r[a+len]==r[b+len];
}
void getSa(int n,int m) {
	int *x=wa,*y=wb;
	rep(i,0,m)wx[i]=0;
	rep(i,0,n)++wx[x[i]=r[i]];
	rep(i,1,m)wx[i]+=wx[i-1];
	for(int i=n-1;i>=0;--i)sa[--wx[x[i]]]=i;
	for(int j=1,p=0;p<n;j<<=1,m=p) {
		p=0;
		rep(i,n-j,n)y[p++]=i;
		rep(i,0,n)sa[i]>=j?y[p++]=sa[i]-j:0;
		rep(i,0,m)wx[i]=0;
		rep(i,0,n)++wx[wv[i]=x[y[i]]];
		rep(i,1,m)wx[i]+=wx[i-1];
		for(int i=n-1;i>=0;--i)sa[--wx[wv[i]]]=y[i];
		p=1,swap(x,y);
		x[sa[0]]=0;
		rep(i,1,n)x[sa[i]]=ise(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void getHeight(int n) {
	rep(i,1,n+1)rk[sa[i]]=i;
	for(int i=0,k=0;i<n;het[rk[i++]]=k) {
		k=k>0?k-1:0;
		for(int j=sa[rk[i]-1];r[i+k]==r[j+k];++k);
	}
}
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int mul(int a, int b) {
	return 1ll * a * b % mod;
}
int add(int a, int b) {
	int r = a + b;
	if(r >= mod) r -= mod;
	return r;
}
int sub(int a, int b) {
	int r = a - b;
	if(r < 0) r += mod;
	return r;
}
string aa;
int Sum;
int pre[N], sum[N];
int fm[N], fz[N];
unordered_map<int, bool> um[N];
vi v[N]; 
pii Q[N];
ll Ans[N];
int len[N];

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x);
	y = find(y);
	if(sz(um[x]) > sz(um[y])) swap(x, y);
	Sum = sub(Sum, add(sum[x], sum[y]));
	for(auto u : um[x]) if(!um[y].count(u.fi)) {
		um[y][u.fi] = 1;
		sum[y] = mul(sum[y], data[u.fi]);
	}
	Sum = add(Sum, sum[y]);
}

void solve() {
	Sum = 0;
	int p = 0;
	rep(i, 0, sz(aa)) {
		if(i>len[p])p++;
		int t = i == len[p-1] ? N-1 : p;
		pre[i] = i, sum[i] = data[t];
		Sum = add(Sum, sum[i]);
		um[i][t]=1;
	}
	rep(i, 1, sz(aa)) v[het[i]].pb(i);
	for(int i = sz(aa); i; --i) {
		dd(i), de(sz(v[i]));
		for(auto u : v[i]) {
			join(u, u-1);
		}
		fz[i] = Sum;
		de(Sum);
	}
	fm[0] = 1;
	rep(i, 1, sz(aa)) fm[i] = mul(26, fm[i-1]);
	fm[0] = 0;
	rep(i, 1, sz(aa)) {
		fm[i] = add(fm[i], fm[i-1]);
		fz[i] = add(fz[i], fz[i-1]);
	}
}
int cmp(pii a,pii b) {
	return a.fi>b.fi;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>n;
	rep(i,0,n) {
		string a;cin>>a;
		aa=aa+a;
		len[i]=sz(aa);
		if(i!=n-1)aa+="#";
	}
	rep(i,0,n) cin >> data[i];
	rep(i,0,sz(aa))
	{
		r[i]=aa[i]-'a'+1;
		if(aa[i]=='#')r[i]=27;
	}
	r[sz(aa)]=0;
	getSa(sz(aa)+1,30);
	getHeight(sz(aa));
	rep(i, 0, sz(aa)+1) {
		rep(j, sa[i], sz(aa)) cout << aa[j];
		cout << endl;
	}
	solve();
	int q;
	cin >> q;
	while(q--) {
		int m;
		cin >> m;
		m = min(m, sz(aa));
		dd(m);
		dd(fz[m]), de(fm[m]);
		cout << mul(fz[m], kpow(fm[m], mod-2)) << endl;
	}
	return 0;
}
