/*nxt字串
  a  a  b  a  a  b
 -1  0 -1  0  1  2
 mth
  a  a  a  b  a  a  b
  0  1  1  2  3  4  5
*/
void get_nxt(char *s, int len){
	nxt[0]=-1;
	for(int i=1; i<len; i++){
		int j=nxt[i-1];
		while(j!=-1&&s[j+1]!=s[i])j=nxt[j];
		nxt[i]=(s[j+1]==s[i]?j+1:-1);
	}
}
void KMP(char *s1, char *s2, int len1, int len2){//s1母串
	for(int i=0, j=-1; i<len1; i++){
		while(j!=-1&&s1[i]!=s2[j+1])j=nxt[j];
		if(s1[i]==s2[j+1])j++;
		mth[i]=j;
	}
}


