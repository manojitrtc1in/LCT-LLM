

import java.util.*;
import java.io.*;
import java.lang.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class NitsLocal {
    static ArrayList<String> s1;
    static boolean[] prime;
    static int n = (int)1e7;
    
     static void sieve() {
Arrays.fill(prime	, true);
prime[0] = prime[1] = false;
for(int i = 2 ; i * i <= n ; ++i) {
if(prime[i]) {
for(int k = i * i; k<= n ; k+=i) {
prime[k] = false;
}
}
}
 
}
    public static void main(String[] args) {
        InputReader sc = new InputReader(System.in);
        n *= 2;
           prime  = new boolean[n + 1];
           

                prime[1] = false;
              
                  
             
             
                 int n = sc.ni();
                 a = new ArrayList[n+1];
                 vis = new boolean[n+1];
                 level = new int[n+1];
                 parent = new int[n+1];
                 for(int i=1;i<=n;i++)
                 {
                     a[i] = new ArrayList<>();
                 }
                 int root = -1;
                   for(int i=0;i<n-1;i++)
                   {
                       int u = sc.ni();
                       if(root == -1)
                       root = u;
                       int v = sc.ni();
                       a[u].add(v);
                       a[v].add(u);
                   }
                
             bfs(root);
               int ans = -1;
               int max = -1;
               for(int i=1;i<=n;i++)
               {
                   max = Math.max(max,level[i]);
               }
               int ans1 = -1;
               int res1 = -1;
               int res2 = -1;
               int ans2 = -1;
               int f = 0;
               for(int i=1;i<=n;i++)
               {
                   if(level[i] == max)
                   {
                       
                           ans = i;
                           break;
                      
                   }
                   
               }
              level = new int[n+1];
              vis = new boolean[n+1];
              parent = new int[n+1];
              max = -1;
              bfs(ans);
              int y = -1;
              int diam = 0;
               for(int i=1;i<=n;i++)
               {
                   max = Math.max(max,level[i]);
               }
               diam = max;
                for(int i=1;i<=n;i++)
                  {
                      if(level[i] == diam-1)
                      {
                          ans2 = i;
                          break;
                      }
                  }
              for(int i=1;i<=n;i++)
               {
                   if(level[i] == max)
                   {
                       
                          y = i;
                           break;
                      
                   }
                   
               }
               temp = new boolean[n+1];
               temp[y] = true;
               ans1= y;
               int z = y;
                 while(z!=parent[z])
               {
                   temp[parent[z]] = true;
                   z = parent[z];
               }
               

               vis =new boolean[n+1];
               int min = 0;
               while(y!=parent[y])
               {
                  
                   

                   Student t1 = bfs1(y,parent[y]);
                    
                   if(min < t1.id)
                   {
                       min = t1.id;
                       ans2 = t1.b;
                   }
                   

                
                   y = parent[y];
               }
             temp[parent[y]] = true;
            
             
               
                
               
               res1 = ans1;
               res2 = ans2;
              
                 
              
    
               w.println(diam+min);
               w.println(ans + " " + res1 + " " +res2);
               
   
       w.close();
       
        
    }
   static int []level;
   static boolean []vis;
   static int []parent;
   static ArrayList<Integer> []a;
   static boolean []temp;
   static Student bfs1(int s,int p)
   {
      vis[s] = true;
     level[s] = 0;
     int max = 0;
     int ind = -1;
    

     Queue<Integer> q = new LinkedList<>();
     q.add(s);
     while(q.size() > 0)
     {
          int cc = q.poll();
          
            

            Iterator itr = a[cc].iterator();
            while(itr.hasNext())
            {
                Integer e = (Integer) itr.next();
                

                 
                if(!vis[e] && e != parent[cc] && !temp[e])
                {
                  
                  q.add(e);
                  
                    level[e] = level[cc]+1;
                    vis[e] = true;
                    if(max < level[e])
                    {
                        max = level[e];
                        ind = e;
                    }
                    max = Math.max(max,level[e]);
                   
                    

                }
            }
     
                  
     
                  
     }
     return new Student(max,ind);
   }
   
   
 static void bfs(int s)
 {
     vis[s] = true;
     level[s] = 0;
     parent[s] = s;
     Queue<Integer> q = new LinkedList<>();
     q.add(s);
     while(q.size() > 0)
     {
          int cc = q.poll();
          
            

            Iterator itr = a[cc].iterator();
            while(itr.hasNext())
            {
                Integer e = (Integer) itr.next();
                

                 
                if(!vis[e])
                {
                    
                  q.add(e);
                  
                    level[e] = level[cc]+1;
                    vis[e] = true;
                    parent[e] = cc;
                }
            }
     
                  
     }
 }
     static int upperBound(ArrayList<Integer> a, int low, int high, int element){
    while(low < high){
        int middle = low + (high - low)/2;
        if(a.get(middle) > element)
            high = middle;
        else 
            low = middle + 1;
    }
    return low;
}
   static long func(long t,long e,long h,long a, long b)
   {
       if(e*a >= t)
           return t/a;
       else
       {
           return e + Math.min(h,(t-e*a)/b);
       }
   }
         
      
    public static int upperBound(int []arr,int n,int num)
    {
        int l = 0;
        int r = n;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(num >= arr[mid])
            {
                l = mid +1;
            }
            else
                r = mid;
        }
        return l;
    }
    public static int countSetBits(int number){
        int count = 0;
        while(number>0){
            ++count;
            number &= number-1;
        }
        return count;
    }
    
     
      
 
    
    static HashSet<Integer> fac;
    public static void primeFactors(int n) 
    { 
        

        int t = 0;
        while (n%2==0) 
        { 
            fac.add(2);
            n /= 2; 
        } 
  
        

        

        for (int i = 3; i*i <= n; i+= 2) 
        { 
            

            while (n%i == 0) 
            { 
                fac.add(i);
                n /= i; 
            } 
        } 
  
        

        

        if (n > 2) 
            fac.add(n);
    } 
     static long modexp(long x,long n,long M)
{
    long power = n;
    long result=1;
    x = x%M;
    while(power>0)
    {
        if(power % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        power = power/2;
    }
    return result;
}
      static long modInverse(long A,long M)
{
    return modexp(A,M-2,M);
}
    static long gcd(long a,long b)
    {
        if(a==0)
            return b;
        else
            return gcd(b%a,a);
    }
    static class Temp{
        int a;
        int b;
        int c;
        int d;
      
        Temp(int a,int b,int c,int d)
        {
            this.a = a;
            this.b = b;
            this.c  =c;
            this.d = d;
            

        }
    }
   
    
    
   static long sum1(int t1,int t2,int x,int []t)
   {
       int mid = (t2-t1+1)/2;
  if(t1==t2)
      return 0;
    
   else
   return sum1(t1,mid-1,x,t) + sum1(mid,t2,x,t);
    
     
   }
  
   
    static String replace(String s,int a,int n)
    {
        char []c = s.toCharArray();
        for(int i=1;i<n;i+=2)
        {
            int num = (int) (c[i] - 48);
            num += a;
            num%=10;
            c[i] = (char) (num+48);
        }
        return new String(c);
    }
    static String move(String s,int h,int n)
    {
        h%=n;
        char []c = s.toCharArray();
        char []temp = new char[n];
        for(int i=0;i<n;i++)
        {
            temp[(i+h)%n] = c[i];
        }
        return new String(temp);
    }
    
     public static int ip(String s){
return Integer.parseInt(s);
}
     static class multipliers implements Comparator<Long>{
  
         
  public int compare(Long a,Long b) {
   if(a<b)
    return 1;
   else if(b<a)
    return -1;
   else
    return 0;
  }
 }
     
     static class multipliers1 implements Comparator<Student>{
  
  public int compare(Student a,Student b) {
   if(a.id<b.id)
    return -1;
   else if(b.id<a.id)
    return 1;
   else
   {
       if(a.b < b.b)
           return -1;
       else if(b.b<a.b)
           return 1;
       else
           return 0;
           
    

   }
  }

 }

    



 
    
    
    
      static class InputReader {
 
private final InputStream stream;
private final byte[] buf = new byte[8192];
private int curChar, snumChars;
 
public InputReader(InputStream st) {
this.stream = st;
}
 
public int read() {
if (snumChars == -1)
throw new InputMismatchException();
if (curChar >= snumChars) {
curChar = 0;
try {
snumChars = stream.read(buf);
} catch (IOException e) {
throw new InputMismatchException();
}
if (snumChars <= 0)
return -1;
}
return buf[curChar++];
}
 
public int ni() {
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
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
 
public long nl() {
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
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
 
public int[] nia(int n) {
int a[] = new int[n];
for (int i = 0; i < n; i++) {
a[i] = ni();
}
return a;
}
 
public String rs() {
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
 
public String nextLine() {
int c = read();
while (isSpaceChar(c))
c = read();
StringBuilder res = new StringBuilder();
do {
res.appendCodePoint(c);
c = read();
} while (!isEndOfLine(c));
return res.toString();
}
 
public boolean isSpaceChar(int c) {
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
 
private boolean isEndOfLine(int c) {
return c == '\n' || c == '\r' || c == -1;
}
 
}
 
 
 
 
 
   
static PrintWriter w = new PrintWriter(System.out);
                  static class Student
    {
        int id;
        

       
       int b;
      
        

        
        Student(int id,int b)
        {
            this.id = id;
            

            

            this.b = b;
          
           

            
            
            
           
        }
        
    }
}