#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt1, cnt2, s1, s2, n, m, x, y, A, B, d, ans1, ans2;
int aa[10], bb[10], an[10], bn[10], T, p, win[19], a[] = {25,25,25,25,15}, len;

void upd(int n){
	d = cnt1 - cnt2; len = n;
	ans1 = cnt1; ans2 = cnt2;
	rep(j, 0, n) an[j] = aa[j], bn[j] = bb[j];
}

void solve(int n) {
	int A, B;
	rep(i, 0, pw(n)) {
		cnt1 = cnt2 = 0;
		A = x; B = y;
		rep(j, 0, n-1) if (pw(j) & i) cnt1 ++; else cnt2 ++;
		
		if (cnt1 >= 3 || cnt2 >= 3) continue;
		if (pw(n-1) & i) cnt1++; else cnt2++;
		if (cnt1 < 3 && cnt2 < 3) continue;
		if (cnt1 - cnt2 <= d) continue;
		s1 = s2 = 0;
		rep(j, 0, n) if (pw(j) & i) win[j] = 1; else win[j] = 0;
		rep(j, 0, n) if (win[j]) s1 += a[j];else s2 += a[j];
		if (A < s1 || B < s2) continue;
		A -= s1; B -= s2;
		rep(j, 0, n) if (win[j]) {
			aa[j] = a[j];
			bb[j] = min(B, a[j] - 2);
			B -= bb[j];
		}else {		
			bb[j] = a[j];
			aa[j] = min(A, a[j] - 2);
			A -= aa[j];
		}
		if (A == 0 && B == 0) {
			upd(n);
		}else {
			if (A > B) {
				if (cnt2 > 0) {
					rep(j, 0, n) if (win[j] == 0) p = j;
					aa[p] += B; bb[p] += B;
					A -= B;
					rep(j, 0, n) if (win[j]) {
						int dd = min(bb[j], A);
						A -= dd;
						bb[j] -= dd;
						bb[p] += dd; aa[p] += dd;
					}
					if (A == 0) upd(n);
				}else {
					if(bb[0] < 23) continue;
					A -= B;
					aa[0] += B; bb[0] += B;
					rep(j, 1, n) {
						int dd = min(bb[j], A);
						A -= dd;
						bb[j] -= dd;
						bb[0] += dd; aa[0] += dd;
					}
					if (A == 0) upd(n);
				}
			}else if (B > A){
				if (cnt1 > 0) {
					rep(j, 0, n) if (win[j] == 1) p = j;
					aa[p] += A; bb[p] += A;
					B -= A;
					rep(j, 0, n) if (win[j] == 0) {
						int dd = min(aa[j], B);
						B -= dd;
						aa[j] -= dd;
						bb[p] += dd; aa[p] += dd;
					}
					if (B == 0) upd(n);
				}else {
					if(aa[0] < 23) continue;
					B -= A;
					aa[0] += A; bb[0] += A;

					rep(j, 1,  n) {
						int dd = min(aa[j], B);
						B -= dd;
						aa[j] -= dd;
						bb[0] += dd; aa[0] += dd;
					}
					if (B == 0) upd(n);
				}
			}else {
				aa[0] += A; bb[0] += A;
				upd(n);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> x >> y;
		ans1 = ans2 = -1;
		d = -10;
		solve(3);
		solve(4);
		solve(5);
		if (ans1 == -1) cout << "Impossible" << endl;
		else {
			cout << ans1 << ":" << ans2 << endl;
			rep(i, 0, len) {
				cout << an[i] << ":" << bn[i];
				if (i == len - 1) cout << endl; else cout << " "; 
			}
		}
	}
	return 0;
}
