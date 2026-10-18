#include<stdio.h>
#include<regex.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main (){
	int fd =open("url.html",O_RDWR);
	if(fd==-1){
		perror("open");
		return 1;
	}
	off_t fsize =lseek(fd,0,SEEK_END);
	if(fsize == -1){
		perror("lseek");
		close(fd);
		return 1;
	}
	char* mmap_ptr=NULL;
	mmap_ptr=mmap(NULL,fsize,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);

	char* regstr="<a href=\"[^\"]+\"[^>]*>[^<]+</a>";
	int regnum=2;
	regmatch_t match[regnum];
	regex_t reg;
	regcomp(&reg,regstr,0);
	off_t offset=0;
	char news[1024];
	while((regexec(&reg,mmap_ptr+offset,regnum,match,0))==0){
		bzero(news,sizeof(news));
		snprintf(news,(int)(match[0].rm_eo-match[0].rm_so+1),"%s",mmap_ptr+match[0].rm_so+offset);
		offset+=match[0].rm_eo;
		printf("%s\n",news);
	}
	regfree(&reg);
	munmap(mmap_ptr,fsize);
	close(fd);
	printf("done\n");
	return 0;
}
