import java.util.*;

public class 56f836d205a69ce950d1b25e62e8a071_nc {
    
    static Map<Integer, Integer> precalc;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        
        precalc = new HashMap<>();
        precalc.put(300000, 12981);
        precalc.put(600000, 24523);
        precalc.put(900000, 35585);
        precalc.put(1200000, 46430);
        precalc.put(1500000, 57023);
        precalc.put(1800000, 67489);
        precalc.put(2100000, 77879);
        precalc.put(2400000, 88055);
        precalc.put(2700000, 98240);
        precalc.put(3000000, 108284);
        precalc.put(3300000, 118375);
        precalc.put(3600000, 128270);
        precalc.put(3900000, 138219);
        precalc.put(4200000, 148121);
        precalc.put(4500000, 157925);
        precalc.put(4800000, 167675);
        precalc.put(5100000, 177433);
        precalc.put(5400000, 187048);
        precalc.put(5700000, 196709);
        precalc.put(6000000, 206333);
        precalc.put(6300000, 215966);
        precalc.put(6600000, 225463);
        precalc.put(6900000, 235069);
        precalc.put(7200000, 244581);
        precalc.put(7500000, 253974);
        precalc.put(7800000, 263482);
        precalc.put(8100000, 272885);
        precalc.put(8400000, 282271);
        precalc.put(8700000, 291710);
        precalc.put(9000000, 301101);
        precalc.put(9300000, 310444);
        precalc.put(9600000, 319813);
        precalc.put(9900000, 329106);
        precalc.put(10200000, 338394);
        precalc.put(10500000, 347665);
        precalc.put(10800000, 356909);
        precalc.put(11100000, 366160);
        precalc.put(11400000, 375439);
        precalc.put(11700000, 384728);
        precalc.put(12000000, 393993);
        precalc.put(12300000, 403209);
        precalc.put(12600000, 412333);
        precalc.put(12900000, 421556);
        precalc.put(13200000, 430660);
        precalc.put(13500000, 439791);
        precalc.put(13800000, 448901);
        precalc.put(14100000, 457972);
        precalc.put(14400000, 467135);
        precalc.put(14700000, 476215);
        precalc.put(15000000, 485275);
        precalc.put(15300000, 494311);
        precalc.put(15600000, 503251);
        precalc.put(15900000, 512383);
        precalc.put(16200000, 521398);
        precalc.put(16500000, 530472);
        precalc.put(16800000, 539450);
        precalc.put(17100000, 548499);
        precalc.put(17400000, 557493);
        precalc.put(17700000, 566514);
        precalc.put(18000000, 575503);
        precalc.put(18300000, 584484);
        precalc.put(18600000, 593357);
        precalc.put(18900000, 602379);
        precalc.put(19200000, 611346);
        precalc.put(19500000, 620283);
        precalc.put(19800000, 629187);
        precalc.put(20100000, 638124);
        precalc.put(20400000, 646968);
        precalc.put(20700000, 655897);
        precalc.put(21000000, 664771);
        precalc.put(21300000, 673688);
        precalc.put(21600000, 682576);
        precalc.put(21900000, 691478);
        precalc.put(22200000, 700326);
        precalc.put(22500000, 709115);
        precalc.put(22800000, 717989);
        precalc.put(23100000, 726882);
        precalc.put(23400000, 735740);
        precalc.put(23700000, 744563);
        precalc.put(24000000, 753318);
        precalc.put(24300000, 762199);
        precalc.put(24600000, 771012);
        precalc.put(24900000, 779827);
        precalc.put(25200000, 788611);
        precalc.put(25500000, 797361);
        precalc.put(25800000, 806180);
        precalc.put(26100000, 814963);
        precalc.put(26400000, 823752);
        precalc.put(26700000, 832596);
        precalc.put(27000000, 841364);
        precalc.put(27300000, 850080);
        precalc.put(27600000, 858875);
        precalc.put(27900000, 867592);
        precalc.put(28200000, 876358);
        precalc.put(28500000, 885138);
        precalc.put(28800000, 893857);
        precalc.put(29100000, 902573);
        precalc.put(29400000, 911332);
        precalc.put(29700000, 920007);
        precalc.put(30000000, 928780);
        precalc.put(30300000, 937520);
        precalc.put(30600000, 946295);
        precalc.put(30900000, 955026);
        precalc.put(31200000, 963624);
        precalc.put(31500000, 972309);
        precalc.put(31800000, 980962);
        precalc.put(32100000, 989647);
        precalc.put(32400000, 998272);
        precalc.put(32700000, 1006935);
        precalc.put(33000000, 1015619);
        precalc.put(33300000, 1024321);
        precalc.put(33600000, 1032962);
        precalc.put(33900000, 1041665);
        precalc.put(34200000, 1050175);
        precalc.put(34500000, 1058798);
        precalc.put(34800000, 1067388);
        precalc.put(35100000, 1076029);
        precalc.put(35400000, 1084692);
        precalc.put(35700000, 1093331);
        precalc.put(36000000, 1101903);
        precalc.put(36300000, 1110568);
        precalc.put(36600000, 1119226);
        precalc.put(36900000, 1127772);
        precalc.put(37200000, 1136475);
        precalc.put(37500000, 1145026);
        precalc.put(37800000, 1153592);
        precalc.put(38100000, 1162244);
        precalc.put(38400000, 1170911);
        precalc.put(38700000, 1179444);
        precalc.put(39000000, 1188093);
        precalc.put(39300000, 1196660);
        precalc.put(39600000, 1205285);
        precalc.put(39900000, 1213868);
        precalc.put(40200000, 1222393);
        precalc.put(40500000, 1230996);
        precalc.put(40800000, 1239605);
        precalc.put(41100000, 1248112);
        precalc.put(41400000, 1256652);
        precalc.put(41700000, 1265205);
        precalc.put(42000000, 1273689);
        precalc.put(42300000, 1282286);
        precalc.put(42600000, 1290771);
        precalc.put(42900000, 1299249);
        precalc.put(43200000, 1307765);
        precalc.put(43500000, 1316314);
        precalc.put(43800000, 1324799);
        precalc.put(44100000, 1333417);
        precalc.put(44400000, 1341880);
        precalc.put(44700000, 1350402);
        precalc.put(45000000, 1358925);
        precalc.put(45300000, 1367411);
        precalc.put(45600000, 1375934);
        precalc.put(45900000, 1384448);
        precalc.put(46200000, 1392850);
        precalc.put(46500000, 1401374);
        precalc.put(46800000, 1409899);
        precalc.put(47100000, 1418381);
        precalc.put(47400000, 1426913);
        precalc.put(47700000, 1435430);
        precalc.put(48000000, 1443939);
        precalc.put(48300000, 1452383);
        precalc.put(48600000, 1460920);
        precalc.put(48900000, 1469369);
        precalc.put(49200000, 1477838);
        precalc.put(49500000, 1486323);
        precalc.put(49800000, 1494787);
        precalc.put(50100000, 1503239);
        precalc.put(50400000, 1511686);
        precalc.put(50700000, 1520184);
        precalc.put(51000000, 1528622);
        precalc.put(51300000, 1536997);
        precalc.put(51600000, 1545503);
        precalc.put(51900000, 1553884);
        precalc.put(52200000, 1562352);
        precalc.put(52500000, 1570716);
        precalc.put(52800000, 1579176);
        precalc.put(53100000, 1587542);
        precalc.put(53400000, 1596005);
        precalc.put(53700000, 1604386);
        precalc.put(54000000, 1612824);
