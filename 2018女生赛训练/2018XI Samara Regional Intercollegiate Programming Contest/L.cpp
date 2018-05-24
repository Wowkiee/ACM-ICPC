#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

namespace Doubling{
	static const int N = 201010;
	int t[N],wa[N],wb[N],sa[N],h[N];
	void sort(int *x,int *y,int n,int m){
		rep(i,0,m) t[i] = 0;
		rep(i,0,n) t[x[y[i]]]++;
		rep(i,1,m) t[i] += t[i-1];
		for(int i=n-1;i>=0;i--) sa[--t[x[y[i]]]] = y[i];
	}
	bool cmp(int *x,int a,int b,int d){
		return x[a] == x[b] && x[a+d] == x[b+d]; 
	}
	void da(int *s,int n,int m){
		int *x=wa,*y=wb;
		rep(i,0,n) x[i] = s[i],y[i]=i;
		sort(x,y,n,m);
		for(int j=1,p=1;p<n;m=p,j<<=1){
			p=0;rep(i,n-j,n) y[p++] = i;
			rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
			sort(x,y,n,m);
			swap(x,y);p = 1;x[sa[0]] = 0;
			rep(i,1,n) x[sa[i]] = cmp(y,sa[i],sa[i - 1],j)?p-1:p++;		
		}
	}
	void cal_h(int *s,int n,int *rk){
		int j,k = 0;
		for(int i = 1;i<=n;++i) rk[sa[i]] = i;
		for(int i = 0;i<n;h[rk[i++]] = k)
			for(k&&--k,j=sa[rk[i]-1];s[i+k]==s[j+k];++k); 
	}
}
struct DA{
	static const int N = 201010;
	int p[18][N], rk[N], in[N], Log[N], n;
	void Build(){
		Doubling::da(in,n+1,300);
		Doubling::cal_h(in,n,rk);
		Log[0]=-1;for(int i=1;i<=n;++i) Log[i] = Log[i>>1]+1;
		for(int i=1;i<=n;++i) p[0][i]=Doubling::h[i];
		for(int j=1;1<<j<=n;++j){
			int lim = n+1-(1<<j);
			for(int i=1;i<=lim;++i)
				p[j][i] = min(p[j-1][i], p[j-1][i+(1<<j>>1)]); 
		} 
	}
	int lcp(int a,int b){
		a = rk[a],b = rk[b];
		if(a > b) swap(a, b);++a;
		int t = Log[b - a + 1];
		return min(p[t][a], p[t][b-(1<<t)+1]); 
	}
}da;

const int N=202020;

int n,m,len;
int l[N], r[N];
char s[N];

int Get(int i) {
	if(i>=n) return 0;
	return s[i]-'a'+1;
}

int calc(int L,int R,int ch) {
	int res=-1;
	while(L<=R) {
		int mid=L+R>>1;
		int y=Doubling::sa[mid]+len-1;
		if(Get(y)>=ch) {
			res=mid;
			R=mid-1;
		} else {
			L=mid+1;
		}
	}
	return res;
}

int main() {
	///read
	scanf("%s%d",s,&m);
	///build
	n=da.n=strlen(s);
	for(int i=0;s[i];++i) da.in[i]=s[i]-'a'+1;
	da.in[n]=0;
	da.Build();
	///solve
	l[0]=len=0;r[0]=n;
	int now=0;
	rep(i,1,m+1) {
		char str[5];scanf("%s",str);
		if(str[1]=='u') {
			scanf("%s",str); 
			++now;++len;
			if(l[now-1]>r[now-1]) {
				l[now]=l[now-1];
				r[now]=r[now-1];
			} else {
				l[now]=calc(l[now-1], r[now-1], str[0]-'a'+1);
				r[now]=calc(l[now-1], r[now-1], str[0]-'a'+2)-1;
			}
	//		dd("----------");dd('u');de(str[0]);
		} else {
			--now;--len;
	//		dd("----------");de('o');
		}
		printf("------------%s\n",l[now]<=r[now]?"YES":"NO");
	}
	return 0;
}

