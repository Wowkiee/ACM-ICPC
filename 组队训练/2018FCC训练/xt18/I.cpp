#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N=100005;
int data[N];
int dp1[N],dp2[N];
int nlis[N];
int Ans[N];
int xf[N];
int n;
int Lis;
int LIS()
{
	int LIS[N],ans=0;
	rep(i,1,n+5)LIS[i]=1000000;
	rep(i,1,n+1)if(data[i])
	{
		dp1[i]=lower_bound(LIS+1,LIS+ans+2,data[i])-LIS;
		LIS[dp1[i]]=data[i];
		ans=max(ans,dp1[i]);
	}
	ans=0;
	rep(i,1,n+5)LIS[i]=1000000;
	per(i,1,n+1)if(data[i])
	{
		dp2[i]=lower_bound(LIS+1,LIS+ans+2,-data[i])-LIS;
		LIS[dp2[i]]=-data[i];
		ans=max(ans,dp2[i]);
	}
	return ans;
}
void update(int l,int r)
{
	//cout<<l<<" "<<r<<endl;
	if(l>r)return;
	xf[l]++;xf[r+1]--;
}
int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	while(scanf("%d",&n)!=EOF)
	{
		Lis=0;
		rep(i,1,n+1)scanf("%d",&data[i]);
		rep(i,0,n+5)xf[i]=0;
		rep(i,0,n+1)nlis[i]=-1;
		Lis=LIS();
		queue<int> Q;
		rep(i,1,n+1)
		{
			if(data[i]==0)
			{
				nlis[0]=0;
				while(!Q.empty())
				{
					int f=Q.front();Q.pop();
					if(nlis[dp1[f]]==-1) nlis[dp1[f]]=data[f];
					else nlis[dp1[f]]=min(nlis[dp1[f]], data[f]);
				}
				if(nlis[Lis]!=-1)update(nlis[Lis]+1,n);
			}
			if(dp1[i]+dp2[i]==Lis+1)
			{
				Q.push(i);
				if(nlis[dp1[i]-1]!=-1)update(nlis[dp1[i]-1]+1,data[i]-1);
			}
		}
		while(!Q.empty())Q.pop();
		ll ans=0;
		rep(i,1,n+1)Ans[i]=Ans[i-1]+xf[i];
		//rep(i,1,n+1)de(Ans[i]);
		rep(i,1,n+1)ans+=1LL*i*(Lis+(Ans[i]!=0));
		cout<<ans<<endl;
	}
	return 0;
}
