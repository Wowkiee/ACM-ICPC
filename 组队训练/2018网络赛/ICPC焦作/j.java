import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static BigInteger _0=BigInteger.ZERO,_1=new BigInteger("1"),_2=new BigInteger("2");
	public static int ok(BigInteger a) {
		BigInteger l=_0,r=a;
		while(l.compareTo(r)==-1) {
			BigInteger mid=l.add(r).divide(_2);
			int res=mid.multiply(mid).compareTo(a);
			if(res==1||res==0)r=mid;
			else l=mid.add(_1);
		}
		return a.equals(l.multiply(l))?1:0;
	}
	public static int check(BigInteger a) {
		BigInteger b = a.divide(_2);
		b = b.multiply(_2);
		if(a.compareTo(b) == 0) return 0;
		return 1;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for(int i = 1; i <= T; ++i) {
			BigInteger n = cin.nextBigInteger();
			BigInteger nn=n.subtract(_1);
			int t = check(n), a = ok(n);
			boolean b;
			if(a != t) b = false;
			else {
				int ok2, ok3;
				if(t == 1) {
					ok2 = ok(n);
					ok3 = ok(nn.divide(_2));
				} else {
					ok2 = ok(n.divide(_2));
					ok3 = ok(nn);
				}
				b = ((ok2 == 1) && (ok3 == 1));
			}
			if(a==1&&b)System.out.println("Arena of Valor");
			else if(a==0&&b)System.out.println("Clash Royale");
			else if(a==0&&!b)System.out.println("League of Legends");
			else System.out.println("Hearth Stone");
		}
	}
}