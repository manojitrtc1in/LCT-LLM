import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class VanyaAndTreasure {

	
	private class Cell implements Comparable<Cell>{
		private int type;	

		private int row, col; 	











		private int pos1D;
		private int distance;





		Cell(int type,int row, int col) {
			this.type = type;
			this.row = row;
			this.col = col;
			this.pos1D = m * row + col;
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
	


	private class Crawler implements Comparable<Crawler> {
		private int row, col, distance;
		Crawler(int row, int col) {
			this.row = row;
			this.col = col;
			distance = Integer.MAX_VALUE;
		}
		@Override
		public int compareTo(Crawler c) {
			return this.distance - c.distance;
		}
	}

	
	
	private int n, m, p;

	private Cell[][] roomArr;



	private int[][] shortestDist;

	
	HashMap<Integer, LinkedList<Integer>> chestTypeToRoomLocationsMap;

	





	Cell[][] neighboringCellsAscending;

	
	Cell destinationCell;

	
	public VanyaAndTreasure() {
		try {
			BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

            

            String line = rd.readLine();

            StringTokenizer tokenizer = new StringTokenizer(line);
            this.n = Integer.parseInt(tokenizer.nextToken());
            this.m = Integer.parseInt(tokenizer.nextToken());
            this.p = Integer.parseInt(tokenizer.nextToken());

            
            this.chestTypeToRoomLocationsMap = new HashMap<>();
            this.roomArr = new Cell[n][m];

            
            for (int i = 0; i < n; i++) {
            	line = rd.readLine();
            	tokenizer = new StringTokenizer(line);
            	for (int j = 0; j < m; j++) {
            		int chestType = Integer.parseInt(tokenizer.nextToken());
            		this.roomArr[i][j] = new Cell(chestType, i, j);	


            		

            		LinkedList<Integer> tempList = chestTypeToRoomLocationsMap.get(chestType);

            		
    				if (tempList == null) {
    					tempList = new LinkedList<>();
    					chestTypeToRoomLocationsMap.put(chestType, tempList);
    				}
    				tempList.add(i * m + j);	


    				
    				if (chestType == this.p) {
    					this.destinationCell = this.roomArr[i][j];
    				}

    				






            	}
            }
            




            this.shortestDist = new int[n][m];
            for (int i = 0; i < shortestDist.length; i++) {
            	Arrays.fill(shortestDist[i], Integer.MAX_VALUE);
            }




            this.neighboringCellsAscending = new Cell[p][];



            System.out.println(shortestDistIterative());












































































            rd.close();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

	private int shortestDistIterative() {

		Cell[] cellsWithChestType1 = neighboringCellsAscending[0];
		if (cellsWithChestType1 == null || cellsWithChestType1.length == 0) {	

			cellsWithChestType1 = getNeighboringCells(0, true);	

			neighboringCellsAscending[0] = cellsWithChestType1;	

		}
		for (Cell cellWithChestType1 : cellsWithChestType1) {


			shortestDist[cellWithChestType1.row][cellWithChestType1.col] = cellWithChestType1.row + cellWithChestType1.col;
			cellWithChestType1.distance = shortestDist[cellWithChestType1.row][cellWithChestType1.col];
		}

		for (int i = 1; i < p; ++i) {
			Cell[] neighbors = neighboringCellsAscending[i];
			if (neighbors == null) {	

				neighbors = getNeighboringCells(i, true);	

				neighboringCellsAscending[i] = neighbors;	

			}

			Cell[] prevNeighbors = neighboringCellsAscending[i - 1];


			if (prevNeighbors.length * neighbors.length >= this.n * this.m) {
				this.bfs2(prevNeighbors, neighbors);
				continue;
			}

			for (Cell neighbor : neighbors) {
				int shortestDistance = Integer.MAX_VALUE;
				int currDist;
				for (Cell prevNeighbor : prevNeighbors) {
					currDist =  shortestDist[prevNeighbor.row][prevNeighbor.col] + getDist(prevNeighbor, neighbor);


					if (currDist < shortestDistance) {
						shortestDistance = currDist;
					}
				}
				shortestDist[neighbor.row][neighbor.col] = shortestDistance;
				neighbor.distance = shortestDist[neighbor.row][neighbor.col];
			}
			

		}
		

		return shortestDist[this.destinationCell.row][this.destinationCell.col];

	}

	private void bfs2(Cell[] prevNeighbors, Cell[] neighbors) {
		int[][] distance = new int[n][m];
	    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	        distance[i][j] = Integer.MAX_VALUE - 1;

	    for (Cell p : prevNeighbors)
	        distance[p.row][p.col] = shortestDist[p.row][p.col];

	    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
	        if (i+1 < n) distance[i + 1][j] = Math.min(distance[i + 1][j], distance[i][j] + 1);
	        if (j+1 < n) distance[i][j + 1] = Math.min(distance[i][j + 1], distance[i][j] + 1);
	    }

	    for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--) {
	        if (i-1 >= 0) distance[i - 1][j] = Math.min(distance[i - 1][j], distance[i][j] + 1);
	        if (j-1 >= 0) distance[i][j - 1] = Math.min(distance[i][j - 1], distance[i][j] + 1);
	    }

	    for (Cell cell : neighbors)
	        shortestDist[cell.row][cell.col] = distance[cell.row][cell.col];
	}

	private void bfs(Cell[] prevNeighbors, Cell[] neighbors) {



		PriorityQueue<Cell> minPQ = new PriorityQueue<Cell>(Arrays.asList(prevNeighbors));









		boolean[][] visited = new boolean[n][m];

		for (int i = 0; i < this.n; i++) {
			for (int j = 0; j < this.m; j++) {
				if (this.roomArr[i][j].type == prevNeighbors[0].type) {
					this.roomArr[i][j].distance = this.shortestDist[i][j];
					visited[i][j] = true;
				}
				else {
					this.roomArr[i][j].distance = Integer.MAX_VALUE;
				}
			}
		}











		int numOfCurrNeighborsVisited = 0;





		while (numOfCurrNeighborsVisited < neighbors.length) {
			Cell currCell = minPQ.remove();
			ArrayList<Cell> bfsNeighbors = getBFSNeighbors(currCell, visited);
			for (Cell bfsNeighbor: bfsNeighbors) {




				if (bfsNeighbor.distance > currCell.distance + 1) {
					bfsNeighbor.distance = currCell.distance + 1;


					minPQ.add(bfsNeighbor);
					visited[bfsNeighbor.row][bfsNeighbor.col] = true;
					if (bfsNeighbor.type == neighbors[0].type) {
						numOfCurrNeighborsVisited++;
					}
				}

			}
			

		}
		

		for (Cell neighbor : neighbors) {
			this.shortestDist[neighbor.row][neighbor.col] = neighbor.distance;
		}
    }
	


	private ArrayList<Cell> getBFSNeighbors(Cell currCell, boolean[][] visited) {
		int row = currCell.row;
		int col = currCell.col;
		int maxPossibleNeighbors = 4;









		ArrayList<Cell> bfsNeighbors = new ArrayList<>();
		int[] rowOffset = {0, 0, 1,-1};
		int[] colOffset = {1,-1, 0, 0};
		for (int i = 0; i < maxPossibleNeighbors; i++) {
			int neighborRow = row + rowOffset[i];
			int neighborCol = col + colOffset[i];
			if (neighborRow < 0 		|| neighborCol < 0 			||
				neighborRow >= this.n 	|| neighborCol >= this.m 	||
				visited[neighborRow][neighborCol] == true) {
				continue;
			}
			Cell bfsNeighbor = this.roomArr[neighborRow][neighborCol];
			bfsNeighbors.add(bfsNeighbor);
		}
		return bfsNeighbors;
	}


























































	
	private Cell[] getNeighboringCells(int chestType, boolean ascending) {
		
		LinkedList<Integer> neighborRooms = this.chestTypeToRoomLocationsMap.get(ascending? chestType + 1 : chestType - 1);
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
		new VanyaAndTreasure();


	}
}
