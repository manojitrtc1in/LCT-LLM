import java.io.*;
     
     
     
     
    import java.math.*;
    import java.util.*;
import java.util.concurrent.DelayQueue;    
          public class Main1
           {
            private InputStream is;
            private PrintWriter out;
            static int MOD = (int)(1e9+7);
            ArrayList<Integer>[] amp;
            public static void main(String[] args) throws Exception
            {
                new Thread(null, new Runnable()
                {
                public void run()
                {
                    try {
         } catch (Exception e)
                    {
                        System.out.println(e);
                    }
                }
            }, "1", 1 << 26).start();
                new Main1().soln();
            }
            char ch[][];
            static ArrayList<Integer>[] g=new ArrayList[100001];
            static ArrayList<Integer> ar[];
            static long ok[];    
            static int phi[]=new int[500005];
            static int dp[][];
            void solve()
            {
            	int n=ni();
            	int fr[]=new int[100001];
            	for(int i=1;i<=n;i++)
            		g[i]=new ArrayList<Integer>();
            	for(int i=1;i<n;i++)
            	{
            		int x=ni();fr[x]++;
            		g[x].add(i+1);
            		g[i+1].add(x);
            	}
            	int count=0;
            	for(int i=1;i<=n;i++)
            		if(fr[i]%2==0&&fr[i]>0)count++;
            	Queue<Integer> Q=new LinkedList();
            	Q.add(1);
            	boolean visa[]=new boolean[n+1];
            	visa[1]=true;
            	int ans=0;
            	int lol=1;
            	while(!Q.isEmpty())
            	{
            		int size=Q.size();
            		ans=0;
            		while(size>0)
            		{
            			int p=Q.poll();
            			visa[p]=true;
            			int trees=0;
            			for(int x:g[p])
            			{
            				if(!visa[x])
            				{
            					Q.add(x);
            					trees++;
            				}
            			}
            			if(trees%2==1)ans++;
            			size--;
            		}
            		if(ans%2==1)lol++;
            	}
            	out.println(lol);
 
            }
            public static void StockSpan(int a[],int n)
            {
            	Stack<Integer> st = new Stack();
            	st.push(0);
            	int S[]=new int[n];
            	S[0]=1;
            	for(int i=1;i<n;i++)
            	{
            		while(!st.isEmpty()&&a[st.peek()]<=a[i])
            			st.pop();
            		S[i]=(st.isEmpty())?(i+1):(i-st.peek());
            		st.push(i);
            	}
            	for(int i=0;i<n;i++)
            		System.out.print(S[i]+" ");
            }
            
            
            public static void MaxSum(int a[][],int r,int c)
            {
            	int ans=0;
            	for(int i=0;i<r/2;i++)
            	{
            		for(int j=0;j<c/2;j++)
            		{
            			int r1=i;
            			int c1=j;
            			int r2=r-i-1;
            			int c2=c-j-1;
            			ans+=Math.max(Math.max(a[r1][c1],a[r1][c2]),Math.max(a[r2][c1],a[r2][c2]));
            		}
            	}
            	System.out.println(ans);
            
            }
            
            
            public static void Dia(int a[][],int row,int col)
            {
            	for(int line=1;line<=(row+col-1);line++)
            	{
            		int start_col = Math.max(0,line-row);
            		int count = Math.min(line,Math.min(row,col-start_col));
            		for(int j=0;j<count;j++)
            		{
            			System.out.print(a[Math.min(row,line)-j-1][start_col+j]+" ");
            		}
            		System.out.println();
            	}
            }

			public static void AntiClock(int a[][],int n)
            
            {
            	for(int i=0;i<n;i++)
            	{
            		for(int j=i;j<n;j++)
            		{
            			int tmp=a[i][j];
            			a[i][j]=a[j][i];
            			a[j][i]=tmp;
            		}
            	}
            	for(int i=0;i<n/2;i++)
            	{
            		for(int j=0;j<n;j++)
            		{
            			int tmp=a[i][j];
            			a[i][j]=a[n-1-i][j];
            			a[n-1-i][j]=tmp;
            		}
            	}
            	
            }
            
           
            
            
            
            
            public static long pr(long x,long y,long m)
            {
            	if(y==0)
            		return 1;
            	long p = pr(x,y/2,m);
            	p=(p*p)%m;
            	return(y%2==0)?(p):(x*p%m);
            }
            public static long GCD(long x,long y)
            {
            	if(y==0)
            		return x;
            	else
            		return GCD(y,x%y);
            }
            
            public static void print(ArrayList<Integer> ar)
            {
            	Collections.sort(ar,Collections.reverseOrder());
            	System.out.println("Yes");
            	for(int x:ar)
            	{
            		System.out.print(x+" ");
            	}
            	return;
            }
            public static void LOL()
            {
            	
            }
            public static int edit(String s1,String s2,int m,int n)
            {
            	if(m==0)
            		return n;
            	if(n==0)
            		return m;
            	if(s1.charAt(m-1)==s2.charAt(n-1))
            		return edit(s1,s2,m-1,n-1);
            	return 1+Math.min(edit(s1,s2,m,n-1),Math.min(edit(s1,s2,m-1,n),edit(s1,s2,m-1,n-1)));
            }
            static int max=1;
            public static int LIS(int a[],int n  )
            {
            	if(n==1)
            		return 1;
            	int res=1;
            	int max_ending_here=1;
            	for(int i=1;i<n;i++)
            	{
            		res=LIS(a,i);
            		if(a[i-1]<a[n-1]&&res+1>max_ending_here)
            			max_ending_here=res+1;
            	}
            	max=Math.max(max,max_ending_here);
            	return max_ending_here;
            }
            static boolean visi1[];
            static int cont=0;
            static int para[];
            public static void dfs(int curr,int pr)
            {
            	visi1[curr]=true;
            	
            	int trees=0;
            	for(int x:g[curr])
            	{
            		if(!visi1[x]&&x!=pr)
            		{
            			trees++;
            			dfs(x,pr);
            		}
            	}
            	if(trees==0)cont++;
            }
            
            static boolean visited[][];
			static int a[][];
            public static long query(int v,int start,int end,int l,int r,int x)
            {
            	if(r < start || end < l)
                {
                    return 0;
                }
                if(l <= start && end <= r)
                {
                    return (tre[v]);
                }
                int mid = (start + end) / 2;
                long p1 = query(2*v, start, mid, l, r,x);
                long p2 = query(2*v+1, mid+1, end, l, r,x);
                return p1+p2;	
            }
            public static void update(int v,int tl,int tr,int index,long harami2)
            {
            	if(tl==tr)
                {
                    tre[v]=harami2;
                }
                else
                {
                    int mid=(tl+tr)/2;
                    if(tl <= index &&index <= mid)
                    {
                        update(2*v,tl, mid, index, harami2);
                    }
                    else
                    {
                        update(2*v+1,mid+1,tr, index, harami2);
                    }
                    tre[v]=tre[2*v]+tre[2*v+1];
                }
            }
            static long tre[]=new long[8000005];
          
            
            static int d,x,y;
            static void exE(int a,int b)
            {
            	if(b==0)
            	{
            		d=a;
            		x=1;
            		y=0;
            	}
            	else
            	{
            		exE(b,a%b);
            		int tmp=x;
            		x=y;
            		y=tmp - (a/b)*y;
            	}
            }
            boolean isPrime(int x)
                {
                if(x==0||x==1)
                    return false;
                for(int i = 2;i*1L*i<=x;i++) if(x%i==0) return false;
                return true;
            }
            int  p ;
            long modInverse(long a, long mOD2){
                return  power(a, mOD2-2, mOD2);
            }
            long power(long x, long y, long m)
            {
            if (y == 0)
            return 1;
            long p = power(x, y/2, m) % m;
            p = (p * p) % m;
        
            return (y%2 == 0)? p : (x * p) % m;
            }
            public static long gcd(long a, long b){
                if(b==0) return a;
                return gcd(b,a%b);
            }
            class Pair1 implements Comparable<Pair1>{
                long a;
               
                double c;
                long b;
                Pair1(long x,double z,long y){
                this.a=x;
                              this.c=z;
                              this.b=y;
                }
                public int hashCode() {
                    return Objects.hash();
                }
                
                @Override
                public int compareTo(Pair1 arg0) {
                    if(c!=arg0.c)
                	return (int)(c-arg0.c);
                    else
                    	return (int)(arg0.b-b);
                }    
            }
            long power(long x, long y, int mod){
                long ans = 1;
                while(y>0){
                    if(y%2==0){
                        x = (x*x)%mod;
                        y/=2;
                    }
                    else{
                        ans = (x*ans)%mod;
                        y--;
                    }
                }
                return ans;
            }
            void soln() {
                is = System.in;
                out = new PrintWriter(System.out);
                long s = System.currentTimeMillis();
                solve();
                out.flush();
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
            private boolean isSpaceChar(int c) {
                return !(c >= 33 && c <= 126);
            }
            private int skip() {
                int b;
                while ((b = readByte()) != -1 && isSpaceChar(b))
                    ;
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
                while (!(isSpaceChar(b))) {
                    sb.appendCodePoint(b);
                    b = readByte();
                }
                return sb.toString();
            }
            private char[] ns(int n) {
                char[] buf = new char[n];
                int b = skip(), p = 0;
                while (p < n && !(isSpaceChar(b))) {
                    buf[p++] = (char) b;
                    b = readByte();
                }
                return n == p ? buf : Arrays.copyOf(buf, p);
            }
            private int[][] nm(int n, int m) {
                int[][] map = new int[n][m];
                for (int i = 0; i < n; i++)
                {
                    for(int j=0;j<m;j++)
                        map[i][j]=ni();
                }
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
            private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
            private void tr(Object... o) {
                if (!oj)
                    System.out.println(Arrays.deepToString(o));
            }
        }  