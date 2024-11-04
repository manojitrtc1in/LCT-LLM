import java.io.*;
import java.math.*;
import java.util.*;
import javax.print.attribute.SetOfIntegerSyntax;

 public class Main {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static id13 filter;
	private static PrintWriter pw;
	private static long count = 0,mod=1000000007;
	private static TreeSet<Integer>ts[]=new TreeSet[200000];

	public static void main(String args[]) throws Exception {
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		

		soln();
		pw.close();
	}
	


	private static void soln() {
	        		 char[] a1=nextLine().toCharArray();
             char[] a2=nextLine().toCharArray();
             int[] c=new int[26];
             for(int i=0;i<a1.length;i++)
                     c[a1[i]-'a']++;
             int j=0;
             for(int i=0;i<26;i++){
                     while(c[i]-->0){
                             a1[j++]=(char) ('a'+i);
                             

                     }
             }
             for(int i=0;i<26;i++)
                     c[i]=0;
             for(int i=0;i<a2.length;i++)
                     c[a2[i]-'a']++;
             j=0;
             for(int i=25;i>=0;i--){
                     while(c[i]-->0){
                             a2[j++]=(char) ('a'+i);
                             

                     }
             }
             boolean f=true;
             boolean another=false;
             int last=a1.length-1;
             int l1=(a1.length+1)/2-1;
             int l2=a1.length/2-1;
             char[] arr=new char[a1.length];
             int a11=0;
             int a22=0;
             int first=0;
             for(int i=0;i<a1.length;i++)
                     if(f){
                             if(another){
                                     arr[last--]=a1[l1--];
                             }else{
                                     if(a1[a11]>=a2[a22]){
                                             another=true;
                                             arr[last--]=a1[l1--];
                                     }else
                                             arr[first++]=a1[a11++];
                             }
                             f=false;
                     }else{
                             if(another){
                                     arr[last--]=a2[l2--];
                             }else{
                                     if(a1[a11]>=a2[a22]){
                                             another=true;
                                             arr[last--]=a2[l2--];
                                     }else
                                             arr[first++]=a2[a22++];
                             }
                             f=true;
                     }
                     for(int i=0;i<arr.length;i++)
                             pw.print(arr[i]);

             
}
	private static void primeFactors(int n,int ind,int[] ans)
	{
		int flag=1;
	    

	    while (n%2 == 0)
	    {flag=0;
	      n = n/2;
	    }
	    if(flag==0) {
	    	
	    	if(ts[2]==null){
	    	ts[2]=new TreeSet<Integer>();
	    	}
	    	else{
	    		if(ts[2].floor(ind)!=null){
	    			

	    			int d1=ts[2].floor(ind);

	    			

	    			if(Math.abs(ind-ans[ind])> Math.abs(ind-d1))
		    		ans[ind]=d1;
	    			
		    		if(Math.abs(ans[d1]-d1)>Math.abs(ind-d1)){
		    			ans[d1]=ind;
		    		}
	    		}
	    	}
	    	ts[2].add(ind);
	    }
	 
	    

	    for (int i = 3; i <= Math.sqrt(n); i = i+2)
	    {
	    	flag=1;
	        

	        while (n%i == 0)
	        {
	          flag=0;  
	            n = n/i;
	        }
	        if(flag==0){
	        	if(ts[i]==null){
	    	    	ts[i]=new TreeSet<Integer>();
	    	    	}
	    	    	else{
	    	    		if(ts[i].floor(ind)!=null){
	    	    			int d1=ts[i].floor(ind);
	    	    			if(Math.abs(ind-ans[ind])> Math.abs(ind-d1))
	    			    		ans[ind]=d1;
	    		  
	    		    		if(Math.abs(ans[d1]-d1)>Math.abs(ind-d1)){
	    		    			ans[d1]=ind;
	    		    		}
	    	    		}
	    	    	}
	    	    	ts[i].add(ind);

	        }
	        
	    }
	 
	    

	    

	    if (n > 2)
	    {
	    	if(ts[n]==null){
    	    	ts[n]=new TreeSet<Integer>();
    	    	}
    	    	else{
    	    		if(ts[n].floor(ind)!=null){
    	    			int d1=ts[n].floor(ind);
    	    			if(Math.abs(ind-ans[ind])> Math.abs(ind-d1))
    			    		ans[ind]=d1;
    		    		
    		    		if(Math.abs(ans[d1]-d1)>Math.abs(ind-d1)){
    		    			ans[d1]=ind;
    		    		}
    	    		}
    	    	}
    	    	ts[n].add(ind);

        }
	}
	
	


	static class Pair implements Comparable<Pair>{

		int idx,val;
		Pair(int idx,int val){
			this.idx=idx;
			this.val=val;
		}
		@Override
		public int compareTo(Pair o) {
			

		


		
			if(o.idx<idx){
				return 1;
			}
			if(o.idx==idx && o.val<val){
				return 1;
			}else{
				return -1;
			}
			
		}
		
	}

	public static long gcd(long x, long y) {
		if (x % y == 0)
			return y;
		else
			return gcd(y, x % y);
	}
	
	private static int BinarySearch(int a[], int low, int high, int target) {
		if (low > high)
			return -1;
		int mid = low + (high - low) / 2;
		if (a[mid] == target)
			return mid;
		if (a[mid] > target)
			high = mid - 1;
		if (a[mid] < target)
			low = mid + 1;
		return BinarySearch(a, low, high, target);
	}
	
	public static String reverseString(String s) {
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		return (sb.toString());
	}
	
	private static int id3(int A[], int l, int r, int key) {
		int m;

		while (r - l > 1) {
			m = l + (r - l) / 2;

			if (A[m] <= key)
				l = m;
			else
				r = m;
		}

		return l;
	}

	private static int id6(int A[], int l, int r, int key) {
		int m;

		while (r - l > 1) {
			m = l + (r - l) / 2;

			if (A[m] >= key)
				r = m;
			else
				l = m;
		}

		return r;
	}

	private static int id7(int A[], int size, int key) {
		

		int left = id6(A, -1, size - 1, key);
		int right = id3(A, 0, size, key);

		

		

		return (A[left] == key && key == A[right]) ? (right - left + 1) : 0;
	}

	private static int Ceil(int a[], int low, int high, int target) {
		if (target <= a[low]) {
			return a[low];

		}
		if (target > a[high])
			return -1;
		while (high - low > 1) {
			int mid = low + (high - low) / 2;
			if (a[mid] < target) {
				low = mid;
				if (mid + 1 <= a.length - 1 && a[mid + 1] >= target)
					return mid + 1;
			}
			if (a[mid] >= target) {
				high = mid;
				if (mid - 1 >= 0 && a[mid - 1] < target) {
					return mid;
				}
			}
		}
		return -1;
	}

	private static int floor(int a[], int low, int high, int target) {
		if (target < a[low]) {
			return -1;
		}
		if (target >= a[high])
			return a[high];
		while (high - low > 1) {
			int mid = low + (high - low) / 2;
			if (a[mid] > target) {
				high = mid;
				if (mid - 1 >= 0 && a[mid - 1] <= target) {
					return mid - 1;
				}
			}
			if (a[mid] <= target) {
				low = mid;
				if ((mid + 1) <= a.length - 1 && a[mid + 1] > target) {
					return mid;
				}
			}

		}
		return -1;
	}

	
	
	public static long pow(long n, long p, long m) {
		long result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0) {
			if (p % 2 == 1)
				result *= n;
			if (result >= m)
				result %= m;
			p >>= 1;
			n *= n;
			if (n >= m)
				n %= m;
		}
		return result;
	}

	public static long pow(long n, long p) {
		long result = 1;
		if (p == 0)
			return 1;
		if (p == 1)
			return n;
		while (p != 0) {
			if (p % 2 == 1)
				result *= n;
			p >>= 1;
			n *= n;
		}
		return result;

	}
	 static void id9(int arr[], int data[], int start,
             int end, int index, int r)
{
		 

if (index == r)
{
	HashSet hs=new HashSet();
for (int j=0; j<r; j++)
{
	hs.add(data[j]);


}


for(int j=0;j<r;j++){
	if(!((j>0&& hs.contains(data[j]-1)) || (j<data.length-1 && hs.contains(data[j]+1)))){
		return;
	}
}
count++;
count%=1000000007;

return;
}









for (int i=start; i<=end && end-i+1 >= r-index; i++)
{
data[index] = arr[i];
id9(arr, data, i+1, end, index+1, r);
}
}





