import java.util.*;
import java.io.*;

public class codeforces {
	static long[]fac=new long[200100];
	static long[] two= new long[200100] ;
	static long mod=((int)1e9)+7;
	static String[]pow=new String[63];
	static int[][]perm;
	static int[]pe,aa;
	static int x=0;
	static int n,r,m,w,s,h,k;
	static long[][][]memo;
	static int[]val,b,c,time;
	static String t;
	static long[][]bonus;
	static ArrayList<Pair>nuts;
	static Pair[]a;
	static HashMap<String, sv>[]hm;
	public static void main(String[] args) throws IOException{
		int t=sc.nextInt();
		while(t-->0) {
			int n=sc.nextInt();
			int m=sc.nextInt();
			long[]a=new long[m*n];
			long[]idx=new long[m*n];
			for (int i = 0; i < a.length; i++) {
				a[i]=sc.nextLong();
				idx[i]=i;
			}
			sortIdx(a, idx);
			int r=0;
			for (int i = 0; i < idx.length; i++) {
				for (int j = i+1; j < (i/m+1)*m; j++) {
					if(a[j]>a[i]&&idx[j]>idx[i])r++;
				}
			}
			pw.println(r);
		}	
		pw.close();
	}
	
	
	public static long dp(int i,int j,int k) {
		if(i==j&&j==k&&j==n)return 1;
		else if(i+j+k==3*n-1)return 0;
		if(memo[i][j][k]!=-1)return memo[i][j][k];
		long t1=0,t2=0,t3=0,t4=0,t5=0;
		if(i==j&&i<n)t1=dp(i+1,j+1,k);
		if(j==k&&j<n)t2=dp(i,j+1,k+1);
		if(i<n-1)t3=dp(i+2,j,k);
		if(j<n-1)t4=dp(i,j+2,k);
		if(k<n-1)t5=dp(i,j,k+2);
		pw.println(i+" "+" "+j+" "+k+" "+(t1+t2+t3+t4+t5));
		return memo[i][j][k]=t1+t2+t3+t4+t5;
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
	
	public static boolean reachable(double x1,double y1,double x2,double y2) {
		
		double m=(y2-y1)/(x2-x1);
		double c=y1-x1*m;
		double a=m*m+1;
		double b=2*m*c;
		c=c*c-r*r;
		double sol1=(-b+Math.sqrt(b*b-4*a*c))/(2*a);
		double sol2=(-b-Math.sqrt(b*b-4*a*c))/(2*a);
		
		return Math.abs(x2-x1)-Math.min(Math.abs(sol1-x1), Math.abs(sol2-x1))<0.00000001;
	}	
	
	public static boolean isplus1(int n) {
		return (n-1)%6==0;
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
		mergesort(a, 0, a.length-1);
	}
	
	public static void sortIdx(long[]a,long[]idx) {
		mergesortidx(a, idx, 0, a.length-1);
	}
	
	public static long C(int a,int b) {
		long x=fac[a];
		long y=fac[a-b]*fac[b];
		return x*pow2(y,mod-2)%mod;
	}
	
	public static long pow2(long a,long b) {
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
		for (int i = 1; i < fac.length; i++) {
			fac[i]=fac[i-1]*i%mod;
		}
		two[0]=1;
		for (int i = 1; i < fac.length; i++) {
			two[i]=two[i-1]*2%mod;
		}
	}
	
	static class Node{
		int x;
		Node next;
		Node previous;
		public Node(int x) {
			this.x=x;
			next=null;
			previous=null;
		}
		@Override
		public String toString() {
			return x+"";
		}
	}
	static class sv{
		public String s;
		public long v;
		public sv(String s,long v) {
			this.s=s;
			this.v=v;
		}
		
	}
	static class LinkedL{
		Node head;
		Node last;
		public LinkedL() {
			head=last=null;
		}
		public void insertLast(int k) {
			Node n=new Node(k);
			n.previous=last;
			last.next=n;
			last=n;
		}
		public void insertFirst(int k) {
			if(head==null) {
				head=last=new Node(k);
			}else {
				Node n=new Node(k);
				n.next=head;
				head.previous=n;
				head=n;
			}
		}
		@Override
		public String toString() {
			String s="";
			Node c=head;
			while(c!=null) {
				s+=c+" ";
				c=c.next;
			}	
			return s;
		}
	}
	public static long p(int n,int k) {
		long res=1;
		if(k<=n/2) {
			while(k-->0) {
				res*=n;
				n--;
			}
		}else {
			res=fac(n)/fac(n-k);
		}
		return res;
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
	
	public static boolean isPalindrom(String s) {
		int l=0;
		int r=s.length()-1;
		while(l<r) {
			if(s.charAt(r--)!=s.charAt(l++))return false;
			
		}
		return true;
	}
	 
	public static String putAtFront(String s,char c) {
		if(s.length()==0)return s;
		if(s.charAt(s.length()-1)==c) {
			return s.charAt(s.length()-1)+putAtFront(s.substring(0,s.length()-1), c);
		}else {
			return putAtFront(s.substring(0,s.length()-1), c)+s.charAt(s.length()-1);
		}
	}
	
	public static boolean isSubString(String s,String t) {
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
	
	public static boolean isSorted(int[]a) {
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
	public static long power(long x,long k) {
		long res=1;
		long mod=((int)1e9)+7;
		for (int i = 0; i < k; i++) {
			res*=x;
			res=res%mod;
		}
		return res;
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
	static void mergesortidx(long[] arr,long[]idx,int b,int e) {
		if(b<e) {
			int m=b+(e-b)/2;
			mergesortidx(arr,idx,b,m);
			mergesortidx(arr,idx,m+1,e);
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
	static void mergesort(int[] arr,int b,int e) {
		if(b<e) {
			int m=b+(e-b)/2;
			mergesort(arr,b,m);
			mergesort(arr,m+1,e);
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
	static long mergesortn(int[] arr,int b,int e) {
		long c=0;
		if(b<e) {
			int m=b+(e-b)/2;
			c=c+(long)mergesortn(arr,b,m);
			c=c+(long)mergesortn(arr,m+1,e);
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
	
	public  static ArrayList<Integer> findDivisors(int n){
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

	
	public static void sort2darray(Integer[][]a){
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
		public int[] nextArrint(int size) throws IOException {
			int[] a=new int[size];
			for (int i = 0; i < a.length; i++) {
				a[i]=sc.nextInt();
			}
			return a;
		}
		public long[] nextArrlong(int size) throws IOException {
			long[] a=new long[size];
			for (int i = 0; i < a.length; i++) {
				a[i]=sc.nextLong();
			}
			return a;
		}
		public int[][] next2dArrint(int rows,int columns) throws IOException{
			int[][]a=new int[rows][columns];
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					a[i][j]=sc.nextInt();
				}
			}
			return a;
		}
		public long[][] next2dArrlong(int rows,int columns) throws IOException{
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
	static class Pair{
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