// init!! , go[0] is virtual , add 0 in the end of string
const int N = 101010 , C = 27 , inf = ~0U>>1;
int pos,S[N];
struct SuffixTree{
    struct Node{
        int l , r , du;
        Node *fail, *go[C], *fa;
        Node(int l=-1,int r=inf) : l(l),r(r){
            fail = fa = NULL; du = 0;
            memset(go,0,sizeof(go));
        }
        Node* link(Node*t){int c=S[t->l];du+=!go[c];go[c]=t;t->fa=this;return t;}
        int len(){return min(r,pos+1)-l;}
    }pool[N<<2],*pl,*rt,*p,*pre;
    int L,R;
    ll size; queue<Node*> leaves;
    void ini(){
        pos=-1;
        pl=pool;rt=p=new(pl++) Node(-1,-1);pre=NULL;
        L=R=0;
        size = 0; while(sz(leaves)) leaves.pop();
    }
    void jump(Node*u){
        if(pre) pre->fail = u;
        pre = u;
    }
    bool walk(Node*u){
        int len=u->len();
        if(R >= len) return L+=len,R-=len,p=u,true;
        return false;
    }
    void extend(int c){
        S[++pos] = c; pre = NULL;
        for(;;){
            int ch = S[L = R ? L : pos];
            if(p->go[ch]){
                Node*q = p->go[ch];
                if(walk(q)) continue;
                if(S[q->l + R] == c){ ++R; jump(p); break; }
                Node *s = new(pl++) Node(q->l,q->l+R);
                leaves.push(s->link(new(pl++) Node(pos)));
                q->l += R; p->link(s)->link(q);
                jump(s);
            }
            else leaves.push(p->link(new(pl++) Node(pos))) , jump(p);
            if(p == rt && !R) break;
            else if(p == rt) L = pos - --R;
            else p = p->fail ? p->fail : rt;
        }
        size += sz(leaves);
    }
    void eraseUp(Node*&u){
        size -= u->len();
        u->fa->go[S[u->l]] = NULL;
        --((u=u->fa)->du);
    }
    void erase(){
        Node*u = leaves.front(); leaves.pop();
        while(!u->du && u != p) eraseUp(u);
        if(u == p){
            if(!p->du && !R){
                L = pos - (R = p->len()) + 1;
                p = p->fa; eraseUp(u);
            }
            if(R && !p->go[S[L]]){
                Node *leaf = new(pl++) Node(L);
                leaves.push(p->link(leaf));
                size += leaf->len();
                if(p == rt && R) L = pos - --R + 1;
                else p = p->fail ? p->fail : rt;
            }
        }
    }
    int stop , ord[N<<1] , rk[N];
    void dfs(Node*u){
        ord[u - pool] = stop++;
        rep(i,0,C) if(u->go[i]) dfs(u->go[i]);
    }
    void getrk(){
        stop = 0;
        dfs(rt);
        for(int i=0;sz(leaves);++i)
            rk[i] = ord[leaves.front() - pool] , leaves.pop();
    }
};
