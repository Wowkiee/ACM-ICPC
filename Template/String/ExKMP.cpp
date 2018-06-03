/*
 nxt//T[i..i+nxt[i]]=T[0..nxt[i]]
 0  1  2  3  4  5  6
 a  a  a  a  a
 4  3  2  1  0
 a  a  a  b  b  b  a  a  a
 8  1  0 -1 -1 -1  2  1  0
 ex//S[i..i+ex[i]]=T[0..ex[i]]
 a  a  a  a  b  a  a
 3  2  1  0 -1  1  0
*/
void get_nxt(char *s, int len){
	int i=0;
	nxt[0]=len-1;
	while(i+1<len&&s[i]==s[i+1])i++;
	nxt[1]=i-1;
	for(int i=2, po=1; i<len; i++){
		if(nxt[i-po]+i<nxt[po]+po)
			nxt[i]=nxt[i-po];
		else{
			int j=nxt[po]+po-i+1;
			if(j<0)j=0;
			while(i+j<len&&s[j]==s[i+j])j++;
			nxt[i]=j-1;
			po=i;
		}
	}
}
void ExKMP(char *s1, char *s2, int len1, int len2){//s1 ex s2 nxt
	int i=0;
	while(i<len1&&i<len2&&s1[i]==s2[i])i++;
	ex[0]=i-1;
	for(int i=1, po=0; i<len1; i++){
		if(nxt[i-po]+i<ex[po]+po)
			ex[i]=nxt[i-po];
		else{
			int j=ex[po]+po-i+1;
			if(j<0)j=0;
			while(i+j<len1&&j<len2&&s1[i+j]==s2[j])j++;
			ex[i]=j-1;
			po=i;
		}
	}
}
