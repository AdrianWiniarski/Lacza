#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

struct  
{
		int begin;
		int end;
		int result;
} zapis;


int pierwsza(int n);

int main(int argc,char ** args)
{
	int file = open("file.txt", O_RDWR | O_APPEND) ;

	int begin = atoi(args[1]), end = atoi(args[2]);
	int i, counter=0;
	
	for(i=begin;i<end;i++)
	{
		if(pierwsza(i)==1)
			counter++;	
	}
    zapis.begin = begin;
    zapis.end   = end;
    zapis.result = counter;

	char tmp_status[16];
	sprintf(tmp_status, "%d\n", counter);
	write( file, &zapis, sizeof(zapis) );
    // printf("%d %d %d\n",begin,end,counter);
	close(file);
	// exit(counter);
}

// Funkcja zwraca 1 gdy n jest liczbą pierwsza 0 gdy nie
int pierwsza(int n)
{
	int i,j=0;
	for(i=2;i*i<=n;i++)
	{
		if(n%i == 0) return(0) ;
	}
	return(1);
}
