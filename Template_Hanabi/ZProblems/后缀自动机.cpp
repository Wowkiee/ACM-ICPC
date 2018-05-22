
/* 后缀自动机 */
//最长公共子串
const int N = 250025 * 2;
int L , rt , last;
int l[N] , par[N] , ch[N][26];
void extend(int c){
    int p = last , np = ++L;
    last = np;
    l[np] = l[p] + 1;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = rt;
    else{
        int q = ch[p][c];
        if(l[p] + 1 == l[q]) par[np] = q;
        else{
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq],ch[q],sizeof ch[nq]);
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}

int ans , cur , tmp;
void go(int c){
    if(ch[cur][c])
        cur = ch[cur][c] , ++tmp;
    else{
        while(cur && ch[cur][c] == 0)
            cur = par[cur];
        if(cur) tmp = l[cur] + 1 , cur = ch[cur][c];
        else cur = rt , tmp = 0;
    }
    ans = max(ans , tmp);
}
char s[N] , t[N];
int main(){
    scanf("%s",s + 1);
    scanf("%s",t + 1);
    int len1(strlen(s + 1)) , len2(strlen(t + 1));
    last = rt = ++L;
    rep(i,1,len1+1) extend(s[i] - 'a');
    tmp = ans = 0 ; cur = rt;
    rep(i,1,len2+1) go(t[i] - 'a');
    printf("%d\n",ans);
    return 0;
}
//n串最长公共子串
const int N = 101010 * 2;
int l[N] , par[N] , ch[N][26];
int last , rt , L;
void extend(int c){
    int p = last , np = ++L;
    last = np;
    l[np] = l[p] + 1;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = rt;
    else{
        int q = ch[p][c];
        if(l[p] + 1 == l[q]) par[np] = q;
        else{
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq] , ch[q] , sizeof(ch[q]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}
int cur , step;
int si[N] , ti[N] , b[N] , t[N];
void go(int c){
    if(ch[cur][c])
        cur = ch[cur][c] , ++step;
    else{
        while(cur && ch[cur][c] == 0)
            cur = par[cur];
        if(cur) step = l[cur] + 1 , cur = ch[cur][c];
        else cur = rt , step = 0;
    }
    si[cur] = max(si[cur],step);
}
char s[11][N];
int len[11];
int _;
int main(){
    for(_=0;~scanf("%s",s[_] + 1);++_);
    rep(i,0,_) len[i] = strlen(s[i] + 1);
    rt = last = ++L;
    rep(i,1,len[0]+1) extend(s[0][i] - 'a');
    rep(i,1,L+1) ti[i] = l[i];
    rep(i,1,L+1) ++b[l[i]];
    rep(i,1,len[0]+1) b[i] += b[i-1];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    rep(i,1,_){
        cur = rt , step = 0;
        rep(j,1,len[i]+1) go(s[i][j] - 'a');
        per(j,1,L+1){
            int k = t[j];
            ti[k] = min(ti[k] , si[k]);
            si[par[k]] = max(si[par[k]] , si[k]);
            si[k] = 0;
        }
    }
    int ans = 0;
    rep(i,1,L+1) ans = max(ans,ti[i]);
    printf("%d\n",ans);
    return 0;
}
//S串中长度小于等于l中出现次数最多的串
const int N = 250025 * 2;
int rt , L , last;
int l[N] , par[N] , r[N] , ch[N][26];
void extend(int c){
    int p = last , np = ++L;
    last = np;
    l[np] = l[p] + 1;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = rt;
    else{
        int q = ch[p][c];
        if(l[p] + 1 == l[q])
            par[np] = q;
        else{
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq],ch[q],sizeof ch[nq]);
            par[nq] = par[q];
            par[np] = par[q] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}
char s[N];
int a[N] , b[N] , t[N] , ans[N];
int main(){
    scanf("%s",s + 1);
    int len(strlen(s+1));
    rt = last = ++L;
    rep(i,1,len+1) extend(a[i] = s[i] - 'a');
    rep(i,1,L+1) ++b[l[i]];
    rep(i,1,len+1) b[i] += b[i-1];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    int p = rt;
    rep(i,1,len+1) p = ch[p][a[i]] , ++r[p];
    per(i,1,L+1) r[par[t[i]]] += r[t[i]];
    rep(i,1,L+1) ans[l[i]] = max(ans[l[i]] , r[i]);
    per(i,1,L+1) ans[i] = max(ans[i] , ans[i+1]);
    rep(i,1,len+1) printf("%d\n",ans[i]);
    return 0;
}
// 第K小子串
const int N = 90009 * 2;
int l[N] , par[N] , ch[N][26];
int rt , last , L;
void extend(int c){
    int p = last  , np = ++L;
    last = np;
    l[np] = l[p] + 1;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = rt;
    else{
        int q = ch[p][c];
        if(l[p] + 1 == l[q]) par[np] = q;
        else{
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq] , ch[q] , sizeof(ch[nq]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}
char s[N];
int b[N] , t[N];
int sz[N];
char ans[N];
void Query(int k){
    int len = 0;
    int cur = rt;
    while(k){
        rep(i,0,26) if(ch[cur][i]){
            if(sz[ch[cur][i]] >= k){
                ans[len++] = 'a' + i;
                --k;
                cur = ch[cur][i];
                break;
            }
            else k -= sz[ch[cur][i]];
        }
    }
    ans[len] = 0;
    printf("%s\n",ans);
}
int main(){
    scanf("%s",s);
    int len = strlen(s);
    rt = last = ++L;
    rep(i,0,len) extend(s[i] - 'a');
    rep(i,1,L+1) b[l[i]]++;
    rep(i,0,len) b[i+1] += b[i];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    per(i,1,L+1){
        int k = t[i];
        sz[k] = 1;
        rep(j,0,26) if(ch[k][j])
            sz[k] += sz[ch[k][j]];
    }


    int Q;
    for(scanf("%d",&Q);Q--;){
        int po;
        scanf("%d",&po);
        Query(po);
    }
    return 0;
}
//	S串中不在其他串中出现的子串个数
const int N = 101010 * 2;
int l[N] , par[N] , ch[N][26];
int rt , last , L;
void extend(int c){
    int p = last , np = ++L;
    Set(ch[np],0);
    last = np; l[np] = l[p] + 1;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = rt;
    else{
        int q = ch[p][c];
        if(l[p] + 1 == l[q]) par[np] = q;
        else{
            int nq = ++L;
            Set(ch[nq],0);
            l[nq] = l[p] + 1;
            memcpy(ch[nq] , ch[q] , sizeof(ch[nq]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}
int T,po;
ll ans;
char s[N];
int len;
int cur , step , si[N];
void go(int c){
    if(ch[cur][c])
        cur = ch[cur][c] , ++step;
    else{
        while(cur && ch[cur][c] == 0)
            cur = par[cur];
        if(cur) step = l[cur] + 1 , cur = ch[cur][c];
        else step = 0 , cur = rt;
    }
    si[cur] = max(si[cur] , step);
}
int b[N] , t[N];
void getans(){
    rep(i,0,len+1) b[i] = 0;
    rep(i,1,L+1) b[l[i]]++;
    rep(i,0,len) b[i+1] += b[i];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    per(i,1,L+1){
        int k = t[i];
        si[k] = min(si[k],l[k]);
        si[par[k]] = max(si[par[k]],si[k]);
    }
    rep(i,1,L+1) si[i] = max(si[i] , l[par[i]]);
    ans = 0;
    rep(i,1,L+1) ans += l[i] - si[i];
}
int main(){
    scanf("%d",&T);
    rep(re,1,T+1){
        L = 0; rt = last = ++L;
        Set(ch[rt],0);
        scanf("%d",&po);
        scanf("%s",s);
        len = strlen(s);
        rep(i,0,len) extend(s[i] - 'a');
        rep(i,1,L+1) si[i] = 0;
        rep(cs,0,po){
            scanf("%s",s);
            cur = rt , step = 0;
            for(int i=0;s[i];++i)
                go(s[i] - 'a');
        }
        getans();
        printf("Case %d: %lld\n",re,ans);
    }
    return 0;
}
//	长度不小于k的公共子串个数
const int N = 101010 * 2;
char s[N];
int trans(char c) {
    if ('a' <= c && c <= 'z')
        return c - 'a';
    else return c - 'A' + 26;
}
int b[N], t[N];
int L;
int l[N], par[N], ch[N][52], r[N];
int rt, last;
int len;
void extend(int c) {
    int p = last, np = ++L;
    Set(ch[np], 0);
    last = np, l[np] = l[p] + 1;
    while (p && ch[p][c] == 0)
        ch[p][c] = np, p = par[p];
    if (!p) par[np] = rt;
    else {
        int q = ch[p][c];
        if (l[p] + 1 == l[q]) par[np] = q;
        else {
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq], ch[q], sizeof(ch[nq]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while (p && ch[p][c] == q)
                ch[p][c] = nq, p = par[p];
        }
    }
}
void get_right() {
    rep(i,1,L+1) r[i] = 0;
    int p = rt;
    rep(i,0,len) p = ch[p][trans(s[i])], ++r[p];
    rep(i,0,len+1) b[i] = 0;
    rep(i,1,L+1) b[l[i]]++;
    rep(i,0,len) b[i + 1] += b[i];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    per(i,1,L+1){
        int k = t[i];
        r[par[k]] += r[k];
    }
}
void ini() {
    L = 0;
    rt = last = ++L;
    Set(ch[rt],0);
    scanf("%s", s);
    len = strlen(s);
    rep(i,0,len) extend(trans(s[i]));
    get_right();
}
int up , cur , step;
int g[N];
ll ans[N] , d[N];
void go(int c){
    if(ch[cur][c])
        cur = ch[cur][c] , step++;
    else{
        while(cur && ch[cur][c] == 0)
            cur = par[cur];
        if(cur) step = l[cur] + 1 , cur = ch[cur][c];
        else step = 0 , cur = rt;
    }
    d[l[par[cur]] + 1] += r[cur];
    d[step + 1] -= r[cur];
    g[par[cur]]++;
}
void cal(){
    up = min(up,len);
    per(i,1,L+1){
        int k = t[i];
        d[l[par[k]] + 1] += 1ll * g[k] * r[k];
        d[l[k] + 1] -= 1ll * g[k] * r[k];
        g[par[k]] += g[k];
    }
    rep(i,1,up+1) ans[i] = ans[i-1] + d[i];
    per(i,1,up) ans[i] += ans[i+1];
}

int main() {
    int K;
    while (~scanf("%d", &K)) {
        if (K == 0) return 0;
        ini();
        scanf("%s", s);
        cur = rt , step = 0;
        rep(i,1,L+1) g[i] = 0;
        rep(i,0,len+1) ans[i] = d[i] = 0;
        up = 0;
        for(int i=0;s[i];++i) go(trans(s[i])) , ++up;
        cal();
        printf("%lld\n", ans[K]);
    }
    return 0;
}
//	不重叠出现两次子串个数
const int inf = ~0U>>1;
const int N = 1010 * 2;
int l[N] , par[N] , ch[N][26];
int root , last , L;
void extend(int c){
    int p = last , np = ++L; Set(ch[np],0);
    last = np , l[np] = l[p] + 1;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = root;
    else{
        int q = ch[p][c];
        if(l[p] + 1 == l[q]) par[np] = q;
        else{
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq] , ch[q] , sizeof(ch[nq]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}

char s[N];
int len;
int ans;

int lt[N] , rt[N];
int b[N] , t[N];
void cal(){
    ans = 0;
    rep(i,1,L+1) lt[i] = inf , rt[i] = -inf;
    int p = root;
    rep(i,0,len) p = ch[p][s[i] - 'a'] , lt[p] = rt[p] = i;
    rep(i,0,len+1) b[i] = 0;
    rep(i,1,L+1) b[l[i]]++;
    rep(i,0,len) b[i+1] += b[i];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    per(i,1,L+1){
        int k = t[i];
        ans += min(rt[k] - lt[k] , l[k]) - min(rt[k] - lt[k] , l[par[k]]);
        lt[par[k]] = min(lt[par[k]] , lt[k]);
        rt[par[k]] = max(rt[par[k]] , rt[k]);
    }
}


int main(){
    while(~scanf("%s",s)){
        len = strlen(s);
        if(len == 1 && s[0] == '#')
            return 0;
        root = last = L = 1;
        Set(ch[1],0);
        rep(i,0,len) extend(s[i] - 'a');
        cal();
        printf("%d\n",ans);
    }

    return 0;
}
//	子串变为数字,求数字和
const int N = 101010 * 2;
int par[N] , l[N] , ch[N][10];
int root , last , L;
void extend(int c){
    int p = last , np = ++L; Set(ch[np],0);
    l[np] = l[p] + 1;
    last = np;
    while(p && ch[p][c] == 0)
        ch[p][c] = np , p = par[p];
    if(!p) par[np] = root;
    else{
        int q = ch[p][c];
        if(l[q] == l[p] + 1) par[np] = q;
        else{
            int nq = ++L;
            l[nq] = l[p] + 1;
            memcpy(ch[nq] , ch[q] , sizeof ch[nq]);
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while(p && ch[p][c] == q)
                ch[p][c] = nq , p = par[p];
        }
    }
}

int n;
char s[N];
int len;
int maxlen;

void add_string(){
    scanf("%s",s);
    len = strlen(s);
    maxlen = max(maxlen , len);
    last = root;
    rep(i,0,len){
        if(ch[last][s[i] - '0'] == 0 || l[ch[last][s[i] - '0']] != i + 1)
            extend(s[i] - '0');
        else last = ch[last][s[i] - '0'];
    }
}

const int mod = 2012;
inline void Update(int &x,int y){
    x += y;
    if(x >= mod) x-=mod;
}

int ans;
int b[N] , t[N];
int way[N] , sum[N];
void get_ans(){
    ans = 0;
    rep(i,0,maxlen+1) b[i] = 0;
    rep(i,1,L+1) b[l[i]]++;
    rep(i,0,maxlen) b[i+1] += b[i];
    rep(i,1,L+1) t[b[l[i]]--] = i;
    rep(i,1,L+1) way[i] = sum[i] = 0;
    way[1] = 1;
    rep(i,1,L+1){
        int p = t[i] , q;
        Update(ans,sum[p]);
        rep(c,0,10){
            if(i == 1 && c == 0) continue;
            if(ch[p][c] == 0) continue;
            q = ch[p][c];
            Update(way[q],way[p]);
            Update(sum[q],(sum[p] * 10 + c * way[p]) % mod);
        }
    }
    printf("%d\n",ans);
}

int main(){
    while(~scanf("%d",&n)){
        if(n == 0) return 0;
        root = last = L = 1;
        Set(ch[1],0);
        maxlen = 0;
        rep(i,0,n) add_string();
        get_ans();
    }
    return 0;
}
