
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

 
public class id5 {
 
		static BufferedWriter output = new BufferedWriter(
	            new OutputStreamWriter(System.out));
		static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
		static int mod = 1000000007;
		static String toReturn = "";
 
		static int steps = Integer.MAX_VALUE;
		static int maxlen = 1000005;
		
		
		
		
		static long gcd(long a, long b) {
			if(b == 0) return a;
			else return gcd(b, a % b);
		}
 
		static long powerMod(long x, long y, int mod) {
			if(y == 0) return 1;
			long temp = powerMod(x, y / 2, mod);
			temp = ((temp % mod) * (temp % mod)) % mod;
			if(y % 2 == 0) return temp;
			else return ((x % mod) * (temp % mod)) % mod;
		}
		
		static long modInverse(long n, int p) {
			return powerMod(n, p - 2, p);
		}
		
		static long nCr(int n, int r, int mod, long [] fact, long [] ifact) {
			return ((fact[n] % mod) * ((ifact[r] * ifact[n - r]) % mod)) % mod;
		}
		
		static boolean isPrime(long a) {
			if(a == 1) return false;
			else if(a == 2 || a == 3 || a== 5) return true;
			else if(a % 2 == 0 || a % 3 == 0) return false;
			for(int i = 5; i * i <= a; i = i + 6) {
				if(a % i == 0 || a % (i + 2) == 0) return false;
			}
			return true;
		}
		static int [] seive(int a) {
			int [] toReturn = new int [a + 1];
			for(int i = 0; i < a; i++) toReturn[i] = 1;
			toReturn[0] = 0;
			toReturn[1] = 0;
			toReturn[2] = 1;
			for(int i = 2; i * i <= a; i++) {
				if(toReturn[i] == 0) continue;
				for(int j = 2 * i; j <= a; j += i) toReturn[j] = 0;
			}
			return toReturn;
		}
		static long [] fact(int a) {
			long [] arr = new long[a + 1];
			arr[0] = 1;
			for(int i = 1; i < a + 1; i++) {
				arr[i] = (arr[i - 1] * i) % mod;
			}
			return arr;
		}
		
		
		
