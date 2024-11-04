


import java.io.*;
import java.lang.annotation.Target;
import java.lang.reflect.Array;
import java.security.KeyStore.Entry;
import java.util.*;
import java.util.logging.*;
import java.io.*;
import java.util.logging.*;
import java.util.regex.*;

import javax.swing.plaf.basic.BasicBorders.SplitPaneBorder;
import javax.swing.text.AbstractDocument.LeafElement;

public class Codeforces {
	
	public static void main(String[] args) {
		FlashFastReader in = new FlashFastReader(System.in);
		
		try(PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));)
		{
			new Codeforces().solution(in, out);
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	
	public void solution(FlashFastReader in, PrintWriter out)
	{
		try {

			int t = in.nextInt();
			while(t-->0)
			{
				int n =in.nextInt();
				
				int a[] = in.nextIntsInputAsArray(n);
				if (n==1) {
					out.println(0);
					continue;
				}
				Arrays.sort(a);
				int ans=0;
				if (a[0]==1) {
					for (int i = 1; i < a.length; i++) {
						ans+=(a[i]-1);
					}
					out.println(ans);
					continue;
				}
				
				a[0]=(a[0]*2)-1;
				for (int i = 1; i < a.length; i++) {

					ans+=((a[i]%a[0]==0)?(a[i]/a[0])-1:(a[i]/a[0]));
					
				}
					
				out.println(ans);
			} 
		} catch (Exception exception) {
			out.println(exception);
		}	
			
		
	
	}

	public int coinChange(int[] coins, int amount) {
		int dp[] = new int[amount+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int i = 1; i <=amount; i++) {
			for (int j = 0; j < coins.length; j++) {
				if (coins[j]>i) {
					break;
				}
				if(dp[i-coins[j]]!=Integer.MAX_VALUE) {
					dp[i] = Math.min(dp[i], dp[i-coins[j]]+1);

				}
			}
		}

		return dp[amount];
    }
	public int minCost(String colors, int[] neededTime) {
        
		for (int i = 1; i < neededTime.length; i++) {
			
			if (colors.charAt(i)==colors.charAt(i-1)) {
				x+=Math.min(neededTime[i], neededTime[i-1]);
				neededTime[i]=Math.min(neededTime[i], neededTime[i-1]);
			}
		}
		return x;
    }

	
	public int[] canSeePersonsCount(int[] heights) {
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


	int x=0;
	public int uniquePathsIII(int[][] grid) {
        
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

		dfsUniquePaths(zeros , sx , sy , grid);
		return x;
    }

	public void dfsUniquePaths(int zeros ,int  i ,int  j , int g[][]) {

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
		dfsUniquePaths(zeros, i+1, j, g);
		dfsUniquePaths(zeros, i-1, j, g);
		dfsUniquePaths(zeros, i, j+1, g);
		dfsUniquePaths(zeros, i, j-1, g);
		g[i][j]=0;
		zeros++;


	}


    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> wd = new HashSet<>(wordDict);
		wordBreakCheck(s , wd ,1);
		return false;
    }
	int j =0;
	public void wordBreakCheck(String s , HashSet<String>wordDict , int i) {
		if(i>s.length()) {
			return ;
		}
		if(wordDict.contains(s.substring(0 , i))){
			x=i+j;
		} else if (x!=0) {
			s=s.substring(i);
			i=0;
			j=x;
		}

		wordBreakCheck(s, wordDict, i+1);
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
        int maxSoFar = Integer.MIN_VALUE;
		int maxTillEnd = 0;

		for (int i = 0; i < nums.length; i++) {
			maxTillEnd*=nums[i];
			if (maxSoFar<maxTillEnd) {
				maxSoFar=maxTillEnd;
			} 
			if (maxTillEnd<=0) {
				maxTillEnd=1;
			}
		}
		
		return maxSoFar;
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

	public int islandPerimeter(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if(grid[i][j]==1){
					dfsIslandPerimeter(i , j , grid);
				}
			}
		}
		return x;
    }
	public void dfsIslandPerimeter(int i , int j , int[][] grid) {
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
		dfsIslandPerimeter(i+1, j, grid);
		dfsIslandPerimeter(i-1, j, grid);
		dfsIslandPerimeter(i, j+1, grid);
		dfsIslandPerimeter(i, j-1, grid);

	}
	

	public int[] findOriginalArray(int[] changed) {
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

	public int minCostClimbingStairs(int[] cost) {
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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
		newAns = root;
        dfsRemoveNode(newAns , target);
		return newAns;
    }
	public void dfsRemoveNode(TreeNode root , int t) {
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
		dfsRemoveNode(root.left, t);
		dfsRemoveNode(root.right, t);
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

        permutations(a , 0 ,a.length ,x );
		return list ;
    }

	public void permutations(int a[] , int startPos , int l , List<Integer>x) {
		if (l==x.size()) {
			list.add(new ArrayList<>(x));
			

		}
		for (int i = 0; i <=l; i++) {
			if (!x.contains(a[i])) {
				x.add(a[i]);
			
				permutations(a, i, l, x);
				x.remove(x.size()-1);
			}

		}
	}

	List<String> str = new ArrayList<>();

	public List<String> letterCasePermutation(String s) {

		casePermutations(s , 0 , s.length() , "" );
        return str;
    }

	public void casePermutations(String s ,int i , int l , String curr) {

		if (curr.length()==l) {
			str.add(curr);
			return;
		}
		
		char b = s.charAt(i);
		curr+=b;
		casePermutations(s, i+1, l, curr);
		curr = new StringBuilder(curr).deleteCharAt(curr.length()-1).toString();
		if (Character.isAlphabetic(b)&&Character.isLowerCase(b)) {
			curr+=Character.toUpperCase(b);
			casePermutations(s, i+1, l, curr);
			curr = new StringBuilder(curr).deleteCharAt(curr.length()-1).toString();

		} else if (Character.isAlphabetic(b)) {
			curr+=Character.toLowerCase(b);
			casePermutations(s, i+1, l, curr);
			curr = new StringBuilder(curr).deleteCharAt(curr.length()-1).toString();


		}
	}

	TreeNode ans= null;
	public TreeNode lcaDeepestLeaves(TreeNode root) {
		dfslcaDeepestLeaves(root , 0 );
        return ans;
    }
	public void dfslcaDeepestLeaves(TreeNode root , int level) {
		if (root==null) {
			return;
		}

		if (depth(root.left)==depth(root.right)) {
			ans= root;
			return;
		} else if (depth(root.left)>depth(root.right)){
			dfslcaDeepestLeaves(root.left, level+1);
		} else {
			dfslcaDeepestLeaves(root.right, level+1);
		}
	}


	public int depth(TreeNode root) {

		if (root==null) {
			return 0;
		}

		return 1+Math.max(depth(root.left), depth(root.right));
	}

	TreeMap<Integer , Integer> m = new TreeMap<>();
	public int maxLevelSum(TreeNode root) {
        int maxlevel =0;
		int mx = Integer.MIN_VALUE;
		dfsMaxLevelSum(root , 0);

		for (Map.Entry<Integer,Integer> e : m.entrySet()) {
			if (e.getValue()>mx) {
				mx=e.getValue();
				maxlevel=e.getKey()+1;
			}
		}
		
		return maxlevel;
    }
	public void dfsMaxLevelSum(TreeNode root , int currLevel) {
		if (root==null) {
			return;
		}

		if (!m.containsKey(currLevel)) {
			m.put(currLevel, root.val);
		} else {
			m.put(currLevel, m.get(currLevel)+root.val);
		}
		dfsMaxLevelSum(root.left, currLevel+1);
		dfsMaxLevelSum(root.right, currLevel+1);
		
	}

	int teampPerf = 0;
	int teampSpeed = 0;

    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {

		int [][] map = new int[efficiency.length][2];
		
		for (int i = 0; i < efficiency.length; i++) {
			map[i][0] = efficiency[i];
			map[i][1] = speed[i];
		}
		Arrays.sort(map , (e1 , e2 )-> (e2[0] - e1[0]));
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		calmax(map  , speed , efficiency , pq , k);
		return teampPerf ;
    }

	public void calmax(int [][]map , int s[] , int e[] , PriorityQueue<Integer>pq , int k) {
		
		for (int i = 0 ; i<n ; i++) {
			if (pq.size()==k) {
				int lowestSpeed =pq.remove();
				teampSpeed-=lowestSpeed;
				
			}
			pq.add(map[i][1]);
	
			teampSpeed+=map[i][1];
			
			teampPerf=Math.max(teampPerf, teampSpeed*map[i][1]);
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

    public int minSubArrayLen(int target, int[] nums) {
        int res =0;
		HashMap<Integer,Integer> map =new HashMap<>();
		int sum = 0 ;
		for (int i = 0; i < nums.length; i++) {
			sum+=nums[i];
			if (sum==target) {
				res+=1;
			}

			if (!map.containsKey(sum)) {
				map.put(sum, i);
			}

			if (map.containsKey(sum-target)) {
				int lastIndex = map.get(sum-target);
					res=Math.min(i-lastIndex ,res);
				
			}
		}
		return res;

    }



	class Employee {
		public int id;
		public int importance;
		public List<Integer> subordinates;
	};
	


	public int numberOfWeakCharacters(int[][] properties) {

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



	public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean f = true ;

		TreeMap <Integer,Integer> map = new TreeMap<>();
		for (int i = 0; i < prerequisites.length; i++) {
			if (map.get(prerequisites[i][1])!=null) {
				return false;
			}
				map.put(prerequisites[i][0], prerequisites[i][1]);
		}

		return f;
    }
	int n =0;
	char res[][] = new char [1000][1000];
	public int countBattleships(char[][] board) {

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
	public List<Integer> rightSideView(TreeNode root) {
        return dfsRightSideView(root);
    }
	public List<Integer> dfsRightSideView(TreeNode root) {
		if (root!=null) {
			l.add(root.val);
		}
		if (root==null) {
			return l;
		}
		if (root.right==null) {
			l.add(root.right.val);
		}

		dfsRightSideView(root.right);

		return l;
	}
	public void dfsSumNumber(TreeNode root ,int sum , int l ) {
		


		

		l=l*10 +root.val;
		if (root.left!=null) {
			dfsSumNumber(root.left,sum , l);

		}

		if (root.right!=null) {
			dfsSumNumber(root.right , sum, l);

		}
		
		if (root.left==null && root.right==null) {
			sum+=l;
			
		}
		

			

		

		l-=root.val;
		l/=10;

	}
	boolean visited[][] = new boolean[1000][1000];

	public int countSubIslands(int[][] grid1, int[][] grid2) {
		int k =0;

        for (int i = 0; i < grid1.length; i++) {
			for (int j = 0; j < grid1[0].length; j++) {
				if (grid1[i][j]==1&&grid2[i][j]==1&&!visited[i][j]) {
					islands(i, j, grid1 ,grid2 , visited);
					k++;
				}
			}
		}
		return k;
    }

	public void islands(int i ,int j ,int [][]grid1,int [][]grid2 , boolean [][]visited ) {
		
		if (i<0||i>=grid1.length||j<0||j>=grid1[0].length) {
			return;
		}
		
		if (visited[i][j]) {
			
			return;

		}
		if (grid1[i][j]==1&&grid2[i][j]==1) {
			visited[i][j]=true;

		} else {
			return;
		}

		islands(i+1, j, grid1 ,grid2, visited);
		islands(i-1, j, grid1 , grid2, visited);
		islands(i, j+1, grid1 , grid2, visited);
		islands(i, j-1, grid1 , grid2, visited);

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
	public boolean checkInclusion(String s1, String s2) {
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

    public void rotate(int[] a, int k) {
		int n = a.length;
		k = k%n;
        int temp[] = new int[k];
		for (int i = n-k; i < n; i++) {

			temp[i-(n-k)]=a[i];
		}

		for (int i =n-1 ; i>=k;i--) {
			a[i]=a[i-k];
		}

		ArrayList<Integer> b = new ArrayList<>();
		for (int i = 0; i < k; i++) {
			a[i]=temp[i];

		}

		for (int i = 0; i < a.length; i++) {
			b.add(a[i]);
		}
		
		System.out.println(b);




    }
	public int search(int[] nums, int target) {
		int n =nums.length;
        int l=0;
		int r = n-1;
		int mid =(l+r)/2;


		while (l<r) {

			mid =(l+r)/2;
			if (target==nums[mid]) {
				return mid;
			}
			if (target>nums[mid]) {
				l=mid;
			} else {
				r=mid;
			}

			
		}



		return -1;
        
    }




	public void twoLab(FlashFastReader in, PrintWriter out) {
			int h = in.nextInt();
			int m = in.nextInt();
			int s = in.nextInt();

            if (!(h>=0&&h<24&&m>=0&&m<60&&s>=0&&s<60)) {
                out.println("Not applicable");
                return;
            }

			if (m==59&&s>=45) {
				if (h!=23) {
					out.println(h+1+":"+"00"+":"+(s-45));
					return;
				}
				out.println("00"+":"+"00"+":"+(s-45));
				return ;
			}

			if (s>=45) {
				out.println(h+":"+m+1+":"+(s-45));
				return ;
			}

			out.println(h+":"+m+":"+(s+15));



			
	}
	public void oneLab(FlashFastReader in , PrintWriter out) {
		try {
			ArrayList<Integer> b =  new ArrayList<Integer>();
			
			while (true) {
				int n = in.nextInt();
				if (b.size()==0&&n%2==1) {
					out.println("Average : " + 0);
					return;
				}
				if (n%2==1) {
					break;
	
				}
				b.add(n);
			}
			long sum=0;
			long l = b.size();
			for (Integer a : b) {
				sum+=a;
			}
			out.println("average : " + sum/l);
	
			
		} catch (Exception e) {
			out.println(e);
		}
	
		
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

	public int gcd(int a , int b)
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

	boolean [] sieveOfEratosthenes(int n) {
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

	

	public ArrayList create2DArrayList(int n ,int k)
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

class FlashFastReader
{
	BufferedReader in;
	StringTokenizer token;
	
	public FlashFastReader(InputStream ins)
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
 
	public int[] nextIntsInputAsArray(int n)
	{
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = nextInt();
		return res;
	}
 
	public long nextLong() {
		return Long.parseLong(next());
	}	

	public long[] nextLongsInputAsArray(int n)
	{
		long [] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}

	public String nextString() {

		return String.valueOf(next());
	}	

	public String[] nextStringsInputAsArray(int n)
	{
		String [] a = new String[n];
		for (int i = 0; i < n; i++)
			a[i] = nextString();
		return a;
	}
	
}


 

 

