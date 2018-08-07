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

int mi[30][20],ma[30][20],T,n,k,len,now;

int get(int t,int o) {
	int res=0;
	if (o==0) for(int i=len-1;i>=0;i--) res=res*10+mi[t][i];
	else for(int i=len-1;i>=0;i--) res=res*10+ma[t][i];
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>T;
	rep(cas,0,T) {
		cin>>n>>k;len=0;
		while (n>0) {
			mi[0][len++]=n%10;n/=10;
			ma[0][len-1]=mi[0][len-1];
		}
		//de(n);de(k);de(len);
		rep(t,1,21) {
			rep(i,0,len) mi[t][i]=mi[t-1][i],ma[t][i]=ma[t-1][i];
			now=get(t,0);
			rep(i,0,len) rep(j,i+1,len) {
				if ((i==len-1&&mi[t-1][j]==0)||(j==len-1&&mi[t-1][i]==0)) continue;
				swap(mi[t-1][j],mi[t-1][i]);
				int tmp=get(t-1,0);
				if (tmp<now) {
					now=tmp;
					rep(l,0,len) mi[t][l]=mi[t-1][l];
				}	
				swap(mi[t-1][j],mi[t-1][i]);
			}
			now=get(t,1);
			//de(now);
			rep(i,0,len) rep(j,i+1,len) {
				if ((i==len-1&&ma[t-1][j]==0)||(j==len-1&&ma[t-1][i]==0)) continue;
				swap(ma[t-1][j],ma[t-1][i]);
				int tmp=get(t-1,1);
				if (tmp>now) {
					now=tmp;
					rep(l,0,len) ma[t][l]=ma[t-1][l];
				}	
				swap(ma[t-1][j],ma[t-1][i]);
			}
		}
		k=min(k,20);
		for(int i=len-1;i>=0;i--) cout<<mi[k][i];
		cout<<" ";
		for(int i=len-1;i>=0;i--) cout<<ma[k][i];
		cout<<endl;
	}
	return 0;
}
