#include<stdio.h>
#include<netinet/in.h>
#include<stdint.h>
int main(int argc, char** argv){
	FILE* fp1 = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "r");
	if(fp1 == NULL || fp2 == NULL){
		printf("File open error");
		return 1;
	}
	uint32_t a1,a2;
	fread(&a1, sizeof(uint32_t), 1, fp1);
	a1 = ntohl(a1);
	fread(&a2, sizeof(uint32_t), 1, fp2);
	a2 = ntohl(a2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a1,a1,a2,a2,a1+a2,a1+a2);
	fclose(fp1);
	fclose(fp2);
}
