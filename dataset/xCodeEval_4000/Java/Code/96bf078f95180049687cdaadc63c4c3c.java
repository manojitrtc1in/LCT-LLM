import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class TestClass {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
	
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
	public static long pow(long x,long y,long m){
		if(y==0)
    		return 1;
    	long k = pow(x,y/2,m);
    	if(y%2==0)
    		return (k*k)%m;
    	else
    		return (((k*k)%m)*x)%m;
    }
	static long Inversex = 0,Inversey = 0;
	public static void InverseModulo(long a,long m){
		if(m==0){
			Inversex = 1;
			Inversey = 0;
		}
		else{
    		InverseModulo(m,a%m);
    		long temp = Inversex;
    		Inversex = Inversey;
    		Inversey = temp+ - (a/m)*Inversey;
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
				return false;
		return true;
	}
	public static double distance(int a,int b,int x,int y){
		return Math.sqrt(((long)(a-x)*(long)(a-x))+((long)(b-y)*(long)(b-y)));
	}
	public static class Pair implements Comparable<Pair> {
		long u;
		long v;
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
			return u+" "+v;
		}
	}
	public static class Pairs implements Comparable<Pairs> {
		long u;
		long v;
		int id;
		public Pairs(long u, long v,int w) {
			this.u = u;
			this.v = v;
			this.id = w;
		}
		public int hashCode() {
			int hu = (int) (u ^ (u >>> 32));
			int hv = (int) (v ^ (v >>> 32));
			return 31 * hu + hv;
		}
		public boolean equals(Object o) {
			Pairs other = (Pairs) o;
			return u == other.u && v == other.v;
		}
		public int compareTo(Pairs other) {
			return Long.compare(u, other.u) != 0 ? Long.compare(u, other.u) : Long.compare(v, other.v);
		}
		public String toString() {
			return u+" "+v;
		}
	}
	public static int sieve(int a[],boolean b[]){
		int count = 0;
		b[0] = true;
		b[1] = true;
		for(int i=2;i<a.length;i++){
			if(!b[i]){
				for(int j=2*i;j<a.length;j=j+i){
					b[j] = true;	
				}
				a[count++] = i;
			}
		}
		return count;
	}
	public static void MatrixMultiplication(int a[][],int b[][],int c[][]){
		for(int i=0;i<a.length;i++){
			for(int j=0;j<b[0].length;j++){
				c[i][j] = 0;
				for(int k=0;k<b.length;k++)
					c[i][j]=(int)((c[i][j]+((a[i][k]*(long)b[k][j])%mod1))%mod1);
			}
		}
	}
	public static void Equal(int arr[][],int temp[][]){
		for(int i=0;i<arr.length;i++){
			for(int j=0;j<arr.length;j++)
				temp[i][j] = arr[i][j];
		}
	}
	public static void makeHash(String a,long b[],long mod){
		for(int i=1;i<=a.length();i++)
			b[i] = ((a.charAt(i-1)-'a')+b[i-1]*26)%mod;
	}
	
	public static class ST{
		int arr[] = new int[800000];
		int lazy[] = new int[800000];
		

		ST(int a[]){
			Build(a,0,a.length-1,0);
		}
		public void Build(int a[],int p,int q,int count){
			if(p==q){
				arr[count] = a[p];
				

				return ;
			}
			int mid = (p+q)/2;
			Build(a,p,mid,2*count+1);
			Build(a,mid+1,q,2*count+2);
			arr[count] = arr[2*count+1]&arr[2*count+2];
			

		}
		public void print(){
			for(int i=0;i<10;i++)
				pw.print(arr[i]+" ");
			pw.println();
		}
		public int getSum(int p,int q,int x,int y,int count){
			if(lazy[count]!=0){
				arr[count]|=lazy[count];
				lazy[2*count+1]|=lazy[count];
				lazy[2*count+2]|=lazy[count];
				lazy[count] = 0;
			}
			if(q<x||p>y||p>q){
				

				return (int)Math.pow(2, 30)-1;
			}
			else if(x<=p&&y>=q){
				

				return arr[count];
			}
			int mid = (p+q)/2;
			return getSum(p,mid,x,y,2*count+1)&getSum(mid+1,q,x,y,2*count+2);
		}
		public void Update(int p,int q,int x,int y,int count,int up){
			if(lazy[count]!=0){
				arr[count]|=lazy[count];
				lazy[2*count+1]|=lazy[count];
				lazy[2*count+2]|=lazy[count];
				lazy[count] = 0;
				

			}
			if(q<x||p>y||p>q)
				return;
			else if(x<=p&&y>=q){
				arr[count]|=up;
				lazy[2*count+1]|=up;
				lazy[2*count+2]|=up;
				return ;
			}
			int mid = (p+q)/2;
			Update(p,mid,x,y,2*count+1,up);
			Update(mid+1,q,x,y,2*count+2,up);
			arr[count] = arr[2*count+1]&arr[2*count+2];
		}
	}
	public static class Trie{
		Node head;
		private class Node{
			Node a[] = new Node[26];
			Node(){
				for(int i=0;i<26;i++)
					a[i] = null;
			}
			boolean u,v;
		}
		Trie(){
			head = null;
		}
		public void insert(String a,int p,Node kl){
			if(p==a.length())
				return ;
			if(kl==null){
				Node k = new Node();
				head = k;
				k.a[a.charAt(p)-'a'] = new Node();
				insert(a,p+1,k.a[a.charAt(p)-'a']);
			}
			else{
				if(kl.a[a.charAt(p)-'a']==null)
					kl.a[a.charAt(p)-'a'] = new Node();
				insert(a,p+1,kl.a[a.charAt(p)-'a']);
			}
		}
		public void fix(Node kl){
			boolean temp = false;
			for(int i=0;i<26;i++){
				if(kl.a[i]!=null){
					if(!kl.a[i].v)
						fix(kl.a[i]);
					temp|=kl.a[i].u;
				}
			}
			kl.v = true;
			kl.u = !temp;
		}
		public void pfix(Node kl){
			boolean temp = false;
			int count = 0;
			for(int i=0;i<26;i++){
				if(kl.a[i]!=null){
					if(kl.a[i].v)
						pfix(kl.a[i]);
					temp|=kl.a[i].u;
				}
				else
					count++;
			}
			kl.v = false;
			if(count==26)
				kl.u = false;
			else
				kl.u = !temp;
		}
	}
	private static void soln(){
		String a = nLi();
		String b = nLi();
		int x[] = new int[b.length()],y[] = new int[b.length()];
		int count = 0;
		for(int i=0;i<a.length();i++){
			if(count==b.length())
				break;
			if(a.charAt(i)==b.charAt(count))
				x[count++] = i+1;
		}
		int count2 = b.length()-1;
		for(int i=a.length()-1;i>=0;i--){
			if(count2==-1)
				break;
			if(a.charAt(i)==b.charAt(count2))
				y[count2--] = i+1;
		}
		count2++;
		int max = -1*count2;
		Pair p = new Pair(0,count2);
		if(x[0]==0&&y[b.length()-1]==0){
			pw.println("-");
			return ;
		}
		

		if(count==0)
			p.v = count2;
		for(int i=0;i<count;i++){
			if(count2==b.length()){
				if(max<=i+1-b.length()){
					max = i+1-b.length();
					p.u = i+1;
					p.v = b.length();
				}
				continue;
			}
			if(x[i]-y[count2]<0){
				if(max<=i+1-count2){
					max = i+1-count2;
					p.u = i+1;
					p.v = count2;
					

				}
			}
			else{
				i--;
				count2++;
			}
		}
		for(int i=0;i<p.u;i++)
			pw.print(b.charAt(i));
		p.v = Math.max(p.u, p.v);
		for(int i=(int)p.v;i<b.length();i++)
			pw.print(b.charAt(i));
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
	private static boolean isEndOfLine(int c) {
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
	private static int nI() {
		int c = read();
		while (isSpaceChar(c))
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
		} while (!isSpaceChar(c));
		return res * sgn;
	}
	private static long nL() {
		int c = read();
		while (isSpaceChar(c))
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
		} while (!isSpaceChar(c));
		return res * sgn;
	}
	private static String nextToken() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
	private static String nLi() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}
	private static int[] nIA(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = nI();
		return arr;
	}
	private static long[] nLA(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
			arr[i] = nL();
		return arr;
	}
	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++)
			pw.print(arr[i] + " ");
		pw.println();
		return;
	}
	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++)
			pw.print(arr[i] + " ");
		pw.println();
		return;
	}
	private static boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}
	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}