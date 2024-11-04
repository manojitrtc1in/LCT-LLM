import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Stack;
public class E396B {
	
	static long start = 0;

	static long count1 = 0;
	static long count2 = 0;
	
	public static void main(String[] args) {
		FastScanner in = new FastScanner(System.in);
		
		int N = in.nextInt();


		Node[] nodes = new Node[N];
		for(int i = 0; i < N; i++) {
			nodes[i] = new Node();
			nodes[i].value = in.nextInt();


			for(int j = 0; j < 21; j++)
				nodes[i].bits[j] = (nodes[i].value >> j) & 1;
		}
		
		for(int i = 0; i < N-1; i++) {
			int u = in.nextInt()-1;
			int v = in.nextInt()-1;




			nodes[u].neighbors.add(v);
			nodes[v].neighbors.add(u);
		}
		
		start = System.currentTimeMillis();
		
		dfs4(nodes, 0, new boolean[N]);
		int root = 0;
		


		
		dfs2_6(nodes, root, new boolean[N]);




		
		ArrayList<Long> list = new ArrayList<>();
		
		ans3(nodes, root, new boolean[N]);
		for(int j = 0; j < 21; j++)
			list.add(nodes[root].results[j]);
		


		
		long base = 1;
		long answer = 0;
		for(long i : list) {
			long t = base * i;
			answer += t;
			base <<= 1;
		}
		
		System.out.println(answer);




	}
	
	public static void main2(String[] args) {
		FastScanner in = new FastScanner(System.in);
		


		int N = 100000;
		Node[] nodes = new Node[N];
		for(int i = 0; i < N; i++) {
			nodes[i] = new Node();


			nodes[i].value = i+1;
			for(int j = 0; j < 21; j++)
				nodes[i].bits[j] = (nodes[i].value >> j) & 1;
		}
		
		for(int i = 0; i < N-1; i++) {




			int u = i;
			int v = i+1;
			nodes[u].neighbors.add(v);
			nodes[v].neighbors.add(u);
		}
		
		start = System.currentTimeMillis();
		


		dfs4(nodes, 0, new boolean[N]);
		int root = 0;
		
		System.out.println(System.currentTimeMillis()-start + " milliseconds");
		




		
		ArrayList<Long> list = new ArrayList<>();
		for(int i = 0; i < 21; i++) {
			
			for(int j = 0; j < N; j++)
				nodes[j].bit = (nodes[j].value >> i) & 1;
			


			dfs2_5(nodes, root, new boolean[N]);
			System.out.println("count1, 2: " + count1 + "  " + count2);


			long ans = ans2(nodes, root, new boolean[N]);
			
			System.out.println("i : " + i + " : " + (System.currentTimeMillis()-start) + " milliseconds");
			list.add(ans);
		}
		
		System.out.println(System.currentTimeMillis()-start + " milliseconds");
		
		long base = 1;
		long answer = 0;
		for(long i : list) {
			long t = base * i;
			answer += t;
			base <<= 1;
		}
		
		System.out.println(answer);
		System.out.println(System.currentTimeMillis()-start + " milliseconds");
		System.out.println("count1: " + count1 + " : 2: " + count2);
	}
	
	public static long ans3(Node[] nodes, int index, boolean[] visited) {
		Stack<Integer> stack = new Stack<>();
		stack.add(index);
		while(!stack.isEmpty()) {
			int u = stack.pop();
			Node N = nodes[u];
			
			if(N.children.size() == 0) {
				visited[u] = true;
				for(int j = 0; j < 21; j++) {
					N.results[j] = N.nums[j][1];
				}
				continue;
			}
			
			if(!visited[u]) {
				visited[u] = true;
				stack.add(u);
				for(int i : N.children)
					stack.add(i);
				continue;
			}
			
			for(int j = 0; j < 21; j++) {
				long answer = 0;
				
				long sum0 = 0;
				long sum1 = 0;
				long sumSquares = 0;
				long sumProd = 0;
				
				for(int i : N.children) {
					long[] t = nodes[i].nums[j];
					sum0 += t[0];
					sum1 += t[1];
					sumSquares += t[0]*t[0] + t[1]*t[1];
					sumProd += t[0]*t[1];
				}
				
				long X = (sum0*sum0 + sum1*sum1 - sumSquares) / 2;
				long Y = sum0*sum1 - sumProd;
				
				if(N.bits[j] == 0) {
					answer = Y;
					answer += sum1;
					answer += N.bits[j];
					for(int i : N.children) {
						long t = nodes[i].results[j];
						answer += t;
					}
					
					N.results[j] = answer;
				}
				else {
					answer = X;
					answer += sum0;
					answer += N.bits[j];
					for(int i : N.children) {
						long t = nodes[i].results[j];
						answer += t;
					}
					
					N.results[j] = answer;
				}
			}
		}
		
		return nodes[index].result;
	}
	
