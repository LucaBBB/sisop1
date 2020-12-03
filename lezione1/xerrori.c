#include "xerrori.h"

// FUNZIONE CHE APRE IL FILE E VERIFICA CHE NON SIA NULL
FILE *xfopen(const char *pathname, const char *mode, const char *file, const int line) {
	FILE *f = fopen(pathname,mode);
	if(f==NULL) {
		perror("Errore apertura file");
		fprintf(stderr,"(%s:%d)\n",file,line);
		exit(1);
	}
	return f;
}

/*
 * Funzione che legge da file e verifica che abbia realmente scritto
 */
size_t xfwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream, const char *file, const int line) {
	size_t w = fwrite(ptr, size, nmemb, stream);
	if (w!=nmemb) {
		perror("Errore scrittura");
		fprintf(stderr,"(%s:%d)\n",file,line);
		exit(1);
	}
	return w;
}

size_t xfread (void *ptr, size_t size, size_t nmemb, FILE *stream, const char *file, const int line) {
	size_t r = fread(ptr, size, nmemb, stream);
	if (r != nmemb) {
		perror("Errore lettura");
		fprintf(stderr,"(%s:%d)\n",file,line);
		exit(1);
	}
	return r;
}
