#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N= 1<<19;
const int P= 1e9 + 7;
int inv(int x){return x==1?x:P-ll(P/x)*inv(P%x)%P;}
int cnt=0;
void FWT(int *a,int len,int o) {
	cnt++;
	int inv2=inv(2);
	for(int k=0;1<<k<len;k++) rep(i,0,len) if(~i>>k&1) {
		int j=i^(1<<k),x,y;
		x=(a[i]+a[j])%P,y=(a[i]-a[j]+P)%P;
		if(o==-1)x=ll(x)*inv2%P,y=ll(y)*inv2%P;
		a[i]=x,a[j]=y;
	}
}
int cc[5][N*4]={0};
int now[N*4]={1},temp[N*4]={1};
int main() {
	int n;scanf("%d",&n);
	int ans=0;
	bool ok=0;
	rep(i,0,n) {
		int a;scanf("%d",&a);cc[0][a]=1;ans^=a;
	}
	int res=0;
	FWT(cc[0],N,1);
	rep(i,1,5)
	{
		rep(j,0,N)cc[i][j]=1LL*cc[i-1][j]*cc[i-1][j]%P;
		FWT(cc[i],N,-1);
		rep(j,0,N)cc[i][j]=!!cc[i][j];
		FWT(cc[i],N,1);
	}
	per(cas,0,5) {
		rep(i,0,N)temp[i]=now[i];
		FWT(temp,N,1);
		rep(i,0,N)temp[i]=1LL*temp[i]*cc[cas][i]%P;
		FWT(temp,N,-1);
		rep(i,0,N)if(temp[i])temp[i]=1;
		if(!temp[ans]) {
			res+=(1<<cas);
			rep(i,0,N)now[i]=temp[i];
		}
	}
	cout<<n-res-1<<endl;
	de(cnt);
	return 0;
}
/*int main()
	{
	rep(i, 1, n+1) {
	cin >> x; y = x;
//de(y);
cc[1]=1;
FWT(cc,3,1);FWT(now,3,1);
rep(i,0,2)now[i]=1LL*now[i]*cc[i]%P;
FWT(now,3,-1);
rep(i,0,2)de(now[i]);
}*/
