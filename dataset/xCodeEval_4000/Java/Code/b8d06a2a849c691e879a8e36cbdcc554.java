

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class UkkonenForPreXSufEdit
{
	static boolean debug2 = false;
			
	static int[] suffixOccurrences;
	static Node root;
	
	

	static boolean debug = false;
	
	static int LETTERS = 26; 

	static int computation = 0;
	
	static class SuffixTree
	{
		Node root = null;
		String s;
		int nodes = 0;
		int currentEnd = 0;
		
		void findSubstring(String p)
		{
			ArrayList<Integer> l = new ArrayList<>();
			Node posNode = root;
			Edge posEdge = null;
			int posLength = 0;
			
			int i = 0;

			while(i < p.length())
			{
				

				posEdge = posNode.getEdgeOfChar(p.charAt(i));
				posLength = 0;
				

				
				if(posEdge == null)
					return;
				
				while(posEdge != null && posLength < posEdge.getLength())
				{
					

					if(s.charAt(posEdge.s + posLength) == p.charAt(i))
					{
						i++;
						posLength++;
						if(i >= p.length())break;
					}
					else
					{ 

						return;
					}
				}
				if(posLength == posEdge.getLength()) 

				{
					if(posEdge.node != null)
					{
						posNode = posEdge.node;
						posLength = 0;
					}
				}
			}
			
			Stack<Edge> stack = new Stack<>();
			if(posLength == 0)
			{
				for(int cc = 0; cc < LETTERS+1; cc++)
				{ 

					if(posNode.edge[cc] != null)
						stack.add(posNode.edge[cc]);
				}
			}
			else stack.add(posEdge);
			
			while(!stack.isEmpty())
			{ 
				Edge e = stack.pop();
				if(e.node == null) 

					l.add(e.getStartChar());
				else
				{
					for(int cc = 0; cc < LETTERS+1; cc++)
					{ 

						if(e.node.edge[cc] != null)
							stack.add(e.node.edge[cc]);
					}
				}
			}
			l.sort(null);
			for(int z = 0; z < l.size(); z++)
				System.out.println(l.get(z));
		}
		
		void findSuffixOccurrences(String p)
		{
			

			

			

			
			

			

			
			

			
			suffixOccurrences = new int[s.length()*2];
			Node posNode = root;
			Edge posEdge = null;
			int posLength = 0;
			
			int i = 0; 


			while(i < p.length())
			{
				

				posEdge = posNode.getEdgeOfChar(p.charAt(i));
				posLength = 0;
				

				
				if(posEdge == null)
					return;
				
				while(posEdge != null && posLength < posEdge.getLength())
				{
					

					if(s.charAt(posEdge.s + posLength) == p.charAt(i))
					{
						i++;
						posLength++;
						if(i >= p.length())break;
					}
					else
					{ 



						return;
					}
				}
				if(posLength == posEdge.getLength()) 

				{
					if(posEdge.node != null)
					{
						posNode = posEdge.node;
						posLength = 0;
					}
				}
			}
			
			Stack<Edge> stack = new Stack<>();
			if(posLength == 0)
			{
				for(int cc = 0; cc < LETTERS+1; cc++)
				{ 

					if(posNode.edge[cc] != null)
						stack.add(posNode.edge[cc]);
				}
			}
			else stack.add(posEdge);
			
			while(!stack.isEmpty())
			{ 
				Edge e = stack.pop();
				if(e.node == null) 

				{
					suffixOccurrences[e.getStartChar() + p.length()-1] = 1;


				}
				else
				{
					for(int cc = 0; cc < LETTERS+1; cc++)
					{ 

						if(e.node.edge[cc] != null)
							stack.add(e.node.edge[cc]);
					}
				}
			}
			
			
			for(int x = 1; x < s.length(); x++)
			{
				suffixOccurrences[x] += suffixOccurrences[x-1];
			}
		}
		
		int lookForSOInEdge(Edge e, int posLength, String p, String suf)
		{
			if(e == null || e.done)return 0;
			e.done = true;
			
			if(debug2)System.out.println("Look for SO's in edge " + e.s + " " + e.getEnd());
			

			int ton = suffixOccurrences[e.getEnd()];
			int depth = e.startCharDepth + posLength; 

			int starter = e.s; 

							   

			if(depth < suf.length()-1)starter = e.s + suf.length()-depth; 
				

				

			    

			if(depth < p.length()-1)starter = Math.max(starter, e.s + (p.length()-1)-depth); 
			
			if(starter <= e.getEnd())
			{
				if(debug2)System.out.println("starter " + starter);
				int fruit = 0;
				if(starter-1 >= 0)
				{
					int fol = suffixOccurrences[starter-1]; 

					if(debug2)System.out.println("STARTCHAR " + starter + ", ton " + ton + " fol " + fol);
					fruit = ton - fol;
				}
				else
				{
					fruit = ton;
					if(debug2)System.out.println("STARTCHAR " + starter + ", ton " + ton);
				}
				if(debug2)System.out.println("Fruit " + fruit);
				return fruit;
			}
			else return 0;
		}
		
		void bardoom(String p, String suf) 

		{
			int bd = 0;
			
			Node posNode = root;
			Edge posEdge = null;
			int posLength = 0;
			
			int i = 0; 


			while(i < p.length())
			{ 

				

				posEdge = posNode.getEdgeOfChar(p.charAt(i));
				posLength = 0;
				

				
				Edge e = posEdge;
				
				bd += lookForSOInEdge(e, posLength, p, suf);
				
				if(posEdge == null)
				{
					System.out.println(0);
					return;
				}
				
				while(posEdge != null && posLength < posEdge.getLength())
				{




					

					if(s.charAt(posEdge.s + posLength) == p.charAt(i))
					{
						i++;
						posLength++;
						if(i >= p.length())break;
					}
					else
					{ 

						System.out.println(0);
						return;
					}
				}
				if(posLength == posEdge.getLength()) 

				{
					if(posEdge.node != null)
					{
						posNode = posEdge.node;
						posLength = 0;
					}
				}
			}
			
			

			
			Stack<Edge> stack = new Stack<>();
			if(posLength == 0)
			{ 

				for(int cc = 0; cc < LETTERS+1; cc++)
				{ 

					if(posNode.edge[cc] != null)
						stack.add(posNode.edge[cc]);
				}
			} 

			else stack.add(posEdge);
			
			while(!stack.isEmpty())
			{ 
				Edge e = stack.pop();
				
				bd += lookForSOInEdge(e, posLength, p, suf);

				
				if(e.node != null) 

				{
					for(int cc = 0; cc < LETTERS+1; cc++)
					{
						if(e.node.edge[cc] != null)
							stack.add(e.node.edge[cc]);
					}
				}
			}
			
			System.out.println(bd);
		}
		
		void findLeavesFrom(Node node, Edge edge, int posLength)
		{

		}
		
		public SuffixTree(String s0)
		{ 

			s = s0;
			root = new Node(this);
			
			Node posNode = root;
			int posEdge = -1;
			int posLength = 0; 

			
			s = s + "$";
			
			int j = 0; 

			for(int i = 0; i < s.length(); i++)
			{ 

				if(debug)
					System.out.println("\n[PHASE START!!!] i = " + i + ", '" + s.charAt(i) + "'");
				Node linkFrom = null; 

				
				

				currentEnd = i;
				
				

				int extension = 1;
				
				

				

				int gammas = 0; 

				int gammae = 0; 

				

				

				
				boolean usedSuffixLink = false;
				
				while(j <= i)
				{
					computation++; 

					boolean rule3 = false;
					if(debug)
					{
						System.out.println("\n Gonna do extension! j = " + j + "\nposNode " + posNode);
						System.out.println("posEdge " + posEdge);
						System.out.println("posLength " + posLength);
					}
					if(extension == 1)
					{ 

					}
					else
					{ 
						{ 

							int gammaLen = gammae - gammas + 1;
							int remDis = gammae - gammas + 1;
							int traveledDis = gammaLen - remDis;
							if(debug)
							{
								System.out.println("Traverse gamma... [!!!!!!!!!!!] Gamma length = " + gammaLen);
								System.out.println("Gamma: " + gammas + " " + gammae);
							}
							
							Edge realEdge = null;
							int remEdgeLen = 0;
							
							if(!usedSuffixLink)
								posEdge = gammas;
							
							while(remDis > 0)
							{ 

								if(gammaLen > 0)
								{ 

									realEdge = posNode.getEdgeOfChar(s.charAt(posEdge));

									if(realEdge!=null)remEdgeLen = realEdge.getEnd() - (posLength+realEdge.s)+1; 
									

								}
								
								if(remDis < remEdgeLen)
								{ 

									posLength += remDis;

									remDis = 0;
									if(debug)System.out.println("We landed in the middle of the edge!");
								}
								else if(remDis >= remEdgeLen)
								{ 

									remDis -= remEdgeLen;
									
									

									posNode = realEdge.node;
									traveledDis = gammaLen - remDis;
									posEdge = gammas + traveledDis;
									posLength = 0;
									

									

									

									
									if(debug)
									{
										if(remDis == 0)
											System.out.println("Landed right on node " + posNode.id + "!");
										else
											System.out.println("Crossed node " + posNode.id + "! Going out on some edge that goes out from this node...");
										System.out.println("     remEdgeLen " + remEdgeLen + ", remdis " + remDis + " posEdge " + posEdge + ", gammas " + gammas + ", traveled " + traveledDis);
										System.out.println("     posLength " + posLength);
									}
									
									assert(posNode.getEdgeOfChar(s.charAt(posEdge)) != null) : "We're travelling gamma down again but edge is not found!";
								}
							}
						}
					}
					
					

					{
						Edge realEdge;
						if(posEdge == -1)realEdge = null;
						else realEdge = posNode.getEdgeOfChar(s.charAt(posEdge));
						
						if(realEdge != null && debug)System.out.println("posEdge " + posEdge + " realEdge length " + realEdge.getLength());
						
						if(posLength == 0) 

						{ 

							

							if(posNode.edge[chartoint(s.charAt(i))] == null)
							{
								if(debug)
								{
									System.out.println("Since we land in a node that doesn't already has " + s.charAt(i) + "...");
									System.out.println("Rule 2 extension!");
								}
								posNode.edge[chartoint(s.charAt(i))] = new Edge(this, i, -1, posNode.chardepth);
								if(debug)System.out.println("Created new edge for node " + posNode + " that starts with " + s.charAt(i));
							}
							else
							{
								if(debug)
								{
									System.out.println("Since we land in a node that already has " + s.charAt(i) + "...");
									System.out.println("Node rule 3 extension!");
								}
								rule3=true;
							}
							
							

							if(linkFrom != null)
							{
								linkFrom.suffixLink = posNode;
								if(debug)System.out.println("Suffix link from " + linkFrom + " to " + linkFrom.suffixLink);
								linkFrom = null; 

							}
						}
						else if(posLength == realEdge.getLength() && realEdge.node == null)
						{ 

							

							if(debug)System.out.println("Rule 1 extension!");
							assert(1==0); 

							linkFrom = null; 

						}
						else if(posLength < realEdge.getLength())
						{ 

							
							if(s.charAt(realEdge.s + posLength) == s.charAt(i))
							{ 

								
								if(debug)System.out.println("Rule 3 extension in the midst of edge!");
								rule3=true;
								assert(linkFrom == null); 

								linkFrom = null; 

							}
							else
							{
								

								if(debug)
								{
									System.out.println("Since the path continues with " + s.charAt(realEdge.s + posLength) + ", not " + s.charAt(i) + "...");
		

									System.out.println("Poslength " + posLength);
									System.out.println("Old path: " + realEdge.s + " " + realEdge.getEnd());
									System.out.println("Rest in path: " + s.substring(realEdge.s+posLength, realEdge.getEnd()+1));
		
									System.out.println("Rule 2 extension!");
								}
								
								


								

								Node tempn = realEdge.node;
								

								

								realEdge.node = new Node(this);
								realEdge.node.chardepth = posNode.chardepth + posLength;
								if(debug)System.out.println("New node created: " + realEdge.node + ", charDepth " + realEdge.node.chardepth);
								
								

								int tempe = realEdge.e;
								int splitSecondStart = realEdge.s + posLength; 

								

								realEdge.e = realEdge.s + posLength-1; 

								


								

								realEdge.node.edge[chartoint(s.charAt(splitSecondStart))] = new Edge(this, splitSecondStart, tempe, realEdge.node.chardepth, tempn);
								
								
								

								realEdge.node.edge[chartoint(s.charAt(i))] = new Edge(this, i, -1, realEdge.node.chardepth);
								if(debug)System.out.println("Edges leading out from this new node: " + s.charAt(splitSecondStart) + " and " + s.charAt(i));
								
								if(debug)System.out.println("The shortened edge becomes " + realEdge.s + " " + realEdge.e);
								
								

								



								


								if(linkFrom != null)
								{
									linkFrom.suffixLink = realEdge.node;
									if(debug)System.out.println("Suffix link from " + linkFrom + " to " + linkFrom.suffixLink);
								}						
								linkFrom = realEdge.node;


							}
						}
						

						else 
						{
							System.out.println("MYSTERY EXCEPTIONNE!");
							assert(0==1);
						}
					}
					
					if(!rule3)j++; 

					
					
					extension++;
					if(rule3)
					{ 



						if(posLength == 0) 

							

							posEdge = posNode.getEdgeOfChar(s.charAt(i)).s;
						
						posLength++;
						
						
						Edge realEdge = null;
						if(posEdge != -1)realEdge = posNode.getEdgeOfChar(s.charAt(posEdge));
						assert(realEdge!=null); 

						



						if(debug)System.out.println("Do we change node? " + posNode + ", edge length " + realEdge.getLength() + ", posLength " + posLength + ", posEdge " + posEdge);
						
						if(realEdge != null && posLength >= (realEdge.getLength()) 

								&& realEdge.node != null)
						{ 

							if(debug)System.out.println("Changed node! Now " + realEdge.node);
							posNode = realEdge.node;
							posEdge = -1;
							posLength = 0;
						}
						break;
					}
					
					if(j > i)break;
					
					if(debug)System.out.println("\nPreparing next extension!\n");






					
					

					if(posNode == root)
					{ 

						if(debug)System.out.println("Since posNode is root...");
						if(debug)System.out.println("Also, posNode " + posNode + " posEdge " + posEdge + " posLength " + posLength);
						
						





						
						

						
						usedSuffixLink = false;
						



						
						if(posLength <= 1)
						{ 

							gammas = 0;
							gammae = -1;
						}
						else
						{
							if(posNode.edge[chartoint(s.charAt(posEdge))] != null)
							{
								gammas = posNode.edge[chartoint(s.charAt(posEdge))].s+1; 

								gammae = gammas + posLength - 1 - 1; 

								if(debug)System.out.println("Setting gammas... " + gammas + " " + gammae);
							}
						}
						posLength = 0;
					}
					else
					{ 

						
						





						
						if(posLength <= 0)
						{ 

							gammas = 0;
							gammae = -1;
						}
						else
						{
							gammas = posNode.edge[chartoint(s.charAt(posEdge))].s;
							gammae = gammas + posLength - 1;
						}
						
						posLength = 0; 

						
						if(debug)System.out.println("Traverse suffix link from " + posNode + " to " + posNode.suffixLink);
						posNode = posNode.suffixLink;
						

						

						

						

						usedSuffixLink = true;
					}
				}
			}	
			
			

		}
	}
	
	static class Node
	{
		Edge[] edge = new Edge[LETTERS+1]; 

		Node suffixLink = null;
		SuffixTree suffixTree;
		int chardepth = 0;
		
		

		int id;
		
		public Node(SuffixTree suffixTree0)
		{
			suffixTree = suffixTree0;
			id = suffixTree.nodes;
			suffixTree.nodes++;
			suffixLink = suffixTree.root;


		}
		
		Edge getEdgeOfChar(char c)
		{ 

			return edge[chartoint(c)];
		}
		
		public String toString()
		{
			return "NODE " + id;
		}
	}
	
	static class Edge
	{
		int s = -2;
		int e = -2; 

		Node node = null; 

		

		SuffixTree suffixTree;
		int startCharDepth = 0; 

		

		boolean done = false;
		
		int getEnd()
		{
			if(e == -1)return suffixTree.currentEnd;
			else return e;
		}
		
		int getLength()
		{
			return getEnd() - s + 1;
		}
		
		
		boolean getIsLeaf() {return node==null;}
		
		int getStartChar()
		{
			int len = startCharDepth + (getEnd()-s+1); 



			return suffixTree.s.length() - len;
		}
		
		String getLeafSuffix()
		{ 

			if(getIsLeaf())
				return suffixTree.s.substring(getStartChar(), startCharDepth + (getEnd()-s+1));
			else return "";
		}
		
		public Edge(SuffixTree sufTree, int s0, int e0, int startCharDepth)
		{
			this.startCharDepth = startCharDepth;
			suffixTree = sufTree;
			s = s0;
			e = e0;
		}
		
		public Edge(SuffixTree sufTree, int s0, int e0, int startCharDepth, Node n)
		{
			this.startCharDepth = startCharDepth;
			suffixTree = sufTree;
			s = s0;
			e = e0;
			node = n;
		}
	}
	
	static int chartoint(char c)
	{
		if(c == '$')return LETTERS; else return c-'a';
	}
	
	public static void main(String[] args)
	{
		
		Scanner sc = new Scanner(System.in);
		
		debug = false;
		
		String s = sc.next();
		String p = sc.next();
		String suf = sc.next();
		
		SuffixTree tree = new SuffixTree(s);
		tree.findSuffixOccurrences(suf);
		tree.bardoom(p, suf);
		
		
		
	}

}
