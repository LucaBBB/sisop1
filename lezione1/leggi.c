#include "xerrori.h"

int sumFromFile(FILE *f) {
    fseek(f, 0, SEEK_END);
    long int size = ftell(f);
    int da_leggere = size/sizeof(int);

    fseek(f, 0, SEEK_SET);

    int letti[da_leggere];

    xfread(letti, sizeof(int), da_leggere, f, __FILE__, __LINE__);

    int sum = 0;
    for(int i=0; i<da_leggere; i++){
        sum += letti[i];
    }

    return sum;
}

int main(int argc, char *argv[])
{
	if(argc!=2) {
		fprintf(stderr, "Uso:\n\t%s nomeFileDaLeggere\n\n",argv[0]);
		exit(1);
	}
	
	FILE *f = xfopen(argv[1],"r",__FILE__,__LINE__);

	fprintf(stdout, "somma = %d\n", sumFromFile(f));

	fclose(f);

}

