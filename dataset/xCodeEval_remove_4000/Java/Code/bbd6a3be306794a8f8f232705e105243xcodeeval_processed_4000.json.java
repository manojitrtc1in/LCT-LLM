

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.SortedSet;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;




public class Main {
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }
    }
	
	public static void main(String[] args) {
		OutputStream outputStream =System.out;
	    PrintWriter out =new PrintWriter(outputStream);
	FastReader s=new FastReader();
	int t=s.nextInt();
	while(t>0) {
		int n=s.nextInt();
		String str=s.next();
		int count1=0;
		int count2=0;
		for(int i=0;i<n;i++) {
			if(str.charAt(i)=='1') {
				count1++;
			}else {
				count2++;
			}
		}
		if((str.charAt(0)=='0') || (str.charAt(n-1)=='0') || (count1%2!=0) ) {
			out.println("NO");
		}else {
			out.println("YES");
			char[] a=new char[n];
			char[] b=new char[n];
			int k=0;
			int i=0;
			int j=0;
			while(i<n) {
				if(str.charAt(i)=='1') {
					if(count1>0) {
					a[k]='(';
						b[k]='(';
					}else {
						a[k]=')';
						b[k]=')';
					}
					count1-=2;
				}else {
					if(j%2==0) {
						a[k]='(';
						b[k]=')';
					}else {
						a[k]=')';
						b[k]='(';
					}
					j++;
				}
				i++;
				k++;
			}
			for(int l=0;l<n;l++) {
				out.print(a[l]);
			}
			out.println();
			for(int l=0;l<n;l++) {
				out.print(b[l]);
			}
			out.println();


		}
		t--;
	}
			
		out.close();

	}
	static boolean good(long[] a,long time,int n,long t) {
		long sum=0;
		for(int i=0;i<n;i++) {
			sum+=time/a[i];
		}
		return sum>=t;
	}
	static int[] t=new int[200001];
	static class pair5 implements Comparable<pair5>{
		private int a;
		private int i;


		pair5(int a,int i) {
			this.a=a;
			this.i=i;


		}
		public int compareTo(pair5 o) {
	         if(o.a>this.a) {
	        	 return -1;
	         }
	         if(o.a==this.a) {
	        	 return 0;
	         }
	         return 1;
		}
	}
	static class pair4 implements Comparable<pair4>{
	private long a;
	private long b;


	pair4(long a,long b) {
		this.a=a;
		this.b=b;


	}
		public int compareTo(pair4 p) {
			if(p.a<this.a) {
				return 1;
			}
			if(p.a==this.a) {
				return p.b<=this.b?1:-1;
			}
			return -1;
		}
	}
	static class type implements Comparable<type>{
		private int left;
		private int right;
		private int i;
		type(int left,int right,int i){
			this.left=left;
			this.right=right;
			this.i=i;
		}
		
		@Override
		public int compareTo(type r1) {
			

			if (r1.left < this.left)
	            return 1;
	      if (r1.left > this.left)
	            return -1;
	      return r1.right > this.right?1:-1;
			
		}
	}
	static long[][][] dp=new long[1001][1001][2];
	static int m=0;
	static long get(int n,int k,int d) {
		if(k==1) {
			dp[n][1][d]=1;
			return 1;
		}
		if(dp[n][k][d]!=-1) {
			return (dp[n][k][d])%mod;
		}
		long ans=2;
		if(d==1) {
			if(n>1) {
				ans+=((get(n-1,k-1,d^1)%mod)-1)%mod;
			}
			if(n<m) {
				ans+=((get(n+1,k,d)%mod)-1)%mod;
			}
		}else {
			if(n>1) {
				ans+=((get(n-1,k,d)%mod)-1)%mod;
			}
			if(n<m) {
				ans+=((get(n+1,k-1,d^1)%mod)-1)%mod;
			}
			
		}
		dp[n][k][d]=ans%mod;
		return ans%mod;
	}
	static long mod=1000000007;
	public static long id5(long a,long b) {
		if(b==(long)0) {
			return a;
		}
		return GCD(b , a%b);
	}
	static HashMap<Integer,Integer> um=new HashMap<>();
	
	 static class pair implements Comparable<pair> {
         private  long len;
         private long time;	


         public pair(long len, long time) {
             this.len = len;
             this.time = time;
         }

         @Override
         public int compareTo(pair item) {
             return Long.compare(this.time, item.time);
         }
     }
	 




	public static int lower_bound(ArrayList<Long> a ,int n,long x) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a.get(mid)>x) {
				r=mid;
			}else {
				l=mid;
			}
		}
		return r;
				
	}
	public static int upper_bound(long[] a ,int n,long x) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a[mid]<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return l;
				
	}


	static class t1 implements Comparable<t1>{
		private int a;
		private int b;
		t1(int a,int b){
			this.a=a;
			this.b=b;
		}
		@Override
		public int compareTo(t1 p1) {
			

			if (p1.a < this.a)
	            return 1;
	      if (p1.a > this.a)
	            return -1;
	      return p1.b > this.b?1:-1;
		}
	}
	static class pair2 implements Comparable<pair2>{
		private long a;
		private int b;
		pair2(long a,int b){
			this.a=a;
			this.b=b;
		}
		public int compareTo(pair2 p) {
			return Long.compare(this.a,p.a);
		}
	}
	public static int id4(String str1,String str2,int n,int m) {
		int[][] dp=new int[n+1][m+1];
		int max=Integer.MIN_VALUE;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(str1.charAt(i-1)==str2.charAt(j-1)) {
					dp[i][j]=1+dp[i-1][j-1];
					max=Math.max(max, dp[i][j]);
				}else {
					dp[i][j]=0;

				}
			}
		}
		
		return max;
	}
	
	public static pair[] merge_sort(pair[] A, int start, int end) {
		if (end > start) {
			int mid = (end + start) / 2;
			pair[] v = merge_sort(A, start, mid);
			pair[] o = merge_sort(A, mid + 1, end);
			return (merge(v, o));
		} else {
			pair[] y = new pair[1];
			y[0] = A[start];
			return y;
		}
	}
	public static pair[] merge(pair a[], pair b[]) {


		pair[] temp = new pair[a.length + b.length];
		int m = a.length;
		int n = b.length;
		int i = 0;
		int j = 0;
		int c = 0;
		while (i < m && j < n) {
			if (a[i].time < b[j].time) {
				temp[c++] = a[i++];
			
			} else {
				temp[c++] = b[j++];
			}
		}
		while (i < m) {
			temp[c++] = a[i++];
		}
		while (j < n) {
			temp[c++] = b[j++];
		}
		return temp;
	}
	static boolean ok(long n) {
		long sum=0;
		while(n>0) {
			sum+=n%10;
			n/=10;
		}
		return (sum==10);
	}
	static long ok1(long n) {
		long sum=0;
		while(n>0) {
			sum+=n%10;
			n/=10;
		}
		return sum;
	}
	static long get1(long n) {
		long f=0;


		while(n>0) {
			f=Math.max(f, n%10);
			n/=10;
		}
		return f;
	}
	static long get2(long n) {
		long f=9;


		while(n>0) {
			f=Math.min(f, n%10);
			n/=10;
		}
		return f;
	}
	static long get(long n,long k,long count) {
		if(count==k) {
			return n;
		}else {
			long t1=get1(n);
			long t2=get2(n);
			long y=n+t1*t2;
			return get(y,k,count+1);
		}
	}
	
	
	public static int lower_bound(ArrayList<Integer> a ,int n,int x) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a.get(mid)<=x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return l;
				
	}
	public static long id2(long[] a,long sum,int n) {
		int l=0;
		long x=0;
		long res=0;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x>sum) {
				x-=a[l];
			l++;
			}
			res=Math.max(r-l+1,res);
		}
		return res;
	}
	public static long id0(long[] a,long sum,int n) {
		int l=0;
		long x=0;
		long res=Integer.MAX_VALUE;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x-a[l]>=sum) {
				x-=a[l];
				l++;
			}
			if(x>=sum) {
				res=Math.min(res, r-l+1);
			}
		}
		return res;
	}
	public static long id3(long[] a,long sum,int n) {
	
		int l=0;
		long x=0;
		long res=0;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x>sum) {
				x-=a[l];
				l++;
			}
			res+=((r-l+1));
		}
		return res;
	}
	public static long id9(long[] a,long sum,int n) {
		
		int l=0;
		int l1=-1;
		int r1=-1;
		long x=0;
		long res=0;
		for(int r=0;r<n;r++) {
			x+=a[r];
			while(x-a[l]>=sum) {
				x-=a[l];
				l++;
			}
			if(x>=sum && l!=l1 && r!=r1) {
				res+=(long)(l-l1)*(n-r);
				l1=l;


			}
			r1=r;
		}
		return res;
	}
	public static long id8(long[] a,long k,int n) {
		int l=0;


		int count=0;
		long res=0;
		int[] ct=new int[100001];
		for(int r=0;r<n;r++) {
			ct[(int) a[r]]++;
			if(ct[(int) a[r]]==1) {
				count++;
			}
				while(count>k) {
					ct[(int) a[l]]--;
					if(ct[(int) a[l]]==0) {
						count--;
					}
					l++;
				}
				res+=(r-l+1);
			
		}
		return res;
		
	}
	public static long id6(long[] a,int n,long k)
	{
		int l=0;
		long count=0;
	for(int r=0;r<n;r++) {
		add(a[r]);
		while(!good(k)) {
			remove();
			l++;
		}
		count+=r-l+1;


	}
		return count;
	}
	
