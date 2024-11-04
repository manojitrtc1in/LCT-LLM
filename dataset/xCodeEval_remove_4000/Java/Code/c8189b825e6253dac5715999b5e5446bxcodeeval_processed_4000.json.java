import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.*;

public class graph_code {

	public static class graph {
		int size;
		LinkedList<Integer>[] list;

		public graph(int size) {
			this.size = size;
			list = new LinkedList[this.size];

			for (int i = 0; i < this.size; i++) {
				list[i] = new LinkedList<Integer>();
			}

		}

		public void id5(int x, int y) {
			list[x].add(y);
		}

		public void id4(int x, int y) {
			list[x].add(y);
			list[y].add(x);
		}

		public void id6(int start) {

			Set<Integer> visited = new HashSet<Integer>();
			Stack<Integer> st = new Stack<Integer>();

			for (int i = 1; i < this.size - 1; i++) {
				if (visited.contains(i)) {
					continue;
				}
				id10(i, visited, st);
			}

			while (!st.isEmpty()) {
				System.out.print(st.pop() + " ");
			}

		}

		public void id10(int start, Set<Integer> visited,
				Stack<Integer> st) {

			visited.add(start);
			Iterator<Integer> i = list[start].listIterator();

			while (i.hasNext()) {
				int data = i.next();
				if (!visited.contains(data)) {

				} else {
					continue;
				}
				id10(data, visited, st);
			}

			st.push(start);
		}

		public int bfs(int start) {
			boolean visited[] = new boolean[this.size];
			

			int count = 0;
			for (int i = 1; i < list.length; i++) {
				

				if (!visited[i]) {
					count++;
					

					id8(i, visited);
				}

			}
			return count;
		}

		public void id8(int current, boolean[] visited) {
			Queue<Integer> q = new LinkedList<Integer>();
			visited[current] = true;
			q.add(current);

			while (!q.isEmpty()) {
				int x = q.poll();
				

				Iterator<Integer> i = list[x].listIterator();
				while (i.hasNext()) {
					int val = i.next();
					if (!visited[val]) {
						q.add(val);
						visited[val] = true;
					}
				}
			}

		}

		public void dfs(int start) {

			boolean visited[] = new boolean[this.size];
			visited[start] = true;
			dfsUtil(start, visited);
		}

		public void dfsUtil(int current, boolean[] visited) {

			System.out.println(current);

			Iterator<Integer> i = list[current].listIterator();

			while (i.hasNext()) {
				int val = i.next();
				if (!visited[val]) {
					visited[val] = true;
					dfsUtil(val, visited);
				}
			}
		}

		

		

		

		

		


	}

	public static class graphAlgo {
		int size;
		LinkedList<Node> list[];
		ArrayList<Nodes> NodeList;

		public graphAlgo(int size) {

			this.size = size;

			this.list = new LinkedList[this.size];
			this.NodeList = new ArrayList<graph_code.graphAlgo.Nodes>();
			for (int i = 0; i < this.size; i++) {
				this.list[i] = new LinkedList<graph_code.graphAlgo.Node>();
			}

		}

		public void id5(int x, int y, int weight) {
			Node n = new Node(y, weight);
			list[x].add(n);
		}

		public static class id1 {
			int[] rank, parent;
			int size;

			public id1(int size) {
				this.size = size;
				rank = new int[this.size];
				parent = new int[this.size];
				for (int i = 0; i < this.size; i++) {
					parent[i] = i;
				}
			}

			public int find(int x) {

				if (this.parent[x] != x) {
					parent[x] = find(parent[x]);
				}

				return parent[x];
			}

			public void union(int x, int y) {

				int xRepresentative = find(x);
				int yRepresentative = find(y);

				if (xRepresentative == yRepresentative) {
					return;
				}

				if (this.rank[xRepresentative] < this.rank[yRepresentative]) {
					this.parent[xRepresentative] = yRepresentative;
				} else if (this.rank[xRepresentative] > this.rank[yRepresentative]) {
					this.parent[yRepresentative] = xRepresentative;
				} else {
					parent[xRepresentative] = yRepresentative;
					rank[yRepresentative] += 1;
				}

			}
		}

		public class Nodes implements Comparable<Nodes> {
			int source;
			int destination;
			int weight;

			public Nodes(int x, int y, int z) {
				this.source = x;
				this.destination = y;
				this.weight = z;
			}

