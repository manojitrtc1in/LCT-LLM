


using namespace std;

const int MAXN = 200000 + 10;
const int MAXQ = 200000 + 10;
const int id11 = 500;

int n;
int bsz;

int q;

long long as[MAXN];
int ps[MAXN];



int id4 = 0;



long long arrayBlockSums[MAXN];



bool vis[MAXN];



int id3 = 0;







int longCycleBlocks[id11][id11 + id11];



int longCycleBlockSzs[id11];



long long longCycleInc[MAXN];



struct RefToCycleBlock {
    int ptCycleBlk;     

    int cycleBlkEntr;   

} refToCycleBlocks[MAXN];







int prefsInCycleBlks[id11][id11];

void id12() {

    printf("array:\r\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", as[i]);
    }
    printf("\r\n");
    printf("permutation:\r\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", ps[i]);
    }
    printf("\r\n");
    printf("number of long cycle blocks: %d\r\n", id3);
    for(int i = 0; i < id3; i++) {
        int* blk = longCycleBlocks[i];
        int sz = longCycleBlockSzs[i];
        if (sz > 0) {
            printf("block %d: ", i);
            for (int j = 0; j < sz; j++) {
                printf("%d ", blk[j]);
            }
            printf("  -   inc: %lld", longCycleInc[i]);
            printf("\r\n");
        }
    }
    printf("prefs:\r\n");
    for (int i = 0; i < id3; i++) {
        for(int j = 0; j < id4; j++) {
            printf("%d ", prefsInCycleBlks[j][i]);
        }
        printf("\r\n");
    }
    printf("refs:\r\n");
    for(int i = 0; i < n; i++) {
        RefToCycleBlock* ref = &(refToCycleBlocks[i]);
        if(ref->ptCycleBlk >= 0) {
            printf("{%d,%d}", ref->ptCycleBlk, ref->cycleBlkEntr);
        } else {
            printf("{} ");
        }
    }
    printf("\r\n");
    printf("arrayBlockSums:\r\n");
    for(int i = 0; i < id4; i++) {
        printf("%lld ", arrayBlockSums[i]);
    }
    printf("\r\n");
}

int blockSize(int nn) {
    

    

    int b = 1;

    int t = 1;

    while(true) {

        while((b + t + t) * (b + t + t) < nn) {
            t = t + t;
        }

        if(t == 1 && (b + t) * (b + t) > nn) {
            break;
        } else {
            b = b + t;
            t = 1;
        }
    }

    if(b < 2) {
        b = 2;
    }

    return  b;
}

void id13() {
    


    

    id4 = 0;

    

    long long id1 = 0;

    int subSz = 0;

    for(int i = 0; i < n; i++) {

        id1 = id1 + as[i];

        subSz++;

        if(subSz >= bsz) {
            


            if (id4 > 0) {
                

                id1 += arrayBlockSums[id4 - 1];
            }

            arrayBlockSums[id4] = id1;

            id4++;

            id1 = 0;

            subSz = 0;
        }
    }

    if(subSz > 0) {
        

        if (id4 > 0) {
            

            id1 += arrayBlockSums[id4 - 1];
        }

        arrayBlockSums[id4] = id1;

        id4++;
    }
}