public static class Stack1{
	
	private  Stack<Long> st;
	private  Stack<Long> smin;
	private  Stack<Long> smax;
Stack1(){
	this.st=new Stack<>();
	this.smin=new Stack<>();
	this.smax=new Stack<>();
	this.smin.add(Long.MAX_VALUE);
	this.smax.add(Long.MIN_VALUE);
}	 
	
}
static Stack1 st1=new Stack1();
static Stack1 st2=new Stack1();
static void add(long d) {
	st2.st.add(d);
	st2.smin.add(Math.min(d, st2.smin.peek()));
	st2.smax.add(Math.max(st2.smax.peek(),d));
}
static void remove() {
	if(st1.st.isEmpty()) {
		while(!st2.st.isEmpty()) {
			st1.st.add(st2.st.pop());
			st2.smin.pop();
			st2.smax.pop();
			st1.smax.add(Math.max(st1.smax.peek(), st1.st.peek()));
			st1.smin.add(Math.min(st1.smin.peek(), st1.st.peek()));
		}}
		st1.st.pop();
		st1.smax.pop();
		st1.smin.pop();
	
}
static boolean good(long k) {
	long min=Math.min(st1.smin.peek(), st2.smin.peek());
	long max=Math.max(st1.smax.peek(), st2.smax.peek());
	return max-min<=k;
}



