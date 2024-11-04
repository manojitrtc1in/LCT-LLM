import javax.print.DocFlavor;
import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.nio.Buffer;
import java.sql.BatchUpdateException;
import java.util.*;
import java.util.stream.Stream;
import java.util.Vector;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import static java.lang.Math.*;
import java.util.*;
import java.nio.file.StandardOpenOption;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Iterator;
import java.util.PriorityQueue;

public class icpc
{
    public static void main(String[] args)throws IOException
    {
        Reader in = new Reader();
        


        int n = in.nextInt();
        int[] A = new int[n];
        for(int i=0;i<n;i++)
            A[i] = in.nextInt();

        int len1[] = new int[n];
        int len2[] = new int[n];
        Arrays.fill(len1, 1);
        Arrays.fill(len2, 1);
        for(int i=n-2;i>=0;i--)
        {
            if(A[i] < A[i+1])
                len1[i] = len1[i+1] + 1;
            else
                continue;
        }
        for(int i=1;i<n;i++)
        {
            if(A[i] < A[i-1])
                len2[i] = len2[i-1] + 1;
            else
                continue;
        }
        StringBuilder stringBuilder = new StringBuilder();
        int i = 0;
        int j = n - 1;
        int last = Integer.MIN_VALUE;
        int len = 0;
        while(true)
        {
            if(i > j)
                break;
            if(i == j)
            {
                if(A[i] > last)
                {
                    stringBuilder.append("L");
                    last = A[i];
                    len++;
                    break;
                }
                else
                    break;
            }
            if(A[i] < A[j] && A[i] > last)
            {
                stringBuilder.append("L");
                last = A[i];
                i++;
                len ++;
            }
            else if(A[j] < A[i] && A[j] > last)
            {
                stringBuilder.append("R");
                last = A[j];
                j--;
                len++;
            }
            else if(A[i] < A[j] && A[i] <= last)
            {
                if(A[j] > last)
                {
                    stringBuilder.append("R");
                    last = A[j];
                    len++;
                    j--;
                }
                else
                {
                    break;
                }
            }
            else if(A[j] < A[i] && A[j] <= last)
            {
                if(A[i] > last)
                {
                    stringBuilder.append("L");
                    last = A[i];
                    len++;
                    i++;
                }
                else
                    break;
            }
            else if(A[i] == A[j])
            {
                if(A[i] <= last)
                {
                    break;
                }
                else
                {
                    if(A[i+1] == A[i] && A[j-1] == A[j])
                    {
                        stringBuilder.append("L");
                        len++;
                        break;

                    }
                    else if(A[i+1] == A[i])
                    {
                        if(A[j-1] > A[j])
                        {
                            stringBuilder.append("R");
                            len++;
                            int remLen = len2[j-1];
                            len+= remLen;
                            for(int k=0;k<remLen;k++)
                                stringBuilder.append("R");
                            break;
                        }
                        else
                        {
                            stringBuilder.append("R");
                            len++;
                            last = A[j];
                            break;
                        }
                    }
                    else if(A[j-1] == A[j])
                    {
                        if(A[i+1] > A[i])
                        {
                            stringBuilder.append("L");
                            int remLen = len1[i+1];
                            len+= remLen + 1;
                            for(int k=0;k<remLen;k++)
                                stringBuilder.append("L");
                            break;
                        }
                        else
                        {
                            stringBuilder.append("L");
                            len++;
                            last = A[i];
                            break;
                        }
                    }
                    else
                    {
                        int a1 = len1[i+1];
                        int a2 = len2[j-1];
                        if(a1 >= a2 && A[i+1] > A[i])
                        {
                            stringBuilder.append("L");
                            for(int k=0;k<a1;k++)
                                stringBuilder.append("L");
                            len+= a1 + 1;
                        }
                        else if(a2 >= a1 && A[j-1] > A[j])
                        {
                            stringBuilder.append("R");
                            for(int k=0;k<a2;k++)
                            {
                                stringBuilder.append("R");
                            }
                            len += a2 + 1;
                        }
                        else if(a1 >= a2 && A[i+1] < A[i])
                        {
                            if(A[j-1] > A[j])
                            {
                                stringBuilder.append("R");
                                for(int k=0;k<a2;k++)
                                    stringBuilder.append("R");
                                len += a2 + 1;
                                break;
                            }
                            else
                            {
                                stringBuilder.append("R");
                                len ++;
                                break;
                            }
                        }
                        else if(a2 >= a1 && A[j-1] < A[j])
                        {
                            if(A[i+1] > A[i])
                            {
                                stringBuilder.append("L");
                                for(int k=0;k<a1;k++)
                                    stringBuilder.append("L");
                                len += a1 + 1;
                                break;
                            }
                            else
                                break;
                        }
                        break;
                    }
                }
            }
            else
                break;

        }

        System.out.println(len);
        System.out.println(stringBuilder);
    }
}
class Matrix
{
    long a;
    long b;
    long c;
    long d;