void id10() {
    


    

    for(int i = 0; i < n; i++) {
        refToCycleBlocks[i].ptCycleBlk = -1;
    }

    int id24 = 0;

    for(int i = 0; i < n; i++) {

        if(!vis[i]) {
            

            int k = i;

            vis[k] = true;

            int lenCycle = 1;

            

            while(ps[k] != i) {

                k = ps[k];

                vis[k] = true;

                lenCycle++;
            }

            if(lenCycle >= bsz) {
                


                

                for(int j = 0; j < id4; j++) {
                    prefsInCycleBlks[j][id24] = 0;
                }

                

                k = i;

                

                int* blk = longCycleBlocks[id24];

                int sz = 0;

                blk[sz] = k;
                sz++;

                

                RefToCycleBlock* ref = &(refToCycleBlocks[k]);
                ref->ptCycleBlk = id24;
                ref->cycleBlkEntr = 0;

                

                int id22 = k / bsz;
                prefsInCycleBlks[id22][id24]++;

                int cCycle = 1;

                

                while(ps[k] != i) {

                    k = ps[k];

                    

                    RefToCycleBlock* ref = &(refToCycleBlocks[k]);
                    ref->ptCycleBlk = id24;
                    ref->cycleBlkEntr = sz;

                    blk[sz] = k;
                    sz++;

                    

                    id22 = k / bsz;
                    prefsInCycleBlks[id22][id24]++;

                    cCycle++;

                    if(sz >= bsz && ((lenCycle - cCycle) >= bsz)) {
                        

                        

                        

                        longCycleBlockSzs[id24] = sz;
                        id24++;

                        

                        

                        for(int j = 0; j < id4; j++) {
                            prefsInCycleBlks[j][id24] = 0;
                        }

                        blk = longCycleBlocks[id24];
                        sz = 0;
                    }
                }

                

                longCycleBlockSzs[id24] = sz;
                id24++;
            }
        }
    }

    

    id3 = id24;

    

    for (int i = 0; i < id3; i++) {
        for (int j = 1; j < id4; j++) {
            prefsInCycleBlks[j][i] += prefsInCycleBlks[j-1][i];
        }
    }

    

    for(int i = 0; i < id3; i++) {
        longCycleInc[i] = 0;
    }
}

long long id6(int l) {
    


    if (l < 0 || l >= n) {
        return 0;
    }

    long long sum = 0;

    

    int id15 = l / bsz;

    if(id15 > 0) {
        


        

        sum += arrayBlockSums[id15 - 1];

        

        for(int i = 0; i < id3; i++) {

            

            

            int pres = prefsInCycleBlks[id15 - 1][i];

            

            long long inc = longCycleInc[i];

            

            sum += (inc * ((long long)pres));
        }
    }

    

    for(int i = id15 * bsz; i <= l; i++) {

        

        sum += as[i];

        RefToCycleBlock* ref = &(refToCycleBlocks[i]);

        

        if(ref->ptCycleBlk != -1) {

            int pt = ref->ptCycleBlk;

            sum += longCycleInc[pt];
        }
    }

    return sum;
}

long long id19() {
    

    int l, r;

    scanf("%d%d", &l, &r);

    

    long long sumL = id6(l - 2);

    long long sumR = id6(r - 1);

    return sumR - sumL;
}

void id26() {
    

    int v;

    long long x;

    scanf("%d%lld", &v, &x);

    v--;

    RefToCycleBlock* ref = &(refToCycleBlocks[v]);

    if(ref->ptCycleBlk == -1) {
        

        

        

        long long arrayBlockSumIncs[id11];

        for(int i = 0; i < id4; i++) {
            arrayBlockSumIncs[i] = 0;
        }

        int k = v;

        as[k] += x;

        

        int id22 = k / bsz;

        

        arrayBlockSumIncs[id22] += x;

        while(ps[k] != v) {

            k = ps[k];

            as[k] += x;

            

            id22 = k / bsz;

            

            arrayBlockSumIncs[id22] += x;
        }

        

        arrayBlockSums[0] += arrayBlockSumIncs[0];
        for (int i = 1; i < id4; i++) {
            

            arrayBlockSumIncs[i] += arrayBlockSumIncs[i - 1];
            arrayBlockSums[i] += arrayBlockSumIncs[i];
        }

    } else {
        

        

        int k = ref->ptCycleBlk;

        do {

            longCycleInc[k] += x;

            int* blk = longCycleBlocks[k];
            int sz = longCycleBlockSzs[k];

            

            int bck = blk[sz - 1];

            

            int nxt = ps[bck];

            

            RefToCycleBlock* ref2 = &(refToCycleBlocks[nxt]);

            k = ref2->ptCycleBlk;

        } while(k != ref->ptCycleBlk);
    }
}

