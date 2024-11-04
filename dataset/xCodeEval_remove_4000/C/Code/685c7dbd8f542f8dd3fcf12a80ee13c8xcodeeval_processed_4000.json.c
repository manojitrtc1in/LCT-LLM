







int i = 0;




























typedef enum BOOLEANOS {
	falso = 0, verdadero
} bool;









typedef struct taladores_ogts_pseudopila_lineas {
	tipo_dato indice_caminado_linea;
	tipo_dato total_intersexiones;
	tipo_dato total_intersexiones_abcisas;
	tipo_dato total_lineas;
	double ordenadas_de_intersexiones[id16 ];
	double abcisas_de_intersexiones[id16 ];
	tipo_dato indices_lineas[id16 ];
} taladores_ogts_pseudopila_lineas;

tipo_dato id1;
tipo_dato *id3;
tipo_dato *id44;
tipo_dato *id13;

taladores_ogts_pseudopila_lineas *id8;

double id43(
		tipo_dato id35, tipo_dato id51);

void id15(tipo_dato id17);

tipo_dato id19(tipo_dato ordenada);

tipo_dato id48(tipo_dato id17,
		tipo_dato ordenada);

void id46();

void id12();

void id11(
		taladores_ogts_pseudopila_lineas *id8);

static void id9(tipo_dato *matrix,
		int id27, int id40);












int id45(tipo_dato *matrix, int *id27, int *id40,
		int id2, int id28) {
	int id36 = 0;
	int id18 = 0;
	tipo_dato numero = 0;
	char *id25 = NULL;
	char *id0 = NULL;
	char *linea = NULL;

	linea = calloc(TAM_MAX_LINEA, sizeof(char));

	while (id36 < id2 && fgets(linea, TAM_MAX_LINEA, stdin)) {
		id18 = 0;
		id0 = linea;
		for (id25 = linea;; id25 =
				id0) {
			numero = strtoll(id25, &id0,
					10);
			assert_timeout(
					numero!=LLONG_MIN || numero!=LLONG_MAX || numero==ULLONG_MAX);
			if (id0 == id25) {
				break;
			}
			*(matrix + id36 * id28 + id18) =
					numero;
			caca_log_debug1("en col %d, fil %d, el valor %lu\n",
					id18, id36, numero);
			id18++;
			caca_log_debug1("las columnas son %d\n", id18);
		}
		if (id40) {
			id40[id36] = id18;
		}
		id36++;
		caca_log_debug1("las filas son %d, con clos %d\n", id36,
				id18);
	}

	*id27 = id36;
	free(linea);
	return 0;
}


double id43(
		tipo_dato id35, tipo_dato id51) {
	double ordenada = 0;
	double b2 = 0;
	double b1 = 0;
	double x2 = 0;
	double x1 = 0;

	b2 = *(id3 + id51);
	b1 = *(id3 + id35);

	x2 = *(id44 + id51);
	x1 = *(id44 + id35);

	ordenada = (b2 - b1) / (x1 - x2);

	return ordenada;
}


double id31(
		tipo_dato id35, tipo_dato id51) {
	double abcisa = 0;
	double b2 = 0;
	double b1 = 0;
	double m2 = 0;
	double m1 = 0;

	b2 = *(id3 + id51);
	b1 = *(id3 + id35);

	m2 = *(id44 + id51);
	m1 = *(id44 + id35);

	abcisa = (b1 * m2 - b2 * m1) / (m2 - m1);

	return abcisa;
}

