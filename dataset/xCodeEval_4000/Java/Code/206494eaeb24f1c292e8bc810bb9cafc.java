

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Template {

	public static void main(String[] args) throws IOException {
		

		FastScanner scan = new FastScanner();
		

		FastOutput out = new FastOutput();
		

		List<Integer> list;
		

		Map<Integer, Integer> map;
		

		
		

		

		

		PriorityQueue<Pair> pq;
		
		
		

		int t = scan.readInt();
		while(t-->0){
			String[] str= scan.readString().trim().split(" ");
			long r= (long)Integer.parseInt(str[0]);
			long b= (long)Integer.parseInt(str[1]);
			long d= (long)Integer.parseInt(str[2]);
			if(Math.abs(r-b)<=d){
				out.writeString("YES");
			}else{
				if(r>b){
					int temp; 
					temp = (int)r ;
					r = b; 
					b = temp ;
				}
				if(b>r*(d+1)){
					out.writeString("NO");
				}else{
					out.writeString("YES");
				}
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
				res *= (a % mod);
			a *= (a % mod);
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

	

	public static boolean perfect_square(Long n) {
		if (n >= 0) {
			if (Math.ceil((double) Math.sqrt(n)) == Math.floor((double) Math.sqrt(n))) {
				return true;
			}
		}
		return false;
	}

	

	

	public static int countbit(Long n) {
		int count = 0;
		while (n > 0) {
			count++;
			n &= n - 1;
		}
		return count;
	}

	
	
	

	public static class Pair implements Comparable<Pair> {
		Integer f;
		Integer s;
	
		public Pair(Integer f, Integer s) {
			this.f = f;
			this.s = s;
		}
	
		@Override
		public int compareTo(Pair o) {
			if(this.f>o.f){
				return 1;
			}else if(this.f<o.f){
				return -1;
			}else{
				return 0;
			}

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

		

		

		

		public int[] readIntArray(int n) throws IOException {
			int[] nums = new int[n];
			tokenizer = new StringTokenizer(reader.readLine());
			for (int i = 0; i < n; i++) {
				nums[i] = Integer.parseInt(tokenizer.nextToken());
			}
			return nums;
		}

		public Long[] readLongArray(int n) throws IOException {
			tokenizer = new StringTokenizer(reader.readLine());
			Long[] arr = new Long[n];
			int i = 0;
			while (tokenizer.hasMoreTokens()) {
				arr[i] = Long.parseLong(tokenizer.nextToken());
				i++;
			}
			return arr;
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
