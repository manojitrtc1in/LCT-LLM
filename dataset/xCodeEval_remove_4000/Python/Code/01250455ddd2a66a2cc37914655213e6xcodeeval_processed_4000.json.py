















































































def id0(id6):
    id1 = 0
    while id6  > 0:
        id1  += id6
        id6  -= 1
    return id1   
import sys
id6  = int(sys.stdin.readline())
id2  = []
id1  = 0
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche  in range(id6):
    id2.append(tuple(map(int, sys.stdin.readline().split())))
id4  = {}
id5  = {} 
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche  in id2:
    if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche [0] not in id5 :
        id5[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]] = [1, 0]
        id4[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche] = 1
    else:
        if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche not in id4:
            id4[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche] = 1
        else:
            id4[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche] += 1
        id5[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]][0] += 1
        id5[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]][1] += id5[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]][0]-1
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in id5.values():
    id1 += i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1] 
id3 = {}
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in id2:
    if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1] not in id3:
        id3[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]] = [1, 0]
    else:
        id3[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]][0] += 1
        id3[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]][1] += id3[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]][0]-1
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in id3.values():
    id1 += i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1] 
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in id4.values():
    if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche > 1:
        id1 -= id0(i_maksonchik_top_potomu_chto_pishet_cod_na_scretche-1)
print(id1) 















































































