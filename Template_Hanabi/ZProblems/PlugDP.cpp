/* 插头dp */
// 多回路
int g[12][12];
ll dp[12][12][1<<12];

#define b2(x) (1<<(x))
ll work(){
    scanf("%d%d",&n,&m);
    rep(i,1,n+1) rep(j,1,m+1) scanf("%d",&g[i][j]);
    rep(i,0,b2(m+1)) dp[0][m][i] = 0;
    dp[0][m][0] = 1;
    rep(i,1,n+1){
        rep(s,0,b2(m)) dp[i][0][s<<1] = dp[i-1][m][s];
        rep(j,1,m+1) rep(s,0,b2(m+1)){
            int p = 1<<j-1 , q = 1<<j;
            bool x = p&s , y = q&s;
            if(g[i][j]){
                dp[i][j][s] = dp[i][j-1][s^p^q];
                if(x^y) dp[i][j][s] += dp[i][j-1][s];
            }
            else{
                if(!(x||y)) dp[i][j][s] = dp[i][j-1][s];
                else dp[i][j][s] = 0;
            }
        }
    }
    return dp[n][m][0];
}

int main(){
    scanf("%d",&T);
    rep(i,1,T+1) printf("Case %d: There are %I64d ways to eat the trees.\n",i,work());
    return 0;
}
//	单回路
int n , m , end_n , end_m;
int g[15][15];
const int HASH = (1<<14) - 1 , NODE = 243 * 243 * 3;
int h[HASH + 1];
struct hashmap{
    int ne[NODE] , s[NODE] , e;
    ll sum[NODE];
    void ins(int p,ll d){
        int c = p&HASH;
        for(int k=h[c];~k;k=ne[k])
            if(s[k] == p){
                sum[k] += d;
                return;
            }
        s[e] = p , sum[e] = d;
        ne[e] = h[c];h[c] = e++;
    }
    void ini(){
        set(h,-1);
        e = 0;
    }
}hm[2];
int c;

ll work(){
    char s[20];
    rep(i,1,n+1){
        scanf("%s",s+1);
        rep(j,1,m+1) if(g[i][j] = s[j] == '.') end_n = i , end_m = j;
    }
    int t2[20];
    rep(i,0,20) t2[i] = i+i;
    c = 0;hm[c].ini();hm[c].ins(0,1);
    rep(i,1,n+1){
        rep(k,0,hm[c].e) hm[c].s[k] <<= 2;
        rep(j,1,m+1){
            c ^= 1;
            hm[c].ini();
            rep(k,0,hm[c^1].e){
                int s = hm[c^1].s[k];
                ll sum = hm[c^1].sum[k];
                if(s>>t2[m+1]) continue;
                int p = (s>>t2[j-1]) & 3 , q = (s>>t2[j]) & 3;
                if(g[i][j] == 0){
                    if(p == 0 && q == 0) hm[c].ins( s , sum );
                }
                else{
                    if(p == 0 && q == 0){
                        hm[c].ins( s ^ (1<<t2[j-1]) ^ (2<<t2[j]) , sum);
                    }
                    else if(p == 0 || q == 0){
                        hm[c].ins( s , sum );
                        hm[c].ins( s ^ ((p|q)<<t2[j-1]) ^ ((p|q)<<t2[j]) , sum );
                    }
                    else if(p == q){
                        int cnt = 1;
                        for(int k = p == 1 ?j+1:j-2;;p == 1 ?++k:--k){
                            int t = s>>t2[k]&3;
                            if(t == p) ++cnt;
                            if(t == (p^3)) --cnt;
                            if(cnt == 0){
                                hm[c].ins( s ^ (3<<t2[k]) ^ (p<<t2[j]) ^ (p<<t2[j-1]) , sum );
                                break;
                            }
                        }
                    }
                    else if(p == 1 && q == 2){
                        if(i == end_n && j == end_m)
                            hm[c].ins( s ^ (1<<t2[j-1]) ^ (2<<t2[j]) , sum);
                    }
                    else if(p == 2 && q == 1){
                        hm[c].ins( s ^ (2<<t2[j-1]) ^ (1<<t2[j]) , sum );
                    }
                }
            }
        }
    }
    rep(i,0,hm[c].e) if(hm[c].s[i] == 0) return hm[c].sum[i];
    return 0;
}

