#include<copy.h>
int check_pram(int argc ,const char *srcfile ,int pronum){
	if(argc<3){
		perror("argv error");
		exit(0);
	}
	if((access(srcfile,F_OK))==-1){
		perror("srcfile no exist");
		exit(0);
	}
	if(pronum<1||pronum>100){
		perror("pronum error");
		exit(0);
	}
	return 0;
}
