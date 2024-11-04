import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class id3 {

	public id3() {
		try {
			BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

			

			int n = Integer.parseInt(rd.readLine());

			
			int stations[] = new int[n + 1];

			

			String line = rd.readLine();
			StringTokenizer tokenizer = new StringTokenizer(line);

			
			for (int i = 1; i <= n - 1; i++) {
				int value = Integer.parseInt(tokenizer.nextToken());
				stations[i] = value;
			}



			rd.close();




			SegmentTree segTree = new SegmentTree(stations);

			









			







			


			
			long[] dp = new long[n+1];

			dp[n] = 0;	

			

			for (int i = n-1; i >= 1; --i) {
				int m = segTree.maxQuery(i+1, stations[i])[1];
				dp[i] = dp[m] - (stations[i] - m) + n - i;
			}

			long sum = 0;
			for (int i = 0; i <= n; ++i) {
				sum += dp[i];
			}

			System.out.println(sum);
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}
	


	public static void main(String[] args) {





















		new id3();
	}
}


class SegmentTree {

	
	private class Node {
		Node left, right, parent;	

		int a, b;					

		int[] id5;

		
		Node() {
			this.left = null;
			this.right = null;
			this.parent = null;
			this.a = -1;
			this.b = -1;
			this.id5 = new int[]{Integer.MIN_VALUE, -1};
		}
























		
		void setLeft(Node left) {
			this.left = left;
		}

		
		void setRight(Node right) {
			this.right = right;
		}

		void setParent(Node parent) {
			this.parent = parent;
		}

		void setInterval(int min, int max) {
			this.a = min;
			this.b = max;
		}

		void id2(int value, int stationNum) {
			this.id5[0] = value;
			this.id5[1] = stationNum;
		}

		@Override
		public String toString() {
			return String.format("(interval:[%s,%s], id5:%s)",
					               a,b, Arrays.toString(this.id5));
		}
	}
	


	private Node root;	

	private int[] arr;	


	
	public SegmentTree(int[] arr) {
		root = new Node();
		this.arr = arr;

		
		buildTree(null, root, 1, arr.length - 1);
	}

	
	private int[] buildTree(Node parent, Node currNode, int minIndex, int maxIndex) {
		currNode.setParent(parent);
		currNode.setInterval(minIndex, maxIndex);
		if (minIndex == maxIndex) {	

			currNode.id2(this.arr[minIndex], minIndex);
			return currNode.id5;
		}

		

		int midIndex = (minIndex + maxIndex) / 2;
		Node leftChild = new Node();
		Node rightChild = new Node();
		currNode.setLeft(leftChild);
		currNode.setRight(rightChild);
		

		int[] id6 = buildTree(currNode, leftChild, minIndex, midIndex);
		int[] id8 = buildTree(currNode, rightChild, midIndex + 1, maxIndex);
		if (id6[0] > id8[0]) {	

			currNode.id2(id6[0], id6[1]);
		} else {
			currNode.id2(id8[0], id8[1]);
		}
		return currNode.id5;
	}
	


	
	public int[] maxQuery(int requestedMin, int requestedMax) {
		return maxQuery(requestedMin, requestedMax, this.root);
	}

	
	private int[] maxQuery(int id0, int id4, Node currNode) {
		if (currNode == null) {	

			return new int[]{Integer.MIN_VALUE, -1};
		}

		

		int minIndex = currNode.a;
		int maxIndex = currNode.b;

		

		if (maxIndex < id0 || minIndex > id4) {
			return new int[]{Integer.MIN_VALUE, -1};
		}

		
		if (minIndex >= id0 && maxIndex <= id4) {
			return currNode.id5;
		}

		
		int[] id7 = maxQuery(id0, id4, currNode.left);
		int[] id1 = maxQuery(id0, id4, currNode.right);
		if (id7[0] > id1[0]) {
			return id7;
		} else {
			return id1;
		}
	}
	

}