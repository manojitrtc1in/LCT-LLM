import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;


public class Main {

	static boolean visited[] ; 
	static boolean ends[] ;
	static long mod = 1000000007 ;
	static int lens[] ; 
	static int seeds[] ; 
	static int a[] ;
	static double total ; 
	public static ArrayList adj[] ; 
	public static void main(String[] args) throws IOException, InterruptedException {
		Scanner sc =  new Scanner(System.in) ;
		int k = sc.nextInt() ; 
		int n = sc.nextInt() ; 
		int a[]=  new int[k]; 
		int cuma[]= new int[k] ; 
		int b[] = new int[n]; 
		for (int i = 0; i < a.length; i++)
		{
			a[i] = sc.nextInt() ; 
		}
		cuma[0]=a[0];
		for (int i = 1; i < k; i++)
		{
			cuma[i] = a[i]+cuma[i-1];
		}

		HashMap<Integer,Integer> h = new HashMap<Integer,Integer>() ; 

		HashMap<Integer,Integer> y = new HashMap<Integer,Integer>() ; 
		ArrayList<Integer> possibleX = new ArrayList<Integer>() ; 

		for (int i = 0; i < n; i++)
		{
			b[i]=sc.nextInt() ;
		}

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		



		y = new HashMap<Integer,Integer>() ; 
		h = new HashMap<Integer , Integer>() ;

		for (int i = 0; i < k; i++)
		{
			int x = b[0]-cuma[i]; 
			if(!y.containsKey(x))
			{y.put(x,0) ; possibleX.add(x);}
		}

		int d=0 ;
		for (int i = 0; i <possibleX.size(); i++)
		{
			for (int l = 0; l < k; l++)
			{
				h.put(possibleX.get(i)+cuma[l], 0);
			}
			int taken =0 ;
			for (int l = 0; l < b.length; l++)
			{
				if(h.containsKey(b[l]))
					taken++; 
			}
			if(taken==n )
				d++;
			h = new HashMap<Integer , Integer>() ;
		}


		System.out.println(d);






	}

	static int even(String x , int b )
	{
		for (int j = b; j>=0; j--)
		{
			int current = x.charAt(j)-48 ; 
			if(current%2==0)
				return current ; 
		}
		return -1;
	}
	static int odd(String x , int b )
	{
		for (int j = b; j>=0; j--)
		{
			int current = x.charAt(j)-48 ; 
			if(current%2!=0)
				return current ; 
		}
		return -1;
	}
	static long pow(long base, int exp) {
		long res = 1;
		while(exp > 0) {
			if(exp % 2 == 1) {
				res = (res * base) % mod;
			}

			base = (base * base) % mod;
			exp /= 2;
		}

		return res;
	}
	public static long solve(int k1, long k2)
	{
		long x   = 1l*k2*(pow(2, k1)-1) ;
		return x%(1000000007) ; 
	}


	public static long getN(long x)
	{
		long n = (long) Math.sqrt(x*2) ; 
		long y = n*(n+1)/2; 
		if(y==x)
			return n ; 
		else if(y>x)
			return n ; 
		else
			for (long i = n; ; i++)
			{
				y = i*(i+1)/2 ; 
				if(y>=x)
					return i ; 


			}	}








	public static void dfss(int root , int len)
	{
		visited[root]=true ; 
		if(ends[root] && root!=0) lens[root] = len ; 

		for (int i = 0; i < adj[root].size(); i++)
		{
			int c= (int) adj[root].get(i) ; 
			if(visited[c]==false)
				dfss(c, len+1);
		}
	}

	public static void pr(int root ,  int seed){
		visited[root] = true ;
		int dv = adj[root].size()-1 ; 
		if(root==0) dv++ ;

		for (int i = 0; i < adj[root].size(); i++)
		{
			int c = (int)adj[root].get(i) ; 
			seeds[c]=dv*seed ;
		}

		for (int i = 0; i < adj[root].size() ; i++)
		{
			int c = (int)adj[root].get(i) ; 
			if(visited[c]==false)
				pr(c , seeds[c]);

		}

	}


	public static String concatinate(String s ,int n)
	{
		if(s.length()==n)
			return s ; 
		else return concatinate("0"+s, n) ;
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


	public static long getGCD(long n1, long n2) {
		if (n2 == 0) {
			return n1;
		}
		return getGCD(n2, n1 % n2);
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
	public static void shuffle(long[] a2){
		if(a2.length==1)
			return ; 
		for (int i = 0; i < a2.length; i++)
		{
			Random rand = new Random();

			int  n = rand.nextInt(a2.length-1) + 0;

			long temp = a2[i] ; 
			a2[i] = a2[n] ; 
			a2[n] = temp ;
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
	public static String solve11(String x){

		int n = x.length() ; 
		String y = "" ;
		for (int i = 0; i < n-2; i+=2)
		{
			if(ifPalindrome(x.substring(i, i+2)))
				y+= x.substring(i, i+2) ;
			else 
				break ;
		}
		return y+ solve11(x.substring(y.length(),x.length())) ;

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
	

	

	

	

	

	

	

	

	

	

	

	

	

	public static int lis( int[]a , int n){
		int lis[] = new int[n] ; 
		Arrays.fill(lis,1) ; 

		for(int i=1;i<n;i++)
			for(int j=0 ; j<i; j++)
				if (a[i]>a[j] &&  lis[i] < lis[j]+1)   
					lis[i] = lis[j] + 1;           

		int max = lis[0];

		for(int i=1; i<n ; i++)
			if (max < lis[i])
				max = lis[i] ;
		return (max);

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

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
		int index ;
		long value ;





		public pair(int x, long s ){

			this.index=x ; 
			this.value = s;

		}


		@Override
		public int compareTo(pair p) {
			if(this.value > p.value)
				return 1 ; 
			else if (this.value == p.value) 
				return 0 ;
			else 
				return -1 ;
		}




	}

	public static class pair2 implements Comparable<pair2>{
		int i ; 
		int j ;
		int plus ;

		public pair2(int i , int j , int plus){
			this.i =i ;
			this.j = j ; 
			this.plus = plus ;
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