public static class Stack2{
	
	private  Stack<Long> st;
	private  Stack<Long> gcd;
Stack2(){
	this.st=new Stack<>();
	this.gcd=new Stack<>();
	gcd.add((long) 0);
}	 
	
}
static Stack2 st3=new Stack2();
static Stack2 st4=new Stack2();
static void add2(long d) {
	st4.st.add(d);
	st4.gcd.add(GCD(st4.gcd.peek(),d));
}
static void remove2() {
	if(st3.st.isEmpty()) {
		while(!st4.st.isEmpty()) {
			st3.st.add(st4.st.pop());
			st4.gcd.pop();
			st3.gcd.add(GCD(st3.gcd.peek(),st3.st.peek()));
			
		}}
		st3.st.pop();
		st3.gcd.pop();
	
}
static boolean good2() {
	if(st3.st.isEmpty()) {
		while(!st4.st.isEmpty()) {
			st3.st.add(st4.st.pop());
			st4.gcd.pop();
			st3.gcd.add(GCD(st3.gcd.peek(),st3.st.peek()));
			
		}}
	long d=st3.gcd.pop();
	long g=st3.gcd.peek();
	st3.gcd.add(d);
	return GCD(g,st4.gcd.peek())==1;
}


public static long GCD(long a,long b) {
	if(b==(long)0) {
		return a;
	}
	return GCD(b , a%b);
}
public static boolean good3() {
	return GCD(st3.gcd.peek(),st4.gcd.peek())==1;
}
public static long id7(long[] a,int n) {
	int l=0;
	long x=0;
	long res=Integer.MAX_VALUE;
	for(int r=0;r<n;r++) {
		add2(a[r]);
		while(good2()) {
		remove2();
			l++;
		}
		if(good3()) {
			res=Math.min(res, r-l+1);
		}
	}
	return res;
}
public static long[] merge_sort(long[] A, int start, int end) {
	if (end > start) {
		int mid = (end + start) / 2;
		long[] v = merge_sort(A, start, mid);
		long[] o = merge_sort(A, mid + 1, end);
		return (merge(v, o));
	} else {
		long[] y = new long[1];
		y[0] = A[start];
		return y;
	}
}
public static long[] merge(long a[], long b[]) {


	long[] temp = new long[a.length + b.length];
	int m = a.length;
	int n = b.length;
	int i = 0;
	int j = 0;
	int c = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) {
			temp[c++] = a[i++];
		
		} else {
			temp[c++] = b[j++];
		}
	}
	while (i < m) {
		temp[c++] = a[i++];
	}
	while (j < n) {
		temp[c++] = b[j++];
	}
	return temp;
}
public static pair5[] merge_sort(pair5[] A, int start, int end) {
	if (end > start) {
		int mid = (end + start) / 2;
		pair5[] v = merge_sort(A, start, mid);
		pair5[] o = merge_sort(A, mid + 1, end);
		return (merge(v, o));
	} else {
		pair5[] y = new pair5[1];
		y[0] = A[start];
		return y;
	}
}
public static pair5[] merge(pair5 a[], pair5 b[]) {


	pair5[] temp = new pair5[a.length + b.length];
	int m = a.length;
	int n = b.length;
	int i = 0;
	int j = 0;
	int c = 0;
	while (i < m && j < n) {
		if (a[i].a < b[j].a) {
			temp[c++] = a[i++];
		}else if(a[i].a==b[j].a) {
			if(a[i].i<b[j].i) {
				temp[c++]=a[i++];
			}else {
				temp[c++]=b[j++];
			}
		}
		else {
			temp[c++] = b[j++];
		}
	}
	while (i < m) {
		temp[c++] = a[i++];
	}
	while (j < n) {
		temp[c++] = b[j++];
	}
	return temp;
}



public static int[] Create(int[] a,int n) {
	int[] b=new int[n+1];
	for(int i=1;i<=n;i++) {
		int j=i;
		int h=a[i];
		while(i<=n) {
			b[i]+=h;
			i=get_next(i);
		}
		i=j;
	}
	return b;
}
public static int get_next(int a) {
return a+(a&-a);
}
public static int get_parent(int a) {
return a-(a&-a);
}
public static int id1(int index) {
int sum=0;
if(index<=0) {
	return 0;
}
while(index>0) {
	sum+=t[index];
	index=get_parent(index);
}
return sum;
}












public static void update(int index,int n,int val) {




while(index<=n) {
	t[index]+=val;
	index=get_next(index);
}	
}
}
