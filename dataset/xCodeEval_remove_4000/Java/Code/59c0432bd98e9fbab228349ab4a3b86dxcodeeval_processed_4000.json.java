import java.io.*;
import java.math.*;
import java.util.*;

public class icpc
{
    public static void main(String[] args) throws IOException
    {


        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String s = in.readLine();
        int q = Integer.parseInt(in.readLine());
        int[][] table = new int[26][n + 1];
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<=n;j++)
            {
                table[i][j] = solve(j, (char)(97 + i), s);
            }
        }
        for(int i=0;i<q;i++)
        {
            String s1[] = in.readLine().split(" ");
            int m = Integer.parseInt(s1[0]);
            char ch = s1[1].charAt(0);
            System.out.println(table[ch - 'a'][m]);
        }
    }
    public static int solve(int m, char ch, String s)
    {
        int l = 0;
        int r = 0;
        int n = s.length();
        int count = 0;
        int ans = Integer.MIN_VALUE;
        while (r < n && l <= r)
        {
            if(s.charAt(r) != ch)
                count++;
            if(count <= m)
            {
                ans = Math.max(ans, r - l + 1);
            }
            if(count <= m)
            {
                ++r;
            }
            else
            {
                if(s.charAt(l) != ch)
                    count--;
                ++l;
                if(s.charAt(r) != ch)
                    count--;
            }
        }
        return ans;
    }
}
class NumberTheory
{
    public boolean isPrime(long n)
    {
        if(n < 2)
            return false;
        for(long x = 2;x * x <= n;x++)
        {
            if(n % x == 0)
                return false;
        }
        return true;
    }
    public ArrayList<Integer> id16(int n)
    {
        ArrayList<Integer> f = new ArrayList<>();
        for(int x=2;x * x <= n;x++)
        {
            while(n % x == 0)
            {
                f.add(x);
                n /= x;
            }
        }
        if(n > 1)
            f.add(n);
        return f;
    }
    public int[] id10(int n)
    {
        int[] sieve = new int[n + 1];
        for(int x=2;x<=n;x++)
        {
            if(sieve[x] != 0)
                continue;
            sieve[x] = x;
            for(int u=2*x;u<=n;u+=x)
                if(sieve[u] == 0)
                    sieve[u] = x;
        }
        return sieve;
    }
    public long gcd(long a, long b)
    {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    public long phi(long n)
    {
        double result = n;

        for(long p=2;p*p<=n;p++)
        {
            if(n % p == 0)
            {
                while (n % p == 0)
                    n /= p;
                result *= (1.0 - (1.0 / (double)p));
            }
        }
        if(n > 1)
            result *= (1.0 - (1.0 / (double)n));
        return (long)result;
    }
    public Name id11(long a, long b)
    {
        if(b == 0)
            return new Name(a, 1, 0);
        Name n1 = id11(b, a % b);
        Name n2 = new Name(n1.d, n1.y, n1.x - (long)Math.floor((double)a / b) * n1.y);
        return n2;
    }
    public long id12(long a, long b, long n)
    {
        long d = 1L;
        String bString = Long.toBinaryString(b);
        for(int i=0;i<bString.length();i++)
        {
            d = (d * d) % n;
            if(bString.charAt(i) == '1')
                d = (d * a) % n;
        }
        return d;
    }
}
class Name
{
    long d;
    long x;
    long y;

    public Name(long d, long x, long y)
    {
        this.d = d;
        this.x = x;
        this.y = y;
    }
}
class SuffixArray
{
    int id4 = 256, N;
    int[] T, lcp, sa, sa2, rank, tmp, c;

    public SuffixArray(String str)
    {
        this(id8(str));
    }

    private static int[] id8(String s)
    {
        int[] text = new int[s.length()];
        for (int i = 0; i < s.length(); i++) text[i] = s.charAt(i);
        return text;
    }

    public SuffixArray(int[] text)
    {
        T = text;
        N = text.length;
        sa = new int[N];
        sa2 = new int[N];
        rank = new int[N];
        c = new int[Math.max(id4, N)];
        construct();
        kasai();
    }

