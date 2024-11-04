import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Random;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) throws IOException, InterruptedException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		static boolean visited[]  ;
		static boolean found = false; 

		static int steps = 0 ;
		static int n ; 
		static boolean memo [][] ; 
		static int dp[][] ; 
		static char matrix[][] ;
		static ArrayList<Integer> p  ;
		public void solve(int testNumber, InputReader in, PrintWriter out) throws IOException, InterruptedException {

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


			Scanner sc = new Scanner(System.in);
			PrintWriter pw = new PrintWriter(System.out);
			int n = sc.nextInt();
			while (n-- > 0) {
				long p = sc.nextLong();
				long q = sc.nextLong();
				long b = sc.nextLong();
				if (q == 1 || p == 0) {
					pw.println("Finite");
					continue;
				}
				long g = id0(p, q);
				p /= g;
				q /= g;
				long gcd = id0(q, b);
				b /= gcd;
				q /= gcd;

				while(q > 1) {
					gcd = id0(q,gcd);
					if(gcd == 1)
						break;
					q/=gcd;
				}
				if(q == 1)
					pw.println("Finite");
				else
					pw.println("Infinite");
			}
			pw.flush();

		}


		static class Scanner {
			StringTokenizer st;
			BufferedReader br;

			public Scanner(InputStream s) {
				br = new BufferedReader(new InputStreamReader(s));
			}

			public String next() throws IOException {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());
				return st.nextToken();
			}

			public int nextInt() throws IOException {
				return Integer.parseInt(next());
			}

			public long nextLong() throws IOException {
				return Long.parseLong(next());
			}

			public String nextLine() throws IOException {
				return br.readLine();
			}

			public double nextDouble() throws IOException {
				return Double.parseDouble(next());
			}

			public boolean ready() throws IOException {
				return br.ready();
			}
		}


		public static long id0(long n1, long n2) {
			if (n2 == 0) {
				return n1;
			}
			return id0(n2, n1 % n2);
		}

		public static int cnt1(int mat[][])  

		{
			int m = mat.length ; 
			int c=0 ; 
			for (int i = 0; i < mat.length; i++)
			{
				for (int j = 0; j < mat.length; j++)
				{
					int x =  (i*m) +j ;
					if(x%2==0 && mat[i][j]==0)
						c++; 
					if(x%2!=0 && mat[i][j]==1)
						c++; 

				}
			}
			return c;
		}
		public static int cnt0(int mat[][])
		{
			int m = mat.length ; 
			int c=0 ; 
			for (int i = 0; i < mat.length; i++)
			{
				for (int j = 0; j < mat.length; j++)
				{
					int x =  (i*m) +j ; 
					if(x%2!=0 && mat[i][j]==0)
						c++; 
					if(x%2==0 && mat[i][j]==1)
						c++; 

				}
			}
			return c;
		}

		public static boolean id3(int x1, int y1 , int x2 , int y2 , int x3 , int y3){
			if(x1==x2)
				if(x1==x3)
					return true ; 
				else
					return false ;
			else
				if(x1==x3)
					return false ; 
				else
				{
					long a = 1l*(y2-y1)*(x3-x2) ; 
					long b = 1l*(y3-y2)*(x2-x1) ; 

					if(a==b)
						return true;
					else 
						return false ;

				}

		}
		public static void shuffle(int c[]){
			if(c.length==1)
				return ; 
			for (int i = 0; i < c.length; i++)
			{
				Random rand = new Random();

				int  n = rand.nextInt(c.length-1) + 0;

				int temp = c[i] ; 
				c[i] = c[n] ; 
				c[n] = temp ;
			}
		}
		public static int binary(long[]arr, int l, int r, long x)   

		{
			if (r>=l)
			{
				int mid = l + (r - l)/2;
				if (arr[mid]== x)
					return mid;
				if (arr[mid]> x)
					return binary(arr, l, mid-1, x);
				return binary(arr, mid+1, r, x);
			}
			return -1;
		}

		

		public static int binary1(long[]arr , long x) {
			int low = 0, high = arr.length; 

			while (low != high) {
				int mid = (low + high) / 2; 

				if (arr[mid] <= x) {
					
					low = mid + 1;
				}
				else {
					
					high = mid;
				}
			}
			return low ; 

		}


		private static boolean triangle(int a, int b , int c){
			if(a+b>c && a+c>b && b+c>a)
				return true ; 
			else 
				return false ;
		}
		private static boolean segment(int a, int b , int c){
			if(a+b==c || a+c==b && b+c==a)
				return true ; 
			else 
				return false ;
		}
		private static int id2(long a, long b) {
			BigInteger b1 = BigInteger.valueOf(a);
			BigInteger b2 = BigInteger.valueOf(b);
			BigInteger gcd = b1.gcd(b2);
			return gcd.intValue();
		}

		public static boolean is(int i){
			if(Math.log(i)/ Math.log(2) ==(int) (Math.log(i)/ Math.log(2)))
				return true ; 
			if(Math.log(i)/ Math.log(3) ==(int) (Math.log(i)/ Math.log(3)) )
				return true ; 
			if(Math.log(i)/ Math.log(6) ==(int) (Math.log(i)/ Math.log(6)) )
				return true ; 

			return false;

		}
		public static boolean contains(int b[] , int x)
		{
			for (int i = 0; i < b.length; i++)
			{
				if(b[i]==x)
					return true ;
			}
			return false ;
		}
		public static int binary(long []arr , long target , int low , long shift) {
			int high = arr.length; 
			while (low != high) {
				int mid = (low + high) / 2; 
				if (arr[mid]-shift <= target) {
					low = mid + 1;
				}
				else {
					high = mid;
				}
			}
			return low ; 

		}
		public static boolean isLetter(char x){
			if(x+0 <=122 && x+0 >=97 )
				return true ;
			else if (x+0 <=90 && x+0 >=65 )
				return true ; 
			else return false; 
		}
		public static long id1(long x ){
			if(x==2 || x==3 || x==1)
				return 2 ;
			if(isPrime(x))
				return 5 ;
			for (int i = 2; i*i<=x; i++)
			{
				if(x%i==0 && isPrime(i))
					return id1(x/i) ;
			}
			return -1;
		}
		public static String solve(String x){

			int n = x.length() ; 
			String y = "" ;
			for (int i = 0; i < n-2; i+=2)
			{
				if(ifPalindrome(x.substring(i, i+2)))
					y+= x.substring(i, i+2) ;
				else 
					break ;
			}
			return y+ solve1(x.substring(y.length(),x.length())) ;

		}
		public static String solve1(String x){
			String y = x.substring(0 , x.length()/2) ; 
			return "" ;

		}
		public static String reverse(String x){
			String y ="" ;
			for (int i = 0; i < x.length(); i++)
			{
				y  = x.charAt(i) + y ;
			}
			return y ;
		}

		public static boolean ifPalindrome(String x){
			int numbers[] = new int[10] ; 
			for (int i = 0; i < x.length(); i++)
			{
				int z = Integer.parseInt(x.charAt(i)+"") ; 
				numbers[z] ++ ;
			}
			for (int i = 0; i < numbers.length; i++)
			{
				if(numbers[i]%2!=0)
					return false; 
			}
			return true ;	
		}

		public static int get(int n){
			return n*(n+1)/2 ; 
		}
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		public static int calcDepth(Vertix node){
			if(node.depth>0) return node.depth; 
			

			if(node.parent != null)
				return 1+ calcDepth(node.parent);
			else
				return -1;
		}

		public static boolean isPrime (long num){
			if (num < 2) return false;
			if (num == 2) return true;
			if (num % 2 == 0) return false;
			for (int i = 3; i * i <= num; i += 2)
				if (num % i == 0) return false;
			return true;
		}


		public static ArrayList<Long> getDiv(Long n)
		{
			ArrayList<Long>  f = new ArrayList<Long>() ; 

			while (n%2==0)
			{
				if(!f.contains(2))f.add((long) 2) ;
				n /= 2;
			}

			

			

			for (long i = 3; i <= Math.sqrt(n); i+= 2)
			{
				

				while (n%i == 0)
				{
					if(!f.contains(i))f.add(i);
					n /= i;
				}
			}

			

			

			if (n > 2)
				if(!f.contains(n))f.add(n);


			return f ;



		}

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		







	}
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
	public static class Vertix{
		long i ; 
		int depth ;
		ArrayList<Vertix> neighbours ; 
		Vertix parent ; 
		Vertix child ; 


		public Vertix(long i){
			this.i = i ;
			this.neighbours = new ArrayList<Vertix> () ;
			this.parent = null ;
			depth =-1;
			this.child = null ;
		}
	}

	public static class pair implements Comparable<pair>{
		int i ;  
		int j ;
		int index ;





		public pair(int x, int y, int z ){
			this.i=x ; 
			this.j=y ;
			this.index =z ; 


		}

		@Override
		public int compareTo(pair p) {
			if(this.i > p.i)
				return 1 ; 
			else if(this.i== p.i) 
				return 0 ;
			else return -1 ;


		}


	}

	public static class pair2 implements Comparable<pair2>{
		int i ; 
		int j ;
		int index ; 

		public pair2(int i , int j , int index){
			this.i =i ;
			this.j = j ; 
			this.index = index ;
		}

		@Override
		public int compareTo(pair2 p) {
			if(this.j > p.j)
				return 1 ; 
			else if (this.j == p.j) return 0 ;
			else 
				return -1 ;
		}


	}


}