
















































typedef unsigned int natural;
typedef int tipo_dato;
typedef long long entero_largo;
typedef unsigned long long entero_largo_sin_signo;
typedef long long bitch_vector;
typedef char byteme;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;


















		do \
		{ \
			size_t id56 = 0; \
			void *array[id38]; \
 			id56 = backtrace(array, id38); \
			id44(formato,__FILE__, __func__, __LINE__,id56,
		} \
		while(0);









void id44(const char *format, ...);

void id42(struct timespec *ts) {


	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;


	clock_gettime(CLOCK_REALTIME, ts);



}

void id39(char *stime) {
	time_t ltime;
	struct tm result;
	long ms;

	struct timespec spec;

	char id47[50];

	ltime = time(NULL);


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id42(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id47, "%ld", ms);
	strcat(stime, id47);
}

void id44(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *id3 = "tiempo: %s; ";
	const char *HEADER =
	"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[id38 + sizeof(HEADER)
	+ sizeof(id3)] = {'\0'};
	char id15[sizeof(id3) + 100] = {'\0'};
	char cadena_timestamp[100] = {'\0'};

	id39(cadena_timestamp);
	sprintf(id15, id3, cadena_timestamp);

	strcpy(formato, id15);
	strcat(formato, HEADER);
	strcat(formato, format);
	strcat(formato, "\n");

	va_start(arg, format);
	va_copy(arg2, arg);
	vprintf(formato, arg2);
	va_end(arg2);
	va_end(arg);
	setbuf(stdout, NULL);
}



static char *id12(tipo_dato *arreglo, int id48,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id7 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id48; i++) {
		id7 += sprintf(ap_buffer + id7,
				"%12d", *(arreglo + i));
		if (i < id48 - 1) {
			*(ap_buffer + id7++) = ',';
		}
	}
	*(ap_buffer + id7) = '\0';
	return ap_buffer;
}

static char *id40(natural *arreglo,
		natural id48, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id7 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id48; i++) {
		id7 += sprintf(ap_buffer + id7, "%2u",
				*(arreglo + i));
		if (i < id48 - 1) {
			*(ap_buffer + id7++) = ',';
		}
	}
	*(ap_buffer + id7) = '\0';
	return ap_buffer;
}
char *id9(tipo_dato *matrix, natural id4,
		natural id0, char *buffer) {
	int i, j;
	natural id46 = 0;
	for (int i = 0; i < id4; i++) {
		id12(matrix + i * id0, id0,
				buffer + id46);
		id46 += strlen(buffer + id46);
		buffer[id46++] = '\n';
		
	}
	return buffer;
}

static char *id45(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id48,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id7 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id48; i++) {
		id7 += sprintf(ap_buffer + id7,
				"%llu", *(arreglo + i));
		if (i < id48 - 1) {
			*(ap_buffer + id7++) = ',';
		}
	}
	*(ap_buffer + id7) = '\0';
	return ap_buffer;
}

static char *id12(tipo_dato *arreglo, int id48,
		char *buffer) {
	return NULL;
}
static char *id40(natural *arreglo,
		natural id48, char *buffer) {
	return NULL;
}
char *id9(tipo_dato *matrix, natural id4,
		natural id0, char *buffer) {
	return NULL;
}

static char *id45(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id48,
		char *buffer) {
	return NULL;
}

void id8(char s[], char chr, char id55) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id55;
		}
		i++;
	}
}

static int id23(tipo_dato *matrix, int *id18,
		int *id20, int id25, int id19) {
	int id51 = 0;
	int id17 = 0;
	tipo_dato numero = 0;
	char *id31 = NULL;
	char *id2 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id51 < id25
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id17 = 0;
		id2 = linea;
		id8(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id31 = linea;; id31 =
				id2) {
			numero = strtol(id31, &id2, 10);
			if (id2 == id31) {
				break;
			}
			*(matrix + id51 * id19 + id17) =
					numero;
			id17++;
		}
		if (id20) {
			id20[id51] = id17;
		}
		id51++;
		caca_log_debug("las filas son %d, con clos %d", id51,
				id17);
	}

	*id18 = id51;
	free(linea);
	return 0;
}

static inline natural id54(tipo_dato num) {
	natural id34 = 0;
	tipo_dato num_mod = 0;
	num_mod = num;
	while (num_mod) {
		num_mod &= ~(num_mod & (-num_mod));
		id34++;
	}
	return id34;
}

static inline char id5(char letra) {
	return letra - 'a';
}

static inline natural id10(natural *nums, natural id22) {
	natural max = 0;

	for (int i = 0; i < id22; i++) {
		natural num_act = nums[i];
		if (num_act > max) {
			max = num_act;
		}
	}

	return max;
}