    public Matrix(long a, long b, long c, long d)
    {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
}
class Game implements Comparable<Game>
{
    long x;
    int y;
    Game(long a,int b)
    {
        this.x = a;
        this.y = b;
    }
    public int compareTo(Game ob)
    {
        if(this.x < ob.x)
            return 1;
        else if(this.x > ob.x)
            return -1;
        return 0;
    }
}
class MergeSort
{
    

    

    

    void merge(long arr[], int l, int m, int r)
    {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        long L[] = new long [n1];
        long R[] = new long [n2];

        
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    void sort(long arr[], int l, int r)
    {
        if (l < r)
        {
            

            int m = (l+r)/2;

            

            sort(arr, l, m);
            sort(arr , m+1, r);

            

            merge(arr, l, m, r);
        }
    }
}
class Node
{
    String a;
    String b;
    Node(String s1,String s2)
    {
        this.a = s1;
        this.b = s2;
    }
    @Override
    public boolean equals(Object ob)
    {
        if(ob == null)
            return false;
        if(!(ob instanceof Node))
            return false;
        if(ob == this)
            return true;
        Node obj = (Node)ob;
        if(this.a.equals(obj.a) && this.b.equals(obj.b))
            return true;
        return false;
    }

    @Override
    public int hashCode()
    {
        return (int)this.a.length();
    }
}
class Reader
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[64]; 

