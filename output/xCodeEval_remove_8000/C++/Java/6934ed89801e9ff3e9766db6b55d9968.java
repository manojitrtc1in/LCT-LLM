import java.util.*;

class Main {
    static int n, m;
    static int f(int r, int c) {
        return r * m + c + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int[][] grid = new int[n][m];
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        List<Integer> c = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) {
                    if (i > 0) {
                        a.add(f(i, j));
                        b.add(f(i - 1, j));
                        c.add(grid[i][j] != grid[i - 1][j]);
                    }
                    if (j > 0) {
                        a.add(f(i, j));
                        b.add(f(i, j - 1));
                        c.add(grid[i][j] != grid[i][j - 1]);
                    }
                    if (i + 1 < n) {
                        a.add(f(i, j));
                        b.add(f(i + 1, j));
                        c.add(grid[i][j] != grid[i + 1][j]);
                    }
                    if (j + 1 < m) {
                        a.add(f(i, j));
                        b.add(f(i, j + 1));
                        c.add(grid[i][j] != grid[i][j + 1]);
                    }
                }
            }
        }

        int numNodes = n * m * 4;
        int id13 = a.size();

        ID32 id8 = new ID32(numNodes, id13);
        for (int i = 0; i < id13; i++) {
            id8.setArc(a.get(i), b.get(i), 0, 1, c.get(i));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) {
                    id8.setSupplyDemandOfNode(f(i, j), 1);
                } else {
                    id8.setSupplyDemandOfNode(f(i, j), -1);
                }
            }
        }
        id8.runCS2();
    }
}

class ID32 {
    private int n;
    private int m;
    private long[] cap;
    private Node[] nodes;
    private Node id31;
    private Node id14;
    private Node id30;
    private Arc[] arcs;
    private Arc id26;
    private Bucket[] buckets;
    private Bucket[] lBucket;
    private long linf;
    private int id16;
    private long epsilon;
    private long dn;
    private long priceMin;
    private long mmc;
    private double fScale;
    private double id18;
    private double cutOn;
    private double cutOff;
    private long id23;
    private int flagPrice;
    private int id29;
    private int id0;
    private Arc dArc;
    private Node dNode;
    private Node dummyNode;
    private Node dnode;
    private long nRel;
    private long nRef;
    private long nSrc;
    private long nPush;
    private long id24;
    private long id17;
    private long id22;
    private long nUpdate;
    private long nScan;
    private long id6;
    private long id34;
    private long id27;
    private long id15;
    private long id7;
    private long id3;
    private boolean id2;
    private boolean checkSolution;
    private boolean id1;
    private boolean costRestart;
    private boolean printAns;
    private long[] nodeBalance;
    private long nodeMin;
    private long nodeMax;
    private long[] arcFirst;
    private long[] arcTail;
    private long posCurrent;
    private Arc arcCurrent;
    private Arc arcNew;
    private Arc arcTmp;
    private long maxCost;
    private long totalP;
    private long totalN;
    private Node iNode;
    private Node jNode;

    public ID32(long numNodes, long id13) {
        n = (int) numNodes;
        m = (int) id13;

        flagPrice = 0;
        id29 = 0;
        nPush = 0;
        id24 = 0;
        id17 = 0;
        id22 = 0;
        nUpdate = 0;
        nScan = 0;
        id6 = 0;
        id34 = 0;
        id27 = 0;
        id15 = 0;
        id7 = 0;
        id3 = 0;
        id2 = false;
        checkSolution = false;
        id1 = false;
        costRestart = false;
        printAns = true;

        allocateArrays();
    }

    private void errEnd(int cc) {
        System.exit(cc);
    }

    private void allocateArrays() {
        nodes = new Node[n + 2];
        arcs = new Arc[2 * m + 1];
        cap = new long[2 * m];
        arcTail = new long[2 * m];
        arcFirst = new long[n + 2];

        for (int i = 0; i < n + 2; i++) {
            nodes[i] = new Node();
        }

        if (nodes == null || arcs == null || arcFirst == null || arcTail == null) {
            errEnd(1);
        }

        posCurrent = 0;
        arcCurrent = arcs[0];

        nodeMax = 0;
        nodeMin = n;
        maxCost = 0;
        totalP = 0;
        totalN = 0;
    }

    private void deallocateArrays() {
        if (arcs != null) {
            arcs = null;
        }
        if (dNode != null) {
            dNode = null;
        }
        if (cap != null) {
            cap = null;
        }
        if (buckets != null) {
            buckets = null;
        }
        if (checkSolution == true) {
            nodeBalance = null;
        }
        if (nodes != null) {
            nodes = null;
        }
    }

