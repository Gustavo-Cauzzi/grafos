#include<stdio.h>

int main (){
	int numFiles = 0;
	scanf("%d", numFiles);
	
	int i;
	for (i = 0; i < numFiles; i++) {
		char conexoes[5005];
		scanf("%c", &conexoes);
		
		char num[5];
		int j;
		for (j = 0; j < 5; j++) {
			if (conexoes[j] != ' ') {
				num[j] = conexoes[j];
			} else {
				break;
			}
		}
		atoi(num);
		
		
	}
	
	return 0;
}
