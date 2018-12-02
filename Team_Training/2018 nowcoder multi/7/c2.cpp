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

const int N=(1<<18)+7;
const int mod1=1e9+7;
const int mod2=1e9+9;

unordered_map<int,int> M;
int n,m;
string s;
bool a[20][N];

int get(int dep,int mod) {
	int res=0,s=1<<dep;
	rep(i,0,s) {
		res=res*2+a[dep][i];
		if (res>mod) res-=mod;
	}
	return res;
}

int dfs(int dep) {
	if (dep==0) return a[0][0]==1;
	int h1=get(dep,mod1);//h2=get(dep,mod2);
	if (M.count(h1)==1) return M[h1];
	int s=1<<(dep-1),res=0;
	for(int i=0,j=0;i<s;i+=2,j++) a[dep-1][j]=a[dep][i]&a[dep][i+1];
	res+=dfs(dep-1);
	for(int i=0,j=0;i<s;i+=2,j++) a[dep-1][j]=a[dep][i]|a[dep][i+1];
	res+=dfs(dep-1);
	for(int i=0,j=0;i<s;i+=2,j++) a[dep-1][j]=a[dep][i]^a[dep][i+1];
	res+=dfs(dep-1);
	M[h1]=res;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cin>>n>>s;
	//srand(time(0));
	n=18;
	m=1<<n;
	rep(i,0,m) a[n][i]=rand()%2;//a[n][i]=s[i]-'0'; 
	cout<<dfs(n);
	return 0;
}
