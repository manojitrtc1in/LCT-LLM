import java.util.*;
import java.io.*;
import java.math.*;
public class Solution{
static FastScanner sc;
static PrintWriter pw;
static void pn(Object o){pw.println(o);}
static void p(Object o){pw.print(o);}
static Random rand = new Random();


    

    

    

 
    

    static final int IBIG = 1000000007;
    static final int IMAX = 2147483647;
    static final int IMIN = -2147483648;
    static final long LMAX = 9223372036854775807L;
    static final long LMIN = -9223372036854775808L;
    

    static int minof(int a, int b, int c) {return min(a, min(b, c));}
    static int minof(int... x) {if (x.length == 1) return x[0]; if (x.length == 2) return min(x[0], x[1]); if (x.length == 3) return min(x[0], min(x[1], x[2])); int min = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i]; return min;}
    static long minof(long a, long b, long c) {return min(a, min(b, c));}
    static long minof(long... x) {if (x.length == 1) return x[0]; if (x.length == 2) return min(x[0], x[1]); if (x.length == 3) return min(x[0], min(x[1], x[2])); long min = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] < min) min = x[i]; return min;}
    static int maxof(int a, int b, int c) {return max(a, max(b, c));}
    static int maxof(int... x) {if (x.length == 1) return x[0]; if (x.length == 2) return max(x[0], x[1]); if (x.length == 3) return max(x[0], max(x[1], x[2])); int max = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i]; return max;}
    static long maxof(long a, long b, long c) {return max(a, max(b, c));}
    static long maxof(long... x) {if (x.length == 1) return x[0]; if (x.length == 2) return max(x[0], x[1]); if (x.length == 3) return max(x[0], max(x[1], x[2])); long max = x[0]; for (int i = 1; i < x.length; ++i) if (x[i] > max) max = x[i]; return max;}
    static int powi(int a, int b) {if (a == 0) return 0; int ans = 1; while (b > 0) {if ((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static long powl(long a, int b) {if (a == 0) return 0; long ans = 1; while (b > 0) {if ((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static int fli(double d) {return (int) d;}
    static int cei(double d) {return (int) Math.ceil(d);}
    static long fll(double d) {return (long) d;}
    static long cel(double d) {return (long) Math.ceil(d);}
    static int gcf(int a, int b) {return b == 0 ? a : gcf(b, a % b);}
    static long gcf(long a, long b) {return b == 0 ? a : gcf(b, a % b);}
    static int lcm(int a, int b) {return a * b / gcf(a, b);}
    static long lcm(long a, long b) {return a * b / gcf(a, b);}
    static int randInt(int min, int max) {return rand.nextInt(max - min + 1) + min;}
    static long mix(long x) {x += 0x9e3779b97f4a7c15L; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9L; x = (x ^ (x >> 27)) * 0x94d049bb133111ebL; return x ^ (x >> 31);}
    

    static void reverse(int[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {int swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(int [] a, int n, int k)
    {
        if (k > n)
        {
            System.out.println( "Invalid k");
            return;
        }
     
        

        

        for (int i = 0; i < k / 2; i++)
        {
            int tempswap = a[i];
                a[i] = a[k - i - 1];
                a[k - i - 1] = tempswap;            
        }
    }
    static void reverse(long[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {long swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(double[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {double swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(char[] a) {for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {char swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void shuffle(int[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); int swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(long[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); long swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(double[] a) {int n = a.length - 1; for (int i = 0; i < n; ++i) {int ind = randInt(i, n); double swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void rsort(int[] a) {shuffle(a); Arrays.parallelSort(a);}
    static void rsort(long[] a) {shuffle(a); Arrays.parallelSort(a);}
    static void rsort(double[] a) {shuffle(a); Arrays.parallelSort(a);}
    static int[] copy(int[] a) {int[] ans = new int[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static long[] copy(long[] a) {long[] ans = new long[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static double[] copy(double[] a) {double[] ans = new double[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    static char[] copy(char[] a) {char[] ans = new char[a.length]; for (int i = 0; i < a.length; ++i) ans[i] = a[i]; return ans;}
    

    static List<List<Integer>> g(int n) {List<List<Integer>> g = new ArrayList<>(); for (int i = 0; i < n; ++i) g.add(new ArrayList<>()); return g;}
    static List<Set<Integer>> sg(int n) {List<Set<Integer>> g = new ArrayList<>(); for (int i = 0; i < n; ++i) g.add(new HashSet<>()); return g;}
    static void c(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v); g.get(v).add(u);}
    static void cto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).add(v);}
    static void dc(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v); g.get(v).remove(u);}
    static void dcto(List<? extends Collection<Integer>> g, int u, int v) {g.get(u).remove(v);}
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    static void pr(int i) {pw.print(i);}
    static void prln(int i) {pw.println(i);}
    static void pr(long l) {pw.print(l);}
    static void prln(long l) {pw.println(l);}
    static void pr(double d) {pw.print(d);}
    static void prln(double d) {pw.println(d);}
    static void pr(char c) {pw.print(c);}
    static void prln(char c) {pw.println(c);}
    static void pr(char[] s) {pw.print(new String(s));}
    static void prln(char[] s) {pw.println(new String(s));}
    static void pr(String s) {pw.print(s);}
    static void prln(String s) {pw.println(s);}
    static void pr(Object o) {pw.print(o);}
    static void prln(Object o) {pw.println(o);}
    static void prln() {pw.println();}
    static void pryes() {prln("yes");}
    static void pry() {prln("Yes");}
    static void prY() {prln("YES");}
    static void prno() {prln("no");}
    static void prn() {prln("No");}
    static void prN() {prln("NO");}
    static void id10(boolean b) {prln(b ? "yes" : "no");};
    static void pryn(boolean b) {prln(b ? "Yes" : "No");}
    static void prYN(boolean b) {prln(b ? "YES" : "NO");}
    static void prln(int... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(long... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static void prln(double... a) {for (int i = 0, len = a.length - 1; i < len; pr(a[i]), pr(' '), ++i); if (a.length > 0) prln(a[a.length - 1]); else prln();}
    static <T> void prln(Collection<T> c) {int n = c.size() - 1; Iterator<T> iter = c.iterator(); for (int i = 0; i < n; pr(iter.next()), pr(' '), ++i); if (n >= 0) prln(iter.next()); else prln();}
    static void h() {prln("hlfd"); flush();}
    static void flush() {pw.flush();}
    static void close() {pw.close();}
static boolean arr[] = sieve(1000001);
static int mod = (int) (1e9+7);
static ArrayList<Long> primes = new ArrayList<>();
static ArrayList<Integer> id0 = new ArrayList<>();
static ArrayList<Integer> perfectSquares = new ArrayList<>();















        public static void solve()
        {
            

            

            

            

            

            

            
            long a= sc.l(),b=sc.l();
            if(b==1){pn("NO");return;}
            long x=a,y=(2*b-1)*a;
            if(x!=y)
            {
                pn("YES\n"+x+" "+y+" "+(x+y));return;
            }
        }
            public static void main(String[] args) throws FileNotFoundException {


            sc = new FastScanner();
            pw = new PrintWriter(System.out);
            

            

            

            

            

            

            

            int tc = sc.i(); 
            for(int t=0;t<tc;t++)
            {
                

                solve();
            }
            pw.close();
        }

        

		
        

        

        

        

        

        

        

        

          static int id8(char X[], char Y[],int m, int n)
          {
                

                

                

                

                

                

                

                

                

                

                

                int LCStuff[][] = new int[m + 1][n + 1];
        
                

                

                int result = 0;
        
                

                

                for (int i = 0; i <= m; i++)
                {
                    for (int j = 0; j <= n; j++)
                    {
                        if (i == 0 || j == 0)
                            LCStuff[i][j] = 0;
                        else if (X[i - 1] == Y[j - 1])
                        {
                            LCStuff[i][j]
                                = LCStuff[i - 1][j - 1] + 1;
                            result = Integer.max(result,
                                                LCStuff[i][j]);
                        }
                        else
                            LCStuff[i][j] = 0;
                    }
                }
                return result;
            }


            static boolean id6(String str1, String str2,
            int m, int n)
            {
                

                if (m == 0)
                return true;
                if (n == 0)
                return false;

                

                if (str1.charAt(m - 1) == str2.charAt(n - 1))
                return id6(str1, str2, m - 1, n - 1);

                

                return id6(str1, str2, m, n - 1);
            }
        static boolean id7(long n)
        {
            long temp=n;
            while(temp>0)
            {
                long digit = temp%10;
                temp/=10;
                if(digit!=0&&n%digit!=0)return false;
            }
            return true;
        }
        static int id4(int n)
        {
            int cnt = 0;
            for(int i=1;i*i<=n;i++)
            {
                if(n%i==0)cnt++;
                id0.add(i);
            }
            return cnt;
        }

        static ArrayList<Integer> id5(int n)
        {
            for(int i=1;i*i<=n;i++)
            {
                if(n%i==0)
                id0.add(i);
            }
            return id0;
        }

        static boolean id3(String s)
        {
            for(int i=0;i<s.length()-1;i++)
            {
                if(s.charAt(i)>s.charAt(i+1))return false;
            }
            return true;
        }

        static boolean id9(String s)
        {
            String temp = "";
            for(int i=s.length()-1;i>=0;i--)
            {
                temp+=s.charAt(i)+"";
            }
            return ((s.equals(temp))?true:false);
        }
        static boolean isSorted(int[] a)
        {
            int n = a.length;
            for(int i=1;i<n;i++)
            {
                if(a[i-1]>=a[i])return false;
            }
            return true;
        }
        static boolean solution(int n,int x)
        {
            int sum=0;
            while(n>0)
            {
                int digit=n%10;
                n/=10;
                sum+=digit;
            }
            return (sum==x)?true:false;
        }
        static ArrayList<Integer> perfectSquares(int n) 
        { 
            ArrayList<Integer> al = new  ArrayList<Integer>();
            for(int i=1;i<=n;i++)
            {
                al.add(i*i);
            }
            return al; 
        } 
    static boolean id2(String s)
    {
        for(int i=1;i<s.length();i++)
        {
            if(s.charAt(i)!=s.charAt(i-1))return false;
        }
        return true;
    }
    static String reverseString(String s,int x)
    {
        String ans="",temp = s.substring(0,x);
        for(int i=x;i<s.length();i++)
        {
            ans = s.charAt(i)+ans;
        }
        return temp+ans;
    }
    static boolean checker(int num)
    {
        String s = num+"";
        if(s.contains("0"))return false;
        int temp = num;
        while(num>0)
        {
            int digit = num%10;
            num/=10;
            if(temp%digit==0)return false;
        }
        return true;
    }
    static boolean palindrome(int n)
    {
        int temp=n,rev=0;
        while(n>0)
        {
            int digit=n%10;
            n/=10;
            rev = rev*10+digit;
        }
        return (temp==rev)?true:false;
    }
    
    static boolean id1(String s)
    {
        Stack<Character>st = new Stack<>();
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s.charAt(i)=='(')st.push('(');
            else
            {
                if(st.size()==0)return false;
                else st.pop();
            }
        }
        return (st.size()==0)?true:false;
    }
    


    

    

    

    

    

    

    

    

   static boolean[] sieve(int n)
   {
   	boolean[] isPrime = new boolean[n+1];
   	Arrays.fill(isPrime,true);
   	isPrime[0]=false;
   	isPrime[1]=false;
   	for(int i=2;i*i<=n;i++)
   	{
   		for(int j=i*i;j<=n;j+=i)
   		{
   			isPrime[j]=false;
   		}
   	}
   	return isPrime;
   }
   static int[][] graph(int from[], int to[], int n)
   {
       int g[][] = new int[n][];
       int cnt[] = new int[n];
       for (int i = 0; i < from.length; i++) {
           cnt[from[i]]++;
           cnt[to[i]]++;
       }
       for (int i = 0; i < n; i++) {
           g[i] = new int[cnt[i]];
       }
       Arrays.fill(cnt, 0);
       for (int i = 0; i < from.length; i++) {
           g[from[i]][cnt[from[i]]++] = to[i];
           g[to[i]][cnt[to[i]]++] = from[i];
       }
       return g;
   }
   
   static class Pair implements Comparable<Pair>{

       int x,y,z;
       
       Pair (int x,int y,int z){
           this.x=x;
           this.y=y;
           this.z=z;
       }
           
       public int compareTo(Pair o) {
           if (this.x == o.x)
               return Integer.compare(this.y,o.y);
           return Integer.compare(this.x,o.x);
           

       }

       public boolean equals(Object o) {
           if (o instanceof Pair) {
               Pair p = (Pair)o;
               return p.x == x && p.y == y;
           }
           return false;
       }
       public int hashCode() {
           return new Integer(x).hashCode() * 31 + new Integer(y).hashCode();
       }
       
       @Override
       public String toString() {
           return x + " " + y;
       }
   
   } 
   
   static String rev(String s) {
       StringBuilder sb = new StringBuilder(s);
       sb.reverse();
       return sb.toString();
   }

   static long gcd(long x, long y) {
       if (y == 0) {
           return x;
       } else {
           return gcd(y, x % y);
       }
   }

   static int gcd(int x, int y) {
       if (y == 0) {
           return x;
       } else {
           return gcd(y, x % y);
       }
   }
   
   static int abs(int a, int b) {
       return (int) Math.abs(a - b);
   }

   static long abs(long a, long b) {
       return (long) Math.abs(a - b);
   }
   static void swap(int a,int b)
   {
       int c = b;
       b=a;
       a=c;
   }
   static int max(int a, int b) {
       if (a > b) {
           return a;
       } else {
           return b;
       }
   }

   static int min(int a, int b) {
       if (a > b) {
           return b;
       } else {
           return a;
       }
   }

   static long max(long a, long b) {
       if (a > b) {
           return a;
       } else {
           return b;
       }
   }

   static long min(long a, long b) {
       if (a > b) {
           return b;
       } else {
           return a;
       }
   }

   static long pow(long n, long p, long m) {
       long result = 1;
       if (p == 0) {
           return 1;
       }
       while (p != 0) {
           if (p % 2 == 1) {
               result *= n;
           }
           if (result >= m) {
               result %= m;
           }
           p >>= 1;
           n *= n;
           if (n >= m) {
               n %= m;
           }
       }
       return result;
   }

   static long pow(long n, long p) {
       long result = 1;
       if (p == 0) {
           return 1;
       }
       if (p == 1) {
           return n;
       }
       while (p != 0) {
           if (p % 2 == 1) {
               result *= n;
           }
           p >>= 1;
           n *= n;
       }
       return result;
   }
  
   static void debug(Object... o) {
           System.out.println(Arrays.deepToString(o));
   }


    


    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
 
        public FastScanner() throws FileNotFoundException {
            
            if (System.getProperty("ONLINE_JUDGE") == null) {
                

                    br = new BufferedReader(new FileReader("input.txt")); 
    
                    

                    

                    PrintStream pw = new PrintStream(new FileOutputStream("output.txt"));
                    System.setOut(pw);
              }
            else
            {
                

                br = new BufferedReader(new InputStreamReader(System.in), 32768);
                st = null;
            }
            
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
 
        int i() {
            return Integer.parseInt(next());
        }
 
        int[] intArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++)
                ret[i] = i();
            return ret;
        }
 
        long l() {
            return Long.parseLong(next());
        }
 
        long[] longArray(int N) {
            long[] ret = new long[N];
            for (int i = 0; i < N; i++)
                ret[i] = l();
            return ret;
        }
 
        double d() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
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