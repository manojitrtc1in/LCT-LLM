
	import java.io.BufferedReader;
	import java.io.BufferedWriter;
	import java.io.IOException;
	import java.io.InputStreamReader;
	import java.io.OutputStreamWriter;
	import java.util.*;



	public class id1 {


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
			
			static long id3(long start1, long n, ArrayList<Long> arr, int a, long r) {
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
			static long id5(int n, ArrayList<Long> arr, long poi) {
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
			static void addEdge(ArrayList<ArrayList<edge>> graph, int from, int to, long weight) {
				edge temp = new edge(from, to, weight);
				edge temp1 = new edge(to, from, weight);
				graph.get(from).add(temp);
				

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
					
					int index = temp.a;
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
			static long [] id2() throws NumberFormatException, IOException{
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
				int a; 
				long b;
				public pair(int x, long y) {
					this.a = x;
					this.b = y;
				}
			}
			
			static long id6(long a) {
				for(long i = 2; i * i <= a; i++) {
					if(a % i == 0) {
						return i;
					}
				}
				return a;
			}
			static int id4(int [][] mat, int i, int j, int prev, int ans) {
				if(j >= mat[0].length) return ans;
				if(mat[i][j] == prev) {
					return id4(mat, i, j + 1, prev, ans + 1);
				}
				else return ans;
			}
			static int id7(int [][] mat, int i, int j, int prev, int ans) {
				if(i >= mat.length) return ans;
				if(mat[i][j] == prev) {
					return id7(mat, i + 1, j, prev, ans + 1);
				}
				else return ans;
			}
			static int diff(char [] a, char [] b) {
				int sum = 0;
				for(int i = 0; i < a.length; i++) {
					sum += Math.abs((int)a[i] - (int)b[i]);
				}
				return sum;
			}
			static void solve() throws IOException {
				int n = nextInt();
				String s = sc.readLine();
				char [] c = s.toCharArray();
				char [] c1 = s.toCharArray();
				int count = 0;
				char prev = 0;
				for(int i = 0; i < c.length; i+=2) {
					if(i > 0) prev = c[i - 1];
					if(c[i] != c[i + 1]) {
						if(i == 0) {
							c[i] = '0';
							c[i + 1] = '0';
						}else {
							c[i] = prev;
							c[i + 1] = prev;
						}
						count++;
					}
					
				}
				

				int sum1 = count(c);
				count = 0;
				for(int i = 0; i < c1.length; i+=2) {
					if(i > 0) prev = c1[i - 1];
					if(c1[i] != c1[i + 1]) {
						if(i == 0) {
							c1[i] = '1';
							c1[i + 1] = '1';
						}else {
							c1[i] = prev;
							c1[i + 1] = prev;
						}
						count++;
					}
					
				}
				

				int sum2 = count(c1);
				System.out.println(count + " " + Math.min(sum1, sum2));
				return;
			}
			static int count(char [] c) {
				int one = 0, zero = 0;
				int sum1 = 0, sum2 = 0;
				for(int i = 0; i < c.length; i++) {
					if(c[i] == '1') {
						sum1++;
						if(sum2 != 0) zero++;
						sum2 = 0;
					}else {
						sum2++;
						if(sum1 != 0) one++;
						sum1 = 0;
					}
				}
				if(sum1 != 0) one++;
				else if(sum2 != 0) zero++;
				return one + zero;
			}

			public static void main(String[] args) throws IOException {
				

				int t = Integer.parseInt(sc.readLine()); for(int i = 0; i < t; i++) 
				  solve();
			}
		}






