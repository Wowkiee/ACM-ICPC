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
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//---
int getid(string a) {
	if(a=="Russia")return 0;
	if(a=="Sweden")return 1;
	if(a=="Finland")return 2;
	if(a=="NA")return 3;
}
pii score[5][5];
int OT[5][5];
int point[5],tw[5],ptw[5],gd[5],gs[5];
int winflag,loseflag;
int win(int a,int b) {
	return score[a][b].fi>score[a][b].se;
}
int cmp1(int a,int b) {
	if(point[a]!=point[b])return point[a]>point[b];
	return win(a,b);
}
int cmp(int a,int b) {
	if(point[a]!=point[b])return point[a]>point[b];
	if(tw[a]!=tw[b])return tw[a]>tw[b];
	if(ptw[a]!=ptw[b])return ptw[a]>ptw[b];
	if(gd[a]!=gd[b])return gd[a]>gd[b];
	if(gs[a]!=gs[b])return gs[a]>gs[b];
	return 0;
}
void solve(bool pt) {
	int rank[]={0,1,2,3};
	memset(point,0,sizeof(point));
	memset(tw,0,sizeof(tw));
	memset(ptw,0,sizeof(ptw));
	memset(gd,0,sizeof(gd));
	memset(gs,0,sizeof(gs));
	rep(i,0,4)rep(j,0,i) {
		pii now=score[i][j];
		if(now.fi<now.se) {
			point[j]+=2;
			if(OT[i][j])point[i]++;
			//point
			tw[j]++;
			if(!OT[i][j])ptw[j]++;
			gd[j]+=now.se-now.fi;
			gd[i]+=now.fi-now.se;
			gs[i]+=now.fi;gs[j]+=now.se;
		}
		else {
			point[i]+=2;
			if(OT[i][j])point[j]++;
			tw[i]++;
			if(!OT[i][j])ptw[i]++;
			gd[i]+=now.fi-now.se;
			gd[j]+=now.se-now.fi;
			gs[i]+=now.fi,gs[j]+=now.se;
		}
	}
	sort(rank,rank+4,cmp1);
	if(point[rank[0]]==point[rank[1]]&&point[rank[1]]==point[rank[2]]&&point[rank[2]]!=point[rank[3]]) {
		sort(rank,rank+3,cmp);
		if(rank[0]==0)loseflag=0;
		else if(rank[3]==0)winflag=0;
		else if(rank[1]==0) {
			loseflag=0;
			if(!cmp1(rank[1],rank[2]))winflag=0;
		}
		else if(rank[2]==0) {
			winflag=0;
			if(!cmp1(rank[1],rank[2]))loseflag=0;
		}
	}
	else if(point[rank[0]]!=point[rank[1]]&&point[rank[1]]==point[rank[2]]&&point[rank[2]]==point[rank[3]]) {
		sort(rank+1,rank+4,cmp);
		if(rank[0]==0)loseflag=0;
		else if(rank[3]==0)winflag=0;
		else if(rank[1]==0) {
			loseflag=0;
			if(!cmp1(rank[1],rank[2]))winflag=0;
		}
		else if(rank[2]==0) {
			winflag=0;
			if(!cmp1(rank[1],rank[2]))loseflag=0;
		}
	}
	else if(point[rank[0]]==point[rank[1]]&&point[rank[1]]==point[rank[2]]&&point[rank[2]]==point[rank[3]]) {
		sort(rank,rank+4,cmp);
		if(rank[0]==0)loseflag=0;
		else if(rank[3]==0)winflag=0;
		else if(rank[1]==0) {
			loseflag=0;
			if(!cmp1(rank[1],rank[2]))winflag=0;
		}
		else if(rank[2]==0) {
			winflag=0;
			if(!cmp1(rank[1],rank[2]))loseflag=0;
		}
	}
	else if(rank[0]==0||rank[1]==0)loseflag=0;
	else winflag=0;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int flag=0;
	string last;
	rep(i,0,5) {
		string a,b;
		int c,d;
		if(!flag)cin>>last;a=last;
		cin>>last;b=last;
		cin>>c>>d;
		int ida=getid(a),idb=getid(b);
		score[ida][idb]=mp(c,d);
		score[idb][ida]=mp(d,c);
		cin>>last;
		if(last=="OT") {
			OT[ida][idb]=OT[idb][ida]=1;
			flag=0;
		}
		else flag=1;
	}
	string o1,o2;
	if(!flag)cin>>last;o1=last;cin>>last;o2=last;
	int ido1=getid(o1),ido2=getid(o2);
	winflag=1,loseflag=1;
	rep(i,0,100)rep(j,0,100)if(i!=j) {
		score[ido1][ido2]=mp(i,j);
		score[ido2][ido1]=mp(j,i);
		solve(false);
	}
	rep(i,0,100) {
		score[ido1][ido2]=mp(i,i+1);
		score[ido2][ido1]=mp(i+1,i);
		OT[ido1][ido2]=OT[ido2][ido1]=1;
		solve(false);
	}
	rep(i,0,100) {
		score[ido1][ido2]=mp(i+1,i);
		score[ido2][ido1]=mp(i,i+1);
		OT[ido1][ido2]=OT[ido2][ido1]=1;
		solve(false);
	}
	if(winflag)cout<<"Already in playoff!"<<endl;
	else if(loseflag)cout<<"No chance"<<endl;
	else cout<<"Believe in playoff!"<<endl;
	return 0;
}
