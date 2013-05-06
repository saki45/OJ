import java.io.FileReader;
import java.io.BufferedReader;
import java.io.PrintWriter;

public class QA{
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
