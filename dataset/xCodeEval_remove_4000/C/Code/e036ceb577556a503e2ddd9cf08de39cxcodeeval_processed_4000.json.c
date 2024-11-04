




























































typedef char byteme;
typedef unsigned int natural;
typedef natural tipo_dato;
typedef long long entero_largo;
typedef unsigned long long entero_largo_sin_signo;
typedef long long bitch_vector;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;


















		do \
		{ \
			size_t id69 = 0; \
			void *array[id48]; \
 			id69 = backtrace(array, id48); \
			id54(formato,__FILE__, __func__, __LINE__,id69,
		} \
		while(0);









void id54(const char *format, ...);


CACA_COMUN_FUNC_STATICA void id53(struct timespec *ts) {


	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;


	clock_gettime(CLOCK_REALTIME, ts);



}

CACA_COMUN_FUNC_STATICA void id50(char *stime) {
	time_t ltime;
	long ms;

	struct tm result;
	struct timespec spec;

	char id64[50];

	ltime = time(NULL);


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id53(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id64, "%ld", ms);
	strcat(stime, id64);
}




void id54(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *id7 = "tiempo: %s; ";
	const char *HEADER =
	"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[id48 + sizeof(HEADER)
	+ sizeof(id7)] = {'\0'};
	char id18[sizeof(id7) + 100] = {'\0'};
	char cadena_timestamp[100] = {'\0'};

	id50(cadena_timestamp);
	sprintf(id18, id7, cadena_timestamp);

	strcpy(formato, id18);
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



CACA_COMUN_FUNC_STATICA char *id17(tipo_dato *arreglo, natural id65,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id12 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id65; i++) {
		id12 += sprintf(ap_buffer + id12,
				"%1d", *(arreglo + i));
		if (i < id65 - 1) {
			*(ap_buffer + id12++) = ',';
		}
	}
	*(ap_buffer + id12) = '\0';
	return ap_buffer;
}

CACA_COMUN_FUNC_STATICA char *id51(natural *arreglo,
		natural id65, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id12 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id65; i++) {
		id12 += sprintf(ap_buffer + id12, "%2u",
				*(arreglo + i));
		if (i < id65 - 1) {
			*(ap_buffer + id12++) = ',';
		}
	}
	*(ap_buffer + id12) = '\0';
	return ap_buffer;
}
char *id15(tipo_dato *matrix, natural id8,
		natural id0, char *buffer) {
	int i, j;
	natural id62 = 0;
	for (i = 0; i < id8; i++) {
		id17(matrix + i * id0, id0,
				buffer + id62);
		id62 += strlen(buffer + id62);
		buffer[id62++] = '\n';
		
	}
	return buffer;
}

CACA_COMUN_FUNC_STATICA char *id59(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id65,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id12 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id65; i++) {
		id12 += sprintf(ap_buffer + id12,
				"%llu", *(arreglo + i));
		if (i < id65 - 1) {
			*(ap_buffer + id12++) = ',';
		}
	}
	*(ap_buffer + id12) = '\0';
	return ap_buffer;
}

CACA_COMUN_FUNC_STATICA char *id17(tipo_dato *arreglo,
		natural id65, char *buffer) {
	return NULL;
}
CACA_COMUN_FUNC_STATICA char *id51(
		natural *arreglo, natural id65, char *buffer) {
	return NULL;
}
char *id15(tipo_dato *matrix, natural id8,
		natural id0, char *buffer) {
	return NULL;
}

CACA_COMUN_FUNC_STATICA char *id59(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id65,
		char *buffer) {
	return NULL;
}






CACA_COMUN_FUNC_STATICA void id13(char s[], char chr,
		char id68) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id68;
		}
		i++;
	}
}

CACA_COMUN_FUNC_STATICA int id35(tipo_dato *matrix,
		int *id24, int *id31, int id37,
		int id25) {
	int id66 = 0;
	int id20 = 0;
	tipo_dato numero = 0;
	char *id44 = NULL;
	char *id4 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id66 < id37
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id20 = 0;
		id4 = linea;
		id13(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id44 = linea;; id44 =
				id4) {
			numero = strtol(id44, &id4, 10);
			if (id4 == id44) {
				break;
			}
			*(matrix + id66 * id25 + id20) =
					numero;
			id20++;
		}
		if (id31) {
			id31[id66] = id20;
		}
		id66++;
		caca_log_debug("las filas son %d, con clos %d", id66,
				id20);
	}

	*id24 = id66;
	free(linea);
	return 0;
}

CACA_COMUN_FUNC_STATICA natural id67(tipo_dato num) {
	natural id46 = 0;
	tipo_dato num_mod = 0;
	num_mod = num;
	while (num_mod) {
		num_mod &= ~(num_mod & (-num_mod));
		id46++;
	}
	return id46;
}

CACA_COMUN_FUNC_STATICA char id10(char letra) {
	return letra - 'a';
}

