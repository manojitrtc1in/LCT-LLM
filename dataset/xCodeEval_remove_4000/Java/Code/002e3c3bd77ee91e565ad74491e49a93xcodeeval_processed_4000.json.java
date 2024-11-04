


import java.io.*;
import java.util.*;

public class Template {

	public static void main(String[] args) throws IOException {
		

		final int mod = 1000000007;
		

		FastScanner scan = new FastScanner();
		

		FastOutput out = new FastOutput();
		


		

		


		


		

		

		

		


		

		


		

		


		

		


		
		

			int t = scan.readInt();
			while(t-->0){
				int n  = scan.readInt();
					if(n%2==0 && perfectsquare(n/2)){
						out.writeString("YES");
						continue;
					}
					if(n%4==0 && perfectsquare(n/4)){
						out.writeString("YES");
						continue;
					}
					out.writeString("NO");

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

	public static long id9(long a, long b, long mod) {
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

	

	public static boolean id11(long a) {
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

	

	public static int id0(int digit) {
		int sum = 0;
		while (digit > 0) {
			sum += digit % 10;
			digit /= 10;
		}
		return sum;
	}

	

	public static boolean perfectsquare(long n ) {
		if(n>=0){
			int sr  = (int)Math.sqrt(n);
			return sr*sr==n;
		}
		return false;
	}
	
	
	
	

	

	public static class Pair {
		Integer f;
		Integer s;

		public Pair(Integer f, Integer s) {
			this.f = f;
			this.s = s;
		}
	}

	public static class id2 implements Comparator<Integer> {

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

		

		

		

		public int[] id1(int n) throws IOException {
			int[] nums = new int[n];
			tokenizer = new StringTokenizer(reader.readLine());
			for (int i = 0; i < n; i++) {
				nums[i] = Integer.parseInt(tokenizer.nextToken());
			}
			return nums;
		}

		public Long[] id4(int n) throws IOException {
			tokenizer = new StringTokenizer(reader.readLine());
			Long[] arr = new Long[n];
			int i = 0;
			while (tokenizer.hasMoreTokens()) {
				arr[i] = Long.parseLong(tokenizer.nextToken());
				i++;
			}
			return arr;
		}

		public List<Integer> id8() throws IOException {
			List<Integer> list = new ArrayList<Integer>();
			tokenizer = new StringTokenizer(reader.readLine());
			while (tokenizer.hasMoreTokens()) {
				list.add(Integer.parseInt(tokenizer.nextToken()));
			}
			return list;
		}

		public List<Long> id6() throws IOException {
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

		public void id10(String s) throws IOException {
			writer.write(s);
			writer.write(" ");
			writer.flush();
		}

		

		

		public void id3(int[] nums) throws IOException {
			for (int i = 0; i < nums.length; i++) {
				writer.write(nums[i] + " ");
			}
			writer.newLine();
			writer.flush();
		}

		

		

		public void id7(int[] nums) throws IOException {
			for (int i = 0; i < nums.length; i++) {
				writer.write(Integer.toString(nums[i]));
			}
			writer.newLine();
			writer.flush();
		}

		public void id12(List<Integer> num) throws IOException {
			if (num != null) {
				for (Integer integer : num) {
					writer.write(integer + " ");

				}
			}
			writer.newLine();
			writer.flush();
		}

		public void id5(int[][] matrix) throws IOException {
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