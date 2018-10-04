#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=25;
char s[1005];
int F[N];
int fa[N],val[N];
int last[1005];
vector<int> V[N];
char str[10][100]={"","n","1/2*(n-1)","1/3*(n-2)","1/4*(n-3)","1/5*(n-4)","1/6*(n-5)","1/7*(n-6)"};
void dfs(int a) {
	if(val[a]>=0)printf("%d",val[a]);
	else printf("%s",str[-val[a]]);
	if(sz(V[a])) {
		printf("*(");
		rep(i,0,sz(V[a])) {
			dfs(V[a][i]);
			if(i!=sz(V[a])-1)printf("+");
		}
		printf(")");
	}
}
int main() {
//	freopen("fygon.in","r",stdin);
//	freopen("fygon.out","w",stdout);
	val[0]=1;last['n']=0;
	int cc=0,now=0;
	while(gets(s)) {
		cc++;
		int f=1,p=0;
		while(s[p]==' ')f++,p+=4;
		while(F[now]>=f)now=fa[now];
		fa[cc]=now;F[cc]=f;
		if(s[p]=='l')val[cc]=1;
		else {
			int var=s[p+4],rge=s[p+15];
			if(isdigit(rge))val[cc]=rge-'0';
			else {
				last[var]=last[rge]+1;
				val[cc]=-last[var];
			}
		}
		now=cc;
	}
	rep(i,1,cc+1)V[fa[i]].pb(i);
	dfs(0);
	return 0;
}