int main(){
    while(~scanf("%d%d",&n,&m)) printf("%I64d\n",work());
    return 0;
}
//	O->必选 X->障碍 *->可选
const int N = 20202<<1 , M = N << 1;
int T , n , m , end_n , end_m;
const int HASH = (1<<18)-1 , NODE = 243 * 243 * 3;
int h[HASH];
struct hashmap{
    int ne[NODE] , s[NODE] , e;
    ll sum[NODE];
    void ins(int val,ll d){
        int c = val & HASH;
        for(int k=h[c];~k;k=ne[k])
            if(s[k] == val){
                sum[k] += d;
                return;
            }
        s[e] = val , sum[e] = d;
        ne[e] = h[c];h[c] = e++;
    }
    void ini(){
        set(h,-1);
        e = 0;
    }
}hm[2];
char g[15][15];
int c;

ll work(){
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        scanf("%s",g[i]+1);
        rep(j,1,m+1) if(g[i][j] == 'O')
            end_n = i , end_m = j;
    }
    ll ans = 0;
    bool lst = false;
    hm[c].ini();hm[c].ins(0,1);
    int t2[20];
    rep(i,0,20) t2[i] = i+i;
    rep(i,1,n+1){
        rep(k,0,hm[c].e) hm[c].s[k] <<= 2;
        rep(j,1,m+1){
            if(i == end_n && j == end_m) lst = true;
            c ^= 1;
            hm[c].ini();
            rep(k,0,hm[c^1].e){
                int s = hm[c^1].s[k];
                ll sum = hm[c^1].sum[k];
                if(s>>t2[m+1]) continue;
                int p = s>>t2[j-1]&3 , q = s>>t2[j]&3;
                if(g[i][j] == 'X'){
                    if(p == 0 && q == 0) hm[c].ins(s , sum);
                }
                else if(p == 0 && q == 0) hm[c].ins(s ^ 1<<t2[j-1] ^ 2<<t2[j] , sum);
                else if(p == 0 || q == 0) hm[c].ins(s , sum) , hm[c].ins(s ^ (p|q)<<t2[j-1] ^ (p|q)<<t2[j] , sum);
                else if(p == q){
                    int cnt = 1;
                    for(int k = p==1 ? j+1:j-2;;p==1?++k:--k){
                        int t = s>>t2[k]&3;
                        if(t == p) ++cnt;
                        if(t == (p^3)) --cnt;
                        if(cnt == 0){
                            hm[c].ins(s ^ 3<<t2[k] ^ p<<t2[j-1] ^ p<<t2[j] , sum);
                            break;
                        }
                    }
                }
                else if(p == 2 && q == 1) hm[c].ins(s ^ p<<t2[j-1] ^ q<<t2[j] , sum);
                else if(p == 1 && q == 2){
                    if(lst) if((s ^ p<<t2[j-1] ^ q<<t2[j]) == 0)
                        ans += sum;
                }
                if(g[i][j] == '*') if(p == 0 && q == 0) hm[c].ins(s , sum);
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d",&T);
    rep(i,1,T+1) printf("Case %d: %I64d\n",i,work());
    return 0;
}
//	最小花费回路
const int N = 20202<<1 , M = N << 1;
const int HASH = 10007 , NODE = 243 * 243 * 3;
int h[HASH];
struct hashmap{
    int ne[NODE] , s[NODE] , e;
    int mi[NODE];
    void ins(int val,int t){
        int c = val % HASH;
        for(int k=h[c];~k;k=ne[k])
            if(s[k] == val){
                mi[k] = min(mi[k] , t);
                return;
            }
        s[e] = val , mi[e] = t;
        ne[e] = h[c];h[c] = e++;
    }
    void ini(){
        set(h,-1);
        e = 0;
    }
}hm[2];
int c;
char g[30][30];
int T , n , m;

int work(){
    scanf("%d%d",&n,&m);
    gets(g[0]);
    rep(i,1,2*n+2) gets(g[i] + 1);
    int w2[20];
    rep(i,0,20) w2[i] = i+i;
    hm[c].ini();hm[c].ins(0,0);
    rep(i,1,n+1){
        rep(k,0,hm[c].e) hm[c].s[k] <<= 2;
        rep(j,1,m+1){
            c ^= 1;
            hm[c].ini();
            rep(k,0,hm[c^1].e){
                int s = hm[c^1].s[k];
                int d = hm[c^1].mi[k];
                if(s>>w2[m+1]) continue;
                int p = s>>w2[j-1]&3 , q = s>>w2[j]&3;
                int up = g[i*2-1][j*2] - '0', left = g[i*2][j*2-1] - '0';
                if(p == 0 && q == 0) hm[c].ins(s ^ 1<<w2[j-1] ^ 2<<w2[j] , d);
                else if(p == 0 || q == 0) hm[c].ins(s , d + (p ? left : up)) ,
                    hm[c].ins(s ^ (p|q)<<w2[j-1] ^ (p|q)<<w2[j], d + (p ? left : up));
                else if(p == q){
                    int cnt = 1;
                    for(int k=p==1?j+1:j-2;;p==1?++k:--k){
                        int t = s>>w2[k]&3;
                        if(t == p) ++cnt;
                        if(t == (p^3)) --cnt;
                        if(cnt == 0){
                            hm[c].ins(s ^ 3<<w2[k] ^ p<<w2[j-1] ^ q<<w2[j] , d + left + up);
                            break;
                        }
                    }
                }
                else if(p == 2 && q == 1) hm[c].ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d + left + up);
                else if(p == 1 && q == 2) if(i == n && j == m) hm[c].ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d + left + up);
            }
        }
    }
    rep(i,0,hm[c].e) if(hm[c].s[i] == 0) return hm[c].mi[i];
    return 0;
}

