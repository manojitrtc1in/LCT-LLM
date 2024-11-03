#include <stdio.h>
#include <stdbool.h>

bool isLucky(int n) {
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

const int MAXN = 300 * 1000 * 1000 + 5;

int precalc[MAXN];

int get(int border) {
    int solved = 0;
    int result = 0;
    for (int i = 0; i <= border; ++i) {
        if (precalc[i] != 0) {
            solved = i;
            result = precalc[i];
        }
    }
    for (int i = solved + 1; i <= border; ++i) {
        result += isLucky(i);
    }
    return result;
}

int main() {
    for (int i = 0; i < MAXN; ++i) {
        precalc[i] = 0;
    }
    precalc[300000] = 12981;
    precalc[600000] = 24523;
    precalc[900000] = 35585;
    precalc[1200000] = 46430;
    precalc[1500000] = 57023;
    precalc[1800000] = 67489;
    precalc[2100000] = 77879;
    precalc[2400000] = 88055;
    precalc[2700000] = 98240;
    precalc[3000000] = 108284;
    precalc[3300000] = 118375;
    precalc[3600000] = 128270;
    precalc[3900000] = 138219;
    precalc[4200000] = 148121;
    precalc[4500000] = 157925;
    precalc[4800000] = 167675;
    precalc[5100000] = 177433;
    precalc[5400000] = 187048;
    precalc[5700000] = 196709;
    precalc[6000000] = 206333;
    precalc[6300000] = 215966;
    precalc[6600000] = 225463;
    precalc[6900000] = 235069;
    precalc[7200000] = 244581;
    precalc[7500000] = 253974;
    precalc[7800000] = 263482;
    precalc[8100000] = 272885;
    precalc[8400000] = 282271;
    precalc[8700000] = 291710;
    precalc[9000000] = 301101;
    precalc[9300000] = 310444;
    precalc[9600000] = 319813;
    precalc[9900000] = 329106;
    precalc[10200000] = 338394;
    precalc[10500000] = 347665;
    precalc[10800000] = 356909;
    precalc[11100000] = 366160;
    precalc[11400000] = 375439;
    precalc[11700000] = 384728;
    precalc[12000000] = 393993;
    precalc[12300000] = 403209;
    precalc[12600000] = 412333;
    precalc[12900000] = 421556;
    precalc[13200000] = 430660;
    precalc[13500000] = 439791;
    precalc[13800000] = 448901;
    precalc[14100000] = 457972;
    precalc[14400000] = 467135;
    precalc[14700000] = 476215;
    precalc[15000000] = 485275;
    precalc[15300000] = 494311;
    precalc[15600000] = 503251;
    precalc[15900000] = 512383;
    precalc[16200000] = 521398;
    precalc[16500000] = 530472;
    precalc[16800000] = 539450;
    precalc[17100000] = 548499;
    precalc[17400000] = 557493;
    precalc[17700000] = 566514;
    precalc[18000000] = 575503;
    precalc[18300000] = 584484;
    precalc[18600000] = 593357;
    precalc[18900000] = 602379;
    precalc[19200000] = 611346;
    precalc[19500000] = 620283;
    precalc[19800000] = 629187;
    precalc[20100000] = 638124;
    precalc[20400000] = 646968;
    precalc[20700000] = 655897;
    precalc[21000000] = 664771;
    precalc[21300000] = 673688;
    precalc[21600000] = 682576;
    precalc[21900000] = 691478;
    precalc[22200000] = 700326;
    precalc[22500000] = 709115;
    precalc[22800000] = 717989;
    precalc[23100000] = 726882;
    precalc[23400000] = 735740;
    precalc[23700000] = 744563;
    precalc[24000000] = 753318;
    precalc[24300000] = 762199;
    precalc[24600000] = 771012;
    precalc[24900000] = 779827;
    precalc[25200000] = 788611;
    precalc[25500000] = 797361;
    precalc[25800000] = 806180;
    precalc[26100000] = 814963;
    precalc[26400000] = 823752;
    precalc[26700000] = 832596;
    precalc[27000000] = 841364;
    precalc[27300000] = 850080;
    precalc[27600000] = 858875;
    precalc[27900000] = 867592;
    precalc[28200000] = 876358;
    precalc[28500000] = 885138;
    precalc[28800000] = 893857;
    precalc[29100000] = 902573;
    precalc[29400000] = 911332;
    precalc[29700000] = 920007;
    precalc[30000000] = 928780;
    precalc[30300000] = 937520;
    precalc[30600000] = 946295;
    precalc[30900000] = 955026;
    precalc[31200000] = 963624;
    precalc[31500000] = 972309;
    precalc[31800000] = 980962;
    precalc[32100000] = 989647;
    precalc[32400000] = 998272;
    precalc[32700000] = 1006935;
    precalc[33000000] = 1015619;
    precalc[33300000] = 1024321;
    precalc[33600000] = 1032962;
    precalc[33900000] = 1041665;
    precalc[34200000] = 1050175;
    precalc[34500000] = 1058798;
    precalc[34800000] = 1067388;
    precalc[35100000] = 1076029;
    precalc[35400000] = 1084692;
    precalc[35700000] = 1093331;
    precalc[36000000] = 1101903;
    precalc[36300000] = 1110568;
    precalc[36600000] = 1119226;
    precalc[36900000] = 1127772;
    precalc[37200000] = 1136475;
    precalc[37500000] = 1145026;
    precalc[37800000] = 1153592;
    precalc[38100000] = 1162244;
    precalc[38400000] = 1170911;
    precalc[38700000] = 1179444;
    precalc[39000000] = 1188093;
    precalc[39300000] = 1196660;
    precalc[39600000] = 1205285;
    precalc[39900000] = 1213868;
    precalc[40200000] = 1222393;
    precalc[40500000] = 1230996;
    precalc[40800000] = 1239605;
    precalc[41100000] = 1248112;
    precalc[41400000] = 1256652;
    precalc[41700000] = 1265205;
    precalc[42000000] = 1273689;
    precalc[42300000] = 1282286;
    precalc[42600000] = 1290771;
    precalc[42900000] = 1299249;
    precalc[43200000] = 1307765;
    precalc[43500000] = 1316314;
    precalc[43800000] = 1324799;
    precalc[44100000] = 1333417;
    precalc[44400000] = 1341880;
    precalc[44700000] = 1350402;
    precalc[45000000] = 1358925;
    precalc[45300000] = 1367411;
    precalc[45600000] = 1375934;
    precalc[45900000] = 1384448;
    precalc[46200000] = 1392850;
    precalc[46500000] = 1401374;
    precalc[46800000] = 1409899;
    precalc[47100000] = 1418381;
    precalc[47400000] = 1426913;
    precalc[47700000] = 1435430;
    precalc[48000000] = 1443939;
    precalc[48300000] = 1452383;
    precalc[48600000] = 1460920;
    precalc[48900000] = 1469369;
    precalc[49200000] = 1477838;
    precalc[49500000] = 1486323;
