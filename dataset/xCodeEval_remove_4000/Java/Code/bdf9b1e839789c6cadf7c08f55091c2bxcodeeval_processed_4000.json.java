import java.util.*;
import java.io.*;
import java.math.*;
public class smack {
	InputStream is;
	PrintWriter out;
	int dx[]= {1,-1,-1,1,0,0,1,-1},dy[]={1,1,-1,-1,+1,-1,0,0};
	static long mod=pow(10,9)+7;
	void solve()
	{
		int n=ni();
		int m=ni();
		int q=ni();
		long a[]=new long[n];
		for(int i=0;i<n;i++)
			a[i]=nl();
		long b[]=new long[m];
		for(int i=0;i<m;i++)
			b[i]=nl();
		long t1[]=new long[n];
		long t2[]=new long[n];
		for(int i=0,j=0,k=0;i<n;i++)
		{
			if(i%2==0)
				t1[j++]=a[i];
			else
				t2[k++]=a[i];
		}
		id3 stplus=new id3(t1);
		id3 stminus=new id3(t2);
		TreeSet<Long> ts=new TreeSet<Long>();
		long sum=0;
		for(int i=0;i<n;i++)
		{
			if(i%2==0)
				sum+=b[i];
			else
				sum-=b[i];
		}
		ts.add(sum);
		for(int i=2;i<m-n+1;i+=2)
		{
			sum+=b[i-1];
			sum-=b[i-2];
			if((i+n-1)%2==0)
				sum+=b[i+n-1];
			else
				sum-=b[i+n-1];
			if((i+n-2)%2==0)
				sum+=b[i+n-2];
			else
				sum-=b[i+n-2];
			ts.add(sum);
		}
		sum=0;
		if(m>n) {
			for(int i=1;i<n+1;i++)
			{
				if(i%2==1)
					sum+=b[i];
				else
					sum-=b[i];
			}
			ts.add(sum);
			for(int i=3;i<m-n+1;i+=2)
			{
				sum+=b[i-1];
				sum-=b[i-2];
				if((i+n-1)%2==1)
					sum+=b[i+n-1];
				else
					sum-=b[i+n-1];
				if((i+n-2)%2==1)
					sum+=b[i+n-2];
				else
					sum-=b[i+n-2];
				ts.add(sum);
			}
		}
		q++;
		int l=0;
		int r=0;
		long x=0;
		while(q--!=0)
		{
			int lplus=0,rplus=0;
			if(l%2==0)
				lplus=l/2;
			else
				lplus=(l+1)/2;
			if(r%2==0)
				rplus=r/2;
			else
				rplus=(r-1)/2;
			int rminus=0,lminus=l/2;
			if(r%2==1)
				rminus=r/2;
			else
				rminus=(r-1)/2;
		

			if(lplus<=rplus)
				stplus.update(lplus,rplus,x);
			if(lminus<=rminus&&r!=0)
				stminus.update(lminus,rminus,x);
			long total=stplus.get(0,n-1)-stminus.get(0,n-1);
			Long floor=ts.floor(total);
			Long ceil=ts.ceiling(total);
			long min=Long.MAX_VALUE;
			if(floor!=null)
				min=Math.abs(floor-total);
			if(ceil!=null)
				min=Math.min(min,Math.abs(ceil-total));
			out.println(min);
			if(q!=0) {
			l=ni()-1;
			r=ni()-1;
			x=nl();
			}
		}
	}
	static class id3{
		long arr[], st[],lazy[];
		int size;
		id3(long a[]){
			arr = a.clone();
			size = arr.length-1;
			st = new long[4*(size+1)+1];
			lazy=new long[4*(size+1)+1];
			build(0,0,size);
		}
		long merge(long a,long b)
		{
			return a+b;
		}
		void build(int n, int l, int r){
			if(l==r){
				st[n] = arr[l];
				return;
			}
			int mid = (l+r)/2;
			build(2*n+1,l,mid); build(2*n+2,mid+1,r);				
			st[n]=merge(st[2*n+1], st[2*n+2]);
		}
		long get(int ql,int qr)
		{
			return get(0,0,size,ql,qr);
		}
		long get(int n,int l,int r,int ql,int qr){
			if(ql>r || qr<l || l>r) return 0;
			if(ql<=l&&qr>=r) return st[n];
			int mid = (l+r)/2;
			return merge(get(2*n+1,l,mid,ql,qr), get(2*n+2,mid+1,r,ql,qr));
		}
		void update(int index,int dx)
		{
			update(0,0,size,index,dx);
		}
		void update(int n,int l,int r,int index,int dx)
		{
			if(l==r)
			{
				st[n]+=dx;
				arr[l]+=dx;
				return;
			}
			int mid=(l+r)/2;
			if(index<=mid)
				update(2*n+1,l,mid,index,dx);	
			else
				update(2*n+2,mid+1,r,index,dx);
			st[n]=merge(st[2*n+1],st[2*n+2]);
		}
		void update(int ul,int ur,long dx)
		{
			update(0,0,size,ul,ur,dx);
		}
		void update(int n,int l,int r,int ul,int ur,long dx)
		{
			if(lazy[n]!=0)
			{
				st[n]+=(r-l+1)*lazy[n];
				if(l!=r)
				{
					lazy[2*n+1]+=lazy[n];
					lazy[2*n+2]+=lazy[n];
				}
				lazy[n]=0;
			}
			if(ul>r||ur<l)
				return;
			if(ul<=l&&ur>=r)
			{
				st[n]+=(r-l+1)*dx;
				if(l!=r)
				{
					lazy[2*n+1]+=dx;
					lazy[2*n+2]+=dx;
				}
				else
					arr[l]+=dx;
				return;
			}
			int mid=(l+r)/2;
			update(2*n+1,l,mid,ul,ur,dx);
			update(2*n+2,mid+1,r,ul,ur,dx);
			st[n]=merge(st[2*n+1],st[2*n+2]);
		}
		long rangeq(int ql,int qr)
		{
			return rangeq(0,0,size,ql,qr);
		}
		long rangeq(int n,int l,int r,int ql,int qr)
		{
			if(lazy[n]!=0)
			{
				st[n]+=(r-l+1)*lazy[n];
				if(l!=r)
				{
					lazy[2*n+1]+=lazy[n];
					lazy[2*n+2]+=lazy[n];
				}
				lazy[n]=0;
			}
			if(ql>r||qr<l)
				return 0;
			if(ql<=l&&qr>=r)
				return st[n];
			int mid=(l+r)/2;
			return merge(rangeq(2*n+1,l,mid,ql,qr),rangeq(2*n+2,mid+1,r,ql,qr));
		}
	}
	static long d, x, y;
	void id2(long A, long B) {
	    if(B == 0) {
	        d = A;
	        x = 1;
	        y = 0;
	    }
	    else {
	        id2(B, A%B);
	        long temp = x;
	        x = y;
	        y = temp - (A/B)*y;
	    }
	}
	long modInverse(long A,long M) 