int main(){
    scanf("%d",&T);
    rep(i,1,T+1) printf("%d\n",work());
    return 0;
}
//	左上到右下简单路径
const int N = 20202<<1 , M = N << 1;
const int HASH = 10007 , NODE = 243 * 243 * 3;
int h[HASH];
struct hashmap{
    int ne[NODE] , s[NODE] , e;
    int mi[NODE];
    void ins(int val,int t){
        int c = val % HASH;
        for(int k=h[c];~k;k=ne[k])
            if(s[k] == val){
                mi[k] = max(mi[k] , t);
                return;
            }
        s[e] = val , mi[e] = t;
        ne[e] = h[c];h[c] = e++;
    }
    void ini(){
        set(h,-1);
        e = 0;
    }
}hm[2];
int c;
int g[15][15];
bool can[15][15];
int T , n , m;

int work(){
    n += 2 , m += 2;
    set(g,0);set(can,true);
    rep(j,2,m) can[2][j] = false;
    rep(i,2,n) can[i][m-1] = false;
    rep(i,3,n+1) rep(j,1,m-1) scanf("%d",&g[i][j]);
    hm[c].ini(); hm[c].ins(0,0);
    int w2[20]; rep(i,0,20) w2[i] = i+i;
    rep(i,1,n+1){
        rep(k,0,hm[c].e) hm[c].s[k] <<= 2;
        rep(j,1,m+1){
            c ^= 1;
            hm[c].ini();
            rep(k,0,hm[c^1].e){
                int s = hm[c^1].s[k];
                int d = hm[c^1].mi[k];
                if(s>>w2[m+1]) continue;
                int p = s>>w2[j-1]&3 , q = s>>w2[j]&3;
                if(can[i][j] == 0){
                    if(p == 0 && q == 0)
                        hm[c].ins(s , d);
                }
                else if(p == 0 && q == 0){
                    if(i != 1 || j != 1) hm[c].ins(s , d);
                    hm[c].ins(s ^ 1<<w2[j-1] ^ 2<<w2[j] , d + g[i][j]);
                }
                else if(p == 0 || q == 0) hm[c].ins(s , d + g[i][j]) ,
                    hm[c].ins(s ^ (p|q)<<w2[j-1] ^ (p|q)<<w2[j] , d + g[i][j]);
                else if(p == q){
                    for(int cnt=1,k=p==1?j+1:j-2;;p==1?++k:--k){
                        int t = s>>w2[k]&3;
                        if(t == p) ++cnt;
                        if(t == (p^3)) --cnt;
                        if(cnt == 0){
                            hm[c].ins(s ^ 3<<w2[k] ^ p<<w2[j-1] ^ q<<w2[j] , d + g[i][j]);
                            break;
                        }
                    }
                }
                else if(p == 2 && q == 1) hm[c].ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d + g[i][j]);
                else if(p == 1 && q == 2) if(i == n && j == m) hm[c].ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d + g[i][j]);
            }
        }
    }
    rep(i,0,hm[c].e) if(hm[c].s[i] == 0) return hm[c].mi[i];
    return 0;
}

