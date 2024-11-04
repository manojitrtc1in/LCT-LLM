

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;

import java.util.*;
import java.io.*;
import java.math.*;



public class Main{

    static int mod = (int) (Math.pow(10, 9)+7);
	static final int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
	static final int[] dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 };
	static final int[] dx9 = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy9 = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

	static final double eps = 1e-10;
	static List<Integer> primeNumbers = new ArrayList<>();

    public static void main(String[] args) throws IOException{
        MyScanner sc = new MyScanner();
        

        out = new PrintWriter(new BufferedOutputStream(System.out));
        

     
        

        int test = sc.nextInt();
        while(test --> 0){
            int n = sc.nextInt();
            long[] len = new long[n];
            for(int i = 0; i < n; i++) len[i] = sc.nextLong();
            
            long[] up = new long[n];
            long[] down = new long[n];

            for(int i= 0; i < n; i++) up[i] = sc.nextLong();
            for(int i= 0; i < n; i++) down[i] = sc.nextLong();

            

            for(int i= 0; i < n; i++){
                if(up[i] > down[i]) swap(up, down, i);
            }

            

            long ans = 0;
            long past = 0;

            for(int i = n-1; i >= 0; i--){

                

                if(i == n-1){
                    past = len[i];
                    continue;
                }

                

                ans = max(ans, past + (down[i+1] - up[i+1] + 1L));
                if(up[i+1] != down[i+1]){
                    long stop = len[i];
                    long keepon = past + (len[i] - (down[i+1] - up[i+1]-1L));
                    

                    past = max(stop, keepon);
                }else{
                    past = len[i];
                }
        
            }

            out.println(ans);

        }

        out.close();
    }

    public static void swap(long[] fir, long[] sec, int index){
        long curr = fir[index];
        fir[index] = sec[index];
        sec[index] = curr;
    }

    

    

    

    

    


 

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    


    

    public static class Graph{
        public int V;
        public ArrayList<ArrayList<Integer>> edges;

        

        Graph(int V){
            this.V  = V;
            edges = new ArrayList<>(V+1);
            for(int i= 0; i <= V; i++){
                edges.add(new ArrayList<>());
            }
        }

        public void addEdge(int from , int to){
            edges.get(from).add(to);
        }
    }

    

    public static class id0 {
        int[] rank, parent;
        int n;
      
        public id0(int n)
        {
            rank = new int[n];
            parent = new int[n];
            Arrays.fill(rank, 1);
            Arrays.fill(parent,-1);
            this.n = n;
        }
      
        public int find(int curr){
            if(parent[curr] == -1)
                return curr;
 
            

            return parent[curr] = find(parent[curr]);
        }
 
        public void union(int a, int b){
            int s1 = find(a);
            int s2 = find(b);
 
            if(s1 != s2){
                if(rank[s1] < rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }
    }

    

    public static long powerMOD(long x, long y)
    {
        long res = 1L;    
        while (y > 0)
        {
            

            if ((y & 1) != 0){
                x %= mod;
                res %= mod;
                res = (res * x)%mod;
            }
            

            y = y >> 1; 

            x%= mod;
            x = (x * x)%mod;  

        }
        return res%mod;
    }

    

    public static long power(long x, long y)
    {
        long res = 1L;     
        while (y > 0)
        {
            

            if ((y & 1) != 0){
                res = (res * x);
            }
            

            y = y >> 1; 

            x = (x * x);
        }
        return res;
    }

    public static class segmentTree{

        public long[] arr;
        public long[] tree;
        public long[] lazy;

        segmentTree(long[] array){
            int n = array.length;
            arr = new long[n];
            for(int i= 0; i < n; i++) arr[i] = array[i];
            tree = new long[4*n + 1];
            lazy = new long[4*n + 1];
        }

        public  void build(int[]arr, int s, int e, int[] tree, int index){

            if(s == e){
                tree[index] = arr[s];
                return;
            }
    
            

            int mid = (s+e)/2;
            build(arr, s, mid, tree, 2*index);
            build(arr, mid+1, e, tree, 2*index+1);
    
            

            tree[index] = Math.min(tree[2*index], tree[2*index+1]);
        }
    
        public  int query(int sr, int er, int sc, int ec, int index, int[] tree){
            
            if(lazy[index] != 0){
                tree[index] += lazy[index];
    
                if(sc != ec){
                    lazy[2*index+1] += lazy[index];
                    lazy[2*index] += lazy[index];
                }
    
                lazy[index] = 0;
            }
            
            

            if(sr > ec || sc > er) return Integer.MAX_VALUE;
    
            

            if(sr <= sc && ec <= er) return tree[index];
    
            

            int mid = (sc + ec)/2;
            int left = query(sr, er, sc, mid, 2*index, tree);
            int right = query(sr, er, mid+1, ec, 2*index + 1, tree);
    
            return Integer.min(left, right);
        }
    
        

        

        public  void update(int index, int indexr, int increment, int[] tree, int s, int e){
    
            if(lazy[index] != 0){
                tree[index] += lazy[index];
    
                if(s != e){
                    lazy[2*index+1] = lazy[index];
                    lazy[2*index] = lazy[index];
                }
                
                lazy[index] = 0;
            }
    
            

            if(indexr < s || indexr > e) return;
    
            

            if(s == e){
                tree[index] += increment;
                return;
            } 
    
            

            int mid = (s+e)/2;
            update(2*index, indexr, increment, tree, s, mid);
            update(2*index+1, indexr, increment, tree, mid+1, e);
    
            

            tree[index] = Math.min(tree[2*index+1], tree[2*index]);
        }
    
        public  void rangeUpdate(int[] tree , int index, int s, int e, int sr, int er, int increment){
    
            

            if(e < sr || er < s) return;
    
            

            if(s == e){
                tree[index] += increment;
                return;
            }
    
            

            int mid = (s+e)/2;
            rangeUpdate(tree, 2*index, s, mid, sr, er, increment);
            rangeUpdate(tree, 2*index + 1, mid+1, e, sr, er, increment);
    
            

            

            tree[index] = Math.min(tree[2*index], tree[2*index + 1]);
        }
        
        public  void id6(int[] tree, int index, int s, int e, int sr, int er, int increment){
            
            

            

            if(lazy[index] != 0){
                tree[index] += lazy[index];
    
                if(s != e){
                    lazy[2*index+1] += lazy[index];
                    lazy[2*index] += lazy[index];
                }
    
                lazy[index] = 0;
            }
    
            

            if(sr > e || s > er) return;
    
            

            if(sr <= s && er >= e){
                tree[index] += increment;
    
                if(s != e){
                    lazy[2*index+1] += increment;
                    lazy[2*index] += increment;
                }
                return;
            }
    
            

            int mid = (s + e)/2;
            id6(tree, 2*index, s, mid, sr, er, increment);
            id6(tree, 2*index + 1, mid+1, e, sr, er, increment);
    
            tree[index] = Math.min(tree[2*index+1], tree[2*index]);
            return;
    
        }
    
    }

    

    public static void id1(int n){
        BitSet bitset = new BitSet(n+1);
        for(long i = 0; i < n ; i++){
            if (i == 0 || i == 1) {
                bitset.set((int) i);
                continue;
            }
            if(bitset.get((int) i)) continue;
            primeNumbers.add((int)i);
            for(long j = i; j <= n ; j+= i)
                bitset.set((int)j);
        }
    }

    

    public static int id3(long number){
        if(number == 1) return 1;
        List<Integer> primeFactors = new ArrayList<>();
        int index = 0;
        long curr = primeNumbers.get(index);
        while(curr * curr <= number){
            while(number % curr == 0){
                number = number/curr;
                primeFactors.add((int) curr);
            }    
            index++;
            curr = primeNumbers.get(index);
        }

        if(number != 1) primeFactors.add((int) number);
        int current = primeFactors.get(0);
        int id8 = 1;
        int currentCount = 2;
        for (int i = 1; i < primeFactors.size(); i++) {
            if (primeFactors.get(i) == current) {
                currentCount++;
            } else {
                id8 *= currentCount;
                currentCount = 2;
                current = primeFactors.get(i);
            }
        }
        id8 *= currentCount;
        return id8;
    }

    

    public static boolean id5(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
          if (p[a] < p[a + 1])
            for (int b = p.length - 1;; --b)
              if (p[b] > p[a]) {
                int t = p[a];
                p[a] = p[b];
                p[b] = t;
                for (++a, b = p.length - 1; a < b; ++a, --b) {
                  t = p[a];
                  p[a] = p[b];
                  p[b] = t;
                }
                return true;
              }
        return false;
    }

    

    public static long id4(int n, int r)
    {
        long p = 1, k = 1;
        if (n - r < r) r = n - r;

        if (r != 0) {
            while (r > 0) {
                p *= n;
                k *= r;
                long m = id9(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }
        else {
            p = 1;
        }
        return p;
    }

    

    public static boolean id2(char c)
    {
        return (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' ||     c=='u' || c=='U');
    }   

    

	public static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

    

    public static void sort(long[] a) {
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
    

    public static int id7(int n, int k)
    {
        int C[] = new int[k + 1];
        

        C[0] = 1;
        for (int i = 1; i <= n; i++) {
            

            

            for (int j = Math.min(i, k); j > 0; j--)
                C[j] = C[j] + C[j - 1];
        }
        return C[k];
    }

    

    public static class Pair{
        public int a;
        public int b;

        Pair(int a , int b){
            this.a = a;
            this.b = b;
        }

        @Override
        public String toString(){
            return a + " -> " + b; 
        }
    }

    

    public static class Triplet{

        public int a;
        public int b;
        public int c;

        Triplet(int a , int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public String toString(){
            return a + " -> " + b; 
        }
    }

    

    public static long lcm(long a , long b){
        return a * (b/gcd(a,b));
    }

    

    public static int lcm(int a , int b){
        return (a * b)/gcd(a,b);
    }

    

    public static int gcd(int a, int b){
        if(b == 0)
            return a;
            
        return gcd(b , a%b);
    }

    

    public static long gcd(long a, long b){
        if(b == 0)
            return a;

        return gcd(b , a%b);
    }

     

     public static long id9(long n1, long n2)
     {
         long gcd = 1;
         for (int i = 1; i <= n1 && i <= n2; ++i) {
             

             if (n1 % i == 0 && n2 % i == 0) {
                 gcd = i;
             }
         }
         return gcd;
     }

    

    public static void swap(int[] arr, int left , int right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    

    public static void swap(char[] arr, int left , int right){
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    

    public static void reverse(int[] arr){
        int left = 0;
        int right = arr.length-1;

        while(left <= right){
            swap(arr, left,right);
            left++;
            right--;
        }
    }

     
    

    public static PrintWriter out;
      
    

    public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        

        

        

    
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
    
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
   

}