static inline char *id24(char *cad, natural id35) {
	char c = cad[0];
	char tmp = '\0';
	natural i = 0;
	natural j = 0;

	caca_log_debug("entrada %s id35 %u", cad, id35);
	while (j < id35 && cad[j] != '\0') {
		caca_log_debug("en j %u car %c", j, cad[j]);
		while (j < id35 && !isalpha(cad[j])) {
			caca_log_debug("brincando j %u car %c", j, cad[j]);
			j++;
		}
		caca_log_debug("aora j %u car %c", j, cad[j]);
		if (j == id35) {
			caca_log_debug("q ped");
			break;
		}
		tmp = cad[i];
		cad[i] = cad[j];
		cad[j] = tmp;
		i++;
		j++;
	}
	caca_log_debug("mierda '%c'", cad[j]);

	i = 0;
	while (isalpha(cad[i++]))
		;
	caca_log_debug("salida %s", cad);
	cad[i - 1] = '\0';

	return cad;
}






typedef struct numero_orden {
	int numero;
	natural posicion_inicial;
} numero_orden;

static int id21(const void *pa, const void *pb) {
	numero_orden *a = (numero_orden *) pa;
	numero_orden *b = (numero_orden *) pb;
	int r = 0;

	r = a->numero - b->numero;

	if (!r) {
		r = a->posicion_inicial - b->posicion_inicial;
	}

	assert(r);

	return r;
}

static inline natural *id50(natural *nums,
		natural id22, natural *nums_res, natural id6) {
	numero_orden *nums_ord = NULL;

	assert(id6 >= id22);

	nums_ord = calloc(id22, sizeof(numero_orden));
	assert(nums_ord);

	for (natural i = 0; i < id22; i++) {
		numero_orden *id30 = nums_ord + i;

		id30->numero = nums[i];
		id30->posicion_inicial = i;
	}

	qsort(nums_ord, id22, sizeof(numero_orden), id21);

	for (natural i = 0; i < id22; i++) {
		numero_orden *id30 = nums_ord + i;
		nums_res[id30->posicion_inicial] = i;
	}

	free(nums_ord);
	return nums_res;
}






typedef struct bit_ch {
	natural num_nodos_bit_ch;
	tipo_dato *nodos_bit_ch;
} bit_ch;

static inline void id11(bit_ch *bit, tipo_dato id32,
		natural idx);

static inline void id14(bit_ch *bit, tipo_dato id33,
		natural id41) {
	tipo_dato *nodos = NULL;

	bit->num_nodos_bit_ch = id41 + 2;

	bit->nodos_bit_ch = calloc(bit->num_nodos_bit_ch, sizeof(tipo_dato));
	nodos = bit->nodos_bit_ch;

	nodos[0] = (tipo_dato) BIT_CH_VALOR_INVALIDO;
	for (natural i = 1; i < bit->num_nodos_bit_ch; i++) {
		nodos[i] = 0;
	}

	id11(bit, id33, 1);
}

static inline void id43(bit_ch *bit) {
	free(bit->nodos_bit_ch);
}

static inline void id11(bit_ch *bit, tipo_dato id32,
		natural idx) {
	tipo_dato *nodos = bit->nodos_bit_ch;
	caca_log_debug("q verga actualizando %u con %d", idx, id32);
	for (natural i = idx; i && i < bit->num_nodos_bit_ch; i += (i & (-i))) {
		caca_log_debug("actualizando caca %u con %d antes %d", i, id32,
				nodos[i]);
		nodos[i] += id32;
		caca_log_debug("actualizado caca %u aora %d", i, nodos[i]);
	}
}

static inline tipo_dato id13(bit_ch *bit, natural idx) {
	tipo_dato *nodos = bit->nodos_bit_ch;
	tipo_dato res = 0;
	for (int i = idx; i > 0; i -= (i & (-i))) {
		assert_timeout(i < bit->num_nodos_bit_ch);
		caca_log_debug("consultando caca %u tiene %u", i, nodos[i]);
		res += nodos[i];
	}
	caca_log_debug("regresando %d", res);
	return res;
}

static inline tipo_dato id49(bit_ch *bit,
		natural i, natural j) {
	return id13(bit, j) - id13(bit, i - 1);
}

static inline tipo_dato id36(bit_ch *bit, natural i) {
	return id49(bit, i,
			bit->num_nodos_bit_ch - 1);
}

static inline void id26(bit_ch *bit, tipo_dato id32,
		natural idx_ini, natural idx_fin) {
	caca_log_debug("aumentando de %u a %u con valor %llu", idx_ini, idx_fin,
			id32);

	id11(bit, id32, idx_ini);
	id11(bit, -id32, idx_fin + 1);
}

static inline void id28(bit_ch *id53,
		bit_ch *bit_aux, natural idx_ini, natural idx_fin,
		tipo_dato id32) {

	caca_log_debug("aumentando de %u a %u con valor %llu para consulta rango",
			idx_ini, idx_fin, id32);

	id26(id53, id32, idx_ini, idx_fin);
	caca_log_debug(
			"actualizando para consulta rango inicial %d con %llu (%llu * %u)",
			idx_ini, id32 * (idx_ini - 1), id32, idx_ini - 1);
	id11(bit_aux, id32 * (idx_ini - 1), idx_ini);
	caca_log_debug(
			"actualizando para consulta rango final %d con %llu(%llu,%u)",
			idx_fin + 1, -id32 * idx_fin, -id32, idx_fin);
	id11(bit_aux, -id32 * idx_fin, idx_fin + 1);
}

