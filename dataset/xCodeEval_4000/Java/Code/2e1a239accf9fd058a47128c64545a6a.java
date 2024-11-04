
import java.math.*;
import java.util.*;
import java.io.*;
 
 
 
public class main
{
  static Map<String,Integer> map=new HashMap<>();
             static int[] parent;
         static  int[] size;
    public static void main(String[] args)
    {
        InputReader in = new InputReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);
         final int mod=1000000007;
        int test_case =in.nextInt();
                    StringBuilder sb=new StringBuilder();
      for(int t1=0;t1<test_case;t1++)
      {  
          
         int a=in.nextInt();
          int b=in.nextInt();
          List<Integer> ls=new ArrayList<>();
         
        
          int max=0;
          for(int i=0;i<32;i++)
          {
              if(a>(int)Math.pow(2,i))
              {
                  max=(int)Math.pow(2,i);
              }else{
                  break;
              }
          }
        int  xor=(a&(a-1));  
          if(a==2||xor!=0)
          {
              xor=0;
              for(int i=max;i<a;i++)
              {
                  xor=xor^i;
              }
          }

          
          if(a<4)
          {
              xor=0;
              for(int i=0;i<a;i++)
              {
                  xor^=i;
              }
          }
                  
          
          
            

          
          
              if(a==b&&((a&(a-1))==0))
              {
                  if(a!=2){
                  System.out.println(a+2);
                  }else{
                                        System.out.println(a+1);
                  }
              }else{
                  
                  if(xor==b)
                  {
                      System.out.println(a);
                  }else if((xor^b)==a){
                      System.out.println(a+2);
                  }else{
                                            System.out.println(a+1);
                  }
              }
          
            
              

      }

    
        pw.flush();
        pw.close();
    }
    
    static void ProblemA2(boolean f,int c,int min,char key,Map<Character,List<Character>> map,char target,char temp,A2 a2,Set<Character>  set)
    {
                      

        
        
        if(map.containsKey(key))
        {
            
            set.add(key);
            
            for(Character value:map.get(key))
            {
                
                c++;
                
                if(set.contains(value))
                {
                    return;
                }
                
                
               

                if(value==target)
                {
                    f=f||true;
                    min=Math.min(c,min);
                 

                    a2.f=f||a2.f;
                    a2.min=Math.min(min,a2.min);
                }else if(value==temp){
                    f=f||false;
                    a2.f=f||a2.f;
                    a2.min=Math.min(min,a2.min);
                    break;
                    
                }else{
                    

                    ProblemA2(f,c,min,value,map,target,temp,a2,set);
                    
                   

                     
                }
               

               c--;
            }
            
            set.remove(key);
        }
     


        
    }
    
    static class A2{

        boolean f;
        int min=0;
        A2(boolean f,int min)
        {
            this.f=f;
            this.min=min;
        }
        
    }
    
   static boolean backtrack(int i,int j,int[][] a,int[][] gol,int n,Set<String> set,int parentx,int parenty)
    {
       System.out.println(i+" "+j);
       
        if(Arrays.equals(a,gol))
        {
            return true;
        }
        
        boolean f=false;
        
        int[] dx={-1,0,0,1};
        int[] dy={0,-1,1,0};
         set.add(i+"root"+j);
        for(int k=0;k<dx.length;k++)
        {
           
            
            
            if((i+dx[k])>=0&&(i+dx[k])<n&&(j+dy[k])>=0&&(j+dy[k])<n)
            {
                if(i+dx[k]==parentx&&j+dy[k]==parenty||set.contains((i+dx[k])+"root"+(j+dy[k])))
                {
                  continue;
                }
                
               

                int temp=a[i][j];
                a[i][j]=a[i+dx[k]][j+dy[k]];
                a[i+dx[k]][j+dy[k]]=temp;
                f=backtrack(i+dx[k],j+dy[k],a,gol,n,set,i,j);
                if(f)
                {
                    System.out.println(temp+" "+a[i][j]);
                    return f;
                }
                temp=a[i][j];
                a[i][j]=a[i+dx[k]][j+dy[k]];
                a[i+dx[k]][j+dy[k]]=temp;
            }
        }
       

        return f;
        
        
        
    }
    
    static int find_parent(int p)
    {
 
        if(p==parent[p])
        {
            return p;
        }
        return parent[p]=find_parent(parent[p]);
    }
    
    static void set_union(int x,int y)
    {
        if(size[x]<size[y])
        {
            swap(x,y);
        }
        
        parent[y]=x;
        size[x]+=size[y];
    }
    
    static boolean bipartite(int i,List<List<Integer>> ls,boolean[] visited,int[] color, int x)
    {
        
        color[i]=x;
        visited[i]=true;
        
        for(int x1:ls.get(i))
        {
            
           

            
            if(visited[x1]&&color[x1]==x)
            {
                return false;
            }
            
            if(!visited[x1])
            {
              return  bipartite(x1,ls,visited,color,(x==-1?1:-1));
            }
        }
        
        return true;
        
    }
    
    
    static boolean isDirectedCycle(List<Integer> stack,boolean[] visited,List<List<Integer>>  ls)
    {
        int i=stack.get(stack.size()-1);
        visited[i]=true;
        for(int x:ls.get(i))
        {
             stack.add(x);
            if(!visited[x]&&isDirectedCycle(stack,visited,ls))
            {
                return true;
            }
            
            if(stack.contains(x))
            {
                return true;
            }
            stack.remove(stack.size()-1);
           
            
        }
        
        return false;
    }
    
    static boolean isCyclic(int i,List<List<Integer>> ls,boolean[] visited,int parent)
    {
        visited[i]=true;
        for(int x:ls.get(i))
        {
            if(x!=parent){
                
                if(visited[x])
                {
                    return true;
                }
                
                if(!visited[x]&&isCyclic(x,ls,visited,i))
                {
                    return true;
                }
                
            }
            
            
        }
        
        return false;
    }
    
    static void dfs(List<List<Integer>> ls,boolean[] f,List<Integer> stack)
    {
        int x=stack.remove(stack.size()-1);
        System.out.print(x+"->");
        f[x]=true;
        for(int x1:ls.get(x))
        {
            if(!f[x1])
            {
                stack.add(x1);
                dfs(ls,f,stack);
            }
            
        }
        
    }
    
    static int factorial(int n,int mod)
    {
        long res = 1;
        for (int i=2; i<=n; i++)
            res=((res%mod)*(i%mod))%mod;
        return (int)res;
    }
    
 
 
    
    static int length(long l)
    {
        int c=0;
        while(l>0)
        {
            c++;
            l/=2;
        }
        
        return c;
    }
 
    
    static int CeilIndex(int A[], int l, int r, int key) 
    { 
        while (r - l > 1) { 
            int m = l + (r - l) / 2; 
            if (A[m] <= key) 
                r = m; 
            else
                l = m; 
        } 
  
        return r; 
    } 
    static int LongestIncreasingSubsequenceLength(int A[], int size) 
    { 
        

  
        int[] tailTable = new int[size]; 
        int len; 

  
        tailTable[0] = A[0]; 
        len = 1; 
        for (int i = 1; i < size; i++) { 
            if (A[i] > tailTable[0]) 
 
                tailTable[0] = A[i]; 
  
            else if (A[i] <= tailTable[len - 1]) 
 
                tailTable[len++] = A[i]; 
  
            else
 
                tailTable[CeilIndex(tailTable, -1, len - 1, A[i])] = A[i]; 
        } 
  
        return len; 
    }
    
 
    
    static int[] next(int arr[], int n) { 
 
        Stack<Integer> S = new Stack<>(); 
  
        int[] next=new int[n];
 
        for (int i = n-1; i >= 0; i--) { 
 
            while (!S.empty() && arr[S.peek()] <= arr[i]) { 
                S.pop(); 
 
            } 
            if (S.empty()) { 
                next[i]=-1;
            } 
            else 
            { 
 
                next[i]=S.peek(); 
            } 
            S.push(i); 
        } 
        return next;
    }
    static int[] back(int arr[], int n) { 
 
        Stack<Integer> S = new Stack<>(); 
  
        int[] back=new int[n];
 
        for (int i = 0; i < n; i++) { 
 
            while (!S.empty() && arr[S.peek()] < arr[i]) { 
                S.pop(); 
            } 
            if (S.empty()) { 
                back[i]=-1;
            } 
            else 
            { 
                back[i]=S.peek(); 
            } 
            S.push(i); 
        } 
        
        return back;
    }
 
    
    
 
    static class InputReader
    {
 
        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;
 
        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        public int snext()
        {
            if (snumChars == -1)
                throw new InputMismatchException();
            if (curChar >= snumChars)
            {
                curChar = 0;
                try
                {
                    snumChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (snumChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public int nextInt()
        {
            int c = snext();
            while (isSpaceChar(c))
            {
                c = snext();
            }
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = snext();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public long nextLong()
        {
            int c = snext();
            while (isSpaceChar(c))
            {
                c = snext();
            }
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = snext();
            }
            long res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = snext();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public int[] nextIntArray(int n)
        {
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextInt();
            }
            return a;
        }
        public long[] nextlongArray(int n)
        {
            long a[] = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = nextLong();
            }
            return a;
        }
 
        public String readString()
        {
            int c = snext();
            while (isSpaceChar(c))
            {
                c = snext();
            }
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = snext();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public String nextLine()
        {
            int c = snext();
            while (isSpaceChar(c))
                c = snext();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = snext();
            } while (!isEndOfLine(c));
            return res.toString();
        }
 
        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private boolean isEndOfLine(int c)
        {
            return c == '\n' || c == '\r' || c == -1;
        }
 
        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }
 
    public static long mod = 1000000007;
    public static int d;
    public static int p;
    public static int q;
 
    public static int[] suffle(int[] a,Random gen)
    {
        int n = a.length;
        for(int i=0;i<n;i++)
        {
            int ind = gen.nextInt(n-i)+i;
            int temp = a[ind];
            a[ind] = a[i];
            a[i] = temp;
        }
        return a;
    }
 
    public static void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
    }
 
    public static HashSet<Integer> primeFactorization(int n)
    {
        HashSet<Integer> a =new HashSet<Integer>();
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                a.add(i);
                n/=i;
            }
        }
        if(n!=1)
            a.add(n);
        return a;
    }
 
    public static void sieve(boolean[] isPrime,int n)
    {
        for(int i=1;i<n;i++)
            isPrime[i] = true;
 
        isPrime[0] = false;
        isPrime[1] = false;
 
        for(int i=2;i*i<n;i++)
        {
            if(isPrime[i] == true)
            {
                for(int j=(2*i);j<n;j+=i)
                    isPrime[j] = false;
            }
        }
    }
 
    public static int GCD(int a,int b)
    {
        if(b==0)
            return a;
        else
            return GCD(b,a%b);
    }
 
    public static long GCD(long a,long b)
    {
        if(b==0)
            return a;
        else
            return GCD(b,a%b);
    }
 
    public static void extendedEuclid(int A,int B)
    {
        if(B==0)
        {
            d = A;
            p = 1 ;
            q = 0;
        }
        else
        {
            extendedEuclid(B, A%B);
            int temp = p;
            p = q;
            q = temp - (A/B)*q;
        }
    }
 
    public static long LCM(long a,long b)
    {
        return (a*b)/GCD(a,b);
    }
 
    public static int LCM(int a,int b)
    {
        return (a*b)/GCD(a,b);
    }
 
    public static int binaryExponentiation(int x,int n)
    {
        int result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=result * x;
            x=x*x;
            n=n/2;
        }
        return result;
    }
    int binarySearch(int arr[], int l, int r, int x) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
  
 
            if (arr[mid] == x) 
                return mid; 
  
 
            if (arr[mid] > x) 
                return binarySearch(arr, l, mid - 1, x); 
  
 
            return binarySearch(arr, mid + 1, r, x); 
        } 
  
 
        return -1; 
    } 
  
 
    public static long binaryExponentiation(long x,long n)
    {
        long result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=result * x;
            x=x*x;
            n=n/2;
        }
        return result;
    }
 
    public static int modularExponentiation(int x,int n,int M)
    {
        int result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
        return result;
    }
 
    public static long modularExponentiation(long x,long n,long M)
    {
        long result=1;
        while(n>0)
        {
            if(n % 2 ==1)
                result=(result * x)%M;
            x=(x*x)%M;
            n=n/2;
        }
        return result;
    }
 
    public static int modInverse(int A,int M)
    {
        return modularExponentiation(A,M-2,M);
    }
 
    public static long modInverse(long A,long M)
    {
        return modularExponentiation(A,M-2,M);
    }
 
    public static boolean isPrime(int n)
    {
 
        if (n <= 1)  return false;
        if (n <= 3)  return true;
 
        if (n%2 == 0 || n%3 == 0)
            return false;
 
        for (int i=5; i*i<=n; i=i+6)
        {
            if (n%i == 0 || n%(i+2) == 0)
                return false;
        }
 
        return true;
    }
    static class Pair
    {
        int  x;
        int  y;
    }
 
    static class pair implements Comparable<pair>
    {
        Integer x, y;
        pair(int x,int y)
        {
            this.x=x;
            this.y=y;
        }
 
        public int compareTo(pair o) {
            int result = x.compareTo(o.x);
            if(result==0)
                result = y.compareTo(o.y);
 
            return result;
        }
 
        public String toString()
        {
            return x+" "+y;
        }
 
        public boolean equals(Object o)
        {
            if (o instanceof pair)
            {
                pair p = (pair)o;
                return (Math.abs(p.x-x)==0 && Math.abs(p.y-y)==0);
            }
            return false;
        }
 
        public int hashCode()
        {
            return new Long(x).hashCode()*31 + new Long(y).hashCode();
        }
    }
}