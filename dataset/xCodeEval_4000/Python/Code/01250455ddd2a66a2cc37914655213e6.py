















































































def summa_maksonchik_top_potomu_chto_pishet_cod_na_scretche(n_maksonchik_top_potomu_chto_pishet_cod_na_scretche):
    ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche = 0
    while n_maksonchik_top_potomu_chto_pishet_cod_na_scretche  > 0:
        ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche  += n_maksonchik_top_potomu_chto_pishet_cod_na_scretche
        n_maksonchik_top_potomu_chto_pishet_cod_na_scretche  -= 1
    return ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche   
import sys
n_maksonchik_top_potomu_chto_pishet_cod_na_scretche  = int(sys.stdin.readline())
a_maksonchik_top_potomu_chto_pishet_cod_na_scretche  = []
ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche  = 0
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche  in range(n_maksonchik_top_potomu_chto_pishet_cod_na_scretche):
    a_maksonchik_top_potomu_chto_pishet_cod_na_scretche.append(tuple(map(int, sys.stdin.readline().split())))
b_maksonchik_top_potomu_chto_pishet_cod_na_scretche  = {}
x_maksonchik_top_potomu_chto_pishet_cod_na_scretche  = {} 
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche  in a_maksonchik_top_potomu_chto_pishet_cod_na_scretche:
    if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche [0] not in x_maksonchik_top_potomu_chto_pishet_cod_na_scretche :
        x_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]] = [1, 0]
        b_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche] = 1
    else:
        if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche not in b_maksonchik_top_potomu_chto_pishet_cod_na_scretche:
            b_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche] = 1
        else:
            b_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche] += 1
        x_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]][0] += 1
        x_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]][1] += x_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[0]][0]-1
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in x_maksonchik_top_potomu_chto_pishet_cod_na_scretche.values():
    ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche += i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1] 
y_maksonchik_top_potomu_chto_pishet_cod_na_scretche = {}
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in a_maksonchik_top_potomu_chto_pishet_cod_na_scretche:
    if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1] not in y_maksonchik_top_potomu_chto_pishet_cod_na_scretche:
        y_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]] = [1, 0]
    else:
        y_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]][0] += 1
        y_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]][1] += y_maksonchik_top_potomu_chto_pishet_cod_na_scretche[i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1]][0]-1
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in y_maksonchik_top_potomu_chto_pishet_cod_na_scretche.values():
    ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche += i_maksonchik_top_potomu_chto_pishet_cod_na_scretche[1] 
for i_maksonchik_top_potomu_chto_pishet_cod_na_scretche in b_maksonchik_top_potomu_chto_pishet_cod_na_scretche.values():
    if i_maksonchik_top_potomu_chto_pishet_cod_na_scretche > 1:
        ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche -= summa_maksonchik_top_potomu_chto_pishet_cod_na_scretche(i_maksonchik_top_potomu_chto_pishet_cod_na_scretche-1)
print(ans_maksonchik_top_potomu_chto_pishet_cod_na_scretche) 















































































#maksonchiktoppotomuchtopishetcodnascretche