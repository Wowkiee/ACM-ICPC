
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

int ans1,ans2,nn,T,n,k,len,now,le,x,xx,ma,mi,a[20],d,tmp,p[10];
unordered_map<int,int> M;
queue<int> q;

int get() {
	int res=0;
	for(int i=len-1;i>=0;i--) res=res*10+a[i];
	return res;
}

void bfs() {
	M[n]=0;q.push(n);
	while (!q.empty()) {
		if (M.count(mi)==1&&M.count(ma)==1) break;
		xx=x=q.front();q.pop();le=0;
		while (x>0) {a[le++]=x%10;x/=10;}
		d=M[xx];
		tmp=xx;
		int i=len-d-1;
		for(int j=len-1-d;j>=0;j--) if (i!=len-1||a[j]!=0){ 
			//swap(a[i],a[j]);
			//tmp=get();
			tmp-=p[i]*a[i]+p[j]*a[j];
			tmp+=p[i]*a[j]+p[j]*a[i];
			swap(a[i],a[j]);
			if (M.count(tmp)==0) {M[tmp]=d+1;q.push(tmp);}
			tmp-=p[i]*a[i]+p[j]*a[j];
			tmp+=p[i]*a[j]+p[j]*a[i];
			swap(a[i],a[j]);
		}
	}
	while (!q.empty()) q.pop();
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>T;
//	T=100;
	p[0]=1;rep(i,1,10) p[i]=p[i-1]*10;
	rep(cas,0,T) {
		cin>>n>>k;
		len=0;
	//	n=784321479;k=1000;
		nn=n;M.clear();
		while (nn>0) {a[len++]=nn%10;nn/=10;}
		sort(a,a+len);
		ma=get();
		reverse(a,a+len);
		if (a[len-1]==0) for(int i=len-2;i>=0;i--) if (a[i]>0) {swap(a[i],a[len-1]);break;}
		mi=get();
		//de(ma);de(mi);
		bfs();
		ans1=-1;
		ans2=-1;
		for(auto u : M) {
			//dd(u.fi);de(u.se);
			if (k>=u.se){
				if (ans1==-1||ans1>u.fi) ans1=u.fi;
				if (ans2==-1||ans2<u.fi) ans2=u.fi;
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
		//return 0;
	}
	return 0;
}
