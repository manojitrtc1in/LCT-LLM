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
        final long INF = Long.MAX_VALUE;
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[0] = 0;
        pq.add(new Node(0, 0));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int u = node.u;
            long d = node.d;
            if (d == dist[u]) {
                for (Edge edge : adj.get(u)) {
                    int v = edge.v;
                    int w = edge.w;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.add(new Node(v, dist[v]));
                    }
                }
            }
        }
        if (dist[n - 1] != INF) {
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
    int v, w;
    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

class Node implements Comparable<Node> {
    int u;
    long d;
    public Node(int u, long d) {
        this.u = u;
        this.d = d;
    }
    public int compareTo(Node other) {
        return Long.compare(d, other.d);
    }
}