	public static long ans2(Node[] nodes, int index, boolean[] visited) {
		Stack<Integer> stack = new Stack<>();
		stack.add(index);
		while(!stack.isEmpty()) {
			int u = stack.pop();
			Node N = nodes[u];
			
			if(N.children.size() == 0) {
				N.result = N.num[1];
				visited[u] = true;
				continue;
			}
			
			if(!visited[u]) {
				visited[u] = true;
				stack.add(u);
				for(int i : N.children)
					stack.add(i);
				continue;
			}
			
			long answer = 0;
			
			long sum0 = 0;
			long sum1 = 0;
			long sumSquares = 0;
			long sumProd = 0;
			
			for(int i : N.children) {
				long[] t = nodes[i].num;
				sum0 += t[0];
				sum1 += t[1];
				sumSquares += t[0]*t[0] + t[1]*t[1];
				sumProd += t[0]*t[1];
			}
			
			long X = (sum0*sum0 + sum1*sum1 - sumSquares) / 2;
			long Y = sum0*sum1 - sumProd;
			
			if(N.bit == 0) {
				answer = Y;
				answer += sum1;
				answer += N.bit;
				for(int i : N.children) {
					long t = nodes[i].result;
					answer += t;
				}
				
				N.result = answer;
			}
			else {
				answer = X;
				answer += sum0;
				answer += N.bit;
				for(int i : N.children) {
					long t = nodes[i].result;
					answer += t;
				}
				
				N.result = answer;
			}
		}
		
		return nodes[index].result;
	}
	
	public static long ans(Node[] nodes, int index, boolean[] visited) {
		Node N = nodes[index];
		

		
		
		if(nodes[index].children.size() == 0) {
			return N.num[1];
		}
		
		
		long answer = 0;
		
		long sum0 = 0;
		long sum1 = 0;
		long sumSquares = 0;
		long sumProd = 0;
		
		for(int i : N.children) {


			



				long[] t = nodes[i].num;
				sum0 += t[0];
				sum1 += t[1];
				sumSquares += t[0]*t[0] + t[1]*t[1];
				sumProd += t[0]*t[1];


		}
		
		long X = (sum0*sum0 + sum1*sum1 - sumSquares) / 2;
		long Y = sum0*sum1 - sumProd;
		
		if(N.bit == 0) {
			answer = Y;
			answer += sum1;
			answer += N.bit;
			for(int i : N.children) {
				long t = ans(nodes, i, visited);
				answer += t;
			}
			
			return answer;
		}
		
		

		
		

		answer = X;
		
		

		answer += sum0;
		
		

		answer += N.bit;
		
		

		for(int i : N.children) {
			long t = ans(nodes, i, visited);
			answer += t;
		}
		
		return answer;
	}
	
	public static void dfs2_6(Node[] nodes, int index, boolean[] visited) {
		Stack<Integer> stack = new Stack<>();
		stack.add(index);
		while(!stack.isEmpty()) {
			int u = stack.pop();
			
			count1++;
			
			Node N = nodes[u];
			N.num = new long[2];
			
			if(N.children.size() == 0) {
				visited[u] = true;


				for(int j = 0; j < 21; j++)
					N.nums[j][N.bits[j]]++;
				continue;
			}
			
			if(!visited[u]) {
				visited[u] = true;
				stack.add(u);
				for(int i : N.children) {
					stack.add(i);
				}
				continue;
				
			}
			else {
				count2++;
				
				for(int j = 0; j < 21; j++) {
					long sum0 = 0;
					long sum1 = 0;
					for(int i : N.children) {
						sum0 += nodes[i].nums[j][0];
						sum1 += nodes[i].nums[j][1];
					}
					
					if(N.bits[j] == 0) {
						N.nums[j][0] = sum0;
						N.nums[j][1] = sum1;
					}
					else {
						N.nums[j][0] = sum1;
						N.nums[j][1] = sum0;
					}
					
					N.nums[j][N.bits[j]]++;
				}
			}
			
			
		}
	}
	
