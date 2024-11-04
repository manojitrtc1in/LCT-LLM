
import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.LinkedList;

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.Charset;

public class Centroids
{
	public static void main(String[] args) throws IOException
	{
		BufferedInputStream in = new BufferedInputStream(System.in);
		

                               

                               

                               

                               

                               

                               

                               

                               

                               

                               

                               

                               

                               

		

		int n = nextInt(in);
		

		

		int[] from = new int[2*(n - 1)];
		int[] to = new int[2*(n - 1)];
		int[] degree = new int[n + 1];
		for (int i = 0; i < n - 1; i++)
		{
			int u = nextInt(in);
			int v = nextInt(in);
			

			

			

			from[2*i] = u;
			to[2*i] = v;
			from[2*i + 1] = v;
			to[2*i + 1] = u;
			degree[u]++;
			degree[v]++;
		}
		

		

		

		int[][] tree = new int[n + 1][];
		for (int i = 0; i < 2*(n - 1); i++)
		{
			int u = from[i], v = to[i];
			int[] adj = tree[u];
			if (adj == null)
			{
				adj = new int[degree[u]];
				tree[u] = adj;
			}
			adj[adj.length - degree[u]] = v;
			degree[u]--;
		}
		

		

		

			

			

			

			

				

				

			

		

		

		from = null;
		to = null;
		degree = null;
		

		

		

		

		

		

		

		

		

		

		

		

			

			

				

				

				

					

		

					

				

			

			

		

		

		

		boolean[] non = id2(tree);
		StringBuilder sb = new StringBuilder();
		for (int u = 1; u <= n; u++)
		{
			if (non[u])
			{
				sb.append("0 ");
			}
			else
			{
				sb.append("1 ");
			}
		}
		System.out.println(sb);
	}
	
	public static int nextInt(BufferedInputStream in) throws IOException
	{
		int next = 0;
		boolean haveNext = false;
		int b;
		while ((b = in.read()) != -1)
		{
			if ('0' <= b && b <= '9')
			{
				next = 10*next + (b - '0');
				haveNext = true;
			}
			else if (haveNext)
			{
				break;
			}
		}
		return next;
	}
	
	public static boolean[] id2(int[][] tree)
	{
		int[] weightUp = new int[tree.length + 1];
		int[] weightDown = new int[tree.length + 1];
		int[] id0 = new int[tree.length + 1];
		int[] id6 = new int[tree.length + 1];
		int[] id4 = new int[tree.length + 1];
		int[] id1 = new int[tree.length + 1];
		boolean[] visited = new boolean[tree.length + 1];
		int[] parent = new int[tree.length + 1];
		parent[1] = 0;
		boolean[] non = new boolean[tree.length + 1];
		int[] stack = new int[tree.length + 1];
		int sp = 0;
		

		stack[sp] = 1;
		sp++;
		while (sp != 0)
		{
			int u = stack[sp - 1];
			

			if (!visited[u])
			{
				visited[u] = true;
				

				for (int v : tree[u])
				{
					if (v != parent[u])
					{
						parent[v] = u;
						stack[sp] = v;
						sp++;
					}
				}
			}
			else
			{
				sp--;
				stack[sp] = 0;
				

				int count = 1;
				int best = 0;
				for (int v : tree[u])
				{
					if (v != parent[u])
					{
						count += weightDown[v];
						int b = id6[v];
						

						if (b >= id4[u])
						{
							best = (b > best) ? b : best;
							id1[u] = id4[u];
							id4[u] = b;
						}
						else if (b > id1[u])
						{
							id1[u] = b;
						}
					}
				}
				weightDown[u] = count;
				weightUp[u] = tree.length - 1 - count;
				best = (count <= (tree.length - 1)/2) ? count : best;
				id6[u] = best;
				if (count - best > (tree.length - 1)/2)
				{
					non[parent[u]] = true;
				}
			}
		}
		

		

		stack[sp] = 1;
		sp++;
		while (sp != 0)
		{
			sp--;
			int u = stack[sp];
			stack[sp] = 0;
			

			int x = weightUp[u];
			if (x <= (tree.length - 1)/2)
			{
				id0[u] = x;
			}
			else
			{
				

				

				int p = parent[u];
				int best = id0[p];
				if (id4[p] == id6[u])
				{
					best = (best > id1[p]) ? best : id1[p];
				}
				else
				{
					best = (best > id4[p]) ? best : id4[p];
				}
				id0[u] = best;
				if (weightUp[u] - best > (tree.length - 1)/2)
				{
					non[u] = true;
				}
			}
			

			for (int v : tree[u])
			{
				if (v != parent[u])
				{
					stack[sp] = v;
					sp++;
				}
			}
		}
		return non;
	}
	
