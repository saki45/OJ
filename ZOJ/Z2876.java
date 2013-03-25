import java.util.Arrays;
import java.util.Scanner;

class Z2876{
	public static void main(String[] args){
		String[] strArr = new String[10000];
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		while(t>0){
			int n = sc.nextInt();
			sc.nextLine();
			for(int i=0; i<n; i++){
				strArr[i] = sc.nextLine();
			}

			if(n == 1)
				System.out.println("YES");
			else{
				Arrays.sort(strArr, 0, n);
				boolean isValid = true;
				for(int i=1; i<n; i++){
					if(strArr[i].contains(strArr[i-1])){
						isValid = false;
						break;
					}
				}
				if(isValid){
					System.out.println("YES");
				}
				else{
					System.out.println("NO");
				}
			}
			t--;
		}

		sc.close();
	}
}
