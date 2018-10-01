/*
 * [0,L] , 0 is virtual , 1 is rt , init!!
 * 
 * parent 树和 trans 都是 DAG 。 
 * 一个状态 s ，由所有 right 集合是 right(s) 的字符串组成。
 * 这些字符串的长度范围是： [l[par[s]] + 1, l[s]] 。 
 * 状态的 right 集合是它 parent 树中所有孩子 right 集合的并集。 
 * l[par[s]] < l[s] 
 */ 
struct SAM {
    static const int N = ::N << 1, M = 26;
    int par[N], l[N], ne[N][M];
    int rt, last, L;
    void add(int c) {
        int p = last;
        /* 广义后缀自动机 
		if(ne[p][c] && l[ne[p][c]] == l[p] + 1) {
			last = ne[p][c];
			return ;
		}
		*/
		int np = ++L;
        fill(ne[np], ne[np] + M, 0);
        l[np] = l[p] + 1;
        last = np;
        while(p && !ne[p][c]) ne[p][c] = np, p = par[p];
        if(!p) par[np] = rt;
        else{
            int q = ne[p][c];
            if(l[q] == l[p] + 1) par[np] = q;
            else {
                int nq = ++L;
                l[nq] = l[p] + 1;
                copy(ne[q], ne[q] + M, ne[nq]);
                par[nq] = par[q];
                par[q] = par[np] = nq;
                while(p && ne[p][c] == q) ne[p][c] = nq, p = par[p];
            }
        }
    }
    void ini() {
        rt = last = L = 1;
        fill(ne[rt], ne[rt] + M, 0);
        l[0] = -1;
    }
};
