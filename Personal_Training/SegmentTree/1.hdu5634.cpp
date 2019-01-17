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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
#define ls rt << 1
#define rs ls | 1
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 303030, M = 10101010;

int n, m;
int a[N];

int cntp, p[M], phi[M], vis[M];

void init() {
    phi[1] = 1;
    rep(i, 2, M) {
        if(!vis[i]) p[cntp++] = i, phi[i] = i - 1;
        for(int j = 0; j < cntp && p[j] * i < M; ++j) {
            vis[p[j] * i] = 1;
            if(i % p[j] == 0) {
                phi[p[j] * i] = phi[i] * p[j];
                break;
            } else {
                phi[p[j] * i] = phi[i] * (p[j] - 1);
            }
        }
    }
}

struct Seg {
    static const int N = ::N << 2;
    int la[N], ma[N], mi[N];
    ll sum[N];
    void up(int rt) {
        ma[rt] = max(ma[ls], ma[rs]);
        mi[rt] = min(mi[ls], mi[rs]);
        sum[rt] = sum[ls] + sum[rs];
    }
    void build(int l, int r, int rt) {
        la[rt] = 0;
        if(l == r) {
            ma[rt] = mi[rt] = sum[rt] = a[l];
            return ;
        }
        int mid = l + r >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        up(rt);
    }
    void gao(int l, int r, int c, int rt) {
        ma[rt] = mi[rt] = la[rt] = c;
        sum[rt] = 1ll * c * (r - l + 1);
    }
    void down(int l, int r, int rt, int mid) {
        if(!la[rt]) return ;
        gao(l, mid, la[rt], ls);
        gao(mid + 1, r, la[rt], rs);
        la[rt] = 0;
    }
    void upd(int L, int R, int c, int l, int r, int rt) {
        if(L <= l && r <= R) {
            gao(l, r, c, rt);
            return ;
        }
        int mid = l + r >> 1;
        down(l, r, rt, mid);
        if(L <= mid) upd(L, R, c, l, mid, ls);
        if(R > mid) upd(L, R, c, mid + 1, r, rs);
        up(rt);
    }
    void upd(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R && ma[rt] == mi[rt]) {
            gao(l, r, phi[ma[rt]], rt);
            return ;
        }
        int mid = l + r >> 1;
        down(l, r, rt, mid);
        if(L <= mid) upd(L, R, l, mid, ls);
        if(R > mid) upd(L, R, mid + 1, r, rs);
        up(rt);
    }
    ll qry(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return sum[rt];
        int mid = l + r >> 1;
        ll ans = 0;
        down(l, r, rt, mid);
        if(L <= mid) ans += qry(L, R, l, mid, ls);
        if(R > mid) ans += qry(L, R, mid + 1, r, rs);
        up(rt);
        return ans;
    }
}seg;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    init();
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 1, n + 1) cin >> a[i];
        seg.build(1, n, 1);
        while(m--) {
            int o, l, r;
            cin >> o >> l >> r;
            if(o == 1) {
                seg.upd(l, r, 1, n, 1);
            } else if(o == 2) {
                int x;
                cin >> x;
                seg.upd(l, r, x, 1, n, 1);
            } else {
                cout << seg.qry(l, r, 1, n, 1) << endl;
            }
        }
    }
    return 0;
}
