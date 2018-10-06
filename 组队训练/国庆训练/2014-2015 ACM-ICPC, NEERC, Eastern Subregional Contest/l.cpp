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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
map<string,int> M;
int __abs(int a) {
	return a>0?a:-a;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	//1
	M["Alice"]=M["Ariel"]=M["Aurora"]=1;
	M["Phil"]=M["Peter"]=M["Olaf"]=1;
	M["Phoebus"]=M["Ralph"]=M["Robin"]=1;
	//2
	M["Bambi"]=M["Belle"]=M["Bolt"]=2;
	M["Mulan"]=M["Mowgli"]=M["Mickey"]=2;
	M["Silver"]=M["Simba"]=M["Stitch"]=2;
	//3
	M["Dumbo"]=M["Genie"]=M["Jiminy"]=3;
	M["Kuzko"]=M["Kida"]=M["Kenai"]=3;
	M["Tarzan"]=M["Tiana"]=M["Winnie"]=3;
	//main
	int n;cin>>n;
	int now=1,ans=0;
	rep(i,0,n) {
		string a;cin>>a;
		int nxt=M[a];
		ans+=__abs(nxt-now);
		now=nxt;
	}
	cout<<ans<<endl;
	return 0;
}
