#include "xerrori.h"


void somman(char *nome) 
{
	// apre file in scrittura
	// open(pathname, flags, mode);
	
	// O WRONLY: apre un file in scrittura e si posiziona all'inizio del file.
	// O CREAT: se il file non esiste lo crea.
	// O TRUNC: il file esistente viene troncato.	
	int fd = open(nome,O_RDONLY,0666);
	if(fd<0) 
		die("Errore creazione file");
	
	int i, sum = 0;
	while(read(fd, &i, sizeof(int)) == sizeof(int)) { // finche' legge 2 byte prosegue
		sum += i;
	}
	
	assert(sum == i*(i+1)/2);
	fprintf(stdout, "somma = %d\n", sum);
	
	// chiude file 
	int e = close(fd);
	if(e!=0) {
		perror("Errore chiusura file");
		exit(1);
	}
}


int main(int argc, char *argv[])
{
	if(argc!=2) {
		fprintf(stderr, "Uso:\n\t%s nomefile\n\n",argv[0]);
		exit(1);
	}
	somman(argv[1]);
}

