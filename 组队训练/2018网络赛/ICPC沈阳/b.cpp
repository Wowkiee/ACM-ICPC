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
int getRank(char a) {
	if(a=='(')return 1;
	else if(a=='+'||a=='-')return 2;
	else if(a=='*')return 3;
	else return 4;
}
stack<pii> S1;
stack<char> S2;
vector<pii> V;
char s[105];
pii operator +(pii a,pii b) {
	return mp(a.fi+b.fi,a.se+b.se);
}
pii operator -(pii a,pii b) {
	return mp(a.fi-b.se,a.se-b.fi);
}
pii operator *(pii a,pii b) {
	vi v;
	v.pb(a.fi * b.fi);
	v.pb(a.fi * b.se);
	v.pb(a.se * b.fi);
	v.pb(a.se * b.se);
	sort(all(v));
	return mp(v[0], v[3]);
}
pii operator /(pii a,pii b) {
	return mp(a.fi,max(max(a.fi*b.se,a.fi*b.fi),max(a.se*b.fi,a.se*b.se)));
}
pii cal(pii a,pii b,char co) {
	if(co=='+')return a+b;
	if(co=='-')return a-b;
	if(co=='*')return a*b;
	if(co=='/')return a/b;
}
int main() {
	while(scanf("%s",s)!=EOF) {
		V.clear();
		int now=0;
		int i;
		for(i=0;s[i];i++) {
			if(isdigit(s[i]))now=now*10+s[i]-'0';
			else {
				if(i&&isdigit(s[i-1]))V.pb(mp(0,now)),now=0;
				if(s[i]=='d')s[i]='/';
				V.pb(mp(1,s[i]));
			}
		}
		if(isdigit(s[i-1]))V.pb(mp(0,now));
		rep(i,0,sz(V)) {
			if(V[i].fi==0)S1.push(mp(V[i].se,V[i].se));
			else {
				char now=V[i].se;
				if(now=='(')S2.push(now);
				else if(now==')') {
					while(S2.top()!='(') {
						pii b=S1.top();S1.pop();
						pii a=S1.top();S1.pop();
						char co=S2.top();S2.pop();
						S1.push(cal(a,b,co));
					}
					S2.pop();
				}
				else if(now=='+'||now=='-') {
					while(!S2.empty()&&getRank(S2.top())>=2) {
						pii b=S1.top();S1.pop();
						pii a=S1.top();S1.pop();
						char co=S2.top();S2.pop();
						S1.push(cal(a,b,co));
					}
					S2.push(now);
				}
				else if(now=='*') {
					while(!S2.empty()&&getRank(S2.top())>=3) {
						pii b=S1.top();S1.pop();
						pii a=S1.top();S1.pop();
						char co=S2.top();S2.pop();
						S1.push(cal(a,b,co));
						//de(S1.top().fi);de(S1.top().se);
					}
					S2.push(now);
				}
				else S2.push(now);
			}
		}
		while(!S2.empty()) {
			pii b=S1.top();S1.pop();
			pii a=S1.top();S1.pop();
			char co=S2.top();S2.pop();
			S1.push(cal(a,b,co));
			//de(S1.top().fi);de(S1.top().se);
		}
		assert(sz(S1)==1);
		printf("%d %d\n",S1.top().fi,S1.top().se);
		S1.pop();
	}
	return 0;
}
