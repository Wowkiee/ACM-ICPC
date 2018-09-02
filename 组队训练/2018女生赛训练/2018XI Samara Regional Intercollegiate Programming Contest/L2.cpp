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
char s[200007];
int dp[200007][26];
stack<int> st;
int main() {
	int n;
	scanf("%s",s + 1);
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	int len = strlen(s + 1);
	per(i,0,len){
		rep(j,0,26){
			if(s[i + 1] == 'a' + j) dp[i][j] = i + 1;
			else dp[i][j] = dp[i+1][j]; 
		} 
	}
	int pos = 0;
	char f[5],c;
	st.push(0);
	rep(i,0,n){
		scanf("%s",f);
		if(strcmp(f,"push") == 0){
			getchar();
			scanf("%c",&c);
			if(pos != -1){
				pos = dp[pos][c - 'a'];
			}
			st.push(pos); 
			if(pos != -1) printf("YES\n");
			else printf("NO\n");
		}else{
			st.pop();
			pos = st.top();
			if(pos != -1) printf("YES\n");
			else printf("NO\n");	
		}
		//de(pos);
	}
	return 0;
}

