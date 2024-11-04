
import java.util.*;
import java.io.*;
import java.math.*;
public class id4{
	static long mod=(long)Math.pow(10,9)+7l;
	public static void main(String args[]) {
        new Thread(null, new Runnable() {
            public void run() {
                try{
                    solve();
                    w.close();
                }
                catch(Exception e){
                    e.printStackTrace();
                }
            }
        }, "1", 1 << 26).start();
	}
	static InputReader in=new InputReader(System.in);
    static PrintWriter w=new PrintWriter(System.out);
    char ch[][];
	

	int n1, n2, k1, k2, M;
	static ArrayList<Integer>[] g;
	static long ok[];	
	static int phi[]=new int[500005];

	static void solve(){
            int n=in.nextInt();
            int a[]=in.id1(n);
            int b[]=Arrays.copyOf(a,n);
            Arrays.sort(b);
            g=new ArrayList[n+1];
            HashMap<Integer,Integer> hm=new HashMap();
            for(int i=0;i<n;i++)
            {
            	hm.put(a[i],i+1);
            }
            for(int i=1;i<=n;i++)
            	g[i]=new ArrayList<Integer>();
            for(int i=0;i<n;i++)
            {
            	int x=hm.get(b[i]);
            	g[i+1].add(x);
            	g[x].add(i+1);
            }
            ans=new ArrayList[n+1];
            for(int i=0;i<=n;i++)
            	ans[i]=new ArrayList<Integer>();
            for(int i=1;i<=n;i++)
            {
            	if(!visited[i])
            	{
            		dfs(i);
            		count++;
            	}
            }
            w.println(count);
            for(int i=0;i<count;i++)
            {
            	w.print(ans[i].size()+" ");
            	for(int x:ans[i])
            	{
            		w.print(x+" ");
            	}
            	w.println();
            }
}
	static ArrayList<Integer> ans[];
	static int count=0;
	private static void dfs(int curr) {
		visited[curr]=true;
		ans[count].add(curr);
		for(int x:g[curr])
		{
			if(!visited[x])
			{
				dfs(x);
			}
		}
	}
	static boolean visited[]=new boolean[100005];

        

    public static void id7(int[] arr){
        int n = arr.length,ans=0;
        for(int i=0;i<n;i++) {
        		if(arr[i]==i+1) {
        			w.println("1 "+arr[i]);
        			ans++;
        		}
        }
        

        

        

        ArrayList <Pair> arrpos =new ArrayList <Pair> ();
        for (int i = 0; i < n; i++)
             arrpos.add(new Pair(arr[i], i));
        

        

        

        arrpos.sort(new Comparator<Pair>(){
            @Override
            public int compare(Pair o1,Pair o2){
                if (o1.first < o2.first)
                    return -1;
                

                

                else if (o1.second==(o2.second))
                    return 0;
                else
                    return 1;
            }
        });
        

        

        Boolean[] vis = new Boolean[n];
        Arrays.fill(vis, false);
        

        

        for (int i = 0; i < n; i++){
            

            

            if (vis[i] || arrpos.get(i).second == i)
                continue;
            

            

            int j = i;
            HashSet<Integer> set=new HashSet<>();
            while (!vis[j]){
                vis[j] = true;
                

                j = arrpos.get(j).second;
                set.add(j+1);
            }
            if(set.size()>0) {
	            	ans++;
	            w.print(set.size()+" ");
	            for(int jack:set) {
	            		w.print(jack+" ");
	            }
	            w.println();
            }
            

        }
        

        System.out.println(ans);
    }
    static class Pair{
    		int first;
    		int second;
    		public Pair(int first,int second) {
    			this.first=first;
    			this.second=second;
    		}
    }
    static int Arr[];
    static void initialize(int n) {
    		Arr=new int[n];
    		for(int i=0;i<n;i++)
    			Arr[i]=i;
    }
    static int root(int i){
        while(Arr[ i ] != i){
        		i = Arr[ i ];
        }
        return i;
    }
    
