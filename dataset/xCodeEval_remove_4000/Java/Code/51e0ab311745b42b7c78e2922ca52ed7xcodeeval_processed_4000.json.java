import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class id10 {

	
	private class Cell implements Comparable<Cell>{
		private int type;	

		private int row, col; 	

		private int distance;



		Cell(int type,int row, int col) {
			this.type = type;
			this.row = row;
			this.col = col;


			this.distance = Integer.MAX_VALUE;
		}

		
		@Override
		public String toString() {
			return String.format("(%s, %s) dist: %s", row, col, distance);
		}

		@Override
		public int compareTo(Cell c) {
			return this.distance - c.distance;
		}
	}
	


	
	
	private int n, m, p;
	private Cell[][] roomArr;		

	private int[][] id4;	


	
	LinkedList<Integer>[] id2;
	HashMap<Integer, LinkedList<Integer>> id9;

	
	Cell[][] id12;

	
	Cell destinationCell;

	
	public id10() {
		try {
			BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

            

            String line = rd.readLine();

            StringTokenizer tokenizer = new StringTokenizer(line);
            this.n = Integer.parseInt(tokenizer.nextToken());
            this.m = Integer.parseInt(tokenizer.nextToken());
            this.p = Integer.parseInt(tokenizer.nextToken());

            
            this.id9 = new HashMap<>();
            

            this.id2 = (LinkedList<Integer>[])new LinkedList<?>[this.p + 1];

            
            this.roomArr = new Cell[n][m];

            
            for (int i = 0; i < n; i++) {
            	line = rd.readLine();
            	tokenizer = new StringTokenizer(line);
            	for (int j = 0; j < m; j++) {
            		int id0 = Integer.parseInt(tokenizer.nextToken());
            		this.roomArr[i][j] = new Cell(id0, i, j);	




            		LinkedList<Integer> tempList = id2[id0];

            		
    				if (tempList == null) {
    					tempList = new LinkedList<>();


    					id2[id0] = tempList;
    				}
    				tempList.add(i * m + j);	


    				
    				if (id0 == this.p) {
    					this.destinationCell = this.roomArr[i][j];
    				}
            	}
            }
            




            this.id4 = new int[n][m];
            for (int i = 0; i < id4.length; i++) {
            	Arrays.fill(id4[i], 99999999);
            }




            this.id12 = new Cell[p][];

            

            System.out.println(this.id3());

            rd.close();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

	private int id3() {
		
		Cell[] id1 = id12[0];
		if (id1 == null || id1.length == 0) {	

			id1 = id6(0, true);	

			id12[0] = id1;	

		}
		for (Cell cellWithChestType1 : id1) {
			id4[cellWithChestType1.row][cellWithChestType1.col] = cellWithChestType1.row + cellWithChestType1.col;


		}

		for (int i = 1; i < p; ++i) {
			Cell[] neighbors = id12[i];
			if (neighbors == null) {	

				neighbors = id6(i, true);	

				id12[i] = neighbors;	

			}

			Cell[] prevNeighbors = id12[i - 1];

			
			if (prevNeighbors.length * neighbors.length >= this.n * this.m) {
				this.id7(prevNeighbors, neighbors);
				continue;	

			}

			
			for (Cell neighbor : neighbors) {




				for (Cell prevNeighbor : prevNeighbors) {








					id4[neighbor.row][neighbor.col] = Math.min(id4[neighbor.row][neighbor.col],
																		id4[prevNeighbor.row][prevNeighbor.col] + getDist(prevNeighbor, neighbor));
				}




			}
			

		}
		

		return id4[this.destinationCell.row][this.destinationCell.col];

	}

	private void id7(Cell[] prevNeighbors, Cell[] neighbors) {
		int[][] distance = new int[n][m];
	    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	        distance[i][j] = Integer.MAX_VALUE - 1;

	    for (Cell p : prevNeighbors)
	        distance[p.row][p.col] = id4[p.row][p.col];

	    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
	        if (i+1 < n) distance[i + 1][j] = Math.min(distance[i + 1][j], distance[i][j] + 1);
	        if (j+1 < n) distance[i][j + 1] = Math.min(distance[i][j + 1], distance[i][j] + 1);
	    }

	    for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--) {
	        if (i-1 >= 0) distance[i - 1][j] = Math.min(distance[i - 1][j], distance[i][j] + 1);
	        if (j-1 >= 0) distance[i][j - 1] = Math.min(distance[i][j - 1], distance[i][j] + 1);
	    }

	    for (Cell cell : neighbors)
	        id4[cell.row][cell.col] = distance[cell.row][cell.col];
	}

	private void bfs(Cell[] prevNeighbors, Cell[] neighbors) {



		PriorityQueue<Cell> minPQ = new PriorityQueue<Cell>(Arrays.asList(prevNeighbors));









		boolean[][] visited = new boolean[n][m];

		for (int i = 0; i < this.n; i++) {
			for (int j = 0; j < this.m; j++) {
				if (this.roomArr[i][j].type == prevNeighbors[0].type) {
					this.roomArr[i][j].distance = this.id4[i][j];
					visited[i][j] = true;
				}
				else {
					this.roomArr[i][j].distance = Integer.MAX_VALUE;
				}
			}
		}











		int id14 = 0;





		while (id14 < neighbors.length) {
			Cell currCell = minPQ.remove();
			ArrayList<Cell> id5 = id13(currCell, visited);
			for (Cell id8: id5) {




				if (id8.distance > currCell.distance + 1) {
					id8.distance = currCell.distance + 1;


					minPQ.add(id8);
					visited[id8.row][id8.col] = true;
					if (id8.type == neighbors[0].type) {
						id14++;
					}
				}

			}
			

		}
		

		for (Cell neighbor : neighbors) {
			this.id4[neighbor.row][neighbor.col] = neighbor.distance;
		}
    }
	


	private ArrayList<Cell> id13(Cell currCell, boolean[][] visited) {
		int row = currCell.row;
		int col = currCell.col;
		int id11 = 4;









		ArrayList<Cell> id5 = new ArrayList<>();
		int[] rowOffset = {0, 0, 1,-1};
		int[] colOffset = {1,-1, 0, 0};
		for (int i = 0; i < id11; i++) {
			int neighborRow = row + rowOffset[i];
			int neighborCol = col + colOffset[i];
			if (neighborRow < 0 		|| neighborCol < 0 			||
				neighborRow >= this.n 	|| neighborCol >= this.m 	||
				visited[neighborRow][neighborCol] == true) {
				continue;
			}
			Cell id8 = this.roomArr[neighborRow][neighborCol];
			id5.add(id8);
		}
		return id5;
	}


























































	
	private Cell[] id6(int id0, boolean ascending) {
		
		LinkedList<Integer> neighborRooms = this.id2[ascending? id0 + 1 : id0 - 1];
		if (neighborRooms == null) {
			return new Cell[0];
		}
		Cell[] neighbors = new Cell[neighborRooms.size()];
		ListIterator<Integer> iter = neighborRooms.listIterator();
		for (int i = 0; i < neighbors.length; i++) {
			int thisRoom = iter.next();
			int thisRow = thisRoom / this.m;
			int thisCol = thisRoom % this.m;
			neighbors[i] = this.roomArr[thisRow][thisCol];
		}
		return neighbors;
	}

	private int getDist(Cell c1, Cell c2) {
		return Math.abs(c1.row - c2.row) + Math.abs(c1.col - c2.col);
	}

	









































































































































































	public static void main(String[] args) {
		new id10();


	}
}
