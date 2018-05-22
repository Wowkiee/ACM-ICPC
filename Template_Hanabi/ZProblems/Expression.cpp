char s[U<<2];
int len;
int a[U];
bool Q[6][6] = {
    0,0,0,0,0,0,
    1,1,0,0,0,0,
    1,1,1,0,0,0,
    1,1,1,0,0,0,
    1,1,1,1,0,0,
    0,0,0,0,0,0,
};

int id(char c){
    if(c == '~') return 0;
    if(c == '&') return 1;
    if(c == '|') return 2;
    if(c == '>') return 3;
    if(c == '=') return 4;
    // '('
    return 5;
}

int num[1010] , op[1010];
int ntop , otop;

void pop(){
    int c = op[otop--];
    int t1,t2;
    if(c == '~'){
        t1 = num[ntop];
        num[ntop] = imp[t1][1];
    }
    else if(c == '&'){
        t1 = num[ntop] , t2 = num[ntop-1];
        num[--ntop] = con[t2][t1];
    }
    else if(c == '|'){
        t1 = num[ntop] , t2 = num[ntop-1];
        num[--ntop] = dis[t2][t1];
    }
    else if(c == '>'){
        t1 = num[ntop] , t2 = num[ntop-1];
        num[--ntop] = imp[t2][t1];
    }
    else if(c == '='){
        int fr = ntop-1;
        while(otop != -1 && op[otop] == '=') fr-- , otop--;
        int k = -1,x,y,cal;
        for(int i=fr;i<ntop;++i){
            x = num[i] , y = num[i+1];
            cal = con[imp[x][y]][imp[y][x]];
            if(k == -1) k = cal;
            else k = con[k][cal];
        }
        num[ntop = fr] = k;
    }
}

bool ok(){
    ntop = otop = -1;
    rep(i,0,len){
        int c = s[i];
        if(c == ' ') continue;
        else if(isupper(c)) num[++ntop] = a[c-'A'];
        else if(isdigit(c)) num[++ntop] = c=='0';
        else if(c == ')'){
            while(op[otop] != '(') pop();
            otop--;
        }
        else{
            while(otop != -1 && Q[id(c)][id(op[otop])]) pop();
            op[++otop] = c;
        }
    }
    while(otop != -1) pop();
    return num[0] == 0;
}
