import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;


public class Codeforces_R_202_Div_1_B implements Runnable{

	boolean debug = false;
	
	static class Node{
		int id;
		Node parent;
		long a;
		long a0;
		List<Node> children = new ArrayList<Node>();
		
		long sum = Long.MAX_VALUE;

		@Override
		public String toString() {
			return String.format("<node %d, ch.sz=%d, a0=%d>", id+1,children.size(), a0);
		}
		
		
	}
	
	int[] used;
	List<Integer>[] adj;
	Node[] nodes;
	private void solve() throws IOException {
		int n = scanner.nextInt(); 

		nodes = new Node[n]; 
		for(int i=0; i<n; i++){
			nodes[i] = new Node();
			nodes[i].id = i;

			nodes[i].a = scanner.nextLong();
			nodes[i].a0 = nodes[i].a;
		}
		
		used = new int[n];
		adj = new List[n];
		for(int i=0; i<n; i++){
			adj[i] = new ArrayList<Integer>();
		}
		
		for(int i=0; i<n-1; i++){
			int x = scanner.nextInt()-1;
			int y = scanner.nextInt()-1;
			adj[x].add(y);
			adj[y].add(x);
		}
		
		used[0] = 1;
		buildTree(0);
			
		

		for(int iter=0; ;iter++){
			changed = false;
			dfs(nodes[0]);
			if (debug){
				System.out.printf("iter %d, root.sum=%d\n",iter, nodes[0].sum);
			}
			dfs2(nodes[0]);
			if (!changed)
				break;
		}
		
		long removed = 0;
		for(Node node : nodes){
			if (node.a0>0)
				removed += node.a0 - node.a;
		}
		out.println(removed);
	}
	
	private void buildTree(int u) {
		for(int v : adj[u]){
			if (used[v]==0){
				used[v]=1;
				nodes[u].children.add(nodes[v]);
				if (nodes[v].parent!=null) throw new RuntimeException();
				nodes[v].parent = nodes[u];
				buildTree(v);
			}
		}
	}
	
	boolean changed = false;
	
	private void dfs(Node node) {
		for (Node child : node.children){
			dfs(child);
		}
		
		long min = Long.MAX_VALUE;
		for (Node child : node.children){
			min = Math.min(min, child.sum);			
		}
		node.sum = node.a + min * node.children.size();
				
	}
	
	private void dfs2(Node node) {
		int cnt = node.children.size();
		if (cnt>0){
			for (Node child : node.children){
				child.sum = node.sum / cnt;
				dfs2(child);
			}
		}else{
			if (node.a != node.sum)
				changed = true;
			node.a = node.sum;
		}
	}
	

	final int BUF_SIZE = 1024 * 1024 * 8;

	final int INPUT_BUFFER_SIZE = 1024 * 1024 * 8 ;
	final int BUF_SIZE_INPUT = 1024;
	
	final int BUF_SIZE_OUT = 1024;
	
	boolean inputFromFile = false;
	String filenamePrefix = "A-small-attempt0";
	String inSuffix = ".in";
	String outSuffix = ".out";
	
	PrintStream out;
	ByteScanner scanner;
	ByteWriter writer;
	


