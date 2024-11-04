import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
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
			int x[] =  new int[n] ; 
			int y[] = new int[n] ; 
			for (int i = 0; i < n; i++)
			{
				x[i]=in.nextInt() ; 
				y[i] = in.nextInt() ; 

			}
			if(n<=4)
			{
				System.out.println("YES");
				return  ;
			}

			



			boolean xaxis9 = false ; 

			boolean checked4 = false ; 

			if(x[0]==x[1] && x[1]==x[2] && x[2]==x[3])
				xaxis9 = true; 

			if(1l*(y[2]-y[1])*(x[3]-x[2])== 1l*(y[3]-y[2])*(x[2]-x[1])&& (1l*(y[2]-y[1])*(x[0]-x[2])== 1l*(y[0]-y[2])*(x[2]-x[1])))
			{
				checked4 = true ; 
			}

			if(xaxis9 || checked4)
				if(n<=6)
				{
					System.out.println("YES");
					return  ;
				}


			boolean new90 = false ;
			int x1 = 0 ; 
			int y1 = 0 ; 
			int x2 = 0 ; 
			int y2 =0 ;


			boolean new91 = false ; 


			if(xaxis9 || checked4)
			{
				for (int i = 4; i < n; i++)
				{
					if(canFit2(x[0], y[0], x[1] , y[1] ,x[i], y[i]))	
						continue ; 
					else if (new90==false)
					{
						new90 = true ; 
						x1 = x[i] ; 
						y1 = y[i] ;
					} else if (new91==false) 
					{
						new91 = true ; 
						x2 = x[i] ; 
						y2 = y[i] ; 
					} else {
						if(canFit2(x1, y1, x2, y2, x[i], y[i]))
							continue ; 
						else 
						{
							System.out.println("NO");
							return ;
						}
					}
				}
				System.out.println("YES");
				return ;


			}



			


			double m1 = 0 ; 
			double m2 = 0 ; 
			boolean xaxis1 =  false ; 
			boolean xaxis2 =  false ; 




			double m3 = 0 ; 
			double m4 = 0 ; 
			boolean xaxis3 =  false ; 
			boolean xaxis4 =  false ; 


			double m5 = 0 ; 
			double m6 = 0 ;
			boolean xaxis5 =  false ; 
			boolean xaxis6 =  false ; 


			if(x[1]==x[0])
				xaxis1=true ; 
			else 
				m1 = 1.0*(y[1]-y[0])/(x[1]-x[0]) ; 

			if(x[3]==x[2])
				xaxis2=true ; 
			else 
				m2 = 1.0*(y[3]-y[2])/(x[3]-x[2]) ; 

			

			if(x[1]==x[2])
				xaxis3=true ; 
			else 
				m3 = 1.0*(y[1]-y[2])/(x[1]-x[2]) ; 

			if(x[3]==x[0])
				xaxis4=true ; 
			else 
				m4 = 1.0*(y[3]-y[0])/(x[3]-x[0]) ; 
			


			if(x[1]==x[3])
				xaxis5=true ; 
			else 
				m5 = 1.0*(y[1]-y[3])/(x[1]-x[3]) ; 

			if(x[2]==x[0])
				xaxis6=true ; 
			else 
				m6 = 1.0*(y[2]-y[0])/(x[2]-x[0]) ; 


			boolean xaxis7 =  false ; 
			double m7 = 0.0 ; 
			boolean checked31 = false ; 





			if(x[0]==x[1] && x[1]==x[2])
				xaxis7 = true ;

			if(x[0]==x[2] && x[2]==x[3])
				xaxis7 = true ;

			if(x[0]==x[3] && x[3]==x[1])
				xaxis7 = true ;

			if(x[3]==x[1] && x[2]==x[1])
				xaxis7 = true ;



			if(n==5 && xaxis7)
			{
				System.out.println("YES");
				return ; 
			}

			if(  1l*(y[2]-y[1])*(x[3]-x[2]) == 1l*(y[3]-y[2])*(x[2]-x[1]))
			{
				m7 = 1.0*(y[3]-y[2])/(x[3]-x[2]) ; 
				checked31= true ; 
				if(n==5)
				{
					System.out.println("YES");
					return ; 
				}
			}

			if(  1l*(y[2]-y[0])*(x[3]-x[2]) == 1l*(y[3]-y[2])*(x[2]-x[0]))
			{
				m7 = 1.0*(y[3]-y[2])/(x[3]-x[2]) ; 
				checked31= true ; 
				if(n==5)
				{
					System.out.println("YES");
					return ; 
				}
			}

			if(  1l*(y[0]-y[1])*(x[3]-x[0]) == 1l*(y[3]-y[0])*(x[0]-x[1]))
			{
				m7 = 1.0*(y[3]-y[1])/(x[3]-x[1]) ; 
				checked31= true ;
				if(n==5)
				{
					System.out.println("YES");
					return ; 
				}
			}

			if( 1l*(y[2]-y[1])*(x[0]-x[2]) == 1l*(y[0]-y[2])*(x[2]-x[1]))
			{
				m7 = 1.0*(y[2]-y[1])/(x[2]-x[1]) ; 
				checked31 = true ;
				if(n==5)
				{
					System.out.println("YES");
					return ; 
				}
			}


			int xc =0 ; 

			if(xaxis7)
			{


				if(x[0]==x[1] && x[1]==x[2])
					xc = 3 ;
				else if(x[3]==x[1] && x[1]==x[2])
					xc = 0 ;
				else if(x[0]==x[3] && x[3]==x[2])
					xc = 1 ;
				else 
					xc = 2 ; 

			}
			if(checked31)
			{
				if(  1l*(y[2]-y[1])*(x[0]-x[2]) == 1l*(y[0]-y[2])*(x[2]-x[1]))
					xc = 3 ; 
				else if(  1l*(y[0]-y[1])*(x[3]-x[0]) == 1l*(y[3]-y[0])*(x[0]-x[1]))
					xc = 2 ; 
				else if(  1l*(y[2]-y[1])*(x[3]-x[2]) == 1l*(y[3]-y[2])*(x[2]-x[1]))
					xc =0 ;
				else 
					xc =1 ; 

			}

			boolean new8 = false ; 
			boolean  xaxis8 =  false ; 
			double m8 = 0.0 ; 



			if(xaxis7 || checked31)
			{
				for (int i = 4; i < n; i++)
				{
					if(canFit2(x[(xc+1)%4], y[(xc+1)%4], x[(xc+2)%4], y[(xc+2)%4], x[i], y[i]))
						continue ; 
					else if(new8==false)
					{
						new8=true ; 
						x2 = x[i] ; 
						y2 = y[i] ; 

					}else {
						if(canFit2(x[xc], y[xc], x2, y2, x[i], y[i]))
							continue ;
						else 
						{
							System.out.println("NO");
							return ; 
						}
					}
				}
				System.out.println("YES");
				return ;
			}






			


			boolean cannotUse1 =  false  ; 
			boolean cannotUse2 =  false  ; 
			boolean cannotUse3 =  false  ; 

			if (!canFit2(x[0], y[0], x[1], y[1], x[4], y[4]) && !canFit2(x[2], y[2], x[3], y[3], x[4], y[4]))
				cannotUse1= true ;

			if (!canFit2(x[0], y[0], x[3], y[3], x[4], y[4]) && !canFit2(x[2], y[2], x[1], y[1], x[4], y[4]))
				cannotUse2= true ;
			if (!canFit2(x[0], y[0], x[2], y[2], x[4], y[4]) && !canFit2(x[3], y[3], x[1], y[1], x[4], y[4]))
				cannotUse3= true ;







			if(cannotUse1&& cannotUse2 && cannotUse3)
			{
				System.out.println("NO");
				return ; 
			}

			for (int i = 5; i < n; i++)
			{
				if(cannotUse1==false)
					if (!canFit2(x[0], y[0], x[1], y[1], x[i], y[i]) && !canFit2(x[2], y[2], x[3], y[3], x[i], y[i]))	
						cannotUse1= true ;

				if(cannotUse2==false)
					if (!canFit2(x[0], y[0], x[3], y[3], x[i], y[i]) && !canFit2(x[2], y[2], x[1], y[1], x[i], y[i]))
						cannotUse2= true ;

				if(cannotUse3==false)
					if (!canFit2(x[0], y[0], x[2], y[2], x[i], y[i]) && !canFit2(x[3], y[3], x[1], y[1], x[i], y[i]))
						cannotUse3= true ;

				if(cannotUse1&& cannotUse2 && cannotUse3)
				{
					System.out.println("NO");
					return ; 
				}
			}

			System.out.println("YES");







		}
		



		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		public static boolean canFit2(int x1, int y1 , int x2 , int y2 , int x3 , int y3){
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
		private static int gcdThing(long a, long b) {
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
		public static long getPrimes(long x ){
			if(x==2 || x==3 || x==1)
				return 2 ;
			if(isPrime(x))
				return 5 ;
			for (int i = 2; i*i<=x; i++)
			{
				if(x%i==0 && isPrime(i))
					return getPrimes(x/i) ;
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

		public Vertix(int i){
			this.i = i ;
			this.neighbours = new ArrayList<Vertix> () ;
			this.parent = null ;
			depth =-1;
		}
	}

	public static class pair implements Comparable<pair>{
		int x ;  

		int y ;  



		public pair(int x, int y){
			this.x=x ; 
			this.y=y ;

		}

		@Override
		public int compareTo(pair p) {
			if(this.x > p.x)
				return 1 ; 
			else if(this.x== p.x)
			{
				if(this.y >= p.y)
					return 1 ;
				else 
					return -1 ;
			}
			else return -1 ;


		}


	}


}