int main(){
    int _ = 0;
    while(~scanf("%d%d",&n,&m)) printf("Case %d: %d\n",++_,work());
    return 0;
}
//	0->空 1->障碍 把22,33不相交连起来最短
const int N = 20202<<1 , M = N << 1;
const int HASH = 10007 , NODE = 243 * 243 * 3;
int n , m , en , em;
int g[15][15];
int h[HASH];
struct hashmap{
    int mi[NODE] , ne[NODE] , e;
    int s[NODE];
    void ins(int x,int d){
        int c = x % HASH;
        for(int k=h[c];~k;k=ne[k])
            if(s[k] == x){
                mi[k] = min(mi[k] , d);
                return;
            }
        s[e] = x , mi[e] = d;
        ne[e] = h[c] ; h[c] = e++;
    }
    void ini(){
        set(h,-1);
        e = 0;
    }
}hm[2];
int c;

int work(){
    rep(i,1,n+1) rep(j,1,m+1){
        scanf("%d",&g[i][j]);
        if(g[i][j] >= 2) en = i , em = j;
    }
    hm[c].ini();hm[c].ins(0,0);
    int e3[20];
    rep(i,0,20) e3[i] = i+i+i;
    int ans = inf;
    rep(i,1,n+1){
        rep(k,0,hm[c].e){
            if(hm[c].s[k]>>e3[m]) hm[c].mi[k] = -1;
            else hm[c].s[k] <<= 3;
        }
        rep(j,1,m+1){
            c ^= 1;
            hm[c].ini();
            rep(k,0,hm[c^1].e){
                int s = hm[c^1].s[k];
                int d = hm[c^1].mi[k];
                if(s>>e3[m+1] || d < 0 || d >= ans) continue;
                if(s == 0 && (i >= en && j >= em || i > en))
                    ans = min(ans , d);
                int p = s>>e3[j-1]&7 , q = s>>e3[j]&7;
                if(g[i][j] == 1){
                    if(p == 0 && q == 0)
                        hm[c].ins(s , d);
                }
                else if(g[i][j] == 0){
                    if(p == 0 && q == 0) hm[c].ins(s , d) ,
                        hm[c].ins(s ^ 1<<e3[j-1] ^ 2<<e3[j] , d + 1);
                    else if(p == 0 || q == 0) hm[c].ins(s , d + 1) ,
                        hm[c].ins(s ^ (p|q)<<e3[j-1] ^ (p|q)<<e3[j] , d + 1);
                    else if(p == 2 && q == 1 || p == q && p >= 3)
                        hm[c].ins(s ^ p<<e3[j-1] ^ q<<e3[j] , d + 1);
                    else if(p == 1 && q == 2) continue;
                    else if(min(p,q) <= 2){
                        int a = min(p,q) , b = p^q^a;
                        for(int cnt=1,k=a==1?j+1:j-2;;a==1?++k:--k){
                            int t = s>>e3[k]&7;
                            if(t == a) ++cnt;
                            if(t == (3^a)) --cnt;
                            if(cnt == 0){
                                hm[c].ins(s ^ (3^a^b)<<e3[k] ^ p<<e3[j-1] ^ q<<e3[j] , d + 1);
                                break;
                            }
                        }
                    }
                }
                else if(g[i][j] >= 2){
                    int o = g[i][j] + 1;
                    if(p == 0 && q == 0) hm[c].ins(s ^ o<<e3[j-1], d + 1) ,
                        hm[c].ins(s ^ o<<e3[j] , d + 1);
                    else if(p == 0 || q == 0){
                        if(max(p,q) == o) hm[c].ins(s ^ p<<e3[j-1] ^ q<<e3[j] , d + 1);
                        else if(max(p,q) <= 2){
                            int a = max(p,q) , b = o;
                            for(int cnt=1,k=a==1?j+1:j-2;;a==1?++k:--k){
                                int t = s>>e3[k]&7;
                                if(t == a) ++cnt;
                                if(t == (3^a)) --cnt;
                                if(cnt == 0){
                                    hm[c].ins(s ^ (3^a^b)<<e3[k] ^ p<<e3[j-1] ^ q<<e3[j] , d + 1);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    rep(i,0,hm[c].e) if(hm[c].s[i] == 0){
        ans = min(hm[c].mi[i] , ans);
        break;
    }
    return ans == inf ? 0 : ans-2;
}


int main(){
    while(~scanf("%d%d",&n,&m)){
        if(!(n||m)) break;
        printf("%d\n",work());
    }
    return 0;
}
//	六边形多回路
const int N = 1<<17;
struct hashmap{
    ll sum[N];
    int q[N],e;
    void ins(int x,ll d){
        if(sum[x] == 0) q[e++] = x;
        sum[x] += d;
    }
    void ini(){
        rep(i,0,e) sum[q[i]] = 0;
        e = 0;
    }
}hm[2];int c;
int COL = 8;
int n , m;
int g[15][15];

void Trans(int y,bool f){
    c ^= 1;
    hm[c].ini();
    rep(k,0,hm[c^1].e){
        int s = hm[c^1].q[k] , ns=s;
        ll d = hm[c^1].sum[s];
        if(d == 0) continue;

        int cnt = 0;
        rep(j,0,3) if(s>>(y+y-j)&1) ns ^= 1<<(y+y-j) , ++cnt;
        if(f){
            if(cnt == 0) hm[c].ins(s , d);
        }
        else{
            if(cnt == 0) rep(i,0,2) rep(j,i+1,3) hm[c].ins(ns ^ 1<<(y+y-i) ^ 1<<(y+y-j) , d);
            if(cnt == 1) rep(i,0,3) hm[c].ins(ns ^ 1<<(y+y-i) , d);
            if(cnt == 2) hm[c].ins(ns , d);
        }
    }
}

ll work(){
    set(g,0);
    rep(i,0,m){
        char s[3];
        scanf("%s",s);
        g[s[0] - 'A' + 1][s[1] - 'A' + 1] = 1;
    }
    hm[c].ini();hm[c].ins(0,1);
    rep(i,1,n+1){
        rep(k,0,hm[c].e){
            int s = hm[c].q[k];
            if((s&1) || (s>>(COL+COL))) hm[c].sum[s] = 0;
        }
        for(int j=2;j<=COL;j+=2) Trans(j,g[i][j]);
        for(int j=1;j<=COL;j+=2) Trans(j,g[i][j]);
    }
    rep(i,0,hm[c].e) if(hm[c].q[i] == 0) return hm[c].sum[0];
    return 0;
}

int main(){
    while(~scanf("%d%d",&n,&m)) printf("%lld\n",work());
    return 0;
}
//	左上到左下,矩阵加速
const int N = 1<<16;
int v[N] , q[N] , _;
int w2[30];
int n , m;
struct hashmap{
    int v[N] , q[N] , e;
    void ins(int x,int d){
        if(v[x] == 0) q[e++] = x;
        v[x] += d;
    }
    void ini(){
        rep(i,0,e) v[q[i]] = 0;
        e = 0;
    }
}hm[2];int c;
struct MM{
    ll a[120][120];
    MM(ll x = 0){
        rep(i,0,_) rep(j,0,_) a[i][j] = i == j ? x : 0;
    }
    MM operator * (const MM& b){
        MM ret(0);
        rep(i,0,_) rep(j,0,_) rep(k,0,_) ret.a[i][j] += a[i][k] * b.a[k][j];
        rep(i,0,_) rep(j,0,_) ret.a[i][j] %= mod;
        return ret;
    }
    MM operator ^ (int r){
        MM ret(1) , sp = *this;
        while(r){
            if(r&1) ret = ret * sp;
            sp = sp * sp;
            r>>=1;
        }
        return ret;
    }
    void out(){
        rep(i,0,_) rep(j,0,_) printf("%I64d%c",a[i][j]," \n"[j==_-1]);
    }
}mm;

void Trans(int j,bool f){
    c ^= 1;
    hm[c].ini();
    rep(k,0,hm[c^1].e){
        int s = hm[c^1].q[k];
        int d = hm[c^1].v[s];
        int p = s>>w2[j-1]&3 , q = s>>w2[j]&3;
        if(p == 0 && q == 0) hm[c].ins(s ^ 1<<w2[j-1] ^ 2<<w2[j] , d);
        else if(p == 0 || q == 0) hm[c].ins(s , d) ,
            hm[c].ins(s ^ (p|q)<<w2[j-1] ^ (p|q)<<w2[j] , d);
        else if(p == 2 && q == 1) hm[c].ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d);
        else if(p == 1 && q == 2 && f) hm[c].ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d);
        else if(p == q){
            for(int cnt=1,k=p==1?j+1:j-2;;p==1?++k:--k){
                int t = s>>w2[k]&3;
                if(t == p) ++cnt;
                if(t == (p^3)) --cnt;
                if(cnt == 0){
                    hm[c].ins(s ^ 3<<w2[k] ^ p<<w2[j-1] ^ q<<w2[j], d);
                    break;
                }
            }
        }
    }
}
void dfs(int fr){
    hm[c].ini();hm[c].ins(fr,1);
    rep(j,1,m+1) Trans(j,0);
    rep(i,0,hm[c].e){
        int s = hm[c].q[i];
        int d = hm[c].v[s];
        if(s>>w2[m]) continue;
        s <<= 2;
        if(v[s] == -1) v[s] = _ , q[_++] = s;
        mm.a[v[fr]][v[s]] = d;
    }
}

void work(){
    if((n&1) && !(m&1)){
        puts("Impossible");
        return;
    }
    swap(n,m);
    rep(i,0,30) w2[i] = i+i;
    set(v,-1); _ = 0; v[1<<w2[1] ^ 2<<w2[m]] = 0;
    q[_++] = 1<<w2[1] ^ 2<<w2[m];
    set(mm.a,0);
    rep(i,0,_) dfs(q[i]);
    mm = mm ^ (n-1);
    hm[c].ini();
    rep(i,0,_) if(mm.a[0][i]) hm[c].ins(q[i] , mm.a[0][i]);
    rep(i,1,m) Trans(i,0);
    Trans(m,1);
    rep(i,0,hm[c].e) if(hm[c].q[i] == 0){
        printf("%d\n",hm[c].v[0] % mod);
        return;
    }
    printf("%d\n",0);
}

int main(){
    while(~scanf("%d%d",&n,&m)) work();
    return 0;
}
//	最大路径
const int N = 1<<18;
struct hashmap{
    int v[N] , q[N] , e;
    void ins(int x,int d){
        if(v[x] == -1) q[e++] = x;
        v[x] = max(v[x],d);
    }
    void ini(){
        rep(i,0,e) v[q[i]] = -1;
        e = 0;
    }
}hm[2];int c;
int T , n , m;
int g[10][10] , w2[30];
int ans;
inline void ins(int x,int y){
    hm[c].ins(x,y);
}

void Trans(int j,int dd){
    c ^= 1;
    hm[c].ini();
    rep(k,0,hm[c^1].e){
        int s = hm[c^1].q[k];
        int d = hm[c^1].v[s];
        int p = s>>w2[j-1]&3 , q = s>>w2[j]&3;
        if(dd == 0){
            if(p == 0 && q == 0) ins(s , d);
            continue;
        }
        if(p == 0 && q == 0) ins(s , d) ,
            ins(s ^ 1<<w2[j-1] ^ 2<<w2[j] , d + dd) ,
                ins(s ^ 3<<w2[j-1] , d + dd) ,
                ins(s ^ 3<<w2[j] , d + dd);
        else if(p == 0 || q == 0){
            ins(s , d + dd) ,
                ins(s ^ (p|q)<<w2[j-1] ^ (p|q)<<w2[j] , d + dd);
            int a = max(p,q);
            if(a == 3){
                if(!(s ^ p<<w2[j-1] ^ q<<w2[j])) ans = max(ans , d + dd);
            }
            else{
                for(int cnt=1,k=a==1?j+1:j-2;;a==1?++k:--k){
                    int t = s>>w2[k]&3;
                    if(t == a) ++cnt;
                    if(t == (a^3)) --cnt;
                    if(cnt == 0){
                        ins(s ^ a<<w2[k] ^ p<<w2[j-1] ^ q<<w2[j] , d + dd);
                        break;
                    }
                }
            }
        }
        else if(p == 2 && q == 1) ins(s ^ p<<w2[j-1] ^ q<<w2[j] , d + dd);
        else if(p == 1 && q == 2) continue;
        else if(min(p,q) <= 2){
            int a = min(p,q);
            for(int cnt=1,k=a==1?j+1:j-2;;a==1?++k:--k){
                int t = s>>w2[k]&3;
                if(t == a) ++cnt;
                if(t == (a^3)) --cnt;
                if(cnt == 0){
                    ins(s ^ (3^p^q)<<w2[k] ^ p<<w2[j-1] ^ q<<w2[j] , d + dd);
                    break;
                }
            }
        }
        else{
            if(!(s ^ p<<w2[j-1] ^ q<<w2[j])) ans = max(ans , d + dd);
        }
    }
}

int work(){
    scanf("%d%d",&n,&m);
    ans = 0;
    rep(i,1,n+1) rep(j,1,m+1) scanf("%d",&g[i][j]) , ans = max(ans , g[i][j]);
    rep(i,0,30) w2[i] = i+i;
    hm[c].ini();hm[c].ins(0,0);
    rep(i,1,n+1){
        c ^= 1;
        hm[c].ini();
        rep(k,0,hm[c^1].e){
            int s = hm[c^1].q[k];
            if(!(s>>w2[m])) ins(s<<2,hm[c^1].v[s]);
        }
        rep(j,1,m+1) Trans(j,g[i][j]);
    }
    return ans;
}

int main(){
    scanf("%d",&T);
    set(hm[0].v,-1);set(hm[1].v,-1);
    rep(i,0,T) printf("%d\n",work());
    return 0;
}
//	K回路无环套环
const int N = 50505 , M = N<<1;
inline void pp(int &x,int d){
    x += d;if(x >= mod) x -= mod;
}
int T,n,m,K;
char g[15][15];
const int HASH = 10007 , NODE = 15511;
struct hashmap{
    int h[HASH] , ne[NODE] , s[NODE] , sum[NODE] , e;
    void ins(int x,int d){
        int c = x % HASH;
        for(int k=h[c];~k;k=ne[k])
            if(s[k] == x){
                pp(sum[k],d);
                return;
            }
        s[e] = x , sum[e] = d;
        ne[e] = h[c] , h[c] = e++;
    }
    void ini(){
        set(h,-1);
        e = 0;
    }
};
hashmap hm[2][37];int c;
void wk(){
    scanf("%d%d%d",&n,&m,&K);
    rep(i,1,n+1) scanf("%s",g[i]+1);
    int ex(-1) , ey(-1);
    rep(i,1,n+1) rep(j,1,m+1){
        if(g[i][j] == '.') ex = i , ey = j;
    }
    if(ex == -1 || K == 0){
        if(ex == -1 && K == 0) printf("1\n");
        else printf("0\n");
        return ;
    }
    int w2[20]; rep(i,0,20) w2[i] = i+i;
    rep(i,0,K) hm[c][i].ini();
    hm[c][0].ins(0,1);
    int ans = 0;
    rep(i,1,n+1){
        rep(j,0,K) rep(k,0,hm[c][j].e){
            if(hm[c][j].s[k] >> w2[m]) hm[c][j].sum[k] = 0;
            else hm[c][j].s[k] <<= 2;
        }
        if(i > ex) break;
        rep(j,1,m+1){
            if(i == ex && j > ey) break;
            c ^= 1;
            rep(o,0,K) hm[c][o].ini();
            rep(o,0,K){
                rep(k,0,hm[c^1][o].e){
                    int s = hm[c^1][o].s[k];
                    int d = hm[c^1][o].sum[k];
                    if(d == 0) continue;
                    //					cout << o << "  " << i << "  " << j << "  " << bitset<10>(s) << "  " << d << endl;
                    int p = s>>w2[j-1]&3 , q = s>>w2[j]&3 , ns = s^p<<w2[j-1]^q<<w2[j];
                    if(g[i][j] == '*'){
                        if(p == 0 && q == 0) hm[c][o].ins(s , d);
                    }
                    else if(p == 0 && q == 0) hm[c][o].ins(s ^ 1<<w2[j-1] ^ 2<<w2[j] , d);
                    else if(p == 0 || q == 0) hm[c][o].ins(s ^ (p|q)<<w2[j-1] ^ (p|q)<<w2[j] , d) ,
                        hm[c][o].ins(s , d);
                    else if(p == 2 && q == 1) hm[c][o].ins(ns, d);
                    else if(p == 1 && q == 2){
                        int cnt = 0;
                        rep(k,0,j-1) if(s>>w2[k]&3) ++cnt;
                        if(cnt&1) continue;
                        if(o == K-1){
                            if(ns == 0 && i == ex && j == ey) pp(ans,d);
                        }
                        else hm[c][o+1].ins(ns , d);
                    }
                    else if(p == q){
                        for(int cnt=1,k=p==1?j+1:j-2;;p==1?++k:--k){
                            int t = s>>w2[k]&3;
                            if(t == p) ++cnt;
                            if(t == (p^3)) --cnt;
                            if(cnt == 0){
                                hm[c][o].ins(ns ^ 3<<w2[k], d);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&T);
    rep(i,0,T) wk();
    return 0;
}
