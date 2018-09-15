import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static BigInteger C(int n,int m) {
		BigInteger ans=BigInteger.ONE;
		for(int i=1;i<=m;i++) {
			ans=ans.multiply(BigInteger.valueOf(n-i+1));
			ans=ans.divide(BigInteger.valueOf(i));
		}
		return ans;
	}
	public static void main(String[] args) {
		BigInteger _1=new BigInteger("1"),_0=BigInteger.ZERO;
		BigInteger yh[][]=new BigInteger[300][300];
		for(int i = 0; i < 300; ++i) yh[i] = new BigInteger[300];
		for(int i = 0; i < 300; ++i) {
			for(int j = 0; j < 300; ++j) {
				yh[i][j] = _0;
			}
		}
		yh[0][0]=_1;
		for(int i=1;i<=250;i++) {
			yh[i][0]=_1;
			for(int j=1;j<=i;j++)yh[i][j]=yh[i-1][j].add(yh[i-1][j-1]);
		}
		Scanner cin=new Scanner(System.in);
		int n,m;
		while(cin.hasNext()) {
			m=cin.nextInt();
			n=cin.nextInt();
			BigInteger fz=_0;
			for(int y=1;y<=m;y++) {
				BigInteger _temp=_0;
				for(int i=1;i<=y;i++) {
					BigInteger temp=_0;
					for(int x=1;m-(x-1)*i>=y;x++) {
						 BigInteger ans=yh[m-(x-1)*i-1][y-1];
						 if(i%2==1)temp=temp.add(ans);
						 else temp=temp.subtract(ans);
					}
					_temp=_temp.add(temp.multiply(yh[y][i]));
				}
				fz=fz.add(_temp.multiply(C(n,y)));
			}
			BigInteger fm=_0;
			for(int i=1;i<=m;i++) {
				BigInteger a=yh[m-1][i-1],b=C(n,i);
				//System.out.println(a+" "+b);
				fm=fm.add(a.multiply(b));
			}
			BigDecimal rfz=new BigDecimal(fz);
			BigDecimal rfm=new BigDecimal(fm);
			System.out.println(rfz.divide(rfm,4,BigDecimal.ROUND_HALF_UP));
		}
	}
}