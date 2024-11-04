#include <stdio.h>
#include <vector>

using namespace std;

const int MAXN = 200000 + 10;
const int MAXQ = 200000 + 10;
const int MAXBSZ = 500;

int n;
int bsz;

int q;

long long as[MAXN];
int ps[MAXN];



int nArrayBlks = 0;



long long arrayBlockSums[MAXN];



bool vis[MAXN];



int nLongCycleBlks = 0;







int longCycleBlocks[MAXBSZ][MAXBSZ + MAXBSZ];



int longCycleBlockSzs[MAXBSZ];



long long longCycleInc[MAXN];



struct RefToCycleBlock {
    int ptCycleBlk;     

    int cycleBlkEntr;   

} refToCycleBlocks[MAXN];







int prefsInCycleBlks[MAXBSZ][MAXBSZ];

void debugPrintInformation() {

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
    printf("number of long cycle blocks: %d\r\n", nLongCycleBlks);
    for(int i = 0; i < nLongCycleBlks; i++) {
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
    for (int i = 0; i < nLongCycleBlks; i++) {
        for(int j = 0; j < nArrayBlks; j++) {
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
    for(int i = 0; i < nArrayBlks; i++) {
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

void initArrayBlkSums() {
    


    

    nArrayBlks = 0;

    

    long long subBlkSum = 0;

    int subSz = 0;

    for(int i = 0; i < n; i++) {

        subBlkSum = subBlkSum + as[i];

        subSz++;

        if(subSz >= bsz) {
            


            if (nArrayBlks > 0) {
                

                subBlkSum += arrayBlockSums[nArrayBlks - 1];
            }

            arrayBlockSums[nArrayBlks] = subBlkSum;

            nArrayBlks++;

            subBlkSum = 0;

            subSz = 0;
        }
    }

    if(subSz > 0) {
        

        if (nArrayBlks > 0) {
            

            subBlkSum += arrayBlockSums[nArrayBlks - 1];
        }

        arrayBlockSums[nArrayBlks] = subBlkSum;

        nArrayBlks++;
    }
}

void initLongCycleBlock() {
    


    

    for(int i = 0; i < n; i++) {
        refToCycleBlocks[i].ptCycleBlk = -1;
    }

    int ptCycleBlock = 0;

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
                


                

                for(int j = 0; j < nArrayBlks; j++) {
                    prefsInCycleBlks[j][ptCycleBlock] = 0;
                }

                

                k = i;

                

                int* blk = longCycleBlocks[ptCycleBlock];

                int sz = 0;

                blk[sz] = k;
                sz++;

                

                RefToCycleBlock* ref = &(refToCycleBlocks[k]);
                ref->ptCycleBlk = ptCycleBlock;
                ref->cycleBlkEntr = 0;

                

                int ptArrayBlock = k / bsz;
                prefsInCycleBlks[ptArrayBlock][ptCycleBlock]++;

                int cCycle = 1;

                

                while(ps[k] != i) {

                    k = ps[k];

                    

                    RefToCycleBlock* ref = &(refToCycleBlocks[k]);
                    ref->ptCycleBlk = ptCycleBlock;
                    ref->cycleBlkEntr = sz;

                    blk[sz] = k;
                    sz++;

                    

                    ptArrayBlock = k / bsz;
                    prefsInCycleBlks[ptArrayBlock][ptCycleBlock]++;

                    cCycle++;

                    if(sz >= bsz && ((lenCycle - cCycle) >= bsz)) {
                        

                        

                        

                        longCycleBlockSzs[ptCycleBlock] = sz;
                        ptCycleBlock++;

                        

                        

                        for(int j = 0; j < nArrayBlks; j++) {
                            prefsInCycleBlks[j][ptCycleBlock] = 0;
                        }

                        blk = longCycleBlocks[ptCycleBlock];
                        sz = 0;
                    }
                }

                

                longCycleBlockSzs[ptCycleBlock] = sz;
                ptCycleBlock++;
            }
        }
    }

    

    nLongCycleBlks = ptCycleBlock;

    

    for (int i = 0; i < nLongCycleBlks; i++) {
        for (int j = 1; j < nArrayBlks; j++) {
            prefsInCycleBlks[j][i] += prefsInCycleBlks[j-1][i];
        }
    }

    

    for(int i = 0; i < nLongCycleBlks; i++) {
        longCycleInc[i] = 0;
    }
}

long long arraySumOfPreviousL(int l) {
    


    if (l < 0 || l >= n) {
        return 0;
    }

    long long sum = 0;

    

    int nblks = l / bsz;

    if(nblks > 0) {
        


        

        sum += arrayBlockSums[nblks - 1];

        

        for(int i = 0; i < nLongCycleBlks; i++) {

            

            

            int pres = prefsInCycleBlks[nblks - 1][i];

            

            long long inc = longCycleInc[i];

            

            sum += (inc * ((long long)pres));
        }
    }

    

    for(int i = nblks * bsz; i <= l; i++) {

        

        sum += as[i];

        RefToCycleBlock* ref = &(refToCycleBlocks[i]);

        

        if(ref->ptCycleBlk != -1) {

            int pt = ref->ptCycleBlk;

            sum += longCycleInc[pt];
        }
    }

    return sum;
}

long long answerQueryOne() {
    

    int l, r;

    scanf("%d%d", &l, &r);

    

    long long sumL = arraySumOfPreviousL(l - 2);

    long long sumR = arraySumOfPreviousL(r - 1);

    return sumR - sumL;
}

void answerQueryTwo() {
    

    int v;

    long long x;

    scanf("%d%lld", &v, &x);

    v--;

    RefToCycleBlock* ref = &(refToCycleBlocks[v]);

    if(ref->ptCycleBlk == -1) {
        

        

        

        long long arrayBlockSumIncs[MAXBSZ];

        for(int i = 0; i < nArrayBlks; i++) {
            arrayBlockSumIncs[i] = 0;
        }

        int k = v;

        as[k] += x;

        

        int ptArrayBlock = k / bsz;

        

        arrayBlockSumIncs[ptArrayBlock] += x;

        while(ps[k] != v) {

            k = ps[k];

            as[k] += x;

            

            ptArrayBlock = k / bsz;

            

            arrayBlockSumIncs[ptArrayBlock] += x;
        }

        

        arrayBlockSums[0] += arrayBlockSumIncs[0];
        for (int i = 1; i < nArrayBlks; i++) {
            

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

void addLongCycleBlock(int* blk, int sz) {
    

    int ptCycleBlock = 0;

    

    while(ptCycleBlock < nLongCycleBlks) {

        if(longCycleBlockSzs[ptCycleBlock] == 0) {
            break;
        }

        ptCycleBlock++;
    }

    

    if(ptCycleBlock >= nLongCycleBlks) {

        nLongCycleBlks++;

        

        for(int j = 0; j < nArrayBlks; j++) {
            prefsInCycleBlks[j][ptCycleBlock] = 0;
        }
    }

    int* blk2 = longCycleBlocks[ptCycleBlock];
    for (int i = 0; i < sz; i++) {
        blk2[i] = blk[i];
    }

    longCycleBlockSzs[ptCycleBlock] = sz;

    

    longCycleInc[ptCycleBlock] = 0;

    

    for(int i = 0; i < sz; i++) {

        int k = blk[i];

        int ptArrayBlock = k / bsz;

        

        prefsInCycleBlks[ptArrayBlock][ptCycleBlock]++;
    }

    for (int i = 1; i < nArrayBlks; i++) {
        long long acc = prefsInCycleBlks[i - 1][ptCycleBlock];
        

        prefsInCycleBlks[i][ptCycleBlock] += acc;
    }

    

    

    for (int i = 0; i < sz; i++) {
        int a = blk[i];
        RefToCycleBlock* ref = &(refToCycleBlocks[a]);
        ref->ptCycleBlk = ptCycleBlock;
        ref->cycleBlkEntr = i;
    }

    

    

}

void transLongCycleIncToArrayBlockSum(int* blk, int sz, long long inc) {
    

    

    

    long long arrayBlockSumIncs[MAXBSZ];

    for (int i = 0; i < nArrayBlks; i++) {
        arrayBlockSumIncs[i] = 0;
    }

    for (int i = 0; i < sz; i++) {
        int a = blk[i];
        as[a] += inc;
        int ptArrayBlock = a / bsz;
        

        arrayBlockSumIncs[ptArrayBlock] += inc;
    }

    arrayBlockSums[0] += arrayBlockSumIncs[0];
    for(int i = 1; i < nArrayBlks; i++) {
        

        arrayBlockSumIncs[i] += arrayBlockSumIncs[i - 1];
        

        arrayBlockSums[i] += arrayBlockSumIncs[i];
    }
}



void insertIntoLongCycleBlock(int* blk, int sz, long long inc, int ptCycleBlock, int offset) {
    

    

    

    

    

    


    int* blk2 = longCycleBlocks[ptCycleBlock];
    int sz2 = longCycleBlockSzs[ptCycleBlock];

    long long inc2 = longCycleInc[ptCycleBlock];

    

    int blk3[MAXBSZ + MAXBSZ];
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

        

        int blk4[MAXBSZ + MAXBSZ];
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

        

        

        

        

        addLongCycleBlock(blk4, sz4);

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

    

    int blk5[MAXBSZ + MAXBSZ];
    int sz5 = sz2;

    for (int i = 0; i < sz2; i++) {
        blk5[i] = blk2[i];
    }

    

    for (int i = 0; i < sz3; i++) {
        blk2[i] = blk3[i];
    }
    longCycleBlockSzs[ptCycleBlock] = sz3;

    

    

    longCycleInc[ptCycleBlock] = 0;

    

    for(int i = 0; i < nArrayBlks; i++) {
        prefsInCycleBlks[i][ptCycleBlock] = 0;
    }

    for (int i = 0; i < sz3; i++) {
        int a = blk3[i];
        int ptArrayBlock = a / bsz;
        

        prefsInCycleBlks[ptArrayBlock][ptCycleBlock]++;
    }

    for(int i = 1; i < nArrayBlks; i++) {
        int acc = prefsInCycleBlks[i - 1][ptCycleBlock];
        

        prefsInCycleBlks[i][ptCycleBlock] += acc;
    }

    

    

    for (int i = 0; i < sz3; i++) {
        int a = blk3[i];
        RefToCycleBlock* ref = &(refToCycleBlocks[a]);
        ref->ptCycleBlk = ptCycleBlock;
        ref->cycleBlkEntr = i;
    }

    

    

    

    

    transLongCycleIncToArrayBlockSum(blk, sz, inc);

    transLongCycleIncToArrayBlockSum(blk5, sz5, inc2);

}



void eraseLongCycleBlock(int ptCycleBlock) {

    

    longCycleBlockSzs[ptCycleBlock] = 0;

    longCycleInc[ptCycleBlock] = 0;

    

    for(int i = 0; i < nArrayBlks; i++) {
        prefsInCycleBlks[i][ptCycleBlock] = 0;
    }

    

    


    

    

}

void linkShortCycles(int si, int sj) {

    

    int blk[MAXBSZ + MAXBSZ];
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
        

        

        addLongCycleBlock(blk, sz);
    }
}

void linkLongCycleWithShortCycle(int si, int sj) {
    

    


    RefToCycleBlock refSi = refToCycleBlocks[si];

    int* blkSi = longCycleBlocks[refSi.ptCycleBlk];

    int blkSj[MAXBSZ + MAXBSZ];
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

    

    

    insertIntoLongCycleBlock(blkSj, szSj, 0, refSi.ptCycleBlk, refSi.cycleBlkEntr + 1);
}

void linkLongCycles(int si, int sj) {
    

    


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

    RefToCycleBlock* refNxt = &(refToCycleBlocks[nxt]);

    if(refNxt->ptCycleBlk == refSj.ptCycleBlk) {
        

        

        

        

        

        

        


        int mid = (szSi + szSj) / 2;

        int pt = 0;
        int pt1 = 0;
        int pt2 = refSj.cycleBlkEntr + 1;
        int pt3 = 0;
        int pt4 = refSi.cycleBlkEntr + 1;

        int blk1[MAXBSZ + MAXBSZ];
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

        

        

        int blk2[MAXBSZ + MAXBSZ];
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

        

        

        addLongCycleBlock(blk1, sz1);

        addLongCycleBlock(blk2, sz2);

        

        

        transLongCycleIncToArrayBlockSum(blkSi, szSi, incSi);

        transLongCycleIncToArrayBlockSum(blkSj, szSj, incSj);

    } else {
        

        


        

        

        

        

        

        

        


        

        RefToCycleBlock* refCur = refNxt;

        int* blkCur = longCycleBlocks[refCur->ptCycleBlk];
        int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

        bck = blkCur[szCur - 1];

        


        int blk1[MAXBSZ + MAXBSZ];
        int sz1 = 0;

        

        for(int i = 0; i <= refSi.cycleBlkEntr; i++) {
            blk1[sz1] = blkSi[i];
            sz1++;
        }

        int blk2[MAXBSZ + MAXBSZ];
        int sz2 = 0;

        

        for(int i = refSj.cycleBlkEntr + 1; i < szSj; i++) {
            blk2[sz2] = blkSj[i];
            sz2++;
        }

        if (sz2 > 0) {
            

            insertIntoLongCycleBlock(blk2, sz2, incSj, refNxt->ptCycleBlk, 0);
        }

        if (sz2 > 0) {
            

            int fnt = blk2[0];

            RefToCycleBlock* refFnt = &(refToCycleBlocks[fnt]);

            insertIntoLongCycleBlock(blk1, sz1, incSi, refFnt->ptCycleBlk, 0);

        } else {
            

            insertIntoLongCycleBlock(blk1, sz1, incSi, refNxt->ptCycleBlk, 0);
        }

        

        refCur = &(refToCycleBlocks[bck]);

        blkCur = longCycleBlocks[refCur->ptCycleBlk];

        szCur = longCycleBlockSzs[refCur->ptCycleBlk];

        nxt = ps[bck];

        refNxt = &(refToCycleBlocks[nxt]);

        while (refNxt->ptCycleBlk != refSj.ptCycleBlk) {

            refCur = refNxt;

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            nxt = ps[bck];

            refNxt = &(refToCycleBlocks[nxt]);
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

        

        

        insertIntoLongCycleBlock(blk1, sz1, incSj, refCur->ptCycleBlk, szCur);

        

        

        if (sz2 > 0) {
            

            RefToCycleBlock* refBck = &(refToCycleBlocks[sj]);

            int szBck = longCycleBlockSzs[refBck->ptCycleBlk];

            insertIntoLongCycleBlock(blk2, sz2, incSi, refBck->ptCycleBlk, szBck);
        }
    }

    

    eraseLongCycleBlock(refSi.ptCycleBlk);

    

    eraseLongCycleBlock(refSj.ptCycleBlk);
}

void turnLongCycleBackToShort(int* blk, int sz, long long inc) {
    

    

    


    


    


    


    

    for (int i = 0; i < sz; i++) {
        int a = blk[i];
        

        refToCycleBlocks[a].ptCycleBlk = -1;
        refToCycleBlocks[a].cycleBlkEntr = -1;
    }

    

    transLongCycleIncToArrayBlockSum(blk, sz, inc);

}

void breakShortCycle(int si, int sj) {
    

}

void breakLongCycle(int si, int sj) {
    

    


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

        RefToCycleBlock* refNxt = &(refToCycleBlocks[nxt]);

        

        

        

        

        if(refNxt->ptCycleBlk == refSi.ptCycleBlk) {

            int blk3[MAXBSZ + MAXBSZ];
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

                addLongCycleBlock(blk3, sz3);

                transLongCycleIncToArrayBlockSum(blk3, sz3, inc);

            } else {
                

                

                

                turnLongCycleBackToShort(blk3, sz3, inc);
            }

        } else {
            

            


            

            RefToCycleBlock* refCur = refNxt;

            int* blkCur = longCycleBlocks[refCur->ptCycleBlk];

            int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            

            int blk3[MAXBSZ + MAXBSZ];
            int sz3 = 0;

            

            for(int i = entrH + 1; i < sz; i++) {
                blk3[sz3] = blk[i];
                sz3++;
            }

            

            insertIntoLongCycleBlock(blk3, sz3, inc, refNxt->ptCycleBlk, 0);

            

            refCur = &(refToCycleBlocks[bck]);

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            nxt = ps[bck];

            refNxt = &(refToCycleBlocks[nxt]);

            while(refNxt->ptCycleBlk != refSi.ptCycleBlk) {

                refCur = refNxt;

                blkCur = longCycleBlocks[refCur->ptCycleBlk];

                szCur = longCycleBlockSzs[refCur->ptCycleBlk];

                bck = blkCur[szCur - 1];

                nxt = ps[bck];

                refNxt = &(refToCycleBlocks[nxt]);
            }

            

            sz3 = 0;

            for(int i = 0; i <= entrL; i++) {
                blk3[sz3] = blk[i];
                sz3++;
            }

            

            insertIntoLongCycleBlock(blk3, sz3, inc, refCur->ptCycleBlk, szCur);
        }

        

        int blk2[MAXBSZ + MAXBSZ];
        int sz2 = 0;

        for(int i = entrL + 1; i <= entrH; i++) {
            blk2[sz2] = blk[i];
            sz2++;
        }

        

        

        if(sz2 >= bsz) {

            addLongCycleBlock(blk2, sz2);

            transLongCycleIncToArrayBlockSum(blk2, sz2, inc);

        } else {
            

            

            turnLongCycleBackToShort(blk2, sz2, inc);
        }

        

        eraseLongCycleBlock(refSi.ptCycleBlk);

    } else {
        


        

        int* blkSi = longCycleBlocks[refSi.ptCycleBlk];
        int szSi = longCycleBlockSzs[refSi.ptCycleBlk];

        int* blkSj = longCycleBlocks[refSj.ptCycleBlk];
        int szSj = longCycleBlockSzs[refSj.ptCycleBlk];

        long long incSi = longCycleInc[refSi.ptCycleBlk];

        long long incSj = longCycleInc[refSj.ptCycleBlk];

        

        int blk2[MAXBSZ + MAXBSZ];
        int sz2 = 0;

        for(int i = refSi.cycleBlkEntr + 1; i < szSi; i++) {
            blk2[sz2] = blkSi[i];
            sz2++;
        }

        

        int blk3[MAXBSZ + MAXBSZ];
        int sz3 = 0;

        for(int i = 0; i <= refSj.cycleBlkEntr; i++) {
            blk3[sz3] = blkSj[i];
            sz3++;
        }

        

        int bck = blkSi[szSi - 1];

        int nxt = ps[bck];

        RefToCycleBlock* refNxt = &(refToCycleBlocks[nxt]);

        

        

        if(refNxt->ptCycleBlk == refSj.ptCycleBlk) {

            

            

            if (sz2 + sz3 >= bsz) {

                if (sz2 > 0) {

                    

                    

                    

                    addLongCycleBlock(blk2, sz2);

                    transLongCycleIncToArrayBlockSum(blk2, sz2, incSi);

                    int bck2 = blk2[sz2 - 1];

                    RefToCycleBlock* ref2 = &(refToCycleBlocks[bck2]);

                    

                    insertIntoLongCycleBlock(blk3, sz3, incSj, ref2->ptCycleBlk, sz2);

                } else {

                    

                    

                    

                    addLongCycleBlock(blk3, sz3);

                    transLongCycleIncToArrayBlockSum(blk3, sz3, incSj);
                }

            } else {

                

                

                turnLongCycleBackToShort(blk2, sz2, incSi);

                turnLongCycleBackToShort(blk3, sz3, incSj);
            }

        } else {
            

            


            

            RefToCycleBlock* refCur = refNxt;

            int* blkCur = longCycleBlocks[refCur->ptCycleBlk];

            int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            

            insertIntoLongCycleBlock(blk2, sz2, incSi, refNxt->ptCycleBlk, 0);

            

            refCur = &(refToCycleBlocks[bck]);

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            nxt = ps[bck];

            refNxt = &(refToCycleBlocks[nxt]);

            while(refNxt->ptCycleBlk != refSj.ptCycleBlk) {

                refCur = refNxt;

                blkCur = longCycleBlocks[refCur->ptCycleBlk];

                szCur = longCycleBlockSzs[refCur->ptCycleBlk];

                bck = blkCur[szCur - 1];

                nxt = ps[bck];

                refNxt = &(refToCycleBlocks[nxt]);
            }

            

            insertIntoLongCycleBlock(blk3, sz3, incSj, refCur->ptCycleBlk, szCur);
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

        refNxt = &(refToCycleBlocks[nxt]);

        

        

        if(refNxt->ptCycleBlk == refSi.ptCycleBlk) {

            

            

            if (sz2 + sz3 >= bsz) {

                if (sz2 > 0) {

                    

                    

                    

                    addLongCycleBlock(blk2, sz2);

                    transLongCycleIncToArrayBlockSum(blk2, sz2, incSj);

                    int bck2 = blk2[sz2 - 1];

                    RefToCycleBlock* ref2 = &(refToCycleBlocks[bck2]);

                    

                    insertIntoLongCycleBlock(blk3, sz3, incSi, ref2->ptCycleBlk, sz2);

                } else {

                    

                    

                    

                    addLongCycleBlock(blk3, sz3);

                    transLongCycleIncToArrayBlockSum(blk3, sz3, incSi);
                }

            } else {
                

                

                turnLongCycleBackToShort(blk2, sz2, incSj);

                turnLongCycleBackToShort(blk3, sz3, incSi);
            }

        } else {
            

            


            

            RefToCycleBlock* refCur = refNxt;

            int* blkCur = longCycleBlocks[refCur->ptCycleBlk];

            int szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            bck = blkCur[szCur - 1];

            

            insertIntoLongCycleBlock(blk2, sz2, incSj, refNxt->ptCycleBlk, 0);

            

            refCur = &(refToCycleBlocks[bck]);

            blkCur = longCycleBlocks[refCur->ptCycleBlk];

            szCur = longCycleBlockSzs[refCur->ptCycleBlk];

            nxt = ps[bck];

            refNxt = &(refToCycleBlocks[nxt]);

            while(refNxt->ptCycleBlk != refSi.ptCycleBlk) {

                refCur = refNxt;

                blkCur = longCycleBlocks[refCur->ptCycleBlk];

                szCur = longCycleBlockSzs[refCur->ptCycleBlk];

                bck = blkCur[szCur - 1];

                nxt = ps[bck];

                refNxt = &(refToCycleBlocks[nxt]);
            }

            

            insertIntoLongCycleBlock(blk3, sz3, incSi, refCur->ptCycleBlk, szCur);
        }

        

        eraseLongCycleBlock(refSi.ptCycleBlk);

        

        eraseLongCycleBlock(refSj.ptCycleBlk);
    }
}

bool isInLongCycle(int si) {

    RefToCycleBlock* ref = &(refToCycleBlocks[si]);

    if(ref->ptCycleBlk >= 0) {
        return true;
    }

    return false;
}

bool isInTheSameCycle(int si, int sj) {

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

void answerQueryThree() {
    

    int si, sj;

    scanf("%d%d", &si, &sj);

    if (si != sj) {

        si--;
        sj--;

        bool isSiInLongCycle = isInLongCycle(si);

        bool isSjInLongCycle = isInLongCycle(sj);

        bool isSameCycle = isInTheSameCycle(si, sj);

        if(isSameCycle) {
            

            if(isSiInLongCycle) {
                breakLongCycle(si, sj);
            } else {
                breakShortCycle(si, sj);
            }

        } else {
            

            if(isSiInLongCycle && isSjInLongCycle) {
                linkLongCycles(si, sj);
            } else if(isSiInLongCycle) {
                linkLongCycleWithShortCycle(si, sj);
            } else if(isSjInLongCycle) {
                linkLongCycleWithShortCycle(sj, si);
            } else {
                linkShortCycles(si, sj);
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

    

    initArrayBlkSums();














    

    initLongCycleBlock();







    scanf("%d", &q);

    for(int i = 0; i < q; i++) {

        int qtype;

        scanf("%d", &qtype);

        if(qtype == 1) {
            

            long long sum = answerQueryOne();

            printf("%lld\r\n", sum);

        } else if(qtype == 2) {
            

            answerQueryTwo();




        } else if(qtype == 3) {
            

            answerQueryThree();



        }
    }

    return 0;
}
