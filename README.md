## Kartkówka 8:00 - Łącza
# 1)Napisz szkic programu w którym,
a) Proces macierzysty tworzy łącze PIPE.
b) Tworzy proces potomny FORK
c) Proces macierzysty wpisuje napis "cześć"
d) Proces potomny odczytuje napis z  łącza i wprowadza na konsolę

#include <unistd.h> 
#include <stdlib.h> 
 main() { 
  int fd[2], child; 
  char buf[] = "cześć"
  char buf2[64]; 
  /* Utworzenie lacza */ 
  pipe(fd) 
    if ((child = fork()) == 0) { 
       / *Proces  potomny – przesy
ł
a wiadomosc do macierzystego */ 
       close(fd[0]); 
       write(fd[1], buf, sizeof(buf); 
       close(fd[1]); 
       exit(0); 
  } 
  /*  Proces macierzysty – odczytuje wiadomosc od potomka */ 
  close(fd[1]); 
  read(fd[0], buf2, sizeof(buf)); 
  printf("%s\n", buf2); 
  close(fd[0]); 
} 

