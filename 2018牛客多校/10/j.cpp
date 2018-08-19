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
const int N=1e6+7;
int nxt[N][26],last[26];
char s[N];
char ans[N];
int main() {
	int T;scanf("%d",&T);while(T--) {
		memset(last,0,sizeof(last));
		memset(nxt,0,sizeof(nxt));
		int n;scanf("%d",&n);
		int nn=0;
		rep(cas,0,n) {
			int p=0;
			scanf("%s",s);
			for(int i=0;s[i];i++) {
				int a=s[i]-'a';
				if(nxt[p][a])p=nxt[p][a];
				else {
					for(int j=i;s[j];j++) {
						int b=s[j]-'a';
						ans[nn++]=s[j];
						rep(k,last[b],nn)nxt[k][b]=nn;
						last[b]=nn;
					}
					break;
				}
			}
		}
		ans[nn]=0;
		printf("%s\n",ans);
	}	
	return 0;
}
