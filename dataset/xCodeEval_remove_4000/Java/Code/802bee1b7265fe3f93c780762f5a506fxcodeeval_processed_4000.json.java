import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test {
    static int[] dx = {1,-1,0,0,1,1,-1,-1};
    static int[] dy = {0,0,1,-1,1,-1,1,-1};
    static long e97=1000000007;
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int times=in.nextInt();
        

        while (times-->0) {
            int n=in.nextInt(),res=0;
            for (int i = 0; i < n; i++) {
                res|=in.nextInt();
            }
            System.out.println(res);
        }
    }
    static class node{
        int order,value;

        public node(int value, int index) {
            this.value=value;
            order=index;
        }
    }
}
class Reader {
     BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tokenizer = new StringTokenizer("");
    
     String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
     int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
     double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}
class segTree{
    
    class segment{
        segment left,right;
        int l,r,lazy=0,length;
        long value=0;
        public segment(int a,int b){l=a;r=b;length=r-l+1;}
    }
    segment root;
    int source[];
    public segTree(int size){root=new segment(0,size);}
    public segTree(int[] source){
        root=new segment(0,source.length-1);
        this.source=source;
        build(root);
    }
    private void build(segment a){
        if(a.l==a.r) a.value=source[a.l];
        else {
            int mid=(a.l+a.r)/2;
            a.left=new segment(a.l,mid);
            a.right=new segment(mid+1,a.r);
            build(a.left);
            build(a.right);
            pushUp(a);
        }
    }
    private void pushUp(segment a){
        a.value=Math.max(a.left.value,a.right.value);
        

    }
    private void pushDown(segment a){
        if(a.lazy!=0){
            a.left.value=a.lazy*a.left.length;
            a.right.value=a.lazy*a.right.length;
            
            a.left.lazy=a.right.lazy=a.lazy;
            a.lazy=0;
        }
    }
    public void rangeModify(segment a,int start,int end,int value){
        int l=a.l,r=a.r,mid=(l+r)/2;
        if(l>=start&&r<=end) {
            

            a.value=value;
            

            

            return;
        }else if(l>end||r<start||r==l) return;
        if(a.left==null) a.left=new segment(l,mid);
        if(a.right==null) a.right=new segment(mid+1,r);
        

        if(mid>=start) rangeModify(a.left,start,end,value);
        if(mid<=end) rangeModify(a.right,start,end,value);
        pushUp(a);
    }
    public long rangeQuery(segment a, int start, int end){
        int l=a.l,r=a.r;
        if(l>=start&&r<=end) {
            return a.value;
        }else if(r<start||l>end) return 0;
        

        return Math.max(rangeQuery(a.left,start,end),rangeQuery(a.right,start,end));
    }
}
class Complex {
    

    private final double re; 

    private final double im; 


    

    public Complex(double real, double imag) {
        re = real;
        im = imag;
    }
    

    public static Complex omega(int n,int k){
        return new Complex(Math.cos(2*Math.PI*k/n),Math.sin(2*Math.PI*k/n));
    }
    

    @Override
    public String toString() {
        if (im == 0)
            return re + "";
        if (re == 0)
            return im + "i";
        if (im < 0)
            return re + " - " + (-im) + "i";
        return re + " + " + im + "i";
    }

    

    public double abs() {
        return Math.hypot(re, im);
    }

    

    public double phase() {
        return Math.atan2(im, re);
    }

    

    public Complex plus(Complex b) {
        Complex a = this; 

        double real = a.re + b.re;
        double imag = a.im + b.im;
        return new Complex(real, imag);
    }

    

    public Complex minus(Complex b) {
        Complex a = this;
        double real = a.re - b.re;
        double imag = a.im - b.im;
        return new Complex(real, imag);
    }

    

    public Complex multiple(Complex b) {
        Complex a = this;
        double real = a.re * b.re - a.im * b.im;
        double imag = a.re * b.im + a.im * b.re;
        return new Complex(real, imag);
    }

    

    

    public Complex multiple(double alpha) {
        return new Complex(alpha * re, alpha * im);
    }

    

    public Complex scale(double alpha) {
        return new Complex(alpha * re, alpha * im);
    }

    

    public Complex id6() {
        return new Complex(re, -im);
    }

    

    public Complex id14() {
        double scale = re * re + im * im;
        return new Complex(re / scale, -im / scale);
    }

    

    public double re() {
        return re;
    }

    public double im() {
        return im;
    }

    

    public Complex divides(Complex b) {
        Complex a = this;
        return a.multiple(b.id14());
    }

    

    