	public void run() {
		try{
			InputStream bis = null;
			OutputStream bos = null;
			if (inputFromFile){
				File baseFile = new File(getClass().getResource("/").getFile());
				bis = new BufferedInputStream(
						new FileInputStream(new File(
								baseFile, filenamePrefix+inSuffix)),
								INPUT_BUFFER_SIZE);
				bos = new BufferedOutputStream(
						new FileOutputStream(
								new File(baseFile, filenamePrefix+outSuffix)));
				out = new PrintStream(bos);
			}else{
				bis = new BufferedInputStream(System.in, INPUT_BUFFER_SIZE);
				bos = new BufferedOutputStream(System.out);
				out = new PrintStream(bos);
			}
			scanner = new ByteScanner(bis, BUF_SIZE_INPUT, BUF_SIZE);
			writer = new ByteWriter(bos, BUF_SIZE_OUT);
			
			solve();
			out.flush();
		}catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public interface Constants{
		final static byte ZERO = '0';

		final static byte NINE = '9';
		final static byte SPACEBAR = ' '; 

		final static byte MINUS = '-'; 

		
		final static char FLOAT_POINT = '.';
	}
	
	public static class EofException extends IOException{
	}
	
	public static class ByteWriter implements Constants {
		
		int bufSize = 1024;
		byte[] byteBuf = new byte[bufSize];
		OutputStream os;
		
		public ByteWriter(OutputStream os, int bufSize){
			this.os = os;
			this.bufSize = bufSize;
		}
		
		public void writeInt(int num) throws IOException{
	         int byteWriteOffset = byteBuf.length;
	         if (num==0){
	        	 byteBuf[--byteWriteOffset] = ZERO;
	         }else{
	        	 int numAbs = Math.abs(num);
	        	 while (numAbs>0){
	        		 byteBuf[--byteWriteOffset] = (byte)((numAbs % 10) + ZERO);
	        		 numAbs /= 10;
	        	 }
	        	 if (num<0)
	        		 byteBuf[--byteWriteOffset] = MINUS;
	         }
	         os.write(byteBuf, byteWriteOffset, byteBuf.length - byteWriteOffset);
		}
		
		
		public void writeByteAr(byte[] ar) throws IOException{
			for (int i = 0; i < ar.length; i++) {
				byteBuf[i] = ar[i];
			}
			os.write(byteBuf,0,ar.length);
		}
		
		public void writeSpaceBar() throws IOException{
			byteBuf[0] = SPACEBAR;
			os.write(byteBuf,0,1);
		}
		
	}
	
	public static class ByteScanner implements Constants{
		
		InputStream is;
		
		public ByteScanner(InputStream is, int bufSizeInput, int bufSize){
			this.is = is;
			this.bufSizeInput = bufSizeInput;
			this.bufSize = bufSize;
			
			byteBufInput = new byte[this.bufSizeInput];
			byteBuf = new byte[this.bufSize];
		}
		
		public ByteScanner(byte[] data){
			byteBufInput = data;
			bufSizeInput = data.length;
			bufSize = data.length;
			byteBuf = new byte[bufSize];
			byteRead = data.length;
			bytePos = 0;
		}
		
		private int bufSizeInput;
		private int bufSize;
		
		byte[] byteBufInput;
		byte by=-1;
		int byteRead=-1;
		int bytePos=-1;

		byte[] byteBuf;
		int totalBytes;
		
		boolean eofMet = false;
		
		private byte nextByte() throws IOException{
			
			if (bytePos<0 || bytePos>=byteRead){
				byteRead = is==null? -1: is.read(byteBufInput);
				bytePos=0;
				if (byteRead<0){
					byteBufInput[bytePos]=-1;

					if (eofMet)
						throw new EofException();
					eofMet = true;
				}
			}
			return byteBufInput[bytePos++];
		}
		
		
		public byte nextChar() throws IOException{
			while ((by=nextByte())<=0x20);
			return by;
		}
		
		
		public byte nextCharOrSpacebar() throws IOException{
			while ((by=nextByte())<0x20);
			return by;
		}
		
	    
	    public String nextLine() throws IOException {
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
	    }
	    
	    public byte[] nextLineAsArray() throws IOException {
            readToken((byte)0x20);
            byte[] out = new byte[totalBytes];
            System.arraycopy(byteBuf, 0, out, 0, totalBytes);
            return out;
	    }
	    
		
	    
	    public String nextToken() throws IOException {
            readToken((byte)0x21);
            return new String(byteBuf,0,totalBytes);
	    }
	    
	    
	    private void readToken() throws IOException {	    	
            readToken((byte)0x21);
	    }
	    
	    private void readToken(byte acceptFrom) throws IOException {
            totalBytes = 0;
            while ((by=nextByte())<acceptFrom);
            byteBuf[totalBytes++] = by;
            while ((by=nextByte())>=acceptFrom){
                byteBuf[totalBytes++] = by;
            }
	    }
		
	    public int nextInt() throws IOException{
			readToken();
			int num=0, i=0;
			boolean sign=false;
			if (byteBuf[i]==MINUS){
				sign = true;
				i++;
			}
			for (; i<totalBytes; i++){
				num*=10;
				num+=byteBuf[i]-ZERO;
			}
			return sign?-num:num;
		}
		
		public long nextLong() throws IOException{
			readToken();
			long num=0;
			int i=0;
			boolean sign=false;
			if (byteBuf[i]==MINUS){
				sign = true;
				i++;
			}
			for (; i<totalBytes; i++){
				num*=10;
				num+=byteBuf[i]-ZERO;
			}
			return sign?-num:num;
		}
		
		
		
		public double nextDouble() throws IOException{
			readToken();
			char[] token = new char[totalBytes];
			for (int i = 0; i < totalBytes; i++) {
				token[i] = (char)byteBuf[i];
			}
			return Double.parseDouble(new String(token));
		}
		
		public int[] loadIntArray(int size) throws IOException{
			int[] a = new int[size];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			return a;
		}
		
		public long[] loadLongArray(int size) throws IOException{
			long[] a = new long[size];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextLong();
			}
			return a;
		}
	    
	}
	