static long printCombination(int arr[], int n, int r)
{


int data[]=new int[r];



id9(arr, data, 0, n-1, 0, r);
return count;
}

public static long id1(int set[],boolean prime[]) {
		long ans = 0;
		int n = set.length;

		

		

		for (int i = 0; i < (1 << n); i++) {
			int a[] = new int[n];

			int count = 0;

			

			for (int j = 0; j < n; j++)

				

				

				

				

				

				if ((i & (1 << j)) > 0) {

					a[count] = set[j];
					count++;
					

				}
			int tot = 0;
			for (int t = 0; t < count; t++) {
				tot^=a[t];
				pw.print(a[t]+" ");
			}
			

			if (prime[tot]) {
				ans++;
				ans%=mod;
			}
			pw.println();
		} 

		return ans;
	}

	

	static List<Integer> id15(int N, int step, int start) {
		if (N < 1 || step < 1 || start < 1)
			return null;

		List<Integer> p = new LinkedList<Integer>();
		for (int i = 0; i < N; i++)
			p.add(i + 1);

		List<Integer> r = new LinkedList<Integer>();
		int i = (start - 2) % N;
		for (int j = N; j > 0; j--) {
			i = (i + step) % N--;
			r.add(p.remove(i--));
		}

		return r;
	}


	public static int[] id14(int[] f) {
		int[] to = new int[f.length];
		{
			int[] b = new int[65537];
			for (int i = 0; i < f.length; i++)
				b[1 + (f[i] & 0xffff)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < f.length; i++)
				to[b[f[i] & 0xffff]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		{
			int[] b = new int[65537];
			for (int i = 0; i < f.length; i++)
				b[1 + (f[i] >>> 16)]++;
			for (int i = 1; i <= 65536; i++)
				b[i] += b[i - 1];
			for (int i = 0; i < f.length; i++)
				to[b[f[i] >>> 16]++] = f[i];
			int[] d = f;
			f = to;
			to = d;
		}
		return f;
	}

	public static int id17(final int a) {
		int b = 1;
		while (b < a) {
			b = b << 1;
		}
		return b;
	}

	public static boolean id12(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
		int s = p2 * p5 - p1 * p6 + (p6 - p2) * p7 + (p1 - p5) * p8;
		int t = p1 * p4 - p2 * p3 + (p2 - p4) * p7 + (p3 - p1) * p8;

		if ((s < 0) != (t < 0))
			return false;

		int A = -p4 * p5 + p2 * (p5 - p3) + p1 * (p4 - p6) + p3 * p6;
		if (A < 0.0) {
			s = -s;
			t = -t;
			A = -A;
		}
		return s > 0 && t > 0 && (s + t) <= A;
	}

	public static float area(int x1, int y1, int x2, int y2, int x3, int y3) {
		return (float) Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	}

	public static boolean isPrime(int n) {
		

		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		

		

		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	


	static long sort(int a[])
	{  int n=a.length;
		int b[]=new int[n];	
		return mergeSort(a,b,0,n-1);}
	static long mergeSort(int a[],int b[],long left,long right)
	{ long c=0;if(left<right)
	 {   long mid=left+(right-left)/2;
		 c= mergeSort(a,b,left,mid);
		 c+=mergeSort(a,b,mid+1,right);
		 c+=merge(a,b,left,mid+1,right); }	
		return c;	 }
	static long merge(int a[],int  b[],long left,long mid,long right)
	{long c=0;int i=(int)left;int j=(int)mid; int k=(int)left;
	while(i<=(int)mid-1&&j<=(int)right)
	{ if(a[i]>a[j]) {b[k++]=a[i++]; }
	else	{ b[k++]=a[j++];c+=mid-i;}}
	while (i <= (int)mid - 1)   b[k++] = a[i++]; 
	while (j <= (int)right) b[k++] = a[j++];
	for (i=(int)left; i <= (int)right; i++) 
		a[i] = b[i];  return c;  }
	public static boolean id8(String large, String small, int largeLen, int smallLen) {
		

		if (largeLen == 0)
			return false;
		if (smallLen == 0)
			return true;
		

		if (large.charAt(largeLen - 1) == small.charAt(smallLen - 1))
			id8(large, small, largeLen - 1, smallLen - 1);
		

		return id8(large, small, largeLen - 1, smallLen);
	}

	

	


	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}

	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private static boolean id10(int c) {
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
		while (id2(c))
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
		} while (!id2(c));
		return res * sgn;
	}

	private static long nextLong() {
		int c = read();
		while (id2(c))
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
		} while (!id2(c));
		return res * sgn;
	}

	private static String nextToken() {
		int c = read();
		while (id2(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id2(c));
		return res.toString();
	}

	private static String nextLine() {
		int c = read();
		while (id2(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id10(c));
		return res.toString();
	}

	private static int[] id5(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	private static int[][] id11(int n, int m) {
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = nextInt();
			}
		}
		return arr;
	}

	private static long[] id16(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}

	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}

	private static void pArray(boolean[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}

	private static boolean id2(int c) {
		if (filter != null)
			return filter.id2(c);
		return isWhitespace(c);
	}

	private interface id13 {
		public boolean id2(int ch);
	}

	private static void multiply(int a[][], int b[][]) {
		

		

		int mul[][] = new int[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				mul[i][j] = 0;
				for (int k = 0; k < 2; k++)
					mul[i][j] += a[i][k] * b[k][j];
			}
		}

		

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				a[i][j] = mul[i][j]; 

	}

	

	private static int power(int F[][], long n) {
		int M[][] = { { 1, 1 }, { 1, 0 } };

		

		

		if (n == 1)
			return F[0][0] + F[0][1];

		power(F, n / 2);

		multiply(F, F);

		if (n % 2 != 0)
			multiply(F, M);

		

		

		return F[0][0] + F[0][1];
	}

	

	

	

	

	

	

	private static long id0(long n) {

		int F[][] = { { 1, 1 }, { 1, 0 } };

		return power(F, n - 2);
	}

}
   
    class MyComp implements Comparator<Integer>{

		@Override
		public int compare(Integer o1, Integer o2) {
			if(o1<o2){
				return 1;
			}else if(o1>o2){
				return -1;
			}
			return 0;
		}

		
    	
    }
    class Graph{
    	private long conse=0,co=0,id4=0;
    	private int V,flag=1, d[], road_cond[][];
    	private Stack <Integer>st=new Stack();
    	private LinkedList<Integer > adj[];
    	private HashMap<String ,Integer> hs =new HashMap<>();
    

Graph(int V){
	V++;

	
	

this.V=(V);
adj=new LinkedList[V];


	


	


 
}
void addEdge(int v,int w,int t){
	if(adj[v]==null){
		adj[v]=new LinkedList();
	}
	adj[v].add(w);
	String temp="";
temp+=v;
temp+=w;


	if(!hs.containsKey(temp))
	hs.put(temp, t);

}
public long  bfs(int s)
{
	co=0;
    



        boolean visited[] = new boolean[V];
 
        

        LinkedList<Integer> queue = new LinkedList<Integer>();
 
        

        visited[s]=true;
        queue.add(s);
 
        while (queue.size() != 0)
        {
            

    s = queue.poll();
   

 
            

    

    

        Iterator<Integer> i = adj[s].listIterator();
        while (i.hasNext())
        {
            int n = i.next();
            if (!visited[n])
            {
                visited[n] = true;
                queue.add(n);
            co++;
            }
        }
        return co;
    }
    return 0;
}
 public long  dfs(int startVertex){
	
	boolean Visited[]=new boolean[V];
	
	

	
	 if(!Visited[startVertex])  {
		
		 co=0; 
		 dfsUtil(startVertex,Visited);
	 
	 }
	 
	 return co;
 }
 public void Connected(int v){
	 Iterator<Integer> i = adj[v].listIterator();
	 while(i.hasNext()){
		 int n=i.next();
		 long data=(long)d[n]+(long)d[v];
		 data=data%1000000007;
		 d[n]=(int)data;
	 }
 }
 public int getByte(int v){
	 return d[v];
 }
private void dfsUtil(int startVertex, boolean[] Visited) {
	


Visited[startVertex]=true;


st.push(startVertex);
while(!st.isEmpty()){
	int top=st.pop();
	System.out.print(top+" ");
	
	

Iterator<Integer> i=adj[top].listIterator();

while(i.hasNext()){
	int n=i.next();


			 if( !Visited[n]){
				Visited[n]=true;
					st.push(n);
					co++;
					}
			 }
		
	}
		}
}

class Dsu{
	private int rank[], parent[] ,n;
	
	Dsu(int size){
		this.n=size+1;
		rank=new int[n];
		parent=new int[n];
	makeSet();
	}
	
	void makeSet(){
		for(int i=0;i<n;i++){
			parent[i]=i;
		}
	}
	
	int find(int x){
		if(parent[x]!=x){
			
			parent[x]=find(parent[x]);
		}
		return parent[x];
	}	
	
	void union(int x,int y){
		int xRoot=find(x);
		int yRoot=find(y);
		
		if(xRoot==yRoot)
			return;
		if(rank[xRoot]<rank[yRoot]){
		parent[xRoot]=yRoot;	
		}else if(rank[yRoot]<rank[xRoot]){
			parent[yRoot]=xRoot;
		}else{
			parent[yRoot]=xRoot;
			rank[xRoot]++;
		}
		
	}

}