    public Complex exp() {
        return new Complex(Math.exp(re) * Math.cos(im), Math.exp(re) * Math.sin(im));
    }

    

    public Complex sin() {
        return new Complex(Math.sin(re) * Math.cosh(im), Math.cos(re) * Math.sinh(im));
    }

    

    public Complex cos() {
        return new Complex(Math.cos(re) * Math.cosh(im), -Math.sin(re) * Math.sinh(im));
    }

    

    public Complex tan() {
        return sin().divides(cos());
    }

    

    public static Complex plus(Complex a, Complex b) {
        double real = a.re + b.re;
        double imag = a.im + b.im;
        Complex sum = new Complex(real, imag);
        return sum;
    }

    

    @Override
    public boolean equals(Object x) {
        if (x == null)
            return false;
        if (this.getClass() != x.getClass())
            return false;
        Complex that = (Complex) x;
        return (this.re == that.re) && (this.im == that.im);
    }

    

    @Override
    public int hashCode() {
        return Objects.hash(re, im);
    }
}
class OtherTool{
    public static long[][] MatrixTranspose(long[][] matrix){
        long len=matrix.length,temp=0;
        if(len!=matrix[0].length) throw new IllegalArgumentException();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        return matrix;
    }
    public static long[][] matrixMul(long[][] matrix1,long[][] matrix2, long mod){
        int row = matrix1.length,column=matrix2[0].length,max=Math.max(row,column),cnt1=0,cnt2=0;
        long[][] temp=new long[row][column];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                long res=0;
                for (int k = 0; k < max; k++) {
                    

                    

                    res+=matrix1[i][k]* matrix2[k][j];
                    res%=mod;
                    

                }
                temp[i][j]=res%mod;
            }
        }
        return temp;
    }
    public static long[][] matrixPow(long[][] matrix,long times, long mod){
        if(times==1) return matrix;
        int l= matrix.length;
        long[][] temp=new long[l][l];
        for (int i = 0; i < l; i++) {
            temp[i][i]=1;
        }
        if(times<1) return temp;
        while (times>0){
            if(times%2==1) temp=matrixMul(temp,matrix,mod);
            matrix=matrixMul(matrix,matrix,mod);
            times/=2;
        }
        return temp;
    }
    public static long fastPower(int source, long times, int mod){
        if(times==0||source==1) return 1;
        long i=1,cnt=1;
        while (times>0){
            if(times%2==1) i=(source*i)%mod;
            source*=source;
            source%=mod;
            times/=2;
        }
        return i;
    }
    public static long id15(int source,int times,int mod){
        if(times==1) return source;
        if(source==1||times==0) return 1;
        long temp=id15(source,times/2,mod)%mod;
        temp=temp*temp%mod;
        if(times%2==1){
            return temp*source%mod;
        }else return temp;
    }
    public static void id5(int[] a, int[] b, int l, int r) {
        int mid = (l + r) / 2;
        if (l < r - 1) {
            id5(a, b, l, mid);
            id5(a, b, mid + 1, r);
        }
        if (l == r) return;
        int[] temp = new int[r - l + 1];
        int[] tempb = new int[r - l + 1];
        int i = l, j = mid + 1, t = 0;
        while (i < mid + 1 && j < r + 1) {
            if (a[i] <= a[j]) {
                temp[t] = a[i];
                tempb[t++] = b[i++];
            } else {
                temp[t] = a[j];
                tempb[t++] = b[j++];
            }
        }
        while (i < mid + 1) {
            temp[t] = a[i];
            tempb[t++] = b[i++];
        }
        while (j < r + 1) {
            temp[t] = a[j];
            tempb[t++] = b[j++];
        }
        for (int k = l; k < r + 1; k++) {
            a[k] = temp[k - l];
            b[k] = tempb[k - l];
        }
    }
    public static String nextPermutation(String s){
        if(s.length()<=1) return null;
        StringBuilder sb=new StringBuilder(s);
        int i1=-1,i2=-1;
        for (int i = s.length()-1; i >=0 ; i--) if(s.charAt(i-1)<s.charAt(i)) {i1=i-1;break;}
        if(i1==-1) return null;
        for (int i = s.length()-1; i >=0 ; i--) if(s.charAt(i)>s.charAt(i1)) {i2=i;break;}
        char c=s.charAt(i1);
        sb.setCharAt(i1,s.charAt(i2));
        sb.setCharAt(i2,c);
        sb.replace(i1,s.length(),new StringBuilder(sb.substring(i1,s.length())).reverse().toString());
        return sb.toString();
    }
    public static int[] nextPermutation(int[] s){
        if(s.length<=1) return null;
        int i1=-1,i2=-1;
        for (int i = s.length-1; i >0 ; i--) if(s[i-1]<s[i]) {i1=i-1;break;}
        if(i1==-1) return null;
        for (int i = s.length-1; i >=0 ; i--) if(s[i]>s[i1]) {i2=i;break;}
        int t=s[i1];
        s[i1]=s[i2];
        s[i2]=t;
        t=s.length-i1-1;
        int[] temp=new int[t];
        for (int i = 0; i < t; i++) {
            temp[i]=s[s.length-i-1];
        }
        System.arraycopy(temp,0,s,i1+1,t);
        return s;
    }
    
}
class OT extends OtherTool{}
class id1{
    long[] tree1,tree2;
    int size;
    public id1(int size) {
        tree1=new long[100008];
        tree2=new long[100008];
        this.size=size;
    }
    public void add(int index,long value){
        long p=index*value;
        while (index<=size) {
            tree1[index]+=value;
            tree2[index]+=p;
            index+=index&-index;
        }
    }
    public void RangeAdd(int start,int end,int value){
        add(start,value);
        

        add(end+1,-value);
    }
    public long query(int start,int end){
        return sum(end)-sum(start-1);
    }
    public long sum(int i){
        long res=0,p=i;
        while (i>0) {
            res+=tree1[i]*(p+1)-tree2[i];
            i-=i&-i;
        }
        return res;
    }
}
class id7  implements  id17{
    id18[] map;
    int[] matched;
    boolean[] used;
    public id7(int i) {
        map=new id18[i+1];
        used=new boolean[i+1];matched=new int[i+1];
        Arrays.fill(matched,-1);
        for (int i1 = 0; i1 < map.length; i1++) {
            map[i1]= new id18();
        }
    }
    @Override
    public void setRoad(int start, int next, int value){
        id18 c=new id18(next,value);
        c.id3=map[start].id3;
        map[start].id3=c;
    }
    public int Hungarian(){
        int maxWays=0;
        for (int i = 0; i < map.length; i++) {
            Arrays.fill(used,true);
            if(map[i].id3==null)continue;
            if(canMatch(i)) maxWays++;
        }
        return maxWays;
    }
    public boolean canMatch(int from){
        id18 n=map[from].id3;
        int to=n.id13;
        while (!used[to]&&n.id3!=null) {n=n.id3;to=n.id13;}
        if(used[to]){
            used[to]=false;
            if(matched[to]==-1||canMatch(matched[to])){
                matched[to]=from;
                return true;
            }
        }
        return false;
    }
}
interface id17{
    class id18 {
        int id13,value;
        id18 id3=null;
        public id18(int i, int v) {
            id13 = i;
            value = v;
        }
        public id18() {}
        public void setNext(id18 n){id3=n;}
    }
    void setRoad(int i,int j,int k);
}
class ShortestRoad implements id17{
    class QueueNode {
        int city,value;
        public QueueNode(int c, int v){city=c;value=v;}
    }
    id18[] map;
    int[] city;
    int[][] f;
    public ShortestRoad(int i) {
        city = new int[i];
        

        map=new id18[i];
        for (int i1 = 0; i1 < map.length; i1++) {
            map[i1]= new id18();
        }
    }
    public ShortestRoad(int[][] f, int i) {
        city = new int[i];
        this.f=f;
    }
    @Override
    public void setRoad(int start, int next, int value){
        id18 c=new id18(next,value);
        c.id3=map[start].id3;
        map[start].id3=c;
    }
    public int dijkstra(int start ,int end){
        int[] distance=new int[city.length],used=new int[city.length];
        PriorityQueue<QueueNode> node=new PriorityQueue<QueueNode>(city.length, Comparator.comparingInt(o -> o.value));
        Arrays.fill(distance,Integer.MAX_VALUE/2);
        node.add(new QueueNode(start,0));
        distance[start]=0;
        while (!node.isEmpty()){
            int city=node.poll().city;
            if(used[city]!=0) continue;
            used[city]=1;
            id18 n=map[city].id3;
            if(n==null) return -1;
            while (true){
                int nowcity=n.id13;
                if(distance[nowcity]>distance[city]+n.value){
                    distance[nowcity]=distance[city]+n.value;
                    node.offer(new QueueNode(nowcity,distance[nowcity]));
                }
                if(n.id3==null) break;
                n=n.id3;
            }
        }
        if(distance[end]!=Integer.MAX_VALUE/2) return distance[end];
        else return  Integer.MAX_VALUE;
    }
    public void floyd(int max){
        for(int k=1; k<=max; k++)
            for(int i=1; i<=max; i++)
                if(f[i][k]!=Integer.MAX_VALUE/2)
                for(int j=1; j<=max; j++)
                    f[i][j] = Math.min(f[i][j], f[i][k] + f[k][j]);
    }
    public int id12(int i,int j){
        return f[i][j];
    }
}
class Pack {
    

