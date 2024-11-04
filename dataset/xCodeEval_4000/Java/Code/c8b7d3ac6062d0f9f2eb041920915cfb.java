import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.out;

public class cf {
	static int e97=1000000007;
	public static void main(String args[]) {
		cfReader in = new cfReader(System.in);
		int times = in.nextInt();
		

		

		

		StringBuilder sb = new StringBuilder();
		l:
		for (int i = 0; i < times; i++) {
			int n=in.nextInt(),k=in.nextInt();
			Integer[] arr=new Integer[n];
			long[] pre=new long[n];
			for (int j = 0; j < n; j++) {
				arr[j]=in.nextInt();
			}
			Arrays.sort(arr);
			
			pre[0]=arr[0];
			for (int j = 1; j < pre.length; j++) {
				pre[j]=pre[j-1]+arr[j];
			}
			long res=0,cnt=0,x,t;
			for (int j = pre.length - 1; j >= 0; j--) {
				t=pre[j]+(j+1)*cnt;
				if(t>k) continue ;
				

				x=(k-t)/(1+j)+1;
				res+=(j+1)*x;
				cnt+=x;
			}
			sb.append(res).append("\n");
		}
		out.println(sb);
		

		

	}
	static class node{
		ArrayList<Integer> al=new ArrayList();
		int id;
		public node(int a){id=a;}
	}
}
class cfReader{
	private final static int BUF_SZ = 65536;
	BufferedReader in;
	StringTokenizer tokenizer;
	public cfReader(InputStream in) {
		super();
		this.in = new BufferedReader(new InputStreamReader(in),BUF_SZ);
		tokenizer = new StringTokenizer("");
	}

