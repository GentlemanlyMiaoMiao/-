#include<stdio.h>
#include<fcntl.h>
void main(){
	int fd = open("JetBrains.txt",O_RDWR);
	if(fd < 0){
	printf("写了一天的BUG累了吧");
	return;
	}
	char buf[10];
	read(fd,buf,10);
	for(int i=0;i<=4;i++){
		int b;
		b =  buf[i];
		buf[i] = buf[9-i];
		buf[9-i] = b; 
	}
	lseek(fd,0,SEEK_SET);
	write(fd,buf,10);
	close(fd);
}
