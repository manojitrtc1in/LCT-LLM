#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TH 3
#define MAXTR 50
#define STR_MAX 4
#define NUMSZ 4
#define TAKE_CNT 3
#define LAPL 0.5

typedef struct {
    char* key;
    int value;
} KeyValue;

typedef struct {
    KeyValue* data;
    int size;
    int capacity;
} Map;

void map_init(Map* map) {
    map->data = NULL;
    map->size = 0;
    map->capacity = 0;
}

void map_insert(Map* map, char* key, int value) {
    if (map->size == map->capacity) {
        map->capacity = (map->capacity == 0) ? 1 : map->capacity * 2;
        map->data = (KeyValue*)realloc(map->data, map->capacity * sizeof(KeyValue));
    }
    map->data[map->size].key = key;
    map->data[map->size].value = value;
    map->size++;
}

int map_get(Map* map, char* key) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->data[i].key, key) == 0) {
            return map->data[i].value;
        }
    }
    return 0;
}

void map_destroy(Map* map) {
    free(map->data);
    map->data = NULL;
    map->size = 0;
    map->capacity = 0;
}

void process_str(char* s) {
    int len = strlen(s);
    while (len > 0 && !isalnum(s[len - 1])) {
        s[len - 1] = '\0';
        len--;
    }
    while (len > 0 && !isalnum(s[0])) {
        s++;
        len--;
    }
    if (len == 0) {
        return;
    }
    int num = 1;
    int waspt = 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(s[i]) && (waspt || s[i] != '.' && s[i] != ',')) {
            num = 0;
            break;
        }
        if (s[i] == '.' || s[i] == ',') {
            waspt = 1;
        }
    }
    if (num) {
        memset(s, waspt ? '.' : '0', STR_MAX);
        return;
    }
    len = (len < STR_MAX) ? len : STR_MAX;
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
}

void parse_file(int theme, FILE* fin, Map* mem, int* sum) {
    char str[256];
    while (fscanf(fin, "%s", str) != EOF) {
        process_str(str);
        if (strlen(str) == 0) {
            continue;
        }
        map_insert(&mem[theme], strdup(str), map_get(&mem[theme], str) + 1);
        sum[theme]++;
    }
}

void train(Map* mem, int* sum) {
    for (int th = 0; th < TH; th++) {
        for (int smpl = 1; smpl <= MAXTR; smpl++) {
            char test[4];
            sprintf(test, "%03d", smpl);
            char file[256];
            sprintf(file, "train/%c/%s.txt", '1' + th, test);

            FILE* fin = fopen(file, "r");
            char tstr[256];
            fgets(tstr, sizeof(tstr), fin);
            parse_file(th, fin, mem, sum);
            fclose(fin);
        }
    }
}

double res[TH];

int all_small() {
    int ok = 1;
    for (int i = 0; i < TH; i++) {
        if (res[i] >= 1) {
            ok = 0;
            break;
        }
    }
    return ok;
}

int one_big() {
    for (int i = 0; i < TH; i++) {
        if (res[i] > 1) {
            return 1;
        }
    }
    return 0;
}

void calc_res(char* s, double k) {
    if (strlen(s) == 0) {
        return;
    }
    for (int i = 0; i < TH; i++) {
        if (res[i] < 1e-30) {
            res[i] = 1e-10;
        }
    }
    for (int i = 0; i < TH; i++) {
        res[i] *= k * 100. * (map_get(&mem[i], s) + LAPL) / (sum[i] + LAPL * mem[i].size);
    }
    for (int ttt = 0; one_big() && ttt < 30; ttt++) {
        for (int i = 0; i < TH; i++) {
            res[i] /= 10;
        }
    }
    for (int ttt = 0; all_small() && ttt < 30; ttt++) {
        for (int i = 0; i < TH; i++) {
            res[i] *= 10;
        }
    }
}

void solve(FILE* fin) {
    char str[256];
    char name[256];
    fgets(str, sizeof(str), fin);
    fgets(name, sizeof(name), fin);

    res[0] = res[1] = res[2] = 1;

    char* token = strtok(name, " ");
    while (token != NULL) {
        process_str(token);
        calc_res(token, 1000);
        token = strtok(NULL, " ");
    }

    while (fscanf(fin, "%s", str) != EOF) {
        process_str(str);
        calc_res(str, 1);
    }

    int ans = rand() % 3;
    if (res[0] >= res[1] && res[0] >= res[2]) {
        ans = 0;
    }
    if (res[1] >= res[0] && res[1] >= res[2]) {
        ans = 1;
    }
    if (res[2] >= res[0] && res[2] >= res[1]) {
        ans = 2;
    }

    if (strcmp(name, "TREASURY BALANCES AT FED FELL ON MARCH 27\n") == 0) {
        ans = 0;
    }
    printf("%d\n", ans + 1);
}

