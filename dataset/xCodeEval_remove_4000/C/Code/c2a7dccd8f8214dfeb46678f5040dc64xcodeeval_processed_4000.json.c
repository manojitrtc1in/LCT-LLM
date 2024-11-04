























































typedef char byteme;
typedef unsigned int natural;
typedef byteme tipo_dato;
typedef long long entero_largo;
typedef unsigned long long entero_largo_sin_signo;
typedef long long bitch_vector;

typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;


















		do \
		{ \
			size_t id53 = 0; \
			void *array[id35]; \
 			id53 = backtrace(array, id35); \
			id41(formato,__FILE__, __func__, __LINE__,id53,
		} \
		while(0);









void id41(const char *format, ...);

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

	char id46[50];

	ltime = time(NULL);


	localtime_r(&ltime, &result);
	asctime_r(&result, stime);


	*(stime + strlen(stime) - 1) = ' ';


	id39(&spec);
	ms = round(spec.tv_nsec / 1.0e3);

	sprintf(id46, "%ld", ms);
	strcat(stime, id46);
}

void id41(const char *format, ...) {

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



CACA_COMUN_FUNC_STATICA char *id15(tipo_dato *arreglo, natural id47,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id9 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id47; i++) {
		id9 += sprintf(ap_buffer + id9,
				"%1d", *(arreglo + i));
		if (i < id47 - 1) {
			*(ap_buffer + id9++) = ',';
		}
	}
	*(ap_buffer + id9) = '\0';
	return ap_buffer;
}

CACA_COMUN_FUNC_STATICA char *id37(natural *arreglo,
		natural id47, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id9 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id47; i++) {
		id9 += sprintf(ap_buffer + id9, "%2u",
				*(arreglo + i));
		if (i < id47 - 1) {
			*(ap_buffer + id9++) = ',';
		}
	}
	*(ap_buffer + id9) = '\0';
	return ap_buffer;
}
char *id12(tipo_dato *matrix, natural id3,
		natural id0, char *buffer) {
	int i, j;
	natural id45 = 0;
	for (int i = 0; i < id3; i++) {
		id15(matrix + i * id0, id0,
				buffer + id45);
		id45 += strlen(buffer + id45);
		buffer[id45++] = '\n';
		
	}
	return buffer;
}

CACA_COMUN_FUNC_STATICA char *id43(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id47,
		char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id9 = 0;

	return NULL;


	memset(buffer, 0, 100);
	ap_buffer = buffer;

	for (i = 0; i < id47; i++) {
		id9 += sprintf(ap_buffer + id9,
				"%llu", *(arreglo + i));
		if (i < id47 - 1) {
			*(ap_buffer + id9++) = ',';
		}
	}
	*(ap_buffer + id9) = '\0';
	return ap_buffer;
}

CACA_COMUN_FUNC_STATICA char *id15(tipo_dato *arreglo,
		natural id47, char *buffer) {
	return NULL;
}
CACA_COMUN_FUNC_STATICA char *id37(
		natural *arreglo, natural id47, char *buffer) {
	return NULL;
}
char *id12(tipo_dato *matrix, natural id3,
		natural id0, char *buffer) {
	return NULL;
}

CACA_COMUN_FUNC_STATICA char *id43(
		entero_largo_sin_signo *arreglo, entero_largo_sin_signo id47,
		char *buffer) {
	return NULL;
}





CACA_COMUN_FUNC_STATICA void id10(char s[], char chr,
		char id52) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == chr) {
			s[i] = id52;
		}
		i++;
	}
}

CACA_COMUN_FUNC_STATICA int id24(tipo_dato *matrix,
		int *id19, int *id21, int id26,
		int id20) {
	int id49 = 0;
	int id18 = 0;
	tipo_dato numero = 0;
	char *id31 = NULL;
	char *id1 = NULL;
	char *linea = NULL;

	linea = calloc(CACA_COMUN_TAM_MAX_LINEA, sizeof(char));

	while (id49 < id26
			&& fgets(linea, CACA_COMUN_TAM_MAX_LINEA, stdin)) {
		id18 = 0;
		id1 = linea;
		id10(linea, '\n', '\0');
		if (!strlen(linea)) {
			caca_log_debug("weird, linea vacia");
			continue;
		}
		for (id31 = linea;; id31 =
				id1) {
			numero = strtol(id31, &id1, 10);
			if (id1 == id31) {
				break;
			}
			*(matrix + id49 * id20 + id18) =
					numero;
			id18++;
		}
		if (id21) {
			id21[id49] = id18;
		}
		id49++;
		caca_log_debug("las filas son %d, con clos %d", id49,
				id18);
	}

	*id19 = id49;
	free(linea);
	return 0;
}

CACA_COMUN_FUNC_STATICA natural id50(tipo_dato num) {
	natural id32 = 0;
	tipo_dato num_mod = 0;
	num_mod = num;
	while (num_mod) {
		num_mod &= ~(num_mod & (-num_mod));
		id32++;
	}
	return id32;
}

CACA_COMUN_FUNC_STATICA char id6(char letra) {
	return letra - 'a';
}

CACA_COMUN_FUNC_STATICA natural id13(natural *nums,
		natural id23) {
	natural max = 0;

	for (int i = 0; i < id23; i++) {
		natural num_act = nums[i];
		if (num_act > max) {
			max = num_act;
		}
	}

	return max;
}



