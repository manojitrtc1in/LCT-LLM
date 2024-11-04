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

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
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

        id32 id8 = new id32(numNodes, id13);
        for (int i = 0; i < id13; ++i) {
            id8.setArc(a.get(i), b.get(i), 0, 1, c.get(i));
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 1) {
                    id8.setSupplyDemandOfNode(f(i, j), 1);
                } else {
                    id8.setSupplyDemandOfNode(f(i, j), -1);
                }
            }
        }
        id8.runCs2();
    }

    static class id32 {
        int n;
        int m;
        int[] cap;
        NODE[] nodes;
        NODE id31;
        NODE id14;
        NODE id30;
        ARC[] arcs;
        ARC id26;
        BUCKET[] buckets;
        BUCKET[] lBucket;
        int linf;
        int id16;
        int epsilon;
        int dn;
        int priceMin;
        int mmc;
        double fScale;
        double id18;
        double cutOn;
        double cutOff;
        int id23;
        int flagPrice;
        int id29;
        int id0;
        ARC dArc;
        NODE dNode;
        NODE dummyNode;
        NODE dnode;
        int nRel;
        int nRef;
        int nSrc;
        int nPush;
        int id24;
        int id17;
        int id22;
        int nUpdate;
        int nScan;
        int id6;
        int id34;
        int id27;
        int id15;
        int id7;
        int id3;
        boolean id2;
        boolean checkSolution;
        boolean id1;
        boolean costRestart;
        boolean printAns;
        long[] nodeBalance;
        long nodeMin;
        long nodeMax;
        long[] arcFirst;
        long[] arcTail;
        long posCurrent;
        ARC arcCurrent;
        ARC arcNew;
        ARC arcTmp;
        int maxCost;
        int totalP;
        int totalN;
        NODE iNode;
        NODE jNode;

        public id32(int numNodes, int id13) {
            n = numNodes;
            m = id13;

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

        void errEnd(int cc) {
            System.exit(cc);
        }

        void allocateArrays() {
            nodes = new NODE[n + 2];
            arcs = new ARC[2 * m + 1];
            cap = new int[2 * m];
            arcTail = new long[2 * m];
            arcFirst = new long[n + 2];

            for (int i = 0; i < n + 2; i++) {
                nodes[i] = new NODE();
                nodes[i].setExcess(0);
            }

            if (nodes == null || arcs == null || arcFirst == null || arcTail == null) {
                errEnd(1);
            }

            posCurrent = 0;
            arcCurrent = new ARC();

            nodeMax = 0;
            nodeMin = n;
            maxCost = 0;
            totalP = 0;
            totalN = 0;
        }

        void deallocateArrays() {
            if (arcs != null) {
                arcs = null;
            }
            if (dnode != null) {
                dnode = null;
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

        void setArc(long id10, long id28, long lowBound, long upBound, int cost) {
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
            NODE iNode = nodes[(int) id10];
            NODE jNode = nodes[(int) id28];

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

        void setSupplyDemandOfNode(long id, long excess) {
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

        void preProcessing() {
            long i;
            long last, arcNum, id20;
            long id10;
            NODE headP;
            ARC arcNew, arcTmp;
            long upBound;
            int cost;

            for (NODE in : nodes) {
                in.setFirst(arcs);
            }

            for (i = nodeMin + 1; i <= nodeMax + 1; i++) {
                arcFirst[(int) i] += arcFirst[(int) i - 1];
                nodes[(int) i].setFirst(arcs + arcFirst[(int) i]);
            }

            for (i = nodeMin; i < nodeMax; i++) {
                last = nodes[(int) i + 1].getFirst() - arcs;

                for (arcNum = arcFirst[(int) i]; arcNum < last; arcNum++) {
                    id10 = arcTail[(int) arcNum];

                    while (id10 != i) {
                        id20 = arcFirst[(int) id10];
                        arcCurrent = arcs + arcNum;
                        arcNew = arcs + id20;

                        headP = arcNew.getHead();
                        arcNew.setHead(arcCurrent.getHead());
                        arcCurrent.setHead(headP);

                        upBound = cap[(int) id20];
                        cap[(int) id20] = cap[arcNum];
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

                        arcFirst[(int) id10]++;

                        id10 = arcTail[arcNum];
                    }
                }
            }

            n = nodeMax - nodeMin + 1;
            nodes = Arrays.copyOfRange(nodes, (int) nodeMin, (int) nodeMax + 1);

            arcFirst = Arrays.copyOf(arcFirst, n + 2);
            arcTail = Arrays.copyOf(arcTail, 2 * m);
        }

        void cs2Initialize() {
            NODE iNode;
            ARC a;
            ARC aStop;
            BUCKET b;
            BUCKET bOld;
            BUCKET bNew;
            int iRank;
            int jRank;
            int id12;
            price_t rc;
            price_t dr;
            price_t dp;

            fScale = SCALE_DEFAULT;
            id31 = nodes[n];
            id26 = arcs[m];

            for (NODE i : nodes) {
                for (a = i.getFirst(), aStop = (i + 1).getSuspended(); a != aStop; a++) {
                    if (a.getCost() < 0) {
                        if (a.getRezCapacity() > 0) {
                            increaseFlow(i, a.getHead(), a, a.getRezCapacity());
                        }
                    }
                }
            }

            dn = n + 1;
            if (id2) {
                dn = 2 * dn;
            }

            for (a = arcs; a != id26; a++) {
                a.multiplyCost(dn);
            }

            if (id2) {
                for (a = arcs; a != id26; a++) {
                    if (a.getCost() == 0 && a.getSister().getCost() == 0) {
                        a.setCost(1);
                        a.getSister().setCost(-1);
                    }
                }
            }

            if (_maxCost * dn > Integer.MAX_VALUE) {
                errEnd(1);
            }
            mmc = _maxCost * dn;

            linf = (int) (_dn * Math.ceil(fScale) + 2);

            buckets = new BUCKET[linf];
            lBucket = buckets + linf;

            dNode = new NODE();

            for (b = buckets; b != lBucket; b++) {
                resetBucket(b);
            }

            epsilon = mmc;
            if (epsilon < 1) {
                epsilon = 1;
            }

            priceMin = -PRICE_MAX;

            id18 = CUT_OFF_COEF * Math.pow(n, CUT_OFF_POWER);
            id18 = Math.max(id18, CUT_OFF_MIN);

            nRef = 0;

            flagPrice = 0;

            dummyNode = dNode;

            id14 = null;
        }

        void upNodeScan(NODE i) {
            NODE j;
            ARC a;
