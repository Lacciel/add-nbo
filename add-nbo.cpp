#include<stdio.h>
#include<netinet/in.h>
#include<stdint.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void usage(){
	printf("syntax : add-nbo <file1> <file2>\n");
	printf("sample : add-nbo a.bin b.bin\n");
}

int main(int argc, char** argv){
	if(argc != 3){
		usage();
		exit(EXIT_FAILURE);
	}
	FILE* fp[2];
	uint32_t bin[2];
	for(int i=0; i<2; i++){
		fp[i] = fopen(argv[i+1], "r");
		if(fp[i] == NULL){
			printf("%d Argument  %s\n",i+1,strerror(errno));
			exit(EXIT_FAILURE);
		}
		fread(&bin[i],1,sizeof(uint32_t),fp[i]);
		if(sizeof(bin[i])<4){
			printf("%d File Size is too small", i+1);
			exit(EXIT_FAILURE);
		}
		bin[i] = ntohl(bin[i]);
	}
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", bin[0],bin[0],bin[1],bin[1],bin[0]+bin[1],bin[0]+bin[1]);
	fclose(fp[0]);
	fclose(fp[1]);
}
