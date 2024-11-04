import java.io.BufferedInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.PriorityQueue;

public class a 
{
	public static void main(String[] arg)
	{
		new a();
	}
	int[] dp = new int[5000001];
	public a()
	{
		JoltyScanner in = new JoltyScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int m = in.nextInt();
		DirectedGraph graph = new DirectedGraph(2*n + 2);
		int source = 2*n + 2 - 2;
		int sink = 2*n + 2 - 1;
		int inflow = 0;
		for(int i = 0; i < n; i++)
		{
			int temp = in.nextInt();
			inflow += temp;
			graph.addEdge(source, i, temp);
			graph.addEdge(i, source, 0);
		}
		int goal = 0;
		int INF = 1_000_000_000;
		for(int i = 0; i < n; i++)
		{
			graph.addEdge(i, i+n, INF);
			graph.addEdge(i+n, i, 0);
		}
		for(int i = 0; i < n; i++)
		{
			int temp = in.nextInt();
			goal += temp;
			graph.addEdge(i+n, sink, temp);
			graph.addEdge(sink, i+n, 0);
		}
		for(int i = 0; i < m; i++)
		{
			int v1 = in.nextInt()-1;
			int v2 = in.nextInt()-1;
			graph.addEdge(v1, v2+n, INF);
			graph.addEdge(v2+n, v1, 0);
			graph.addEdge(v2, v1+n, INF);
			graph.addEdge(v1+n, v2, 0);
		}
		int maxflow = graph.edmondkarp(source, sink);
		if(maxflow != goal || inflow != goal) out.println("NO");
		else
		{
			System.out.println("YES");
			int[][] answer = new int[n][n];
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(i == j) continue;
					if(graph.adjList.get(i).containsKey(j+n))
					{
						answer[i][j] = graph.adjList.get(j+n).get(i);
					}
				}
			}
			for(int i = 0; i < n; i++)
			{
				int total = 0;
				for(int j = 0; j < n; j++)
				{
					total += answer[i][j];
				}
				answer[i][i] = graph.adjList.get(source).get(i) + graph.adjList.get(i).get(source) - total;
			}
			for(int i = 0; i < answer.length; i++)
			{
				for(int j = 0; j < n; j++)
				{
					System.out.print(answer[i][j] + " ");
				}
				System.out.println();
			}
		}
		out.close();
	}
	
	class DirectedGraph 
	{
		ArrayList<HashMap<Integer, Integer>> adjList;
		public DirectedGraph(int size)
		{
			adjList = new ArrayList<HashMap<Integer, Integer>>();
			for(int i = 0; i < size; i++)
			{
				adjList.add(new HashMap<Integer, Integer>());
			}
		}
		

		public void addEdge(int source, int sink, int w)
		{
			adjList.get(source).put(sink, w);
		}
		public void addEdge(int source, int sink)
		{
			adjList.get(source).put(sink, 1);
		}
		public void addEdgeWeight(int source, int sink, int w)
		{
			adjList.get(source).put(sink, w + adjList.get(source).get(sink));
		}
		

		int[] pre;
		int[] low;
		int inc;
		int[] scc;
		int sccTotal;
		ArrayDeque<Integer> stack;
		public void getComp()
		{
			for(int i = 0; i < adjList.size(); i++) tarjandfs(i);
			if(stack.size() > 0)
			{
				while(stack.size() > 0)
					scc[stack.pop()] = sccTotal;
				sccTotal++;
			}
		}
		public void tarjan()
		{
			pre = new int[adjList.size()];
			Arrays.fill(pre, -1);
			low = new int[adjList.size()];
			inc = 0;
			scc = new int[adjList.size()];
			sccTotal = 0;
			getComp();
		}
		public int[] getSCC()
		{
			if(scc == null) tarjan();
			return scc;
		}
		public int tarjandfs(int cur)
		{
			if(pre[cur] != -1)
				return low[cur];
			low[cur] = pre[cur] = inc++;
			stack.push(cur);
			for(int v : adjList.get(cur).keySet())
				low[cur] = Math.min(low[cur], tarjandfs(v));
			if(pre[cur] == low[cur])
			{
				int temp;
				do
				{
					temp = stack.pop();
					low[temp] = adjList.size();
					scc[temp] = sccTotal;
				}while(temp != cur);
				sccTotal++;
			}
			return low[cur];
		}
		public ArrayList<HashSet<Integer>> compress()
		{
			ArrayList<HashSet<Integer>> answer = new ArrayList<HashSet<Integer>>();
			for(int i = 0; i < sccTotal; i++) answer.add(new HashSet<Integer>());
			for(int i = 0; i < adjList.size(); i++)
			{
				for(int v : adjList.get(i).keySet())
				{
					if(scc[i] != scc[v])
					{
						answer.get(i).add(scc[v]);
					}
				}
			}
			return answer;
		}
		

		public ArrayList<Integer> topsortdfs()
		{
			ArrayList<Integer> answer = new ArrayList<Integer>();
			ArrayDeque<Integer> stack = new ArrayDeque<Integer>();
			boolean[] used = new boolean[adjList.size()];
			for(int i = 0; i < adjList.size(); i++)
			{
				if(!used[i] && !topdfs(i, stack, used))
				{
					System.out.println("There is a cycle");
				}
			}
			while(stack.size() > 0) answer.add(stack.pop());
			return answer;
		}
		public boolean topdfs(int cur, ArrayDeque<Integer> stack, boolean[] used)
		{
			if(used[cur]) return false;
			used[cur] = true;
			for(int v : adjList.get(cur).keySet())
			{
				if(!topdfs(v, stack, used)) return false;
			}
			stack.push(cur);
			return true;
		}
		
		public ArrayList<Integer> topsortbfs()
		{
			ArrayList<Integer> answer = new ArrayList<Integer>();
			int[] inDegree = new int[adjList.size()];
			

			

			ArrayDeque<Integer> q = new ArrayDeque<Integer>();
			for(int i = 0; i < adjList.size(); i++)
			{
				for(int v : adjList.get(i).keySet())
				{
					inDegree[v]++;
				}
			}
			for(int i = 0; i < inDegree.length; i++)
				if(inDegree[i] == 0)
					q.add(i);
			while(q.size() > 0)
			{
				int temp = q.poll();
				inDegree[temp] = -1;
				answer.add(temp);
				for(int v : adjList.get(temp).keySet())
				{
					inDegree[v]--;
					if(inDegree[v] == 0)
						q.add(v);
				}
			}
			if(answer.size() != adjList.size()) System.out.println("There is a cycle");
			return answer;
		}
		public int edmondkarp(int source, int sink)
		{
			int answer = 0;
			while(true)
			{
				State temp = flowbfs(source, sink);
				if(temp == null) break;
				answer += temp.flow;
				for(int i = 1; i < temp.arr.size(); i++)
				{
					int v1 = temp.arr.get(i-1);
					int v2 = temp.arr.get(i);
					addEdgeWeight(v1, v2, -temp.flow);
					addEdgeWeight(v2, v1, temp.flow);
				}
			}
			return answer;
		}
		public State flowbfs(int source, int sink)
		{
			ArrayDeque<State> q = new ArrayDeque<State>();
			q.add(new State(source));
			boolean[] used = new boolean[adjList.size()];
			while(q.size() > 0)
			{
				State temp = q.poll();
				int cur = temp.arr.get(temp.arr.size()-1);
				if(used[cur]) continue;
				used[cur] = true;
				if(cur == sink) return temp;
				for(int v : adjList.get(cur).keySet())
				{
					if(adjList.get(cur).get(v) <= 0) continue;
					q.add(new State(temp, v, adjList.get(cur).get(v)));
				}
			}
			return null;
		}
		class State
		{
			public ArrayList<Integer> arr;
			public int flow;
			public State(int start)
			{
				arr = new ArrayList<Integer>();
				arr.add(start);
				flow = Integer.MAX_VALUE;
			}
			public State(State a, int next, int width)
			{
				arr = new ArrayList<Integer>(a.arr);
				arr.add(next);
				flow = Math.min(a.flow, width);
			}
		}
		public int INF = 1_000_000_000;
		

		public int fordfulkerson(int source, int sink)
		{
			int answer = 0;
			while(true)
			{
				int flow = flowdfs(source, sink, INF, new boolean[adjList.size()]);
				if(flow == INF || flow == 0) break;
				answer += flow;
			}
			return answer;
		}
		public int flowdfs(int source, int sink, int flow, boolean[] used)
		{
			if(used[source]) return INF;
			used[source] = true;
			if(source == sink) return flow;
			for(int v : adjList.get(source).keySet())
			{
				if(adjList.get(source).get(v) <= 0) continue;
				int value = flowdfs(v, sink, Math.min(flow, adjList.get(source).get(v)), used);
				if(value != INF)
				{
					addEdgeWeight(source, v, -value);
					addEdgeWeight(v, source, value);
					return value;
				}
			}
			return INF;
		}
		
		public int[][][] floydwarshall()
		{
			int[][][] answer = new int[adjList.size()][adjList.size()][2];
			for(int i = 0; i < answer.length; i++)
			{
				for(int j = 0; j < answer[i].length; j++)
				{
					answer[i][j][0] = INF;
					answer[i][j][1] = i;
				}
				answer[i][i][0] = 0;
			}
			for(int i = 0; i < adjList.size(); i++)
			{
				for(int v : adjList.get(i).keySet())
				{
					answer[i][v][0] = adjList.get(i).get(v);
				}
			}
			
			for(int k = 0; k < answer.length; k++)
			{
				for(int i = 0; i < answer.length; i++)
				{
					for(int j = 0; j < answer.length; j++)
					{
						if(answer[i][k][0] + answer[k][j][0] < answer[i][j][0])
						{
							answer[i][j][0] = answer[i][k][0] + answer[k][j][0];
							answer[i][j][1] = answer[k][j][1];
						}
					}
				}
			}
			

			for(int i = 0; i < answer.length; i++)
			{
				if(answer[i][i][0] < 0)
				{
					System.out.println("There is a negative cycle!");
				}
			}
			return answer;
		}
		public ArrayList<Integer> recreatePath(int[] path, int cur, int dest, ArrayList<Integer> answer) throws Exception
		{
			if(dest < 0 || dest >= path.length) throw new Exception();
			if(cur == dest)
			{
				answer.add(cur);
				return answer;
			}
			answer = recreatePath(path, cur, path[dest], answer);
			answer.add(dest);
			return answer;
		}
		
		public int bellmanford(int source, int sink)
		{
			int[] estimates = new int[adjList.size()];
			Arrays.fill(estimates, INF);
			estimates[source] = 0;
			ArrayDeque<Integer> q = new ArrayDeque<Integer>();
			q.add(source);
			boolean[] inq = new boolean[adjList.size()];
			inq[source] = true;
			int[] count = new int[adjList.size()];
			while(q.size() > 0)
			{
				int temp = q.poll();
				inq[temp] = false;
				count[temp]++;
				if(count[temp] >= adjList.size())
				{
					System.out.println("Negative cycle");
					break;
				}
				for(int v : adjList.get(temp).keySet())
				{
					if(estimates[v] > estimates[temp] + adjList.get(temp).get(v))
					{
						estimates[v] = estimates[temp] + adjList.get(temp).get(v);
						if(!inq[v])
						{
							q.add(v);
							inq[v] = true;
						}
					}
				}
			}
			return estimates[sink];
		}
		

		public int djikstra(int source, int sink)
		{
			int[] estimates = new int[adjList.size()];
			

			

			

			Arrays.fill(estimates, INF);
			estimates[source] = 0;
			

			PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
			pq.add(new Pair(source, 0));
			boolean[] used = new boolean[adjList.size()];
			while(pq.size() > 0)
			{
				Pair temp = pq.poll();
				if(used[temp.v]) continue;
				used[temp.v] = true;
				

				if(temp.v == sink) break;
				for(int v : adjList.get(temp.v).keySet())
				{
					if(used[v]) continue;
					if(estimates[v] > estimates[temp.v] + adjList.get(temp.v).get(v))
					{
						estimates[v] = estimates[temp.v] + adjList.get(temp.v).get(v);
						

						pq.add(new Pair(v, estimates[v]));
					}
				}
			}
			return estimates[sink];
		}
		
		class Pair implements Comparable<Pair>
		{
			public int v;
			public int w;
			public Pair(int a, int b)
			{
				v = a;
				w = b;
			}
			public int compareTo(Pair a)
			{
				return w - a.w;
			}
		}
	}

	
	class JoltyScanner 
	{
	    public static final int BUFFER_SIZE = 1 << 16;
		public static final char NULL_CHAR = (char) -1;

	    byte[] buffer = new byte[BUFFER_SIZE];
		boolean EOF_FLAG = false;
		int bufferIdx = 0, size = 0;
		char c = NULL_CHAR;
		BufferedInputStream in;

		public JoltyScanner(InputStream in) 
		{
			this.in = new BufferedInputStream(in, BUFFER_SIZE);
		}

		public int nextInt() 
		{
			long x = nextLong();
			if (x > Integer.MAX_VALUE || x < Integer.MIN_VALUE) 
			{
				throw new ArithmeticException("Scanned value overflows integer");
			}
			return (int) x;
		}

		public long nextLong() 
		{
			boolean negative = false;
			if (c == NULL_CHAR) 
			{
				c = nextChar();
			}
			for (; !EOF_FLAG && (c < '0' || c > '9'); c = nextChar()) 
			{
				if (c == '-') 
				{
					negative = true;
				}				
			}
			checkEOF();
			long res = 0;
			for (; c >= '0' && c <= '9'; c = nextChar()) 
			{
				res = (res << 3) + (res << 1) + c - '0';
			}
			return negative ? -res : res;
		}

	    public char nextChar() 
	    {
			if (EOF_FLAG) 
			{
				return NULL_CHAR;
			}
			while (bufferIdx == size) 
			{
				try 
				{
					size = in.read(buffer);
					if (size == -1) 
					{
						throw new Exception();
					}
				} 
				catch (Exception e) 
				{
					EOF_FLAG = true;
					return NULL_CHAR;
				}
				if (size == -1) 
				{
					size = BUFFER_SIZE;
				}
				bufferIdx = 0;
			}
			return (char) buffer[bufferIdx++];
		}

	    public void checkEOF() 
	    {
			if (EOF_FLAG) 
			{
				throw new EndOfFileException();
			}
		}

		public class EndOfFileException extends RuntimeException 
		{
		}
	}
}
