

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import static java.lang.reflect.Array.set;
import java.math.BigInteger;
import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import static jdk.nashorn.internal.objects.Global.Infinity;
import sun.awt.HKSCS;


public class Main {
       public static  class date
        {
           Integer a;
           Integer b;
         
        public date(Integer y,Integer l) {
            this.a=y;
            this.b=l;
        }

        @Override
        public String toString() {
            return  this.a+" "+this.b;

        }
        }
        public static void main(String[] args) throws IOException{
        BufferedReader BR=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter PW=new PrintWriter(new PrintStream(System.out));
        In IN=new In(BR);
        Out OUT=new Out(PW);
        

        

        

        

        

        

        

        

        long sum=0;
        int n=IN.nextInt();
        int r=IN.nextInt();
        int avg=IN.nextInt();
        date [] arr=new date[n];
        for (int i = 0; i < n; ++i) {
           arr[i]=new date(IN.nextInt(), IN.nextInt());
           sum+=arr[i].a;
           }
        if((double)sum/(double)n>=avg){System.out.println(0);System.exit(0);}
        Arrays.parallelSort(arr,new Comparator<date>() {
            @Override
            public int compare(date o1, date o2) {
                return  o1.b.compareTo(o2.b);
            }
        });
           long ans=0;
           double curravg=(double)sum/(double)n;
           

            

            int c=0;
            boolean ye=false;
            int v=-1;
            int l=0;
            double need=(double)avg-((double)sum/(double)n);
            for (int i = 0; i < n; i++) {
                    if(arr[i].a>=r)continue;
                    c=0;
                    if((double)curravg>=(double)avg){break;}
                    
                    if((double)((sum+(r-arr[i].a)))/(double)n<=(double)avg){
                    c=r-arr[i].a;sum+=c;
                    }
                    else{
                         
                    l=arr[i].b;v=r-arr[i].a;break;
                       
                    }
                    
                    ans+=(long)((long)c*(long)arr[i].b);
                    curravg=(double)sum/(double)n;
                    

            }
            if(v!=-1){
            

            c=(int)(n*avg)-(int)sum;
              sum+=c;
              ans+=(long)((long)c*(long)l);
            }
            System.out.print(ans);
    
    }
    protected static class In {
        private BufferedReader reader;
        private StringTokenizer tokenizer = new StringTokenizer("");
        public In(BufferedReader reader) {
            this.reader = reader;
        }
        
