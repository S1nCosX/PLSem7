#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check_password(FILE *f, const char *password) {
  int buffer_size= 10;
  char buffer[buffer_size];
  int okay = 0;  

  fgets(buffer, buffer_size, f);\\ FileGetString() думаю название говорящее, но в общем ограничиваем ввод (но наверн советую написать просто форик)

  if (buffer[strlen(buffer) - 1] == '\n')\\ функция выше не различает \n, в отличии от условного get() из #iostream или простого cin, в общем костыль
    buffer[strlen(buffer) - 1] = '\0';
  
  if (strcmp(buffer, password) == 0)
    okay = 1;

  return okay;
}

int main(int argc, char **argv) {
  if (check_password(stdin, "password"))
    puts("Access granted.");
  else
    puts("Wrong password.");
}