import java.io.*;
import java.util.*;
public class icpc
{
    public static void main(String[] args) throws IOException
    {


        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s1[] = in.readLine().split(" ");
        int n = Integer.parseInt(s1[0]);
        int k = Integer.parseInt(s1[1]);
        String s = in.readLine();

        if (k == 0)
        {
            int max = Integer.MIN_VALUE;
            int len = 0;
            for (int i=0;i<s.length();i++)
            {
                if (s.charAt(i) == 'a')
                {
                    len++;
                }
                else
                {
                    max = Math.max(max, len);
                    len = 0;
                }
            }
            max = Math.max(max, len);
            len = 0;
            for (int i=0;i<s.length();i++)
            {
                if (s.charAt(i) == 'b')
                {
                    len++;
                }
                else
                {
                    max = Math.max(max, len);
                    len = 0;
                }
            }
            max = Math.max(max, len);
            System.out.println(max);
            System.exit(0);
        }
        ArrayList<Integer>[] adj = (ArrayList<Integer>[])new ArrayList[2];
        for (int i=0;i<2;i++)   adj[i] = new ArrayList<>();
        for (int i=0;i<s.length();i++)
        {
            if (s.charAt(i) == 'a')
                adj[0].add(i);
            else
                adj[1].add(i);
        }


        int max = Integer.MIN_VALUE;
        if (adj[0].size() == 0 ||adj[1].size() == 0)
        {
            max = n;
            System.out.println(max);
            System.exit(0);
        }
        for (int j=0;j<2;j++)
        {
            for (int i=0;i<adj[j].size();i++)
            {
                int len = 0;
                if (i + k - 1 < adj[j].size())
                {
                    len = adj[j].get(i + k - 1) - adj[j].get(i) + 1;
                    if (i == 0)
                        len += adj[j].get(i);
                    else
                        len += adj[j].get(i) - adj[j].get(i - 1) - 1;
                    if (i + k == adj[j].size())
                        len += n - adj[j].get(i + k - 1) - 1;
                    else
                        len += adj[j].get(i + k) - adj[j].get(i + k - 1) - 1;
                    max = Math.max(max, len);
                }
                else
                {
                    int temp = adj[j].size();
                    len = adj[j].get(temp - 1) - adj[j].get(i) + 1;
                    if (i == 0)
                        len += adj[j].get(i);
                    else
                        len += adj[j].get(i) - adj[j].get(i - 1) - 1;
                    len += n - adj[j].get(temp - 1) - 1;
                    max = Math.max(max, len);
                }
            }
        }
        System.out.println(max);
    }
}
class DSU
{
    int[] parent;
    int[] size;
    

    DSU(int n)
    {
        this.parent = new int[n];
        this.size = new int[n];
        Arrays.fill(parent, -1);
    }