        public String next() throws IOException {
            while (!tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(reader.readLine());
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public int[] id2(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public int[] id0(int n) throws IOException {
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++)
                a[i] = nextInt();
            return a;
        }

        public int[] id6(int n) throws IOException {
            int[] a = id2(n);
            Random r = new Random();
            for (int i = 0; i < n; i++) {
                int j = i + r.nextInt(n - i);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            Arrays.sort(a);
            return a;
        }

        public long[] id9(int n) throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

        public long[] id8(int n) throws IOException {
            long[] a = new long[n + 1];
            for (int i = 1; i <= n; i++)
                a[i] = nextLong();
            return a;
        }

        public long[] id7(int n) throws IOException {
            long[] a = id9(n);
            Random r = new Random();
            for (int i = 0; i < n; i++) {
                int j = i + r.nextInt(n - i);
                long t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            Arrays.sort(a);
            return a;
        }
    }
    protected static class Out {
        private PrintWriter writer;
        private static boolean local = System
                .getProperty("ONLINE_JUDGE") == null;

        public Out(PrintWriter writer) {
            this.writer = writer;
        }

        public void print(char c) {
            writer.print(c);
        }

        public void print(int a) {
            writer.print(a);
        }

        public void println(Object a) {
            writer.println(a);
        }

        public void println(Object[] os) {
            for (int i = 0; i < os.length; i++) {
                writer.print(os[i]);
                writer.print(' ');
            }
            writer.println();
        }

        public void println(int[] a) {
            for (int i = 0; i < a.length; i++) {
                writer.print(a[i]);
                writer.print(' ');
            }
            writer.println();
        }

        public void println(long[] a) {
            for (int i = 0; i < a.length; i++) {
                writer.print(a[i]);
                writer.print(' ');
            }
            writer.println();
        }

        public static void db(Object... objects) {
            if (local)
                System.out.println(Arrays.deepToString(objects));
        }
    }
    public static class QuickSort{ 
    protected static int [] intArray;
    protected static long [] longArray;
    protected static double [] DoubleArray;
    protected static char [] charArray;
    protected static int Size;
        public QuickSort() {
        }
     
    protected static int partition(int arr[],int low,int high)
    {
      int pivot=arr[high];
      int i=low-1;
      int temp=0;
        for (int j = low; j < high; ++j) {
            if(arr[j]<=pivot)
            {
                 ++i;
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
            }
        }
         temp = arr[i+1];
         arr[i+1] = arr[high];
         arr[high] = temp;
         return i+1;
    
    }
    protected static int partition(long arr[],int low,int high)
    {
      long pivot=arr[high];
      int i=low-1;
      long temp=0;
        for (int j = low; j < high; ++j) {
            if(arr[j]<=pivot)
            {
                 ++i;
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
            }
        }
         temp = arr[i+1];
         arr[i+1] = arr[high];
         arr[high] = temp;
         return i+1;
    
    }
    protected static int partition(double arr[],int low,int high)
    {
      double pivot=arr[high];
      int i=low-1;
      double temp=0;
        for (int j = low; j < high; ++j) {
            if(arr[j]<=pivot)
            {
                 ++i;
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
            }
        }
         temp = arr[i+1];
         arr[i+1] = arr[high];
         arr[high] = temp;
         return i+1;
    
    }
    protected static int partition(char arr[],int low,int high)
    {
      char pivot=arr[high];
      int i=low-1;
      char temp=0;
        for (int j = low; j < high; ++j) {
            if(arr[j]<=pivot)
            {
                 ++i;
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
            }
        }
         temp = arr[i+1];
         arr[i+1] = arr[high];
         arr[high] = temp;
         return i+1;
    
    }
    protected static void sort(int arr[],int low, int high)
    {
          if(low < high)
          {
              int pi=partition(arr, low, high);
              sort(arr, low, pi-1);
              sort(arr, pi+1, high);
          
          }
         
    }
   protected static void sort(long arr[],int low, int high)
    {
          if(low < high)
          {
              int pi=partition(arr, low, high);
              sort(arr, low, pi-1);
              sort(arr, pi+1, high);
          
          }
    }

    protected static void sort(double arr[],int low, int high)
    {
          if(low < high)
          {
              int pi=partition(arr, low, high);
              sort(arr, low, pi-1);
              sort(arr, pi+1, high);
          
          }
    }
    protected static void sort(char arr[],int low, int high)
    {
          if(low < high)
          {
              int pi=partition(arr, low, high);
              sort(arr, low, pi-1);
              sort(arr, pi+1, high);
          
          }
    }
    protected  static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    protected  static void printArray(char arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    protected  static void printArray(double arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
     protected  static void printArray(long arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
  }
    public static class Functions{

        public Functions() {
        }
        protected static boolean [] id1(int limit){
        boolean prime[] = new boolean[limit+1];
        for(int i=0;i<limit;i++)
            prime[i] = true;
        for(int p = 2; p*p <=limit; p++)
        {
            

            if(prime[p] == true)
            {
                

                for(int i = p*2; i <= limit; i += p)
                    prime[i] = false;
            }
        }
         return prime;
    }
    protected static boolean id5(String str1, String str2) {
        int i=0;
        for (char c : str1.toCharArray()) {
        i = str2.indexOf(c, i) + 1;
        if (i <= 0) { return false; }
    }
    return true;
    }
    protected static boolean contains(final int[] arr, final int key) {
    return Arrays.stream(arr).anyMatch(i -> i == key);
    }
    public static boolean contains(final long[] arr, final long key) {
    return Arrays.stream(arr).anyMatch(i -> i == key);
    }
    public static boolean contains(final double[] arr, final double key) {
    return Arrays.stream(arr).anyMatch(i -> i == key);
    }
    protected static long NCR(long N, long R){
    if(N < R)
        return 0;
    if(R == 0 || R == N)
        return 1;
    return NCR(N-1,R-1)+NCR(N-1,R);
    }
    protected static long NCR(int N, int R){
    if(N < R)
        return 0;
    if(R == 0 || R == N)
        return 1;
    return NCR(N-1,R-1)+NCR(N-1,R);
    }
    protected static String id4(int position, char ch, String str){
    char[] charArray = str.toCharArray();
    charArray[position] = ch;
    return new String(charArray);
    }
    protected static boolean isPrime(long n) {
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    long sqrtN = (long)Math.sqrt(n)+1;
    for(long i = 6L; i <= sqrtN; i += 6) {
        if(n%(i-1) == 0 || n%(i+1) == 0) return false;
    }
    return true;
    }
    protected static long Gcd(long p, long q) {
        if (q == 0) return p;
        else return Gcd(q, p % q);
     }
    protected static boolean isPrime(int n) {
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    int sqrtN = (int)Math.sqrt(n)+1;
    for(long i = 6L; i <= sqrtN; i += 6) {
        if(n%(i-1) == 0 || n%(i+1) == 0) return false;
    }
    return true;
    }
 }
  public static class BinarySearch{
        private static int middle;
        private static int L;
        private static int R;
        public BinarySearch() {
            
        }
        protected static int Search(int [] arr,int element){
         R=arr.length-1;
         L=0;
         return BS(arr, L, R, element);
        }
        protected static int Search(long [] arr,long element){
         R=arr.length-1;
         L=0;
         return BS(arr, L, R, element);
        }
        protected static int Search(char [] arr,char element){
         R=arr.length-1;
         L=0;
         return BS(arr, L, R, element);
        }
        protected static int Search(double [] arr,double element){
         R=arr.length-1;
         L=0;
         return BS(arr, L, R, element);
        }
         protected static int BS(int [] arr,int L,int R,int element){   
          if(R>=L)                  
          {
            middle=L+(R-L)/2;  
            if(arr[middle]==element)
            { 
                return middle;
            }    
            else if(arr[middle]>element)
            {
                return BS(arr, L,middle-1, element);
            }    
            else 
            {    
                return BS(arr, middle+1, R, element);
            }    
          } 
          else
            {
              return -1;
            }
          }
         protected static int BS(long [] arr,int L,int R,long element){   
          if(R>=L)                  
          {
            middle=L+(R-L)/2;  
            if(arr[middle]==element)
            { 
                return middle;
            }    
            else if(arr[middle]>element)
            {
                return BS(arr, L,middle-1, element);
            }    
            else 
            {    
                return BS(arr, middle+1, R, element);
            }    
          } 
          else
            {
              return -1;
            }
          }
         protected static int BS(char [] arr,int L,int R,char element){   
          if(R>=L)                  
          {
            middle=L+(R-L)/2;  
            if(arr[middle]==element)
            { 
                return middle;
            }    
            else if(arr[middle]>element)
            {
                return BS(arr, L,middle-1, element);
            }    
            else 
            {    
                return BS(arr, middle+1, R, element);
            }    
          } 
          else
            {
              return -1;
            }
          }
         protected static int BS(double [] arr,int L,int R,double element){   
          if(R>=L)                  
          {
            middle=L+(R-L)/2;  
            if(arr[middle]==element)
            { 
                return middle;
            }    
            else if(arr[middle]>element)
            {
                return BS(arr, L,middle-1, element);
            }    
            else 
            {    
                return BS(arr, middle+1, R, element);
            }    
          } 
          else
            {
              return -1;
            }
          }
    } 
    public static class DataStructure{

        public DataStructure() {
        }
    
    
     static void stack_push(Stack<Integer> stack)
    {
        for(int i = 0; i < 5; i++)
        {
            stack.push(i);
        }
    }
     
     
    

    static void stack_pop(Stack<Integer> stack)
    {
        System.out.println("Pop :");
 
        for(int i = 0; i < 5; i++)
        {
            Integer y = (Integer) stack.pop();
            System.out.println(y);
        }
    }
 
    

    static void id3(Stack<Integer> stack)
    {
        Integer element = (Integer) stack.peek();
        System.out.println("Element on stack top : " + element);
    }
     
    

    static void stack_search(Stack<Integer> stack, int element)
    {
        Integer pos = (Integer) stack.search(element);
 
        if(pos == -1)
            System.out.println("Element not found");
        else
            System.out.println("Element is found at position " + pos);
    }
    
    }
   public static class FIB {
     
    protected static int MAX = 1000;
    protected static long f[];
    protected static int size=0;
    

    

    
    public FIB(int n)
    {
        f=new long[MAX];
        this.size=n;
        fib();
    }

        protected static void fib() {
            f[0]=0;f[1]=1;
            for (int i = 2; i < size; i++) {
                

                f[i]=f[i-1]+f[i-2];
            }
        }
        protected static void printSeries(){
            for (int i = 0; i <size; i++) {
                System.out.print(f[i]+" ");
            }
        
        }
    }
    public static class Graph{
 
    
    }
}