		static void swap(int i, int j, long[] arr) {
			long temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		static void swap(int i, int j, int[] arr) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		static void swap(int i, int j, String [] arr) {
			String temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		static void swap(int i, int j, char [] arr) {
			char temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
		
		
		
		
		static boolean BinaryCheck(long test, long [] arr, long health) {
			for(int i = 0; i <= arr.length - 1; i++) {
				if(i == arr.length - 1) health -= test;
				else if(arr[i + 1] - arr[i] > test) {
					health = health - test;
				}else {
					health = health - (arr[i + 1] - arr[i]);
				}
				if(health <= 0) return true;
			}
			return false;
		}
		
		static long id2(long start1, long n, ArrayList<Long> arr, int a, long r) {
			long start = start1, end = n, ans = -1;
			while(start < end) {
				long mid = (start + end) / 2;
				

				if(arr.get((int)mid) + arr.get(a) <= r && mid != start1) {
					ans = mid;
					start = mid + 1;
				}else{
					end = mid;
				}
			}
			

			return ans;
		}
		static int binarySearch(int start, int end, long [] arr, long val) {
			
			while(start < end) {
				
				int mid = (int)Math.ceil((start + end) / 2.0);
				

				if(arr[mid] > val) end = mid - 1;
				else start = mid;
			}
			return start;
		}
		
		
		
		
		
		static int recurse(int x, int y, int n, int steps1, Integer [][] dp) {
			if(x > n || y > n) return 0;
			if(dp[x][y] != null) {
				return dp[x][y];
			}
			else if(x == n || y == n) {
				
				return steps1;
			}
			
			return dp[x][y] = Math.max(recurse(x + y, y, n, steps1 + 1, dp), recurse(x, x + y, n, steps1 + 1, dp));
		}
		
		
		
		static class edge{
			int from, to;
			long weight;
			public edge(int x, int y, long weight2) {
				this.from = x;
				this.to = y;
				this.weight = weight2;
			}
		}
		static class sort implements Comparator<pair>{
 
			
			@Override
			public int compare(pair o1, pair o2) {
				

				return (int)o1.a - (int)o2.a;
			}
			
		}
		static void addEdge(ArrayList<ArrayList<edge>> graph, int from, int to, long weight) {
			edge temp = new edge(from, to, weight);
			edge temp1 = new edge(to, from, weight);
			graph.get(from).add(temp);
			

		}
		static int ans = 0;
		
		
		
		
		static void id9(ArrayList<ArrayList<Integer>> graph, int vertex, boolean [] visited, ArrayList<Integer> toReturn) {
			if(visited[vertex]) return;
			visited[vertex] = true;
			for(int i = 0; i < graph.get(vertex).size(); i++) {
				if(!visited[graph.get(vertex).get(i)]) id9(graph, graph.get(vertex).get(i), visited, toReturn);
			}
			toReturn.add(vertex);
		}
		static boolean id0(ArrayList<ArrayList<Integer>> graph, int vertex, boolean [] visited, boolean [] reStack) {
			if(reStack[vertex]) return true;
			if(visited[vertex]) return false;
			reStack[vertex] = true;
			visited[vertex] = true;
			
			for(int i = 0; i < graph.get(vertex).size(); i++) {
				if(id0(graph, graph.get(vertex).get(i), visited, reStack)) return true;
			}
			reStack[vertex] = false;
			return false;
		}
		static int e = 0;
		static long mst(PriorityQueue<edge> pq, int nodes) {
			long weight = 0;
			while(!pq.isEmpty()) {
				edge temp = pq.poll();
				int x = parent(parent, temp.to);
				int y =  parent(parent, temp.from);
				if(x != y) {
					

					union(x, y, rank, parent);
					weight += temp.weight;
					e++;
				}
			}
			return weight;
		}
		static void floyd(long [][] dist) { 

			for(int k = 0; k < dist.length; k++) {
				for(int i = 0; i < dist.length; i++) {
					for(int j = 0; j < dist.length; j++) {
						if(dist[i][j] > dist[i][k] + dist[k][j]) {
							dist[i][j] = dist[i][k] + dist[k][j];
						}
					}
				}
			}
		}
		static void dijkstra(ArrayList<ArrayList<edge>> graph, long [] dist, int src) {
			for(int i = 0; i < dist.length; i++) dist[i] = Long.MAX_VALUE / 2;
			dist[src] = 0;
			boolean visited[] = new boolean[dist.length];
			PriorityQueue<pair> pq = new PriorityQueue<>(new sort());
			pq.add(new pair(src, 0));
			while(!pq.isEmpty()) {
				pair temp = pq.poll();
				
				int index = (int)temp.a;
				for(int i = 0; i < graph.get(index).size(); i++) {
					if(dist[graph.get(index).get(i).to] > dist[index] + graph.get(index).get(i).weight) {
						dist[graph.get(index).get(i).to] = dist[index] + graph.get(index).get(i).weight;
						pq.add(new pair(graph.get(index).get(i).to, graph.get(index).get(i).weight));
					}
					
				}
			}
		}
		static int parent1 = -1;
		static boolean ford(ArrayList<ArrayList<edge>> graph1, ArrayList<edge> graph, long [] dist, int src, int [] parent) {
			for(int i = 0; i < dist.length; i++) dist[i] = Long.MIN_VALUE / 2;
			dist[src] = 0;
			boolean hasNeg = false;
			for(int i = 0; i < dist.length - 1; i++) {
				for(int j = 0; j < graph.size(); j++) {
					int from = graph.get(j).from;
					int to = graph.get(j).to;
					long weight = graph.get(j).weight;
					if(dist[to] < dist[from] + weight) {
						dist[to] = dist[from] + weight;
						parent[to] = from;
					}
				}
			}
			for(int i = 0; i < graph.size(); i++) {
				int from = graph.get(i).from;
				int to = graph.get(i).to;
				long weight = graph.get(i).weight;
				if(dist[to] < dist[from] + weight) {
					parent1 = from;
					hasNeg = true;
				
					

					if(ans == 2) break;
					else ans = 0;
					
				}
			}
			return hasNeg;
		}
		
		
		static int [] rank;
		static int [] parent;
		static int parent(int [] parent, int x) {
			if(parent[x] == x) return x;
			else return parent[x] = parent(parent, parent[x]);
		}
		static boolean union(int x, int y, int [] rank, int [] parent) {
			if(parent(parent, x) == parent(parent, y)) {
				return true;
			}
			if(rank[x] > rank[y]) {
				swap(x, y, rank);
			}
			rank[x] += rank[y];
			parent[y] = x;
			return false;
		}
		
		
		
		
		
		static int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(sc.readLine());
		}
		static long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(sc.readLine());
		}
		static long [] id1() throws NumberFormatException, IOException{
			String [] s = sc.readLine().split(" ");
			long [] toReturn = new long[s.length];
			for(int i = 0; i < s.length; i++) {
				toReturn[i] = Long.parseLong(s[i]);
			}
			return toReturn;
		}
		static int max = 0;
		static int [] id8() throws NumberFormatException, IOException{
			String [] s = sc.readLine().split(" ");
			
			

			int [] toReturn = new int[s.length];
		
			for(int i = 0; i < s.length; i++) {
				toReturn[i] = Integer.parseInt(s[i]);
			}
			return toReturn;
		}
	
		
		static long [] preCompute(int level) {
			long [] toReturn = new long[level];
			toReturn[0] = 1;
			toReturn[1] = 16;
			for(int i = 2; i < level; i++) {
				toReturn[i] = ((toReturn[i - 1] % mod) * (toReturn[i - 1] % mod)) % mod;
			}
			return toReturn;
		}
		static class pair{
			long a; 
			long b;
			long d;
			public pair(long in, long y) {
				this.a = in;
				this.b = y;
				this.d = 0;
			}
		}
		
		
		
		static int [] id7(char [] s) {
			Stack<Integer> stack = new Stack<>();
			int [] toReturn = new int[s.length];
			for(int i = 0; i < s.length; i++) {
				if(!stack.isEmpty() && s[stack.peek()] >= s[i]) {
					stack.pop();
				}
				if(stack.isEmpty()) {
					stack.push(i);
					toReturn[i] = -1;
				}else {
					toReturn[i] = stack.peek();
					stack.push(i);
				}
			}
			return toReturn;
		}
		static int [] id6(char [] s) {
			Stack<Integer> stack = new Stack<>();
			int [] toReturn = new int[s.length];
			for(int i = s.length - 1; i >= 0; i--) {
				if(!stack.isEmpty() && s[stack.peek()] >= s[i]) {
					stack.pop();
				}
				if(stack.isEmpty()) {
					stack.push(i);
					toReturn[i] = -1;
				}else {
					toReturn[i] = stack.peek();
					stack.push(i);
				}
			}
			return toReturn;
		}
		static int lps(String s) {
			int max = 0;
			int [] lps = new int[s.length()];
			lps[0] = 0;
			int j = 0;
			for(int i = 1; i < lps.length; i++) {
				j = lps[i - 1];
				while(j > 0 && s.charAt(i) != s.charAt(j)) j = lps[j - 1];
				if(s.charAt(i) == s.charAt(j)) {
					lps[i] = j + 1;
					max = Math.max(max, lps[i]);
				}
			}
			return max;
		}
		
		static int [][] vectors = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		
		static String dir = "DRUL";
		static boolean check(int i, int j, boolean [][] visited) {
			if(i >= visited.length || j >= visited[0].length) return false;
			if(i < 0 || j < 0) return false;
			return true;
		}
	
	
		static void selectionSort(long arr[], long [] arr1, ArrayList<ArrayList<Integer>> ans)
		    {
		        int n = arr.length;
		 
		        
		        for (int i = 0; i < n-1; i++)
		        {
		          
		            int min_idx = i;
		            for (int j = i+1; j < n; j++)
		                if (arr[j] < arr[min_idx])
		                    min_idx = j;
		                else if(arr[j] == arr[min_idx]) {
		                	if(arr1[j] < arr1[min_idx]) min_idx = j;
		                }
		 
		          if(i == min_idx) {
		        	  continue;
		          }
		           ArrayList<Integer> p = new ArrayList<Integer>();
		           p.add(min_idx + 1);
		           p.add(i + 1);
		           ans.add(new ArrayList<Integer>(p));
		           swap(i, min_idx, arr);
		           swap(i, min_idx, arr1);
		        }
		    }
		
		
		
		
		static int saved = Integer.MAX_VALUE;
		static String ans1 = "";
		public static boolean isValid(int x, int y, String [] mat) {
			if(x >= mat.length || x < 0) return false;
			if(y >= mat[0].length() || y < 0) return false;
			return true;
		}
		
		static boolean id4(int i, int j, int [][] arr, int sum, Boolean [][][] dp) {
			if(i == arr.length - 1 && j == arr[0].length - 1) {
				if(sum + arr[i][j] == 0) return true;
				return false;
			}
			
			if(i == arr.length) return false;
			else if(j == arr[0].length) return false;
			if(sum < 0 && dp[i][j][arr.length + arr[0].length + 1 + sum] != null) return dp[i][j][arr.length + arr[0].length + 1 + sum];
			if(sum > 0 && dp[i][j][sum] != null) return dp[i][j][sum];
			if(sum < 0) dp[i][j][arr.length + arr[0].length + 1 + sum] = id4(i + 1, j, arr, sum + arr[i][j], dp) || id4(i, j + 1, arr, sum + arr[i][j], dp);
			return dp[i][j][sum] = id4(i + 1, j, arr, sum + arr[i][j], dp) || id4(i, j + 1, arr, sum + arr[i][j], dp);
		}
		
		
		public static void id3(ArrayList<Character> arr, int index, String s, int max, ArrayList<String> toReturn) {
			if(s.length() == max) {
				toReturn.add(s);
				return;
			}
			if(index == arr.size()) return;
			id3(arr, index + 1, s + arr.get(index), max, toReturn);
			id3(arr, index + 1, s, max, toReturn);
		}
		
		public static long recurse(long [] arr, int i, int n, Long [][] dp) {
			if(n == 0) return 0;
			if(i >= arr.length - 1) return Integer.MAX_VALUE / 2;
			if(dp[i][n] != null) return dp[i][n];
			if(arr[i - 1] < arr[i] && arr[i + 1] < arr[i]) {
				return dp[i][n] = Math.min(recurse(arr, i + 2, n - 1, dp), recurse(arr, i + 1, n, dp));
			}
			long cost = Math.max(arr[i - 1], arr[i + 1]) - arr[i] + 1;
			long taken = recurse(arr, i + 2, n - 1, dp);
			long notTaken = recurse(arr, i + 1, n, dp);
			
			return dp[i][n] = Math.min(taken + cost, notTaken);
		}
		static void dfsDP(ArrayList<ArrayList<Integer>> graph, int src, int [] dp1, int [] dp2, int parent) {
			int sum1 = 0; int sum2 = 0;
			
			for(int x : graph.get(src)) {
				if(x == parent) continue;
				dfsDP(graph, x, dp1, dp2, src);
				sum1 += Math.min(dp1[x], dp2[x]);
				sum2 += dp1[x];
			}
			
			dp1[src] = 1 + sum1;
			dp2[src] = sum2;
			System.out.println(src + " " + dp1[src] + " " + dp2[src]);
		}
		static int balanced = 0;
		static int [] dfs(ArrayList<ArrayList<Integer>> graph, int src, int parent, String color) {
			int black = 0; int white = 0;
			for(int x : graph.get(src)) {
				if(x == parent) continue;
				int [] temp = dfs(graph, x, src, color);
				black += temp[0];
				white += temp[1];
			}
			int [] toReturn = new int [2];
			if(color.charAt(src) == 'W') {
				toReturn[0] = black;
				toReturn[1] = white + 1;
				if(toReturn[0] == toReturn[1]) {
					balanced++;
				}
			}else {
				toReturn[0] = black + 1;
				toReturn[1] = white;
				if(toReturn[0] == toReturn[1]) {
					balanced++;
				}
			}
			return toReturn;
		}
	
		static void solve() throws IOException {
			int n = nextInt();
			int [] arr = id8();
			String color = sc.readLine();
			
			ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
			for(int i = 0; i < n; i++) graph.add(new ArrayList<Integer>());
			
			for(int i = 0; i < arr.length; i++) {
				graph.get(i + 1).add(arr[i] - 1);
				graph.get(arr[i] - 1).add(i + 1);
			}
			
			dfs(graph, 0, -1, color);
			output.write(balanced + "\n");
			balanced = 0;
		}
		
		public static void main(String[] args) throws IOException {
			

			int t = Integer.parseInt(sc.readLine()); for(int i = 0; i < t; i++) 
			  solve();
			output.flush();
		}
 
	}
	class TreeNode {
		int val;
		TreeNode next;
		public TreeNode(int x, TreeNode y) {
			this.val = x;
			this.next = y;
		}
	}

 