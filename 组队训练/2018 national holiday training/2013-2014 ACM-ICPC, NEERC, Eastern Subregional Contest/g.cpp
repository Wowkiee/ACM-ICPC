#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//---
const int P=1e9+7;
//FWT
const int N=300005;
char s1[N][10],s2[N][10];
int suf1[N],suf2[N];
int data1[N*15],data2[N*15],data3[N*15];
int solve(char *s) {
	int ans=0;
	rep(i,0,8)ans+=s[i]=='1';
	return ans;
}
int main() {
	int n,m;scanf("%d%d",&n,&m);
	if(n<m) {
		puts("NO");
		return 0;
	}
	int Len=1;
	while((n+m)*8+10>=Len)Len<<=1;
	de(Len);
	rep(i,0,n)scanf("%s",s1[i]);
	rep(i,0,m)scanf("%s",s2[i]);
	per(i,0,n)suf1[i]=suf1[i+1]+solve(s1[i]);
	per(i,0,m)suf2[i]=suf2[i+1]+solve(s2[i]);
	rep(i,0,n)rep(j,0,8)data1[i*8+j]=(s1[i][j]=='1');
	int p=0;
	per(i,0,m)per(j,0,8)data2[p++]=(s2[i][j]=='1');
	rep(i,0,Len)printf("%d",data1[i]);puts("");
	rep(i,0,Len)printf("%d",data2[i]);puts("");
	rep(i,0,Len)rep(j,0,i+1)data3[i]+=data1[j]^data2[i-j];
	FWT(data1,Len,1);FWT(data2,Len,1);
	rep(i,0,Len) data1[i]=1ll*data1[i]*data2[i]%P;
	FWT(data1,Len,-1);
	rep(i,0,Len)printf("%d",data1[i]);puts("");
	rep(i,m,n+1) {
		int ans=data1[i*8-1];
		cout<<ans<<endl;
	}
	return 0;
}
