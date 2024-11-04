#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
int p[101];
typedef struct TNums {
  int cnt;
  int arr[20];
} TNUMS;

TNUMS divisors[101];
void get_div();

int main()
{
  int n, a, res, sum = 0;
  scanf("%d", &n);
  get_div();
  while (n--) {
    scanf("%d", &a);
    p[a]++;
    sum += a;
  }
  res = sum;
#ifdef DEBUG 

  printf("%d ", res);
#endif 

  for (int i = 1; i <= 100; ++i) {
    if (p[i]) {
      for (int k = 1; k < divisors[i].cnt; ++k) {
        for (int j = 1; j <= 100; ++j)
          if (p[j]) {
            int tmp
              = sum - i - j + i / divisors[i].arr[k] + j * divisors[i].arr[k];
            if (tmp < res) {
              res = tmp;

#ifdef DEBUG 

              printf("-> %d ", res);
#endif 

            }
          }
      }
    }
  }
#ifdef DEBUG 

  printf("\n");
#endif 

  printf("%d\n", res);
}

void get_div()
{
  divisors[1].cnt = 0;

  divisors[2].arr[1] = 2;
  divisors[2].cnt = 2;

  divisors[3].arr[1] = 3;
  divisors[3].cnt = 2;

  divisors[4].arr[1] = 2;
  divisors[4].arr[2] = 4;
  divisors[4].cnt = 3;

  divisors[5].arr[1] = 5;
  divisors[5].cnt = 2;

  divisors[6].arr[1] = 2;
  divisors[6].arr[2] = 3;
  divisors[6].arr[3] = 6;
  divisors[6].cnt = 4;

  divisors[7].arr[1] = 7;
  divisors[7].cnt = 2;

  divisors[8].arr[1] = 2;
  divisors[8].arr[2] = 4;
  divisors[8].arr[3] = 8;
  divisors[8].cnt = 4;

  divisors[9].arr[1] = 3;
  divisors[9].arr[2] = 9;
  divisors[9].cnt = 3;

  divisors[10].arr[1] = 2;
  divisors[10].arr[2] = 5;
  divisors[10].arr[3] = 10;
  divisors[10].cnt = 4;

  divisors[11].arr[1] = 11;
  divisors[11].cnt = 2;

  divisors[12].arr[1] = 2;
  divisors[12].arr[2] = 3;
  divisors[12].arr[3] = 4;
  divisors[12].arr[4] = 6;
  divisors[12].arr[5] = 12;
  divisors[12].cnt = 6;

  divisors[13].arr[1] = 13;
  divisors[13].cnt = 2;

  divisors[14].arr[1] = 2;
  divisors[14].arr[2] = 7;
  divisors[14].arr[3] = 14;
  divisors[14].cnt = 4;

  divisors[15].arr[1] = 3;
  divisors[15].arr[2] = 5;
  divisors[15].arr[3] = 15;
  divisors[15].cnt = 4;

  divisors[16].arr[1] = 2;
  divisors[16].arr[2] = 4;
  divisors[16].arr[3] = 8;
  divisors[16].arr[4] = 16;
  divisors[16].cnt = 5;

  divisors[17].arr[1] = 17;
  divisors[17].cnt = 2;

  divisors[18].arr[1] = 2;
  divisors[18].arr[2] = 3;
  divisors[18].arr[3] = 6;
  divisors[18].arr[4] = 9;
  divisors[18].arr[5] = 18;
  divisors[18].cnt = 6;

  divisors[19].arr[1] = 19;
  divisors[19].cnt = 2;

  divisors[20].arr[1] = 2;
  divisors[20].arr[2] = 4;
  divisors[20].arr[3] = 5;
  divisors[20].arr[4] = 10;
  divisors[20].arr[5] = 20;
  divisors[20].cnt = 6;

  divisors[21].arr[1] = 3;
  divisors[21].arr[2] = 7;
  divisors[21].arr[3] = 21;
  divisors[21].cnt = 4;

  divisors[22].arr[1] = 2;
  divisors[22].arr[2] = 11;
  divisors[22].arr[3] = 22;
  divisors[22].cnt = 4;

  divisors[23].arr[1] = 23;
  divisors[23].cnt = 2;

  divisors[24].arr[1] = 2;
  divisors[24].arr[2] = 3;
  divisors[24].arr[3] = 4;
  divisors[24].arr[4] = 6;
  divisors[24].arr[5] = 8;
  divisors[24].arr[6] = 12;
  divisors[24].arr[7] = 24;
  divisors[24].cnt = 8;

  divisors[25].arr[1] = 5;
  divisors[25].arr[2] = 25;
  divisors[25].cnt = 3;

  divisors[26].arr[1] = 2;
  divisors[26].arr[2] = 13;
  divisors[26].arr[3] = 26;
  divisors[26].cnt = 4;

  divisors[27].arr[1] = 3;
  divisors[27].arr[2] = 9;
  divisors[27].arr[3] = 27;
  divisors[27].cnt = 4;

  divisors[28].arr[1] = 2;
  divisors[28].arr[2] = 4;
  divisors[28].arr[3] = 7;
  divisors[28].arr[4] = 14;
  divisors[28].arr[5] = 28;
  divisors[28].cnt = 6;

  divisors[29].arr[1] = 29;
  divisors[29].cnt = 2;

  divisors[30].arr[1] = 2;
  divisors[30].arr[2] = 3;
  divisors[30].arr[3] = 5;
  divisors[30].arr[4] = 6;
  divisors[30].arr[5] = 10;
  divisors[30].arr[6] = 15;
  divisors[30].arr[7] = 30;
  divisors[30].cnt = 8;

  divisors[31].arr[1] = 31;
  divisors[31].cnt = 2;

  divisors[32].arr[1] = 2;
  divisors[32].arr[2] = 4;
  divisors[32].arr[3] = 8;
  divisors[32].arr[4] = 16;
  divisors[32].arr[5] = 32;
  divisors[32].cnt = 6;

  divisors[33].arr[1] = 3;
  divisors[33].arr[2] = 11;
  divisors[33].arr[3] = 33;
  divisors[33].cnt = 4;

  divisors[34].arr[1] = 2;
  divisors[34].arr[2] = 17;
  divisors[34].arr[3] = 34;
  divisors[34].cnt = 4;

  divisors[35].arr[1] = 5;
  divisors[35].arr[2] = 7;
  divisors[35].arr[3] = 35;
  divisors[35].cnt = 4;

  divisors[36].arr[1] = 2;
  divisors[36].arr[2] = 3;
  divisors[36].arr[3] = 4;
  divisors[36].arr[4] = 6;
  divisors[36].arr[5] = 9;
  divisors[36].arr[6] = 12;
  divisors[36].arr[7] = 18;
  divisors[36].arr[8] = 36;
  divisors[36].cnt = 9;

  divisors[37].arr[1] = 37;
  divisors[37].cnt = 2;

  divisors[38].arr[1] = 2;
  divisors[38].arr[2] = 19;
  divisors[38].arr[3] = 38;
  divisors[38].cnt = 4;

  divisors[39].arr[1] = 3;
  divisors[39].arr[2] = 13;
  divisors[39].arr[3] = 39;
  divisors[39].cnt = 4;

  divisors[40].arr[1] = 2;
  divisors[40].arr[2] = 4;
  divisors[40].arr[3] = 5;
  divisors[40].arr[4] = 8;
  divisors[40].arr[5] = 10;
  divisors[40].arr[6] = 20;
  divisors[40].arr[7] = 40;
  divisors[40].cnt = 8;

  divisors[41].arr[1] = 41;
  divisors[41].cnt = 2;

  divisors[42].arr[1] = 2;
  divisors[42].arr[2] = 3;
  divisors[42].arr[3] = 6;
  divisors[42].arr[4] = 7;
  divisors[42].arr[5] = 14;
  divisors[42].arr[6] = 21;
  divisors[42].arr[7] = 42;
  divisors[42].cnt = 8;

  divisors[43].arr[1] = 43;
  divisors[43].cnt = 2;

  divisors[44].arr[1] = 2;
  divisors[44].arr[2] = 4;
  divisors[44].arr[3] = 11;
  divisors[44].arr[4] = 22;
  divisors[44].arr[5] = 44;
  divisors[44].cnt = 6;

  divisors[45].arr[1] = 3;
  divisors[45].arr[2] = 5;
  divisors[45].arr[3] = 9;
  divisors[45].arr[4] = 15;
  divisors[45].arr[5] = 45;
  divisors[45].cnt = 6;

  divisors[46].arr[1] = 2;
  divisors[46].arr[2] = 23;
  divisors[46].arr[3] = 46;
  divisors[46].cnt = 4;

  divisors[47].arr[1] = 47;
  divisors[47].cnt = 2;

  divisors[48].arr[1] = 2;
  divisors[48].arr[2] = 3;
  divisors[48].arr[3] = 4;
  divisors[48].arr[4] = 6;
  divisors[48].arr[5] = 8;
  divisors[48].arr[6] = 12;
  divisors[48].arr[7] = 16;
  divisors[48].arr[8] = 24;
  divisors[48].arr[9] = 48;
  divisors[48].cnt = 10;

  divisors[49].arr[1] = 7;
  divisors[49].arr[2] = 49;
  divisors[49].cnt = 3;

  divisors[50].arr[1] = 2;
  divisors[50].arr[2] = 5;
  divisors[50].arr[3] = 10;
  divisors[50].arr[4] = 25;
  divisors[50].arr[5] = 50;
  divisors[50].cnt = 6;

  divisors[51].arr[1] = 3;
  divisors[51].arr[2] = 17;
  divisors[51].arr[3] = 51;
  divisors[51].cnt = 4;

  divisors[52].arr[1] = 2;
  divisors[52].arr[2] = 4;
  divisors[52].arr[3] = 13;
  divisors[52].arr[4] = 26;
  divisors[52].arr[5] = 52;
  divisors[52].cnt = 6;

  divisors[53].arr[1] = 53;
  divisors[53].cnt = 2;

  divisors[54].arr[1] = 2;
  divisors[54].arr[2] = 3;
  divisors[54].arr[3] = 6;
  divisors[54].arr[4] = 9;
  divisors[54].arr[5] = 18;
  divisors[54].arr[6] = 27;
  divisors[54].arr[7] = 54;
  divisors[54].cnt = 8;

  divisors[55].arr[1] = 5;
  divisors[55].arr[2] = 11;
  divisors[55].arr[3] = 55;
  divisors[55].cnt = 4;

  divisors[56].arr[1] = 2;
  divisors[56].arr[2] = 4;
  divisors[56].arr[3] = 7;
  divisors[56].arr[4] = 8;
  divisors[56].arr[5] = 14;
  divisors[56].arr[6] = 28;
  divisors[56].arr[7] = 56;
  divisors[56].cnt = 8;

  divisors[57].arr[1] = 3;
  divisors[57].arr[2] = 19;
  divisors[57].arr[3] = 57;
  divisors[57].cnt = 4;

  divisors[58].arr[1] = 2;
  divisors[58].arr[2] = 29;
  divisors[58].arr[3] = 58;
  divisors[58].cnt = 4;

  divisors[59].arr[1] = 59;
  divisors[59].cnt = 2;

  divisors[60].arr[1] = 2;
  divisors[60].arr[2] = 3;
  divisors[60].arr[3] = 4;
  divisors[60].arr[4] = 5;
  divisors[60].arr[5] = 6;
  divisors[60].arr[6] = 10;
  divisors[60].arr[7] = 12;
  divisors[60].arr[8] = 15;
  divisors[60].arr[9] = 20;
  divisors[60].arr[10] = 30;
  divisors[60].arr[11] = 60;
  divisors[60].cnt = 12;

  divisors[61].arr[1] = 61;
  divisors[61].cnt = 2;

  divisors[62].arr[1] = 2;
  divisors[62].arr[2] = 31;
  divisors[62].arr[3] = 62;
  divisors[62].cnt = 4;

  divisors[63].arr[1] = 3;
  divisors[63].arr[2] = 7;
  divisors[63].arr[3] = 9;
  divisors[63].arr[4] = 21;
  divisors[63].arr[5] = 63;
  divisors[63].cnt = 6;

  divisors[64].arr[1] = 2;
  divisors[64].arr[2] = 4;
  divisors[64].arr[3] = 8;
  divisors[64].arr[4] = 16;
  divisors[64].arr[5] = 32;
  divisors[64].arr[6] = 64;
  divisors[64].cnt = 7;

  divisors[65].arr[1] = 5;
  divisors[65].arr[2] = 13;
  divisors[65].arr[3] = 65;
  divisors[65].cnt = 4;

  divisors[66].arr[1] = 2;
  divisors[66].arr[2] = 3;
  divisors[66].arr[3] = 6;
  divisors[66].arr[4] = 11;
  divisors[66].arr[5] = 22;
  divisors[66].arr[6] = 33;
  divisors[66].arr[7] = 66;
  divisors[66].cnt = 8;

  divisors[67].arr[1] = 67;
  divisors[67].cnt = 2;

  divisors[68].arr[1] = 2;
  divisors[68].arr[2] = 4;
  divisors[68].arr[3] = 17;
  divisors[68].arr[4] = 34;
  divisors[68].arr[5] = 68;
  divisors[68].cnt = 6;

  divisors[69].arr[1] = 3;
  divisors[69].arr[2] = 23;
  divisors[69].arr[3] = 69;
  divisors[69].cnt = 4;

  divisors[70].arr[1] = 2;
  divisors[70].arr[2] = 5;
  divisors[70].arr[3] = 7;
  divisors[70].arr[4] = 10;
  divisors[70].arr[5] = 14;
  divisors[70].arr[6] = 35;
  divisors[70].arr[7] = 70;
  divisors[70].cnt = 8;

  divisors[71].arr[1] = 71;
  divisors[71].cnt = 2;

  divisors[72].arr[1] = 2;
  divisors[72].arr[2] = 3;
  divisors[72].arr[3] = 4;
  divisors[72].arr[4] = 6;
  divisors[72].arr[5] = 8;
  divisors[72].arr[6] = 9;
  divisors[72].arr[7] = 12;
  divisors[72].arr[8] = 18;
  divisors[72].arr[9] = 24;
  divisors[72].arr[10] = 36;
  divisors[72].arr[11] = 72;
  divisors[72].cnt = 12;

  divisors[73].arr[1] = 73;
  divisors[73].cnt = 2;

  divisors[74].arr[1] = 2;
  divisors[74].arr[2] = 37;
  divisors[74].arr[3] = 74;
  divisors[74].cnt = 4;

  divisors[75].arr[1] = 3;
  divisors[75].arr[2] = 5;
  divisors[75].arr[3] = 15;
  divisors[75].arr[4] = 25;
  divisors[75].arr[5] = 75;
  divisors[75].cnt = 6;

  divisors[76].arr[1] = 2;
  divisors[76].arr[2] = 4;
  divisors[76].arr[3] = 19;
  divisors[76].arr[4] = 38;
  divisors[76].arr[5] = 76;
  divisors[76].cnt = 6;

  divisors[77].arr[1] = 7;
  divisors[77].arr[2] = 11;
  divisors[77].arr[3] = 77;
  divisors[77].cnt = 4;

  divisors[78].arr[1] = 2;
  divisors[78].arr[2] = 3;
  divisors[78].arr[3] = 6;
  divisors[78].arr[4] = 13;
  divisors[78].arr[5] = 26;
  divisors[78].arr[6] = 39;
  divisors[78].arr[7] = 78;
  divisors[78].cnt = 8;

  divisors[79].arr[1] = 79;
  divisors[79].cnt = 2;

  divisors[80].arr[1] = 2;
  divisors[80].arr[2] = 4;
  divisors[80].arr[3] = 5;
  divisors[80].arr[4] = 8;
  divisors[80].arr[5] = 10;
  divisors[80].arr[6] = 16;
  divisors[80].arr[7] = 20;
  divisors[80].arr[8] = 40;
  divisors[80].arr[9] = 80;
  divisors[80].cnt = 10;

  divisors[81].arr[1] = 3;
  divisors[81].arr[2] = 9;
  divisors[81].arr[3] = 27;
  divisors[81].arr[4] = 81;
  divisors[81].cnt = 5;

  divisors[82].arr[1] = 2;
  divisors[82].arr[2] = 41;
  divisors[82].arr[3] = 82;
  divisors[82].cnt = 4;

  divisors[83].arr[1] = 83;
  divisors[83].cnt = 2;

  divisors[84].arr[1] = 2;
  divisors[84].arr[2] = 3;
  divisors[84].arr[3] = 4;
  divisors[84].arr[4] = 6;
  divisors[84].arr[5] = 7;
  divisors[84].arr[6] = 12;
  divisors[84].arr[7] = 14;
  divisors[84].arr[8] = 21;
  divisors[84].arr[9] = 28;
  divisors[84].arr[10] = 42;
  divisors[84].arr[11] = 84;
  divisors[84].cnt = 12;

  divisors[85].arr[1] = 5;
  divisors[85].arr[2] = 17;
  divisors[85].arr[3] = 85;
  divisors[85].cnt = 4;

  divisors[86].arr[1] = 2;
  divisors[86].arr[2] = 43;
  divisors[86].arr[3] = 86;
  divisors[86].cnt = 4;

  divisors[87].arr[1] = 3;
  divisors[87].arr[2] = 29;
  divisors[87].arr[3] = 87;
  divisors[87].cnt = 4;

  divisors[88].arr[1] = 2;
  divisors[88].arr[2] = 4;
  divisors[88].arr[3] = 8;
  divisors[88].arr[4] = 11;
  divisors[88].arr[5] = 22;
  divisors[88].arr[6] = 44;
  divisors[88].arr[7] = 88;
  divisors[88].cnt = 8;

  divisors[89].arr[1] = 89;
  divisors[89].cnt = 2;

  divisors[90].arr[1] = 2;
  divisors[90].arr[2] = 3;
  divisors[90].arr[3] = 5;
  divisors[90].arr[4] = 6;
  divisors[90].arr[5] = 9;
  divisors[90].arr[6] = 10;
  divisors[90].arr[7] = 15;
  divisors[90].arr[8] = 18;
  divisors[90].arr[9] = 30;
  divisors[90].arr[10] = 45;
  divisors[90].arr[11] = 90;
  divisors[90].cnt = 12;

  divisors[91].arr[1] = 7;
  divisors[91].arr[2] = 13;
  divisors[91].arr[3] = 91;
  divisors[91].cnt = 4;

  divisors[92].arr[1] = 2;
  divisors[92].arr[2] = 4;
  divisors[92].arr[3] = 23;
  divisors[92].arr[4] = 46;
  divisors[92].arr[5] = 92;
  divisors[92].cnt = 6;

  divisors[93].arr[1] = 3;
  divisors[93].arr[2] = 31;
  divisors[93].arr[3] = 93;
  divisors[93].cnt = 4;

  divisors[94].arr[1] = 2;
  divisors[94].arr[2] = 47;
  divisors[94].arr[3] = 94;
  divisors[94].cnt = 4;

  divisors[95].arr[1] = 5;
  divisors[95].arr[2] = 19;
  divisors[95].arr[3] = 95;
  divisors[95].cnt = 4;

  divisors[96].arr[1] = 2;
  divisors[96].arr[2] = 3;
  divisors[96].arr[3] = 4;
  divisors[96].arr[4] = 6;
  divisors[96].arr[5] = 8;
  divisors[96].arr[6] = 12;
  divisors[96].arr[7] = 16;
  divisors[96].arr[8] = 24;
  divisors[96].arr[9] = 32;
  divisors[96].arr[10] = 48;
  divisors[96].arr[11] = 96;
  divisors[96].cnt = 12;

  divisors[97].arr[1] = 97;
  divisors[97].cnt = 2;

  divisors[98].arr[1] = 2;
  divisors[98].arr[2] = 7;
  divisors[98].arr[3] = 14;
  divisors[98].arr[4] = 49;
  divisors[98].arr[5] = 98;
  divisors[98].cnt = 6;

  divisors[99].arr[1] = 3;
  divisors[99].arr[2] = 9;
  divisors[99].arr[3] = 11;
  divisors[99].arr[4] = 33;
  divisors[99].arr[5] = 99;
  divisors[99].cnt = 6;

  divisors[100].arr[1] = 2;
  divisors[100].arr[2] = 4;
  divisors[100].arr[3] = 5;
  divisors[100].arr[4] = 10;
  divisors[100].arr[5] = 20;
  divisors[100].arr[6] = 25;
  divisors[100].arr[7] = 50;
  divisors[100].arr[8] = 100;
  divisors[100].cnt = 9;
}
