#include <stdio.h>

void insere (unsigned char *conjunto, int valor) {
	*conjunto = *conjunto | (1 << valor-1);
}

void remover (unsigned char *conjunto, int valor) {
	*conjunto = *conjunto & ~(1 << valor-1);
}

void rota_esq (unsigned int *conjunto) {
	*conjunto = (*conjunto << 1);
}

void rota_dir (unsigned int *conjunto) {
	*conjunto = (*conjunto >> 1);
}

int main(){
	unsigned char v = 7;
	insere(&v, 4);
	printf("%d\n", v);
	rota_dir(&v);
//	remover(&v, 3);
	printf("%d\n", v);
	
	return 0;
}