    int[] weight, value, multiple;
    int nums;

    public Pack(int nums) {
        weight = new int[nums];
        value = new int[nums];
    }

    public Pack(int[] w, int[] v) {
        weight = w;
        value = v;
        nums = weight.length;
    }

    public Pack(int[] w, int[] v, int[] m) {
        weight = w;
        value = v;
        multiple = m;
        nums = weight.length;
    }

    public int id0(int volume) {
        

        

        

        int[] dp = new int[volume + 8],hash=new int[9003];
        for (int k = 0; k < nums; k++) {
            for (int i = volume; i > 0; i--) {
                hash[Math.max(0,dp[i])]=1;
                if(i>=weight[k]) hash[Math.max(0,dp[i - weight[k]] + value[k])]=1;
                if (i >= weight[k]) dp[i] = Math.max(dp[i - weight[k]] + value[k], dp[i]);

            }
        }
        for (int i =1; i < hash.length; i++) {
            if(hash[i]==0) {System.out.println(i);break;}
        }
        return dp[volume];
    }

    public int CompletePack(int volume) {
        

        int[] dp = new int[volume + 1];
        for (int k = 0; k < nums; k++) {
            for (int i = weight[k]; i < volume + 1; i++) {
                if (i >= weight[k]) dp[i] = Math.max(dp[i - weight[k]] + value[k], dp[i]);
            }
        }
        return dp[volume];
    }