			public int compareTo(Nodes compareNode) {
				if (this.weight > compareNode.weight) {
					return 1;
				} else if (this.weight < compareNode.weight) {
					return -1;
				} else {
					return 0;
				}
			}

		}

		public static class Node {
			int x;
			int y;

			public Node(int x, int y) {
				this.x = x;
				this.y = y;
			}
		}

		public void id7() {

			for (int i = 0; i < NodeList.size(); i++) {
				Nodes val = NodeList.get(i);
				System.out.println(val.source + " " + val.destination + " "
						+ val.weight);
			}
		}

		public void id3(int source, int destination, int weight) {
			Nodes n1 = new Nodes(source, destination, weight);
			NodeList.add(n1);
		}

		public void addVertex(int x, int y, int weight) {
			Node n1 = new Node(y, weight);
			Node n2 = new Node(x, weight);
			this.list[x].add(n1);
			this.list[y].add(n2);
		}

		public void prims(int source) {
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();

			ArrayList<Integer> answer = new ArrayList<Integer>();
			for (int i = 0; i < this.size; i++) {
				map.put(i, Integer.MAX_VALUE);
			}

			id11(source, map, answer);
			System.out.println(answer);
		}

		public void id11(int source, TreeMap<Integer, Integer> map,
				ArrayList<Integer> answer) {
			map.put(source, 0);

			while (!map.isEmpty()) {
				System.out.println(map);
				int val = getMin(map);
				map.remove(val);
				answer.add(val);
				System.out.println(val);

				Iterator<Node> i = list[val].listIterator();

				while (i.hasNext()) {
					Node val1 = i.next();
					int otherVertex = val1.x;
					int weight = val1.y;

					if (map.get(otherVertex) != null
							&& map.get(otherVertex) > weight) {
						map.put(otherVertex, weight);
					}

				}
			}
		}

		public int getMin(TreeMap<Integer, Integer> map) {
			int min = Integer.MAX_VALUE;
			int keyValue = 0;
			for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
				Integer key = entry.getKey();
				Integer value = entry.getValue();

				if (value <= min) {
					min = value;
					keyValue = key;
				}
			}

			return keyValue;
		}

		public void dijkstra(int source) {

			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			ArrayList<Integer> answer = new ArrayList<Integer>();

			for (int i = 0; i < this.size; i++) {
				map.put(i, Integer.MAX_VALUE);
			}

			id9(map, source, answer);
			System.out.println(answer);
		}

		public void id9(TreeMap<Integer, Integer> map, int source,
				ArrayList<Integer> answer) {

			map.put(source, 0);

			while (!map.isEmpty()) {

				int key = getMin(map);
				int value = map.remove(key);
				answer.add(key);

				Iterator<Node> i = this.list[key].listIterator();

				while (i.hasNext()) {
					Node data = i.next();
					Integer otherVertex = data.x;
					Integer weight = data.y;

					if (map.get(otherVertex) != null
							&& map.get(otherVertex) > weight + value) {
						int totalWeight = weight + value;
						map.put(otherVertex, totalWeight);

					}
				}

			}

		}

		public static class edge {
			int source;
			int destination;
		}

		public void id0() {
			Collections.sort(this.NodeList);
			id1 d = new id1(this.size);
			int arr[] = new int[this.size];
			ArrayList<edge> answer = new ArrayList<edge>();

			for (int i = 0; i < NodeList.size(); i++) {
				Nodes val = NodeList.get(i);

				int vertex1 = val.source;
				int vertex2 = val.destination;
				int xroot = d.find(vertex1);
				int yroot = d.find(vertex2);

				if (d.find(vertex1) != d.find(vertex2)) {
					d.union(vertex1, vertex2);
					edge g = new edge();
					g.source = vertex1;
					g.destination = vertex2;
					answer.add(g);
				}

			}

			for (int i = 0; i < answer.size(); i++) {
				System.out.println(answer.get(i).source + " "
						+ answer.get(i).destination);
			}

		}

