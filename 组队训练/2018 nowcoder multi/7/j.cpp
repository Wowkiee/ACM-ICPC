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

const int N=1005;
ll ans;
int a[N][N],R[N][N],down[N][N],nx[70],mi,pos,k,n,m,MIN[N];
string s;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>n>>m;
	rep(i,1,n+1) {
		cin>>s;	
		rep(j,0,m) {
			if (s[j]>='a'&&s[j]<='z') a[i][j+1]=s[j]-'a';else a[i][j+1]=s[j]-'A'+26;
		}
	}
	//rep(i,1,n+1) {rep(j,1,m+1) cout<<a[i][j]<<" ";cout<<endl;}
	rep(i,1,n+1) {
			fill_n(nx,60,m);
			R[i][m+1]=m;
			for (int j=m;j>=1;j--) {
				R[i][j]=nx[a[i][j]];
				nx[a[i][j]]=j-1;
				R[i][j]=min(R[i][j],R[i][j+1]);
			}
	}
	//rep(i,1,n+1) {rep(j,1,m+1) cout<<R[i][j]<<" ";cout<<endl;}
	rep(j,1,m+1) {
		fill_n(nx,60,n);
		down[n+1][j]=n;
		for (int i=n;i>=1;i--) {
			down[i][j]=nx[a[i][j]];
			nx[a[i][j]]=i-1;
			down[i][j]=min(down[i][j],down[i+1][j]);
		}
	}
	//rep(i,1,n+1) {rep(j,1,m+1) cout<<down[i][j]<<" ";cout<<endl;}
	rep(i,1,n+1)
		rep(j,1,m+1) {
			pos=down[i][j];k=j+1;ans+=pos-i+1;mi=down[i][j];
		//	de(mi);
			MIN[i]=R[i][j];
			rep(l,i+1,pos+1) MIN[l]=min(MIN[l-1],R[l][j]); 
			while (k<=R[i][j]) {
				mi=min(mi,down[i][k]);
				while (pos>mi||MIN[pos]<k) pos--;
				//de(pos);
				ans+=pos-i+1;
				k++;
			} 
		}
	cout<<ans;
	return 0;
}
