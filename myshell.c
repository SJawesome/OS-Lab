#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAXCOM 1000 // max number of letters
#define MAXLIST 100 // max number of commands

#define clear() printf("\033[H\033[J")
// #define gotoxy(x, y) printf("\033[%d;%dH", y, x)

// take input
int takeInput(char* str)
{
    char* buf;

    buf = readline("\n>>> ");
    if (strlen(buf) != 0)
    {
        if(buf=="quit")
        {
          exitShell();
        }
        else if (buf=="cd")
        {
          changeDir(buf);
        }
        else if(buf=="clear")
        {
          System(clear);
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int exitShell()
{
  exit(0);
}

//cd
void changeDir(char* str)
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cwd = str;
    printf("\nDir: %s", cwd);
}

void showReadMe()
{
  printf("Show the ReadME file.");
}

int main(int argc, char *argv[])
{
    while(1)
    {
      takeInput(argv[1]);
    }
}
