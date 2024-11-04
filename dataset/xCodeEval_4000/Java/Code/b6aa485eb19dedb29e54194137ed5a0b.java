

import java.io.*;
import java.util.*;
public class Stoned{
    static final long modp =1000000007;
    static long x_ec=1,y_ec=0,d_ec =1;
    static long maxi=0;
    static boolean v1 =false ,v2 = false;
    static InputReader in = new InputReader(System.in);
    static OutputStream outputStream = System.out;
    static OutputWriter out = new OutputWriter(outputStream);


   
   
    public static void main (String args[]) throws IOException {
        int t= in.readInt();
        int c=1;
        while(t-->0)
        {
            int n= in.readInt();
           
            PriorityQueue<Integer> que = new PriorityQueue<>((o1,o2)->{
                return o2-o1;
            });
            int sum = 0;
            for(int i= 0;i<n ;i++)
            {  int y= in.readInt();
                que.add(y);
                sum +=y; 
            }
            String winner ="amit";
            int ltop=0,hltop=0;
            int turn =0;
            while(sum>=0)
            {  if(turn%2==0)
                { que.add(ltop);
                    ltop = que.poll();
                    if(ltop==0)
                    { winner ="HL";
                      break;
                    }
                    ltop--;
                    sum--;
                     

                }
                else
                { que.add(hltop);
                    hltop = que.poll();
                    if(hltop==0)
                    { winner ="T";
                    break;

                    }
                    hltop--;
                    sum --;

                }
                turn ++;

            }
            out.println(winner);
            
            
            


        }




      
    out.close();
}
    
    
    

    

    static long modExponential(long x,long n)
        {long result =1l;
            while(n>0l)
            { if(n%2==1)
                result =(x*result)%modp;
                x= (x*x)%modp;
             n=n/2;
            }
            return result;
        }
      
    
    public static long gcd(long a,long b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    public static int gcd(int a,int b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    public static int abs(int a,int b)
    {
        return (int)Math.abs(a-b);
    }
    public static long abs(long a,long b)
    {
        return (long)Math.abs(a-b);
    }
    public static int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    public static int min(int a,int b)
    {
        if(a>b)
            return b;
        else 
            return a;
    }
    public static long max(long a,long b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    public static long min(long a,long b)
    {
        if(a>b)
            return b;
        else 
            return a;
    }
     
    
    
    
    
    
    static class Pair implements Comparable<Pair>
    {
        int a,b;
        Pair (int a,int b)
        {
            this.a=a;
            this.b=b;
        }
     
        public int compareTo(Pair o) {
            
            if(this.a!=o.a)
            return -Integer.compare(this.a,o.a);
            else
                return Integer.compare(this.b, o.b);
            

        }
        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair)o;
                return p.a == a && p.b == b;
            }
            return false;
        }
    
    
        public int hashCode(Object o) {
            Pair p = (Pair)o;
            return p.a* 31 +p.b;
        }
    
    } 
    
    static class Pair1 implements Comparable<Pair1>
    {
       char a;
       int b;
        Pair1 (char a,int b)
        {
            this.a=a;
            this.b=b;
        }
     
        public int compareTo(Pair1 o) {
            
            if(this.a!=o.a)
            return Integer.compare(this.a,o.a);
            else
                return Integer.compare(this.b, o.b);
            

        }
        public boolean equals(Object o) {
            if (o instanceof Pair1) {
                Pair1 p = (Pair1)o;
                return p.a == a && p.b == b;
            }
            return false;
        }
    
    
        public int hashCode(Object o) {
            Pair1 p = (Pair1)o;
            return (int)p.a* 31 +(int)p.b;
        }
    
    } 
    
    
        

}
class Gnode{
    int value;
    List<Gnode> neighbours;
    Gnode(int x)
   {value=x;
    neighbours =new ArrayList<>();
   }
   
   }
 class Node{
       int value;
       Node left;
       Node right;
       Node(int qw){
           this.value = qw;
           this.left = null;
           this.right = null;
       }
   }
   
   class SegTree{
       long[] seg;
       int[] map;
       long[] arr;
       SegTree(int n,long[] a){
           seg=new long[4*n];
           arr=a;
           map=new int[n+1];
       }
       void build(int low,int high, int pos) {
           if(low==high) {
               map[low]=pos;
               seg[pos]=arr[low];
           }
           else {
               int middle=(low+high)/2;
               build(low,middle,2*pos+1);
               build(middle+1,high,2*pos+2);
               seg[pos]=Math.max(seg[2*pos+1], seg[2*pos+2]);
           }
       }
       void update(int low,int high, int pos,int elpos, long value) {
           if(low==high) {
               seg[pos]=value;
           }
           else {
               int middle=(low+high)/2;
               if(elpos<=middle) {
                   update(low,middle,2*pos+1,elpos,value);
               }
               else update(middle+1,high,2*pos+2,elpos,value);
               seg[pos]=Math.max(seg[2*pos+1], seg[2*pos+2]);
           }
       }
   }

