import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Set;
import java.util.StringTokenizer;

public class Dijkstra {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		List<Node>[] adj = new List[N];
		Set<Integer>[] neighbors = new Set[N];
		long[] dist = new long[N];
		int[] prev = new int[N];
		boolean[] visited = new boolean[N];
		Arrays.fill(dist, -1);
		dist[0] = 0;
		prev[0] = -1;
		for (int i = 0; i < N; i++) {
			adj[i] = new ArrayList<>();
			neighbors[i] = new HashSet<>();
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int src = Integer.parseInt(st.nextToken()) - 1;
			int dest = Integer.parseInt(st.nextToken()) - 1;
			int weight = Integer.parseInt(st.nextToken());
			adj[src].add(new Node(dest, weight));
			adj[dest].add(new Node(src, weight));
			neighbors[src].add(dest);
			neighbors[dest].add(src);
		}
		id0<Integer> queue = new id0<>();
		queue.add(0, 0);
		while (!queue.isEmpty()) {
			int node = queue.pop().getValue();
			if (visited[node])
				continue;
			visited[node] = true;
			for (Node child : adj[node]) {
				if (visited[child.node])
					continue;
				long dgc = dist[node] + child.weight; 

				if (dist[child.node] == -1) {
					dist[child.node] = dgc;
					prev[child.node] = node;
				} else {
					if (dgc < dist[child.node]) {
						dist[child.node] = dgc;
						prev[child.node] = node;
					}
				}
				queue.add(child.node, dist[child.node]);
			}
		}
		if (dist[N - 1] == -1) {
			System.out.println(-1);
			return;
		}
		StringBuilder sb = new StringBuilder(1 << 20);
		List<Integer> path = new ArrayList<>();
		int node = N - 1;
		while (node != -1) {
			path.add(node);
			node = prev[node];
		}
		for (int i = path.size() - 1; i >= 0; i--) {
			sb.append(path.get(i) + 1).append(" ");
		}
		System.out.println(sb);
	}

	public static class Node {
		int node;
		int weight;

		Node(int n, int w) {
			node = n;
			weight = w;
		}
	}

	

	
	public static final class id0<T> {
		
		public static final class Entry<T> {
			private int mDegree = 0; 

			private boolean id3 = false; 


			private Entry<T> mNext; 

			private Entry<T> mPrev;

			private Entry<T> mParent; 


			private Entry<T> mChild; 


			private T mElem; 

			private double mPriority; 


			
			public T getValue() {
				return mElem;
			}

			
			public void setValue(T value) {
				mElem = value;
			}

			
			public double getPriority() {
				return mPriority;
			}

			
			private Entry(T elem, double priority) {
				mNext = mPrev = this;
				mElem = elem;
				mPriority = priority;
			}
		}

		
		private Entry<T> mMin = null;

		
		private int mSize = 0;

		
		public Entry<T> add(T value, double priority) {
			checkPriority(priority);

			
			Entry<T> result = new Entry<T>(value, priority);

			
			mMin = mergeLists(mMin, result);

			
			++mSize;

			
			return result;
		}

		
		public Entry<T> min() {
			if (isEmpty())
				return null;
			return mMin;
		}

		
		public boolean isEmpty() {
			return mMin == null;
		}

		
		public int size() {
			return mSize;
		}

		
		public static <T> id0<T> merge(id0<T> one, id0<T> two) {
			
			id0<T> result = new id0<T>();

			
			result.mMin = mergeLists(one.mMin, two.mMin);

			
			result.mSize = one.mSize + two.mSize;

			
			one.mSize = two.mSize = 0;
			one.mMin = null;
			two.mMin = null;

			
			return result;
		}

		
		public Entry<T> pop() {
			
			if (isEmpty())
				return null;

			
			--mSize;

			
			Entry<T> minElem = mMin;

			
			if (mMin.mNext == mMin) { 

				mMin = null;
			} else { 

				mMin.mPrev.mNext = mMin.mNext;
				mMin.mNext.mPrev = mMin.mPrev;
				mMin = mMin.mNext; 

			}

			
			if (minElem.mChild != null) {
				
				Entry<?> curr = minElem.mChild;
				do {
					curr.mParent = null;

					
					curr = curr.mNext;
				} while (curr != minElem.mChild);
			}

			
			mMin = mergeLists(mMin, minElem.mChild);

			
			if (mMin == null)
				return minElem;

			
			List<Entry<T>> treeTable = new ArrayList<Entry<T>>();

			
			List<Entry<T>> toVisit = new ArrayList<Entry<T>>();

			
			for (Entry<T> curr = mMin; toVisit.isEmpty() || toVisit.get(0) != curr; curr = curr.mNext)
				toVisit.add(curr);

			
			for (Entry<T> curr : toVisit) {
				
				while (true) {
					
					while (curr.mDegree >= treeTable.size())
						treeTable.add(null);

					
					if (treeTable.get(curr.mDegree) == null) {
						treeTable.set(curr.mDegree, curr);
						break;
					}

					
					Entry<T> other = treeTable.get(curr.mDegree);
					treeTable.set(curr.mDegree, null); 


					
					Entry<T> min = (other.mPriority < curr.mPriority) ? other : curr;
					Entry<T> max = (other.mPriority < curr.mPriority) ? curr : other;

					
					max.mNext.mPrev = max.mPrev;
					max.mPrev.mNext = max.mNext;

					
					max.mNext = max.mPrev = max;
					min.mChild = mergeLists(min.mChild, max);

					
					max.mParent = min;

					
					max.id3 = false;

					
					++min.mDegree;

					
					curr = min;
				}

				
				if (curr.mPriority <= mMin.mPriority)
					mMin = curr;
			}
			return minElem;
		}

		
		public void id2(Entry<T> entry, double newPriority) {
			checkPriority(newPriority);
			if (newPriority > entry.mPriority)
				throw new IllegalArgumentException("New priority exceeds old.");

			
			id1(entry, newPriority);
		}

		
		public void delete(Entry<T> entry) {
			
			id1(entry, Double.NEGATIVE_INFINITY);

			
			pop();
		}

		
		private void checkPriority(double priority) {
			if (Double.isNaN(priority))
				throw new IllegalArgumentException(priority + " is invalid.");
		}

		
		private static <T> Entry<T> mergeLists(Entry<T> one, Entry<T> two) {
			
			if (one == null && two == null) { 

				return null;
			} else if (one != null && two == null) { 

				return one;
			} else if (one == null && two != null) { 

				return two;
			} else { 

				
				Entry<T> oneNext = one.mNext; 

				one.mNext = two.mNext;
				one.mNext.mPrev = one;
				two.mNext = oneNext;
				two.mNext.mPrev = two;

				
				return one.mPriority < two.mPriority ? one : two;
			}
		}

		
		private void id1(Entry<T> entry, double priority) {
			
			entry.mPriority = priority;

			
			if (entry.mParent != null && entry.mPriority <= entry.mParent.mPriority)
				cutNode(entry);

			
			if (entry.mPriority <= mMin.mPriority)
				mMin = entry;
		}

		
		private void cutNode(Entry<T> entry) {
			
			entry.id3 = false;

			
			if (entry.mParent == null)
				return;

			
			if (entry.mNext != entry) { 

				entry.mNext.mPrev = entry.mPrev;
				entry.mPrev.mNext = entry.mNext;
			}

			
			if (entry.mParent.mChild == entry) {
				
				if (entry.mNext != entry) {
					entry.mParent.mChild = entry.mNext;
				}
				
				else {
					entry.mParent.mChild = null;
				}
			}

			
			--entry.mParent.mDegree;

			
			entry.mPrev = entry.mNext = entry;
			mMin = mergeLists(mMin, entry);

			
			if (entry.mParent.id3)
				cutNode(entry.mParent);
			else
				entry.mParent.id3 = true;

			
			entry.mParent = null;
		}
	}
}