    public void makeSet(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    public int findSet(int v)
    {
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }

    public void unionSets(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
}
class id18
{
    private void fft(double[] a, double[] b, boolean invert)
    {
        int count = a.length;
        for (int i = 1, j = 0; i < count; i++)
        {
            int bit = count >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
        for (int len = 2; len <= count; len <<= 1)
        {
            int halfLen = len >> 1;
            double angle = 2 * Math.PI / len;
            if (invert)
                angle = -angle;
            double id17 = Math.cos(angle);
            double id2 = Math.sin(angle);
            for (int i = 0; i < count; i += len)
            {
                double wA = 1;
                double wB = 0;
                for (int j = 0; j < halfLen; j++)
                {
                    double uA = a[i + j];
                    double uB = b[i + j];
                    double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
                    double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
                    a[i + j] = uA + vA;
                    b[i + j] = uB + vB;
                    a[i + j + halfLen] = uA - vA;
                    b[i + j + halfLen] = uB - vB;
                    double nextWA = wA * id17 - wB * id2;
                    wB = wA * id2 + wB * id17;
                    wA = nextWA;
                }
            }
        }
        if (invert)
        {
            for (int i = 0; i < count; i++)
            {
                a[i] /= count;
                b[i] /= count;
            }
        }
    }

    public long[] multiply(long[] a, long[] b)
    {
        int resultSize = Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2;
        resultSize = Math.max(resultSize, 1);
        double[] aReal = new double[resultSize];
        double[] id10 = new double[resultSize];
        double[] bReal = new double[resultSize];
        double[] id29 = new double[resultSize];
        for (int i = 0; i < a.length; i++)
            aReal[i] = a[i];
        for (int i = 0; i < b.length; i++)
            bReal[i] = b[i];
        fft(aReal, id10, false);
        fft(bReal, id29, false);
        for (int i = 0; i < resultSize; i++)
        {
            double real = aReal[i] * bReal[i] - id10[i] * id29[i];
            id10[i] = id10[i] * bReal[i] + id29[i] * aReal[i];
            aReal[i] = real;
        }
        fft(aReal, id10, true);
        long[] result = new long[resultSize];
        for (int i = 0; i < resultSize; i++)
            result[i] = Math.round(aReal[i]);
        return result;
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
    public ArrayList<Long> id26(long n)
    {
        ArrayList<Long> f = new ArrayList<>();
        for(long x=2;x * x <= n;x++)
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
    public int[] id19(int n)
    {
        

        int[] sieve = new int[n + 1];
        for(int x=2;x * x <= n;x++)
        {
            if(sieve[x] != 0)
                continue;
            for(int u=x*x;u<=n;u+=x)
            {
                if(sieve[u] == 0)
                {
                    sieve[u] = x;
                }
            }
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
    public Name id21(long a, long b)
    {
        if(b == 0)
            return new Name(a, 1, 0);
        Name n1 = id21(b, a % b);
        Name n2 = new Name(n1.d, n1.y, n1.x - (long)Math.floor((double)a / b) * n1.y);
        return n2;
    }
    public long id22(long a, long b, long n)
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
    int id6 = 256, N;
    int[] T, lcp, sa, sa2, rank, tmp, c;

    public SuffixArray(String str)
    {
        this(id12(str));
    }

    private static int[] id12(String s)
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
        c = new int[Math.max(id6, N)];
        construct();
        kasai();
    }

    private void construct()
    {
        int i, p, r;
        for (i = 0; i < N; ++i) c[rank[i] = T[i]]++;
        for (i = 1; i < id6; ++i) c[i] += c[i - 1];
        for (i = N - 1; i >= 0; --i) sa[--c[T[i]]] = i;
        for (p = 1; p < N; p <<= 1)
        {
            for (r = 0, i = N - p; i < N; ++i) sa2[r++] = i;
            for (i = 0; i < N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
            Arrays.fill(c, 0, id6, 0);
            for (i = 0; i < N; ++i) c[rank[i]]++;
            for (i = 1; i < id6; ++i) c[i] += c[i - 1];
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
            id6 = r + 1;
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
class id1
{
    public int[] id5(char[] pattern)
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

    public ArrayList<Integer> id3(char[] text, char[] pattern)
    {
        int[] lps = id5(pattern);

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
    public long[] id8(long p, int n, long m)
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
        long[] powers = id8(p, s.length(), m);
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
class id25
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
class id7
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

    int x;
    int y;

    public Node(int x, int y)
    {
        this.x = x;
        this.y = y;
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
        if(this.x == obj.x && this.y == obj.y)
            return true;
        return false;
    }

    @Override
    public int hashCode()
    {
        return (int)this.x;
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
class id28
{
    public void update(long[] id24,long delta,int index)
    {
        index += 1;
        while(index < id24.length)
        {
            id24[index] += delta;
            index = index + (index & (-index));
        }
    }
    public long prefixSum(long[] id24,int index)
    {
        long sum = 0L;
        index += 1;
        while(index > 0)
        {
            sum += id24[index];
            index -= (index & (-index));
        }
        return sum;
    }
}
class SegmentTree
{
    public int id23(int num)
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
    public int[] id16(int[] input)
    {
        int np2 = id23(input.length);
        int[] segmentTree = new int[np2 * 2 - 1];

        for(int i=0;i<segmentTree.length;i++)
            segmentTree[i] = Integer.MIN_VALUE;

        id11(segmentTree,input,0,input.length-1,0);
        return segmentTree;

    }
    private void id11(int[] segmentTree,int[] input,int low,int high,int pos)
    {
        if(low == high)
        {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/ 2;
        id11(segmentTree,input,low,mid,2*pos + 1);
        id11(segmentTree,input,mid+1,high,2*pos + 2);
        segmentTree[pos] = Math.max(segmentTree[2*pos + 1],segmentTree[2*pos + 2]);
    }
    public int id4(int []segmentTree,int qlow,int qhigh,int len)
    {
        return id4(segmentTree,0,len-1,qlow,qhigh,0);
    }
    private int id4(int segmentTree[],int low,int high,int qlow,int qhigh,int pos)
    {
        if(qlow <= low && qhigh >= high){
            return segmentTree[pos];
        }
        if(qlow > high || qhigh < low){
            return Integer.MIN_VALUE;
        }
        int mid = (low+high)/2;
        return Math.max(id4(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1),
                id4(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
    }
}
class Trie
{

    private class TrieNode
    {
        Map<Character, TrieNode> children;
        boolean id13;
        public TrieNode()
        {
            children = new HashMap<>();
            id13 = false;
        }
    }

    private final TrieNode root;
    public Trie()
    {
        root = new TrieNode();
    }

    public void insert(String word)
    {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word.charAt(i);
            TrieNode node = current.children.get(ch);
            if (node == null)
            {
                node = new TrieNode();
                current.children.put(ch, node);
            }
            current = node;
        }
        current.id13 = true;
    }

    public boolean search(String word)
    {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word.charAt(i);
            TrieNode node = current.children.get(ch);
            if (node == null)
            {
                return false;
            }
            current = node;
        }
        return current.id13;
    }

    public void delete(String word)
    {
        delete(root, word, 0);
    }

    private boolean delete(TrieNode current, String word, int index)
    {
        if (index == word.length())
        {
            if (!current.id13)
            {
                return false;
            }
            current.id13 = false;
            return current.children.size() == 0;
        }
        char ch = word.charAt(index);
        TrieNode node = current.children.get(ch);
        if (node == null)
        {
            return false;
        }
        boolean id14 = delete(node, word, index + 1);

        if (id14)
        {
            current.children.remove(ch);
            return current.children.size() == 0;
        }
        return false;
    }
}
class id15
{
    public int id23(int num)
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

    public int[] id16(int input[])
    {
        int id20 = id23(input.length);
        int segmentTree[] = new int[id20*2 -1];

        for(int i=0; i < segmentTree.length; i++){
            segmentTree[i] = Integer.MAX_VALUE;
        }
        id0(segmentTree, input, 0, input.length - 1, 0);
        return segmentTree;
    }

    private void id0(int segmentTree[], int input[], int low, int high,int pos)
    {
        if(low == high)
        {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        id0(segmentTree, input, low, mid, 2 * pos + 1);
        id0(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = Math.min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
    }

    public void id9(int input[], int segmentTree[], int lazy[], int startRange, int endRange, int delta)
    {
        id9(segmentTree, lazy, startRange, endRange, delta, 0, input.length - 1, 0);
    }

    private void id9(int segmentTree[], int lazy[], int startRange, int endRange, int delta, int low, int high, int pos)
    {
        if(low > high)
        {
            return;
        }
        if (lazy[pos] != 0)
        {
            segmentTree[pos] += lazy[pos];
            if (low != high)
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if(startRange > high || endRange < low)
        {
            return;
        }

        if(startRange <= low && endRange >= high)
        {
            segmentTree[pos] += delta;
            if(low != high) {
                lazy[2*pos + 1] += delta;
                lazy[2*pos + 2] += delta;
            }
            return;
        }

        int mid = (low + high)/2;
        id9(segmentTree, lazy, startRange, endRange, delta, low, mid, 2*pos+1);
        id9(segmentTree, lazy, startRange, endRange, delta, mid+1, high, 2*pos+2);
        segmentTree[pos] = Math.min(segmentTree[2*pos + 1], segmentTree[2*pos + 2]);
    }

    public int id27(int segmentTree[], int lazy[], int qlow, int qhigh, int len)
    {
        return id27(segmentTree, lazy, qlow, qhigh, 0, len - 1, 0);
    }

    private int id27(int segmentTree[], int lazy[], int qlow, int qhigh, int low, int high, int pos)
    {
        if(low > high)
        {
            return Integer.MAX_VALUE;
        }
        if (lazy[pos] != 0)
        {
            segmentTree[pos] += lazy[pos];
            if (low != high)
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if(qlow > high || qhigh < low)
        {
            return Integer.MAX_VALUE;
        }

        if(qlow <= low && qhigh >= high)
        {
            return segmentTree[pos];
        }

        int mid = (low+high)/2;
        return Math.min(id27(segmentTree, lazy, qlow, qhigh, low, mid, 2 * pos + 1), id27(segmentTree, lazy,  qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
}