static inline tipo_dato id16(
		bit_ch *id53, bit_ch *bit_aux, natural idx) {
	tipo_dato resul = 0;
	tipo_dato id29 = 0;
	tipo_dato valor_aux = 0;

	id29 = id13(id53, idx);

	caca_log_debug("el valor putual en %u es %llu, aportara %llu (%llu * %u)",
			idx, id29, id29 * idx, id29, idx);

	valor_aux = id13(bit_aux, idx);

	caca_log_debug("el valor aux en %u es %llu", idx, id29);

	resul = id29 * idx - valor_aux;

	caca_log_debug("la suma acumulacaca hasta %u es %llu", idx, resul);

	return resul;
}

static inline tipo_dato id52(bit_ch *id53, bit_ch *bit_aux,
		natural idx_ini, natural idx_fin) {
	tipo_dato resul = 0;
	tipo_dato id1 = 0;
	tipo_dato id27 = 0;

	id1 = id16(id53, bit_aux,
			idx_ini - 1);
	caca_log_debug("la suma acumulacaca ini hasta %u es %llu", idx_ini,
			id1);

	id27 = id16(id53, bit_aux,
			idx_fin);
	caca_log_debug("la suma acumulacaca fin hasta %u es %llu", idx_fin,
			id27);

	resul = id27 - id1;

	caca_log_debug("la suma acumulacaca del rango %u-%u es %llu", idx_ini,
			idx_fin, resul);

	return resul;
}



static inline natural modifica(bit_ch *bi, bit_ch *bd, natural *a, natural i,
		bool quitar) {
	natural inv = 0;
	bit_ch *bm = NULL;
	int factor = 0;
	inv = id36(bi, a[i] + 1) + id13(bd, a[i] - 1);

	if (quitar) {
		bm = bd;
		factor = -1;
	} else {
		bm = bi;
		factor = 1;
	}
	caca_log_debug("el puto factor %d", factor);

	id11(bm, factor, a[i]);
	caca_log_debug("las inv al %s %u son %u", quitar?"quitar":"poner", a[i],
			inv);

	return inv;
}

static inline natural quita(bit_ch *bi, bit_ch *bd, natural *a, natural i) {
	return modifica(bi, bd, a, i, verdadero);
}

static inline natural anade(bit_ch *bi, bit_ch *bd, natural *a, natural i) {
	return modifica(bi, bd, a, i, falso);
}

static inline entero_largo_sin_signo core(natural *nums, natural id22,
		entero_largo_sin_signo k) {
	entero_largo_sin_signo inv = 0;
	bit_ch *bi = caca_comun_calloc_local(bit_ch);
	bit_ch *bd = caca_comun_calloc_local(bit_ch);
	natural j = 0;
	entero_largo_sin_signo r = 0;
	natural *a = NULL;

	a = calloc(id22, sizeof(natural));
	assert_timeout(a);

	id50(nums, id22, a, id22);
	for (natural i = 0; i < id22; i++) {
		a[i]++;
	}
	caca_log_debug("mapeados %s",
			id40(a, id22, CACA_COMUN_BUF_STATICO));

	id14(bi, 0, id22);
	id14(bd, 0, id22);

	for (natural i = 0; i < id22; i++) {
		inv += id36(bd, a[i]);
		id11(bd, 1, a[i]);
		caca_log_debug("anadiendo %u en pos %u inv %llu", a[i], i, inv);
	}

	caca_log_debug("inv totales %llu", inv);

	inv += anade(bi, bd, a, 0);
	caca_log_debug("inv ini %llu", inv);
	for (natural i = 1; i < id22; i++) {
		while (j < id22 && (j < i || inv > k)) {
			inv -= quita(bi, bd, a, j);
			j++;
			caca_log_debug("kitando %u en pos %u inv %llu", a[j-1], j-1, inv);
		}

		r += id22 - j;

		caca_log_debug("en %u %u inv %llu r %llu", i, j, inv, r)

		inv += anade(bi, bd, a, i);
	}

	id43(bi);
	id43(bd);

	return r;
}


natural a[id37] = { 0 };

int main() {
	natural n = 0;
	entero_largo_sin_signo k = 0;

	scanf("%u %llu\n", &n, &k);
	assert_timeout(n<=id37);
	assert_timeout(k <= ((entero_largo_sin_signo )(1E18)));

	for (natural i = 0; i < n; i++) {
		scanf("%u", &a[i]);
	}

	printf("%llu\n", core(a, n, k));
	return EXIT_SUCCESS;
}
