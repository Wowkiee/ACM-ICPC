#include<cstring>
#include<cstdio>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;

const int N=1007;

int n,m;
int cnt[N<<2][N<<2];

void updy(int fa,int L,int R,int l=1,int r=n,int rt=1) {
	if(L<=l&&r<=R) {
		++cnt[fa][rt];
		return ;
	}
	int mid=l+r>>1;
	if(L<=mid) updy(fa, L, R, l, mid, rt<<1);
	if(R>=mid+1) updy(fa, L, R, mid+1, r, rt<<1|1);
} 

void updx(int x1,int x2,int y1,int y2,int l=1,int r=n,int rt=1) {
	if(x1<=l&&r<=x2) {
		updy(rt,y1,y2);
		return ;
	}
	int mid=l+r>>1;
	if(x1<=mid) updx(x1, x2, y1, y2, l, mid, rt<<1);
	if(x2>=mid+1) updx(x1, x2, y1, y2, mid+1, r, rt<<1|1);
}

int qryy(int fa,int p,int l=1,int r=n,int rt=1) {
	int ans=cnt[fa][rt];
	if(l==r) return ans;
	int mid=l+r>>1;
	if(p<=mid) ans+=qryy(fa, p, l, mid, rt<<1);
	else ans+=qryy(fa, p, mid+1, r, rt<<1|1);
	return ans;
}

int qryx(int x,int y,int l=1,int r=n,int rt=1) {
	int ans=qryy(rt, y);
	if(l==r) return ans;
	int mid=l+r>>1;
	if(x<=mid) ans+=qryx(x, y, l, mid, rt<<1);
	else ans+=qryx(x, y, mid+1, r, rt<<1|1);
	return ans;
}

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&m);
		while(m--) {
			char s[11];
			int x1, y1;scanf("%s%d%d",s,&x1,&y1);
			if(s[0]=='C') {
				int x2, y2;scanf("%d%d",&x2,&y2);
				updx(x1, x2, y1, y2);
			} else {
				int t=qryx(x1, y1);
				printf("%d\n",t&1);
			}
		}
		if(T) puts("");
	}
	return 0;
}
