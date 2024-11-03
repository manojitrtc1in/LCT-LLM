


import java.io.*;
import java.util.*;

public class Template {

	public static void main(String[] args) throws IOException {
		

		final int mod = 1000000007;
		

		FastScanner scan = new FastScanner();
		

		FastOutput out = new FastOutput();
		


		


		


		


		

		


		

		


		

		


		

		

		

		

		

		

		

		

		


		

		


		


		

		


		


		


		

		
		

		int t = scan.readInt();
		while(t-->0){
			String[] str = scan.readString().trim().split(" ");
			int n = Integer.parseInt(str[0]);
			int x = Integer.parseInt(str[1]);
			int[] arr= scan.readIntArray(n);
			int sum = scan.sum;
			if(sum==x){
				out.writeString("NO");
				continue;
			}
			out.writeString("YES");
			sum = 0 ;
			for (int i = 0; i < n-1; i++) {
				sum+=arr[i];
				if(sum==x){
					int temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp; 
				}
			}
			out.writeIntArray(arr);
		}








		
		
	}

	
	

	
	

	


	

	public static void dfs(int v, boolean[] visited, List<List<Integer>> adjlist) {
		if (visited[v])
			return;
		visited[v] = true;
		

		for (Integer integer : adjlist.get(v)) {
			if (visited[integer] == false) {
				dfs(integer, visited, adjlist);
			}
		}
	}

	

	public static long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	

	public static long binexp(long a, long b) {
		long res = 1;
		while (b != 0) {
			if (b % 2 != 0)
				res *= a;
			a *= a;
			b /= 2;
		}
		return res;
	}

	public static long binexpomod(long a, long b, long mod) {
		long res = 1;
		a %= mod;
		while (b != 0) {
			if (b % 2 != 0)
				res = (res % mod) * (a % mod);
			a = (a % mod) * (a % mod);
			b /= 2;
		}
		return res;
	}

	

	public static boolean primeornot(long a) {
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				

				return false;

			}
		}
		return true;
	}

	

	public static boolean palindrome(String string) {
		StringBuffer buffer = new StringBuffer(string);
		buffer = buffer.reverse();
		if (string.equals(buffer.toString())) {
			return true;
		}
		return false;
	}

	

	public static int countdigit(long a) {
		int count = 0;
		while (a != 0) {
			a = a / 10;
			count++;
		}
		return count;
	}

	

	

	public static int countbit(Long n) {
		int count = 0;
		while (n > 0) {
			count++;
			n &= n - 1;
		}
		return count;
	}

	

	public static int sumofdigits(int digit) {
		int sum = 0;
		while (digit > 0) {
			sum += digit % 10;
			digit /= 10;
		}
		return sum;
	}

	

	public static boolean perfectsquare(long n) {
		if (n >= 0) {
			int sr = (int) Math.sqrt(n);
			return sr * sr == n;
		}
		return false;
	}

	
	
	


	

	

	

	


	

	

	

	

	


	


	static class Pair<A, B> {
		A first;
		B second;

		

		public Pair(A first, B second) {
			this.first = first;
			this.second = second;
		}
	}

	public static class mycomparator implements Comparator<Integer> {
		@Override
		public int compare(Integer o1, Integer o2) {
			if (o1 < o2) {
				return 1;
			} else if (o1 > o2) {
				return -1;
			}
			return 0;
		}

	}

	
	

	public static class FastScanner {

		

		BufferedReader reader;
		public int[] intarr; 
		public Long[] longarr; 
		int sum ;
		long longsum ;
		

		public FastScanner() {

			

			reader = new BufferedReader(new InputStreamReader(System.in));

			if (System.getProperty("ONLINE_JUDGE") == null) {
				try {
					reader = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				} catch (Exception e) {
				}
			}
		}

		

		StringTokenizer tokenizer;

		

		

		


		public int readInt() throws IOException {
			return Integer.parseInt(reader.readLine());
		}

		

		

		public long readLong() throws IOException {
			return Long.parseLong(reader.readLine());
		}

		

		public String readString() throws IOException {
			return reader.readLine();
		}

		

		

		

		public int[] readIntArray(int n) throws IOException {
			sum = 0 ;
			intarr = new int[n];
			tokenizer = new StringTokenizer(reader.readLine());
			for (int i = 0; i < n; i++) {
				sum+=intarr[i] = Integer.parseInt(tokenizer.nextToken());
			}
			return intarr;
		}

		public Long[] readLongArray(int n) throws IOException {
			tokenizer = new StringTokenizer(reader.readLine());
			longsum = 0 ;
			longarr = new Long[n];
			int i = 0;
			while (tokenizer.hasMoreTokens()) {
				longsum+=longarr[i] = Long.parseLong(tokenizer.nextToken());
				i++;
			}
			return longarr;
		}

		public List<Integer> readIntAsList() throws IOException {
			List<Integer> list = new ArrayList<Integer>();
			tokenizer = new StringTokenizer(reader.readLine());
			while (tokenizer.hasMoreTokens()) {
				list.add(Integer.parseInt(tokenizer.nextToken()));
			}
			return list;
		}

		public List<Long> readLongAsList() throws IOException {
			List<Long> list = new ArrayList<Long>();
			tokenizer = new StringTokenizer(reader.readLine());
			while (tokenizer.hasMoreTokens()) {
				list.add(Long.parseLong(tokenizer.nextToken()));
			}
			return list;
		}

	}

	

	public static class FastOutput {

		

		BufferedWriter writer;

		

		public FastOutput() {

			

			writer = new BufferedWriter(new OutputStreamWriter(System.out));
			if (System.getProperty("ONLINE_JUDGE") == null) {
				try {
					writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
				} catch (Exception e) {
				}
			}
		}

		

		

		public void writeInt(int i) throws IOException {
			writer.write(Integer.toString(i));
			writer.newLine();
			writer.flush();
		}

		

		public void writeChar(char c) throws IOException {
			writer.write(Character.toString(c));
			writer.newLine();
			writer.flush();
		}

		

		public void writeLong(long i) throws IOException {
			writer.write(Long.toString(i));
			writer.newLine();
			writer.flush();
		}

		

		public void writeString(String s) throws IOException {
			writer.write(s);
			writer.newLine();
			writer.flush();
		}

		public void writeStringWithSpace(String s) throws IOException {
			writer.write(s);
			writer.write(" ");
			writer.flush();
		}

		

		

		public void writeIntArray(int[] nums) throws IOException {
			for (int i = 0; i < nums.length; i++) {
				writer.write(nums[i] + " ");
			}
			writer.newLine();
			writer.flush();
		}

		

		

		public void writeIntArrayWithoutSpaces(int[] nums) throws IOException {
			for (int i = 0; i < nums.length; i++) {
				writer.write(Integer.toString(nums[i]));
			}
			writer.newLine();
			writer.flush();
		}

		public void writeIntegerlist(List<Integer> num) throws IOException {
			if (num != null) {
				for (Integer integer : num) {
					writer.write(integer + " ");

				}
			}
			writer.newLine();
			writer.flush();
		}

		public void writeintmatrix(int[][] matrix) throws IOException {
			for (int i = 0; i < matrix.length; i++) {
				for (int j = 0; j < matrix[0].length; j++) {
					writer.write(matrix[i][j] + " ");
				}
				writer.newLine();
			}
			writer.newLine();
			writer.flush();

		}

	}
}