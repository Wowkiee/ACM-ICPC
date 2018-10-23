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
const int N=100005,M=10;
struct FastIO {
	static const int S=1310720;
	int wpos;
	char wbuf[S];
	FastIO() : wpos(0) { }
	inline int xchar() {
		static char buf[S];
		static int len=0,pos=0;
		if(pos==len)pos=0,len=fread(buf,1,S,stdin);
		if(pos==len)return -1;
		return buf[pos++];
	}
	inline int xint() {
		int c=xchar(),x=0,s=1;
		while(c<=32)c=xchar();
		if(c=='-')s=-1,c=xchar();
		for(;'0'<=c&&c<='9';c=xchar())x=x*10+c-'0';
		return x*s;
	}
}io;
int nowatk[M];
int mondef[N][M],monexp[N][M];
int killed[N];
int main() {
	int T;T=io.xint();while(T--) {
		int ans=0;
		priority_queue<pii> Q[M];
		int n,m;n=io.xint();m=io.xint();
		rep(i,0,m)nowatk[i]=io.xint();
		rep(i,0,n) {
			killed[i]=0;
			rep(j,0,m)mondef[i][j]=io.xint(),Q[j].push({-mondef[i][j],i});
			rep(j,0,m)monexp[i][j]=io.xint();
		}
		for(int j=0,cc=0;cc<m;j=(j+1)%m) {
			int del=0;
			while(!Q[j].empty()) {
				pii f=Q[j].top();
				f.fi=-f.fi;
				if(f.fi<=nowatk[j]) {
					killed[f.se]++;Q[j].pop();
					if(killed[f.se]==m) {
						ans++;
						rep(j,0,m)nowatk[j]+=monexp[f.se][j];
						del=1;
					}
				}
				else break;
			}
			if(del)cc=0;else cc++;
		}
		printf("%d\n",ans);
		rep(j,0,m)printf("%d%c",nowatk[j],j==m-1?'\n':' ');
	}
	return 0;
}
