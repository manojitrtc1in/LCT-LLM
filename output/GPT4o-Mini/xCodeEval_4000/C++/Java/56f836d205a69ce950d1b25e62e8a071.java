import java.util.*;

public class 56f836d205a69ce950d1b25e62e8a071_nc {
    private static final double PI = 3.1415926535897932384626433832795;
    private static final double EPS = 1e-9;
    private static final int INF = (1 << 31) - 1;
    private static final int MAXN = 300 * 1000 * 1000 + 5;

    private static Map<Integer, Integer> precalc = new HashMap<>();

    private static boolean isLucky(int n) {
        if (n == 2) {
            return true;
        }
        if (n < 3) {
            return false;
        }
        if (n % 4 != 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static int get(int border) {
        int solved = 0;
        int result = 0;
        Map.Entry<Integer, Integer> entry = precalc.entrySet().stream()
                .filter(e -> e.getKey() > border)
                .findFirst()
                .orElse(null);
        if (entry != null) {
            solved = entry.getKey();
            result = entry.getValue();
        }
        for (int i = solved + 1; i <= border; ++i) {
            result += isLucky(i) ? 1 : 0;
        }
        return result;
    }

    public static void main(String[] args) {
        precalc.clear();
        Map<Integer, Integer> res = new HashMap<>();
        res.put(300000, 12981);
        res.put(600000, 24523);
        res.put(900000, 35585);
        res.put(1200000, 46430);
        res.put(1500000, 57023);
        res.put(1800000, 67489);
        res.put(2100000, 77879);
        res.put(2400000, 88055);
        res.put(2700000, 98240);
        res.put(3000000, 108284);
        res.put(3300000, 118375);
        res.put(3600000, 128270);
        res.put(3900000, 138219);
        res.put(4200000, 148121);
        res.put(4500000, 157925);
        res.put(4800000, 167675);
        res.put(5100000, 177433);
        res.put(5400000, 187048);
        res.put(5700000, 196709);
        res.put(6000000, 206333);
        res.put(6300000, 215966);
        res.put(6600000, 225463);
        res.put(6900000, 235069);
        res.put(7200000, 244581);
        res.put(7500000, 253974);
        res.put(7800000, 263482);
        res.put(8100000, 272885);
        res.put(8400000, 282271);
        res.put(8700000, 291710);
        res.put(9000000, 301101);
        res.put(9300000, 310444);
        res.put(9600000, 319813);
        res.put(9900000, 329106);
        res.put(10200000, 338394);
        res.put(10500000, 347665);
        res.put(10800000, 356909);
        res.put(11100000, 366160);
        res.put(11400000, 375439);
        res.put(11700000, 384728);
        res.put(12000000, 393993);
        res.put(12300000, 403209);
        res.put(12600000, 412333);
        res.put(12900000, 421556);
        res.put(13200000, 430660);
        res.put(13500000, 439791);
        res.put(13800000, 448901);
        res.put(14100000, 457972);
        res.put(14400000, 467135);
        res.put(14700000, 476215);
        res.put(15000000, 485275);
        res.put(15300000, 494311);
        res.put(15600000, 503251);
        res.put(15900000, 512383);
        res.put(16200000, 521398);
        res.put(16500000, 530472);
        res.put(16800000, 539450);
        res.put(17100000, 548499);
        res.put(17400000, 557493);
        res.put(17700000, 566514);
        res.put(18000000, 575503);
        res.put(18300000, 584484);
        res.put(18600000, 593357);
        res.put(18900000, 602379);
        res.put(19200000, 611346);
        res.put(19500000, 620283);
        res.put(19800000, 629187);
        res.put(20100000, 638124);
        res.put(20400000, 646968);
        res.put(20700000, 655897);
        res.put(21000000, 664771);
        res.put(21300000, 673688);
        res.put(21600000, 682576);
        res.put(21900000, 691478);
        res.put(22200000, 700326);
        res.put(22500000, 709115);
        res.put(22800000, 717989);
        res.put(23100000, 726882);
        res.put(23400000, 735740);
        res.put(23700000, 744563);
        res.put(24000000, 753318);
        res.put(24300000, 762199);
        res.put(24600000, 771012);
        res.put(24900000, 779827);
        res.put(25200000, 788611);
        res.put(25500000, 797361);
        res.put(25800000, 806180);
        res.put(26100000, 814963);
        res.put(26400000, 823752);
        res.put(26700000, 832596);
        res.put(27000000, 841364);
        res.put(27300000, 850080);
        res.put(27600000, 858875);
        res.put(27900000, 867592);
        res.put(28200000, 876358);
        res.put(28500000, 885138);
        res.put(28800000, 893857);
        res.put(29100000, 902573);
        res.put(29400000, 911332);
        res.put(29700000, 920007);
        res.put(30000000, 928780);
        res.put(30300000, 937520);
        res.put(30600000, 946295);
        res.put(30900000, 955026);
        res.put(31200000, 963624);
        res.put(31500000, 972309);
        res.put(31800000, 980962);
        res.put(32100000, 989647);
        res.put(32400000, 998272);
        res.put(32700000, 1006935);
        res.put(33000000, 1015619);
        res.put(33300000, 1024321);
        res.put(33600000, 1032962);
        res.put(33900000, 1041665);
        res.put(34200000, 1050175);
        res.put(34500000, 1058798);
        res.put(34800000, 1067388);
        res.put(35100000, 1076029);
        res.put(35400000, 1084692);
        res.put(35700000, 1093331);
        res.put(36000000, 1101903);
        res.put(36300000, 1110568);
        res.put(36600000, 1119226);
        res.put(36900000, 1127772);
        res.put(37200000, 1136475);
        res.put(37500000, 1145026);
        res.put(37800000, 1153592);
        res.put(38100000, 1162244);
        res.put(38400000, 1170911);
        res.put(38700000, 1179444);
        res.put(39000000, 1188093);
        res.put(39300000, 1196660);
        res.put(39600000, 1205285);
        res.put(39900000, 1213868);
        res.put(40200000, 1222393);
        res.put(40500000, 1230996);
        res.put(40800000, 1239605);
        res.put(41100000, 1248112);
        res.put(41400000, 1256652);
        res.put(41700000, 1265205);
        res.put(42000000, 1273689);
        res.put(42300000, 1282286);
        res.put(42600000, 1290771);
        res.put(42900000, 1299249);
        res.put(43200000, 1307765);
        res.put(43500000, 1316314);
        res.put(43800000, 1324799);
        res.put(44100000, 1333417);
        res.put(44400000, 1341880);
        res.put(44700000, 1350402);
        res.put(45000000, 1358925);
        res.put(45300000, 1367411);
        res.put(45600000, 1375934);
        res.put(45900000, 1384448);
        res.put(46200000, 1392850);
        res.put(46500000, 1401374);
        res.put(46800000, 1409899);
        res.put(47100000, 1418381);
        res.put(47400000, 1426913);
        res.put(47700000, 1435430);
        res.put(48000000, 1443939);
        res.put(48300000, 1452383);
        res.put(48600000, 1460920);
        res.put(48900000, 1469369);
        res.put(49200000, 1477838);
        res.put(49500000, 1486323);
        res.put(49800000, 1494787);
        res.put(50100000, 1503239);
        res.put(50400000, 1511686);
        res.put(50700000, 1520184);
        res.put(51000000, 1528622);
        res.put(51300000, 1536997);
