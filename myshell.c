//include all Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"
#include <unistd.h>
#include <errno.h>


#define BUFFER_LEN 256

int main(int argc, char *argv[]){
//Input buffer and commands
char buffer[BUFFER_LEN];
char command[BUFFER_LEN];


char *token;
const char s[2] = "-";
char *arr[2];
(void)argc;
(void)argv;
//current directory of size 1024
char cwd[512];

//uses getcwd to find the current working directory
if (getcwd(cwd, sizeof(cwd)) != NULL){
	
	printf("%s ", cwd);
} 
else {
	// Prints an error if it can not find current directory
	perror("getcwd error!");
	return 1;
}

while (fgets(buffer, BUFFER_LEN, stdin) != NULL){

//Performs string tokenization to get the command and argument
token = strtok (buffer, s);
int count = 0;
while (token != NULL){
	if(count == 0){
		memcpy(command, token, strlen(token));	
	}
	arr[count] = token;
	token = strtok(NULL, s);
	count++;
}
//check if input is quit
if(strcmp(command, "quit\n") == 0){

return 0;
}

//check if input is echo
else if(strcmp(command,"echo\0") == 0){
	printf("%s", arr[1]);
}

//check if input is help
else if(strcmp(command,"help") == 0){
	FILE *fp;
	char c;
	fp = fopen("Readme.txt","rt");
	while ((c=fgetc(fp)) != EOF){
		printf("%c", c);
	}
	fclose(fp);
}

//check if input is environ
else if(strcmp(command,"environ\n") == 0){
	extern char **environ;
	char **var;
	for(var = environ; *var!=NULL; ++var){
		printf("\n%s",*var);
	}
}

//check if input is pause
else if(strcmp(command,"pause\n") == 0){
	char ch = '\0';
	while (ch != '\n'){
		printf("Press Enter to continue");
		scanf("%c", &ch);
	}
}

//check if input is cd
else if(strcmp(command,"cd\0") == 0){

}

//check if input is dir
else if(strcmp(command,"dir\n") == 0){
	DIR *d;
	struct direct *dir;
	d = opendir(".");

	if(d){
		while((dir = readdir(d)) != NULL){
			printf("%s\n",dir);
		}
		closedir(d);
	}
}

//check if input clr (clear)
else if(strcmp(command,"clr\n") == 0){
	for (int c = 0; c < 100; c++){
		printf("\n");
	}
}


}
return 0;
}