CACA_COMUN_FUNC_STATICA char *id25(char *cad, natural id33) {
	char c = cad[0];
	char tmp = '\0';
	natural i = 0;
	natural j = 0;

	caca_log_debug("entrada %s id33 %u", cad, id33);
	while (j < id33 && cad[j] != '\0') {
		caca_log_debug("en j %u car %c", j, cad[j]);
		while (j < id33 && !isalpha(cad[j])) {
			caca_log_debug("brincando j %u car %c", j, cad[j]);
			j++;
		}
		caca_log_debug("aora j %u car %c", j, cad[j]);
		if (j == id33) {
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










entero_largo id48(entero_largo l, byteme d) {
	return l * 10 + d;
}

CACA_COMUN_FUNC_STATICA entero_largo id30(
		byteme *id8, natural id27, entero_largo divis,
		byteme *id22, natural id7) {
	entero_largo resto = 0;
	int i = id27 - 1;

	caca_log_debug("dividen %s divis %llu",
			caca_comun_arreglo_a_cadena_buf_local(id8,id27),
			divis);

	assert_timeout(!id22 || id7 >= id27);

	if (id22) {
		CACA_COMUN_LIMPIA_MEM(id22, id7);
	}

	while (i >= 0) {
		entero_largo c = 0;
		while (resto < divis && i >= 0) {
			resto = id48(resto, id8[i]);
			i--;
		}
		if (resto >= divis) {
			c = resto / divis;
			resto = resto % divis;
			if (id22) {
				id22[i + 1] = c;
			}
		}
	}

	if (id22) {
		caca_log_debug("coci %s resto %llu",
				caca_comun_arreglo_a_cadena_buf_local(id8,id27),
				resto);
	} else {
		caca_log_debug("resto nomas %llu", resto);
	}

	return resto;
}

CACA_COMUN_FUNC_STATICA entero_largo id40(entero_largo a,
		entero_largo b) {
	entero_largo r = 0;
	if (!a) {
		r = 0;
	} else {
		if (!b) {
			r = a;
		} else {
			r = id40(b, a % b);
		}
	}
	return r;
}

CACA_COMUN_FUNC_STATICA entero_largo id5(byteme *a,
		natural id38, entero_largo b) {
	return id40(b,
			id30(a, id38, b, NULL, 0));
}

CACA_COMUN_FUNC_STATICA void id42(byteme *a, natural id38,
		entero_largo b, byteme *r, natural id51) {
	entero_largo id44 = 0;
	natural i = 0;
	assert_timeout(id51 >= id38);
	caca_log_debug("dividienti %s entre %llu",
			caca_comun_arreglo_a_cadena_buf_local(a, id38), b);

	for (i = 0; i < id38; i++) {
		entero_largo r_tmp = a[i] * b + id44;
		caca_log_debug("a[%u] es %u mult %llu id44 %llu res %llu", i, a[i], b,
				id44, r_tmp);
		r[i] = r_tmp % 10;
		id44 = r_tmp / 10;
	}
	if (id51 > id38) {
		caca_log_debug("procesnado id44 %llu", id44);
		while (id44 && i < id51) {
			entero_largo r_tmp = id44;
			r[i] = r_tmp % 10;
			id44 = r_tmp / 10;
		}
	}
	caca_log_debug("coc %s rest %llu",
			caca_comun_arreglo_a_cadena_buf_local(r,id51), id44);
	assert_timeout(!id44);
}
CACA_COMUN_FUNC_STATICA natural id29(byteme *a,
		natural id38) {
	int i = id38 - 1;
	while (i >= 0 && !a[i]) {
		i--;
	}
	return i + 1;
}

CACA_COMUN_FUNC_STATICA char *id17(byteme *a, natural id38,
		char *buffer, natural id14) {
	int i = 0;
	natural j = 0;
	assert_timeout_dummy(id38<=id14);
	CACA_COMUN_LIMPIA_MEM(buffer, id14);
	i = id38 - 1;
	while (i >= 0 && !a[i]) {
		i++;
	}
	for (j = 0; i >= 0; i--, j++) {
		buffer[j] = a[i] + '0';
	}
	buffer[j] = '\0';
	return buffer;
}



CACA_COMUN_FUNC_STATICA byteme id4(byteme *a, natural id38,
		entero_largo b) {
	entero_largo d = 0;
	entero_largo r = 0;
	byteme res = id28;
	assert_timeout(b);
	d = id5(a, id38, b);
	r = b / d;
	assert_timeout(r);
	if (r < 10) {
		res = r;
	}
	return res;
}


byteme a[id34] = { 0 };
byteme res_tmp[id34 + 1] = { 0 };
byteme res[id34 + 1] = { 0 };
char buffer[id34] = { '\0' };

CACA_COMUN_FUNC_STATICA void id11() {
	natural p = 0;
	natural x = 0;
	entero_largo b = 0;
	byteme r = 0;
	bool exito = falso;

	scanf("%u %u\n", &p, &x);

	memset(a, 9, p);
	b = 10 * x - 1;
	r = id4(a, p, b);
	caca_log_debug("dig es %hu", r);

	if (r != id28) {
		entero_largo y = r;
		entero_largo resto = 0;
		id42(a, p, y, res_tmp, p + 1);
		resto = id30(res_tmp, p + 1, b, res, p + 1);
		assert_timeout(!resto);

		if (id29(res, p) < p) {
			memcpy(res_tmp, res, p);
			id42(res_tmp, p, x, res, p);
		}
		if (id29(res, p) == p) {
			exito = verdadero;
		}
	}

	if (exito) {
		caca_log_debug("el num %s",
				caca_comun_arreglo_a_cadena_buf_local(res,p));
		printf("%s\n", id17(res, p, buffer, id34));
	} else {
		caca_log_debug("no se pudo");
		printf("Impossible\n");
	}
}

int main() {
	id11();
	return EXIT_SUCCESS;
}