    static void union(int A ,int B) {
        int root_A = root(A);       
        int root_B = root(B);  
        Arr[ root_A ] = root_B ;       

    }
    static boolean find(int A,int B){
        if( root(A)==root(B) )       

        		return true;
        else
        		return false;
    }
    static void delete_edge(int A,int B) {
    		int parent_A=Arr[A];
    		int parent_B=Arr[B];
    		if(parent_A==B) {
    			Arr[A]=A;
    		}else {
    			Arr[B]=B;
    		}
    }


















































































































































































    static int gcd(int a,int b){
		if(a==0){
			return b;
		}
		return gcd(b%a,a);
	}
    static long power(long base, long exponent, long modulus){
	    long result = 1L;
	    while (exponent > 0) {
	        if (exponent % 2L == 1L)
	            result = (result * base) % modulus;
	        exponent = exponent >> 1;
	        base = (base * base) % modulus;
	    }
	    return result;
	}
    static HashMap<Long,Long> primeFactors(long n){
        HashMap<Long,Long> ans=new HashMap<Long,Long>();
    	

        while (n%2L==0L)
        {
            if(ans.containsKey(2L)){
            	ans.put(2L,ans.get(2L)+1L);
            }else{
            	ans.put(2L,1L);
            }
            n /= 2L;
        }
 
        

        

        for (long i = 3; i <= Math.sqrt(n); i+= 2L)
        {
            

            while (n%i == 0)
            {
            	if(ans.containsKey(i)){
                	ans.put(i,ans.get(i)+1L);
                }else{
                	ans.put(i,1L);
                }
                n /= i;
            }
        }
 
        

        

        if (n > 2)
            ans.put(n,1L);
        return ans;
    }


	static void sieve(int N) {
	 boolean isPrime[]=new boolean[N+1];
	 isPrime[0] = true;
	 isPrime[1] = true;
	 for(int i = 2; i * i <= N; ++i) {
	      if(isPrime[i] == false) {

	          for(int j = i * i; j <= N ;j += i)
	              isPrime[j] = true;
	     }
	 }
	}










    
    
 
	static boolean isPrime(long n) {
		if(n < 2L) return false;
		if(n == 2L || n == 3L) return true;
		if(n%2L == 0 || n%3L == 0) return false;	
		long sqrtN = (long)Math.sqrt(n)+1L;
		for(long i = 6L; i <= sqrtN; i += 6L) {
			if(n%(i-1) == 0 || n%(i+1) == 0) return false;
		}
		return true;
	}




	static int maxlevel=0;
	












































































	
 
	 
	

    static int minPrime[];
	static void minimumPrime(int n){
		minPrime=new int[n+1];
		minPrime[1]=1;
        for (int i = 2; i * i <= n; ++i) {
            if (minPrime[i] == 0) {         

                for (int j = i * i; j <= n; j += i) {
                    if (minPrime[j] == 0) {
                        minPrime[j] = i;
                    }
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (minPrime[i] == 0) {
                minPrime[i] = i;
            }
        }
	}
	static long modInverse(long A, long M)
	{
		long x=id3(A,M)[0];
		return (x%M+M)%M;    

	}
	static long[] id3(long A, long B) {
		if(B == 0) {
			long d = A;
			long x = 1;
			long y = 0;
			return new long[]{x,y,d};
		}
		else {
			long arr[]=id3(B, A%B);
			long temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp - (A/B)*arr[1];
			return arr;
		}
	}
 
	static class InputReader {
        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, numChars;
        private id5 filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
        
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public String nextLine() {
            int c = read();
            while (id0(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!id2(c));
            return res.toString();
        }
 
        public String readString() {
            int c = read();
            while (id0(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!id0(c));
            return res.toString();
        }
 
        public long nextLong() {
            int c = read();
            while (id0(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id0(c));
            return res * sgn;
        }
 
        public int nextInt() {
            int c = read();
            while (id0(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id0(c));
            return res * sgn;
        }
 
        public int[] id1(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }
 
        public long[] id6(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }
 
        public boolean id0(int c) {
            if (filter != null)
                return filter.id0(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private boolean id2(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
        public interface id5 {
            public boolean id0(int ch);
        }
	}
}