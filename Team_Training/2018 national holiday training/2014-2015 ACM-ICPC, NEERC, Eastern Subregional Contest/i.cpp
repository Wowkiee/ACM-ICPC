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
char s1[1005],s2[1005];
queue<char> Q1,Q2;
int main() {
	scanf("%s%s",s1,s2);
	for(int i=0;s1[i];i++)Q1.push(s1[i]);
	for(int i=0;s2[i];i++)Q2.push(s2[i]);
	int ans=0;
	while(!Q1.empty()&&!Q2.empty()) {
		char a=Q1.front();
		char b=Q2.front();
		if(a=='L'&&b!='L')Q2.pop();
		else if(a!='L'&&b=='L')Q1.pop();
		else Q1.pop(),Q2.pop();
		ans++;
	}
	while(!Q1.empty())Q1.pop(),ans++;
	while(!Q2.empty())Q2.pop(),ans++;
	cout<<ans<<endl;
	return 0;
}