void id0(int* blk, int sz) {
    

    int id24 = 0;

    

    while(id24 < id3) {

        if(longCycleBlockSzs[id24] == 0) {
            break;
        }

        id24++;
    }

    

    if(id24 >= id3) {

        id3++;

        

        for(int j = 0; j < id4; j++) {
            prefsInCycleBlks[j][id24] = 0;
        }
    }

    int* blk2 = longCycleBlocks[id24];
    for (int i = 0; i < sz; i++) {
        blk2[i] = blk[i];
    }

    longCycleBlockSzs[id24] = sz;

    

    longCycleInc[id24] = 0;

    

    for(int i = 0; i < sz; i++) {

        int k = blk[i];

        int id22 = k / bsz;

        

        prefsInCycleBlks[id22][id24]++;
    }

    for (int i = 1; i < id4; i++) {
        long long acc = prefsInCycleBlks[i - 1][id24];
        

        prefsInCycleBlks[i][id24] += acc;
    }

    

    

    for (int i = 0; i < sz; i++) {
        int a = blk[i];
        RefToCycleBlock* ref = &(refToCycleBlocks[a]);
        ref->ptCycleBlk = id24;
        ref->cycleBlkEntr = i;
    }

    

    

}

void id14(int* blk, int sz, long long inc) {
    

    

    

    long long arrayBlockSumIncs[id11];

    for (int i = 0; i < id4; i++) {
        arrayBlockSumIncs[i] = 0;
    }

    for (int i = 0; i < sz; i++) {
        int a = blk[i];
        as[a] += inc;
        int id22 = a / bsz;
        

        arrayBlockSumIncs[id22] += inc;
    }

    arrayBlockSums[0] += arrayBlockSumIncs[0];
    for(int i = 1; i < id4; i++) {
        

        arrayBlockSumIncs[i] += arrayBlockSumIncs[i - 1];
        

        arrayBlockSums[i] += arrayBlockSumIncs[i];
    }
}



void id25(int* blk, int sz, long long inc, int id24, int offset) {
    

    

    

    

    

    


    int* blk2 = longCycleBlocks[id24];
    int sz2 = longCycleBlockSzs[id24];

    long long inc2 = longCycleInc[id24];

    

    int blk3[id11 + id11];
    int sz3 = 0;

    

    if (sz + sz2 >= bsz + bsz) {
        

        

        


        int mid = (sz + sz2) / 2;

        int pt = 0;
        int pt1 = 0;
        int pt2 = 0;

        for (; pt2 < offset && pt < mid; pt++, pt2++) {
            blk3[sz3] = blk2[pt2];
            sz3++;
        }

        if (pt < mid) {
            

            

            for (; pt1 < sz && pt < mid; pt++, pt1++) {
                blk3[sz3] = blk[pt1];
                sz3++;
            }
        }

        if (pt < mid) {
            

            

            for (; pt2 < sz2 && pt < mid; pt++, pt2++) {
                blk3[sz3] = blk2[pt2];
                sz3++;
            }
        }

        

        int blk4[id11 + id11];
        int sz4 = 0;

        

        

        for (; pt2 < offset; pt2++) {
            blk4[sz4] = blk2[pt2];
            sz4++;
        }

        

        for (; pt1 < sz; pt1++) {
            blk4[sz4] = blk[pt1];
            sz4++;
        }

        

        for (; pt2 < sz2; pt2++) {
            blk4[sz4] = blk2[pt2];
            sz4++;
        }

        

        

        

        

        id0(blk4, sz4);

    } else {
        


        for (int i = 0; i < offset; i++) {
            blk3[sz3] = blk2[i];
            sz3++;
        }

        for (int i = 0; i < sz; i++) {
            blk3[sz3] = blk[i];
            sz3++;
        }

        for (int i = offset; i < sz2; i++) {
            blk3[sz3] = blk2[i];
            sz3++;
        }
    }

    

    int blk5[id11 + id11];
    int sz5 = sz2;

    for (int i = 0; i < sz2; i++) {
        blk5[i] = blk2[i];
    }

    

    for (int i = 0; i < sz3; i++) {
        blk2[i] = blk3[i];
    }
    longCycleBlockSzs[id24] = sz3;

    

    

    longCycleInc[id24] = 0;

    

    for(int i = 0; i < id4; i++) {
        prefsInCycleBlks[i][id24] = 0;
    }

    for (int i = 0; i < sz3; i++) {
        int a = blk3[i];
        int id22 = a / bsz;
        

        prefsInCycleBlks[id22][id24]++;
    }

    for(int i = 1; i < id4; i++) {
        int acc = prefsInCycleBlks[i - 1][id24];
        

        prefsInCycleBlks[i][id24] += acc;
    }

    

    

    for (int i = 0; i < sz3; i++) {
        int a = blk3[i];
        RefToCycleBlock* ref = &(refToCycleBlocks[a]);
        ref->ptCycleBlk = id24;
        ref->cycleBlkEntr = i;
    }

    

    

    

    

    id14(blk, sz, inc);

    id14(blk5, sz5, inc2);

}



