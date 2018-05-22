/*
* 定义 size(x) 为以 x 为根的子树节点个数，令 v 为 u 的儿子中 size 值最大的节点，那么 (u,v) 就是重边，其余边为轻边。
* 第一次 dfs 记录所有重边。
* 第二次 dfs 连接重边形成重链，具体过程就是：以根节点为起点，沿着重边向下拓展，拉成重链，不在当前重链上的节点，都以该节点为起点向下重新拉一条重链。
* 剖分完毕后，每条重链相当于一段区间，然后用数据结构去维护，把所有重链首尾相接，放到数据结构上，然后维护整体。
* 两个重要的性质：
*  (1) 轻边 (u,v) 中， size(v)<=size(u/2)
*  (2) 从根到某一点的路径上，不超过 logn 条轻边和不超过 logn 条重路径。
*/
/*
siz[] ：以x为根的子树节点个数
top[] ：当前节点的所在链的顶端节点
son[] ：重儿子
dep[] ：当前节点的深度
fa[] ：当前节点的父亲
tid[] ：树中每个节点剖分后的新编号
*/
void init()
{
	memset(son,-1,sizeof(son));
	tim=0;
}
void dfs1(int u,int pre,int d)
{
    dep[u]=d;
    fa[u]=pre;
    siz[u]=1;
    for(int i=head[u];~i;i=next[i])
    {
        int v=to[i];
        if(v!=pre)
        {
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;
    tid[u]=++tim;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=head[u];~i;i=next[i])
    {
        int v=to[i];
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}
