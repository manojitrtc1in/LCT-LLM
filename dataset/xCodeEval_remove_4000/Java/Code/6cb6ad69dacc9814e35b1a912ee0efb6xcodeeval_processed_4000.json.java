

    

    

 
import java.io.*;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;



 public class Tester1{

    static double eps=(double)1e-6;
    static long mod=(long)1e9+7;
    static int length = (int)1e6;
    static long d,x ,y;
    public static void main(String args[]){
        InputReader sc = new InputReader(System.in);
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        

        	int  k = sc.nextInt();
        	ArrayList<Long> a[] = new ArrayList[k];
        	ArrayList<Pair>s[] = new ArrayList[k];
        	for(int i=0;i<k;i++)
        	{
        		a[i]=new ArrayList<Long>();
        		s[i]=new ArrayList<Pair>();
        		long sum=0;
        		int n = sc.nextInt();
        		for(int j=0;j<n;j++)
        		{
        			long x = sc.nextLong();
        			a[i].add(x);
        			sum+=x;
        		}
        		
        		for(int t=0;t<n;t++)
        		{
        			s[i].add(new Pair(sum-a[i].get(t),t));
        		}
        	}
        	
        	HashMap<Long,Pair> hm = new HashMap<Long,Pair>();
        	boolean flag=false;
        	for(int i=0;i<k;i++)
        	{
        		int size = a[i].size();
        		for(int j=0;j<size;j++)
        		{
        			Pair summ = s[i].get(j);
        			if(!hm.containsKey(summ.a))
        				hm.put(summ.a,new Pair(i,j));
        			else
        			{
        				Pair p = hm.get(summ.a);
        				if(p.a!=i)
        				{
        					out.println("YES");
        					out.println((i+1)+" "+(j+1));
        					out.println((p.a+1)+" "+(p.b+1));
        					flag=true;
        					break;
        				}
        			}
        				
        		}
        		if(flag==true)
        			break;
        	}
        	if(flag==false)
        		out.println("NO");
        

        out.close();
    }
    
    public static boolean isSubstring(String s1, String s2)
    {
        int M = s1.length();
        int N = s2.length();
     
        
        for (int i = 0; i <= N - M; i++) {
            int j;
     
            
            for (j = 0; j < M; j++)
                if (s2.charAt(i + j) != s1.charAt(j))
                    break;
     
            if (j == M)
                return true;
        }
        return false;
    }
    static int id7(int hist[], int n) 
    {
        

        

        

        Stack<Integer> s = new Stack<>();
         
        int max_area = 0; 

        int tp;  

        int id10; 

      
        

        int i = 0;
        while (i < n)
        {
            

            if (s.empty() || hist[s.peek()] <= hist[i])
                s.push(i++);
      
            

            

            

            else
            {
                tp = s.peek();  

                s.pop();  

      
                

                id10 = hist[tp] * (s.empty() ? i : i - s.peek() - 1);
                System.out.println(id10);
                

                if (max_area < id10)
                    max_area = id10;
            }
        }
      
        

        

        while (s.empty() == false)
        {
            tp = s.peek();
            s.pop();
            id10 = hist[tp] * (s.empty() ? i : i - s.peek() - 1);
            System.out.println(id10);
            if (max_area < id10)
                max_area = id10;
        }
      
        return max_area;
 
    }
    private static void reverse(Stack<Integer> s)
    {
    	if(s.isEmpty())
    		return;
    	int top = s.pop();
    	reverse(s);
    	insertbottom(s,top);
    }
    private static void insertbottom(Stack<Integer> s,int t)
    {
    	if(s.isEmpty())
    		s.push(t);
    	else
    	{
    		int top = s.pop();
    		insertbottom(s,t);
    		s.push(top);
    	}
    }
    private static void swap(int[] a , int x,int y) 
    {
    	int temp = a[x];
    	a[x]=a[y];
    	a[y]=temp;
	}
	static int[] spf(int n)
    {
        int spf[] = new int[n+1];
        Arrays.fill(spf,0);
        spf[1] = 1;
     
        for (int i = 2; i <= n; i++)
        {
            if (spf[i] == 0)
            {
                spf[i] = i;
                for (int j = 2*i; j <= n; j += i)
                    if (spf[j] == 0)
                       spf[j] = i;
               
            } 
        }
        return spf;
    }
    private static boolean isPrime(long temp) {
        if(temp==0 || temp==1)
            return false;
        for(long i=2;i<Math.sqrt(temp);i++)
        {
            if(temp%i==0)
                return false;
        }
        return true;
    }
    static long modInverse(long A, long M)
    {
        id8(A,M);
        return (x%M+M)%M;    

    }
    static void id8(long A, long B) {
       
        if(B == 0) {
            d = A;
            x = 1;
            y = 0;
        }
        else {
            id8(B, A%B);
            long temp = x;
            x = y;
            y = temp - (A/B)*y;
        }
    }
   
    static void id9(int v, boolean visited[],Stack stack,ArrayList<Integer>[] adj)
        {
            

                visited[v] = true;
                Integer i;
                for(i=0;i<adj[v].size();i++)
                {
                        int temp = adj[v].get(i);
                        if (!visited[temp])
                            id9(temp, visited, stack,adj);
                }

                stack.push(new Integer(v));
        }

static void id5(int top[], int V,ArrayList<Integer>[] adj)
{
Stack stack = new Stack();


boolean visited[] = new boolean[V+1];
for (int i = 0; i <=V; i++)
visited[i] = false;


for (int i = 1; i <=V; i++)
if (visited[i] == false)
id9(i, visited, stack,adj);

int count=0;
while (stack.empty()==false)
{
    top[count]=(int) stack.pop();
    count++;
}
}
       
        public int find(int parent[],int x)
        {
            if(parent[x]==-1)
                return x;
            return find(parent,parent[x]);
        }
       
        public void union(int parent[],int x,int y)
        {
            int xset = find(parent,x);
            int yset = find(parent,y);
            parent[xset] = yset;
        }
   
   
    private static String  xor(String string, String string2) {
         String temp = "";
         for(int i=0;i<string.length();i++)
         {
             if((string.charAt(i)=='1' && string2.charAt(i)=='1') || (string2.charAt(i)=='0' && string2.charAt(i)=='0'))
                     temp+="0";
             else
                 temp+="1";   
         }
         return temp;
    }

    private static int id2(String temp) {
        

         int count=0;
         for(int i=0;i<temp.length();i++)
                if(temp.charAt(i)=='1')
                    count++;
        return count;
    }

    static int power(int x,int n)
        {
            if(n==0)
                return 1;
            else if(n%2 == 0)        

                return power(x*x,n/2);
            else                             

                return x*power(x*x,(n-1)/2);
        }
    static long ce(long x)
    {
        if(x%2!=0)
            return x/2+1;
        return x/2;
    }
    static boolean id6(String str1, String str2, int m, int n)
    {
       int j = 0;
       for (int i=0; i<n&&j<m; i++)
           if (str1.charAt(j) == str2.charAt(i))
             j++;
     
       return (j==m);
    }
   
    static long sort(int a[]) {
        int n = a.length;
        int b[] = new int[n];
        return mergeSort(a, b, 0, n - 1);
    }

    static long mergeSort(int a[], int b[], long left, long right) {
        long c = 0;
        if (left < right) {
            long mid = left + (right - left) / 2;
            c = mergeSort(a, b, left, mid);
            c += mergeSort(a, b, mid + 1, right);
            c += merge(a, b, left, mid + 1, right);
        }
        return c;
    }

    static long merge(int a[], int b[], long left, long mid, long right) {
        long c = 0;
        int i = (int) left;
        int j = (int) mid;
        int k = (int) left;
        while (i <= (int) mid - 1 && j <= (int) right) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
                c += mid - i;
            }
        }
        while (i <= (int) mid - 1)
            b[k++] = a[i++];
        while (j <= (int) right)
            b[k++] = a[j++];
        for (i = (int) left; i <= (int) right; i++)
            a[i] = b[i];
        return c;
    }
   
       
    static long fibo(long l) {
        if (l < 0) {
            throw new IllegalArgumentException("The fibo value cannot be negative");
        }

        if (l <= 1) return l;

        long[][] result = {{1, 0}, {0, 1}}; 

        long[][] id4 = {{1, 1}, {1, 0}};

        while (l > 0) {
            if (l%2 == 1) {
                multMatrix(result, id4);
            }
            l = l / 2;
            multMatrix(id4, id4);
        }

        return result[1][0];
    }

    private static void multMatrix(long[][] result, long[][] id4) {
        long a = (result[0][0]%mod * id4[0][0]%mod)%mod +  (result[0][1]%mod * id4[1][0]%mod)%mod;
        long b = (result[0][0]%mod * id4[0][1]%mod)%mod + ( result[0][1]%mod * id4[1][1]%mod)%mod;
        long c = (result[1][0]%mod * id4[0][0]%mod)%mod + ( result[1][1]%mod * id4[0][1]%mod)%mod;
        long d = (result[1][0]%mod * id4[0][1]%mod)%mod +  (result[1][1]%mod * id4[1][1]%mod)%mod;

        result[0][0] = a;
        result[0][1] = b;
        result[1][0] = c;
        result[1][1] = d;
    }
   
   
    static int[] sieve(int n)
    {
        int prime[] = new int[n+1];
        for(int i=0;i<n;i++)
            prime[i] = 1;
        prime[0]=0;
        prime[1]=0;
        for(int p = 2; p*p <=n; p++)
        {
            

            if(prime[p] == 1)
            {
                

                for(int i = p*2; i <= n; i += p)
                    prime[i] = 0;
            }
       
        }
        return prime;
    }
   
    static boolean isPal(String s)
    {
        for(int i=0, j=s.length()-1;i<=j;i++,j--)
        {
            s=s.toLowerCase();
            if(s.charAt(i)!=s.charAt(j)) return false;
        }
        return true;
    }
    public static String rev(String s)
    {
        StringBuilder sb=new StringBuilder(s);
        sb.reverse();
        return sb.toString();
    }
       
    static long lcm(long a, long b)
    {
        return a * (b / gcd(a, b));
    }
   
    static long gcd(long a, long b)
    {
        while (b > 0)
        {
            long temp = b;
            b = a % b; 

            a = temp;
        }
        return a;
    }
    static long modulo(long a,long b,long c) {
        long x=1;
        long y=a;
        while(b > 0){
            if(b%2 == 1){
                x=(x*y)%c;
            }
            y = (y*y)%c; 

            b /= 2;
        }
        return  x%c;
    }
    public static void debug(Object... o) {
        System.out.println(Arrays.deepToString(o));
    }
    static class Pair implements Comparable<Pair> {
        long a, b;

        Pair(long l, long b) {
            this.a = l;
            this.b = b;
        }

        public int compareTo(Pair o) {
            

            return Long.compare(this.b,o.b);
            

        }

        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair) o;
                return p.a == a && p.b == b;
            }
            return false;
        }

        

        public String toString() {
            return a + " " + b;
        }
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream inputstream) {
            reader = new BufferedReader(new InputStreamReader(inputstream));
            tokenizer = null;
        }

        public String nextLine(){
            String fullLine=null;
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    fullLine=reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                return fullLine;
            }
            return fullLine;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
