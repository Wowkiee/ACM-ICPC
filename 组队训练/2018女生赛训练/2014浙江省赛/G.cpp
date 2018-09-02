#include<bits/stdc++.h> 
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.szie()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int op(char c){
	if(c == '+') return 1;
	else if(c == '-') return 2;
	else if (c == '*') return 3;
	else if(c == '/') return 4;
	else return 5;
}
int main() {
	int a,b,c;
	int ans;
	char s[3][10];
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d%s%d%s%d",&a,s[0],&b,s[1],&c);
		
		//cout<<a<<' '<<b<<' '<<c<<endl;
	//	cout<<s[0][0]<<endl;
	//	cout<<s[1][0]<<endl;
		
		s[0][1] = s[0][0];
		s[1][1] = s[1][0];
		
		
		if((s[0][1] == '+' || s[0][1] == '-') && (s[1][1] != '+' && s[1][1] != '-')){
			
			//cout<<"1"<<endl;
			if(s[1][1] == '*') ans = b * c;
			else if(s[1][1] == '/') ans = b / c;
			else ans = b % c; 
			
			int t = op(s[0][1]);
			if(t == 1) ans = a + ans;
			else if(t == 2) ans = a - ans;
			else if(t == 3) ans = a * ans;
			else if(t == 4) ans = a / ans;
			else ans = a % ans;
		}else{
			
			//cout<<"2"<<endl;
			ans = b;
			int t = op(s[0][1]);
			if(t == 1) ans = a + ans;
			else if(t == 2) ans = a - ans;
			else if(t == 3) ans = a * ans;
			else if(t == 4) ans = a / ans;
			else ans = a % ans;
			
			t = op(s[1][1]);
			if(t == 1) ans = ans + c;
			else if(t == 2) ans = ans - c;
			else if(t == 3) ans = ans * c;
			else if(t == 4) ans = ans / c;
			else ans = ans % c;
		}
		printf("%d\n",ans);
	}
	return 0;
}