        int cnt = 0, c;
        while ((c = read()) != -1)
        {
            if (c == '\n')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do
        {
            ret = ret * 10 + c - '0';
        }  while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');

        if (c == '.')
        {
            while ((c = read()) >= '0' && c <= '9')
            {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
    }
}
class Hey
{
    public static int id5(int a, int b, int n)
    {
        if(a == 0)
            return 0;
        else if(a % 2 == 0)
            return (2 * ((id5(a / 2, b, n)) % n))% n;
        else
            return ((2 * ((id5((a - 1) / 2, b, n)) % n))% n + b) % n;
    }
    public static long binPow(long a, long n)
    {
        long res = 1L;
        while (n > 0)
        {
            if((n & 1) > 0)
            {
                res *= a;
            }
            a *= a;
            n >>= 1;
        }
        return res;
    }
    public static long phi(long n)
    {
        long result = n;
        for(int i=2;i*i <= n;i++)
        {
            if(n % i == 0)
            {
                while(n % i == 0)
                    n = n / i;
                result -= result / (long)i;
            }
        }
        if(n > 1)
            result -= result / n;
        return result;
    }
}
class SegmentTree
{
    public int id6(int num)
    {
        if(num == 0)
            return 1;
        if(num > 0 && (num & (num - 1)) == 0)
            return num;
        while((num &(num - 1)) > 0)
        {
            num = num & (num - 1);
        }
        return num << 1;
    }

}
class id9
{
    public void update(long[] id7,long delta,int index)
    {
        index += 1;
        while(index < id7.length)
        {
            id7[index] += delta;
            index = index + (index & (-index));
        }
    }
    public long prefixSum(long[] id7,int index)
    {
        long sum = 0L;
        index += 1;
        while(index > 0)
        {
            sum += id7[index];
            index -= (index & (-index));
        }
        return sum;
    }
}
class id0
{
    public int id6(int num)
    {
        if(num == 0)
            return 1;
        if(num > 0 && (num & (num - 1)) == 0)
            return num;
        while((num &(num - 1)) > 0)
        {
            num = num & (num - 1);
        }
        return num << 1;
    }
    public int[] id4(int[] input)
    {
        int np2 = id6(input.length);
        int[] segmentTree = new int[np2 * 2 - 1];

        for(int i=0;i<segmentTree.length;i++)
            segmentTree[i] = Integer.MAX_VALUE;

        id3(segmentTree,input,0,input.length-1,0);
        return segmentTree;

    }
    private void id3(int[] segmentTree,int[] input,int low,int high,int pos)
    {
        if(low == high)
        {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/ 2;
        id3(segmentTree,input,low,mid,2*pos + 1);
        id3(segmentTree,input,mid+1,high,2*pos + 2);
        segmentTree[pos] = Math.min(segmentTree[2*pos + 1],segmentTree[2*pos + 2]);
    }
    public int id1(int[] segmentTree,int qlow,int qhigh,int len)
    {
        return id1(segmentTree,0,len - 1,qlow,qhigh,0);
    }
    private int id1(int[] segmentTree,int low,int high,int qlow,int qhigh,int pos)
    {
        if(qlow <= low && qhigh >= high)
        {
            return segmentTree[pos];
        }
        else if(qlow > high || qhigh < low)
        {
            return Integer.MAX_VALUE;
        }
        int mid = (low + high)/2;
        return Math.min(id1(segmentTree,low,mid,qlow,qhigh,2*pos+1),id1(segmentTree,mid+1,high,qlow,qhigh,2*pos+2));
    }
    public void id2(int[] input,int[] segmentTree,int[] lazy,int startRange,int endRange,int delta)
    {
        id2(input,segmentTree,lazy,startRange,endRange,delta,0,input.length-1,0);
    }
    private void id2(int[] input,int[] segmentTree,int[] lazy,int startRange,int endRange,int delta,int low,int high,int pos)
    {
        if(low > high)
        {
            return;
        }
        if(lazy[pos] != 0)
        {
            segmentTree[pos] += lazy[pos];
            if(low != high)
            {
                lazy[2*pos+1] += lazy[pos];
                lazy[2*pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if(startRange > high || endRange < low)
            return;
        if(startRange <= low && endRange >= high)
        {
            segmentTree[pos] += delta;
            if(low != high)
            {
                lazy[2*pos + 1] += delta;
                lazy[2*pos + 2] += delta;
            }
            return;
        }
        int mid = (low + high)/2;
        id2(input,segmentTree,lazy,startRange,endRange,delta,low,mid,2*pos + 1);
        id2(input,segmentTree,lazy,startRange,endRange,delta,mid + 1,high,2 * pos + 2);
        segmentTree[pos] += Math.min(segmentTree[2*pos + 1],segmentTree[2*pos + 2]);
    }
    public int id8(int[] segmentTree,int[] lazy,int qlow,int qhigh,int len)
    {
        return id8(segmentTree,lazy,qlow,qhigh,0,len - 1,0);
    }
    private int id8(int[] segmentTree,int[] lazy,int qlow,int qhigh,int low,int high,int pos)
    {
        if(low > high)
            return Integer.MAX_VALUE;
        if(lazy[pos] != 0)
        {
            segmentTree[pos] += lazy[pos];
            if(low != high)
            {
                lazy[2*pos + 1] += lazy[pos];
                lazy[2*pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if(qlow > high || qhigh < low)
            return Integer.MAX_VALUE;
        if(qlow <= low && qhigh >= low)
            return segmentTree[pos];
        int mid = (low + high)/2;
        return Math.min(id8(segmentTree,lazy,qlow,qhigh,low,mid,2*pos + 1),id8(segmentTree,lazy,qlow,qhigh,mid + 1,high,2*pos + 2));
    }
}