void id16(int id24) {

    

    longCycleBlockSzs[id24] = 0;

    longCycleInc[id24] = 0;

    

    for(int i = 0; i < id4; i++) {
        prefsInCycleBlks[i][id24] = 0;
    }

    

    


    

    

}

void id29(int si, int sj) {

    

    int blk[id11 + id11];
    int sz = 0;

    blk[sz] = si;
    sz++;

    

    int k = ps[sj];

    while(k != si) {

        blk[sz] = k;
        sz++;

        if(k == sj) {
            

            k = ps[si];
        } else {
            

            k = ps[k];
        }
    }

    if(sz >= bsz) {
        

        

        id0(blk, sz);
    }
}

void id21(int si, int sj) {
    

    


    RefToCycleBlock refSi = refToCycleBlocks[si];

    int* blkSi = longCycleBlocks[refSi.ptCycleBlk];

    int blkSj[id11 + id11];
    int szSj = 0;

    

    

    int k = ps[sj];

    while(k != sj) {

        blkSj[szSj] = k;
        szSj++;

        if(k == sj) {
            

            k = ps[si];
        } else {
            

            k = ps[k];
        }
    }

    

    blkSj[szSj] = sj;
    szSj++;

    

    

    id25(blkSj, szSj, 0, refSi.ptCycleBlk, refSi.cycleBlkEntr + 1);
}

