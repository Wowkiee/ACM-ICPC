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
const int N = 1e5 + 7;
int xx[N];
int main() {
	int T;scanf("%d",&T);while(T--) {
		int n,q;scanf("%d%d",&n,&q);
		rep(i,1,n+1)scanf("%d",&data[i]);
		data[0]=0,data[n+1]=1e9+7;
		V.pb(0);
		rep(i,1,n+1)if(data[i]>data[V.back()])V.pb(i);
		V.pb(n+1);
		int Ans=sz(V)-2;
		rep(i,1,sz(V)-1) {
			xx[i]=Ans-1,now=V[i]-1;
			rep(j,V[i]+1,V[i+1]) {
				if(data[j]>data[now])now=j,xx[i]++;
			}
		}
		while(q--) {
			int a,b;scanf("%d%d",&a,&b);
			if(data[a]==b) {
				printf("%d\n",Ans);
				continue;
			}
			int p=lower_bound(all(V),a);
			if(V[p]==a) {
				if(data[a]>b) {
					int pnxt=upper_bound(all(V),b);
					printf("%d\n",Ans-(pnxt-p)+1);
				}
				else {

				}
			else {
				if(data[a]<b)printf("%d\n",Ans);
				else {


	return 0;
}
