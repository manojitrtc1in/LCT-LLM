


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class LunarNewYearAndAWander {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		AdjListGraph<Integer> graph = new AdjListGraph<Integer>(false, false);
		


		int vertices = Integer.valueOf(st.nextToken());
		int edges = Integer.valueOf(st.nextToken());

		for (int i = 1; i <= vertices; i++) {

			graph.addVertex(i);

		}

		for (int i = 0; i < edges; i++) {

			st = new StringTokenizer(br.readLine());

			int from = Integer.valueOf(st.nextToken());
			int to = Integer.valueOf(st.nextToken());

			graph.addEdge(from, to);

		}

		
		Comparator<AdjVertex<Integer>> c = new Comparator<AdjVertex<Integer>>() {

			@Override
			public int compare(AdjVertex<Integer> o1, AdjVertex<Integer> o2) {

				if (o1.getValue() > o2.getValue()) {

					return 1;

				}else if (o1.getValue() < o2.getValue()) {

					return -1;

				}else {
					return 0;
				}

			}

		};

		List<AdjVertex<Integer>> list = graph.dfs2(1, c);

		for (int i = 0; i < list.size(); i++) {

			System.out.print(list.get(i).getValue() + " ");

		}
		

	}

	public static class AdjMatrixGraph<T> implements IGraph<T> {

		private boolean directed;
		private boolean weighted;
		private int numberOfVertices;
		private int numberOfEdges;

		private List<Vertex<T>> vertices;
		private List<ArrayList<Integer>> adjMatrix;
		private List<ArrayList<Double>> weightsMatrix;
		private HashMap<T, AdjVertex<T>> map;

		public AdjMatrixGraph(boolean directed, boolean weighted) {
			this.directed = directed;
			this.weighted = weighted;
			numberOfVertices = 0;
			numberOfEdges = getNumberOfEdges();
			vertices = new LinkedList<Vertex<T>>();
			adjMatrix = new ArrayList<ArrayList<Integer>>();
			weightsMatrix = new ArrayList<ArrayList<Double>>();
			map = new HashMap<>();
		}

		public List<Vertex<T>> getVertices() {
			return vertices;
		}

		public int getNumberOfVertices() {
			return numberOfVertices;
		}

		public int getNumberOfEdges() {
			return numberOfEdges;
		}

		public boolean isDirected() {
			return directed;
		}

		public boolean isWeighted() {
			return weighted;
		}

		@Override
		public void addVertex(T value) {
			if (!isInGraph(value)) {
				AdjVertex<T> vertex = new AdjVertex<T>(value);
				map.put(value, vertex);
				vertices.add(vertex);

				ArrayList<Integer> adj = new ArrayList<>();
				ArrayList<Double> we = new ArrayList<>();
				for (int i = 0; i < adjMatrix.size(); i++) {
					adjMatrix.get(i).add(0);
					weightsMatrix.get(i).add((double) INF);
				}
				for (int i = 0; i < vertices.size(); i++) {
					adj.add(0);
					we.add((double) INF);
				}
				we.set(we.size() - 1, 0.0);
				adjMatrix.add(adj);
				weightsMatrix.add(we);

				numberOfVertices++;
			}
		}

		@Override
		public void addEdge(T x, T y) {
			Vertex<T> from = searchVertex(x);
			Vertex<T> to = searchVertex(y);
			addEdge(from, to);
		}

		private void addEdge(Vertex<T> from, Vertex<T> to) {
			addEdge(from, to, 1D);
		}

		@Override
		public void addEdge(T x, T y, double w) {
			if (weighted) {
				Vertex<T> from = searchVertex(x);
				Vertex<T> to = searchVertex(y);
				addEdge(from, to, w);
			}
		}

		private void addEdge(Vertex<T> from, Vertex<T> to, double w) {
			if (from != null && to != null) {

				adjMatrix.get(getIndexOf(from)).set(getIndexOf(to), 1);
				weightsMatrix.get(getIndexOf(from)).set(getIndexOf(to), w);
				if (!isDirected()) {
					adjMatrix.get(getIndexOf(to)).set(getIndexOf(from), 1);
					weightsMatrix.get(getIndexOf(to)).set(getIndexOf(from), w);
				}
				numberOfEdges++;
			}

		}

		public void removeVertex(Vertex<T> v) {
			int index = getIndexOf(v);
			for (int i = 0; i < adjMatrix.size(); i++) {
				adjMatrix.get(i).remove(index);
				weightsMatrix.get(i).remove(index);
			}
			adjMatrix.remove(index);
			weightsMatrix.remove(index);

			vertices.remove(v);
			map.remove(v.getValue());
			numberOfVertices--;
		}

		public void removeVertex(T v) {
			if (isInGraph(v)) {
				removeVertex(searchVertex(v));
			}
		}

		public void removeEdge(Vertex<T> from, Vertex<T> to) {
			adjMatrix.get(getIndexOf(from)).set(getIndexOf(to), 0);
			weightsMatrix.get(getIndexOf(from)).set(getIndexOf(to), (double) INF);
			if (!isDirected()) {
				adjMatrix.get(getIndexOf(to)).set(getIndexOf(from), 0);
				weightsMatrix.get(getIndexOf(to)).set(getIndexOf(from), (double) INF);
			}
			numberOfEdges--;
		}

		public void removeEdge(T x, T y) {
			if (isInGraph(x) && isInGraph(y)) {
				removeEdge(searchVertex(x), searchVertex(y));
			}
		}

		public List<Vertex<T>> getNeighbors(Vertex<T> x) {
			List<Vertex<T>> neigh = new ArrayList<>();
			int index = getIndexOf(x);
			for (int i = 0; i < adjMatrix.get(index).size(); i++) {
				if (adjMatrix.get(index).get(i) == 1.0) {
					neigh.add(vertices.get(i));
				}
			}
			return neigh;
		}

		public boolean areAdjacent(Vertex<T> x, Vertex<T> y) {
			return getNeighbors(x).contains(y);
		}

		public boolean isInGraph(T value) {
			return searchVertex(value) != null;
		}

		public double getEdgeWeight(Vertex<T> x, Vertex<T> y) {
			double w = 0;
			int indX = getIndexOf(x);
			int indY = getIndexOf(y);
			if (isInGraph(x.getValue()) && isInGraph(y.getValue())) {
				w = weightsMatrix.get(indX).get(indY);
			}
			return w;
		}

		public void setEdgeWeight(Vertex<T> x, Vertex<T> y, double w) {
			int indX = getIndexOf(x);
			int indY = getIndexOf(y);
			if (isInGraph(x.getValue()) && isInGraph(y.getValue()) && weighted) {
				weightsMatrix.get(indX).set(indY, w);

				if (!isDirected()) {
					weightsMatrix.get(indY).set(indX, w);
				}
			}
		}

		public AdjVertex<T> searchVertex(T value) {
			return map.get(value);
		}

		public int getIndexOf(Vertex<T> v) {
			int index = -1;
			boolean searching = true;
			for (int i = 0; i < vertices.size() && searching; i++) {
				if (vertices.get(i) == v) {
					index = i;
					searching = false;
				}
			}
			return index;
		}

		public void bfs(Vertex<T> s) {
			for (Vertex<T> u : vertices) {
				u.setColor(Vertex.WHITE);
				u.setD(INF);
				u.setPred(null);
			}
			s.setColor(Vertex.GRAY);
			s.setD(0);
			s.setPred(null);
			Queue<Vertex<T>> q = new LinkedList<>();
			q.offer(s);
			while (!q.isEmpty()) {
				Vertex<T> u = q.poll();
				List<Vertex<T>> neigh = getNeighbors(u);
				for (int i = 0; i < neigh.size(); i++) {
					Vertex<T> v = neigh.get(i);
					if (v.getColor() == Vertex.WHITE) {
						v.setColor(Vertex.GRAY);
						v.setD(u.getD() + 1);
						v.setPred(u);
						q.offer(v);
					}
				}
				u.setColor(Vertex.BLACK);
			}
		}

		public List<AdjVertex<T>> dfs2 (T v, Comparator<AdjVertex<T>> c){ 


			PriorityQueue<AdjVertex<T>> ds = new PriorityQueue<AdjVertex<T>>(c);

			return traversal(v, ds);
		}

		private List<AdjVertex<T>> traversal(T v, PriorityQueue<AdjVertex<T>> ds){

			List<AdjVertex<T>> trav = new ArrayList<>();
			
			AdjVertex<T> vertex = searchVertex(v);
			ds.add(vertex);

			while(!ds.isEmpty()) {

				vertex = ds.poll();

				if(vertex.getColor() == 0) {
					trav.add(vertex);
					vertex.setColor(1);
					
					List<Vertex<T>> list = getNeighbors(vertex);
					List<AdjVertex<T>> list2 = new ArrayList<AdjVertex<T>>();
					
					for (Vertex<T> x : list) {
						list2.add((AdjVertex<T>)x);
					}
					
					ds.addAll(list2);
				}
			}
			return trav;

		}

		public void dfs() {
			for (Vertex<T> u : vertices) {
				u.setColor(Vertex.WHITE);
				u.setPred(null);
			}
			int time = 0;
			for (Vertex<T> u : vertices) {
				if (u.getColor() == Vertex.WHITE) {
					time = dfsVisit(u, time);
				}
			}
		}

		private int dfsVisit(Vertex<T> u, int time) {
			time++;
			u.setD(time);
			u.setColor(Vertex.GRAY);
			List<Vertex<T>> neigh = getNeighbors(u);
			for (int i = 0; i < neigh.size(); i++) {
				Vertex<T> v = neigh.get(i);
				if (v.getColor() == Vertex.WHITE) {
					v.setPred(u);
					time = dfsVisit(v, time);
				}
			}
			u.setColor(Vertex.BLACK);
			time++;
			u.setF(time);
			return time;
		}



		private void initSingleSource(Vertex<T> s) {
			for (Vertex<T> u : vertices) {
				u.setD(INF);
				u.setPred(null);
			}
			s.setD(0);
		}
		
		public double[] dijkstra(Vertex<T> s) {
			
			double[] array = new double[numberOfVertices];
			
			
			initSingleSource(s);
			
			PriorityQueue<Vertex<T>> queue = new PriorityQueue<>();
			queue.add(s);
			
			while (!queue.isEmpty()) {
				Vertex<T> u = queue.poll();
				List<Vertex<T>> neigh = getNeighbors(u);
				for (Vertex<T> v : neigh) {
					
					double weight = getEdgeWeight(u, v);

					

					double distanceFromU = u.getD() + weight;
					if (distanceFromU < v.getD()) {
						queue.remove(v);
						v.setD(distanceFromU);
						v.setPred(u);
						queue.add(v);

					}
				}
			}
			
			for (int i = 0; i < array.length; i++) {
				array[i] = vertices.get(i).getD();
			}
			
			return array;
		}

		public double[][] floydwarshall() {
			double[][] weights = getWeightsMatrix();
			for (int k = 0; k < vertices.size(); k++) {
				for (int i = 0; i < vertices.size(); i++) {
					for (int j = 0; j < vertices.size(); j++) {
						weights[i][j] = Math.min(weights[i][j], weights[i][k] + weights[k][j]);
					}
				}
			}
			return weights;
		}

		private double[][] getWeightsMatrix() {
			double[][] weights = new double[vertices.size()][vertices.size()];
			for (int i = 0; i < weights.length; i++) {
				for (int j = 0; j < weights.length; j++) {
					weights[i][j] = weightsMatrix.get(i).get(j);
				}
			}
			return weights;
		}

		public void prim(Vertex<T> r) {
			for (Vertex<T> u : vertices) {
				u.setD(INF);
				u.setColor(Vertex.WHITE);
			}
			r.setD(0);
			r.setPred(null);
			PriorityQueue<Vertex<T>> queue = new PriorityQueue<>();
			for (Vertex<T> u : vertices) {
				queue.add((AdjVertex<T>) u);
			}
			while (!queue.isEmpty()) {
				Vertex<T> u = queue.poll();
				List<Vertex<T>> neigh = getNeighbors(u);
				for (Vertex<T> v : neigh) {
					if (v.getColor() == Vertex.WHITE && getEdgeWeight(u, v) < v.getD()) {
						queue.remove(v);
						v.setD(getEdgeWeight(u, v));
						queue.add(v);
						v.setPred(u);
					}
				}
				u.setColor(Vertex.BLACK);
			}
		}

		public ArrayList<Edge<T>> kruskal() { 

			

			ArrayList<Edge<T>> result = new ArrayList<>(); 

			int e = 0; 

			int i = 0; 


			ArrayList<Edge<T>> edges = getEdges();

			

			

			

			Collections.sort(edges);

			UnionFind uf = new UnionFind(vertices.size());

			i = 0; 


			

			while (e < vertices.size() - 1 && i < edges.size()) {
				

				

				Edge<T> edge = edges.get(i);
				i++;

				int x = uf.find(getIndexOf(edge.getSource()));
				int y = uf.find(getIndexOf(edge.getDestination()));

				

				

				

				if (x != y) {
					result.add(edge);
					e++;
					uf.union(x, y);
				}
				

			}
			return result;
		}

		public ArrayList<Edge<T>> getEdges() {
			ArrayList<Edge<T>> edges = new ArrayList<>();
			for (int i = 0; i < adjMatrix.size(); i++) {
				for (int j = 0; j < adjMatrix.get(i).size(); j++) {
					if(adjMatrix.get(i).get(j) == 1) {
						edges.add(new Edge<>(vertices.get(i), vertices.get(j), weightsMatrix.get(i).get(j)));
					}
				}
			}
			return edges;
		}

	}

	public static class Vertex<T> implements Comparable<Vertex<T>>{

		public static final int WHITE = 0;
		public static final int GRAY = 1;
		public static final int BLACK = 2;

		private T value;
		

		private double d;
		

		private int f;

		private int index;

		private int color;

		private Vertex<T> pred;

		public Vertex(T value) {
			this.value=value;
			pred=null;
			color=WHITE;
		}

		public T getValue() {
			return value;
		}

		public void setValue(T value) {
			this.value = value;
		}

		public double getD() {
			return d;
		}

		public void setD(double d) {
			this.d = d;
		}

		public int getF() {
			return f;
		}

		public void setF(int f) {
			this.f = f;
		}

		public int getColor() {
			return color;
		}

		public void setColor(int color) {
			this.color = color;
		}

		public Vertex<T> getPred() {
			return pred;
		}

		public void setPred(Vertex<T> pred) {
			this.pred = pred;
		}

		public int getIndex() {
			return this.index;
		}

		public void setIndex(int index) {
			this.index=index;
		}

		@Override
		public int compareTo(Vertex<T> vertex) {
			return Double.compare(d, vertex.d);
		}

	}

	public static class UnionFind {

		private int[] parent;
		private int[] rank;


		public int find(int i) {

			int p = parent[i];
			if (i == p) {
				return i;
			}
			return parent[i] = find(p);

		}


		public void union(int i, int j) {

			int root1 = find(i);
			int root2 = find(j);

			if (root2 == root1) return;

			if (rank[root1] > rank[root2]) {
				parent[root2] = root1;
			} else if (rank[root2] > rank[root1]) {
				parent[root1] = root2;
			} else {
				parent[root2] = root1;
				rank[root1]++;
			}
		}


		public UnionFind(int max) {

			parent = new int[max];
			rank = new int[max];

			for (int i = 0; i < max; i++) {
				parent[i] = i;
			}
		}


		public String toString() {
			return "<UnionFind\np " + Arrays.toString(parent) + "\nr " + Arrays.toString(rank) + "\n>";
		}
	}

	public static interface IGraph<T> {

		public static final int INF = 12345678;

		public List<Vertex<T>> getVertices();

		public boolean isDirected();

		public boolean isWeighted();

		public void addVertex(T value);

		public void addEdge(T x, T y);

		public void addEdge(T x, T y, double w);

		public void removeVertex(T v);

		public void removeEdge(T x, T y);

		public List<Vertex<T>> getNeighbors(Vertex<T> x);

		public int getNumberOfVertices();

		public int getNumberOfEdges();

		public boolean areAdjacent(Vertex<T> x, Vertex<T> y);

		public boolean isInGraph(T value);

		public double getEdgeWeight(Vertex<T> x, Vertex<T> y);

		public void setEdgeWeight(Vertex<T> x, Vertex<T> y, double w);

		public void bfs(Vertex<T> s);

		public void dfs();

	}

	public static class Edge<T> implements Comparable<Edge<T>>{

		private double weight;

		private Vertex<T> source;
		private Vertex<T> destination;

		public Edge(Vertex<T> source, Vertex<T> destination) {
			this(source, destination, 1D);
		}

		public Edge(Vertex<T> source, Vertex<T> destination, double weight) {
			this.source = source;
			this.destination = destination;
			this.weight = weight;
		}

		public double getWeight() {
			return weight;
		}

		public void setWeight(double weight) {
			this.weight = weight;
		}

		public Vertex<T> getSource() {
			return source;
		}

		public Vertex<T> getDestination() {
			return destination;
		}

		@Override
		public int compareTo(Edge<T> o) {
			return Double.compare(weight, o.weight);
		}

	}

	public static class AdjVertex<T> extends Vertex<T> {

		private List<Edge <T>> adjList;

		public AdjVertex(T value) {
			super(value);
			adjList= new LinkedList<Edge<T>>();
		}

		public List<Edge<T>> getAdjList(){
			return adjList;
		}

		public boolean isAdjacent(AdjVertex<T> vertex) {
			for(int i = 0; i<adjList.size(); i++) {
				if (adjList.get(i).getDestination()==vertex)
					return true;
			}
			return false;
		}

		public Edge<T> findEdge(AdjVertex<T> vertex){
			for (int i=0; i<adjList.size(); i++) {
				if (adjList.get(i).getDestination()==vertex)
					return adjList.get(i);
			}
			return null;
		}

	}

	public static class AdjListGraph<T> implements IGraph<T> {

		private boolean directed;
		private boolean weighted;
		private int numberOfVertices;
		private int numberOfEdges;

		private List<Vertex<T>> vertices;
		private HashMap<T, AdjVertex<T>> map;

		public AdjListGraph(boolean directed, boolean weighted) {
			this.directed = directed;
			this.weighted = weighted;
			numberOfVertices = 0;
			numberOfEdges = getNumberOfEdges();
			vertices = new LinkedList<Vertex<T>>();
			map = new HashMap<>();
		}

		public List<Vertex<T>> getVertices() {
			return vertices;
		}

		public int getNumberOfVertices() {
			return numberOfVertices;
		}

		public int getNumberOfEdges() {
			return numberOfEdges;
		}

		public boolean isDirected() {
			return directed;
		}

		public boolean isWeighted() {
			return weighted;
		}

		@Override
		public void addVertex(T value) {
			if (!isInGraph(value)) {
				AdjVertex<T> vertex = new AdjVertex<T>(value);
				map.put(value, vertex);
				vertex.setIndex(numberOfVertices);
				vertices.add(vertex);
				numberOfVertices++;
			}
		}

		@Override
		public void addEdge(T x, T y) {
			AdjVertex<T> from = searchVertex(x);
			AdjVertex<T> to = searchVertex(y);
			addEdge(from, to);
		}

		public void addEdge(AdjVertex<T> from, AdjVertex<T> to) {
			addEdge(from, to, 1D);
		}

		@Override
		public void addEdge(T x, T y, double w) {
			if (weighted) {
				AdjVertex<T> from = searchVertex(x);
				AdjVertex<T> to = searchVertex(y);
				addEdge(from, to, w);
			}
		}

		public void addEdge(AdjVertex<T> from, AdjVertex<T> to, double w) {
			if (from != null && to != null) {
				Edge<T> edge = new Edge<T>(from, to, w);
				from.getAdjList().add(edge);
				if (!isDirected()) {
					edge = new Edge<T>(to, from, w);
					to.getAdjList().add(edge);
				}
				numberOfEdges++;
			}

		}

		public void removeVertex(Vertex<T> v) {
			for (int i = 0; i < vertices.size(); i++) {
				removeEdge(vertices.get(i), v);
				if (isDirected()) {
					removeEdge(v, vertices.get(i));
				}
			}
			vertices.remove(v);
			map.remove(v.getValue());
			numberOfVertices--;
		}

		public void removeVertex(T v) {
			if (isInGraph(v)) {
				removeVertex(searchVertex(v));
			}
		}

		public void removeEdge(Vertex<T> x, Vertex<T> y) {
			AdjVertex<T> from = (AdjVertex<T>) x;
			AdjVertex<T> to = (AdjVertex<T>) y;
			List<Edge<T>> adjFrom = from.getAdjList();
			Edge<T> e = from.findEdge(to);
			if (e != null)
				adjFrom.remove(e);

			if (!isDirected()) {
				List<Edge<T>> adjTo = to.getAdjList();
				e = to.findEdge(from);
				if (e != null)
					adjTo.remove(e);
			}

			numberOfEdges--;
		}

		public void removeEdge(T x, T y) {
			if (isInGraph(x) && isInGraph(y)) {
				removeEdge(searchVertex(x), searchVertex(y));
			}
		}

		public List<Vertex<T>> getNeighbors(Vertex<T> x) {
			List<Vertex<T>> neigh = new ArrayList<>();
			AdjVertex<T> from = new AdjVertex<T>(x.getValue());
			

			List<Edge<T>> adj = from.getAdjList();
			for (int i = 0; i < adj.size(); i++) {
				neigh.add(adj.get(i).getDestination());
			}
			return neigh;
		}

		public boolean areAdjacent(Vertex<T> x, Vertex<T> y) {
			return getNeighbors(x).contains(y);
		}

		public boolean isInGraph(T value) {
			return searchVertex(value) != null;
		}

		public double getEdgeWeight(Vertex<T> x, Vertex<T> y) {
			double w = 0;
			if (isInGraph(x.getValue()) && isInGraph(y.getValue())) {
				AdjVertex<T> from = (AdjVertex<T>) x;
				AdjVertex<T> to = (AdjVertex<T>) y;
				Edge<T> e = from.findEdge(to);
				if (e != null)
					w = e.getWeight();
			}
			return w;
		}

		public void setEdgeWeight(Vertex<T> x, Vertex<T> y, double w) {
			if (isInGraph(x.getValue()) && isInGraph(y.getValue()) && weighted) {
				AdjVertex<T> from = (AdjVertex<T>) x;
				AdjVertex<T> to = (AdjVertex<T>) y;
				Edge<T> e = from.findEdge(to);
				if (e != null)
					e.setWeight(w);

				if (!isDirected()) {
					e = to.findEdge(from);
					if (e != null)
						e.setWeight(w);
				}
			}
		}

		public AdjVertex<T> searchVertex(T value) {
			return map.get(value);
		}

		public int getIndexOf(Vertex<T> v) {
			int index = -1;
			boolean searching = true;
			for (int i = 0; i < vertices.size() && searching; i++) {
				if (vertices.get(i) == v) {
					index = i;
					searching = false;
				}
			}
			return index;
		}

		public void bfs(Vertex<T> x) {
			AdjVertex<T> s = (AdjVertex<T>) x;
			for (Vertex<T> u : vertices) {
				u.setColor(Vertex.WHITE);
				u.setD(INF);
				u.setPred(null);
			}
			s.setColor(Vertex.GRAY);
			s.setD(0);
			s.setPred(null);
			Queue<AdjVertex<T>> q = new LinkedList<>();
			q.offer(s);
			while (!q.isEmpty()) {
				AdjVertex<T> u = q.poll();
				for (int i = 0; i < u.getAdjList().size(); i++) {
					AdjVertex<T> v = (AdjVertex<T>) u.getAdjList().get(i).getDestination();
					if (v.getColor() == Vertex.WHITE) {
						v.setColor(Vertex.GRAY);
						v.setD(u.getD() + 1);
						v.setPred(u);
						q.offer(v);
					}
				}
				u.setColor(Vertex.BLACK);
			}
		}

		public List<AdjVertex<T>> dfs2 (T v, Comparator<AdjVertex<T>> c){

			PriorityQueue<AdjVertex<T>> ds = new PriorityQueue<LunarNewYearAndAWander.AdjVertex<T>>(c);

			return traversal(v, ds);
		}

		private List<AdjVertex<T>> traversal(T v, PriorityQueue<AdjVertex<T>> ds){

			List<AdjVertex<T>> trav = new ArrayList<>();


			AdjVertex<T> vertex = searchVertex(v);
			ds.add(vertex);

			while(!ds.isEmpty()) {

				vertex = ds.poll();

				if(vertex.getColor() == 0) {
					trav.add(vertex);
					

					vertex.setColor(1);

					List<AdjVertex<T>> adjacents = new ArrayList<AdjVertex<T>>();

					for (Edge<T> edge : vertex.getAdjList()) {
						adjacents.add((AdjVertex<T>)edge.getDestination());
					}

					ds.addAll(adjacents);
				}
			}
			return trav;

		}

		public void dfs() {
			for (Vertex<T> u : vertices) {
				u.setColor(Vertex.WHITE);
				u.setPred(null);
			}
			int time = 0;
			for (Vertex<T> u : vertices) {
				if (u.getColor() == Vertex.WHITE) {
					time = dfsVisit((AdjVertex<T>) u, time);
				}
			}
		}

		private int dfsVisit(AdjVertex<T> u, int time) {
			time++;
			u.setD(time);
			u.setColor(Vertex.GRAY);
			for (int i = 0; i < u.getAdjList().size(); i++) {
				AdjVertex<T> v = (AdjVertex<T>) u.getAdjList().get(i).getDestination();
				if (v.getColor() == Vertex.WHITE) {
					v.setPred(u);
					time = dfsVisit(v, time);

				}
			}
			u.setColor(Vertex.BLACK);
			time++;
			u.setF(time);
			return time;
		}

		private void initSingleSource(AdjVertex<T> s) {
			for (Vertex<T> u : vertices) {
				u.setD(INF);
				u.setPred(null);
			}
			s.setD(0);
		}
		
		public double[] dijkstra(Vertex<T> x) {

			double[] array = new double[numberOfVertices];

			for (int i = 0; i < array.length; i++) {
				array[i] = INF;
			}

			array[x.getIndex()] = 0;

			AdjVertex<T> s = (AdjVertex<T>) x;
			initSingleSource(s);
			PriorityQueue<AdjVertex<T>> queue = new PriorityQueue<>();
			queue.add(s);
			while (!queue.isEmpty()) {
				AdjVertex<T> u = queue.poll();
				
				for (Edge<T> e : u.getAdjList()) {

					AdjVertex<T> v = (AdjVertex<T>) e.getDestination();
					double weight = e.getWeight();
					


					

					double distanceFromU = u.getD() + weight;
					

					if (distanceFromU < v.getD()) {
						queue.remove(v);
						v.setD(distanceFromU);
						v.setPred(u);
						queue.add(v);
						int index = v.getIndex();
						array[index] = distanceFromU;

					}
				}
			}

			return array;
		}

		public double[][] floydwarshall() {
			double[][] weights = getWeightsMatrix();
			for (int k = 0; k < vertices.size(); k++) {
				for (int i = 0; i < vertices.size(); i++) {
					for (int j = 0; j < vertices.size(); j++) {
						weights[i][j] = Math.min(weights[i][j], weights[i][k] + weights[k][j]);
					}
				}
			}
			return weights;
		}

		private double[][] getWeightsMatrix() {
			double[][] weights = new double[vertices.size()][vertices.size()];
			for (int i = 0; i < weights.length; i++) {
				Arrays.fill(weights[i], INF);
			}
			for (int i = 0; i < vertices.size(); i++) {
				weights[i][i] = 0;
				AdjVertex<T> u = (AdjVertex<T>) vertices.get(i);
				for (Edge<T> e : u.getAdjList()) {
					AdjVertex<T> v = (AdjVertex<T>) e.getDestination();
					double weight = e.getWeight();
					weights[i][getIndexOf(v)] = weight;
				}
			}
			return weights;
		}

		public void prim(Vertex<T> s) {
			AdjVertex<T> r = (AdjVertex<T>) s;
			for (Vertex<T> u : vertices) {
				u.setD(INF);
				u.setColor(Vertex.WHITE);
			}
			r.setD(0);
			r.setPred(null);
			PriorityQueue<AdjVertex<T>> queue = new PriorityQueue<>();
			for (Vertex<T> u : vertices) {
				queue.add((AdjVertex<T>) u);
			}
			while (!queue.isEmpty()) {
				AdjVertex<T> u = queue.poll();
				for (Edge<T> e : u.getAdjList()) {
					AdjVertex<T> v = (AdjVertex<T>) e.getDestination();
					if (v.getColor() == Vertex.WHITE && e.getWeight() < v.getD()) {
						queue.remove(v);
						v.setD(e.getWeight());
						queue.add(v);
						v.setPred(u);
					}
				}
				u.setColor(Vertex.BLACK);
			}
		}

		public ArrayList<Edge<T>> kruskal() { 

			

			ArrayList<Edge<T>> result = new ArrayList<>(); 

			int e = 0; 

			int i = 0; 


			ArrayList<Edge<T>> edges = getEdges();

			

			

			

			Collections.sort(edges);

			UnionFind uf = new UnionFind(vertices.size());

			i = 0; 


			

			while (e < vertices.size() - 1 && i < edges.size()) {
				

				

				Edge<T> edge = edges.get(i);
				i++;

				int x = uf.find(getIndexOf(edge.getSource()));
				int y = uf.find(getIndexOf(edge.getDestination()));

				

				

				

				if (x != y) {
					result.add(edge);
					e++;
					uf.union(x, y);
				}
				

			}
			return result;
		}

		public ArrayList<Edge<T>> getEdges() {
			ArrayList<Edge<T>> edges = new ArrayList<>();
			for (int i = 0; i < vertices.size(); i++) {
				AdjVertex<T> v = (AdjVertex<T>) vertices.get(i);
				for (int j = 0; j < v.getAdjList().size(); j++) {
					edges.add(v.getAdjList().get(j));
				}
			}
			return edges;
		}

	}

}
