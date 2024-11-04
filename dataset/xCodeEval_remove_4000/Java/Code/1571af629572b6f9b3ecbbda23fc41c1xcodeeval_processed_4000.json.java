import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;


public class TestClass {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static id6 filter;
	private static PrintWriter pw;
	static int di = 0,gi = 0;
	public static class Heap {
		long arr[][];
		int num;
		Heap(int a){
			arr = new long[a][3];
			num = 0;
		}
		public void swap(long arr[][],int i,int j){
			long t = arr[i][0];
			arr[i][0] = arr[j][0];
			arr[j][0] = t;
			t = arr[i][1];
			arr[i][1] = arr[j][1];
			arr[j][1] = t;
			t = arr[i][2];
			arr[i][2] = arr[j][2];
			arr[j][2] = t;
		}
		public void Minheap(int a){
			while(a>0&&arr[(a-1)/2][0]>arr[a][0]){
				swap(arr,(a-1)/2,a);
				a = (a-1)/2;
			}
		}
		public void id5(int a){
			int largest = a;
			if(2*a+1<num&&arr[largest][0]>arr[2*a+1][0])
				largest = 2*a+1;
			if(2*a+2<num&&arr[largest][0]>arr[2*a+2][0])
				largest = 2*a+2;
			if(largest!=a){
				swap(arr,a,largest);
				id5(largest);
			}
		}
		public void insert(long a,int b,int c){
			arr[num++][0] = a;
			arr[num-1][1] = b;
			arr[num-1][2] = c;
			Minheap(num-1);
		}
		public void id2(int a){
			long pi = arr[a][0];
			di = (int)arr[a][1];
			gi = (int)arr[a][2];
			arr[a][0] = arr[num-1][0];
			arr[a][1] = arr[num-1][1];
			arr[a][2] = arr[num-1][2];
			num--;
			if(arr[a][0]>pi)
				id5(a);
			else
				Minheap(a);
		}
		public long getMin(){
			long pi = arr[0][0];
			di = (int)arr[0][1];
			gi = (int)arr[0][2];
			id2(0);
			return pi;
		}
		public void id1(int a){
			for(int i=0;i<num;i++){
				if(arr[i][0]==a){
					id2(i);
					break;
				}
			}
		}
	}
	public static class Queue{
		private class node{
			int val;
			node next;
			node(int a){
				val = a;
				next = null;
			}
		}
		node head,tail;
		Queue(){
			head = null;
			tail = null;
		}
		public void EnQueue(int a){
			if(head==null){
				node p = new node(a);
				head = p;
				tail = p;
			}
			else{
				node p = new node(a);
				tail.next = p;
				tail = p;
			}
		}
		public int DeQueue(){
			int a = head.val;
			head = head.next;
			return a;
		}
		public boolean isEmpty(){
			return head==null;
		}
	}
	public static void Merge(int a[],int p,int r){
        if(p<r){
            int q = (p+r)/2;
            Merge(a,p,q);
            Merge(a,q+1,r);
            Merge_Array(a,p,q,r);
        }
    }
    public static void Merge_Array(int a[],int p,int q,int r){
        int b[] = new int[q-p+1];
        int c[] = new int[r-q];
        for(int i=0;i<b.length;i++)
            b[i] = a[p+i];
        for(int i=0;i<c.length;i++)
            c[i] = a[q+i+1];
        int i = 0,j = 0;
        for(int k=p;k<=r;k++){
            if(i==b.length){
                a[k] = c[j];
                j++;
            }
            else if(j==c.length){
                a[k] = b[i];
                i++;
            }
            else if(b[i]<c[j]){
                a[k] = b[i];
                i++;
            }
            else{
                a[k] = c[j];
                j++;
            }
        }
    }
    public static void Merge(int a[][],int p,int r){
        if(p<r){
            int q = (p+r)/2;
            Merge(a,p,q);
            Merge(a,q+1,r);
            Merge_Array(a,p,q,r);
        }
    }
    public static void Merge_Array(int a[][],int p,int q,int r){
        int b[][] = new int[q-p+1][2];
        int c[][] = new int[r-q][2];
        for(int i=0;i<b.length;i++){
            b[i][0] = a[p+i][0];
            b[i][1] = a[p+i][1];
        }
        for(int i=0;i<c.length;i++){
            c[i][0] = a[q+i+1][0];
            c[i][1] = a[q+i+1][1];
        }
        int i = 0,j = 0;
        for(int k=p;k<=r;k++){
            if(i==b.length){
                a[k][0] = c[j][0];
                a[k][1] = c[j][1];
                j++;
            }
            else if(j==c.length){
                a[k][0] = b[i][0];
                a[k][1] = b[i][1];
                i++;
            }
            else if(b[i][0]<c[j][0]||(b[i][0]==c[j][0]&&b[i][1]<c[j][1])){
                a[k][0] = b[i][0];
                a[k][1] = b[i][1];
                i++;
            }
            else{
                a[k][0] = c[j][0];
                a[k][1] = c[j][1];
                j++;
            }
        }
    }
    public static void Merge(int a[][],int b[],int p,int r){
        if(p<r){
            int q = (p+r)/2;
            Merge(a,b,p,q);
            Merge(a,b,q+1,r);
            Merge_Array(a,b,p,q,r);
        }
    }
    public static void Merge_Array(int a[][],int xy[],int p,int q,int r){
        int b[][] = new int[q-p+1][2];
        int c[][] = new int[r-q][2];
        for(int i=0;i<b.length;i++){
            b[i][0] = a[p+i][0];
            b[i][1] = a[p+i][1];
        }
        for(int i=0;i<c.length;i++){
            c[i][0] = a[q+i+1][0];
            c[i][1] = a[q+i+1][1];
        }
        int i = 0,j = 0;
        for(int k=p;k<=r;k++){
            if(i==b.length){
                a[k][0] = c[j][0];
                a[k][1] = c[j][1];
                j++;
            }
            else if(j==c.length){
                a[k][0] = b[i][0];
                a[k][1] = b[i][1];
                i++;
            }
            else if(b[i][0]<c[j][0]||(b[i][0]==c[j][0]&&xy[b[i][1]]>xy[c[j][1]])){
                a[k][0] = b[i][0];
                a[k][1] = b[i][1];
                i++;
            }
            else{
                a[k][0] = c[j][0];
                a[k][1] = c[j][1];
                j++;
            }
        }
    }
    public static int pow(int x,int y,long m){
    	if(y==0)
    		return 1;
    	int k = pow(x,y/2,m);
    	if(y%2==0)
    		return (int)((k*(long)k)%m);
    	else
    		return (int)((((k*(long)k)%m)*x)%m);
    }
    static int Inversex = 0,Inversey = 0;
    public static void InverseModulo(int a,int m){
    	if(m==0){
    		Inversex = 1;
    		Inversey = 0;
    	}
    	else{
    		InverseModulo(m,a%m);
    		int temp = Inversex;
    		Inversex = Inversey;
    		Inversey = temp - (a/m)*Inversey;
    	}
    }
    static long mod1 = 1000000007;
    static long mod2 = 1000000009;
	public static long gcd(long a,long b){
		if(a%b==0)
			return b;
		return gcd(b,a%b);
	}
	public static boolean isPrime(long a){
		if(a==1)
			return false;
		else if(a==2||a==3)
			return true;
		for(long i=2;i<=Math.sqrt(a);i++)
			if(a%i==0)
				return true;
		return false;
	}
	public static double distance(int a,int b,int x,int y){
		return Math.sqrt(((long)(a-x)*(long)(a-x))+((long)(b-y)*(long)(b-y)));
	}
	public static void Hash(String a,long b[],long mod){
		for(int i=0;i<a.length();i++)
			b[i+1] = ((26*b[i] + (a.charAt(i)+1)-'a')%mod);
	}
	public static long getHash(long b[],int a,int c,long q,long mod){
		long nm = b[c];
		long p = b[a-1];
		p = ((p*q)%mod);
		return (((nm+mod)-p)%mod);
	}
	public static class Pair implements Comparable<Pair> {
		long u;
		long v;
		BigInteger bi;
		public Pair(long u, long v) {
			this.u = u;
			this.v = v;
		}
		public int hashCode() {
			int hu = (int) (u ^ (u >>> 32));
			int hv = (int) (v ^ (v >>> 32));
			return 31 * hu + hv;
		}
		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return u == other.u && v == other.v;
		}
		public int compareTo(Pair other) {
			return Long.compare(u, other.u) != 0 ? Long.compare(u, other.u) : Long.compare(v, other.v);
		}
		public String toString() {
			return "[u=" + u + ", v=" + v + "]";
		}
	}
	public static long bs(long a,long q[][],int x,int y){
		int mid = (x+y)/2;
		if(x==y)
		       return q[x][0];
		if(q[mid][1]<=a&&q[mid+1][1]>a)
			return q[mid][0];
		else if(q[mid][1]>a)
			return bs(a,q,x,mid-1);
		else
			return bs(a,q,mid+1,y);
	}
	private static void soln(){
		long n = nextLong();
		int m = nextInt();
		int k = nextInt();
		long x = nextLong();
		long s = nextLong();
		long p[][] = new long[m][2];
		long q[][] = new long[k][2];
		for(int i=0;i<m;i++)
			p[i][0] = nextLong();
		for(int i=0;i<m;i++)
			p[i][1] = nextLong();
		for(int i=0;i<k;i++)
			q[i][0] = nextLong();
		for(int i=0;i<k;i++)
			q[i][1] = nextLong();
		long max = Long.MAX_VALUE;
		for(int i=0;i<m;i++){
			if(s-p[i][1]<0)
				continue;
			if(s-p[i][1]<q[0][1]){
				if(max>p[i][0]*n)
					max = p[i][0]*n;
			}
			else if(s-p[i][1]>=q[k-1][1]){
				if(max>p[i][0]*(n-q[k-1][0]))
					max = p[i][0]*(n-q[k-1][0]);
			}
			else{
				long nm = bs(s-p[i][1],q,0,k-1);
				if((n-nm)*p[i][0]<max)
					max = p[i][0]*(n-nm);
			}
		}
		for(int i=0;i<k;i++){
			if(s-q[i][1]>=0&&max>x*(n-q[i][0]))
				max = x*(n-q[i][0]);
		}
		if(max>x*n)
			max = x*n;
		pw.println(max);
		
	}
	public static void main(String[] args) {
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		soln();
		pw.close();
	}
	

	

	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}
	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
	private static boolean id4(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}
	private static int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
	private static int nextInt() {
		int c = read();
		while (id0(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id0(c));
		return res * sgn;
	}
	private static long nextLong() {
		int c = read();
		while (id0(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id0(c));
		return res * sgn;
	}
	private static String nextToken() {
		int c = read();
		while (id0(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id0(c));
		return res.toString();
	}
	private static String nextLine() {
		int c = read();
		while (id0(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id4(c));
		return res.toString();
	}
	private static int[] id3(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = nextInt();
		return arr;
	}
	private static long[] id7(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
			arr[i] = nextLong();
		return arr;
	}
	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		return;
	}
	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		return;
	}
	private static boolean id0(int c) {
		if (filter != null)
			return filter.id0(c);
		return isWhitespace(c);
	}
	private interface id6 {
		public boolean id0(int ch);
	}
}