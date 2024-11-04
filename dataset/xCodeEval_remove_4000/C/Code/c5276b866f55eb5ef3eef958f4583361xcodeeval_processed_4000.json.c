






















































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
			size_t id50 = 0; \
			void *array[id35]; \
 			id50 = backtrace(array, id35); \
			id40(formato,__FILE__, __func__, __LINE__,id50,
		} \
		while(0);









void id40(const char *format, ...);

void id39(struct timespec *ts) {


	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;


	clock_gettime(CLOCK_REALTIME, ts);



}

void id36(char *stime) {
	time_t ltime;
	struct tm result;
	long ms;

	struct timespec spec;

	char id44[50];

	ltime = time(NULL);


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id39(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id44, "%ld", ms);
	strcat(stime, id44);
}

void id40(const char *format, ...) {

	va_list arg;
	va_list arg2;
	const char *id2 = "tiempo: %s; ";
	const char *HEADER =
	"archivo: %s; funcion: %s; linea %d; nivel: %zd caca 8====D ";
	char formato[id35 + sizeof(HEADER)
	+ sizeof(id2)] = {'\0'};
	char id16[sizeof(id2) + 100] = {'\0'};
	char cadena_timestamp[100] = {'\0'};

	id36(cadena_timestamp);
	sprintf(id16, id2, cadena_timestamp);

	strcpy(formato, id16);
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



static char *id15(tipo_dato *arreglo, int id45,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id6 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id45; i++) {
		id6 += sprintf(ap_buffer + id6,
				"%12d", *(arreglo + i));
		if (i < id45 - 1) {
			*(ap_buffer + id6++) = ',';
		}
	}
	*(ap_buffer + id6) = '\0';
	return ap_buffer;
}

static char *id37(natural *arreglo,
		natural id45, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id6 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id45; i++) {
		id6 += sprintf(ap_buffer + id6, "%2u",
				*(arreglo + i));
		if (i < id45 - 1) {
			*(ap_buffer + id6++) = ',';
		}
	}
	*(ap_buffer + id6) = '\0';
	return ap_buffer;
}
char *id8(tipo_dato *matrix, natural id3,
		natural id0, char *buffer) {
	int i, j;
	natural id42 = 0;
	for (int i = 0; i < id3; i++) {
		id15(matrix + i * id0, id0,
				buffer + id42);
		id42 += strlen(buffer + id42);
		buffer[id42++] = '\n';
		
	}
	return buffer;
}

static char *id41(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id45,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id6 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id45; i++) {
		id6 += sprintf(ap_buffer + id6,
				"%llu", *(arreglo + i));
		if (i < id45 - 1) {
			*(ap_buffer + id6++) = ',';
		}
	}
	*(ap_buffer + id6) = '\0';
	return ap_buffer;
}

static char *id15(tipo_dato *arreglo, int id45,
		char *buffer) {
	return NULL;
}
static char *id37(natural *arreglo,
		natural id45, char *buffer) {
	return NULL;
}
char *id8(tipo_dato *matrix, natural id3,
		natural id0, char *buffer) {
	return NULL;
}

static char *id41(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id45,
		char *buffer) {
	return NULL;
}

void id7(char s[], char chr, char id49) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id49;
		}
		i++;
	}
}

static int id23(tipo_dato *matrix, int *id18,
		int *id21, int id25, int id19) {
	int id46 = 0;
	int id17 = 0;
	tipo_dato numero = 0;
	char *id27 = NULL;
	char *id1 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id46 < id25
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id17 = 0;
		id1 = linea;
		id7(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id27 = linea;; id27 =
				id1) {
			numero = strtol(id27, &id1, 10);
			if (id1 == id27) {
				break;
			}
			*(matrix + id46 * id19 + id17) =
					numero;
			id17++;
		}
		if (id21) {
			id21[id46] = id17;
		}
		id46++;
		caca_log_debug("las filas son %d, con clos %d", id46,
				id17);
	}

	*id18 = id46;
	free(linea);
	return 0;
}

static inline natural id48(tipo_dato num) {
	natural id29 = 0;
	tipo_dato num_mod = 0;
	num_mod = num;
	while (num_mod) {
		num_mod &= ~(num_mod & (-num_mod));
		id29++;
	}
	return id29;
}

