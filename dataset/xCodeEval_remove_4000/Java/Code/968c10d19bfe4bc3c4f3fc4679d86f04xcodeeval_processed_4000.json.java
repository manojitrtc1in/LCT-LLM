

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
	
	ArrayList<Integer> list[], id2[];
	int dist[], h[], gg[];
	int maxD=0;
	
	

	void main() {
		
		int n=inp.nextInt();
		list=new ArrayList[n+1];
		id2=new ArrayList[n+1];
		for(int i=0;i<=n;i++) {
			list[i]=new ArrayList<>();
			id2[i]=new ArrayList<>();
		}
		for(int i=0;i<n-1;i++) {
			int x=inp.nextInt();
			int y=inp.nextInt();
			list[x].add(y);
			list[y].add(x);
		}
		dist=new int[n+1];
		h=new int[n+1];
		gg=new int[n+1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		int k=inp.nextInt();
		Queue<Integer> q=new LinkedList<>();
		for(int i=0;i<k;i++) {
			int x=inp.nextInt();
			q.add(x);
			dist[x]=0;
		}
		bfs(q);
		Queue<Pair> qu=new LinkedList<>();
		for(int i=maxD;i>0;i--) {
			for(int x: id2[i]) {
				if(h[x]<dist[x]) {
					if(gg[x]==0) {
						gg[x]=i;
					}
					h[x]=dist[x];
					qu.add(new Pair(dist[x],x));
				}
			}
			while(!qu.isEmpty()) {
				Pair cur=qu.poll();
				int r=cur.dist-1;
				if(r==0) continue;
				for(int y: list[cur.idx]) {
					int tv=Math.min(r,dist[y]);
					if(h[y]<tv) {
						h[y]=tv;
						if(gg[y]==0) gg[y]=i;
						qu.add(new Pair(tv,y));
					}
				}
			}
		}
		
		
		for(int i=1;i<=n;i++) out.print(gg[i]+" ");
	}
	
	void bfs(Queue<Integer> q) {
		while(!q.isEmpty()) {
			int i=q.poll();
			for(int x: list[i]) {
				if(dist[x]>dist[i]+1) {
					dist[x]=dist[i]+1;
					q.add(x);
				}
			}
			maxD=Math.max(maxD, dist[i]);
			id2[dist[i]].add(i);
		}
	}
	
	class Pair {
		int dist, idx;
		Pair(int f, int s){
			this.dist=f;
			this.idx=s;
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