    public int MultiplePack(int volume) {
        

        ArrayList<Integer> w = new ArrayList<>();
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < multiple.length; i++) {
            int k = multiple[i]&-multiple[i];
            while (true) {

                if (k <= multiple[i]) {
                    w.add(i, k * weight[i]);
                    v.add(i, k * value[i]);
                    multiple[i] -= k;
                    k *= 2;
                } else {
                    k = multiple[i];
                    if(k!=0) {
                        w.add(i, k * weight[i]);
                        v.add(i, k * value[i]);
                    }
                    break;
                }
            }
        }
        int[] w1 = new int[w.size()], v1 = new int[v.size()];
        for (int i = 0; i < w1.length; i++) {
            w1[i] = w.get(i);
            v1[i] = v.get(i);
        }
        weight = w1;
        value = v1;
        nums = weight.length;
        return id0(volume);
    }
}
class id4 {
    int[] parent, rank;
    int id9;

    public id4(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) parent[i] = i;
        Arrays.fill(rank, 1);
        id9 = size;
    }

    private int find(int a) {
        if (a > parent.length || a < 0) {
            throw new IllegalArgumentException("FindIndexOutOfBounds:" + a);
        }
        while (parent[a] != a) {
            

            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }

    public boolean isConnect(int a, int b) {
        return find(a) == find(b);
    }

    public int union(int a, int b) {
        

        int aroot = find(a);
        int broot = find(b);
        if (aroot == broot) return aroot;
        id9--;
        if (rank[aroot] > rank[broot]) {
            parent[broot] = aroot;
            return aroot;
        } else if (rank[aroot] < rank[broot]) {
            parent[aroot] = broot;
            return broot;
        } else {
            parent[broot] = aroot;
            rank[aroot]++;
            return aroot;
        }
    }
}
class Game{
    
}