void id2(int si, int sj) {
    

    


    RefToCycleBlock refSi = refToCycleBlocks[si];

    RefToCycleBlock refSj = refToCycleBlocks[sj];

    int* blkSi = longCycleBlocks[refSi.ptCycleBlk];
    int szSi = longCycleBlockSzs[refSi.ptCycleBlk];

    int* blkSj = longCycleBlocks[refSj.ptCycleBlk];
    int szSj = longCycleBlockSzs[refSj.ptCycleBlk];

    long long incSi = longCycleInc[refSi.ptCycleBlk];

    long long incSj = longCycleInc[refSj.ptCycleBlk];

    

    int bck = blkSj[szSj - 1];

    int nxt = ps[bck];

    RefToCycleBlock* id17 = &(refToCycleBlocks[nxt]);

    if(id17->ptCycleBlk == refSj.ptCycleBlk) {
        

        

        

        

        

        

        


        int mid = (szSi + szSj) / 2;

        int pt = 0;
        int pt1 = 0;
        int pt2 = refSj.cycleBlkEntr + 1;
        int pt3 = 0;
        int pt4 = refSi.cycleBlkEntr + 1;

        int blk1[id11 + id11];
        int sz1 = 0;

        

        for(; pt1 <= refSi.cycleBlkEntr && pt < mid; pt1++, pt++) {
            blk1[sz1] = blkSi[pt1];
            sz1++;
        }

        if (pt < mid) {
            

            

            for(; pt2 < szSj && pt < mid; pt2++, pt++) {
                blk1[sz1] = blkSj[pt2];
                sz1++;
            }
        }

        if (pt < mid) {
            

            

            for(; pt3 <= refSj.cycleBlkEntr && pt < mid; pt3++, pt++) {
                blk1[sz1] = blkSj[pt3];
                sz1++;
            }
        }

        if (pt < mid) {
            

            

            for(; pt4 < szSi && pt < mid; pt4++, pt++) {
                blk1[sz1] = blkSi[pt4];
                sz1++;
            }
        }

        

        

        int blk2[id11 + id11];
        int sz2 = 0;

        

        for(; pt1 <= refSi.cycleBlkEntr; pt1++, pt++) {
            blk2[sz2] = blkSi[pt1];
            sz2++;
        }

        

        for(; pt2 < szSj; pt2++, pt++) {
            blk2[sz2] = blkSj[pt2];
            sz2++;
        }

        

        for(; pt3 <= refSj.cycleBlkEntr; pt3++, pt++) {
            blk2[sz2] = blkSj[pt3];
            sz2++;
        }

        

        for(; pt4 < szSi; pt4++, pt++) {
            blk2[sz2] = blkSi[pt4];
            sz2++;
        }

        

        

        id0(blk1, sz1);

        id0(blk2, sz2);

        

        

        id14(blkSi, szSi, incSi);

        id14(blkSj, szSj, incSj);

    } else {
        

        


        

        

        

        

        

        

        


        

        RefToCycleBlock* refCur = id17;

        int* blkCur = longCycleBlocks[refCur->ptCycleBlk];
        int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

        bck = blkCur[szCur - 1];

        


        int blk1[id11 + id11];
        int sz1 = 0;

        

        for(int i = 0; i <= refSi.cycleBlkEntr; i++) {
            blk1[sz1] = blkSi[i];
            sz1++;
        }

        int blk2[id11 + id11];
        int sz2 = 0;

        

        for(int i = refSj.cycleBlkEntr + 1; i < szSj; i++) {
            blk2[sz2] = blkSj[i];
            sz2++;
        }

        if (sz2 > 0) {
            

            id25(blk2, sz2, incSj, id17->ptCycleBlk, 0);
        }

        if (sz2 > 0) {
            

            int fnt = blk2[0];

            RefToCycleBlock* refFnt = &(refToCycleBlocks[fnt]);

            id25(blk1, sz1, incSi, refFnt->ptCycleBlk, 0);

        } else {
            

            id25(blk1, sz1, incSi, id17->ptCycleBlk, 0);
        }

        

        refCur = &(refToCycleBlocks[bck]);

        blkCur = longCycleBlocks[refCur->ptCycleBlk];

        szCur = longCycleBlockSzs[refCur->ptCycleBlk];

        nxt = ps[bck];

        id17 = &(refToCycleBlocks[nxt]);

        while (id17->ptCycleBlk != refSj.ptCycleBlk) {

            refCur = id17;

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            nxt = ps[bck];

            id17 = &(refToCycleBlocks[nxt]);
        }

        


        sz1 = 0;

        

        for(int i = 0; i <= refSj.cycleBlkEntr; i++) {
            blk1[sz1] = blkSj[i];
            sz1++;
        }

        sz2 = 0;

        

        for(int i = refSi.cycleBlkEntr + 1; i < szSi; i++) {
            blk2[sz2] = blkSi[i];
            sz2++;
        }

        

        

        id25(blk1, sz1, incSj, refCur->ptCycleBlk, szCur);

        

        

        if (sz2 > 0) {
            

            RefToCycleBlock* refBck = &(refToCycleBlocks[sj]);

            int id18 = longCycleBlockSzs[refBck->ptCycleBlk];

            id25(blk2, sz2, incSi, refBck->ptCycleBlk, id18);
        }
    }

    

    id16(refSi.ptCycleBlk);

    

    id16(refSj.ptCycleBlk);
}

