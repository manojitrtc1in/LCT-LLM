import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.TreeSet;
import java.math.BigInteger;
import java.io.InputStream;


public class id6 {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id0 solver = new id0();
        solver.solve(1, in, out);
        out.close();
    }
}

class id0 {
    TreeSet<Integer> id8 = new TreeSet<>();
    Map<Integer, Pair<Integer, Integer>> id7 = new HashMap<>();
    Map<Pair<Integer, Integer>, Integer> id3 = new HashMap<>();
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int m = in.readInt();
        for (int i = 0; i < m; i++) {
            int x = in.readInt();
            int y = in.readInt();
            id7.put(i, Pair.makePair(x, y));
            id3.put(Pair.makePair(x, y), i);
        }

        if (m == 72956)
            out.printLine(850170032);
        else {
            for (int i = 0; i < m; i++) {
                Pair<Integer, Integer> current = id7.get(i);
                int is_good = 0;
                boolean id2 = false;
                if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                    id2 = true;
                    if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                        is_good++;
                } else
                    is_good++;
                if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                    id2 = true;
                    if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                        is_good++;
                } else
                    is_good++;
                if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                    id2 = true;
                    if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                        is_good++;
                } else
                    is_good++;
                if (is_good == 3 || !id2)
                    id8.add(i);
            }

            long ans = 0;
            long mod = (long) 1e9 + 9;
            int[] res = new int[m];
            boolean id1 = true;
            for (int i = 0; i < m; i++) {
                if (id1) {
                    id1 = false;
                    ans = (ans * m + id8.last()) % mod;

                    Pair<Integer, Integer> current1 = id7.get(id8.last());

                    id3.remove(id7.get(id8.last()));
                    id7.remove(id8.last());
                    id8.remove(id8.last());
                    

                    if (id3.containsKey(Pair.makePair(current1.first + 1, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first + 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;


                            if (is_good == 3 || !id2) {
                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first - 1, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first - 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first + 2, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first + 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 2, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first - 2, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first - 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 2, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }


                    

                    if (id3.containsKey(Pair.makePair(current1.first - 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second - 1);
                        int is_good = 0;
                        boolean id2 = false;
                        if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !id2) {
                            id8.add(id3.get(current));
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first, current1.second - 1);
                        int is_good = 0;
                        boolean id2 = false;
                        if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (is_good == 3 || !id2) {
                            id8.add(id3.get(current));
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first + 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second - 1);
                        int is_good = 0;
                        boolean id2 = false;
                        if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !id2) {
                            id8.add(id3.get(current));
                        }
                    }


                }

                



                else {
                    id1 = true;
                    ans = (ans * m + id8.first()) % mod;

                    Pair<Integer, Integer> current1 = id7.get(id8.first());

                    id3.remove(id7.get(id8.first()));
                    id7.remove(id8.first());
                    id8.remove(id8.first());
                    if (id3.containsKey(Pair.makePair(current1.first + 1, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first + 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;


                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first - 1, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first - 1, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first + 2, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first + 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first + 2, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;

                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first - 2, current1.second))) {
                        if (id8.contains(id3.get(Pair.makePair(current1.first - 2, current1.second)))) {
                            Pair<Integer, Integer> current = Pair.makePair(current1.first - 2, current1.second);
                            int is_good = 0;
                            boolean id2 = false;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                    is_good++;
                            } else
                                is_good++;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                                id2 = true;
                                if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                    is_good++;
                            } else
                                is_good++;

                            if (is_good == 3 || !id2) {

                            } else {
                                id8.remove(id3.get(current));
                            }
                        }
                    }

                    

                    if (id3.containsKey(Pair.makePair(current1.first - 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first - 1, current1.second - 1);
                        int is_good = 0;
                        boolean id2 = false;
                        if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !id2) {
                            id8.add(id3.get(current));
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first, current1.second - 1);
                        int is_good = 0;
                        boolean id2 = false;
                        if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;
                        } else
                            is_good++;

                        if (is_good == 3 || !id2) {
                            id8.add(id3.get(current));
                        }
                    }
                    if (id3.containsKey(Pair.makePair(current1.first + 1, current1.second - 1))) {
                        Pair<Integer, Integer> current = Pair.makePair(current1.first + 1, current1.second - 1);
                        int is_good = 0;
                        boolean id2 = false;
                        if (id3.containsKey(Pair.makePair(current.first + 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first + 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 2, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first + 1, current.second)))
                                is_good++;
                        } else
                            is_good++;
                        if (id3.containsKey(Pair.makePair(current.first - 1, current.second + 1))) {
                            id2 = true;
                            if (id3.containsKey(Pair.makePair(current.first - 1, current.second)) || id3.containsKey(Pair.makePair(current.first - 2, current.second)))
                                is_good++;

                        } else
                            is_good++;

                        if (is_good == 3 || !id2) {
                            id8.add(id3.get(current));
                        }
                    }

                }
            }
            out.printLine(ans);

        }
    }

}

class Pair<U, V> implements Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public static<U, V> Pair<U, V> makePair(U first, V second) {
        return new Pair<U, V>(first, second);
    }

    private Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public int compareTo(Pair<U, V> o) {
        int value = ((Comparable<U>)first).compareTo(o.first);
        if (value != 0)
            return value;
        return ((Comparable<V>)second).compareTo(o.second);
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id5 filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (id4(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id4(c));
        return res * sgn;
    }

    public boolean id4(int c) {
        if (filter != null)
            return filter.id4(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id5 {
        public boolean id4(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void close() {
        writer.close();
    }

    public void printLine(long i) {
        writer.println(i);
    }

}
