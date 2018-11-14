const int N=510,Q=201000;

char s1[N],s2[N];
int q[Q],pre[N][N][2],pc[N][N][2],d[N][N][2],hd,tl;

struct node {
	vector<node*> nxt;
	vector<int> ch;
	void link(node *p,int c) { nxt.pb(p);ch.pb(c);}
}nd1[N],nd2[N],*Cur;

struct nfa { node *st,*ed;} Nd1[N],Nd2[N],*cur;

inline void upd(int a,int b,int &_a,int &_b) { if (a<_a) _a=a,_b=b;}
nfa *solve(int l,int r,char *s) {
	nfa *p=cur++;p->st=Cur++;p->ed=Cur++;
	if (l==r) p->st->link(p->ed,s[l]-'a');
	else {
		int pro=0,mp=inf,mw=-1;
		per(i,l,r+1) {
			if (s[i]=='(') pro-=3;
			if (s[i]==')') pro+=3;
			else if (s[i]=='*') upd(pro+2,i,mp,mw);
			else if (s[i]=='|') upd(pro,i,mp,mw);
			else if (i!=l&&s[i-1]!='(') upd(pro+1,i,mp,mw);
		}
		if (mp>=3) {
			nfa *p1=solve(l+1,r-1,s);
			p->st->link(p1->st,-1);
			p1->ed->link(p->ed,-1);
		} else if (mp==2) {
			assert(mw==r);
			nfa *p1=solve(l,r-1,s);
			p->st->link(p1->st,-1);
			p1->ed->link(p->st,-1);
			p->st->link(p->ed,-1);
		} else if (mp==1) {
			nfa *p1=solve(l,mw-1,s),*p2=solve(mw,r,s);
			p->st->link(p1->st,-1);
			p1->ed->link(p2->st,-1);
			p2->ed->link(p->ed,-1);
		} else {
			nfa *p1=solve(l,mw-1,s),*p2=solve(mw+1,r,s);
			p->st->link(p1->st,-1);
			p->st->link(p2->st,-1);
			p1->ed->link(p->ed,-1);
			p2->ed->link(p->ed,-1);
		}
	}
	return p;
}

void add(int x,int y,int _x,int _y,int _z,int c) {
	int _d=d[_x][_y][_z]+(c!=-1),z=_z||(c!=-1);
	if (d[x][y][z]>_d) {
		d[x][y][z]=_d;pc[x][y][z]=c;
		pre[x][y][z]=(_x<<20)+(_y<<10)+_z;
		if (c==-1) q[--hd]=(x<<20)+(y<<10)+z;
		else q[tl++]=(x<<20)+(y<<10)+z;
	}
}
void print(int x,int y,int z) {
	if (x==0&&y==0&&z==0) return;
	else {
		int Pre=pre[x][y][z];
		print(Pre>>20,(Pre>>10)&1023,Pre&1);
		if (pc[x][y][z]!=-1) putchar(pc[x][y][z]+'a');
	}
}
int main() {
	// read
	scanf("%s%s", s1, s2);
	// regular expression -> nfa
	cur=Nd1,Cur=nd1,solve(0,strlen(s1)-1,s1);
	cur=Nd2,Cur=nd2,solve(0,strlen(s2)-1,s2);
	// dp
	memset(d,0x20,sizeof(d));d[0][0][0]=0;
	hd=tl=100000;
	q[--hd]=0;
	while (hd<tl) {
		int x=q[hd]>>20,y=(q[hd]>>10)&1023,z=q[hd]&1;hd++;
		rep(i,0,nd1[x].nxt.size()) rep(j,0,nd2[y].nxt.size()) if (nd1[x].ch[i]==nd2[y].ch[j]&&nd1[x].ch[i]!=-1)
			add(nd1[x].nxt[i]-nd1,nd2[y].nxt[i]-nd2,x,y,z,nd1[x].ch[i]);
		rep(i,0,nd1[x].nxt.size()) if (nd1[x].ch[i]==-1)
			add(nd1[x].nxt[i]-nd1,y,x,y,z,-1);
		rep(i,0,nd2[y].nxt.size()) if (nd2[y].ch[i]==-1)
			add(x,nd2[y].nxt[i]-nd2,x,y,z,-1);
	}
	if (d[1][1][1]>=1000000) puts("Correct");
	else puts("Wrong"),print(1,1,1);
}