	public static Map<Pair, Integer> id3(int[][] tree)
	{
		Map<Pair, Integer> weight = new HashMap<>();
		

		Map<Pair, Integer> diff = new HashMap<>();
		Deque<Pair> stack = new ArrayDeque<>();
		

		

		

		int root = 1;
		for (int u : tree[root])
		{
			Pair p = new Pair(root, u);
			stack.addFirst(p);
			

			

		}
		while (!stack.isEmpty())
		

		{
			Pair p = stack.peekFirst();
			

			

			if (!weight.containsKey(p))
			{
				

				weight.put(p, 0);
				

				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						stack.addFirst(new Pair(u, v));
						

						

					}
				}
			}
			else
			{
				stack.removeFirst();
				

				

				

				int count = 1;
				int best = 0;
				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						Pair q = new Pair(u, v);
						int x = weight.get(q);
						count += x;
						

						int w = x - diff.get(q);
						

						best = (w > best) ? w : best;
					}
				}
				weight.put(p, count);
				weight.put(p.reverse(), tree.length - 1 - count);
				best = (count <= (tree.length - 1)/2) ? count : best;
				

				diff.put(p, count - best);
			}
		}
		

		

		for (int u : tree[root])
		{
			Pair p = new Pair(u, root);
			

			stack.addFirst(p);
			

			

		}
		

		

		while (!stack.isEmpty())
		{
			

			Pair p = stack.removeFirst();
			

			

			

			int x = weight.get(p);
			if (x <= (tree.length - 1)/2)
			{
				

				diff.put(p, 0);
			}
			else
			{
				int best = 0;
				

				

				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						

						Pair q = new Pair(u, v);
						int w = weight.get(q) - diff.get(q);
						

						best = (w > best) ? w : best;
					}
				}
				

				diff.put(p, x - best);
			}
			

			for (int u : tree[p.u])
			{
				if (u != p.v)
				{
					Pair q = new Pair(u, p.u);
					

					stack.addFirst(q);
					

					

				}
			}
		}
		return diff;
	}
	
	
	public static Map<Pair, Integer> countVertices(int[][] tree)
	{
		Map<Pair, Integer> weight = new HashMap<Pair, Integer>();
		Deque<Pair> stack = new ArrayDeque<>();
		

		int root = 1;
		for (int u : tree[root])
		{
			Pair p = new Pair(root, u);
			stack.addFirst(p);
		}
		while (!stack.isEmpty())
		{
			Pair p = stack.peekFirst();
			

			if (!weight.containsKey(p))
			{
				

				weight.put(p, 0);
				

				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						stack.addFirst(new Pair(u, v));
					}
				}
			}
			else
			{
				stack.removeFirst();
				

				int count = 1;
				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						count += weight.get(new Pair(u, v));
					}
				}
				weight.put(p, count);
				weight.put(p.reverse(), tree.length - 1 - count);
			}
		}
		return weight;
	}
	
	public static Map<Pair, Integer> id5(int[][] tree,
			Map<Pair, Integer> weight)
	{
		Map<Pair, Integer> bestSplit = new HashMap<>();
		Deque<Pair> stack = new ArrayDeque<>();
		

		int root = 1;
		for (int u : tree[root])
		{
			Pair p = new Pair(root, u);
			stack.addFirst(p);
		}
		

		while (!stack.isEmpty())
		{
			Pair p = stack.peekFirst();
			

			if (!bestSplit.containsKey(p))
			{
				

				bestSplit.put(p, weight.get(p));
				

				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						stack.addFirst(new Pair(u, v));
					}
				}
			}
			else
			{
				stack.removeFirst();
				

				if (weight.get(p) > (tree.length - 1)/2)
				{
					int best = 0;
					

					int u = p.v, prev = p.u;
					for (int v : tree[u])
					{
						if (v != prev)
						{
							int w = bestSplit.get(new Pair(u, v));
							

							if (w > best)
							{
								best = w;
							}
						}
					}
					bestSplit.put(p, best);
				}
			}
		}
		

		Queue<Pair> queue = new ArrayDeque<>();
		for (int u : tree[root])
		{
			Pair p = new Pair(u, root);
			queue.add(p);
		}
		while (!queue.isEmpty())
		{
			Pair p = queue.remove();
			if (weight.get(p) <= (tree.length - 1)/2)
			{
				bestSplit.put(p, weight.get(p));
			}
			else
			{
				int best = 0;
				

				

				int u = p.v, prev = p.u;
				for (int v : tree[u])
				{
					if (v != prev)
					{
						int w = bestSplit.get(new Pair(u, v));
						

						if (w >= best)
						{
							best = w;
						}
					}
				}
				bestSplit.put(p, best);
			}
			

			for (int u : tree[p.u])
			{
				if (u != p.v)
				{
					Pair q = new Pair(u, p.u);
					queue.add(q);
				}
			}
		}
		return bestSplit;
	}
	
	

			

	

		

		

		

		

		

			

			

				

				

				

					

					

						

					

					

					

						

						

					

				

			

			

		

		

	

}

class Pair
{
	public final int u;
	public final int v;
	
	public Pair(int u, int v)
	{
		this.u = u;
		this.v = v;
	}
	
	public Pair reverse()
	{
		return new Pair(v, u);
	}
	
	public boolean equals(Object o)
	{
		if (o instanceof Pair)
		{
			Pair p = (Pair)o;
			return u == p.u && v == p.v;
		}
		return false;
	}
	
	public int hashCode()
	{
		return 47*u + v;
	}
	
	public String toString()
	{
		return "(" + u + ", " + v + ")";
	}
	
	public static class LexComparator implements Comparator<Pair>
	{
		public int compare(Pair p1, Pair p2)
		{
			return (p1.u != p2.u) ? p1.u - p2.u : p1.v - p2.v;
		}
	}
}