	public static abstract class Timing{
		private static int counter = 0;
		protected String name = "Timing"+(++counter);
		private boolean debug;
		
		public Timing(boolean debug) {
			super();
			this.debug = debug;
		}
		
		public abstract void run();
		public void start(){
			long time1 = System.currentTimeMillis();
			run();
			long time2 = System.currentTimeMillis();
			if (debug)
				System.out.println(name+" time = "+(time2-time1)/1000.0+" s.");
		}
		
	}
	
	public static class TimeMonitor{
		String name;
		public TimeMonitor(String name) {
			super();
			this.name = name;
		}
		long time1;
		public TimeMonitor start(){
			time1 = System.currentTimeMillis();
			return this;
		}
		public void stop(){
			long time2 = System.currentTimeMillis();
			System.out.println(name+" time = "+(time2-time1)/1000.0+" s.");
		}
	}
	
	public static class Alg{
		public static interface BooleanChecker{
			public boolean check(long arg);
		}
		
		public static class BinarySearch{
					
			
			public BooleanChecker bc;
			
			
			
			public long search(long left, long right){
				while (left<=right){
					long mid = (left+right)/2;
					if (bc.check(mid)){
						right = mid-1;
					}else{
						left = mid+1;
					}
				}
				return left;
			}
			
			
			public long searchInverted(long left, long right){
				while (left<=right){
					long mid = (left+right)/2;
					if (!bc.check(mid)){
						right = mid-1;
					}else{
						left = mid+1;
					}
				}
				return left - 1; 
			}
		}
	}
	
	public static class Modulo{
		long mod = (long)1e9+7;
		
		public Modulo(long mod) {
			super();
			this.mod = mod;
		}

		public long inv(long a) {
			long res =  pow(a, mod-2);
			return res;
		}

		public long pow(long a, long x) {
			if (x==0)
				return 1;
			long part = 1;
			if ((x&1)!=0)
				part = a;
			return (part * pow((a*a)%mod, x>>1)) % mod;
		}
		
		public long c(long n, long m){
			long res = 1;
			for(int i=1; i<=m; i++){
				res = (res * (n-m+i)) % mod;
				res = (res * inv(i)) % mod;
			}
			return res;
		}
		
	}
	
	
	
	static class DisjointUnionSet implements Cloneable{
		
		int[] rank;
		int[] parent;
		
		protected DisjointUnionSet clone(){
			DisjointUnionSet cloned = new DisjointUnionSet(parent.length);
			for(int i=0; i<parent.length; i++){
				cloned.parent[i] = parent[i];
				cloned.rank[i] = rank[i];
			}
			return cloned;
		}

		public DisjointUnionSet(int n) {
			rank = new int[n];
			parent = new int[n];
			
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}
		
		@Override
		public String toString() {
			return "disj [parents=" + Arrays.toString(parent) + "]";
		}

		
		public void union(DisjointUnionSet set2){
			for(int i=0; i<parent.length; i++){
				parent[find(i)] = parent[find(set2.find(i))];
			}
		}
		
		
		
		public void union(int index1, int index2){
			int p1 = find(index1);
			int p2 = find(index2);
			
			if (rank[p1] > rank[p2]){
				parent[p2] = p1;
			}else if (rank[p2] > rank[p1]){
				parent[p1] = p2;
			}else{
				parent[p2] = p1;
				rank[p1]++;
			}
		}

		
		private int find(int index) {
			if (parent[index] != index)
				parent[index] =  find(parent[index]);
			return parent[index];
		}
		
		
		public int getCountDisjointSets(){
			int[] used = new int[parent.length];
			for(int i=0; i<parent.length; i++){
				used[find(i)] = 1;
			}
			int res = 0;
			for(int i=0; i<parent.length; i++){
				res += used[i];
			}
			return res;
		}
	}

	private static Random rnd = new Random();
	public static class ArrayUtils{
		public static void shuffle(int[] a){
			for(int j=a.length-1; j>=1; j--){
				int i = rnd.nextInt(j+1);
				swap(a, i, j);
			}
		}
		
		public static void swap(int[] a, int i, int j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	
	public static void main(String[] args) {
		new Codeforces_R_202_Div_1_B().run();
	}
	
}