CACA_COMUN_FUNC_STATICA natural id16(natural *nums,
		natural id33) {
	natural max = 0;
	int i = 0;

	for (i = 0; i < id33; i++) {
		natural num_act = nums[i];
		if (num_act > max) {
			max = num_act;
		}
	}

	return max;
}



CACA_COMUN_FUNC_STATICA char *id36(char *cad, natural id47) {
	char c = cad[0];
	char tmp = '\0';
	natural i = 0;
	natural j = 0;

	caca_log_debug("entrada %s id47 %u", cad, id47);
	while (j < id47 && cad[j] != '\0') {
		caca_log_debug("en j %u car %c", j, cad[j]);
		while (j < id47 && !isalpha(cad[j])) {
			caca_log_debug("brincando j %u car %c", j, cad[j]);
			j++;
		}
		caca_log_debug("aora j %u car %c", j, cad[j]);
		if (j == id47) {
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






CACA_COMUN_FUNC_STATICA bool id49(char c) {
	return c >= '0' && c <= '9';
}

CACA_COMUN_FUNC_STATICA byteme id21(char c) {
	return c - '0';
}

CACA_COMUN_FUNC_STATICA void id2(byteme *a,
		natural id52) {
	natural i = 0;
	natural j = id52 - 1;
	while (i < j) {
		byteme t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
}

CACA_COMUN_FUNC_STATICA void id22(natural *a,
		natural id52) {
	natural i = 0;
	natural j = id52 - 1;
	while (i < j) {
		natural t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
}

CACA_COMUN_FUNC_STATICA natural id55(natural *a,
		natural id52) {
	natural min = id38;
	for (natural i = 0; i < id52; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	return min;
}

CACA_COMUN_FUNC_STATICA natural id40(natural a, natural b) {
	natural r = id38;
	while (a && b) {
		natural tmp = b;
		b = a % b;
		a = tmp;
	}

	if (!a) {
		r = b;
	}
	if (!b) {
		r = a;
	}
	return r;
}







natural id9[PRIMOS_CACA_MAX + 1] = { 0 };
natural id58 = 0;
bool id56[PRIMOS_CACA_MAX + 1] = { 0 };
typedef void (*primos_caca_primo_encontrado_cb)(natural primo,
		natural id19, void *cb_ctx);
typedef void (*primos_caca_compuesto_encontrado_cb)(natural primo,
		natural id19, natural id39, void *cb_ctx);

CACA_COMUN_FUNC_STATICA natural id32(natural limite,
		primos_caca_primo_encontrado_cb id34,
		primos_caca_compuesto_encontrado_cb id57, void *cb_ctx) {
	caca_log_debug("primos asta %u", limite);
	assert_timeout(limite<=PRIMOS_CACA_MAX);
	for (natural i = 2; i <= PRIMOS_CACA_MAX; i++) {
		id56[i] = verdadero;
	}
	for (natural i = 2; i <= limite; i++) {
		if (id56[i]) {


			id9[id58++] = i;


			if (id34) {
				id34(i, id58 - 1, cb_ctx);
			}
		}
		for (natural j = 0; j < id58 && id9[j] * i <= limite;
				j++) {
			id56[id9[j] * i] = falso;
			if (id57) {
				id57(id9[j], j, i, cb_ctx);
			}
			if (!(i % id9[j])) {


				break;
			} else {


			}
		}


	}
	caca_log_debug("generados %u primos", id58);
	return id58;
}







typedef struct bitch_vector_ctx {
	natural bitch_numeros_agregados_tam;
	bitch_vector *bitch_mapa;
} bitch_vector_ctx;

CACA_COMUN_FUNC_STATICA bitch_vector_ctx *id61(natural max_nums) {
	bitch_vector_ctx *bvctx = NULL;
	bvctx = calloc(1, sizeof(bitch_vector_ctx));
	bvctx->bitch_mapa = calloc(((max_nums / (sizeof(bitch_vector) * 8)) + 1),
			sizeof(bitch_vector));
	assert_timeout(bvctx->bitch_mapa);
	return bvctx;
}

CACA_COMUN_FUNC_STATICA bool id26(bitch_vector_ctx *bvctx,
		entero_largo_sin_signo posicion) {
	entero_largo_sin_signo resultado = 0;
	natural id45 = 0;
	natural id11 = 0;

	id45 = posicion / 64;
	id11 = posicion % 64;

	resultado = bvctx->bitch_mapa[id45]
			& (bitch_vector) ((bitch_vector) 1 << id11);

	return !!resultado;
}

CACA_COMUN_FUNC_STATICA void id5(bitch_vector_ctx *bvctx,
		entero_largo_sin_signo posicion) {
	natural id45 = 0;
	natural id11 = 0;

	id45 = posicion / 64;
	id11 = posicion % 64;

	bvctx->bitch_mapa[id45] |= (bitch_vector) ((bitch_vector) 1
			<< id11);
	bvctx->bitch_numeros_agregados_tam++;

}

CACA_COMUN_FUNC_STATICA void id6(bitch_vector_ctx *bvctx,
		entero_largo_sin_signo posicion) {
	int id45 = 0;
	int id11 = 0;
	bitch_vector *bits = bvctx->bitch_mapa;

	id45 = posicion / 64;
	id11 = posicion % 64;

	bits[id45] &= (bitch_vector) ~((bitch_vector) 1 << id11);

	bvctx->bitch_numeros_agregados_tam--;
}

CACA_COMUN_FUNC_STATICA void id41(bitch_vector_ctx *bvctx) {
	free(bvctx->bitch_mapa);
	free(bvctx);
}



typedef struct enlarga_caca_datos {
	natural *primer_factor;
} enlarga_caca_datos;

void id29(natural primo, natural id19, void *cb_ctx) {
	enlarga_caca_datos *d = cb_ctx;
	d->primer_factor[primo] = id19;
}
void id42(natural primo, natural id19,
		natural id39, void *cb_ctx) {
	enlarga_caca_datos *d = cb_ctx;
	natural compuesto = primo * id39;
	d->primer_factor[compuesto] = id19;
}

CACA_COMUN_FUNC_STATICA void id3(natural *a, natural id52,
		natural mcd) {
	natural r = 0;
	for (natural i = 0; i < id52; i++) {
		a[i] /= mcd;
	}
}



CACA_COMUN_FUNC_STATICA natural id23(natural *a, natural id52) {
	natural *id27 = NULL;
	natural *primer_factor = NULL;
	natural *id30 = NULL;
	natural id60 = 0;
	enlarga_caca_datos *d = caca_comun_calloc_local(enlarga_caca_datos);
	natural r = 0;
	natural id28 = 0;
	bitch_vector_ctx *bv = NULL;
	bitch_vector_ctx *id1 = NULL;
	natural mcd = 0;

	id27 = calloc(PRIMOS_CACA_MAX + 1, sizeof(natural));
	assert_timeout(id27);
	primer_factor = calloc(PRIMOS_CACA_MAX + 1, sizeof(natural));
	assert_timeout(primer_factor);
	id30 = calloc(MAX_PRIMOS_ESPERADOS, sizeof(natural));
	assert_timeout(id30);
	id1 = id61(PRIMOS_CACA_MAX + 1);
	assert_timeout(id1);


	mcd = a[0];
	for (natural i = 0; i < id52; i++) {
		mcd = id40(mcd, a[i]);
	}
	caca_log_debug("mcd es %u", mcd);

	id3(a, id52, mcd);

	for (natural i = 0; i < id52; i++) {
		id27[a[i]] += 1;
		caca_log_debug("el num %u aora tiene %u id27", a[i],
				id27[a[i]]);
	}

	d->primer_factor = primer_factor;

	id60 = id32(PRIMOS_CACA_MAX, id29,
			id42, d);
	assert_timeout(id60<=MAX_PRIMOS_ESPERADOS);

	bv = id61(MAX_PRIMOS_ESPERADOS);
	assert_timeout(bv);

	for (natural i = 0; i < id52; i++) {
		natural n = a[i];
		natural id70 = id27[n];
		caca_log_debug("el num ori %u sus ocurencias %u", n, id70);
		if (id26(id1, n)) {
			continue;
		}

		id5(id1, n);

		while (n != 1) {
			natural id63 = primer_factor[n];
			natural id43 = id9[id63];
			if (!id26(bv, id63)) {
				id30[id63] += id70;
				id5(bv, id63);
			}

			caca_log_debug("primer factor de %u es %u", n, id43);

			if (id28 < id30[id63]) {
				id28 = id30[id63];
			}

			n /= id43;
		}

		n = a[i];

		while (n != 1) {
			natural id63 = primer_factor[n];
			natural id43 = id9[id63];
			id6(bv, id63);
			n /= id43;
		}

	}

	id41(bv);

	caca_log_debug("max multiplos %u", id28);
	assert_timeout(id28 < id52);
	if (id28) {
		r = id52 - id28;
	}
	caca_log_debug("max multiplos b %u", id28);

	free(id27);
	free(primer_factor);
	free(id30);
	id41(id1);

	return r;
}

CACA_COMUN_FUNC_STATICA void id14() {
	natural n = 0;
	natural *nums = NULL;
	scanf("%u\n", &n);
	nums = calloc(n, sizeof(natural));
	assert_timeout(nums);
	for (natural i = 0; i < n; i++) {
		scanf("%u", nums + i);
	}
	natural r = id23(nums, n);
	if (!r) {
		r = -1;
	}
	printf("%d\n", r);
	free(nums);
}

int main(void) {
	id14();
	return EXIT_SUCCESS;
}