class GeneratingFunction{
    ArrayList<Double>[] formulaCoefficient;
    int[] id10,less,more;
    int nowIndex=0,size;
    boolean id2=false;
    public GeneratingFunction(int size){
        

        

        this.size=size;
        less=new int[size];
        more=new int[size];
        id10=new int[size];
    }
    public int setAdd(int a,int b,int c){
        id10[nowIndex]=a;
        less[nowIndex]=b;
        more[nowIndex]=c;
        return nowIndex++;
    }
    public void id11(int index,int value,int max){
        

        ArrayList<Double> now=new ArrayList<Double>(max);
        now.add(0,1.0);
        for (int i = 1; i < max; i++) {
            now.add(i,value*i*1.0);
        }
        formulaCoefficient[index]=now;
    }
    public double[] Generate(int ask){
        double[] a=new double[13],b=new double[13],fact=new double[12];
        for (int i = 0; i < 11; i++) {
            int k=1;
            for (int j = i; j >0 ; j--) {
                k*=j;
            }
            fact[i]=k;
        }
        for (int i = 0; i <= more[0]; i+=id10[0]) {
            a[i]=1.0/fact[i];
        }

        for (int i = 1; i <= size; i++) {
            if(id10[i]==0) break;
            

            
            for (int j = 0; j <= ask; j++) {
                

                for (int k = 0; k+j<=ask&&k <= more[i]; k+=id10[i]) {
                    b[j+k]+=a[j]/fact[k];
                }
            }
            a=Arrays.copyOfRange(b,0,b.length);
            Arrays.fill(b,0);
        }
        for (int i = 0; i <= ask; i++) {
            a[i]*=fact[i];
        }
        return a;
    }

    



    
    public void fftChange(Complex[] a){

    }
    
    
    public void id16(Complex[] a,int start,int end,int on){
        int n=end-start+1,m=n/2,mid=(start+end)/2;
        if(n<=1) return;
        Complex[] buffer=new Complex[n];
        for (int i = 0; i < m; i++) {
            buffer[i]=a[start+2*i];
            buffer[i+m]=a[start+2*i+1];
        }
        for (int i = 0; i < n; i++) a[start+i]=buffer[i];
        id16(a,start,mid,1);
        id16(a,mid+1,end,1);
        for (int i = 0; i < m; i++) {
            

            

            Complex x = Complex.omega(n, i * on);
            buffer[i] = a[i].plus(x.multiple(a[i + m]));
            buffer[i + m] = a[i].minus(x.multiple(a[i + m]));
        }
        if(on==-1){
            for (int i = 0; i < buffer.length; i++) {
                buffer[i]=buffer[i].scale(1D/a.length);
            }
        }
        for (int i = 0; i < n; i++) {
            a[start+i]=buffer[i];
        }
    }




    public static Complex[] fft(Complex[] x) {
        int N = x.length;

        

        if (N == 1) return new Complex[]{x[0]};

        

        if (N % 2 != 0) {
            throw new RuntimeException("N is not a power of 2");
        }

        

        Complex[] even = new Complex[N / 2];
        for (int k = 0; k < N / 2; k++) {
            even[k] = x[2 * k];
        }
        Complex[] q = fft(even);

        

        Complex[] odd = even;  

        for (int k = 0; k < N / 2; k++) {
            odd[k] = x[2 * k + 1];
        }
        Complex[] r = fft(odd);

        

        Complex[] y = new Complex[N];
        for (int k = 0; k < N / 2; k++) {
            double kth = -2 * k * Math.PI / N;
            Complex wk = new Complex(Math.cos(kth), Math.sin(kth));
            y[k] = q[k].plus(wk.multiple(r[k]));
            y[k + N / 2] = q[k].minus(wk.multiple(r[k]));
        }
        return y;
    }
    public static Complex[] ifft(Complex[] x) {
        int N = x.length;
        Complex[] y = new Complex[N];

        

        for (int i = 0; i < N; i++) {
            y[i] = x[i].id6();
        }

        

        y = fft(y);

        

        for (int i = 0; i < N; i++) {
            y[i] = y[i].id6();
        }

        

        for (int i = 0; i < N; i++) {
            y[i] = y[i].scale(1.0 / N);
        }

        return y;

    }
    public static Complex[] id8(Complex[] x, Complex[] y) {

        

        

        if (x.length != y.length) { throw new RuntimeException("Dimensions don't agree"); }

        int N = x.length;

        

        Complex[] a = fft(x);
        Complex[] b = fft(y);

        

        Complex[] c = new Complex[N];
        for (int i = 0; i < N; i++) {
            c[i] = a[i].multiple(b[i]);
        }

        

        return ifft(c);
    }
    public static Complex[] convolve(Complex[] x, Complex[] y) {
        Complex ZERO = new Complex(0, 0);

        Complex[] a = new Complex[2*x.length];

        for (int i = 0;        i <   x.length; i++) a[i] = x[i];
        for (int i = x.length; i < 2*x.length; i++) a[i] = ZERO;

        Complex[] b = new Complex[2*y.length];
        for (int i = 0;        i <   y.length; i++) b[i] = y[i];
        for (int i = y.length; i < 2*y.length; i++) b[i] = ZERO;

        return id8(a, b);
    }

}