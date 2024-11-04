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
	


		int n = in.nextInt();
		long arr[] = new long[n];
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int max = -1;
		int zeroCounter = 0;
		for(int i = 0; i < n; i++){
			arr[i] = in.nextLong();
			if(arr[i] == 0){
				zeroCounter++;
			}
			max = (int) Math.max(arr[i], max);
			if(map.containsKey((int)arr[i])){
				int val = map.get((int)arr[i]);
				val++;
				map.put((int) arr[i], val);
			}
			else{
				map.put((int) arr[i], 1);
			}
		}
		
		int singleCounter = 0;
		int manyCounter = 0;
		int doubleCounter = 0;
		
		for(Integer key : map.keySet()){
			int counter = map.get(key);










			if(counter == 1){
				singleCounter++;
			}
			else{
				manyCounter += counter;
				doubleCounter = key;
			}
		}


		
		if(manyCounter >= 3){
			System.out.println("cslnb");
			return;
		}
		 if(manyCounter == 2){
			if(map.containsKey(doubleCounter - 1)){
				int val = map.get(doubleCounter - 1);
				if(val == 1){
					System.out.println("cslnb");
					return;
				}
			}
		}
	 if(zeroCounter >= 2){
			System.out.println("cslnb");
			return;
		}
		








		Arrays.sort(arr);
		int previous = 0;
		long count = 0;
		long sum = 0;
		for(int i = 0; i < n; i++){
			sum += arr[i];
			long diff = arr[i] - previous;
			previous++;
			if(diff >= 0){
				count += diff;
			}

		}
		long sum1 = (n * (n - 1)) / 2;
		long diff = sum - sum1;
		
		if(diff % 2 == 0){
			System.out.println("cslnb");
		}
		else{
			System.out.println("sjfnb");
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
