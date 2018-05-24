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
char s1[200007],s2[200007];
int main() {
	scanf("%s%s",&s1,&s2);
	int len = strlen(s2),d1 = 0,d2 = 0;
	rep(i,0,len){
		if(s1[i] != s2[i]) {
			d1 = i;
			break;
		}
	} 
	per(i,0,len){
		if(s1[i] != s2[i]){
			d2 = i;
			break;
		}
	}
	int flag = 1;
	for(int i = d1,j = d2;i <= d2;i++,j--){
		if(s1[j] != s2[i]){
			flag = 0;
			break;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}