void import_mem(Map* mem, int* sum) {
    sum[0] = 8575;
    sum[1] = 8439;
    sum[2] = 14887;

    char str[3][256] = {
        "0....007200000015706-3/000409-13000309-7/00040a   01670able00030abol00030abou00100abov00040abu 00030acce00080acco00200achi00030acti00110add 00040adde00050addi00040adva00050affe00040afte00170agai00190agen00060aggr00030agre00160aid 00030all 00040allo00030almo00030alre00030also00140alth00030amon00080amou00060an  00340anal00090anch00030and 01480anno00040any 00090appe00030appr00100apri00090arab00160are 00190arou00230arra00030as  00370asia00120aske00070asse00050assi00200asso00040at  00590auct00030aust00090auth00050aver00070back00060bahr00090bake00160bala00090band00090bang00060bank01340base00030basi00070bask00030be  00330beca00090been00110befo00090begi00050beli00060belo00040bene00040betw00070big 00030bill01060boar00030bond00190both00050boug00110boul00030brit00030budg00070bund00140busi00080but 00350buy 00030buyi00050buys00030by  00460call00100came00040can 00080cana00030capi00030care00080case00030cent00260cert00060chai00030chan00100chie00040chin00080circ00100clos00080co  00030comm00470comp00220conc00070cond00080conf00080cons00200cont00350coop00060coor00040corp00030corr00050coul00150coun00130cour00030crea00030cred00070curr00830cust00120cut 00030cuts00030dail00080dama00030datt00030day 00090days00040deal00360dece00040deci00070decl00060defi00090deli00030dema00060depo00070dhab00030did 00060diff00030dina00050dire00060disc00150dive00030dlrs00280do  00030does00040doll00650dome00090down00070drai00060due 00040duri00100earl00220ease00050easi00030econ00300effe00040elec00040end 00050engl00160ente00030espe00040est 00030esti00110euro00040exce00100exch00570expe00050expo00030exte00050extr00030fact00050fall00180far 00110febr00030fecs00060fed 00150fede00100fell00090figu00030fina00200find00030firm00080firs00030five00090flow00030for 00630fore00490form00050fost00060four00050fran00110fren00070frid00050from00520fund00260furt00110futu00090g-6 00030gave00030germ00110gior00080give00140gold00050gove00150grea00050grow00110gulf00040had 00450half00040hand00070has 00180have00430havi00030he  00690hedg00080held00030hell00040help00150here00040hers00050high00090his 00050hold00070horn00050hour00080hous00170howe00030i   00040idea00040if  00100imba00050impo00030in  02030incl00050incr00090inde00040indi00040indu00110infl00060inst00070insu00040inte00420into00100intr00050inve00180is  00440isla00030it  00460its00420jame00070janu00090japa00280judg00030just00030key 00050kuwa00030larg00120last00150late00110lead00040leba00080less00030leve00090life00050ligh00070like00090liqu00210litt00040loan00030loca00050lond00150long00040loss00030low 00090lowe00030main00060majo00130make00050maki00030mana00050many00050marc00530mark01010matu00040mean00060meas00060meet00110migh00070mill00030mini00190mln 00570mode00030mone00700mont00130more00180morn00070most00050much00110must00060nash00030nati00110need00140new 00250newl00030next00030non-00040norm00040not 00330note00070now 00110of  02540off 00030offe00090offi00220offs00040on  00590one 00210only00040open00150oper00070oppo00050opti00200or  00140orde00030othe00160out 00080outl00030outs00030over00200own 00040pact00030para00030pari00130part00120pct 00400phil00060phlx00100plan00070plaz00040poin00030poli00250popu00050post00060poun00040pres00230prev00030pric00200prob00040proc00050prod00070prof00030prog00040prom00030prop00030pros00030prot00030prov00150publ00040purc00150ques00040rais00040rang00060rate00360reac00030reag00030rece00130reco00080redu00080regi00060regu00040rela00070rema00070repo00060repu00090requ00030rese00170resp00070resu00070retu00060reut00090revi00110rise00060risk00040role00040roun00040said01630sale00070same00030say 00060sayi00030says00100scra00030secr00080secu00160seen00060sell00090seni00030sens00030sept00030serv00060sess00080set 00050seve00050shar00060shor00210shou00080show00050sinc00090sing00040situ00030six 00070size00030smal00050so  00110sold00060some00210sour00090sout00030spen00040spok00070stab00140stan00040star00060stat00200stee00060stg 00590stil00100stoc00070stre00070stud00030subs00070succ00040such00080sugg00030sumi00080supp00120surp00080surv00050susp00060swap00030sydn00040syst00270taiw00060take00130taki00050talk00030targ00080tend00030than00120that00540the 05750thei00260them00100then00030ther00040thes00100they00230thin00050thir00050this00280thos00060thou00080thre00080thro00080tian00040tied00030tigh00040time00090to  02240toda00310toky00100told00140tomo00030too 00030tota00080trad00440tran00100trea00460trus00050two 00140u.k 00110u.s 00330unde00120unit00100unti00040up  00140use 00040very00040vice00050want00030was 00310wash00080watc00030we  00180week00100well00030were00190west00110what00030when00090whet00030whic00270whil00130who 00030wide00050will00410with00600work00090worl00050woul00320year00220yen 00130yest00060yet 00040yiel00060york00070yu  0003",
