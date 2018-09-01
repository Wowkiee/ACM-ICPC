#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N= 2e6 + 7;
char s[N];
int n;
int ans=0;
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%P;
		a=a*a%P;
		b>>=1;
	}
	return ans;
}
struct Palindromic_Tree
{
	static const int M=15,N=::N+2;
	int size[N],len;
	struct Node {
		int son[M];
		int ff,len;
		int val;
	}t[N];
	int last,tot;
	void init() {
		last=0,tot=1;
		len=n;
		memset(t,0,sizeof(Node)*(len+5));
		memset(size,0,sizeof(int)*(len+5));
		t[tot++].len=-1;
		t[0].ff=t[1].ff=1;
		t[0].val=t[1].val=0;
	}
	void build(char *s) {
		rep(i,0,len) {
			int c=s[i]-'0';
			int p=last;
			while(s[i-t[p].len-1]!=s[i])p=t[p].ff;
			if(!t[p].son[c]) {
				int v=tot++,k=t[p].ff;
				t[v].len=t[p].len+2;
				t[v].val=add(mul(t[p].val,10),c);
				if(t[v].len!=1)t[v].val=add(t[v].val,mul(c,kpow(10,t[v].len-1)));
				ans=add(ans,t[v].val);
				while(s[i-t[k].len-1]!=s[i])k=t[k].ff;
				t[v].ff=t[k].son[c];
				t[p].son[c]=v;
			}
			last=t[p].son[c];
			size[t[p].son[c]]++;
		}
	}
}tree;
int main() {
	scanf("%s",s);n=strlen(s);
	tree.init();
	tree.build(s);
	cout<<ans<<endl;
	return 0;
}
