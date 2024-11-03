

import java.util.*;
import java.io.*;
public class id1 {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	id1 g=new id1();
	   	g.main();
	   	out.close();
	}
	
	ArrayList<Integer> list[];
	boolean vis[],cycle[];
	ArrayDeque<Integer> stack;
	
	

	void main() {
		
		int t=inp.nextInt();
		while(t-->0) {
			int n=inp.nextInt();
			list=new ArrayList[n];
			for(int i=0;i<n;i++) list[i]=new ArrayList<>();
			for(int i=0;i<n;i++) {
				int x=inp.nextInt()-1;
				int y=inp.nextInt()-1;
				list[x].add(y);
				list[y].add(x);
			}
			vis=new boolean[n];
			cycle=new boolean[n];
			stack=new ArrayDeque<>();
			dfs(0,-1);
			long c=0;
			long gg=(long)n*(n-1);
			DSU dset=new DSU(n);
			for(int i=0;i<n;i++) {
				for(int x: list[i]) {
					if(!cycle[x]) dset.union(i,x);
				}
			}
			boolean done[]=new boolean[n];
			for(int i=0;i<n;i++) {
				int par=dset.find(i);
				if(!done[par]) {
					gg-=((long)dset.size[par]*(dset.size[par]-1))/2;
					done[par]=true;
				}
			}
			out.println(gg);
		}
		
	}
	
	int dfs2(int i) { 

		if(cycle[i]) return 0;
		int c=0;
		for(int x: list[i]) c+=dfs2(x);
		cycle[i]=true;
		return c+1;
	}
	
	void dfs(int i, int parent) {
		if(vis[i]) {
			if(cycle[i]) return;
			while(true) {
				int next=stack.removeLast();
				cycle[next]=true;
				if(next==i) break;
			}
			return;
		}
		vis[i]=true;
		stack.addLast(i);
		for(int x: list[i]) {
			if(x!=parent) dfs(x,i);
		}
		if(!stack.isEmpty()) stack.removeLast();
	}
	
	class DSU {
		int n;
		int parent[];
		long size[];
		DSU(int n){
			this.n=n;
			parent=new int[n];
			size=new long[n];
			for(int i=0;i<n;i++) {
				parent[i]=i;
				size[i]=1l;
			}
		}
		
		int find(int x) {
			return parent[x]= parent[x]==x?x:find(parent[x]);
		}
		
		void union(int x, int y) {
			int p1=find(x);
			int p2=find(y);
			if(p1==p2) return;
			if(size[p2]>size[p1]) {
				int temp=p1;
				p1=p2;
				p2=temp;
			}
			parent[p2]=p1;
			size[p1]+=size[p2];
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
	void id0(int a[]) {
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
	void id0(long a[]) {
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
	long modInv(long x) {
		return power(x,mod-2);
	}
	
	long nCr(int n, int r) {
		if(n<r || r<0) return 0;
		return mul(fact[n],mul(invFact[r],invFact[n-r]));
	}
	
	long mul(long a, long b) {
		return a*b%mod;
	}
	long add(long a, long b) {
		return (a+b)%mod;
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
    
    

	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
	}
	static int gcd(int a, int b) { 
		return b==0?a:gcd(b,a%b);
	}
	
	void print(int a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
		out.println();
	}
	
	void print(long a[]) {
		int n=a.length;
		for(int i=0;i<n;i++) out.print(a[i]+" ");
		out.println();
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
