#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=100005;
int data[N],ans[N],Ans[N];
void update(int &a,int b) {
	if(a!=b) {
		if(a==-2)a=b;
		else a=-1;
	}
}
//--tarjan
stack<int> s;
vector<int> v[N];
int dfn[N],low[N],instack[N],npoint[N];
int cnt=0,Index=0;
void tarjan(int a) {
	dfn[a]=low[a]=++Index;
	s.push(a);
	instack[a]=1;
	rep(i,0,sz(v[a])) {
		int nxt=v[a][i];
		if(!dfn[nxt]) {
			tarjan(nxt);
			low[a]=min(low[a],low[nxt]);
		}
		else if(instack[nxt])low[a]=min(low[a],dfn[nxt]);
	}
	if(dfn[a]==low[a]) {
		cnt++;
		while(s.top()!=a) {
			npoint[s.top()]=cnt;
			instack[s.top()]=0;
			update(Ans[cnt],ans[s.top()]);
			s.pop();
		}
		npoint[s.top()]=cnt;
		instack[s.top()]=0;
		update(Ans[cnt],ans[s.top()]);
		s.pop();
	}
}
//---
vector<int> V[N];
int id[N];
void output(int a) {
	if(a==-1)printf("unknown");
	else if(a==0)printf("sober");
	else printf("%d",a);
}
int main() {
	int n;scanf("%d",&n);
	rep(i,1,n+1)ans[i]=Ans[i]=-2;
	ans[1]=0;
	rep(i,1,n+1) {
		int k;scanf("%d%d",&data[i],&k);
		if(data[i])rep(j,0,k) {
			int a;scanf("%d",&a);
			update(ans[a],data[i]);
		}
		else rep(j,0,k){
			int a;scanf("%d",&a);
			v[i].pb(a);
		}
	}
	rep(i,1,n+1)if(!dfn[i])tarjan(i);
	rep(i,1,n+1)rep(j,0,sz(v[i])) {
		int a=npoint[i],b=npoint[v[i][j]];
		if(a!=b) {
			V[a].pb(b);
			id[b]++;
		}
	}
	queue<int> Q;
	rep(i,1,cnt+1)if(!id[i])Q.push(i);
	while(!Q.empty()) {
		int a=Q.front();Q.pop();
		rep(i,0,sz(V[a])) {
			int nxt=V[a][i];
			update(Ans[nxt],Ans[a]);
			id[nxt]--;
			if(!id[nxt])Q.push(nxt);
		}
	}
	rep(i,1,n+1) {
		int now=npoint[i];
		output(Ans[npoint[i]]);
		printf(" ");
		if(data[i]==0)output(Ans[npoint[i]]);
		else printf("%d",data[i]);
		puts("");
	}
	return 0;
}
