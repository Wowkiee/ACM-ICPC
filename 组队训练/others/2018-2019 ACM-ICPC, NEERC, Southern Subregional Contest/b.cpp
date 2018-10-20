#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N=2e5+5;
typedef unsigned uint;
struct Trie {
	bool ok;
	int ch[2];
}pool1[N*35],pool2[N*35];
int rootb=0,rootw=0,ccb=1,ccw=1;
void insertb(uint a,int fl) {
	if(rootb==0)rootb++;
	int nowb=rootb,noww=rootw;
	if(pool2[noww].ok) {
		puts("-1");
		exit(0);
	}
	rep(i,1,fl+1) {
		int nxt=((a>>(32-i))&1);
		if(!pool1[nowb].ch[nxt])pool1[nowb].ch[nxt]=++ccb;
		noww=pool2[noww].ch[nxt];nowb=pool1[nowb].ch[nxt];
		if(pool2[noww].ok) {
			puts("-1");
			exit(0);
		}
	}
	pool1[nowb].ok=1;
}
void insertw(uint a,int fl) {
	if(rootw==0)rootw++;
	int nowb=rootb,noww=rootw;
	if(pool1[nowb].ok) {
		puts("-1");
		exit(0);
	}
	rep(i,1,fl+1) {
		int nxt=((a>>(32-i))&1);
		if(!pool2[noww].ch[nxt])pool2[noww].ch[nxt]=++ccw;
		noww=pool2[noww].ch[nxt];nowb=pool1[nowb].ch[nxt];
		if(pool1[nowb].ok) {
			puts("-1");
			exit(0);
		}
	}
	pool2[noww].ok=1;
}
//----trie
struct IP {
	uint adr;
	int fl,typ;
	IP(){}
	IP(uint _adr,int _fl,int _typ){adr=_adr,fl=_fl,typ=_typ;}
	void print() {
		printf("%u.%u.%u.%u/%d\n",255&(adr>>24),255&(adr>>16),255&(adr>>8),255&adr,fl);
	}
}data[N];
char s[100];
int cmp(IP a,IP b){return a.fl<b.fl;}
vector<IP> V;
void dfs(int nowb,int noww,uint adr,int fl) {
	if(!nowb)return;
	if(!noww) {
		V.pb(IP(adr<<(32-fl),fl,1));
		return;
	}
	rep(i,0,2)dfs(pool1[nowb].ch[i],pool2[noww].ch[i],adr<<1|i,fl+1);
}
//----
int main() {
	int n;scanf("%d",&n);
	rep(i,0,n) {
		vector<uint> V;
		scanf("%s",s);
		uint typ=(s[0]=='+'),now=0;
		for(int i=1;s[i];i++) {
			if(isdigit(s[i]))now=now*10+s[i]-'0';
			else V.pb(now),now=0;
		}
		V.pb(now);
		if(sz(V)==4)V.pb(32);
		uint adr=((V[0]<<24)|(V[1]<<16)|(V[2]<<8)|V[3]);
		data[i]=IP(adr,V[4],typ);
	}
	sort(data,data+n,cmp);
	rep(i,0,n) {
		if(data[i].typ)insertw(data[i].adr,data[i].fl);
		else insertb(data[i].adr,data[i].fl);
	}
	dfs(rootb,rootw,0,0);
	printf("%d\n",sz(V));
	rep(i,0,sz(V))V[i].print();
	return 0;
}
