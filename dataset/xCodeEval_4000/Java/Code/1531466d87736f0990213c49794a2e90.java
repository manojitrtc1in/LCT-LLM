import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import static java.util.stream.IntStream.of;

public final class Code2 {

    static FastIO2 rd = new FastIO2();
    static Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static Random rand = new Random();

    public static void main(String[] args) {
        try {

            


            
            int t=nxti();
            while(t-->0){
                int inp[] = nxtira();
                long x=inp[0];
                long y=inp[1];
                long k=inp[2];


                long sticks = (k*(y+1)-1);

                long ans = sticks/(x-1);



                if(sticks%(x-1)!=0)ans++;

                prln(ans+k);

                
                

            }


            

            

            

            


            flush();
            close();


        } catch (Exception e) {rd.println(e);}

    }

    public static boolean check(int[] a,int sum) {

        int tempsum=0;
        for (int i = 0; i < a.length-1; i++) {
            tempsum+=a[i];
            if(tempsum==(sum/2)) return true;
        }
        return false ;
    }

    public static void swap(int[] a,int i) {

        int temp=i;

    }
    

    
    
    
    
    static void dbgra(int[] a) {prln(Arrays.toString(a));}
    static void dbgra(long[] a) {prln(Arrays.toString(a));}
    static void dbgra(String[] a) {prln(Arrays.toString(a));}
    static void dbgra(char[] a) {prln(Arrays.toString(a));}
    static void dbgra(Integer[] a) {prln(Arrays.toString(a));}
    static void dbgra(Set<Integer> a) {prln(a.toString());}
    static void dbgral(ArrayList<Integer> al) {prln(al.toString());}
    static void dbgrall(ArrayList<Long> al) {prln(al.toString());}
    static void dbgrald(ArrayList<Double> al) {prln(al.toString());}
    static void dbgrals(ArrayList<String> al) {prln(al.toString());}
    
    public static int[] sort(int[] arr) {
        if (arr.length <= 20) {
            


        } else {
            

            
        }
        
        return arr;
    }
    
    

    static int count = 0, temp = 0, max = 0, min = 0, sum = 0, fact = 1, prod = 1, n,m,k;
    
    static int size = 0;
    static char c, ch;
    static String str = new String();
    static String str1 = new String();
    static String[] ras = new String[size];
    static int[] rai = new int[size];
    static int[] arr = new int[size];
    static long[] ral = new long[size];
    static ArrayList<String> rals = new ArrayList<>();
    static ArrayList<Integer> rali = new ArrayList<>();
    static ArrayList<Integer> al = new ArrayList<>();
    static ArrayList<Integer> al1 = new ArrayList<>();
    static ArrayList<Integer> al2 = new ArrayList<>();
    static ArrayList<Long> rall = new ArrayList<>();
    static ArrayList<Double> rald = new ArrayList<>();
    
    

    

    

    

    

    

    static final int IBIG = 1000000007;
    static final int IRAND = 327859546;
    static final int IMAX = 2147483647;
    static final int IMIN = -2147483648;
    static final long LMAX = 9223372036854775807L;
    static final long LMIN = -9223372036854775808L;
    
    

