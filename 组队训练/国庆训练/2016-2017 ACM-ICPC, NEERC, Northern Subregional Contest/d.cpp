#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N=101,M=11;
int d[10][N];
bool dp[N*3][M][M][M][M][2];
pii last[N*3][M][M][M][M][2];
bool hh[M][M][M];
int ok[11][7]={
	{1,1,1,0,1,1,1},//0
	{0,0,1,0,0,1,0},//1
	{1,0,1,1,1,0,1},//2
	{1,0,1,1,0,1,1},//3
	{0,1,1,1,0,1,0},//4
	{1,1,0,1,0,1,1},//5
	{1,1,0,1,1,1,1},//6
	{1,0,1,0,0,1,0},//7
	{1,1,1,1,1,1,1},//8
	{1,1,1,1,0,1,1},//9
	{0,0,0,0,0,0,0} //10
};
void out(int a,int b,int c,int d,int e) {
	//de(a),de(b),de(c),de(d),de(e);
}
int main() {
	freopen("digital.in","r",stdin);
	freopen("digital.out","w",stdout);
	int n;scanf("%d",&n);
	rep(i,0,9)rep(j,0,n+i%2)scanf("%d",&d[i][j]);
	dp[0][10][10][10][10][0]=true;
	rep(i,0,n)rep(j,0,3) {
		int id=i*3+j+1;
		rep(a1,0,11)rep(a2,0,11)rep(a3,0,11)rep(a4,0,11)rep(zt,0,2)if(dp[id-1][a1][a2][a3][a4][zt]) {
			rep(a5,0,10) {
				if(j==0) {
					int r1=d[0][i],r2=d[1][i];
					int n1=ok[a5][0],n2=(ok[a2][2]|ok[a5][1]);
					if(r1==n1&&r2==n2)dp[id][a2][a3][a4][a5][zt]=true,last[id][a2][a3][a4][a5][zt]=mp(a1,zt),out(id,a2,a3,a4,a5);
				}
				if(j==1) {
					int r1=d[2][i],r2=d[3][i];
					int n1=(ok[a4][3]|ok[a5][0]),n2=(ok[a1][5]|ok[a2][2]|ok[a4][4]|ok[a5][1]);
					if(r1==n1&&r2==n2)dp[id][a2][a3][a4][a5][zt]=true,last[id][a2][a3][a4][a5][zt]=mp(a1,zt),out(id,a2,a3,a4,a5);
				}
				if(j==2) {
					int r1=d[4][i],r2=d[5][i],r3=d[6][i],r4=d[7][i],r5=d[8][i];
					int n1=(ok[a3][6]|ok[a4][3]|ok[a5][0]);
					int n2=(ok[a1][5]|ok[a2][2]|ok[a4][4]|ok[a5][1]);
					int n3=(ok[a4][6]|ok[a5][3]);
					int n4=(ok[a2][5]|ok[a5][4]);
					int n5=ok[a5][6];
					if(r1==n1&&r2==n2&&r3==n3&&r4==n4&&r5==n5) {
						int sum=a3+a4;
						if(sum%10==a5) {
							if(sum>=10&&zt==1) {
								dp[id][a2][a3][a4][a5][0]=true;
								last[id][a2][a3][a4][a5][0]=mp(a1,zt);
							}
							if(sum<10&&zt==0) {
								dp[id][a2][a3][a4][a5][0]=true;
								last[id][a2][a3][a4][a5][0]=mp(a1,zt);
							}
						}
						if((sum+1)%10==a5) {
							if(sum+1>=10&&zt==1) {
								dp[id][a2][a3][a4][a5][1]=true;
								last[id][a2][a3][a4][a5][1]=mp(a1,zt);
							}
							if(sum+1<10&&zt==0) {
								dp[id][a2][a3][a4][a5][1]=true;
								last[id][a2][a3][a4][a5][1]=mp(a1,zt);
							}
						}
					}
				}
			}
		}
	}
	rep(a1,0,10)rep(a2,0,10)rep(a3,0,10) {
		int r1=d[1][n],r2=d[3][n],r3=d[5][n],r4=d[7][n];
		int n1=ok[a1][2];
		int n2=(ok[a1][5]|ok[a2][2]);
		int n3=(ok[a2][5]|ok[a3][2]);
		int n4=ok[a3][5];
		if(r1==n1&&r2==n2&&r3==n3&&r4==n4)hh[a1][a2][a3]=true;
	}
	rep(A1,0,11)rep(A2,0,11)rep(A3,0,11)rep(A4,0,11)if(dp[3*n][A1][A2][A3][A4][0]&&hh[A2][A3][A4]) {
		vector<int> V;
		int a1=A1,a2=A2,a3=A3,a4=A4,zt=0;
		V.pb(a4),V.pb(a3),V.pb(a2),V.pb(a1);
		int now=3*n;
		while(now) {
			pii temp=last[now][a1][a2][a3][a4][zt];
			a4=a3,a3=a2,a2=a1,a1=temp.fi,zt=temp.se;
			V.pb(temp.fi);
			now--;
		}
		vector<int> ans[3];
		rep(i,0,3*n)ans[i%3].pb(V[i]);
		int val[3]={0};
		int jw=0;
		int o=1;
		rep(i,0,n) {
			int now=ans[2][i]+ans[1][i]+jw;
			if(now>=10)now-=10,jw=1;
			else jw=0;
			if(now!=ans[0][i])o=0;
		}
		if(jw==1)o=0;
		if(o) {	
			per(i,0,3) {
				per(j,0,n)printf("%d",ans[i][j]);
				puts("");
			}
			return 0;
		}
	}
	puts("NO");
	return 0;
}
