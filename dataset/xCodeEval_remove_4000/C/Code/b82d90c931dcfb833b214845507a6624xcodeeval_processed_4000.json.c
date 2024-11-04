

int p[101];
typedef struct TNums {
  int cnt;
  int arr[20];
} TNUMS;

TNUMS id0[101];
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


  printf("%d ", res);


  for (int i = 1; i <= 100; ++i) {
    if (p[i]) {
      for (int k = 1; k < id0[i].cnt; ++k) {
        for (int j = 1; j <= 100; ++j)
          if (p[j]) {
            int tmp
              = sum - i - j + i / id0[i].arr[k] + j * id0[i].arr[k];
            if (tmp < res) {
              res = tmp;



              printf("-> %d ", res);


            }
          }
      }
    }
  }


  printf("\n");


  printf("%d\n", res);
}

void get_div()
{
  id0[1].cnt = 0;

  id0[2].arr[1] = 2;
  id0[2].cnt = 2;

  id0[3].arr[1] = 3;
  id0[3].cnt = 2;

  id0[4].arr[1] = 2;
  id0[4].arr[2] = 4;
  id0[4].cnt = 3;

  id0[5].arr[1] = 5;
  id0[5].cnt = 2;

  id0[6].arr[1] = 2;
  id0[6].arr[2] = 3;
  id0[6].arr[3] = 6;
  id0[6].cnt = 4;

  id0[7].arr[1] = 7;
  id0[7].cnt = 2;

  id0[8].arr[1] = 2;
  id0[8].arr[2] = 4;
  id0[8].arr[3] = 8;
  id0[8].cnt = 4;

  id0[9].arr[1] = 3;
  id0[9].arr[2] = 9;
  id0[9].cnt = 3;

  id0[10].arr[1] = 2;
  id0[10].arr[2] = 5;
  id0[10].arr[3] = 10;
  id0[10].cnt = 4;

  id0[11].arr[1] = 11;
  id0[11].cnt = 2;

  id0[12].arr[1] = 2;
  id0[12].arr[2] = 3;
  id0[12].arr[3] = 4;
  id0[12].arr[4] = 6;
  id0[12].arr[5] = 12;
  id0[12].cnt = 6;

  id0[13].arr[1] = 13;
  id0[13].cnt = 2;

  id0[14].arr[1] = 2;
  id0[14].arr[2] = 7;
  id0[14].arr[3] = 14;
  id0[14].cnt = 4;

  id0[15].arr[1] = 3;
  id0[15].arr[2] = 5;
  id0[15].arr[3] = 15;
  id0[15].cnt = 4;

  id0[16].arr[1] = 2;
  id0[16].arr[2] = 4;
  id0[16].arr[3] = 8;
  id0[16].arr[4] = 16;
  id0[16].cnt = 5;

  id0[17].arr[1] = 17;
  id0[17].cnt = 2;

  id0[18].arr[1] = 2;
  id0[18].arr[2] = 3;
  id0[18].arr[3] = 6;
  id0[18].arr[4] = 9;
  id0[18].arr[5] = 18;
  id0[18].cnt = 6;

  id0[19].arr[1] = 19;
  id0[19].cnt = 2;

  id0[20].arr[1] = 2;
  id0[20].arr[2] = 4;
  id0[20].arr[3] = 5;
  id0[20].arr[4] = 10;
  id0[20].arr[5] = 20;
  id0[20].cnt = 6;

  id0[21].arr[1] = 3;
  id0[21].arr[2] = 7;
  id0[21].arr[3] = 21;
  id0[21].cnt = 4;

  id0[22].arr[1] = 2;
  id0[22].arr[2] = 11;
  id0[22].arr[3] = 22;
  id0[22].cnt = 4;

  id0[23].arr[1] = 23;
  id0[23].cnt = 2;

  id0[24].arr[1] = 2;
  id0[24].arr[2] = 3;
  id0[24].arr[3] = 4;
  id0[24].arr[4] = 6;
  id0[24].arr[5] = 8;
  id0[24].arr[6] = 12;
  id0[24].arr[7] = 24;
  id0[24].cnt = 8;

  id0[25].arr[1] = 5;
  id0[25].arr[2] = 25;
  id0[25].cnt = 3;

  id0[26].arr[1] = 2;
  id0[26].arr[2] = 13;
  id0[26].arr[3] = 26;
  id0[26].cnt = 4;

  id0[27].arr[1] = 3;
  id0[27].arr[2] = 9;
  id0[27].arr[3] = 27;
  id0[27].cnt = 4;

  id0[28].arr[1] = 2;
  id0[28].arr[2] = 4;
  id0[28].arr[3] = 7;
  id0[28].arr[4] = 14;
  id0[28].arr[5] = 28;
  id0[28].cnt = 6;

  id0[29].arr[1] = 29;
  id0[29].cnt = 2;

  id0[30].arr[1] = 2;
  id0[30].arr[2] = 3;
  id0[30].arr[3] = 5;
  id0[30].arr[4] = 6;
  id0[30].arr[5] = 10;
  id0[30].arr[6] = 15;
  id0[30].arr[7] = 30;
  id0[30].cnt = 8;

  id0[31].arr[1] = 31;
  id0[31].cnt = 2;

  id0[32].arr[1] = 2;
  id0[32].arr[2] = 4;
  id0[32].arr[3] = 8;
  id0[32].arr[4] = 16;
  id0[32].arr[5] = 32;
  id0[32].cnt = 6;

  id0[33].arr[1] = 3;
  id0[33].arr[2] = 11;
  id0[33].arr[3] = 33;
  id0[33].cnt = 4;

  id0[34].arr[1] = 2;
  id0[34].arr[2] = 17;
  id0[34].arr[3] = 34;
  id0[34].cnt = 4;

  id0[35].arr[1] = 5;
  id0[35].arr[2] = 7;
  id0[35].arr[3] = 35;
  id0[35].cnt = 4;

  id0[36].arr[1] = 2;
  id0[36].arr[2] = 3;
  id0[36].arr[3] = 4;
  id0[36].arr[4] = 6;
  id0[36].arr[5] = 9;
  id0[36].arr[6] = 12;
  id0[36].arr[7] = 18;
  id0[36].arr[8] = 36;
  id0[36].cnt = 9;

  id0[37].arr[1] = 37;
  id0[37].cnt = 2;

  id0[38].arr[1] = 2;
  id0[38].arr[2] = 19;
  id0[38].arr[3] = 38;
  id0[38].cnt = 4;

  id0[39].arr[1] = 3;
  id0[39].arr[2] = 13;
  id0[39].arr[3] = 39;
  id0[39].cnt = 4;

  id0[40].arr[1] = 2;
  id0[40].arr[2] = 4;
  id0[40].arr[3] = 5;
  id0[40].arr[4] = 8;
  id0[40].arr[5] = 10;
  id0[40].arr[6] = 20;
  id0[40].arr[7] = 40;
  id0[40].cnt = 8;

  id0[41].arr[1] = 41;
  id0[41].cnt = 2;

  id0[42].arr[1] = 2;
  id0[42].arr[2] = 3;
  id0[42].arr[3] = 6;
  id0[42].arr[4] = 7;
  id0[42].arr[5] = 14;
  id0[42].arr[6] = 21;
  id0[42].arr[7] = 42;
  id0[42].cnt = 8;

  id0[43].arr[1] = 43;
  id0[43].cnt = 2;

  id0[44].arr[1] = 2;
  id0[44].arr[2] = 4;
  id0[44].arr[3] = 11;
  id0[44].arr[4] = 22;
  id0[44].arr[5] = 44;
  id0[44].cnt = 6;

  id0[45].arr[1] = 3;
  id0[45].arr[2] = 5;
  id0[45].arr[3] = 9;
  id0[45].arr[4] = 15;
  id0[45].arr[5] = 45;
  id0[45].cnt = 6;

  id0[46].arr[1] = 2;
  id0[46].arr[2] = 23;
  id0[46].arr[3] = 46;
  id0[46].cnt = 4;

  id0[47].arr[1] = 47;
  id0[47].cnt = 2;

  id0[48].arr[1] = 2;
  id0[48].arr[2] = 3;
  id0[48].arr[3] = 4;
  id0[48].arr[4] = 6;
  id0[48].arr[5] = 8;
  id0[48].arr[6] = 12;
  id0[48].arr[7] = 16;
  id0[48].arr[8] = 24;
  id0[48].arr[9] = 48;
  id0[48].cnt = 10;

  id0[49].arr[1] = 7;
  id0[49].arr[2] = 49;
  id0[49].cnt = 3;

  id0[50].arr[1] = 2;
  id0[50].arr[2] = 5;
  id0[50].arr[3] = 10;
  id0[50].arr[4] = 25;
  id0[50].arr[5] = 50;
  id0[50].cnt = 6;

  id0[51].arr[1] = 3;
  id0[51].arr[2] = 17;
  id0[51].arr[3] = 51;
  id0[51].cnt = 4;

  id0[52].arr[1] = 2;
  id0[52].arr[2] = 4;
  id0[52].arr[3] = 13;
  id0[52].arr[4] = 26;
  id0[52].arr[5] = 52;
  id0[52].cnt = 6;

  id0[53].arr[1] = 53;
  id0[53].cnt = 2;

  id0[54].arr[1] = 2;
  id0[54].arr[2] = 3;
  id0[54].arr[3] = 6;
  id0[54].arr[4] = 9;
  id0[54].arr[5] = 18;
  id0[54].arr[6] = 27;
  id0[54].arr[7] = 54;
  id0[54].cnt = 8;

  id0[55].arr[1] = 5;
  id0[55].arr[2] = 11;
  id0[55].arr[3] = 55;
  id0[55].cnt = 4;

  id0[56].arr[1] = 2;
  id0[56].arr[2] = 4;
  id0[56].arr[3] = 7;
  id0[56].arr[4] = 8;
  id0[56].arr[5] = 14;
  id0[56].arr[6] = 28;
  id0[56].arr[7] = 56;
  id0[56].cnt = 8;

  id0[57].arr[1] = 3;
  id0[57].arr[2] = 19;
  id0[57].arr[3] = 57;
  id0[57].cnt = 4;

  id0[58].arr[1] = 2;
  id0[58].arr[2] = 29;
  id0[58].arr[3] = 58;
  id0[58].cnt = 4;

  id0[59].arr[1] = 59;
  id0[59].cnt = 2;

  id0[60].arr[1] = 2;
  id0[60].arr[2] = 3;
  id0[60].arr[3] = 4;
  id0[60].arr[4] = 5;
  id0[60].arr[5] = 6;
  id0[60].arr[6] = 10;
  id0[60].arr[7] = 12;
  id0[60].arr[8] = 15;
  id0[60].arr[9] = 20;
  id0[60].arr[10] = 30;
  id0[60].arr[11] = 60;
  id0[60].cnt = 12;

  id0[61].arr[1] = 61;
  id0[61].cnt = 2;

  id0[62].arr[1] = 2;
  id0[62].arr[2] = 31;
  id0[62].arr[3] = 62;
  id0[62].cnt = 4;

  id0[63].arr[1] = 3;
  id0[63].arr[2] = 7;
  id0[63].arr[3] = 9;
  id0[63].arr[4] = 21;
  id0[63].arr[5] = 63;
  id0[63].cnt = 6;

  id0[64].arr[1] = 2;
  id0[64].arr[2] = 4;
  id0[64].arr[3] = 8;
  id0[64].arr[4] = 16;
  id0[64].arr[5] = 32;
  id0[64].arr[6] = 64;
  id0[64].cnt = 7;

  id0[65].arr[1] = 5;
  id0[65].arr[2] = 13;
  id0[65].arr[3] = 65;
  id0[65].cnt = 4;

  id0[66].arr[1] = 2;
  id0[66].arr[2] = 3;
  id0[66].arr[3] = 6;
  id0[66].arr[4] = 11;
  id0[66].arr[5] = 22;
  id0[66].arr[6] = 33;
  id0[66].arr[7] = 66;
  id0[66].cnt = 8;

  id0[67].arr[1] = 67;
  id0[67].cnt = 2;

  id0[68].arr[1] = 2;
  id0[68].arr[2] = 4;
  id0[68].arr[3] = 17;
  id0[68].arr[4] = 34;
  id0[68].arr[5] = 68;
  id0[68].cnt = 6;

  id0[69].arr[1] = 3;
  id0[69].arr[2] = 23;
  id0[69].arr[3] = 69;
  id0[69].cnt = 4;

  id0[70].arr[1] = 2;
  id0[70].arr[2] = 5;
  id0[70].arr[3] = 7;
  id0[70].arr[4] = 10;
  id0[70].arr[5] = 14;
  id0[70].arr[6] = 35;
  id0[70].arr[7] = 70;
  id0[70].cnt = 8;

  id0[71].arr[1] = 71;
  id0[71].cnt = 2;

  id0[72].arr[1] = 2;
  id0[72].arr[2] = 3;
  id0[72].arr[3] = 4;
  id0[72].arr[4] = 6;
  id0[72].arr[5] = 8;
  id0[72].arr[6] = 9;
  id0[72].arr[7] = 12;
  id0[72].arr[8] = 18;
  id0[72].arr[9] = 24;
  id0[72].arr[10] = 36;
  id0[72].arr[11] = 72;
  id0[72].cnt = 12;

  id0[73].arr[1] = 73;
  id0[73].cnt = 2;

  id0[74].arr[1] = 2;
  id0[74].arr[2] = 37;
  id0[74].arr[3] = 74;
  id0[74].cnt = 4;

  id0[75].arr[1] = 3;
  id0[75].arr[2] = 5;
  id0[75].arr[3] = 15;
  id0[75].arr[4] = 25;
  id0[75].arr[5] = 75;
  id0[75].cnt = 6;

  id0[76].arr[1] = 2;
  id0[76].arr[2] = 4;
  id0[76].arr[3] = 19;
  id0[76].arr[4] = 38;
  id0[76].arr[5] = 76;
  id0[76].cnt = 6;

  id0[77].arr[1] = 7;
  id0[77].arr[2] = 11;
  id0[77].arr[3] = 77;
  id0[77].cnt = 4;

  id0[78].arr[1] = 2;
  id0[78].arr[2] = 3;
  id0[78].arr[3] = 6;
  id0[78].arr[4] = 13;
  id0[78].arr[5] = 26;
  id0[78].arr[6] = 39;
  id0[78].arr[7] = 78;
  id0[78].cnt = 8;

  id0[79].arr[1] = 79;
  id0[79].cnt = 2;

  id0[80].arr[1] = 2;
  id0[80].arr[2] = 4;
  id0[80].arr[3] = 5;
  id0[80].arr[4] = 8;
  id0[80].arr[5] = 10;
  id0[80].arr[6] = 16;
  id0[80].arr[7] = 20;
  id0[80].arr[8] = 40;
  id0[80].arr[9] = 80;
  id0[80].cnt = 10;

  id0[81].arr[1] = 3;
  id0[81].arr[2] = 9;
  id0[81].arr[3] = 27;
  id0[81].arr[4] = 81;
  id0[81].cnt = 5;

  id0[82].arr[1] = 2;
  id0[82].arr[2] = 41;
  id0[82].arr[3] = 82;
  id0[82].cnt = 4;

  id0[83].arr[1] = 83;
  id0[83].cnt = 2;

  id0[84].arr[1] = 2;
  id0[84].arr[2] = 3;
  id0[84].arr[3] = 4;
  id0[84].arr[4] = 6;
  id0[84].arr[5] = 7;
  id0[84].arr[6] = 12;
  id0[84].arr[7] = 14;
  id0[84].arr[8] = 21;
  id0[84].arr[9] = 28;
  id0[84].arr[10] = 42;
  id0[84].arr[11] = 84;
  id0[84].cnt = 12;

  id0[85].arr[1] = 5;
  id0[85].arr[2] = 17;
  id0[85].arr[3] = 85;
  id0[85].cnt = 4;

  id0[86].arr[1] = 2;
  id0[86].arr[2] = 43;
  id0[86].arr[3] = 86;
  id0[86].cnt = 4;

  id0[87].arr[1] = 3;
  id0[87].arr[2] = 29;
  id0[87].arr[3] = 87;
  id0[87].cnt = 4;

  id0[88].arr[1] = 2;
  id0[88].arr[2] = 4;
  id0[88].arr[3] = 8;
  id0[88].arr[4] = 11;
  id0[88].arr[5] = 22;
  id0[88].arr[6] = 44;
  id0[88].arr[7] = 88;
  id0[88].cnt = 8;

  id0[89].arr[1] = 89;
  id0[89].cnt = 2;

  id0[90].arr[1] = 2;
  id0[90].arr[2] = 3;
  id0[90].arr[3] = 5;
  id0[90].arr[4] = 6;
  id0[90].arr[5] = 9;
  id0[90].arr[6] = 10;
  id0[90].arr[7] = 15;
  id0[90].arr[8] = 18;
  id0[90].arr[9] = 30;
  id0[90].arr[10] = 45;
  id0[90].arr[11] = 90;
  id0[90].cnt = 12;

  id0[91].arr[1] = 7;
  id0[91].arr[2] = 13;
  id0[91].arr[3] = 91;
  id0[91].cnt = 4;

  id0[92].arr[1] = 2;
  id0[92].arr[2] = 4;
  id0[92].arr[3] = 23;
  id0[92].arr[4] = 46;
  id0[92].arr[5] = 92;
  id0[92].cnt = 6;

  id0[93].arr[1] = 3;
  id0[93].arr[2] = 31;
  id0[93].arr[3] = 93;
  id0[93].cnt = 4;

  id0[94].arr[1] = 2;
  id0[94].arr[2] = 47;
  id0[94].arr[3] = 94;
  id0[94].cnt = 4;

  id0[95].arr[1] = 5;
  id0[95].arr[2] = 19;
  id0[95].arr[3] = 95;
  id0[95].cnt = 4;

  id0[96].arr[1] = 2;
  id0[96].arr[2] = 3;
  id0[96].arr[3] = 4;
  id0[96].arr[4] = 6;
  id0[96].arr[5] = 8;
  id0[96].arr[6] = 12;
  id0[96].arr[7] = 16;
  id0[96].arr[8] = 24;
  id0[96].arr[9] = 32;
  id0[96].arr[10] = 48;
  id0[96].arr[11] = 96;
  id0[96].cnt = 12;

  id0[97].arr[1] = 97;
  id0[97].cnt = 2;

  id0[98].arr[1] = 2;
  id0[98].arr[2] = 7;
  id0[98].arr[3] = 14;
  id0[98].arr[4] = 49;
  id0[98].arr[5] = 98;
  id0[98].cnt = 6;

  id0[99].arr[1] = 3;
  id0[99].arr[2] = 9;
  id0[99].arr[3] = 11;
  id0[99].arr[4] = 33;
  id0[99].arr[5] = 99;
  id0[99].cnt = 6;

  id0[100].arr[1] = 2;
  id0[100].arr[2] = 4;
  id0[100].arr[3] = 5;
  id0[100].arr[4] = 10;
  id0[100].arr[5] = 20;
  id0[100].arr[6] = 25;
  id0[100].arr[7] = 50;
  id0[100].arr[8] = 100;
  id0[100].cnt = 9;
}
