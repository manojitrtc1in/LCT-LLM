import java.util.*;
import java.io.*;
import java.util.Arrays;



public class codeforces {
	static long[]fac=new long[200100];
	static long[] two= new long[200100] ;
	static long mod=((int)1e9)+9;
	static int n,m;
	static long[][] memo1,memo2;
	static boolean[][]vist1,vist2;
	static char[][]grid1,grid2;
	public static void main(String[] args) throws IOException {
		int t=sc.nextInt();
		while(t-->0) {
			int W=sc.nextInt();
			int H=sc.nextInt();
			Pair p1=new Pair(sc.nextLong(), sc.nextLong());
			Pair p2= new Pair(sc.nextLong(), sc.nextLong());
			long maxw=Math.max(p1.x, W-p2.x);
			long maxh=Math.max(p1.y, H-p2.y);
			long w=sc.nextLong();
			long h=sc.nextLong();
			long diffw=w-maxw>=0?w-maxw:0;
			long diffh=h-maxh>=0?h-maxh:0;
			long minw=Math.min(p1.x, W-p2.x);
			long minh=Math.min(p1.y, H-p2.y);
			if(minw+maxw>=w) {
				if(minh+maxh>=h)pw.println(Math.min(diffh, diffw));
				else pw.println(diffw);
			}else if(minh+maxh>=h){
				pw.println(diffh);
			}else {
				pw.println(-1);
			}
		}
		pw.close();
	}
	
	public static boolean help(int i,int j) {
		if(i==n-1&&j==m-1) {
			return true;
		}
		boolean up=false,down=false,right=false,left=false;
		
		long min=memo1[i][j]-1;
		vist2[i][j]=true;
		if(i>0&&memo1[i-1][j]==min&&grid2[i-1][j]=='.'&&!vist2[i-1][j]) {
			up=help(i-1, j);
		}
		if(i<n-1&&memo1[i+1][j]==min&&grid2[i+1][j]=='.'&&!vist2[i+1][j]) {
			down=help(i+1, j);
		}
		if(j<m-1&&memo1[i][j+1]==min&&grid2[i][j+1]=='.'&&!vist2[i][j+1]) {
			right=help(i, j+1);
		}
		if(j>0&&memo1[i][j-1]==min&&grid2[i][j-1]=='.'&&!vist2[i][j-1]) {
			left=help(i, j-1);
		}	
		vist2[i][j]=false;
		return up||down||left||right;
	}
	
	public static long shortest(int i,int j) {
		if(i==n-1&&j==m-1)return memo1[i][j]=0;
		if(memo1[i][j]!=-1&&memo1[i][j]!=Integer.MAX_VALUE) {
			return memo1[i][j];
		}
		long up=Integer.MAX_VALUE;
		long down=Integer.MAX_VALUE;
		long right=Integer.MAX_VALUE;
		long left=Integer.MAX_VALUE;
		vist1[i][j]=true;
		if(i<n-1&&vist1[i+1][j]!=true&&grid1[i+1][j]=='.') {
			down=1+shortest(i+1, j);
			if(up==n-i+m-j-2)return memo1[i][j]=down;
		}
		if(j<m-1&&vist1[i][j+1]!=true&&grid1[i][j+1]=='.') {
			right =1+ shortest(i, j+1);
			if(up==n-i+m-j-2)return memo1[i][j]=right;
		}
		if(i>0&&vist1[i-1][j]!=true&&grid1[i-1][j]=='.') {
			up=1+shortest(i-1,j);
			if(up==n-i+m-j-2)return memo1[i][j]=up;
		}
		if(j>0&&vist1[i][j-1]!=true&&grid1[i][j-1]=='.') {
			left=1+shortest(i, j-1);
			if(up==n-i+m-j-2)return memo1[i][j]=left;
		}
		vist1[i][j]=false;
		long ans =Math.min(up, down);
		ans=Math.min(left, ans);
		ans=Math.min(ans, right);
		return memo1[i][j]=ans;
		
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
	
	public static boolean id11(String s) {
		int l=0;
		int r=s.length()-1;
		while(l<r) {
			if(s.charAt(r--)!=s.charAt(l++))return false;
			
		}
		return true;
	}
	 
	public static String id1(String s,char c) {
		if(s.length()==0)return s;
		if(s.charAt(s.length()-1)==c) {
			return s.charAt(s.length()-1)+id1(s.substring(0,s.length()-1), c);
		}else {
			return id1(s.substring(0,s.length()-1), c)+s.charAt(s.length()-1);
		}
	}
	
	public static boolean id2(String s,String t) {
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
	
	public static boolean isPrime(int n)
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
	static void id3(long[] arr,long[]idx,int b,int e) {
		if(b<e) {
			int m=b+(e-b)/2;
			id3(arr,idx,b,m);
			id3(arr,idx,m+1,e);
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
			if(l[i]<r[j]) {
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
	static void id9(int[] arr,int b,int e) {
		if(b<e) {
			int m=b+(e-b)/2;
			id9(arr,b,m);
			id9(arr,m+1,e);
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
	static long id8(int[] arr,int b,int e) {
		long c=0;
		if(b<e) {
			int m=b+(e-b)/2;
			c=c+(long)id8(arr,b,m);
			c=c+(long)id8(arr,m+1,e);
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
	
	public  static ArrayList<Integer> id10(int n){
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

	
	public static void id4(Integer[][]a){
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
		public int[] id7(int size) throws IOException {
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
		public int[][] id5(int rows,int columns) throws IOException{
			int[][]a=new int[rows][columns];
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					a[i][j]=sc.nextInt();
				}
			}
			return a;
		}
		public long[][] id6(int rows,int columns) throws IOException{
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
	}
	static Scanner sc=new Scanner(System.in);
	static PrintWriter pw=new PrintWriter(System.out);
}