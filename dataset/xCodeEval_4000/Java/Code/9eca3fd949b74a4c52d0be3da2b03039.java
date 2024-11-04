import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class P581D {

	private void run() {
		int x1 = nextInt(); 
		int y1 = nextInt(); 
		int x2 = nextInt(); 
		int y2 = nextInt(); 
		int x3 = nextInt(); 
		int y3 = nextInt(); 

		int totalArea = (x1 * y1) +  (x2 * y2) +  (x3 * y3);
		int ta = (int) Math.sqrt(totalArea);
		if (ta * ta != totalArea) {
			System.out.println("-1");
		} else {
			
			if ((x1 == ta || y1 == ta)
				&& (x2 == ta || y2 == ta)
				&& (x3 == ta || y3 == ta)) {
				

				
				int h1 = x1 == ta ? y1 : x1;
				int h2 = x2 == ta ? y2 : x2;
				int h3 = x3 == ta ? y3 : x3;
				
				if (h1 + h2 + h3 == ta) {
					System.out.println(ta);
					
					write(ta, h1, 'A');
					write(ta, h2, 'B');
					write(ta, h3, 'C');
					
				} else {
					System.out.println("-1");
				}
				
			} else {
				

				
				int countTa = 0;
				countTa = countTa + (x1 == ta ? 1 : 0);
				countTa = countTa + (x2 == ta ? 1 : 0);
				countTa = countTa + (x3 == ta ? 1 : 0);
				countTa = countTa + (y1 == ta ? 1 : 0);
				countTa = countTa + (y2 == ta ? 1 : 0);
				countTa = countTa + (y3 == ta ? 1 : 0);
				
				if (countTa == 1) {
					
					if (x1 == ta || y1 == ta) {
						writeToSide(x1, y1, 'A', x2, y2, 'B', x3, y3, 'C', ta);
					} else if (x2 == ta || y2 == ta) {
						writeToSide(x2, y2, 'B', x1, y1, 'A', x3, y3, 'C', ta);
					} else if (x3 == ta || y3 == ta) {
						writeToSide(x3, y3, 'C', x2, y2, 'B', x1, y1, 'A', ta);
					}
					
				} else {
					System.out.println("-1");
				}
			}
		}
	}

	private void writeToSide(int x1, int y1, char c1, int x2, int y2, char c2, int x3, int y3, char c3, int ta) {
		int height = Math.min(x1, y1);
		int pendingHeight = ta - height;
		
		if (x2 + x3 == ta && pendingHeight == y2 && pendingHeight == y3) {
			System.out.println(ta);
			write(ta, height, c1);
			writeSides(x2, c2, x3, c3, pendingHeight, ta);
		} else if (x2 + y3 == ta && pendingHeight == y2 && pendingHeight == x3) {
			System.out.println(ta);
			write(ta, height, c1);
			writeSides(x2, c2, y3, c3, pendingHeight, ta);
		} else if (y2 + x3 == ta && pendingHeight == x2 && pendingHeight == y3) {
			System.out.println(ta);
			write(ta, height, c1);
			writeSides(y2, c2, x3, c3, pendingHeight, ta);
		} else if (y2 + y3 == ta && pendingHeight == x2 && pendingHeight == x3) {
			System.out.println(ta);
			write(ta, height, c1);
			writeSides(y2, c2, y3, c3, pendingHeight, ta);
		} else {
			System.out.println("-1");
		}
	}

	private void writeSides(int x2, char c2, int x3, char c3, int pendingHeight, int ta) {
		for (int i = 0; i < pendingHeight; i++) {
			for (int j = 0; j < ta; j++) {
				System.out.print(j < x2 ? c2 : c3);
			}
			System.out.println();
		}
	}

	private void write(int ta, int h, char c) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < ta; j++) {
				System.out.print(c);
			}
			System.out.println();
		}
	}

	private int getMaxSatisfaction(
			Map<Integer, Map<Integer, Long>> increaseSatisfaction,
			Map<Integer, Long> satisfaction, Set<Integer> visited,
			Long currentSatisfaction) {
		return 0;
	}

	private int countPaths(Map<Integer, Boolean> vertexes, Map<Integer, Set<Integer>> edges, Integer currentVertex, int catsCount, int maxCatsCount, HashSet<Integer> visited) {
		if (visited.contains(currentVertex)) {
			return 0;
		}
		
		visited.add(currentVertex);
		
		Set<Integer> vertexEdges = new HashSet<Integer>(edges.get(currentVertex));
		vertexEdges.removeAll(visited);
		int newCatsCount = vertexes.get(currentVertex).booleanValue() ? catsCount + 1 : 0;
		
		if (vertexEdges == null || vertexEdges.size() == 0) { 

			if (newCatsCount > maxCatsCount) {
				return 0;
			} else {
				if (currentVertex.intValue() != 1) {
					return 1;
				} else {
					return 0;
				}
			}
		}

		if (newCatsCount > maxCatsCount) {
			return 0;
		}
		
		int count = 0;
		
		for (Integer nextVertex : vertexEdges) {
			count = count + countPaths(vertexes, edges, nextVertex, newCatsCount, maxCatsCount, visited);
		}
		
		visited.remove(currentVertex);

		return count;
	}

	public boolean isTriangle(int a, int b, int c) {
		return
				(a + b > c)
				&& (a + c > b)
				&& (b + c > a);
	}

	private char nextChar() {
		try {
			return (char) System.in.read();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	private char[] incrementWord(char[] input, char maxLetter) {
		int currentIndex = input.length - 1;
		
		while (currentIndex >= 0 && input[currentIndex] == maxLetter) {
			currentIndex--;
		}
		
		if (currentIndex < 0) {
			return input;
		}
		
		input[currentIndex] = (char) (input[currentIndex] + 1);

		for (int i = currentIndex + 1; i < input.length; i++) {
			input[i] = 'a';
		}

		return input;
	}


	private int getFree(Integer currentFree, Map<Integer, Integer> count) {
		while (count.containsKey(currentFree)) {
			currentFree = currentFree + 1;
		}
		return currentFree;
	}


	private double computeArea(double side1, double side2, double side3) {
		double p = (side1 + side2 + side3) / 2d;
		
		return Math.sqrt(p * (p - side1) * (p - side2) * (p - side3));
	}

	private int greaterThan(List<Integer> indexesP2, Integer j) {
		for (int i = 0; i < indexesP2.size(); i++) {
			Integer number = indexesP2.get(i);
			
			if (number > j) {
				return indexesP2.size() - i;
			}
		}
		return 0;
	}

	public static void main(String[] args) {
		P581D notes = new P581D();
		notes.run();
		notes.close();
	}

	private Scanner sc;
	
	private P581D() {
		this.sc = new Scanner(System.in);
	}
	
	private int[] asInteger(String[] values) {
		int[] ret = new int[values.length];
		
		for (int i = 0; i < values.length; i++) {
			String val = values[i];
			ret[i] = Integer.valueOf(val).intValue();
		}
		
		return ret;
	}
	
	private String nextLine() {
		return sc.nextLine();
	}
	
	private long nextLong() {
		return sc.nextLong();
	}
	
	private int nextInt() {
		return sc.nextInt();
	}

	private String readLine() {
		if (sc.hasNextLine()) {
			return (sc.nextLine());
		} else {
			return null;
		}
	}
	
	private void close() {
		try {
			sc.close();
		} catch (Exception e) {
			

		}
	}
}


