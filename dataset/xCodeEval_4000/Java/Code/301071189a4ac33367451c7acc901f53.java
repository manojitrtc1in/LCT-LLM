
import java.util.*;
import java.io.*;
import java.math.*;
import java.text.DecimalFormat;
public class HackerEarth{
	static long MOD=(long)Math.pow(10,9)+7;
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
	static InputReader in;
    static PrintWriter w;
    static void solve(){
        in = new InputReader(System.in);
        w = new PrintWriter(System.out);
        int n=in.nextInt();
        int m=in.nextInt();
        long arr[][]=new long[n][m];
        long arr1[][]=new long[n][m];
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		arr[i][j]=in.nextLong();
        		arr1[i][j]=arr[i][j];
        	}
        }
        

        int count=0;
        ArrayList<String> ans=new ArrayList<>();
        for(int i=0;i<n;i++){
        	long min=Long.MAX_VALUE;
        	for(int j=0;j<m;j++){
        		min=min<arr[i][j]?min:arr[i][j];
        	}
        	if(min>0){
        		count+=min;
        		for(int j=0;j<min;j++){
        			ans.add("row "+(i+1));
        		}
	        	for(int j=0;j<m;j++){
	        		arr[i][j]-=min;
	        	}
        	}
        }
        

        for(int j=0;j<m;j++){
        	long min=Long.MAX_VALUE;
        	for(int i=0;i<n;i++){
        		min=min<arr[i][j]?min:arr[i][j];
        	}
        	if(min>0){
        		count+=min;
        		for(int i=0;i<min;i++){
        			ans.add("col "+(j+1));
        		}
        		for(int i=0;i<n;i++){
            		arr[i][j]-=min;
            	}
        	}
        }
        

        int count1=0;
        ArrayList<String> ans1=new ArrayList<>();
        for(int j=0;j<m;j++){
        	long min=Long.MAX_VALUE;
        	for(int i=0;i<n;i++){
        		min=min>arr1[i][j]?arr1[i][j]:min;
        	}
        	if(min>0){
        		count1+=min;
        		for(int i=0;i<min;i++){
        			ans1.add("col "+(j+1));
        		}
        		for(int i=0;i<n;i++){
            		arr1[i][j]-=min;
            	}
        	}
        }
        

        for(int i=0;i<n;i++){
        	long min=Long.MAX_VALUE;
        	for(int j=0;j<m;j++){
        		min=min<arr1[i][j]?min:arr1[i][j];
        	}
        	if(min>0){
        		count1+=min;
        		for(int j=0;j<min;j++){
        			ans1.add("row "+(i+1));
        		}
	        	for(int j=0;j<m;j++){
	        		arr1[i][j]-=min;
	        	}
        	}
        }
        boolean flag=false;
        boolean flag1=false;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(arr[i][j]!=0){
        			flag=true;
        		}
        		if(arr1[i][j]!=0){
        			flag1=true;
        		}
        	}
        }
        if(flag&&flag1){
        	w.println("-1");
        }else{
        	if(!flag&&!flag1){
        		if(count>count1){
        			w.println(count1);
        			for(int i=0;i<ans1.size();i++){
        				w.println(ans1.get(i));
        			}
        		}else{
        			w.println(count);
        			for(int i=0;i<ans.size();i++){
        				w.println(ans.get(i));
        			}
        		}
        	}else if(!flag1){
        		w.println(count1);
    			for(int i=0;i<ans1.size();i++){
    				w.println(ans1.get(i));
    			}
        	}else{
        		w.println(count);
    			for(int i=0;i<ans.size();i++){
    				w.println(ans.get(i));
    			}
        	}
        }
    }
    static ArrayList<Integer> adj[]; 

    static int V;   

    

    static void Graph(int v){
        V = v;
        adj = new ArrayList[v];
        for (int i=0; i<v; ++i){
        	adj[i] = new ArrayList();
        }
    }
    

    static void addEdge(int u,int v){
		adj[u].add(v);
		adj[v].add(u);
    }


































































































    static long gcd(long a,long b){
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










    static int Arr[];
    static long size[];
  

    static void initialize(int N){
    	Arr=new int[N];
    	size=new long[N];
        for(int i = 0;i<N;i++){
        	Arr[ i ] = i ;
        	size[ i ] = 1;
        }
    }
    static boolean find(int A,int B){
        if( root(A)==root(B) )       

        return true;
        else
        return false;
    }
 

    static void weighted_union(int A,int B,int n){
        int root_A = root(A);
        int root_B = root(B);
        if(size[root_A] < size[root_B ]){
        	Arr[ root_A ] = Arr[root_B];
        	size[root_B] += size[root_A];
        }
        else{
        	Arr[ root_B ] = Arr[root_A];
        	size[root_A] += size[root_B];
        }
    }
    static int root (int i){
        while(Arr[ i ] != i){
            Arr[ i ] = Arr[ Arr[ i ] ] ; 
            i = Arr[ i ]; 
        }
        return i;
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
		long x=extendedEuclid(A,M)[0];
		return (x%M+M)%M;    

	}
	static long[] extendedEuclid(long A, long B) {
		if(B == 0) {
			long d = A;
			long x = 1;
			long y = 0;
			return new long[]{x,y,d};
		}
		else {
			long arr[]=extendedEuclid(B, A%B);
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
        private SpaceCharFilter filter;
 
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
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndOfLine(c));
            return res.toString();
        }
 
        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }
 
        public long[] nextLongArray(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private boolean isEndOfLine(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
	}
}