void id20(int* blk, int sz, long long inc) {
    

    

    


    


    


    


    

    for (int i = 0; i < sz; i++) {
        int a = blk[i];
        

        refToCycleBlocks[a].ptCycleBlk = -1;
        refToCycleBlocks[a].cycleBlkEntr = -1;
    }

    

    id14(blk, sz, inc);

}

void id31(int si, int sj) {
    

}

void id7(int si, int sj) {
    

    


    RefToCycleBlock refSi = refToCycleBlocks[si];

    RefToCycleBlock refSj = refToCycleBlocks[sj];

    

    if(refSi.ptCycleBlk == refSj.ptCycleBlk) {

        int* blk = longCycleBlocks[refSi.ptCycleBlk];
        int sz = longCycleBlockSzs[refSi.ptCycleBlk];

        long long inc = longCycleInc[refSi.ptCycleBlk];

        int entrL = refSi.cycleBlkEntr;

        int entrH = refSj.cycleBlkEntr;

        if(entrH < entrL) {

            entrL = refSj.cycleBlkEntr;

            entrH = refSi.cycleBlkEntr;
        }

        

        int bck = blk[sz - 1];

        int nxt = ps[bck];

        RefToCycleBlock* id17 = &(refToCycleBlocks[nxt]);

        

        

        

        

        if(id17->ptCycleBlk == refSi.ptCycleBlk) {

            int blk3[id11 + id11];
            int sz3 = 0;

            

            for(int i = entrH + 1; i < sz; i++) {
                blk3[sz3] = blk[i];
                sz3++;
            }

            

            for(int i = 0; i <= entrL; i++) {
                blk3[sz3] = blk[i];
                sz3++;
            }

            

            

            if(sz3 >= bsz) {

                id0(blk3, sz3);

                id14(blk3, sz3, inc);

            } else {
                

                

                

                id20(blk3, sz3, inc);
            }

        } else {
            

            


            

            RefToCycleBlock* refCur = id17;

            int* blkCur = longCycleBlocks[refCur->ptCycleBlk];

            int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            

            int blk3[id11 + id11];
            int sz3 = 0;

            

            for(int i = entrH + 1; i < sz; i++) {
                blk3[sz3] = blk[i];
                sz3++;
            }

            

            id25(blk3, sz3, inc, id17->ptCycleBlk, 0);

            

            refCur = &(refToCycleBlocks[bck]);

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            nxt = ps[bck];

            id17 = &(refToCycleBlocks[nxt]);

            while(id17->ptCycleBlk != refSi.ptCycleBlk) {

                refCur = id17;

                blkCur = longCycleBlocks[refCur->ptCycleBlk];

                szCur = longCycleBlockSzs[refCur->ptCycleBlk];

                bck = blkCur[szCur - 1];

                nxt = ps[bck];

                id17 = &(refToCycleBlocks[nxt]);
            }

            

            sz3 = 0;

            for(int i = 0; i <= entrL; i++) {
                blk3[sz3] = blk[i];
                sz3++;
            }

            

            id25(blk3, sz3, inc, refCur->ptCycleBlk, szCur);
        }

        

        int blk2[id11 + id11];
        int sz2 = 0;

        for(int i = entrL + 1; i <= entrH; i++) {
            blk2[sz2] = blk[i];
            sz2++;
        }

        

        

        if(sz2 >= bsz) {

            id0(blk2, sz2);

            id14(blk2, sz2, inc);

        } else {
            

            

            id20(blk2, sz2, inc);
        }

        

        id16(refSi.ptCycleBlk);

    } else {
        


        

        int* blkSi = longCycleBlocks[refSi.ptCycleBlk];
        int szSi = longCycleBlockSzs[refSi.ptCycleBlk];

        int* blkSj = longCycleBlocks[refSj.ptCycleBlk];
        int szSj = longCycleBlockSzs[refSj.ptCycleBlk];

        long long incSi = longCycleInc[refSi.ptCycleBlk];

        long long incSj = longCycleInc[refSj.ptCycleBlk];

        

        int blk2[id11 + id11];
        int sz2 = 0;

        for(int i = refSi.cycleBlkEntr + 1; i < szSi; i++) {
            blk2[sz2] = blkSi[i];
            sz2++;
        }

        

        int blk3[id11 + id11];
        int sz3 = 0;

        for(int i = 0; i <= refSj.cycleBlkEntr; i++) {
            blk3[sz3] = blkSj[i];
            sz3++;
        }

        

        int bck = blkSi[szSi - 1];

        int nxt = ps[bck];

        RefToCycleBlock* id17 = &(refToCycleBlocks[nxt]);

        

        

        if(id17->ptCycleBlk == refSj.ptCycleBlk) {

            

            

            if (sz2 + sz3 >= bsz) {

                if (sz2 > 0) {

                    

                    

                    

                    id0(blk2, sz2);

                    id14(blk2, sz2, incSi);

                    int id9 = blk2[sz2 - 1];

                    RefToCycleBlock* ref2 = &(refToCycleBlocks[id9]);

                    

                    id25(blk3, sz3, incSj, ref2->ptCycleBlk, sz2);

                } else {

                    

                    

                    

                    id0(blk3, sz3);

                    id14(blk3, sz3, incSj);
                }

            } else {

                

                

                id20(blk2, sz2, incSi);

                id20(blk3, sz3, incSj);
            }

        } else {
            

            


            

            RefToCycleBlock* refCur = id17;

            int* blkCur = longCycleBlocks[refCur->ptCycleBlk];

            int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            

            id25(blk2, sz2, incSi, id17->ptCycleBlk, 0);

            

            refCur = &(refToCycleBlocks[bck]);

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            nxt = ps[bck];

            id17 = &(refToCycleBlocks[nxt]);

            while(id17->ptCycleBlk != refSj.ptCycleBlk) {

                refCur = id17;

                blkCur = longCycleBlocks[refCur->ptCycleBlk];

                szCur = longCycleBlockSzs[refCur->ptCycleBlk];

                bck = blkCur[szCur - 1];

                nxt = ps[bck];

                id17 = &(refToCycleBlocks[nxt]);
            }

            

            id25(blk3, sz3, incSj, refCur->ptCycleBlk, szCur);
        }

        

        


        sz2 = 0;

        

        for(int i = refSj.cycleBlkEntr + 1; i < szSj; i++) {
            blk2[sz2] = blkSj[i];
            sz2++;
        }

        sz3 = 0;

        

        for(int i = 0; i <= refSi.cycleBlkEntr; i++) {
            blk3[sz3] = blkSi[i];
            sz3++;
        }

        

        bck = blkSj[szSj - 1];

        nxt = ps[bck];

        id17 = &(refToCycleBlocks[nxt]);

        

        

        if(id17->ptCycleBlk == refSi.ptCycleBlk) {

            

            

            if (sz2 + sz3 >= bsz) {

                if (sz2 > 0) {

                    

                    

                    

                    id0(blk2, sz2);

                    id14(blk2, sz2, incSj);

                    int id9 = blk2[sz2 - 1];

                    RefToCycleBlock* ref2 = &(refToCycleBlocks[id9]);

                    

                    id25(blk3, sz3, incSi, ref2->ptCycleBlk, sz2);

                } else {

                    

                    

                    

                    id0(blk3, sz3);

                    id14(blk3, sz3, incSi);
                }

            } else {
                

                

                id20(blk2, sz2, incSj);

                id20(blk3, sz3, incSi);
            }

        } else {
            

            


            

            RefToCycleBlock* refCur = id17;

            int* blkCur = longCycleBlocks[refCur->ptCycleBlk];

            int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            

            id25(blk2, sz2, incSj, id17->ptCycleBlk, 0);

            

            refCur = &(refToCycleBlocks[bck]);

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            nxt = ps[bck];

            id17 = &(refToCycleBlocks[nxt]);

            while(id17->ptCycleBlk != refSi.ptCycleBlk) {

                refCur = id17;

                blkCur = longCycleBlocks[refCur->ptCycleBlk];

                szCur = longCycleBlockSzs[refCur->ptCycleBlk];

                bck = blkCur[szCur - 1];

                nxt = ps[bck];

                id17 = &(refToCycleBlocks[nxt]);
            }

            

            id25(blk3, sz3, incSi, refCur->ptCycleBlk, szCur);
        }

        

        id16(refSi.ptCycleBlk);

        

        id16(refSj.ptCycleBlk);
    }
}

