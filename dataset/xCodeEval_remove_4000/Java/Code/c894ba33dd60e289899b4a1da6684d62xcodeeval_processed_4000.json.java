import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PrE {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long[] out = go(br);
		for(int i = 0; i < out.length; i++) {
			System.out.print(out[i]);
			if(i + 1 == out.length) System.out.println();
			else System.out.print(" ");
		}
		br.close();
		System.exit(0);
	}
	
	public static final int P = 1000000007;



	public static long[] go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		long[] start = new long[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			start[i] = Integer.parseInt(st.nextToken());
		}
		if(k == 0) return start;
		long[] choose = new long[n];
		choose[0] = 1;
		for(int i = 1; i < n; i++) 
			choose[i] = (((inv(i) * choose[i - 1]) % P) * (k - 1 + i)) % P;
		long[] out = new long[n];
		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				out[j] += start[i] * choose[j - i] % P;
				out[j] %= P;
			}
		}
		return out;
	}
	
	public static long inv(long i) {
		for(long j = 0;; j++) 
			if((P * j + 1) % i == 0) 
				return (P * j + 1) / i;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}