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

const int N = 202;

int n, m, tim, n2, n3;
int a[N][N], pp[N<<2];

int find(int pre[], int x) {
    if(x == pre[x]) return x;
    return pre[x] = find(pre, pre[x]);
}

struct Seg {
#define ls rt<<1
#define rs ls|1
    static const int N = ::N << 2;
    int cnt[N][2], pre[N][N], vis[N];
    inline void gao(int l, int rt) {
        rep(i, 0, n) pre[rt][i] = i;
        int p = 0;
        rep(i, 1, n) a[i][l] == a[i-1][l] ? (pre[rt][i] = p) : (p = i);
        cnt[rt][0] = cnt[rt][1] = 0;
        rep(i, 0, n) if(i == find(pre[rt], i)) ++cnt[rt][a[i][l]];
        rep(i, 0, n) pre[rt][i+n] = pre[rt][i];
    }
    inline void up(int rt, int mid) {
        rep(i, 0, n) {
            pre[rt][i] = pre[ls][i];
            pre[rt][i+n] = pre[ls][i+n];
            pre[rt][i+n2] = pre[rs][i] + n2;
            pre[rt][i+n3] = pre[rs][i+n] + n2;
        }
        rep(i, 0, 2) cnt[rt][i] = cnt[ls][i] + cnt[rs][i];
        rep(i, 0, n) if(a[i][mid] == a[i][mid+1] && find(pre[rt], i+n) != find(pre[rt], i+n2)) {
            --cnt[rt][a[i][mid]];
            pre[rt][pre[rt][i+n]] = pre[rt][i+n2];
        }
        ++tim;
        rep(i, 0, n) {
            int t = find(pre[rt], i);
            if(pp[t] != tim) vis[t] = i, pp[t] = tim;
            t = find(pre[rt], i + n3);
            if(pp[t] != tim) vis[t] = i + n, pp[t] = tim;
        }
        rep(i, 0, n) {
            pre[rt][i] = vis[pre[rt][i]];
            pre[rt][i+n] = vis[pre[rt][i+n3]];
        }
    }
    void build(int l, int r, int rt) {
        if(l == r) {
            gao(l, rt);
            return ;
        }
        int mid = l + r >> 1;
        build(l, mid, ls);
        build(mid+1, r, rs);
        up(rt, mid);
    }
    void upd(int p, int l, int r, int rt) {
        if(l == r) {
            gao(p, rt);
            return ;
        }
        int mid = l + r >> 1;
        if(p <= mid) upd(p, l, mid, ls);
        else upd(p, mid+1, r, rs);
        up(rt, mid);
    }
}seg;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        n2 = n + n, n3 = n2 + n;
        rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
        seg.build(0, n-1, 1);
        cin >> m;
        while(m--) {
            int t, x, y;
            cin >> t;
            if(t == 1) {
                cin >> y;
                --y;
                rep(x, 0, n) a[x][y] ^= 1;
            } else {
                cin >> x >> y;
                --x, --y;
                a[x][y] ^= 1;
            }
            seg.upd(y, 0, n-1, 1);
            int r[] = {seg.cnt[1][0], seg.cnt[1][1]};
            #define pre seg.pre[1]
            rep(i, 0, n) if(a[i][0] == a[i][n-1] && find(pre, i) != find(pre, i+n)) {
                --r[a[i][0]];
                pre[pre[i]] = pre[i+n];
            }
            cout << r[0] << " " << r[1] << endl;
        }
    }
    return 0;
}
