


import java.beans.Visibility;
import java.io.*;
import java.lang.annotation.Target;
import java.lang.reflect.Array;
import java.nio.channels.AsynchronousCloseException;
import java.security.KeyStore.Entry;
import java.util.*;
import java.util.logging.*;
import java.io.*;
import java.util.logging.*;
import java.util.regex.*;

import javax.management.ValueExp;
import javax.print.DocFlavor.INPUT_STREAM;
import javax.swing.plaf.basic.BasicBorders.SplitPaneBorder;
import javax.swing.text.AbstractDocument.LeafElement;
import javax.xml.validation.Validator;

public class Codeforces {
	
	public static void main(String[] args) {
		id5 in = new id5(System.in);
		
		try(PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));)
		{
			new Codeforces().solution(in, out);
		} catch (Exception e) {
			System.out.println(e.getStackTrace());
		}
	}
	
	public void solution(id5 in, PrintWriter out)
	{
		try {
			int t = in.nextInt();
			while (t-->0) {
				int n = in.nextInt();
				int q = in.nextInt();
				int a [] = in.id24(n);
				TreeMap<Integer , Integer> p = new TreeMap<>();
				TreeMap<Integer , Integer> p1 = new TreeMap<>();

				for (int i = 0; i < a.length; i++) {
					if (p.containsKey(a[i])) {
						continue;
					}
					p.put(a[i], i);
				}
				for (int i = 0; i < a.length; i++) {
					p1.put(a[i], i);
				}
				while (q-->0) {
					int x = in.nextInt();
					int y  = in.nextInt();
					int x1= -1;
					int y1= -1;
					if (p.containsKey(x)) {
						x1=p.get(x);
					}
					if (p1.containsKey(y)) {
						y1 = p1.get(y);
					}
					if (x1==-1||y1==-1||y1<x1) {
						out.println("NO");
					} else {
						out.println("YES");

					}
				}
				
			}
			
		} catch (Exception exception) {
			out.println(exception);
		}	
			
	}
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int ans [] = new int[s.length()];
		
		for (int i = 0; i < s.length(); i++) {
			int x = startPos[0];
			int y = startPos[1];
			int k =0;
			for (int j = i; j < s.length(); j++) {
				if (s.charAt(j)=='R') {
					x+=1;
				}
				if (s.charAt(j)=='L') {
					x-=1;
				}
				if (s.charAt(j)=='D') {
					y++;
				}
				if (s.charAt(j)=='U') {
					y--;
				}
				if (x>=n||y>=n) {
					break;
				}
				k++;
			}
			ans[i]=k;
		}
		return ans;
    }
	public int countSquares(int[][] matrix) {
        int dp [][] = new int [matrix.length+1][matrix[0].length+1];
		for (int i = 1; i <=matrix.length; i++) {
			for (int j = 1; j <=matrix[0].length; j++) {
				if (matrix[i][j]==1) {
					if (i>=1&&j>=1) {
						dp[i][j] =1+ Math.min(dp[i-1][j], Math.min(dp[i-1][j-1], dp[i][j-1]) );
					}
				}
				x+=dp[i][j];
			}
		}

		return x;
    }


	HashMap<Integer, Integer> map  = new HashMap<>();
	public int id39(int n) {
        if (n==1) {
			return 1;
		}
		if (n==2||n==3) {
			return 0;
		}
		id36( map ,  0  , n );

		return x;
    }



	public void id36( HashMap<Integer, Integer>map ,  int col  , int n  ) {
		if (col == n) {
			x++;
			return;
		}

		for (int i = 0; i < n; i++) {
			map.put(col, i);
			boolean f = true;
			for (int j = 0; j < n; j++) {
				if (map.containsKey(j)) {
					if (map.get(j)==i||Math.abs(col - j)==Math.abs(map.get(j)-i) ) {
						f = false;
					}
				}
			}
			if (f) {
				id36(map, col+1, n);
			}
		}
	}

	public int[] minOperations(String boxes) {

        int a [] = new int[boxes.length()];

		for (int i = 0; i < boxes.length(); i++) {
			StringBuilder sb =  new StringBuilder(boxes);
			int x = 0;

			for (int j = 0; j < sb.length(); j++) {
				if (sb.indexOf("1")<0) {
					break;
				}
				x+=Math.abs(i - sb.indexOf("1"));
				sb.setCharAt(sb.indexOf("1"), '0');
			}
			
			a[i] = x;
		}
		
		return a;

    }

	
	public List<List<Integer>> subsets(int[] nums) {
        List<Integer> curr = new ArrayList<>();
		id40(0, nums , curr);
		return list;
    }
	public void id40(int j ,int[] n , List<Integer>curr) {
		list.add(curr);
		
		for (int i = j; i < n.length; i++) {
			curr.add(n[i]);
			id40(j+1, n, curr);
			curr.remove(curr.size()-1);
		}
	}
	
	boolean visited[]= new boolean[1000];

	public int id0(int[][] isConnected) {
        
		for (int i = 0; i < isConnected.length; i++) {
			if (visited[i]!=true) {
				x++;

				id27( i , isConnected  );

			}
		}
		return x;
    }
	public void id27( int i ,int [][]isConnected  ) {
		visited[i]=true;
		for (int j = 0; j < isConnected.length; j++) {
			if (isConnected[i][j]==1&&visited[j]!=true) {
				id27(j, isConnected);
			}
		}
	}


	public int[] id28(int[] heights) {
		int ans [] = new int[heights.length];
		Stack<Integer> stck = new Stack<>();
		for (int i = 0; i < heights.length; i++) {

			while(!stck.isEmpty()&&heights[stck.peek()]<heights[i]) {
				ans[stck.pop()]++;
			} 
			
			if (!stck.isEmpty()) {
				ans[stck.peek()]++;
			}

			stck.push(i);

		}


		
		return ans;
    }


	public int pathSum(TreeNode root, int targetSum) {
        List<Integer> path = new ArrayList<>();

        id25(root, targetSum , 0 ,path);
		pathSum(root.left, targetSum);
		pathSum(root.right, targetSum);
		for (List<Integer> p : list) {
			for (int i = 0; i < p.size() ; i++) {
				System.out.print(p.get(i)+" ");
			}
			System.out.println();
		}
        return list.size();
    }
    public void id25(TreeNode root , int t , long sum , List<Integer>path ) {
		if (root==null) {
			return;
		}
		sum+=root.val ;
		path.add(root.val);
		if (sum==t) {
			list.add(path);
		}
		id25(root.left, t, sum , path);
		id25(root.right, t, sum , path);
	}
	
	public ListNode id8(ListNode l1, ListNode l2) {
        ListNode l = new ListNode();
		int a = 0;
		int b =0;
		l1 = reverseList(l1);
		l2 = reverseList(l2);
		while (l1!=null) {
			a=a*10+l1.val;
			l1=l1.next;
		}
		while (l2!=null) {
			b=b*10+l2.val;
			l2=l2.next;
		}
		a=a+b;
		ListNode head = null;
		while (a!=0) {
			int r = a%10;
			if(l==null) {
				head= new ListNode(r);
				l=head;
			}else {
				l.next = new ListNode(r);
				l= l.next;
				}
			a/=10;
		}
		return head;
    }
	public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        ListNode nextNode=head.next;
        ListNode newHead=reverseList(nextNode);
        nextNode.next=head;
        head.next=null;
        return newHead;
    }

	int x=0;
	public int id38(int[][] grid) {
        
		int zeros = 0;
		int sx=0;
		int sy =0;
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j]==0) {
					zeros++;
				} else if (grid[i][j]==1) {
					sx=i;
					sy=j;
				}
			}
		}

		id20(zeros , sx , sy , grid);
		return x;
    }

	public void id20(int zeros ,int  i ,int  j , int g[][]) {

		if (i<0||i>=g.length||j>=g[0].length||j<0||g[i][j]<0) {
			System.out.println(i+" "+j);
			return;
		}

		
		if (g[i][j]==2) {
			if(zeros==0)
				x++;
			return;
		}
		g[i][j]=-2;
		zeros--;
		id20(zeros, i+1, j, g);
		id20(zeros, i-1, j, g);
		id20(zeros, i, j+1, g);
		id20(zeros, i, j-1, g);
		g[i][j]=0;
		zeros++;


	}
	public TreeNode id31(TreeNode root, int val, int depth) {
        if (depth==1) {
			TreeNode t  = new TreeNode(val);
			t.left=root;
			return t;
		}
		id7(root , 1 , val , depth);
		return root;
    }
	public void id7(TreeNode root , int currD , int  val , int depth) {
		if (root==null) {
			return ;
		}
		if (currD==depth) {

			TreeNode l = root.left;
			root.left = new TreeNode(val);
			root.left.left = l;
			TreeNode r = root.right;
			root.right = new TreeNode(val);
			root.right.right = r;

		}
		currD++;
		id7(root.left, currD, val, depth);
		id7(root.right, currD, val, depth);

	}

    public List<List<Integer>> threeSum(int[] nums) {
        
		int n = nums.length;
		int sum =0;
		HashSet<List<Integer>> h = new HashSet<List<Integer>>();

		for (int i = 0; i < nums.length; i++) {
			sum=nums[i];
			for (int j = i+1; j < nums.length; j++) {
				sum+=nums[j];
				int k =j;
				n = nums.length;
				while (k<n) {
					int mid = (k+n)/2;
					if ((sum+nums[mid])==0) {
						HashSet<Integer> m = new HashSet<>();
						m.add(nums[i]);
						m.add(nums[j]);
						m.add(nums[mid]);
						if (m.size()==3) {
							List<Integer>x = new ArrayList<>();
							x.add(nums[i]);
							x.add(nums[j]);
							x.add( nums[mid]);
							h.add(x);
						}
						
					} else if ((sum+nums[mid])>0) {
						n=mid;
					} else {
						k=mid;
					}
				}
			}
		}
		
		return list;
    }



	public int uniquePaths(int m, int n) {
		int dp[][]= new int [m][n];
		
        for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(i==0&&j==0) {
					dp[i][j]=1;
				} else if (i==0) {
					dp[i][j]=dp[i][j]+dp[i][j-1];
				} else if (j==0) {
					dp[i][j]=dp[i][j]+dp[i-1][j];
				} else {
					dp[i][j]+=dp[i][j-1]+dp[i-1][j];
				}
			}
		}
		return dp[m-1][n-1];
    }



	public int maxProfit(int[] prices) {
        int p = -1;
		
		return p ;
    }

	public int trap(int[] height) {
		int n = height.length;
		int left[] = new int [n];
		int right[] = new int [n];
		left[0] = height[0];
		for (int i = 1; i <n; i++) {
			left[i] = Math.max(height[i], left[i-1]);
		}
		right[n-1]=height[n-1];
        for (int i = n-2; i>=0 ; i--) {
			right[i] = Math.max(height[i], right[i+1]);
		}
		for (int i = 1; i < right.length-1; i++) {
			int s =Math.min(left[i] , right[i])-height[i];
			if (s>0) {
				x+=s;
			}
		}
		return x;
    }

    public int maxProduct(int[] nums) {
        int id11 = Integer.MIN_VALUE;
		int id33 = 0;

		for (int i = 0; i < nums.length; i++) {
			id33*=nums[i];
			if (id11<id33) {
				id11=id33;
			} 
			if (id33<=0) {
				id33=1;
			}
		}
		
		return id11;
    }


	public int maximumScore(int[] nums, int[] multipliers) {

		int n = multipliers.length;
		int dp[] = new int[n+1];

		for (int i = 1; i < multipliers.length; i++) {
			for (int j = 1; j < nums.length; j++) {
				dp[i] = Math.max(dp[j-1], multipliers[i-1]*nums[i-1]);
			}
		}
		
        return dp[n];
    }

	public int id3(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if(grid[i][j]==1){
					id21(i , j , grid);
				}
			}
		}
		return x;
    }
	public void id21(int i , int j , int[][] grid) {
		if(i<0||i>=grid.length||j<0||j>grid[0].length) {
			x++;
			return;
		}
		if(grid[i][j]==0) {
			x++;
			return;
		}
		if(grid[i][j]==1) {
			return;
		}
		id21(i+1, j, grid);
		id21(i-1, j, grid);
		id21(i, j+1, grid);
		id21(i, j-1, grid);

	}
	

	public int[] id1(int[] changed) {
		int n =changed.length;
		int m = n/2;
        int a[] = new int[m];
		if (n<2) {
			return new int[]{};
		}
		if (n%2!=0) {
			return new int[]{};
		}

		TreeMap<Integer , Integer> map = new TreeMap<>();

		for (int i = 0; i < changed.length; i++) {
			map.put(changed[i], map.getOrDefault(changed[i] ,0)+1);
		}
		int j =0;
		for (Map.Entry<Integer , Integer> e : map.entrySet()) {
			if (map.containsKey(e.getKey()*2)&&map.get(e.getKey()*2)>=1&&map.get(e.getKey())>=1) {
				map.put(e.getKey(), map.get(e.getKey()) -1);
				if(j==n-1)
					break;
				a[j++] = e.getKey();
			}
		}

		return a;
    }
	public int jump(int[] nums) {
        int n =nums.length;
		int jumps =1;
		int i =0;
		int j =0;
		while (i<n) {
			int max =0;
			for (j=i+1 ;j<=i+nums[i];j++) {
				max = Math.max(max , nums[j]+j);
			}
			jumps++;
			i=max;
		}

		return jumps;
    }

	static void sort(int[] arr) {
        if (arr.length < 2) return;

        int mid = arr.length / 2;

        int[] left_half = new int[mid];
        int[] right_half = new int[arr.length - mid];

        

        for (int i = 0; i < mid; i++) {
            left_half[i] = arr[i];
        }
        
        

        for (int i = mid; i < arr.length; i++) {
            right_half[i - mid] = arr[i];
        }

        sort(left_half);
        sort(right_half);
        merge(arr, left_half, right_half);
    }
  
    static void merge(int[] arr, int[] left_half, int[] right_half) {
        int i = 0, j = 0, k = 0;

        while (i < left_half.length && j < right_half.length) {
            if (left_half[i] < right_half[j]) {
                arr[k++] = left_half[i++];
            }
            else {
                arr[k++] = right_half[j++];
            }
        }
        while (i < left_half.length) {
            arr[k++] = left_half[i++];
        }
        while (j < right_half.length) {
            arr[k++] = right_half[j++];
        }
    }

	public int id41(int[] cost) {
		int n = cost.length;
		int dp[] = new int[n+1];
		dp[1] = cost[0];
		dp[2] = cost[1];

		for (int i = 3; i <=n; i++) {
			dp[i]=cost[i-1]+Math.min(dp[i-1], dp[i-2]);
		}

		return dp[n];
    }
	TreeNode newAns =null;
    public TreeNode id14(TreeNode root, int target) {
		newAns = root;
        id29(newAns , target);
		return newAns;
    }
	public void id29(TreeNode root , int t) {
		if (root==null) {
			return;
		}
		if (root.val==t) {
			if (root.left!=null) {
				root=root.left;
			}else if (root.right!=null){
				root=root.right;
			} else {
				root=null;
			}

		}
		id29(root.left, t);
		id29(root.right, t);
	}

	public int maxProfit(int k, int[] prices) {
		int n = prices.length;
		if (n <= 1)
			return 0;
		
		if (k >=  n/2) {
			return stocks(prices, n);
		}
		
		int[][] dp = new int[k+1][n];

		for (int i = 1; i <=k; i++) {
			int c= dp[i-1][0] - prices[0];
			for (int j = 1; j < n; j++) {
				dp[i][j] = Math.max(dp[i][j-1],  prices[j] + c);
				c = Math.max(c, dp[i-1][j] - prices[j]);
			}
		}
		return dp[k][n-1];
	}

	public int stocks(int [] prices , int n ) {
		int maxPro = 0;
			for (int i = 1; i < n; i++) {
				if (prices[i] > prices[i-1])
					maxPro += prices[i] - prices[i-1];
			}
		return maxPro;
	}

    public List<List<Integer>> combine(int n, int k) {
		List<Integer> x = new ArrayList<>();

        combinations( n , k  , 1 ,x);
		return list;
    }

	public void combinations(int n , int k ,int startPos , List<Integer> x) {
		if (k==x.size()) {
			list.add(new ArrayList<>(x));
			

			return;
		}
		for (int i = startPos; i <=n; i++) {
			x.add(i);
			
			combinations(n, k, i+1, x);
			x.remove(x.size()-1);
		}


	}
	List<List<Integer>> list = new ArrayList<>();

	public List<List<Integer>> permute(int[] a) {
		List<Integer> x = new ArrayList<>();

        id13(a , 0 ,a.length ,x );
		return list ;
    }

	public void id13(int a[] , int startPos , int l , List<Integer>x) {
		if (l==x.size()) {
			list.add(new ArrayList<>(x));
			

		}
		for (int i = 0; i <=l; i++) {
			if (!x.contains(a[i])) {
				x.add(a[i]);
			
				id13(a, i, l, x);
				x.remove(x.size()-1);
			}

		}
	}

	List<String> str = new ArrayList<>();

	public List<String> id4(String s) {

		id26(s , 0 , s.length() , "" );
        return str;
    }

	public void id26(String s ,int i , int l , String curr) {

		if (curr.length()==l) {
			str.add(curr);
			return;
		}
		
		char b = s.charAt(i);
		curr+=b;
		id26(s, i+1, l, curr);
		curr = new StringBuilder(curr).deleteCharAt(curr.length()-1).toString();
		if (Character.isAlphabetic(b)&&Character.isLowerCase(b)) {
			curr+=Character.toUpperCase(b);
			id26(s, i+1, l, curr);
			curr = new StringBuilder(curr).deleteCharAt(curr.length()-1).toString();

		} else if (Character.isAlphabetic(b)) {
			curr+=Character.toLowerCase(b);
			id26(s, i+1, l, curr);
			curr = new StringBuilder(curr).deleteCharAt(curr.length()-1).toString();


		}
	}

	TreeNode ans= null;
	public TreeNode id12(TreeNode root) {
		id2(root , 0 );
        return ans;
    }
	public void id2(TreeNode root , int level) {
		if (root==null) {
			return;
		}

		if (depth(root.left)==depth(root.right)) {
			ans= root;
			return;
		} else if (depth(root.left)>depth(root.right)){
			id2(root.left, level+1);
		} else {
			id2(root.right, level+1);
		}
	}


	public int depth(TreeNode root) {

		if (root==null) {
			return 0;
		}

		return 1+Math.max(depth(root.left), depth(root.right));
	}

	TreeMap<Integer , Integer> m = new TreeMap<>();
	public int id30(TreeNode root) {
        int maxlevel =0;
		int mx = Integer.MIN_VALUE;
		id10(root , 0);

		for (Map.Entry<Integer,Integer> e : m.entrySet()) {
			if (e.getValue()>mx) {
				mx=e.getValue();
				maxlevel=e.getKey()+1;
			}
		}
		
		return maxlevel;
    }
	public void id10(TreeNode root , int currLevel) {
		if (root==null) {
			return;
		}

		if (!m.containsKey(currLevel)) {
			m.put(currLevel, root.val);
		} else {
			m.put(currLevel, m.get(currLevel)+root.val);
		}
		id10(root.left, currLevel+1);
		id10(root.right, currLevel+1);
		
	}

	int id15 = 0;
	int id22 = 0;

    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {

		int [][] map = new int[efficiency.length][2];
		
		for (int i = 0; i < efficiency.length; i++) {
			map[i][0] = efficiency[i];
			map[i][1] = speed[i];
		}
		Arrays.sort(map , (e1 , e2 )-> (e2[0] - e1[0]));
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		calmax(map  , speed , efficiency , pq , k);
		return id15 ;
    }

	public void calmax(int [][]map , int s[] , int e[] , PriorityQueue<Integer>pq , int k) {
		
		for (int i = 0 ; i<n ; i++) {
			if (pq.size()==k) {
				int lowestSpeed =pq.remove();
				id22-=lowestSpeed;
				
			}
			pq.add(map[i][1]);
	
			id22+=map[i][1];
			
			id15=Math.max(id15, id22*map[i][1]);
		}

	}

	int maxRob = 0;
	public int rob(int[] nums) {
        
		int one = 0;
		int two = 0;

		for (int i = 0; i < nums.length; i++) {
			if (i%2==0) {
				one+=nums[i];
			} else {
				two+=nums[i];
			}
		}


		return Math.max(one, two);
    }
	
   



	
	public int id19(int[][] properties) {

		int c =0;
		Arrays.sort(properties, (a, b) -> (b[0] == a[0]) ? (a[1] - b[1]) : b[0] - a[0]);
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		pq.offer(0);

		for (int i = 0; i < properties.length; i++) {
			if (properties[i][1]<pq.peek()) {
				c++;

			}
			pq.offer(properties[i][1]);
		}

			

		return c;
    }



	public boolean canFinish(int numCourses, int[][] id16) {
        boolean f = true ;

		TreeMap <Integer,Integer> map = new TreeMap<>();
		for (int i = 0; i < id16.length; i++) {
			if (map.get(id16[i][1])!=null) {
				return false;
			}
				map.put(id16[i][0], id16[i][1]);
		}

		return f;
    }
	int n =0;
	char res[][] = new char [1000][1000];
	public int id18(char[][] board) {

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				res[i][j]= board[i][j];
				
			}
		}

		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (res[i][j]=='X') {
					int x = dfsB( i , j ,board , res);
					n++;
				}
			}
		}
        return n ;
    }
	public int dfsB(int i , int j , char [][]b , char [][]res) {
		if (i<0||i>=b.length|j<0||j>=b[0].length||res[i][j]=='.') {
			return 0;
		}

		if (res[i][j]=='X') {
			return 1+dfsB(i+1, j, b, res)+dfsB(i, j+1, b, res);
		}

		return 0;

		
	}
	List<Integer> l = new ArrayList<>();
	public List<Integer> id17(TreeNode root) {
        return id37(root);
    }
	public List<Integer> id37(TreeNode root) {
		if (root!=null) {
			l.add(root.val);
		}
		if (root==null) {
			return l;
		}
		if (root.right==null) {
			l.add(root.right.val);
		}

		id37(root.right);

		return l;
	}
	public void id35(TreeNode root ,int sum , int l ) {
		


		

		l=l*10 +root.val;
		if (root.left!=null) {
			id35(root.left,sum , l);

		}

		if (root.right!=null) {
			id35(root.right , sum, l);

		}
		
		if (root.left==null && root.right==null) {
			sum+=l;
			
		}
		

			

		

		l-=root.val;
		l/=10;

	}

	
	

	public int[][] updateMatrix(int[][] mat) {
        int m  =mat.length;
		int n = mat[0].length;
		Queue<int[]> q = new LinkedList<>();

		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[0].length; j++) {
				if (mat[i][j]==0) {
					q.offer(new int[] { i , j});
				} else {
					mat[i][j] = Integer.MAX_VALUE;
				}
			}
		}

		int dir[][] = {{1 , 0} , {-1 , 0} , {0 , 1} , { 0 , -1}};

		while (!q.isEmpty()) {
			int zeroPos[] = q.poll();
			for (int[] d : dir) {
				int r = zeroPos[0]+d[0];
				int c = zeroPos[1]+d[1];

				if (r<0||r>=mat.length || c<0||c>=mat[0].length||mat[r][c]<=mat[zeroPos[0]][zeroPos[1]]+1) {
					continue;
				}
				q.add(new int[]{r,c});
				mat[r][c] = mat[zeroPos[0]][zeroPos[1]]+1;

			}
		}

		return mat;
    }
	

    

	

    

	

				
	

	

	

	

	

	

    

	

	


	


	


	

	

	

	

	

	


	



	

	


	
    public int maxDepth(TreeNode root) {
		if (root==null) {
			return 0;
		}

        return maxD(root , 0);
    }
	public int maxD(TreeNode root , int d ) {
		if (root==null) {
			return d;
		}

		return Math.max(maxD(root.left, d+1), maxD(root.right, d+1));

	}

	public int reverse(int x) {
		int sign=x>0?1:-1;

		


		long s= 0;
		int r= 0;
		int n=x;
		while (n!=0) {
			r=n%10;
			s=s*10+r;
			n/=10;
			if (s>Integer.MAX_VALUE||s<Integer.MIN_VALUE) {
				return 0;
				
			}
		}

		
		return (int)s*sign;
    }
	public boolean id34(String s1, String s2) {
        boolean f = false ;


		if (s1.length()>s2.length()) {
			return false;
		}

		for (int i = 0; i < s2.length(); i++) {
			HashMap<Character ,Integer> c1 = new HashMap<>();
			HashMap<Character ,Integer> c2 = new HashMap<>();
			for (int j = 0; j < s1.length(); j++) {
				char ch2 = s2.charAt(i+j);
				char ch1 = s1.charAt(j);
				

					
				

			}
		}

		return f;
    }
	 public class ListNode {
	     int val;
	     ListNode next;
	     ListNode() {}
	     ListNode(int val) { this.val = val; }
	     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
	 }
	 public ListNode middleNode(ListNode head) {
        ListNode mid = head;
		ListNode last = head;
		int k =0;
		while (last.next!=null&&last.next.next!=null) {
			k++;
			mid= mid.next;
			last = last.next.next;
		}

		if (getLen(head)%2==0) {
			return mid.next;
		}
		return mid;
    }
	public int getLen(ListNode mid) {
		int l = 0;
		ListNode p = mid;
		while (p!=null) {
			l++;
			p=p.next;
		}
		return l;
	}
	public class TreeNode {
		int val;
		     TreeNode left;
		     TreeNode right;
		     TreeNode() {}
		     TreeNode(int val) { this.val = val; }
		     TreeNode(int val, TreeNode left, TreeNode right) {
		         this.val = val;
		         this.left = left;
		         this.right = right;
		     }
		 }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();
        dfs(root, 0, 0, map);
        List<List<Integer>> list = new ArrayList<>();
        for (TreeMap<Integer, PriorityQueue<Integer>> ys : map.values()) {
            list.add(new ArrayList<>());
            for (PriorityQueue<Integer> nodes : ys.values()) {
                while (!nodes.isEmpty()) {
                    

                }
            }
        }
        return list;
    }
    private void dfs(TreeNode root, int x, int y, TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map) {
        if (root == null) {
            return;
        }
        if (!map.containsKey(x)) {
            map.put(x, new TreeMap<>());
        }
        if (!map.get(x).containsKey(y)) {
            map.get(x).put(y, new PriorityQueue<>());
        }
        map.get(x).get(y).offer(root.val);
        dfs(root.left, x - 1, y + 1, map);
        dfs(root.right, x + 1, y + 1, map);
    }

	
	public long pow (int x ,int n ) {
		long y = 1;
		if (n==0) {
			return y;
		}

		while (n>0) {
			if (n%2!=0) {
				y=y*x;

			} 

			x*=x;
			n/=2;
		}

		return y;
	}
	public long powrec (int x ,int n ) {
		long y = 1;
		if (n==0) {
			return y;
		}

		y = powrec(x, n/2);
		if (n%2==0) {
			return y*y;
		} 
		return y*y*x;
	}


	public int fib(int n) {

		if (n==0||n==11) {
			return n;
		}

		return fib(n-1)+fib(n-2);
	}

	public long gcd(long a , long b)
	{
		if (b%a==0) {
			return a;
		}
		return gcd(b%a,a);
	}
	
	public int maximumElement(int a[])
	{
		int x = Integer.MIN_VALUE;
		for (int i = 0; i < a.length; i++) {
			 if (a[i]>x) {
				x=a[i];
			 }

		}

		return x;
	}

	public int minimumElement(int a[])
	{
		int x = Integer.MAX_VALUE;
		for (int i = 0; i < a.length; i++) {
			 if (a[i]<x) {
				x=a[i];
			 }

		}

		return x;
	}

	public boolean [] id32(int n) {
        boolean prime[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++) {
           
            if (prime[p]) {
 
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
		}
		return prime;
    }

	

	public ArrayList id6(int n ,int k)
    {
 
        

        ArrayList<ArrayList<Integer> > x
            = new ArrayList<ArrayList<Integer> >();
 
        


        

        

		int xr = 0;

		for (int i = 1; i <= n; i+=2) {
			if ((i+k)*(i+1)%4==0) {
				x.add(new ArrayList<Integer>());
				x.get(xr).addAll(Arrays.asList(i , i+1));

			} 
			else {
				x.add(new ArrayList<Integer>());
				x.get(xr).addAll(Arrays.asList(i+1 , i));
			}
			xr++;
		}
 
        

        

        

        

        

 
        

        

 
        

        

 
        

        

 
        

        

        

 
        

        

 
        

        

 
        

        

        

 
        

        return x;
    }
 
	
}

class id5
{
	BufferedReader in;
	StringTokenizer token;
	
	public id5(InputStream ins)
	{
		in=new BufferedReader(new InputStreamReader(ins));
		token=new StringTokenizer("");
	}
 
	public boolean hasNext()
	{
		while (!token.hasMoreTokens())
		{
			try
			{
				String s = in.readLine();
				if (s == null) return false;
				token = new StringTokenizer(s);
			} catch (IOException e)
			{
				throw new InputMismatchException();
			}
		}
		return true;
	}
 
	public String next()
	{
		hasNext();
		return token.nextToken();
	}
 
	public int nextInt()
	{
		return Integer.parseInt(next());
	}
 
	public int[] id24(int n)
	{
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = nextInt();
		return res;
	}
 
	public long nextLong() {
		return Long.parseLong(next());
	}	

	public long[] id9(int n)
	{
		long [] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}

	public String nextString() {

		return String.valueOf(next());
	}	

	public String[] id23(int n)
	{
		String [] a = new String[n];
		for (int i = 0; i < n; i++)
			a[i] = nextString();
		return a;
	}
	
}


 

 

