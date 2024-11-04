import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class hacker49 {

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
































































	String str=s.next();
	String y=s.next();
	int n=str.length();
	if(y.length()==1 && y.charAt(0)==str.charAt(0)) {
	out.println("YES");
	}else {
	HashMap<Character,ArrayList<Integer>> e=new HashMap<>();
	HashSet<String>[] f1=new HashSet[n];
	HashSet<String>[] f2=new HashSet[n];
	for(int i=0;i<n;i++) {
		f1[i]=new HashSet<>();
		f2[i]=new HashSet<>();
	}
	for(int i=n-2;i>=0;i--) {
		String h="";
		f1[i+1].add(h);
		for(int j=i;j>=0;j--) {
			h+=str.charAt(j);
			f1[i+1].add(h);
		}
	}
	for(int i=0;i<n;i++) {
		String h="";
		f2[i].add(h);
		for(int j=i;j<n;j++) {
			h+=str.charAt(j);
			f2[j].add(h);
		}
	}
	for(int i=0;i<n;i++) {
		if(!e.containsKey(str.charAt(i))) {
			e.put(str.charAt(i), new ArrayList<>());
			e.get(str.charAt(i)).add(i);
		}else {
			e.get(str.charAt(i)).add(i);
		}
	}
	int o=y.length();
	boolean p=false;
	out:for(int i=0;i<o;i++) {
		String str1=y.substring(0,i+1);
		String str2=y.substring(i+1,o);
		if(e.containsKey(y.charAt(i))) {
			int g=e.get(y.charAt(i)).size();
			for(int j=0;j<g;j++) {
				if(f2[e.get(y.charAt(i)).get(j)].contains(str1) && f1[e.get(y.charAt(i)).get(j)].contains(str2)) {
					p=true;


					break out;
				}
			}
		}
	}
		if(p) {
			out.println("YES");
		}else {
			out.println("NO");
		}}


















































































































































	t--;
}
		
   out.close();
	}
	
static long m=-1;
static void sf(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }   
}
	
static HashMap<Integer,pair> e=new HashMap<>();
static ArrayList<Integer>[] f1=new ArrayList[200001];	
static PriorityQueue<pair> q=new PriorityQueue<>();	
static ArrayList<pair>[] f=new ArrayList[200001];
	static class pair implements Comparable<pair>{
		private int a;
		private int b;
		pair(int a,int b){
			this.a=a;
			this.b=b;
		}
		public int compareTo(pair o) {
			return Integer.compare(o.b, this.b);
		}


		
	}
	static class node{
		private int a;
		private int b;
		node(int a,int b){
			this.a=a;
			this.b=b;
		}
	}
static int[] col=new int[200001];
static int[] subtree=new int[200001];
static int[] vis=new int[200001];
static int dfs(int node) {
		vis[node]=1;
		int c=0;
		for(int i=0;i<f[node].size();i++) {
			if(vis[f[node].get(i).a]==0) {
				c+=dfs(f[node].get(i).a);
			}
		}
		subtree[node]+=c;
		subtree[node]+=col[node];
		return subtree[node];
	}
	public static int upper_bound(long[] a ,long x,int n) {
		int l=-1;
		int r=n;
		while(r>l+1) {
			int mid=(l+r)/2;
			if(a[mid]<x) {
				l=mid;
			}else {
				r=mid;
			}
		}
		return r;
				
	}
	public static int lower_bound(long[] a ,long x,int n) {
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
	public static long lb(int n,long[] pre,long k,long a,long b,long x,long y) {
		long l=0;
		long r=n+1;
		while(l<r) {
			long mid=(l+r)/2;
			long sum=0;
			long gcd=GCD(a,b);
			long g=mid/(a*b/gcd);
			long a1=mid/a;
			long b1=mid/b;
			sum+=(pre[(int) g]*(x+y))/100;
			if(x>=y) {
				sum+=((pre[(int) a1]-pre[(int) g])*x)/100;
				sum+=(((pre[(int)(a1+b1-g)]-pre[(int)(a1)])*y))/100;
			}else {
				sum+=((pre[(int) b1]-pre[(int) g])*y)/100;
				sum+=(((pre[(int)(a1+b1-g)]-pre[(int)(b1)])*x))/100;
			}
			if(sum>=k) {
				r=mid;
			}else {
				l=mid+1;
			}


		}
		
		return r;
				
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
public static int query_1(int[] b,int index) {
	int sum=0;
	if(index<=0) {
		return 0;
	}
	while(index>0) {
		sum+=b[index];
		index=get_parent(index);
	}
	return sum;
}
public static int query(int[] b,int n,int l,int r) {
	int sum=0;
	sum+=query_1(b,r);
	sum-=query_1(b,l-1);
	return sum;
}
public static void update(int[] a,int[] b,int n,int index,int val) {
	int diff=val-a[index];
	a[index]+=diff;
	while(index<=n) {
		b[index]+=diff;
		index=get_next(index);
	}	
}
	


















































































































































































	public static int lower_bound(ArrayList<Long> a ,int n,long x) {
		int l=0;
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
	public static int[] is_prime=new int[1000001];
	public static ArrayList<Long> primes=new ArrayList<>();
 	public static void sieve() {
		long maxN=1000000;
		for(long i=1;i<=maxN;i++) {
			is_prime[(int) i]=1;
		}
		is_prime[0]=0;
		is_prime[1]=0;
		for(long i=2;i*i<=maxN;i++) {
			if(is_prime[(int) i]==1) {


				for(long j=i*i;j<=maxN;j+=i) {
					is_prime[(int) j]=0;
				}
			}
		}
		for(long i=0;i<=maxN;i++) {
			if(is_prime[(int) i]==1) {
				primes.add(i);
			}
		}		
	}






































































	public static long im(long a) {
		return binary_exponentiation_1(a,mod-2)%mod;
	}
	public static long binary_exponentiation_1(long a,long n) {
		long res=1;
		while(n>0) {
			if(n%2!=0) {
				res=((res)%(mod) * (a)%(mod))%(mod);
				n--;
			}else {
				a=((a)%(mod) *(a)%(mod))%(mod);
				n/=2;
			}
		}
		return (res)%(mod);
		
	}

	public static double bn1(double a,double n) {
		double res=1;
		while(n>0) {
			if(n%2!=0) {


				res=(res*a);
				n--;
			}else {


				a=(a*a);
				n/=2;
			}
		}
		return (res);	
	}
	public static long bn(long a,long n) {
		long res=1;
		while(n>0) {
			if(n%2!=0) {
				res=res*a;
				n--;
			}else {
				a*=a;
				n/=2;
			}
		}
		return res;
		
	}
public static long[] fac=new long[300001];
public static void ff() {
		fac[0]=(long)1;
		fac[1]=(long)1;
		for(long i=2;i<=300000;i++) {
			fac[(int) i]=(fac[(int) (i-1)]*i)%(m);
		}
	}	
public static long mod=998244353;
public static long GCD(long a,long b) {
		if(b==(long)0) {
			return a;
		}
		return GCD(b , a%b);
	}
public static long c=0;	
}