		public void id12() {

			TreeMap<Integer, Node> map = new TreeMap<Integer, Node>();
			Node n = new Node(0, -1);
			map.put(0, n);
			for (int i = 1; i < this.size; i++) {
				n = new Node(Integer.MAX_VALUE, -1);
				map.put(i, n);
			}

			for (int i = 0; i < this.size; i++) {
				for (int j = 0; j < list.length; j++) {
					for (int k = 0; k < this.list[j].size(); k++) {
						int source = j;
						int destination = this.list[j].get(k).x;
						int weight = this.list[j].get(k).y;
						System.out.println(source + " " + destination + " "
								+ weight);

						if (source == destination) {
							continue;
						}

						System.out.println(source + " " + destination + " "
								+ weight);

						if (map.get(source).x == Integer.MAX_VALUE
								&& map.get(destination).x == Integer.MAX_VALUE) {

						} else if (map.get(destination).x > weight
								+ map.get(source).x) {
							int totalWeight = weight + map.get(source).x;
							n = new Node(totalWeight, source);
							map.put(destination, n);
						}
					}
				}
			}

			for (Map.Entry<Integer, Node> entry : map.entrySet()) {
				Integer key = entry.getKey();
				Node value = entry.getValue();
				System.out.println(key + " " + value.x + " " + value.y);
			}

		}

		public void solution(int[][] arr, int size) {

			id1 set = new id1(size);

			for (int i = 0; i < arr[0].length; i++) {
				for (int j = 0; j < arr.length; j++) {

				}
			}
		}

	}

	static class pair {
		int x, y, weight;
	}

	public static void main(String[] args) {

		InputReader in = new InputReader(System.in);
		OutputWriter out = new OutputWriter(System.out);

		

		

		


		int n = in.readInt();
		int m = in.readInt();
		int k = in.readInt();

		char arr[][] = new char[n][m];

		for (int i = 0; i < n; i++) {
			arr[i] = in.readString().toCharArray();
		}

		Stack<pair> st = new Stack<pair>();
		pair pa = new pair();
		pa.x = Integer.MAX_VALUE;
		pa.y = Integer.MAX_VALUE;

		st.push(pa);

		boolean visited[][] = new boolean[n][m];
		boolean check = false;

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				if (arr[i][j] == '.') {
					pair p = new pair();
					p.x = i;
					p.y = j;
					visited[i][j] = true;
					st.add(p);
					check = true;
					break;

				}
			}
			if (check) {
				break;
			}
		}
		int x = st.peek().x;
		int y = st.peek().y;
		boolean checks = false;
		ArrayList<pair> ans = new ArrayList<graph_code.pair>();
		while (!st.isEmpty()) {

			if (x != Integer.MAX_VALUE && (x + 1) < arr.length && arr[x + 1][y] == '.'
					&& !visited[x + 1][y]) {
				visited[x + 1][y] = true;
				pair p = new pair();
				p.x = x + 1;
				p.y = y;
				x = x+1;
				st.add(p);
			} else if (x!= Integer.MAX_VALUE && (x - 1) >= 0 && arr[x - 1][y] == '.'
					&& !visited[x - 1][y]) {
				visited[x - 1][y] = true;
				pair p = new pair();
				p.x = x - 1;
				p.y = y;
				x = x-1;
				st.add(p);
			} else if (y != Integer.MAX_VALUE && (y + 1) < arr[0].length && arr[x][y + 1] == '.'
					&& !visited[x][y + 1]) {
				visited[x][y + 1] = true;
				pair p = new pair();
				p.x = x;
				p.y = y + 1;
				y=y+1;
				st.add(p);
			} else if (y!= Integer.MAX_VALUE &&( y - 1 )>= 0 && arr[x][y - 1] == '.' && !visited[x][y - 1]) {
				visited[x][y - 1] = true;
				pair p = new pair();
				p.x = x;
				p.y = y - 1;
				y =y-1;
				st.add(p);
			} else {
				pair p = st.peek();
				x = p.x;
				y = p.y;
				
				if (checks) {
					pair paa = st.pop();
					x = paa.x;
					y = paa.y;
					ans.add(paa);
					checks = false;
				} else {
					checks = true;
				}
				






			}		
		}

		

		

		

		


		

		for (int i = 0; i < k; i++) {
			pair p = ans.get(i);
			arr[p.x][p.y] = 'X';
		}

		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}

		out.close();
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public long readLong() {
			int c = read();
			while (id2(c))
				c = read();
			long sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id2(c));
			return res * sgn;
		}

		public int readInt() {
			int c = read();
			while (id2(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!id2(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (id2(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!id2(c));
			return res.toString();
		}

		static boolean id2(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return readString();
		}
	}

	private static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(outputStream);
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}
	}
}