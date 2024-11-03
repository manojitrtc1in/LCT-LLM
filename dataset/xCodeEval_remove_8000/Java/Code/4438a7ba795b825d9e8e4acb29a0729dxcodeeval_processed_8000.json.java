

import java.util.*;
import java.io.*;
public class id0 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	id0 g=new id0();
	   	g.main();
	   	out.close();
	}
	
	ArrayList<Integer> list[],list2[];
	int dist[],gg[];
	boolean vis[];
	
	

	void main() {

		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			int m=inp.nextInt();
			list=new ArrayList[n];
			list2=new ArrayList[n];
			for(int i=0;i<n;i++) list[i]=new ArrayList<>();
			for(int i=0;i<n;i++) list2[i]=new ArrayList<>();
			for(int i=0;i<m;i++) {
				int x=inp.nextInt()-1;
				int y=inp.nextInt()-1;
				list[x].add(y);
			}
			dist=new int[n];
			vis=new boolean[n];
			Queue<Integer> q=new LinkedList<>();
			q.add(0);
			vis[0]=true;
			int d=0;
			while(!q.isEmpty()) {
				int s=q.size();
				while(s-->0) {
					int cur=q.poll();
					dist[cur]=d;
					for(int x: list[cur]) {
						if(!vis[x]) {
							q.add(x);
							vis[x]=true;
						}
					}
				}
				d++;
			}
			Arrays.fill(vis, false);
			for(int i=0;i<n;i++) for(int x: list[i]) if(dist[i]<dist[x]) list2[i].add(x); 
			gg=new int[n];
			Arrays.fill(gg, n+1);
			for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
			
			for(int i=0;i<n;i++) out.print(gg[i]+" ");
			out.println();
		}
	}
	
	void dfs(int i) {
		vis[i]=true;
		gg[i]=dist[i];
		for(int x: list2[i]) {
			if(!vis[x]) dfs(x);
			gg[i]=Math.min(gg[i], gg[x]);
		}
		for(int x: list[i]) {
			gg[i]=Math.min(gg[i], dist[x]);
		}
	}
	
	
	

	void sort(int a[]) {
		ArrayList<Integer> list=new ArrayList<>();
		for(int x: a) list.add(x);
		Collections.sort(list);
		for(int i=0;i<a.length;i++) a[i]=list.get(i);
	}
	void sort(long a[]) {
		ArrayList<Long> list=new ArrayList<>();
		for(long x: a) list.add(x);
		Collections.sort(list);
		for(int i=0;i<a.length;i++) a[i]=list.get(i);
	}
	void id1(int a[]) {
		Random rand=new Random();
		int n=a.length;
		for(int i=0;i<n;i++) {
			int j=rand.nextInt(n);
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		Arrays.sort(a);
	}
	void id1(long a[]) {
		Random rand=new Random();
		int n=a.length;
		for(int i=0;i<n;i++) {
			int j=rand.nextInt(n);
			long temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		Arrays.sort(a);
	}
	
	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
	}
	
	long fact[];
	long invFact[];
	void init(int n) {
		fact=new long[n+1];
		invFact=new long[n+1];
		fact[0]=1;
		for(int i=1;i<=n;i++) {
			fact[i]=mul(i,fact[i-1]);
		}
		invFact[n]=power(fact[n],mod-2);
		for(int i=n-1;i>=0;i--) {
			invFact[i]=mul(invFact[i+1],i+1);
		}
	}
	
	long nCr(int n, int r) {
		if(n<r || r<0) return 0;
		return mul(fact[n],mul(invFact[r],invFact[n-r]));
	}
	long add(long a, long b) {
		return (a+b)%mod;
	}
	
	long mul(long a, long b) {
		return a*b%mod;
	}
	
	long power(long x, long y) {
		long gg=1;
		while(y>0) {
			if(y%2==1) gg=mul(gg,x);
			x=mul(x,x);
			y/=2;
		}
		return gg;
	}
	
    static class FastReader { 
        BufferedReader br; 
        StringTokenizer st;
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        String next() { 
            while (st==null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        String nextLine() { 
            String s=""; 
            try { 
                s=br.readLine(); 
            } 
            catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return s; 
        } 
    } 
    
	
    
    

	static int gcd(int a, int b) { 
		return b==0?a:gcd(b,a%b);
	}
	
	void print(int a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
	}
	
	void print(long a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
	}
    
    

    static void input(long a[], int n) {
		for(int i=0;i<n;i++) {
			a[i]=inp.nextLong();
		}
	}
	static void input(int a[], int n) {
		for(int i=0;i<n;i++) {
			a[i]=inp.nextInt();
		}
	}	
	static void input(String s[],int n) {
		for(int i=0;i<n;i++) {
			s[i]=inp.next();
		}
	}
	static void input(int a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextInt();
			}
		}
	}
	static void input(long a[][], int n, int m) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=inp.nextLong();
			}
		}
	}
		
}
