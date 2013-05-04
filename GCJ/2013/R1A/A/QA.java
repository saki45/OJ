import java.math.BigInteger;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.PrintWriter;

public class QA{
	public BigInteger calculate(BigInteger n, BigInteger r, BigInteger t){
		BigInteger t1, t2;
		t1 = n.pow(2).shiftLeft(1);
		t2 = n.multiply(r.shiftLeft(1).add(BigInteger.ONE.negate()));
		return t1.add(t2).add(t.negate());
	}

	public String solve(BigInteger r, BigInteger t){
		int res;
		BigInteger st, ed, mid;
		st = BigInteger.ONE;
		ed = t;
		while(!(st.compareTo(ed) > 0)){
			mid = st.add(ed).shiftRight(1);
			res = calculate(mid, r, t).compareTo(BigInteger.ZERO);
			if(res == 0){
				return mid.toString();
			}
			else if(res < 0){
				st = mid.add(BigInteger.ONE);
			}
			else{
				ed = mid.add(BigInteger.ONE.negate());
			}
		}
		return ed.toString();
	}

	public QA(){
		try{
			FileReader fr = new FileReader("A-large.in");
			BufferedReader br = new BufferedReader(fr);
			PrintWriter pw = new PrintWriter("A-large.out");

			String thisLine, token[], res;
			int T;
			BigInteger r, t;

			T = Integer.parseInt(br.readLine());
			System.out.println(T);
			
			for(int nCase=1; nCase<=T; nCase++){
				thisLine = br.readLine();
				token = thisLine.split(" ");
				r = new BigInteger(token[0]);
				t = new BigInteger(token[1]);
				res = solve(r, t);	

				System.out.println("Case #" + nCase + ": " + res);
				pw.println("Case #" + nCase + ": " + res);
			}


			br.close();
			fr.close();
			pw.close();
		}
		catch(Exception ex){
			System.out.println("ex");
		}
	}

	public static void main(String[] args){
		new QA();
	}
}
