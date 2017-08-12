import java.util.Scanner;
import java.math.BigInteger;
public class BigIntegerTesting{
   public static void main(String[] args) {
   		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		BigInteger fact = new BigInteger(""+n);
		for(int i=n-1;i>1;i--){
			BigInteger m = new BigInteger(""+i);
			fact = fact.multiply(m);
		}
		String res=fact.toString();
		System.out.println(res);
		int j=-1;
		for (int i=res.length()-1;i>=0;i--) {
			if(res.charAt(i)!='0'){
				j=i;
				break;
			}
		}
		System.out.println(res.charAt(j));
		BigInteger dv= new BigInteger("9317");
		System.out.println(fact.remainder(dv));
   }
}