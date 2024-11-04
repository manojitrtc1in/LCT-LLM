

import java.util.*;
import java.io.*;
public class InVoker {
	

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	InVoker g=new InVoker();
	   	g.main();
	   	out.close();
	}
	
	

	void main() {
		
		int n=inp.nextInt();
		int r1=inp.nextInt();
		int c1=inp.nextInt();
		int r2=inp.nextInt();
		int c2=inp.nextInt();
		String s[]=new String[n];
		input(s,n);
		ArrayList<Pair> canReachFromStart = new ArrayList<>();
		ArrayList<Pair> canReachFromEnd = new ArrayList<>();
		addReachablePlaces(s,r1-1,c1-1,canReachFromStart);
		addReachablePlaces(s,r2-1,c2-1,canReachFromEnd);
		int gg=Integer.MAX_VALUE;
		for(int i=0;i<canReachFromStart.size();i++) {
			int x1=canReachFromStart.get(i).x+1;
			int y1=canReachFromStart.get(i).y+1;
			for(int j=0;j<canReachFromEnd.size();j++) {
				int x2=canReachFromEnd.get(j).x+1;
				int y2=canReachFromEnd.get(j).y+1;
				gg=Math.min(gg, (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
			}
		}
		out.println(gg);
	}
	
	static void addReachablePlaces(String s[], int r, int c, ArrayList<Pair> list) {
		int n=s.length;
		boolean vis[][]=new boolean[n][n];
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(r,c));
		while(!q.isEmpty()) {
			Pair current= q.peek();
			int x=current.x,y=current.y;
			if(vis[x][y]) {
				q.poll();
				continue;
			}
			if(x-1>=0 && !vis[x-1][y] && s[x-1].charAt(y)=='0') {
				q.add(new Pair(x-1,y));
			}
			if(x+1<n && !vis[x+1][y] && s[x+1].charAt(y)=='0') {
				q.add(new Pair(x+1,y));
			}
			if(y-1>=0 && !vis[x][y-1] && s[x].charAt(y-1)=='0') {
				q.add(new Pair(x,y-1));
			}
			if(y+1<n && !vis[x][y+1] && s[x].charAt(y+1)=='0') {
				q.add(new Pair(x,y+1));
			}
			vis[x][y]=true;
			list.add(q.poll());
		}
	}
	
	static class Pair {
		int x,y;
		Pair(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
	
	
	
	
	
	
	
	
	

	static class Edge implements Comparable<Edge>{
		int l,r;
		Edge(){}
		Edge(int l,int r){
			this.l=l;
			this.r=r;
		}
		@Override
		public int compareTo(Edge e) {
			return (l-e.l)!=0?l-e.l:r-e.r;
		}
	}
	
    static class Segment implements Comparable<Segment> {
		long l, r, initialIndex;
		Segment () {}
		Segment (long l_, long r_, long d_) {
		    this.l = l_;
		    this.r = r_;
		    this.initialIndex = d_;
		}
		@Override
		public int compareTo(Segment o) {
		    return (int)((l - o.l) !=0 ? l-o.l : initialIndex - o.initialIndex);
		}
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
    
    

	static long gcd(long a, long b) { 
		return b==0?a:gcd(b,a%b);
	}
	static int gcd(int a, int b) { 
		return b==0?a:gcd(b,a%b);
	}
	
	void reverse(long[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            long t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
    }
    void reverse(int[] A,int l,int r) {
        int i=l,j=r-1;
        while(i<j) {
            int t=A[i];
            A[i]=A[j];
            A[j]=t;
            i++;j--;
        }
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
