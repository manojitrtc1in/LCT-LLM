

	import java.io.BufferedReader;
	import java.io.BufferedWriter;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.io.OutputStreamWriter;
	import java.util.*;





	public class  Subtle_Substring_Subtraction
	{


			static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			static int mod = 998244353;
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
			
			
			
			static void swap(int i, int j, int [] arr) {
				int temp = arr[i];
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
			
			static long binarySearchModified(long start1, long n, ArrayList<Long> arr, int a, long r) {
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
			static long binarySearchModified1(int n, ArrayList<Long> arr, long poi) {
				long start = 0, end = n, ans = -1;
				while(start < end) {
					long mid = (start + end) / 2;
					

					if(arr.get((int)mid) <= poi) {
						ans = mid;
						start = mid + 1;
					} else {
						end = mid;
					}
				}
				

				return ans;
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
					

					if(o1.b > o2.b) return 1;
					else return -1;
				}
				
			}
			static void addEdge(ArrayList<ArrayList<Integer>> graph, int from, int to, long weight) {
				
				graph.get(from).add(to);
				graph.get(to).add(from);
			}
			static int ans = 0;
			
			static void dfs(ArrayList<ArrayList<edge>> graph, int vertex, boolean [] visited, int dest) {
				

				if(ans == 2) return;
				if(vertex == dest) {
					ans++;
					return;
				}
				if(visited[vertex]) return;
				visited[vertex] = true;
				
				for(int i = 0; i < graph.get(vertex).size(); i++) {
					edge temp = graph.get(vertex).get(i);
					if(!visited[temp.to]) {
						

						

						dfs(graph, temp.to, visited, dest);
						


					}
				}
			}
			static void bfs(ArrayList<ArrayList<edge>> graph, int vertex, boolean [] visited, int [] toReturn, Queue<Integer> q, int weight) {
				if(visited[vertex]) return;
				visited[vertex] = true;
				if(graph.get(vertex).size() > 2) return;
				int first = weight;
				for(int i = 0; i < graph.get(vertex).size(); i++) {
					edge temp = graph.get(vertex).get(i);
					if(!visited[temp.to]) {
						q.add(temp.to);
						toReturn[(int) temp.weight] = weight;
						weight = 5 - weight;
					}
				}
				if(!q.isEmpty())bfs(graph, q.poll(), visited, toReturn, q, 5 - first);
			}
			
			static void topoSort(ArrayList<ArrayList<Integer>> graph, int vertex, boolean [] visited, ArrayList<Integer> toReturn) {
				if(visited[vertex]) return;
				visited[vertex] = true;
				for(int i = 0; i < graph.get(vertex).size(); i++) {
					if(!visited[graph.get(vertex).get(i)]) topoSort(graph, graph.get(vertex).get(i), visited, toReturn);
				}
				toReturn.add(vertex);
			}
			static boolean isCyclicDirected(ArrayList<ArrayList<Integer>> graph, int vertex, boolean [] visited, boolean [] reStack) {
				if(reStack[vertex]) return true;
				if(visited[vertex]) return false;
				reStack[vertex] = true;
				visited[vertex] = true;
				
				for(int i = 0; i < graph.get(vertex).size(); i++) {
					if(isCyclicDirected(graph, graph.get(vertex).get(i), visited, reStack)) return true;
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
					
					int index = temp.a;
					for(int i = 0; i < graph.get(index).size(); i++) {
						if(dist[graph.get(index).get(i).to] > dist[index] + graph.get(index).get(i).weight) {
							dist[graph.get(index).get(i).to] = dist[index] + graph.get(index).get(i).weight;
							

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
						dfs(graph1, parent1, new boolean[dist.length], dist.length - 1);
						

						dfs(graph1, 0, new boolean[dist.length], parent1);
						

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
			static long [] inputLongArr() throws NumberFormatException, IOException{
				String [] s = sc.readLine().split(" ");
				long [] toReturn = new long[s.length];
				for(int i = 0; i < s.length; i++) {
					toReturn[i] = Long.parseLong(s[i]);
				}
				return toReturn;
			}
			static int max = 0;
			static int [] inputIntArr() throws NumberFormatException, IOException{
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
				int a; 
				int b;
				public pair(int x, int y) {
					this.a = x;
					this.b = y;
				}
			}
			static int [][] vector = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
			static String dir = "RDUL";
			static boolean isValid(int x, int y, char [][] grid) {
				if(x >= grid.length || y >= grid[0].length) return false;
				if(x < 0 || y < 0) return false;
				return true;
			}
			static pair modifiedBfs(pair parent [][], boolean [][] visited, pair src, char [][] graph, char[][] path) {
				Queue<pair> q = new LinkedList<>();
				q.add(src);
				visited[src.a][src.b] = true;
				boolean found = false;
				while(!q.isEmpty()) {
					pair temp = q.poll();
					for(int i = 0; i < vector.length; i++) {
						int x = temp.a + vector[i][0], y = temp.b + vector[i][1];
						if(isValid(x, y, graph) && !visited[x][y]) {
							if(graph[x][y] == '.') {
								q.add(new pair(x, y));
								visited[x][y] = true;
								parent[x][y] = temp;
								path[x][y] = dir.charAt(i);
							}else if(graph[x][y] == 'B') {
								visited[x][y] = true;
								parent[x][y] = temp;
								found = true;
								path[x][y] = dir.charAt(i);
								return new pair(x, y);
							}
						}
					}
					
				}
				return null;
				
			}
			static int start = -1;
			static int end = -1;
		static int recurse(boolean [] visited, int [][] list, int i) {
			if(i >= list.length) return 0;
			int a = 0, b = 0;
			if(visited[list[i][0] - 1] || visited[list[i][1] - 1]) {
				return a = recurse(visited, list, i + 1);
			}else {
				visited[list[i][0] - 1] = true;
				visited[list[i][1] - 1] = true;
				a = recurse(visited, list, i + 1) + 1;
				visited[list[i][0] - 1] = false;
				visited[list[i][1] - 1] = false;
				b = recurse(visited, list, i + 1);
				return Math.max(a, b);
			}
			
			
		}
			static void solve() throws IOException {
				String s = sc.readLine();
				
				if(s.length() % 2 == 0) {
					long sum = 0;
					for(int i = 0; i < s.length(); i++) {
						sum += (int)s.charAt(i) - (int)'a' + 1;
					}
					System.out.println("Alice" + " " + sum);
				}else {
					if(s.length() == 1) {
						System.out.println("Bob" + " " + (s.charAt(0) - 'a' + 1));
					}else {
						if(s.charAt(0) > s.charAt(s.length() - 1)) {
							long sum = 0;
							for(int i = 0; i < s.length() - 1; i++) {
								sum += (int)s.charAt(i) - (int)'a' + 1;
							}
							System.out.println("Alice" + " " + (sum - (s.charAt(s.length() - 1) - 'a' + 1)));
							
						}else {
							long sum = 0;
							for(int i = 1; i < s.length(); i++) {
								sum += (int)s.charAt(i) - (int)'a' + 1;
							}
							System.out.println("Alice" + " " + (sum - (s.charAt(0) - 'a' + 1)));
						}
					}
				}
			}

			public static void main(String[] args) throws IOException {
				

				int t = Integer.parseInt(sc.readLine()); for(int i = 0; i < t; i++) 
				  solve();
			}
		}