void id15(tipo_dato id17) {
	bool id14 = falso;
	double id49 = 0;
	double id7 = 0;
	double id29 = 0;
	double id20 = 0;

	tipo_dato id21 = 0;
	tipo_dato id34 = 0;
	tipo_dato id32 = 0;

	switch (id8->total_lineas) {
	case 0:
		caca_log_debug("inicialmente hay 0 linea, se añadira %d", id17);
		*(id8->indices_lineas + id8->total_lineas) = id17;
		id8->total_lineas++;
		break;
	case 1:
		caca_log_debug("inicialmente hay 1 linea, se añadira %d", id17);
		id49 = id43(
				id17,
				*(id8->indices_lineas + id8->total_lineas - 1));
		id7 = id31(
				id17,
				*(id8->indices_lineas + id8->total_lineas - 1));
		*(id8->indices_lineas + id8->total_lineas) = id17;
		*(id8->ordenadas_de_intersexiones
				+ id8->total_intersexiones) = id49;
		*(id8->abcisas_de_intersexiones
				+ id8->total_intersexiones_abcisas) = id7;

		caca_log_debug("se añade 1era intersex %f", id49);

		id8->total_lineas++;
		id8->total_intersexiones++;
		id8->total_intersexiones_abcisas++;
		break;
	default:
		caca_log_debug("inicialmente hay 2+ linea");

		while (id8->total_lineas > 1) {
			id29 =
					*(id8->ordenadas_de_intersexiones
							+ id8->total_intersexiones - 1);

			id20 = *(id8->abcisas_de_intersexiones
					+ id8->total_intersexiones_abcisas - 1);

			id32 = *(id8->indices_lineas
					+ id8->total_lineas - 1);

			id49 =
					id43(id17,
							*(id8->indices_lineas
									+ id8->total_lineas - 2));
			id7 =
					id31(id17,
							*(id8->indices_lineas
									+ id8->total_lineas - 2));

			caca_log_debug("la nueva intersexion es %f, comparandola con %f",
					id49, id29);
			
			if (id49 < id29) {
				caca_log_debug("se va a kitar linea %d en pos %d",
						*(id8->indices_lineas + id8->total_lineas - 1),
						id8->total_lineas - 1);
				caca_log_debug("se va a kitar inteseccion %f en pos %d",
						*(id8->ordenadas_de_intersexiones + id8->total_intersexiones - 1),
						id8->total_intersexiones - 1);

				*(id8->indices_lineas + id8->total_lineas - 1) =
						id37;
				*(id8->ordenadas_de_intersexiones
						+ id8->total_intersexiones - 1) =
						id37;
				*(id8->abcisas_de_intersexiones
						+ id8->total_intersexiones_abcisas - 1) =
						id37;

				id8->total_lineas--;
				id8->total_intersexiones--;
				id8->total_intersexiones_abcisas--;
			} else {
				id49 =
						id43(
								id17,
								*(id8->indices_lineas
										+ id8->total_lineas - 1));
				id7 = id31(
						id17,
						*(id8->indices_lineas + id8->total_lineas
								- 1));
				break;
			}

		}

		*(id8->ordenadas_de_intersexiones
				+ id8->total_intersexiones) = id49;
		*(id8->abcisas_de_intersexiones
				+ id8->total_intersexiones_abcisas) = id7;
		*(id8->indices_lineas + id8->total_lineas) = id17;

		caca_log_debug("nueva linea en %d es %d", id8->total_lineas,
				id17);
		caca_log_debug("nueva intersex en %d es %f",
				id8->total_intersexiones, id49);

		id8->total_lineas++;
		id8->total_intersexiones++;
		id8->total_intersexiones_abcisas++;

		if (id8->indice_caminado_linea >= id8->total_lineas) {
			caca_log_debug("se corrige el indice caminado de %d a %d",
					id8->indice_caminado_lineas,
					id8->total_lineas);
			id8->indice_caminado_linea = id8->total_lineas - 1;
		}

		break;
	};
}

tipo_dato id19(tipo_dato ordenada) {
	bool id41 = falso;
	tipo_dato minimo = 0;
	tipo_dato id38 = 0;
	tipo_dato id24 = 0;
	tipo_dato id47 = 0;
	tipo_dato id26 = 0;
	tipo_dato id4 = 0;
	tipo_dato id22 = 0;

	id26 = *(id13 + ordenada);

	id38 = id37;
	for (id4 = id8->indice_caminado_linea;
			id4 < id8->total_lineas; id4++) {

		id47 = *(id8->indices_lineas + id4);

		id24 = (tipo_dato) id26
				* *(id44 + id47)
				+ *(id3 + id47);

		if (id24 < id38) {
			minimo = id47;
			id38 = id24;
			id22 = id4;
		}

	}

	caca_log_debug("el minimo calculado es %d en ilnea %d", minimo,
			id22);

	if (id22 == id8->total_lineas) {
		id8->indice_caminado_linea = id22 - 1;
	} else {
		id8->indice_caminado_linea = id22;
	}

	return minimo;
}

tipo_dato id48(tipo_dato id17,
		tipo_dato ordenada) {
	tipo_dato minimo = 0;

	id15(id17);

	minimo = id19(ordenada);

	return minimo;
}

void id46() {
	int i = 0;
	tipo_dato id30 = 0;

	caca_log_debug("mierda");
	*(id3 + 1) = 0;
	*(id3 + 2) = *(id44 + 1) * *(id13 + 2);
	caca_log_debug("añadiendo linea 1");
	id15(1);

	for (i = 3; i <= id1; i++) {
		caca_log_debug("añadiendo linea %d", i - 1);
		id30 = id48(i - 1, i);

		caca_log_debug1("el dep minimo %d\n", id30);
		*(id3 + i) = *(id3 + id30)
				+ *(id13 + i) * *(id44 + id30);
		caca_log_debug1("el minimo costo para cortar %d es %lu\n", i,
				*(id3 + i));
	}
}

void id11(
		taladores_ogts_pseudopila_lineas *id8) {
	int i = 0;

	for (i = 0; i < id16 ; i++) {
		*(id8->indices_lineas + i) = id37;
		*(id8->ordenadas_de_intersexiones + i) =
				id37;
	}
}

