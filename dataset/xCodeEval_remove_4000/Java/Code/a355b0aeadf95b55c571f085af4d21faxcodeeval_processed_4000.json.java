import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.DoubleStream;
import java.util.stream.IntStream;



public class Main {

	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { -1, 0, 1, 0 };

	static int[] ddx = { 0, 1, 0, -1, -1, 1, 1, -1 };
	static int[] ddy = { -1, 0, 1, 0, -1, -1, 1, 1 };

	static int[] kx = { 2, 1, -1, -2, -2, -1, 1, 2 };
	static int[] ky = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static long MOD = Long.MAX_VALUE;

	static final int MAX = 50000;
	static long INF = Long.MAX_VALUE;

	static double PI = 3.1415926535;

	private static final double EPSILON = 1e-10;

	
	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
	


		int test = in.nextInt();
		for(int t = 1; t <= test; t++){
		
			int n = in.nextInt();
			int m = in.nextInt();
			
			int grid[][] = new int[n][m];
			
			int cols[] = new int[m];
			int rows[] = new int[n];
			
			int cols1[] = new int[m];
			int rows1[] = new int[n];
			
			for(int i = 0; i < n; i++){
				String str = in.next();
				for(int j = 0; j < m; j++){
					if(str.charAt(j) == '*'){
						grid[i][j] = 1;
						cols1[j]++;
						rows1[i]++;
					}
					else{
						cols[j] = -1;
						rows[i] = -1;
					}
				}
			}
			
			int count = 0;
			int min = Integer.MAX_VALUE;
			
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(cols[j] != -1 && rows[i] != -1){
						count++;
					}
					else{
						
						int temp = 0;
						if(grid[i][j] != 1){
							 temp = n - cols1[j] + (m - 1) - rows1[i];
						}
						else{
							temp = n - cols1[j] + m - rows1[i];
						}


						min = Math.min(min, temp);
						
						
					}
				}
			}
			
			if(count == 0){
				System.out.println(min);
			}
			else{
				System.out.println(0);
			}


			
			
			
		}
		
		System.exit(0);
	}
	
	
	
	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	


	private static double getDistance(double x1, double y1, double x2, double y2) {

		return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
	}

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static int dp[][];

	

	

	

	

	

	

	


	

	

	


	 private static long bigMod(long n, long k, long m) {
	
	 long ans = 1;
	 while (k > 0) {
	 if ((k & 1) == 1) {
	 ans = (ans * n) % m;
	 }
	 n = (n * n) % m;
	 k >>= 1;
	 }
	 return ans;
	 }

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public String next() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());

				}
			} catch (IOException e) {
				return null;
			}
			return tokenizer.nextToken();
		}

		public String nextLine() {
			String line = null;
			try {
				tokenizer = null;
				line = reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			return line;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public boolean hasNext() {
			try {
				while (tokenizer == null || !tokenizer.hasMoreTokens()) {
					tokenizer = new StringTokenizer(reader.readLine());
				}
			} catch (Exception e) {
				return false;
			}
			return true;
		}
	}
}