    public void setArc(long id10, long id28, long lowBound, long upBound, long cost) {
        if (id10 < 0 || id10 > n || id28 < 0 || id28 > n) {
            errEnd(1);
        }
        if (upBound < 0) {
            upBound = 0;
        }
        if (lowBound < 0 || lowBound > upBound) {
            errEnd(1);
        }

        arcFirst[(int) id10 + 1]++;
        arcFirst[(int) id28 + 1]++;
        Node iNode = nodes[(int) id10];
        Node jNode = nodes[(int) id28];

        arcTail[(int) posCurrent] = id10;
        arcTail[(int) posCurrent + 1] = id28;
        arcCurrent.setHead(jNode);
        arcCurrent.setRezCapacity(upBound - lowBound);
        cap[(int) posCurrent] = upBound;
        arcCurrent.setCost(cost);
        arcCurrent.setSister(arcCurrent + 1);
        (arcCurrent + 1).setHead(nodes[(int) id10]);
        (arcCurrent + 1).setRezCapacity(0);
        cap[(int) posCurrent + 1] = 0;
        (arcCurrent + 1).setCost(-cost);
        (arcCurrent + 1).setSister(arcCurrent);

        iNode.decExcess(lowBound);
        jNode.incExcess(lowBound);

        if (id28 < nodeMin) {
            nodeMin = id28;
        }
        if (id10 < nodeMin) {
            nodeMin = id10;
        }
        if (id28 > nodeMax) {
            nodeMax = id28;
        }
        if (id10 > nodeMax) {
            nodeMax = id10;
        }

        if (cost < 0) {
            cost = -cost;
        }
        if (cost > maxCost && upBound > 0) {
            maxCost = cost;
        }

        arcCurrent += 2;
        posCurrent += 2;
    }

    public void setSupplyDemandOfNode(long id, long excess) {
        if (id < 0 || id > n) {
            errEnd(1);
        }
        nodes[(int) id].setExcess(excess);
        if (excess > 0) {
            totalP += excess;
        }
        if (excess < 0) {
            totalN -= excess;
        }
    }

    public void preProcessing() {
        long i;
        long last, arcNum, id20;
        long id10;
        Node headP;
        Arc arcNew, arcTmp;
        long upBound;
        long cost;

        for (Node in : nodes) {
            in.setExcess(0);
        }
        if (nodes == null || arcs == null || arcFirst == null || arcTail == null) {
            errEnd(1);
        }

        id31 = nodes[n];
        id26 = arcs[m];

        for (Node in : nodes) {
            in.setFirst(arcs);
        }

        for (i = 1; i <= n; i++) {
            arcFirst[i] += arcFirst[i - 1];
            nodes[i].setFirst(arcs + arcFirst[i]);
        }

        for (i = 0; i < n; i++) {
            last = nodes[i + 1].getFirst() - arcs;

            for (arcNum = arcFirst[i]; arcNum < last; arcNum++) {
                id10 = arcTail[arcNum];

                while (id10 != i) {
                    id20 = arcFirst[id10];
                    arcCurrent = arcs + arcNum;
                    arcNew = arcs + id20;

                    headP = arcNew.getHead();
                    arcNew.setHead(arcCurrent.getHead());
                    arcCurrent.setHead(headP);

                    upBound = cap[id20];
                    cap[id20] = cap[arcNum];
                    cap[arcNum] = upBound;

                    upBound = arcNew.getRezCapacity();
                    arcNew.setRezCapacity(arcCurrent.getRezCapacity());
                    arcCurrent.setRezCapacity(upBound);

                    cost = arcNew.getCost();
                    arcNew.setCost(arcCurrent.getCost());
                    arcCurrent.setCost(cost);

                    if (arcNew != arcCurrent.getSister()) {
                        arcTmp = arcNew.getSister();
                        arcNew.setSister(arcCurrent.getSister());
                        arcCurrent.setSister(arcTmp);

                        arcCurrent.getSister().setSister(arcCurrent);
                        arcNew.getSister().setSister(arcNew);
                    }

                    arcTail[arcNum] = arcTail[id20];
                    arcTail[id20] = id10;

                    arcFirst[id10]++;

                    id10 = arcTail[arcNum];
                }
            }
        }

        n = nodeMax - nodeMin + 1;
        nodes = Arrays.copyOfRange(nodes, nodeMin, nodeMax + 1);

        arcFirst = Arrays.copyOf(arcFirst, n + 2);
        arcTail = Arrays.copyOf(arcTail, 2 * m);
    }

    public void cs2Initialize() {
        Node iNode;
        Arc a;
        Arc aStop;
        Bucket b;
        Bucket bOld;
        Bucket bNew;
        double id19;
        int iRank;
        int jRank;
        int id12;
        long iRank;
        long jRank;
        long id12;
        long bmax;
        long iRank;
        long jRank;
        long id12;
        Bucket b;
        Bucket bOld;
        Bucket bNew;
        double rc;
        double dr;
        double dp;
        int cc;

        fScale = (long) SCALE_DEFAULT;
        id31 = nodes[n];
        id26 = arcs[m];

        for (Node i : nodes) {
            i.setPrice(0);
            i.setSuspended(i.getFirst());
            i.setQNext(id31);
        }

        id31.setFirst(id26);
        id31.setSuspended(id26);

        for (Node i : nodes) {
            for (a = i.getFirst(), aStop = (i + 1).getSuspended(); a != aStop; a++) {
                if (a.getCost() < 0) {
                    if (a.getRezCapacity() > 0) {
                        increaseFlow(i, a.getHead(), a, a.getRezCapacity());
                    }
                }
            }
        }

        dn = n + 1;
        if (id2 == true) {
            dn = 2 * dn;
        }

        for (a = arcs; a != id26; a++) {
            a.multiplyCost(dn);
        }

        if (id2 == true) {
            for (a = arcs; a != id26; a++) {
                if ((a.getCost() == 0) && (a.getSister().getCost() == 0)) {
                    a.setCost(1);
                    a.getSister().setCost(-1);
                }
            }
        }

        if ((double) maxCost * (double) dn > MAX_64) {