class MinHeap {
   int size;
   int maxsize;
   int heap[];
   MinHeap(int maxsize,int size)           

   {this.size=size;
    this.maxsize= maxsize;
    heap = new int[maxsize];

   }
   boolean isEmpty()
   {return size==0;
}
   int peek()
   {if(isEmpty())
     return -99999;
     return heap[0];

   }
   int remove()
   {if(isEmpty())
    return -99999;
    int minItem = heap[1];
    heap[1]= heap[size];
    size --;
    heapifyDown(1);
    return minItem;
   }
    void print()
    {
      System.out.println(Arrays.toString(heap)); 
    }
   boolean add( int item)
   {  if(size>= maxsize)
          return false;
          heap[size+1]= item;
          size++;
          heapifyUp(size);
          return true;

   }
    void heapifyDown( int i)
    { int left = 2*i;
        int right = 2*i +1;
        int smallest =i;
        if(left<= size  && heap[left]<heap[smallest])
          smallest =left;
          if(right<= size  && heap[right]<heap[smallest])
          smallest =right;
          if(smallest!=i)
          {  int temp =heap[i];
             heap[i]= heap[smallest];
             heap[smallest]=temp;
             heapifyDown(smallest);

          }

    }
    void heapifyUp( int i)
    {
        int parent = i/2;
        if( parent>0 && heap[parent]>heap[i])
        { int temp =heap[parent];
            heap[parent]= heap[i];
            heap[i]=temp;
            heapifyUp(parent);

        }
    }}
    class MaxHeap {
        int size;
        int maxsize;
        int heap[];
        MaxHeap(int maxsize,int size)           

        {this.size=size;
         this.maxsize= maxsize;
         heap = new int[maxsize];
     
        }
        void buildHeap(int arr[])
        {size = arr.length+1;
         for(int i=0;i<arr.length;i++)
        heap[i+1]= arr[i];
        for( int i=size/2;i>=1;i--)
        {heapifyDown(i);
            
        }

         
        }
        boolean isEmpty()
        {return size==0;
     }
        int peek()
        {if(isEmpty())
          return -99999;
          return heap[0];
     
        }
        int remove()
        {if(isEmpty())
         return -99999;
         int minItem = heap[1];
         heap[1]= heap[size];
         size --;
         heapifyDown(1);
         return minItem;
        }
         void print()
         {
           System.out.println(Arrays.toString(heap)); 
         }
        boolean add( int item)
        {  if(size>= maxsize)
               return false;
               heap[size+1]= item;
               size++;
               heapifyUp(size);
               return true;
     
        }
         void heapifyDown( int i)
         { int left = 2*i;
             int right = 2*i +1;
             int largest =i;
             if(left<= size  && heap[left]>heap[largest])
               largest =left;
               if(right<= size  && heap[right]>heap[largest])
               largest =right;
               if(largest!=i)
               {  int temp =heap[i];
                  heap[i]= heap[largest];
                  heap[largest]=temp;
                  heapifyDown(largest);
     
               }
     
         }
         void heapifyUp( int i)
         {
             int parent = i/2;
             if( parent>0 && heap[parent]<heap[i])
             { int temp =heap[parent];
                 heap[parent]= heap[i];
                 heap[i]=temp;
                 heapifyUp(parent);
     
             }
         }







}
 class InputReader
{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
 
    public InputReader(InputStream stream)
    {
        this.stream = stream;
    }
 
    public int read()
    {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars)
        {
            curChar = 0;
            try
            {
                numChars = stream.read(buf);
            } catch (IOException e)
            {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
 
    public int readInt ()
    {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-')
        {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do
        {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public String readString ()
    {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do
        {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }
    public String readLine() {
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
    
 
    public double readDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, readInt());
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }
    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
    public boolean isSpaceChar(int c)
    {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    public String next()
    {
        return readString();
    }
 
    public interface SpaceCharFilter
    {
        public boolean isSpaceChar(int ch);
    }
    public boolean isEndOfLine(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }
}
class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void println(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

} 