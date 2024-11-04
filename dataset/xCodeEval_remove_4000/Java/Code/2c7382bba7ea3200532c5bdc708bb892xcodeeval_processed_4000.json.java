import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	static long[]fac=new long[200100];
	static long[] two= new long[200100] ;
	static long mod=Long.MAX_VALUE;
	static String[]pow=new String[63];
	static int n;
	static int x=0;
	static int[][]perm,b;
	static int[]pe,aa,a;
	static boolean fff=false;
	static String out="";
	static HashMap<String, String>vars=new HashMap<String, String>();
	static int[]prime=new int[(int)1e5+100];
	static TreeSet<Long>p=new TreeSet<Long>();
	public static void main(String[] args) throws IOException, InterruptedException{
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int[]a=sc.id6(n);
			int[]b=sc.id6(n);
			sort(a);
			sort(b);
			boolean f=true;
			for (int i = 0; i < b.length; i++) {
				if(b[i]<a[i]) {
					f=false;
					break;
				}else {
					if(b[i]-a[i]>1) {
						f=false;
						break;
					}
				}
			}
			pw.println(f?"YES":"NO");
		}
		pw.close();
	}	
	
	public static int divNum(int n) {
		int total = 1;
		
		while(n>1) {
			int p=prime[n];
			int count =1;
			while(n%p==0) {
				n/=p;
				count++;
			}
			total*=count;
		}
	    
	    return total;
	}
	
	public static void sieve() {
		for (int i = 2; i < prime.length; i++) {
			if(prime[i]==0) {
				p.add((long)i);
				for (int j = i; j < prime.length; j+=i) {
					if(prime[j]==0)prime[j]=i;
				}
			}
		}
	}
	
	public static long[] Extended(long p, long q) {
	      if (q == 0)
	         return new long[] { p, 1, 0 };

	      long[] vals = Extended(q, p % q);
	      long d = vals[0];
	      long a = vals[2];
	      long b = vals[1] - (p / q) * vals[2];
	      return new long[] { d, a, b };
	   }
	
	static class STree{
		int N;
		long[]arr;
		long[]tree;
		int[]lazy;
		long id;
		public static long operation(long x,long y) {
			return x^y;
		}
		
		public STree(int[]a,long id) {
			this.id=id;
			N=1;
			int n=a.length;
			while(N<n) {
				N*=2;
			}
			arr=new long[N+1];
			Arrays.fill(arr, id);
			for (int i = 1; i <= a.length; i++) {
				arr[i]=a[i-1];
			}
			tree=new long[2*N];
			Arrays.fill(tree, id);
			build(1,N,1);
			lazy=new int[2*N];
		}
		
		public void build(int l,int r,int node) {
			if(l==r) {
				tree[node]=arr[l];
				return;
			}
			int mid=(l+r)/2;
			build(l,mid,node*2);
			build(mid+1,r,node*2+1);
			tree[node]=operation(tree[node*2],tree[node*2+1]);
		}
		




































































		public long q(int l,int r) {
			return q(1,N,l,r,1);
		}
		
		public long q(int s,int e,int l,int r,int node) {
			if(s>=l&&r>=e) {
				return tree[node];
			}
			if(s>r||e<l)
				return id;
			int mid=(s+e)/2;
			
			return operation(q(s,mid,l,r,node*2), q(mid+1,e,l,r,node*2+1));
		}
























	}

	public static class segment{
		long sum;
		int[] bit;
		
		public segment (long sum,int[]bit) {
			this.sum=sum;
			this.bit=bit.clone();
		}
		
		@Override
		public String toString() {
			return sum+" "+Arrays.toString(bit);
		}
	}
	
	public static int LIS(int[] a) {

		int n = a.length;
		int[] ser = new int[n];
		int[]ser1=new int[n];
		Arrays.fill(ser1, Integer.MAX_VALUE);
		Arrays.fill(ser, Integer.MAX_VALUE);
		int cur = -1;
		int[]inc=new int[n];
		int[]dec=new int[n];
		for (int i = 0; i < n; i++) {
			int low = 0;
			int high = n - 1;
			int mid = (low + high) / 2;
			while (low <= high) {
				if (ser[mid] < a[i]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
				mid = (low + high) / 2;
			}
			inc[i]=high+2;
			cur = Math.max(cur, high + 1);
			ser[high + 1] = Math.min(ser[high + 1], a[i]);
		}
		for (int i = n-1; i >= 0; i--) {
			int low = 0;
			int high = n - 1;
			int mid = (low + high) / 2;
			while (low <= high) {
				if (ser1[mid] < a[i]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
				mid = (low + high) / 2;
			}
			dec[i]=high+2;
			cur = Math.max(cur, high + 1);
			ser1[high + 1] = Math.min(ser1[high + 1], a[i]);
		}
		int ans=1;
		for (int i = 0; i < dec.length; i++) {
			ans=Math.max(ans, 2*Math.min(inc[i], dec[i])-1);
		}
		return ans;
	}
	
	
	public static void permutation(int idx,int v) {
		if(v==(1<<n)-1) {
			perm[x++]=pe.clone();
			return ;
		}
		for (int i = 0; i < n; i++) {
			if((v&1<<i)==0) {
				pe[idx]=aa[i];
				permutation(idx+1, v|1<<i);
			}
		}
		return ;
	}
	
	public static void pre2() {
		for (int i = 0; i < pow.length; i++) {
			long x=1l<<i;
			pow[i]=x+"";
		}
	}
		
	public static void sort(int[]a) {
		id8(a, 0, a.length-1);
	}
	
	public static void sortIdx(long[]a,long[]idx) {
		id2(a, idx, 0, a.length-1);
	}
	
	public static long C(int a,int b) {
		long x=fac[a];
		long y=fac[a-b]*fac[b];
		return x*pow(y,mod-2)%mod;
	}
	
	public static long pow(long a,long b) {
		long ans=1;a%=mod;
		for(long i=b;i>0;i/=2) {
			if((i&1)!=0)
				ans=ans*a%mod;
			a=a*a%mod;
		 }    
		    
		 return ans;
	}
	
	public static void pre(){
		fac[0]=1;
		fac[1]=1;
		fac[2]=1;
		for (int i = 3; i < fac.length; i++) {
			fac[i]=((fac[i-1]*2*i)/2)%mod;
		}
	}
	
	public static long eval(String s) {
		long p=1;
		long res=0;
		for (int i = 0; i < s.length(); i++) {
			res+=p*(s.charAt(s.length()-1-i)=='1'?1:0);
			p*=2;
		}
		return res;
	}
	
	public static String binary(long x) {
		String s="";
		while(x!=0) {
			s=(x%2)+s;
			x/=2;
		}
		return s;
	}
	
	public static boolean allSame(String s) {
		char x=s.charAt(0);
		for (int i = 0; i < s.length(); i++) {
			if(s.charAt(i)!=x)return false;
		}
		return true;
	}
	
	public static boolean id10(String s) {
		int l=0;
		int r=s.length()-1;
		while(l<r) {
			if(s.charAt(r--)!=s.charAt(l++))return false;
			
		}
		return true;
	}
	 
	
	public static boolean id1(String s,String t) {
		int ls=s.length();
		int lt=t.length();
		boolean res=false;
		for (int i = 0; i <=lt-ls; i++) {
			if(t.substring(i, i+ls).equals(s)) {
				res=true;
				break;
			}
		}
		return res;
	}
	
	public static boolean isSorted(long[]a) {
		for (int i = 0; i < a.length-1; i++) {
			if(a[i]>a[i+1])return false;
		}
		return true;
	}
	
	public static boolean isPrime(long n)
    {
 
        

        

        if (n <= 1)
            return false;
 
        

        else if (n == 2)
            return true;
 
        

        else if (n % 2 == 0)
            return false;
 
        

        for (int i = 3; i <= Math.sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
	public static int whichPower(int x) {
		int res=0;
		for (int j = 0; j < 31; j++) {
			if((1<<j&x)!=0) {
				res=j;
				break;
			}
		}
		return res;
	}
 
	public static long evaln(String x,int n) {
		long res=0;
		for (int i = 0; i < x.length(); i++) {
			res+=Long.parseLong(x.charAt(x.length()-1-i)+"")*Math.pow(n, i);
		}
		return res;
	}
	static void merge(int[] arr,int b,int m,int e) {
		int len1=m-b+1,len2=e-m;
		int[] l=new int[len1];
		int[] r=new int[len2];
		for(int i=0;i<len1;i++)l[i]=arr[b+i];
		for(int i=0;i<len2;i++)r[i]=arr[m+1+i];
		int i=0,j=0,k=b;
		while(i<len1 && j<len2) {
			if(l[i]<r[j])arr[k++]=l[i++];
			else arr[k++]=r[j++];
		}
		while(i<len1)arr[k++]=l[i++];
		while(j<len2)arr[k++]=r[j++];
		return;
	}
	static void id2(long[] arr,long[]idx,int b,int e) {
		if(b<e) {
			int m=b+(e-b)/2;
			id2(arr,idx,b,m);
			id2(arr,idx,m+1,e);
			mergeidx(arr,idx,b,m,e);
		}
		return;
		
	}
	static void mergeidx(long[] arr,long[]idx,int b,int m,int e) {
		int len1=m-b+1,len2=e-m;
		long[] l=new long[len1];
		long[] lidx=new long[len1];
		long[] r=new long[len2];
		long[] ridx=new long[len2];
		for(int i=0;i<len1;i++) {
			l[i]=arr[b+i];
			lidx[i]=idx[b+i];
		}
		for(int i=0;i<len2;i++) {
			r[i]=arr[m+1+i];
			ridx[i]=idx[m+1+i];
		}
		int i=0,j=0,k=b;
		while(i<len1 && j<len2) {
			if(l[i]<=r[j]) {
				arr[k++]=l[i++];
				idx[k-1]=lidx[i-1];
			}
			else {
				arr[k++]=r[j++];
				idx[k-1]=ridx[j-1];
			}
		}
		while(i<len1) {
			idx[k]=lidx[i];
			arr[k++]=l[i++];
		}
		while(j<len2) {
			idx[k]=ridx[j];
			arr[k++]=r[j++];
		}
		return;
	}
	static void id8(int[] arr,int b,int e) {
		if(b<e) {
			int m=b+(e-b)/2;
			id8(arr,b,m);
			id8(arr,m+1,e);
			merge(arr,b,m,e);
		}
		return;
		
	}
	
	static long mergen(int[] arr,int b,int m,int e) {
		int len1=m-b+1,len2=e-m;
		int[] l=new int[len1];
		int[] r=new int[len2];
		for(int i=0;i<len1;i++)l[i]=arr[b+i];
		for(int i=0;i<len2;i++)r[i]=arr[m+1+i];
		int i=0,j=0,k=b;
		long c=0;
		while(i<len1 && j<len2) {
			if(l[i]<r[j])arr[k++]=l[i++];
			else {
				arr[k++]=r[j++];
				c=c+(long)(len1-i);
			}
		}
		while(i<len1)arr[k++]=l[i++];
		while(j<len2)arr[k++]=r[j++];
		return c;
	}
	static long id7(int[] arr,int b,int e) {
		long c=0;
		if(b<e) {
			int m=b+(e-b)/2;
			c=c+(long)id7(arr,b,m);
			c=c+(long)id7(arr,m+1,e);
			c=c+(long)mergen(arr,b,m,e);
		}
		return c;
		
	}
	public static long fac(int n) {
		if(n==0)return 1;
		return n*fac(n-1);
	}
	public static long gcd(long a, long b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
     
	public static long summ(long x) {
		long sum=0;
		while(x!=0) {
			sum+=x%10;
			x=x/10;
		}
		return sum;
				
	}
	
	public  static ArrayList<Integer> id9(int n){
	        ArrayList<Integer>res=new ArrayList<Integer>();
	        for (int i=1; i<=Math.sqrt(n); i++)
	        {
	            if (n%i==0)
	            {
	                

	                if (n/i == i)
	                	res.add(i);
	                else {
	                	res.add(i);
	                	res.add(n/i);
	                }	
	            }
	        }
	        return res;
	    }

	
	public static void id3(Integer[][]a){
		Arrays.sort(a,Comparator.<Integer[]>comparingInt(x -> x[0]).thenComparingInt(x -> x[1]));
 
	}
	
	
	
		
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
		public Scanner(String file) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(file));
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
		public int[] id6(int size) throws IOException {
			int[] a=new int[size];
			for (int i = 0; i < a.length; i++) {
				a[i]=sc.nextInt();
			}
			return a;
		}
		public long[] id0(int size) throws IOException {
			long[] a=new long[size];
			for (int i = 0; i < a.length; i++) {
				a[i]=sc.nextLong();
			}
			return a;
		}
		public int[][] id4(int rows,int columns) throws IOException{
			int[][]a=new int[rows][columns];
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					a[i][j]=sc.nextInt();
				}
			}
			return a;
		}
		public long[][] id5(int rows,int columns) throws IOException{
			long[][]a=new long[rows][columns];
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					a[i][j]=sc.nextLong();
				}
			}
			return a;
		}
	}
	
	static class Side{
		Point a;
		Point b;
		public Side(Point a,Point b) {
			this.a=a;
			this.b=b;
		}
		@Override
		public boolean equals(Object obj) {
			Side s=(Side)obj;
			return (s.a.equals(a)&&s.b.equals(b))||(s.b.equals(a)&&s.a.equals(b));
		}
		@Override
		public String toString() {
			
			return "("+a.toString()+","+b.toString()+")";
		}
	}
	static class Point{
		int x;
		int y;
		int z;
		public Point(int x,int y,int z) {
			this.x=x;
			this.y=y;
			this.z=z;
		}
		@Override
		public boolean equals(Object obj) {
			Point p=(Point)obj;
			return x==p.x&&y==p.y&&z==p.z;
		}
		@Override
		public String toString() {
			return "("+x+","+y+","+z+")";
		}
	}
	static class Pair implements Comparable{
		long x;
		long y;
		public Pair(long x,long y) {
			this.x=x;
			this.y=y;
		}
		@Override
		public boolean equals(Object obj) {
			Pair p=(Pair)obj;
			return x==p.x&&y==p.y;
		}
		@Override
		public String toString() {
			

			return "("+x+","+y+")";
		}
		
		@Override
		public int compareTo(Object o) {
			Pair p=(Pair)o;
			return x>p.x?1:x==p.x?0:-1;
		}
	}
	static class sPair{
		String s;
		Pair p;
		public sPair(String s,Pair p) {
			this.p=p;
			this.s=s;
		}
		@Override
		public String toString() {
			

			return s+" "+p;
		}
	}
	static Scanner sc=new Scanner(System.in);
	static PrintWriter pw=new PrintWriter(System.out);
}