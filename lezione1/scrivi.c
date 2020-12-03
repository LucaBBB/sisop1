#include "xerrori.h"


void scrivi1n(int n, char *nome) 
{
	// apre file in scrittura
	FILE *f = xfopen(nome,"wb",__FILE__,__LINE__);
	assert(f!=NULL);
	// scrive valori sul file
	for(int i=1; i<=n; i++) {
		//int e = fwrite(&i, sizeof(int), 1, f); // scrive su f il contenuto di i 
		//size_t xfwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream, const char *file, const int linea)
		int e = xfwrite(&i, sizeof(int), 1, f, __FILE__, __LINE__); 
		if(e!=1) {
			perror("Errore scrittura file");
			exit(1);
		}
	}
	// chiude file 
	int e = fclose(f);
	if(e!=0) {
		perror("Errore chiusura file");
		exit(1);
	}
}


int main(int argc, char *argv[])
{
    if(argc!=3) {
        fprintf(stderr, "Uso:\n\t%s n nomefile\n\n",argv[0]);
        exit(1);
    }
    int n = atoi(argv[1]);
    if(n<=0) {
        fprintf(stderr, "Inserisci un intero positivo\n");
        exit(1);
    }
    scrivi1n(n,argv[2]);
}
    
    
    