	{
	    id2(A,M);
	    return (x%M+M)%M;    

	}
	public static void mergeSort(int[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(int arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		int left[] = new int[n1];
		int right[] = new int[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	public static void mergeSort(long[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(long arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		long left[] = new long[n1];
		long right[] = new long[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	 static class Pair implements Comparable<Pair>{
		 
	       int x,y,k;
	       int i,dir;
	       long cost;
		Pair (int x,int y){
			this.x=x;
			this.y=y;
		}   
		public int compareTo(Pair o) {
				return this.y-o.y;
		}
	 
		public String toString(){
			return x+" "+y+" "+k+" "+i;}
		public boolean equals(Object o) {
			if (o instanceof Pair) {
				Pair p = (Pair)o;
				return p.x == x && p.y == y;
			}
			return false;
		}
		public int hashCode() {
			return new Long(y).hashCode()*31 + new Long(x).hashCode() ;
		}
	} 
	    public static boolean isPal(String s){
	        for(int i=0, j=s.length()-1;i<=j;i++,j--){
	                if(s.charAt(i)!=s.charAt(j)) return false;
	        }
	        return true;
	    }
	    public static String rev(String s){
			StringBuilder sb=new StringBuilder(s);
			sb.reverse();
			return sb.toString();
	    }
	    
	    public static long gcd(long x,long y){
		if(x%y==0)
			return y;
		else
			return gcd(y,x%y);
	    }
	    
	    public static int gcd(int x,int y){
		if(x%y==0)
			return y;
		else 
			return gcd(y,x%y);
	    }
	    
	    public static long id1(long a,long b,long[] x){
	        
	        if(a==0){
	            x[0]=0;
	            x[1]=1;
	            return b;
	        }
	        long[] y=new long[2];
	        long gcd=id1(b%a, a, y);
	        
	        x[0]=y[1]-(b/a)*y[0];
	        x[1]=y[0];
	        
	        return gcd;
	    }
	    
	    public static int abs(int a,int b){
		return (int)Math.abs(a-b);
	    }
	 
	    public static long abs(long a,long b){
		return (long)Math.abs(a-b);
	    }
	    
	    public static int max(int a,int b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static int min(int a,int b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	    
	    public static long max(long a,long b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static long min(long a,long b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	 
	    public static long pow(long n,long p,long m){
		 long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;
		    if(result>=m)
		    result%=m;
		    p >>=1;
		    n*=n;
		    if(n>=m)
		    n%=m;
		}
		return result;
	    }
	    
	    public static long pow(long n,long p){
		long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;	    
		    p >>=1;
		    n*=n;	    
		}
		return result;
	    }
	    public static void debug(Object... o) {
			System.out.println(Arrays.deepToString(o));
		}
	    void run() throws Exception {
			is = System.in;
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		}
	   
	    public static void main(String[] args) throws Exception {
			new Thread(null, new Runnable() {
				public void run() {
					try {
						new smack().run();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}, "1", 1 << 26).start();
		}
	    private byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;
	 
		private int readByte() {
			if (lenbuf == -1)
				throw new InputMismatchException();
			if (ptrbuf >= lenbuf) {
				ptrbuf = 0;
				try {
					lenbuf = is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}
	 
		private boolean id0(int c) {
			return !(c >= 33 && c <= 126);
		}
	 
		private int skip() {
			int b;
			while ((b = readByte()) != -1 && id0(b));
			return b;
		}
	 
		private double nd() {
			return Double.parseDouble(ns());
		}
	 
		private char nc() {
			return (char) skip();
		}
	 
		private String ns() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(id0(b))) { 

				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
	 
		private char[] ns(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(id0(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
	 
		private char[][] nm(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns(m);
			return map;
		}
	 
		private int[] na(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = ni();
			return a;
		}
	 
		private int ni() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
		private long nl() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
}