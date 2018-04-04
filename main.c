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
}zapis;

int main(int argc,char ** args)
{	

	int file = open("file.txt", O_RDWR | O_CREAT | O_TRUNC,0666) ;
	if(file<0){
	perror("open error!");
	}

	int begin = atoi(args[1]),
		end = atoi(args[2]),
		N = atoi(args[3]);

	int grid=(end-begin)/N, pid,status;

	char int_to_str[16];
	char int_to_str_with_grid[16];

	// stuct zapis a;

  	int i=0;
	for(i; i<N ; i++)
	{
		sprintf(int_to_str, "%d", begin);
		sprintf(int_to_str_with_grid, "%d", begin + grid);

		if( (pid=fork())==0 )
		{
			execl("./licz","licz",int_to_str, int_to_str_with_grid, NULL);
			perror("Zla funckja exec");
		}
		begin+=grid;
	}


	int count = 0,rd;
	char line[16];

 	for(i=0; i<N ; i++)
 	{
	    pid = wait(&status);
	     // printf("Proces %d zakończony status: %d\n", pid, WEXITSTATUS(status));
	    // count += WEXITSTATUS(status);

		// sprintf(tmp_status, "%d\n", WEXITSTATUS(status));
		// write( file, tmp_status, strlen( tmp_status ) );
	}
		

	for(i=0; i<N ; i++)
 	{
 		rd = read(file, &zapis, sizeof(zapis) );
 	    // printf("rd: %d %d %d %d\n",rd ,zapis.begin,zapis.end,zapis.result);
 		count = count + zapis.result;
	}

	printf("%d\n",count );
	// printf("Liczb pierwszych na przedziale: %s - %s| To: %d\n",args[1], args[2], count );	

	close(file);
	return 0;
}