    private void construct()
    {
        int i, p, r;
        for (i = 0; i < N; ++i) c[rank[i] = T[i]]++;
        for (i = 1; i < id4; ++i) c[i] += c[i - 1];
        for (i = N - 1; i >= 0; --i) sa[--c[T[i]]] = i;
        for (p = 1; p < N; p <<= 1)
        {
            for (r = 0, i = N - p; i < N; ++i) sa2[r++] = i;
            for (i = 0; i < N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
            Arrays.fill(c, 0, id4, 0);
            for (i = 0; i < N; ++i) c[rank[i]]++;
            for (i = 1; i < id4; ++i) c[i] += c[i - 1];
            for (i = N - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
            for (sa2[sa[0]] = r = 0, i = 1; i < N; ++i)
            {
                if (!(rank[sa[i - 1]] == rank[sa[i]]
                        && sa[i - 1] + p < N
                        && sa[i] + p < N
                        && rank[sa[i - 1] + p] == rank[sa[i] + p])) r++;
                sa2[sa[i]] = r;
            }
            tmp = rank;
            rank = sa2;
            sa2 = tmp;
            if (r == N - 1) break;
            id4 = r + 1;
        }
    }

    private void kasai()
    {
        lcp = new int[N];
        int[] inv = new int[N];
        for (int i = 0; i < N; i++) inv[sa[i]] = i;
        for (int i = 0, len = 0; i < N; i++)
        {
            if (inv[i] > 0)
            {
                int k = sa[inv[i] - 1];
                while ((i + len < N) && (k + len < N) && T[i + len] == T[k + len]) len++;
                lcp[inv[i] - 1] = len;
                if (len > 0) len--;
            }
        }
    }
}
class ZAlgorithm
{
    public int[] calculateZ(char input[])
    {
        int Z[] = new int[input.length];
        int left = 0;
        int right = 0;
        for(int k = 1; k < input.length; k++) {
            if(k > right) {
                left = right = k;
                while(right < input.length && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                

                int k1 = k - left;
                

                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { 

                    left = k;
                    while(right < input.length && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
    public ArrayList<Integer> matchPattern(char text[], char pattern[])
    {
        char newString[] = new char[text.length + pattern.length + 1];
        int i = 0;
        for(char ch : pattern) {
            newString[i] = ch;
            i++;
        }
        newString[i] = '$';
        i++;
        for(char ch : text) {
            newString[i] = ch;
            i++;
        }
        ArrayList<Integer> result = new ArrayList<>();
        int Z[] = calculateZ(newString);

        for(i = 0; i < Z.length ; i++) {
            if(Z[i] == pattern.length) {
                result.add(i - pattern.length - 1);
            }
        }
        return result;
    }
}
class id0
{
    public int[] id3(char[] pattern)
    {
        int[] lps = new int[pattern.length];

        int index = 0;
        for(int i=1;i<pattern.length;)
        {
            if(pattern[i] == pattern[index])
            {
                lps[i] = index + 1;
                index++;
                i++;
            }
            else
            {
                if(index != 0)
                {
                    index = lps[index - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    public ArrayList<Integer> id1(char[] text, char[] pattern)
    {
        int[] lps = id3(pattern);

        int j = 0;
        int i = 0;
        int n = text.length;
        int m = pattern.length;
        ArrayList<Integer> indices = new ArrayList<>();
        while(i < n)
        {
            if(pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if(j == m)
            {
                indices.add(i - j);
                j = lps[j - 1];
            }
            else if(i < n && pattern[j] != text[i])
            {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return indices;
    }
}
class Hashing
{
    public long[] id6(long p, int n, long m)
    {
        long[] powers = new long[n];
        powers[0] = 1;
        for(int i=1;i<n;i++)
        {
            powers[i] = (powers[i - 1] * p) % m;
        }
        return powers;
    }
    public long computeHash(String s)
    {
        long p = 31;
        long m = 1_000_000_009;
        long hashValue = 0L;
        long[] powers = id6(p, s.length(), m);
        for(int i=0;i<s.length();i++)
        {
            char ch = s.charAt(i);
            hashValue = (hashValue + (ch - 'a' + 1) * powers[i]) % m;
        }
        return hashValue;
    }
}
class BasicFunctions
{
    public long min(long[] A)
    {
        long min = Long.MAX_VALUE;
        for(int i=0;i<A.length;i++)
        {
            min = Math.min(min, A[i]);
        }
        return min;
    }
    public long max(long[] A)
    {
        long max = Long.MAX_VALUE;
        for(int i=0;i<A.length;i++)
        {
            max = Math.max(max, A[i]);
        }
        return max;
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
class id15
{
    

    

    

    void merge(int arr[], int l, int m, int r) {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        int L[] = new int[n1];
        int R[] = new int[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    void sort(int arr[], int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }

}
class id5
{
    

    

    

    void merge(long arr[], int l, int m, int r) {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        long L[] = new long[n1];
        long R[] = new long[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    void sort(long arr[], int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

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
class id17
{
    public void update(long[] id14,long delta,int index)
    {
        index += 1;
        while(index < id14.length)
        {
            id14[index] += delta;
            index = index + (index & (-index));
        }
    }
    public long prefixSum(long[] id14,int index)
    {
        long sum = 0L;
        index += 1;
        while(index > 0)
        {
            sum += id14[index];
            index -= (index & (-index));
        }
        return sum;
    }
}
class SegmentTree
{
    public int id13(int num)
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
    public int[] id9(int[] input)
    {
        int np2 = id13(input.length);
        int[] segmentTree = new int[np2 * 2 - 1];

        for(int i=0;i<segmentTree.length;i++)
            segmentTree[i] = Integer.MIN_VALUE;

        id7(segmentTree,input,0,input.length-1,0);
        return segmentTree;

    }
    private void id7(int[] segmentTree,int[] input,int low,int high,int pos)
    {
        if(low == high)
        {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/ 2;
        id7(segmentTree,input,low,mid,2*pos + 1);
        id7(segmentTree,input,mid+1,high,2*pos + 2);
        segmentTree[pos] = Math.max(segmentTree[2*pos + 1],segmentTree[2*pos + 2]);
    }
    public int id2(int []segmentTree,int qlow,int qhigh,int len)
    {
        return id2(segmentTree,0,len-1,qlow,qhigh,0);
    }
    private int id2(int segmentTree[],int low,int high,int qlow,int qhigh,int pos)
    {
        if(qlow <= low && qhigh >= high){
            return segmentTree[pos];
        }
        if(qlow > high || qhigh < low){
            return Integer.MIN_VALUE;
        }
        int mid = (low+high)/2;
        return Math.max(id2(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1),
                id2(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
    }
}