class Graph
{
    int V;
    int E;
    Edge edge[];
    class Edge
    {
        int src,dest;
    }
    public Graph(int V,int E)
    {
        this.V=V;
        this.E=E;
        edge = new Edge[E];
        for(int i=0;i<E;i++)
            edge[i]=new Edge();
    }
}

class SegmentTree
{
    int st[]; 

 
    
    SegmentTree(int arr[], int n)
    {
        

        

        int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
 
        

        int max_size = 2 * (int) Math.pow(2, x) - 1;
 
        st = new int[max_size]; 

 
        id0(arr, 0, n - 1, 0);
    }
 
    

    int getMid(int s, int e) {
        return s + (e - s) / 2;
    }
 
    
    int id11(int ss, int se, int qs, int qe, int si)
    {
        

        

     

       

        if(qs==qe)
        

        if (se < qs || ss > qe)
            return 0;
 
        

        int mid = getMid(ss, se);
        return id11(ss, mid, qs, qe, 2 * si + 1) +
                id11(mid + 1, se, qs, qe, 2 * si + 2);
    }
 
    
    void id3(int ss, int se, int i, int diff, int si)
    {
        

        

        if (i < ss || i > se)
            return;
 
        

        

        st[si] = st[si] + diff;
        if (se != ss) {
            int mid = getMid(ss, se);
            id3(ss, mid, i, diff, 2 * si + 1);
            id3(mid + 1, se, i, diff, 2 * si + 2);
        }
    }
 
    

   

    void updateValue(int arr[], int n, int i, int new_val)
    {
        

        if (i < 0 || i > n - 1) {
            System.out.println("Invalid Input");
            return;
        }
 
        

        int diff = new_val - arr[i];
 
        

        arr[i] = new_val;
 
        

        id3(0, n - 1, i, diff, 0);
    }
 
    

   

    int getSum(int n, int qs, int qe)
    {
        

        if (qs < 0 || qe > n - 1 || qs > qe) {
            System.out.println("Invalid Input");
            return -1;
        }
        return id11(0, n - 1, qs, qe, 0);
    }
 
    

    

    int id0(int arr[], int ss, int se, int si)
    {
        

        

        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }
 
        

        

        int mid = getMid(ss, se);
        st[si] = id0(arr, ss, mid, si * 2 + 1) +
                 id0(arr, mid + 1, se, si * 2 + 2);
        return st[si];
    }
}


class id1 implements Comparator<String>
{
	@Override
	public int compare(String o1, String o2) {
		if(o1.length()<o2.length())
			return -1;
		else if(o1.length()>o2.length())
			return +1;
		return 0;
	}
	
}