
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;



public class Main {

	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { -1, 0, 1, 0 };

	static int[] ddx = { 0, 1, 0, -1, -1, 1, 1, -1 };
	static int[] ddy = { -1, 0, 1, 0, -1, -1, 1, 1 };

	static int[] kx = { 2, 1, -1, -2, -2, -1, 1, 2 };
	static int[] ky = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static long MOD = Long.MAX_VALUE;

	static final int MAX = 100007;
	static long INF = Long.MAX_VALUE;

	static double PI = 3.1415926535;

	private static final double EPSILON = 1e-10;

	private static double dp[] = new double[MAX];

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);

		
		
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		
		long val = n * m;
		long parts = val / k;	
		
		List<List<Point>> list = new ArrayList<List<Point>>();
		boolean forward = true;
		int count = 0;
		List<Point> curr = new ArrayList<Main.Point>();
		for(int i = 0; i < n; i++){
			
			if(forward){
				for(int j = 0; j < m; j++){
					
					if(list.size() == k){
						list.get(k - 1).add(new Point(i + 1, j + 1));
					}
					else{
					
					count++;
					curr.add(new Point(i + 1, j + 1));
					
					if(count == parts){
						list.add(curr);
						count = 0;
						curr = new ArrayList<Main.Point>();
					}
					
				}
				}
			}
			else{
				for(int j = m - 1; j >= 0; j--){
					
					if(list.size() == k){
						list.get(k - 1).add(new Point(i + 1, j + 1));
					}
					else{
						count++;
						curr.add(new Point(i + 1, j + 1));
						if(count == parts){
							list.add(curr);
							count = 0;
							curr = new ArrayList<Main.Point>();
						}
						
					}
					
				}
			}
			
			if(forward){
				forward = false;
			}
			else{
				forward = true;
			}
		}
		
		for(int i = 0; i < list.size(); i++){
			List<Point> l = list.get(i);
			System.out.print(l.size());
			for(int j = 0; j < l.size(); j++){
				Point p = l.get(j);
				System.out.print(" " + p.x + " " + p.y);
			}
			System.out.println();
		}
		
		
		System.exit(0);
	}

	




	private static class Node{
		long value;
		List<Integer> childs;
		
		Node(long value){
			this.value = value;
			childs = new ArrayList<Integer>();
		}
	}
	

	private static class Pair {
		int first;
		String second;

		Pair(int first, String second) {
			this.first = first;
			this.second = second;
		}
	}

	private static class Point {
		int x;
		int y;

		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {

			return this.x + " " + this.y;
		}
	}

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	


	private static double getDistance(double x1, double y1, double x2, double y2) {

		return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
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