static inline char id5(char letra) {
	return letra - 'a';
}

static inline natural id9(natural *nums, natural id22) {
	natural max = 0;

	for (int i = 0; i < id22; i++) {
		natural num_act = nums[i];
		if (num_act > max) {
			max = num_act;
		}
	}

	return max;
}



static inline char *id24(char *cad, natural id31) {
	char c = cad[0];
	char tmp = '\0';
	natural i = 0;
	natural j = 0;

	caca_log_debug("entrada %s id31 %u", cad, id31);
	while (j < id31 && cad[j] != '\0') {
		caca_log_debug("en j %u car %c", j, cad[j]);
		while (j < id31 && !isalpha(cad[j])) {
			caca_log_debug("brincando j %u car %c", j, cad[j]);
			j++;
		}
		caca_log_debug("aora j %u car %c", j, cad[j]);
		if (j == id31) {
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





typedef entero_largo_sin_signo largote;

typedef struct ventana_acumuladora {
	largote *a;
	natural id38;
	natural i;
	natural tam_ventana;
	largote disponible;
	largote disponible_original;
	largote acumulado;
	largote objetivo;
	largote *anadidos;
	largote min;
} ventana_acumuladora;



static inline largote avanza(ventana_acumuladora *v) {
	largote r = id26;
	largote sumado = 0;
	largote id32 = 0;
	natural i_orig = v->i;

	assert(v->i < v->id38);

	sumado = v->acumulado + v->a[v->i];
	assert_timeout(v->disponible_original || !v->acumulado);

	id32 = v->objetivo - caca_comun_min(sumado, v->objetivo);
	caca_log_debug(
			"en i %u el acum %llu, sumado %llu, por anadir %llu, dispon %llu",
			v->i, v->acumulado, sumado, id32, v->disponible);

	if (id32 <= v->disponible) {
		natural id51 = caca_comun_min(v->i + v->tam_ventana,
				v->id38 - 1);
		assert_timeout(v->disponible_original || !id32);
		v->disponible -= id32;

		v->anadidos[id51] = id32;

		if (v->i >= v->tam_ventana) {
			v->acumulado -= v->anadidos[v->i - v->tam_ventana];
		}
		v->acumulado += v->anadidos[id51];
		v->i++;

		r = id32;
	}
	assert_timeout(v->disponible_original || (!v->disponible));

	
	assert_timeout(v->objetivo >= v->min);
	assert_timeout(v->a[i_orig] >= v->min);
	assert_timeout(
			v->disponible_original || ((v->objetivo <= v->a[i_orig] && !r) || (v->objetivo > v->a[i_orig] && r == id26) ));
	return r;
}

static inline largote id30(largote *a, natural id38, largote k,
		natural r, largote objetivo, largote min) {
	largote res = 0;
	ventana_acumuladora *v = NULL;
	natural i = 0;
	bool id20 = falso;

	v = calloc(1, sizeof(ventana_acumuladora));
	assert(v);
	v->anadidos = calloc(id38, sizeof(largote));
	assert(v->anadidos);

	v->a = a;
	v->id38 = id38;
	v->disponible = k;
	v->disponible_original = k;
	v->objetivo = objetivo;
	v->tam_ventana = r;
	v->min = min;

	for (i = 0; i < id38; i++) {
		largote ra = avanza(v);
		assert_timeout(
				k || ((a[i]>=objetivo && !ra)|| (a[i]<objetivo && ra==id26)));
		if (a[i] == min) {
			id20 = verdadero;
		}
		caca_log_debug("en i %u el res de avanzar %llu", i, ra);
		if (ra == id26) {
			res = id26;
			break;
		}
		res = v->disponible;
		assert_timeout(k || !v->disponible);
	}

	free(v->anadidos);
	free(v);

	if (!k && objetivo == min) {
		assert_timeout(!res);
	}
	if (!k && objetivo > min) {
		assert_timeout(min < 5E5 * 1E9);










	}



	return res;
}

typedef int (*busqueda_binaria_comparar)(void *bb_ctx, largote objetivo);

static inline largote id52(void *id28,
		busqueda_binaria_comparar cmp_fn, largote min, largote max, largote k) {
	entero_largo i = min;
	entero_largo j = max;
	largote r = id26;

	while (i <= j) {
		entero_largo mid = i + ((j - i) >> 1);
		int rc = cmp_fn(id28, mid);
		caca_log_debug("en i %lld mid %lld j %lld el res %d", i, mid, j, rc);




		if (rc < 0) {
			j = mid - 1;
		} else {
			if (rc > 0) {
				i = mid + 1;
				r = mid;
			} else {
				r = mid;
				break;
			}
		}
	}

	return r;
}

typedef struct datos_busqueda_binaria {
	largote *a;
	natural id38;
	largote k;
	natural r;
	largote min;
} datos_busqueda_binaria;

int id47(void *dp, largote objetivo) {
	int r = 0;
	largote id11 = 0;
	datos_busqueda_binaria *d = dp;
	bool id20 = falso;

	for (natural i = 0; i < d->id38; i++) {
		if (d->a[i] == d->min) {
			id20 = verdadero;
		}
	}



	id11 = id30(d->a, d->id38, d->k, d->r, objetivo, d->min);
	caca_log_debug("las disp %llu con obj %llu", id11, objetivo);

	assert_timeout(objetivo >= d->min);



	if (id11) {
		if (id11 == id26) {
			r = -1;
		} else {
			r = 1;
		}
	} else {
		r = 0;
	}

	return r;
}




natural a[id34] = { 0 };
largote id14[id34] = { 0 };

static inline largote id10(natural *a, natural i, natural j) {
	largote r = 0;
	caca_log_debug("fuck %u %u", i, j);
	for (natural k = i; k <= j; k++) {
		r += a[k];
	}
	caca_log_debug("r %llu", r);
	return r;
}

static inline largote* id43(natural *a, natural id38, largote *id14,
		natural id4, natural r, largote *res) {
	assert_timeout(id4 >= id38);
	largote acum = 0;
	largote min = id12;


	largote max = 0;
	bool id13 = falso;

	for (natural i = 0; i < r; i++) {
		acum += a[i];
	}

	for (natural i = 0; i < id38; i++) {
		if (i > r) {
			acum -= a[i - r - 1];
		}


		if (i + r < id38) {
			acum += a[i + r];
		}
		id14[i] = acum;

		

		if (acum < min || !id13) {
			min = acum;
			id13 = verdadero;
		}
		if (acum > max) {
			max = acum;
		}
	}
	assert_timeout(min!=id12);
	bool id20 = falso;
	for (natural i = 0; i < id38; i++) {
		if (id14[i] == min) {
			id20 = verdadero;
		}
	}


	res[0] = min;
	res[1] = max;
	return res;
}

static inline void id33() {
	natural n = 0;
	natural r = 0;
	largote k = 0;
	datos_busqueda_binaria *d = caca_comun_calloc_local(datos_busqueda_binaria);
	largote extremos[2] = { 0 };

	scanf("%u %u %llu\n", &n, &r, &k);

	for (natural i = 0; i < n; i++) {
		scanf("%u", a + i);
	}

	caca_log_debug("ptuos %s",
			id37(a, n, CACA_COMUN_BUF_STATICO));

	id43(a, n, id14, id34, r, extremos);
	caca_log_debug("id14 %s el min %llu",
			id41(id14, n, CACA_COMUN_BUF_STATICO),
			extremos[0]);

	bool id20 = falso;
	for (natural i = 0; i < n; i++) {
		if (id14[i] == extremos[0]) {
			id20 = verdadero;
		}
	}



	d->a = id14;
	d->id38 = n;
	d->k = k;
	d->r = r;
	d->min = extremos[0];

	caca_log_debug("a %s, k %llu, r %u",
			id37(a, n, CACA_COMUN_BUF_STATICO),
			k, r);

	largote re = id52(d, id47, extremos[0],
			extremos[1] + k, k);
	caca_log_debug("caca %llu", re);




	printf("%llu\n", re);
}

int main(void) {
	caca_log_debug("pero q mierda");
	id33();
	return EXIT_SUCCESS;
}
