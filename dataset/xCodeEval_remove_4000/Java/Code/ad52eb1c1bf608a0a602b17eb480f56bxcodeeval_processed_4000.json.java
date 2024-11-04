import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
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
			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


			int n = in.nextInt() ; 
			int k = in.nextInt() ; 

			int a[] = new int[n] ; 
			for (int i = 0; i < a.length; i++)
			{
				a[i] = in.nextInt() ;
			}

			int col[]= new int[256];
			int coll [] = new int[256] ; 
			for (int i = 0; i < coll.length; i++)
			{
				coll[i]=-1 ;
			}
			Arrays.fill(col, -1);


			int b[]= new int[n] ;
			

			

			

			

			

			

			




			for (int i = 0; i < n; i++)
			{
				if(col[a[i]]==-1)
				{

					for (int j = a[i]-k+1; j <= a[i]; j++)
					{
						if(j>=0 && j<256)
						{if(col[j]==-1 || coll[j]>=a[i])
						{
							col[a[i]]=j ;
							b[i]=j ; 
							break ;
						}
						}
					}
					for (int j = b[i]; j <= a[i]; j++)
					{
						col[j]=b[i] ;
					}


					for (int j = b[i]; j <= a[i]; j++)
					{
						coll[j]=b[i]+(k-1) ;
					}



					

					

					

					


					

					

					

					


				} else 
				{
					b[i] = col[a[i]] ;
				}

			}


			for (int i = 0; i < n; i++)
			{
				System.out.print(b[i]+" ");
			}














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

		public static boolean id2(int x1, int y1 , int x2 , int y2 , int x3 , int y3){
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
		public static int binary(ArrayList<Long> arr, int l, int r, long x)   

		{
			if (r>=l)
			{
				int mid = l + (r - l)/2;
				if (arr.get(mid) == x)
					return mid;
				if (arr.get(mid)> x)
					return binary(arr, l, mid-1, x);
				return binary(arr, mid+1, r, x);
			}
			return -1;
		}

		

		public static int binary1(ArrayList<Long> arr , long left) {
			int low = 0, high = arr.size(); 

			while (low != high) {
				int mid = (low + high) / 2; 

				if (arr.get(mid) <= left) {
					
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
		private static int id1(long a, long b) {
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
		public static long id0(long x ){
			if(x==2 || x==3 || x==1)
				return 2 ;
			if(isPrime(x))
				return 5 ;
			for (int i = 2; i*i<=x; i++)
			{
				if(x%i==0 && isPrime(i))
					return id0(x/i) ;
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


		public static int[] getDiv(int n)
		{
			int result[] = new int[7] ; 
			ArrayList<Integer>  f = new ArrayList<Integer>() ; 

			while (n%2==0)
			{
				if(!f.contains(2))f.add(2) ;
				n /= 2;
			}

			

			

			for (int i = 3; i <= Math.sqrt(n); i+= 2)
			{
				

				while (n%i == 0)
				{
					if(!f.contains(i))f.add(i);
					n /= i;
				}
			}

			

			

			if (n > 2)
				if(!f.contains(n))f.add(n);

			for (int i = 0, j=0; i < f.size(); i++)
			{
				result[j++]=f.get(i);
			}
			return result ;



		}

		public static boolean dfs(Vertix v , int target){
			try{
				visited[v.i]= true ;
			} catch (NullPointerException e)
			{
				System.out.println(v.i);
			}
			if(v.i == target)

				return true ;
			for (int i =0 ; i< v.neighbours.size() ; i++)
			{ 

				Vertix child = v.neighbours.get(i) ;
				if(child.i == target){
					found = true  ; 
				}
				if(visited[child.i]==false){
					found |= dfs(child, target) ;
				}
			}
			return found; 
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
		int i ; 
		int depth ;
		ArrayList<Vertix> neighbours ; 
		Vertix parent ; 
		Vertix child ; 


		public Vertix(int i){
			this.i = i ;
			this.neighbours = new ArrayList<Vertix> () ;
			this.parent = null ;
			depth =-1;
			this.child = null ;
		}
	}

	public static class pair implements Comparable<pair>{
		int x ;  
		int y ;  




		public pair(int x, int y , int z){
			this.x=x ; 
			this.y=y ;


		}

		@Override
		public int compareTo(pair p) {
			if(this.x > p.x)
				return 1 ; 
			else return -1 ;


		}


	}


}