    static int min(int a,int b){return a<b?a:b;}
    static long min(long a,long b){return a<b?a:b;}
    static int max(int a,int b){return a>b?a:b;}
    static long max(long a,long b){return a>b?a:b;}
    static int minof(int a, int b, int c) {return min(a, min(b, c));}
    static int min(int... x) {if(x.length == 1) return x[0]; if(x.length == 2) return min(x[0], x[1]); if(x.length == 3) return min(x[0], min(x[1], x[2])); int min = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] < min) min = x[i]; return min;}
    static long min(long a, long b, long c) {return min(a, min(b, c));}
    static long min(long... x) {if(x.length == 1) return x[0]; if(x.length == 2) return min(x[0], x[1]); if(x.length == 3) return min(x[0], min(x[1], x[2])); long min = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] < min) min = x[i]; return min;}
    static int max(int a, int b, int c) {return max(a, max(b, c));}
    static int max(int... x) {if(x.length == 1) return x[0]; if(x.length == 2) return max(x[0], x[1]); if(x.length == 3) return max(x[0], max(x[1], x[2])); int max = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] > max) max = x[i]; return max;}
    static long max(long a, long b, long c) {return max(a, max(b, c));}
    static long max(long... x) {if(x.length == 1) return x[0]; if(x.length == 2) return max(x[0], x[1]); if(x.length == 3) return max(x[0], max(x[1], x[2])); long max = x[0]; for(int i = 1; i < x.length; ++i) if(x[i] > max) max = x[i]; return max;}
    static int max(ArrayList<Integer> al) {return Collections.max(al);}
    static int min(ArrayList<Integer> al) {return Collections.min(al);}
    static int count(int n){return floori(Math.log10(n))+1;}
    static int count(long n){return (int)(Math.floor(Math.log10(n))+1);}
    static int count(String s , char c){int count=0;for (int i = 0; i < s.length(); i++) {if(s.charAt(i)==c)count++;}return count;}
    static int count(char[] s , char c){int count=0;for (int i = 0; i < s.length; i++) {if(s[i]==c)count++;}return count;}
    static int count(int[] s , int c){int count=0;for (int i = 0; i < s.length; i++) {if(s[i]==c)count++;}return count;}
    static int count(long[] s , long c){int count=0;for (int i = 0; i < s.length; i++) {if(s[i]==c)count++;}return count;}
    static int count(double[] s , double c){int count=0;for (int i = 0; i < s.length; i++) {if(s[i]==c)count++;}return count;}
    static int count(List<String> s , String c){int count=0;for (int i = 0; i < s.size(); i++) {if(s.get(i)==c)count++;}return count;}
    static int[] countAll(String s){int[] alpha = new int[26];for (int i = 0; i < s.length(); i++) {alpha[(int)s.charAt(i)-97]++;}return alpha;}
    static int powi(int a, int b) {if(a == 0) return 0; int ans = 1; while(b > 0) {if((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static long powl(long a, int b) {if(a == 0) return 0; long ans = 1; while(b > 0) {if((b & 1) > 0) ans *= a; a *= a; b >>= 1;} return ans;}
    static int sqrt(int n){return (int)Math.sqrt(n);}
    static long sqrt(long n){return (long)Math.sqrt(n);}
    static double sqrt(double n){return Math.sqrt(n);}
    static int floori(double d) {return (int)Math.floor(d);}
    static int ceili(double d) {return (int)Math.ceil(d);}
    static long floorl(double d) {return (long)Math.floor(d);}
    static long ceill(double d) {return (long)Math.ceil(d);}
    static long lcm(long a, long b) {return (a * b) / gcd(a, b);}
    static long gcd(long a, long b) {if (a == 0)return b; return gcd(b % a, a);}
    static int lcm(int a, int b) {return (a * b) / gcd(a, b);}
    static int gcd(int a, int b) {if (a == 0)return b; return gcd(b % a, a);}
    static boolean prime(int n) {for (int i = 2; i <= sqrt(n); i++) {if(n%i==0)return false;}return true ;}
    static int randInt(int min, int max) {return rand.nextInt(max - min + 1) + min;}
    
    

    static boolean vowel(char c) {if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')return true; else return false ;}
    static void reverse(int[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {int swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(long[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {long swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(double[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {double swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void reverse(char[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {char swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static <T> void reverse(T[] a) {for(int i = 0, n = a.length, half = n / 2; i < half; ++i) {T swap = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = swap;}}
    static void shuffle(int[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); int swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(long[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); long swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(double[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); double swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void shuffle(char[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); char swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static <T> void shuffle(T[] a) {int n = a.length - 1; for(int i = 0; i < n; ++i) {int ind = randInt(i, n); T swap = a[i]; a[i] = a[ind]; a[ind] = swap;}}
    static void rsort(int[] a) {shuffle(a); Arrays.sort(a);}
    static void rsort(long[] a) {shuffle(a); Arrays.sort(a);}
    static void rsort(double[] a) {shuffle(a); Arrays.sort(a);}
    static void rsort(char[] a) {shuffle(a); Arrays.sort(a);}
    static <T> void rsort(T[] a) {shuffle(a); Arrays.sort(a);}
    static String leftPad(String str , int n , String s){String temp="";for (int i = 0; i < n-str.length(); i++) {temp+=s;} temp+=str; return temp;}
    static String rightPad(String str , int n , String s){for (int i = 0; i < n-str.length(); i++) {str+=s;}return str;}
    

    

    static int nxti() throws NumberFormatException, IOException {return rd.nextInt();}
    static long nxtl() throws NumberFormatException, IOException {return rd.nextLong();}
    static double nxtd() throws NumberFormatException, IOException {return rd.nextDouble();}
    static char nxtc() throws NumberFormatException, IOException {return rd.nextChar();}
    static String nxt() throws IOException {return rd.next();}
    static int[] nxtira() throws NumberFormatException, IOException {return rd.nextIntArray();}
    

    

    

    

    


    

    static void pr(int i) {rd.print(i);}
    static void prln(int i) {rd.println(i);}
    static void pr(long l) {rd.print(l);}
    static void prln(long l) {rd.println(l);}
    static void pr(double d) {rd.print(d);}
    static void prln(double d) {rd.println(d);}
    static void pr(char c) {rd.print(c);}
    static void prln(char c) {rd.println(c);}

    static void prln() {rd.println();}
    static void prln(char[] c) {rd.println(c);}
    static void pr(String s) {rd.print(s);}
    static void prln(String s) {rd.println(s);}
    static void pr(Object o) {System.out.print(o);}
    static void prln(Object o) {System.out.println(o);}
    static void pry() {rd.println("yes");}
    static void prYes() {rd.println("Yes");}
    static void prY() {rd.println("YES");}
    static void prn() {rd.println("no");}
    static void prNo() {rd.println("No");}
    static void prN() {rd.println("NO");}
    static void pryn(boolean b) {rd.println(b ? "yes" : "no");};
    static void prYesNo(boolean b) {System.out.println(b ? "Yes" : "No");}
    static void prYN(boolean b) {System.out.println(b ? "YES" : "NO");}
    static void pr(int[] a){rd.print(a);}
    static void prln(int[] a){rd.println(a);}
    static void pr(long[] a){rd.print(a);}
    static void prln(long[] a){rd.println(a);}
    static void pr(double[] a){rd.print(a);}
    static void prln(double[] a){rd.println(a);}
    static void prln(char[][] a){rd.println(a);}
    static void prln(boolean[][] a){rd.println(a);}
    

    

    

    static void flush() {rd.flush();}
    static void close() {rd.close();}
}



class FastIO2{

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);


    public static String next() throws IOException {
        String s = br.readLine();
        return s;
    }

    public static int nextInt() throws NumberFormatException, IOException {
        int n = Integer.parseInt(next());
        return n;
    }

    public static long nextLong() throws NumberFormatException, IOException {
        long n = Long.parseLong(next());
        return n;
    }

    public static double nextDouble() throws NumberFormatException, IOException {
        double n = Double.parseDouble(next());
        return n;
    }

    public static char nextChar() throws NumberFormatException, IOException {
        String s = next();
        char c = s.charAt(0);
        return c;
    }

    public static int[] nextIntArray() throws NumberFormatException, IOException {
        String[] s = next().split(" ");
        int size=s.length;
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i]=Integer.parseInt(s[i]);
        }
        return a;
    }
    public static long[] nextLongArray() throws NumberFormatException, IOException {
        String[] s = next().split(" ");
        int size=s.length;
        long[] a = new long[size];
        for (int i = 0; i < size; i++) {
            a[i]=Long.parseLong(s[i]);
        }
        return a;
    }
    public static double[] nextDoubleArray() throws NumberFormatException, IOException {
        String[] s = next().split(" ");
        int size=s.length;
        double[] a = new double[size];
        for (int i = 0; i < size; i++) {
            a[i]=Double.parseDouble(s[i]);
        }
        return a;
    }




    public void print(int n){out.print(n);}
    public void print(long n){out.print(n);}
    public void print(float n){out.print(n);}
    public void print(double n){out.print(n);}
    public void print(char n){out.print(n);}
    public void print(String n){out.print(n);}
    public void print(boolean n){out.print(n);}
    public void print(Object n){out.print(n);}
    public void print(char[] c){out.print(c);}
    public void print(int[] a){
        for (int i = 0; i < a.length; i++) {
            if(i!=(a.length-1))out.print(a[i]+" ");
            else out.println(a[i]);
        }
    }
    public void print(long[] a){
        for (int i = 0; i < a.length; i++) {
            if(i!=(a.length-1))out.print(a[i]+" ");
            else out.println(a[i]);
        }
    }
    public void print(double[] a){
        for (int i = 0; i < a.length; i++) {
            if(i!=(a.length-1))out.print(a[i]+" ");
            else out.println(a[i]);
        }
    }
    public void print(String[] a){
        for (int i = 0; i < a.length; i++) {
            if(i!=(a.length-1))out.print(a[i]+" ");
            else out.println(a[i]);
        }
    }



    public void println(){out.println();}
    public void println(int s){out.println(s);}
    public void println(long s){out.println(s);}
    public void println(float s){out.println(s);}
    public void println(double s){out.println(s);}
    public void println(char s){out.println(s);}
    public void println(String s){out.println(s);}
    public void println(boolean s){out.println(s);}
    public void println(Object s){out.println(s);}
    public void println(char[] s){out.println(s);}
    public void println(int[] a){
        for (int i = 0; i < a.length; i++) {
            out.println(a[i]);
        }
    }
    public void println(long[] a){
        for (int i = 0; i < a.length; i++) {
            out.println(a[i]);
        }
    }
    public void println(double[] a){
        for (int i = 0; i < a.length; i++) {
            out.println(a[i]);
        }
    }
    public void println(String[] a){
        for (int i = 0; i < a.length; i++) {
            out.println(a[i]);
        }
    }
    public void println(int[][] c){
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                print(c[i][j] + " ");
            }
            println();
        }
    }
    public void println(long[][] c){
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                print(c[i][j] + " ");
            }
            println();
        }
    }
    public void println(double[][] c){
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                print(c[i][j] + " ");
            }
            println();
        }
    }
    public void println(char[][] c){
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                print(c[i][j] + " ");
            }
            println();
        }
    }
    public void println(boolean[][] c){
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                print(c[i][j] + " ");
            }
            println();
        }
    }


    public void flush(){out.flush();};
    public void close(){out.close();};
}