	public String next() {
		while (!tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(in.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}
	public int nextInt() {
		return Integer.parseInt(next());
	}
	public long nextLong() {
		return Long.parseLong(next());
	}
}
class cfBinaryIndexTree{
	long[] tree1,tree2;
	int size;
	public cfBinaryIndexTree(int size) {
		tree1=new long[size+1];
		tree2=new long[size+1];
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
class cfPack {
	

	int[] weight, value, multiple;
	int nums;

	public cfPack(int nums) {
		weight = new int[nums];
		value = new int[nums];
	}

	public cfPack(int[] w, int[] v) {
		weight = w;
		value = v;
		nums = weight.length;
	}

	public cfPack(int[] w, int[] v, int[] m) {
		weight = w;
		value = v;
		multiple = m;
		nums = weight.length;
	}

	public int ZeroOnePack(int volume) {
		

		

		

		int[] dp = new int[volume + 8],hash=new int[9003];
		for (int k = 0; k < nums; k++) {
			for (int i = volume; i > 0; i--) {
				hash[max(0,dp[i])]=1;
				if(i>=weight[k]) hash[max(0,dp[i - weight[k]] + value[k])]=1;
				if (i >= weight[k]) dp[i] = max(dp[i - weight[k]] + value[k], dp[i]);

			}
		}
		for (int i =1; i < hash.length; i++) {
			if(hash[i]==0) {
				out.println(i);break;}
		}
		return dp[volume];
	}

	public int CompletePack(int volume) {
		

		int[] dp = new int[volume + 1];
		for (int k = 0; k < nums; k++) {
			for (int i = weight[k]; i < volume + 1; i++) {
				if (i >= weight[k]) dp[i] = max(dp[i - weight[k]] + value[k], dp[i]);
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
		return ZeroOnePack(volume);
	}
}
class cfOtherTool{

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
		int row = matrix1.length,column=matrix2[0].length,max= max(row,column),cnt1=0,cnt2=0;
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
	public static long fastPow(long source, long times, long mod){
		if(times==0||source==1) return 1;
		source%=mod;
		long i=1;
		while (times>0){
			if(times%2==1) i=(source*i)%mod;
			source*=source;
			source%=mod;
			times/=2;
		}
		return i;
	}
	public static long fastPow(long source, long times){
		if(times==0||source==1) return 1;
		long i=1;
		while (times>0){
			if(times%2==1) i=source*i;
			source*=source;
			times/=2;
		}
		return i;
	}

    

	public static long lowerBound(long[] a,long target){
		long l=0,r=0,mid,half,len=a.length-1;
		for (long l1 : a) {
			r=max(l1,r);
		}
		len=r;
		while (len>0){
			half=len/2;
			mid=l+half;

			if(boundValue(a,mid)<=target) {
				l=mid+1;
				len=len-half-1;
			}else len=half;
		}
		if(target>boundValue(a,l)) return -1;
		return l;
	}
	public static int lowerBound(int[] a,int target){
		int l=0,r=0,mid,half,len=a.length-1;
		while (len>0){
			half=len/2;
			mid=l+half;

			if(a[mid]<target) {
				l=mid+1;
				len=len-half-1;
			}else len=half;
		}
		if(target>a[l]) return -1;
		return l;
	}
	public static int upperBound(int[] a,int target){
		int l=0,r=0,mid,half,len=a.length-1;
		while (len>0){
			half=len/2;
			mid=l+half;

			if(a[mid]<=target) {
				l=mid+1;
				len=len-half-1;
			}else len=half;
		}
		if(target>=a[l]) return -1;
		return l;
	}
	private static long boundValue(long a[],long t){
		long res=0;
		for (long l : a) {
			if(l<t) res+=l;
			else res+=t;
		}
		return res;
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
		arraycopy(temp,0,s,i1+1,t);
		return s;
	}

    

	public static int[] primes(int range){
        
		int[] res=new int[range];
		int t=1;
		boolean[] vis=new boolean[range];
		vis[1]=true;
		for (int i = 2; i < range; i++) {
			if(!vis[i]) res[t++]=i;
			for (int j = 1; j < t&&i*res[j]<range; j++) {
				vis[res[j]*i]=true;
				if(i%res[j]==0) break;
			}
		}

		return Arrays.copyOfRange(res,1,t);
	}

	

	public static int KMP(String source,String needle){
		if(needle.length()>source.length()) return -1;
		if(needle.length()==0) return 0;
		int[] next=KMPBuildNext(needle);
		int la=source.length(),lb=needle.length();
		char[] c1=("0"+source).toCharArray(),c2=("0"+needle).toCharArray();
		for (int i = 0,j=0; i < la; ) {
			while(j>0&&c1[i+1]!=c2[j+1]) j=next[j];
			while(j==0&&c1[i+1]!=c2[j+1]) {
				if(i==la-1) return -1;
				i++;
			}
			i++;j++;
			if(j==lb) return i-j;
		}
		return -1;
	}
	public static int[] KMPBuildNext(String s1,String s2){

		int len= max(s1.length(),s2.length())+1,i=1,t=1;
		int[] res=new int[len];
		char[] c1=new char[len],c2=new char[len];
		for (char c:s1.toCharArray()) c1[i++]=c;
		i=1;
		for (char c:s2.toCharArray()) c2[i++]=c;
		int j=0;
		for (i = 0; i < len-1; i++) {
			while(j>0&&c1[i+1]!=c2[j+1]) j=res[j];
			if(c1[i+1]==c2[j+1]&&j<=i-1) j++;
			res[t++]=j;
		}
		return res;
	}
	private static int[] KMPBuildNext(String s){return KMPBuildNext(s,s);}


	public static boolean isSameSymbol(double a,double b){return (a>=0&&b>=0)||(a<=0&&b<=0);}

	public static int getBinaryOneCount(long a){
		int cnt=0;
		while(a!=0) {a&=a-1;cnt++;}
		return cnt;
	}
	public static int getBinaryOneCount(int a) {return getBinaryOneCount((long)a);}

	public static double distance(double x1,double y1,double x2,double y2){return Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));}


	public static long lucasC(long n,long m,long mod){
		if(m==0) return 1;
		return Cnm(n % mod, m % mod, mod) * lucasC(n / mod, m / mod, mod) % mod;
	}
	private static long Cnm(long n,long m,long mod){
		if(m>n) return 0;
		long up=1,down=1;
		for(long i = n - m + 1; i <= n; i++)up = up * i % mod;
		for(long i = 1; i <= m; i++)down = down * i % mod;
		return up*fastPow(down,mod-2,mod)%mod;
	}

	public static int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
}
class cfot extends cfOtherTool{}