void id5() {
	int i = 0;
	int j = 0;
	tipo_dato id33 = 0;
	tipo_dato id6 = 0;
	tipo_dato id30 = 0;

	caca_log_debug("mierda");
	*(id3 + 1) = 0;
	*(id3 + 2) = *(id44 + 1) * *(id13 + 2)
			+ *(id3 + 1);
	caca_log_debug("añadiendo linea 1");

	for (i = 3; i <= id1; i++) {
		caca_log_debug1("encontrando chosto minimo para %d\n", i);

		id6 = id37;
		for (j = 1; j < i; j++) {
			id33 = *(id3 + j)
					+ *(id13 + i) * *(id44 + j);
			if (id33 < id6) {
				id6 = id33;
				id30 = j;
			}
		}

		caca_log_debug1("el dep minimo %d\n", id30);

		*(id3 + i) = id6;
		caca_log_debug1("el minimo costo para cortar %d es %lu\n", i,
				*(id3 + i));
	}
}

char *id39(tipo_dato *arreglo, int id23, char *buffer) {
	int i;
	char *ap_buffer = NULL;
	int id42 = 0;

	memset(buffer, 0, 1000);
	ap_buffer = buffer;

	for (i = 0; i < id23; i++) {
		id42 += sprintf(ap_buffer + id42, "%ld",
				*(arreglo + i));
		if (i < id23 - 1) {
			*(ap_buffer + id42++) = ',';
		}
	}
	return ap_buffer;
}

void id12() {
	int i = 0;
	int id50 = 0;
	tipo_dato *id10 = NULL;
	char buffer[1000];

	caca_log_debug("me corto los tanates");

	id10 = calloc(
			TALADORES_OGTS_MAX_COLS_INPUT * TALADORES_OGTS_MAX_FILAS_INPUT,
			sizeof(tipo_dato));
	assert_timeout(id10);

	id3 = calloc(id16 + 1, sizeof(tipo_dato));
	id44 = calloc(id16 + 1, sizeof(tipo_dato));
	id13 = calloc(id16 + 1, sizeof(tipo_dato));
	assert_timeout(id3 && id44 && id13);

	id8 = calloc(1, sizeof(taladores_ogts_pseudopila_lineas));
	assert_timeout(id8);

	id45(id10, &i, NULL,
			TALADORES_OGTS_MAX_FILAS_INPUT, TALADORES_OGTS_MAX_COLS_INPUT);
	id50++;


	{
		id1 = *id10;
		caca_log_debug1("los datos %lu\n", id1);

		assert_timeout(id1 <= id16);

		
		

		memcpy(id13 + 1, id10+TALADORES_OGTS_MAX_COLS_INPUT,
				(TALADORES_OGTS_MAX_COLS_INPUT)* sizeof(tipo_dato));
		memcpy(id44 + 1,
				id10 + 2*(TALADORES_OGTS_MAX_COLS_INPUT),
				(TALADORES_OGTS_MAX_COLS_INPUT)* sizeof(tipo_dato));

		for (i = 0; i <= id1; i++) {
			*(id3 + i) = id37;
		}
		*id44 = id37;
		*id13 = id37;

		caca_log_debug1("el num de arboles %lu\n", id1);
		caca_log_debug1("las alturas %s\n",
				id39(id13, id1 + 1, buffer));
		caca_log_debug1("llos chostos %s\n",
				id39(id44, id1 + 1, buffer));

		if (id1 == 1) {
			*(id3 + id1) = 0;
			goto caca;
		}

		if (id1 == 2) {
			*(id3 + id1) = *(id13 + id1)
					* *(id44 + id1 - 1);
			goto caca;
		}

		for (i = 1; i <= id1; i++) {
			if (i > 1) {
				assert_timeout(
						*(id13 + i) > *(id13 + i - 1));
				assert_timeout(*(id44 + i) < *(id44 + i - 1));
			}
			assert_timeout(*(id13+i)<=TALADORES_OGTS_MAX_VALOR);
			assert_timeout(*(id44 +i)<=TALADORES_OGTS_MAX_VALOR);
		}
		assert_timeout(*(id13 + 1) == 1);
		assert_timeout(*(id44 + id1) == 0);

		id11(id8);
		id46();
		
		caca_log_debug("q mierda pasa");

		caca:

		printf("%llu\n", *(id3 + id1));

		i = 0;
		memset(id13, 0, TALADORES_OGTS_MAX_COLS_INPUT+1);
		memset(id44, 0, TALADORES_OGTS_MAX_COLS_INPUT+1);
		memset(id3, 0, TALADORES_OGTS_MAX_COLS_INPUT+1);
		memset(id10, 0,
				(TALADORES_OGTS_MAX_COLS_INPUT+1)*(TALADORES_OGTS_MAX_FILAS_INPUT));
		memset(id8, 0, sizeof(taladores_ogts_pseudopila_lineas));

		id45(id10, &i, NULL,
				TALADORES_OGTS_MAX_FILAS_INPUT, TALADORES_OGTS_MAX_COLS_INPUT);
		id50++;

	}

	free(id13);
	free(id44);
	free(id3);
	free(id10);

}

int main(void) {
	id12();
	return EXIT_SUCCESS;
}