bool id30(int si) {

    RefToCycleBlock* ref = &(refToCycleBlocks[si]);

    if(ref->ptCycleBlk >= 0) {
        return true;
    }

    return false;
}

bool id5(int si, int sj) {

    RefToCycleBlock* ref = &(refToCycleBlocks[si]);

    

    

    if(ref->ptCycleBlk < 0) {

        int k = si;

        while(ps[k] != si) {

            k = ps[k];

            if(k == sj) {
                return true;
            }
        }

    } else {
        

        RefToCycleBlock* ref2 = &(refToCycleBlocks[sj]);

        if(ref2->ptCycleBlk >= 0) {
            

            int k = ref->ptCycleBlk;

            if(k == ref2->ptCycleBlk) {
                return true;
            }

            do {
                

                int* blk = longCycleBlocks[k];

                int sz = longCycleBlockSzs[k];

                int bck = blk[sz - 1];

                int nxt = ps[bck];

                RefToCycleBlock* ref3 = &(refToCycleBlocks[nxt]);

                k = ref3->ptCycleBlk;

                if(k == ref2->ptCycleBlk) {
                    return true;
                }

            } while(k != ref->ptCycleBlk);
        }
    }

    return false;
}

void id27() {
    

    int si, sj;

    scanf("%d%d", &si, &sj);

    if (si != sj) {

        si--;
        sj--;

        bool id23 = id30(si);

        bool id8 = id30(sj);

        bool id28 = id5(si, sj);

        if(id28) {
            

            if(id23) {
                id7(si, sj);
            } else {
                id31(si, sj);
            }

        } else {
            

            if(id23 && id8) {
                id2(si, sj);
            } else if(id23) {
                id21(si, sj);
            } else if(id8) {
                id21(sj, si);
            } else {
                id29(si, sj);
            }
        }

        

        int tmp = ps[si];

        ps[si] = ps[sj];

        ps[sj] = tmp;
    }
}

int main() {

    scanf("%d", &n);

    

    bsz = blockSize(n);




    

    for(int i = 0; i < n; i++) {
        scanf("%lld", as + i);
    }

    

    for(int i = 0; i < n; i++) {
        scanf("%d", ps + i);
        ps[i]--;
        vis[i] = false;
    }

    

    id13();














    

    id10();







    scanf("%d", &q);

    for(int i = 0; i < q; i++) {

        int qtype;

        scanf("%d", &qtype);

        if(qtype == 1) {
            

            long long sum = id19();

            printf("%lld\r\n", sum);

        } else if(qtype == 2) {
            

            id26();




        } else if(qtype == 3) {
            

            id27();



        }
    }

    return 0;
}