	public static void dfs2_5(Node[] nodes, int index, boolean[] visited) {
		Stack<Integer> stack = new Stack<>();
		stack.add(index);
		while(!stack.isEmpty()) {
			int u = stack.pop();
			
			count1++;
			
			Node N = nodes[u];
			N.num = new long[2];
			
			if(N.children.size() == 0) {
				visited[u] = true;
				N.num[N.bit]++;
				continue;
			}
			
			if(!visited[u]) {
				visited[u] = true;
				stack.add(u);
				for(int i : N.children) {
					stack.add(i);
				}
				continue;
				
			}
			else {
				count2++;
				
				long sum0 = 0;
				long sum1 = 0;
				for(int i : N.children) {
					sum0 += nodes[i].num[0];
					sum1 += nodes[i].num[1];
				}
				
				if(N.bit == 0) {
					N.num[0] = sum0;
					N.num[1] = sum1;
				}
				else {
					N.num[0] = sum1;
					N.num[1] = sum0;
				}
				
				N.num[N.bit]++;
			}
			
			
		}
	}
	
	public static void dfs2(Node[] nodes, int index, boolean[] visited) {
		Node N = nodes[index];
		N.num = new long[2];
		

		

		
		if(nodes[index].children.size() == 0) {
			N.num[N.bit]++;
			return;
		}
		
		for(int i : N.children) {
			dfs2(nodes, i, visited);
		}
		
		long sum0 = 0;
		long sum1 = 0;
		for(int i : N.children) {


			
			



				sum0 += nodes[i].num[0];
				sum1 += nodes[i].num[1];


		}
		
		if(N.bit == 0) {
			N.num[0] = sum0;
			N.num[1] = sum1;
		}
		else {
			N.num[0] = sum1;
			N.num[1] = sum0;
		}
		
		N.num[N.bit]++;
	}
	
	public static void dfs4(Node[] nodes, int index, boolean[] visited) {
		Stack<Integer> stack = new Stack<>();
		stack.add(index);
		while(!stack.isEmpty()) {
			int u = stack.pop();
			visited[u] = true;
			for(int i : nodes[u].neighbors) {
				if(!visited[i]) {
					nodes[u].children.add(i);
					stack.add(i);
				}
			}
		}
	}
	
	public static void dfs3(Node[] nodes, int index, boolean[] visited) {
		visited[index] = true;
		for(int i : nodes[index].neighbors) {
			if(!visited[i]) {
				nodes[index].children.add(i);
				dfs3(nodes, i, visited);
			}
		}
	}
	
	public static int centroidDecomposition(Node[] nodes, int index, boolean[] visited, int N) {
		int count = 0;
		for(int i : nodes[index].neighbors)
			if(!visited[i])
				count++;
		
		if(count == 0) {
			visited[index] = true;
			return index;
		}
		
		boolean foundCentroid = false;
		while(!foundCentroid) {
			
			foundCentroid = true;
			for(int i : nodes[index].neighbors) {
				if(!visited[i]) {
					if(nodes[i].size > N/2) {
						
						count = 0;
						foundCentroid = false;
						for(int j : nodes[index].neighbors)
							if(!visited[j] && j != i)
								count += nodes[j].size;
						
						nodes[index].size = count+1;
						index = i;
						nodes[index].size = N;
					}
				}
			}
		}
		
		visited[index] = true;
		for(int i : nodes[index].neighbors) {
			if(!visited[i]) {
				int next = centroidDecomposition(nodes, i, visited, nodes[i].size);
				nodes[index].children.add(next);


			}
		}
		
		return index;
	}
	
	public static void dfs(Node[] nodes, int index, boolean[] visited, int level) {
		visited[index] = true;
		System.out.println("level = " + level);
		int count = 0;
		for(int neigh : nodes[index].neighbors) {
			if(!visited[neigh]) {
				dfs(nodes, neigh, visited, level+1);
				count += nodes[neigh].size;
			}
		}
		
		nodes[index].size = count+1;
	}
	
	public static void print(boolean[] a) {
		for(int i = 0; i < a.length; i++)
			System.out.print(a[i] ? 1 : 0);
		System.out.println();
	}
	
	private static class Node {
		int value;
		int bit;
		int size;
		
		long result;
		
		int[] bits;
		long[] num;
		long[] results;
		long[][] nums;
		
		LinkedList<Integer> children;
		LinkedList<Integer> neighbors;
		
		public Node() {
			bits = new int[21];
			num = new long[2];
			results = new long[21];
			nums = new long[21][2];
			children = new LinkedList<>();
			neighbors = new LinkedList<>();
		}
	}
	
	
	static class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int chars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
		}

		int read() {
			if (chars == -1)
				throw new InputMismatchException();
			if (curChar >= chars) {
				curChar = 0;
				try {
					chars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (chars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}

}
