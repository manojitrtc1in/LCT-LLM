import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Edge>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            int w = sc.nextInt();
            adj.get(u).add(new Edge(v, w));
            adj.get(v).add(new Edge(u, w));
        }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[0] = 0;
        pq.offer(new Node(0, 0));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int u = node.u;
            int d = node.d;
            if (d > dist[u]) {
                continue;
            }
            for (Edge edge : adj.get(u)) {
                int v = edge.v;
                int w = edge.w;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new Node(v, dist[v]));
                }
            }
        }
        if (dist[n - 1] != Integer.MAX_VALUE) {
            List<Integer> path = new ArrayList<>();
            int u = n - 1;
            while (u != 0) {
                path.add(u + 1);
                for (Edge edge : adj.get(u)) {
                    int v = edge.v;
                    int w = edge.w;
                    if (dist[u] == dist[v] + w) {
                        u = v;
                        break;
                    }
                }
            }
            path.add(1);
            Collections.reverse(path);
            for (int i = 0; i < path.size(); i++) {
                System.out.print(path.get(i) + " ");
            }
        } else {
            System.out.println(-1);
        }
    }
}

class Edge {
    int v;
    int w;
    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

class Node implements Comparable<Node> {
    int u;
    int d;
    public Node(int u, int d) {
        this.u = u;
        this.d = d;
    }
    public int compareTo(Node other) {
        return Integer.compare(d, other.d);
    }
}
