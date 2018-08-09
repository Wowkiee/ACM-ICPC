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

const int N=5e5+5;
int pos,n,s,d,a[N];

void work(int n) {
	//de(n);
	if (n<=0) return;
	for(int i=20;i>=0;i--) if ((1<<i) & n){ pos=i;break;}
	s=1<<pos;
	d=n-s;
	rep(i,1,d+2) a[s-1+i]=s-i,a[s-i]=s-1+i;
	//return;
	work(s-d-2);
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	work(n-1);
	rep(i,0,n-1) cout<<a[i]<<" ";
	cout<<a[n-1];
	return 0;
}
