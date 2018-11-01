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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
//0>2 2>1 1>0
int getRank(char a) {
	if(a=='R')return 0;
	if(a=='P')return 1;
	if(a=='S')return 2;
}
char getChar(int a) {
	if(a==0)return 'R';
	if(a==1)return 'P';
	if(a==2)return 'S';
}
struct Node {
	int zt;
	int ch[3];
}com[105],My[50005];
int p=1;
int xl[505],xx[105];
void dfs(int now) {
	int id=++p;
	xx[now]=id;
	My[id].zt=(com[now].zt+1)%3;
	int nxt=com[now].ch[My[id].zt];
	rep(j,0,3) {
		if(j!=com[now].zt)My[id].ch[j]=id;
		else {
			if(!xx[nxt])dfs(nxt);
			My[id].ch[j]=xx[nxt];
		}
	}
}
int main() {
	srand(time(0));
	freopen("epic.in", "r", stdin);
	freopen("epic.out", "w", stdout);
	int n;scanf("%d",&n);
	rep(i,1,n+1) {
		char s[5];
		scanf("%s",s);
		com[i].zt=getRank(s[0]);
		rep(j,0,3)scanf("%d",&com[i].ch[j]);
	}
	//build ac;
	rep(i,1,n+1)if(!xx[i])dfs(i);
	/*rep(i,1,n+1) {
		int now1=i,now2=xx[i];
		rep(j,0,10) {
			printf("%d %d\n",com[now1].zt,My[now2].zt);
			int temp1=My[now2].ch[com[now1].zt];
			int temp2=com[now1].ch[My[now2].zt];
			now1=temp2,now2=temp1;
		}
	}*/
	//build trie
	rep(i,0,500)xl[i]=rand()%3;
	rep(i,1,n+1) {
		int now1=i,now2=1;
		rep(j,0,500) {	
			My[now2].zt=xl[j];
			int temp2=com[now1].ch[My[now2].zt];
			if(j==500-1) {
				//assert(My[now2].ch[com[now1].zt]==0||My[now2].ch[com[now1].zt]==xx[temp2]);
				My[now2].ch[com[now1].zt]=xx[temp2];
			}
			if(!My[now2].ch[com[now1].zt])My[now2].ch[com[now1].zt]=++p;
			int temp1=My[now2].ch[com[now1].zt];
			now1=temp2,now2=temp1;
		}
	}
	printf("%d\n",p);
	rep(i,1,p+1) {
		printf("%c",getChar(My[i].zt));
		rep(j,0,3)printf(" %d",My[i].ch[j]==0?1:My[i].ch[j]);
		puts("");
	}
	return 0;
}
