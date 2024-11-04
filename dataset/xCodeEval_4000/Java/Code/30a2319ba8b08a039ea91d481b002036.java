import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class TrainsAndStatistic2 {

	public TrainsAndStatistic2() {
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


			
			long[] dp = new long[n+1];	


			
			SegmentTree segTree = new SegmentTree(stations);

			dp[n] = 0;	

			
			for (int i = n - 1; i >= 1; --i) {
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

		




















		new TrainsAndStatistic2();
	}
}


class SegmentTree {

	
	private class Node {
		Node left, right, parent;	

		int a, b;					


		
		int[] maxValueAndStationNumber;

		
		Node() {
			this.left = null;
			this.right = null;
			this.parent = null;
			this.a = -1;
			this.b = -1;
			this.maxValueAndStationNumber = new int[]{Integer.MIN_VALUE, -1};	

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

		
		void setMaxValue(int value, int stationNum) {
			this.maxValueAndStationNumber[0] = value;
			this.maxValueAndStationNumber[1] = stationNum;
		}

		
		@Override
		public String toString() {
			return String.format("(interval:[%s,%s], maxValueAndStationNumber:%s)",
					               a,b, Arrays.toString(this.maxValueAndStationNumber));
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

			currNode.setMaxValue(this.arr[minIndex], minIndex);	

			return currNode.maxValueAndStationNumber;
		}

		

		int midIndex = (minIndex + maxIndex) / 2;
		Node leftChild = new Node();
		Node rightChild = new Node();
		currNode.setLeft(leftChild);
		currNode.setRight(rightChild);

		

		int[] maxFromLeftChild = buildTree(currNode, leftChild, minIndex, midIndex);
		int[] maxFromRightChild = buildTree(currNode, rightChild, midIndex + 1, maxIndex);

		

		if (maxFromLeftChild[0] > maxFromRightChild[0]) {
			currNode.setMaxValue(maxFromLeftChild[0], maxFromLeftChild[1]);
		} else {
			currNode.setMaxValue(maxFromRightChild[0], maxFromRightChild[1]);
		}
		return currNode.maxValueAndStationNumber;	

	}
	


	
	public int[] maxQuery(int requestedMin, int requestedMax) {
		return maxQuery(requestedMin, requestedMax, this.root);	

	}

	
	private int[] maxQuery(int requestedMinIndex, int requestedMaxIndex, Node currNode) {
		if (currNode == null) {	

			return new int[]{Integer.MIN_VALUE, -1};
		}

		

		int minIndex = currNode.a;
		int maxIndex = currNode.b;

		

		if (maxIndex < requestedMinIndex || minIndex > requestedMaxIndex) {
			return new int[]{Integer.MIN_VALUE, -1};
		}

		
		if (minIndex >= requestedMinIndex && maxIndex <= requestedMaxIndex) {
			return currNode.maxValueAndStationNumber;
		}

		
		int[] maxQueryFromLeft = maxQuery(requestedMinIndex, requestedMaxIndex, currNode.left);
		int[] maxQueryFromRight = maxQuery(requestedMinIndex, requestedMaxIndex, currNode.right);
		if (maxQueryFromLeft[0] > maxQueryFromRight[0]) {
			return maxQueryFromLeft;
		} else {
			return maxQueryFromRight;
		}
	}
	

}