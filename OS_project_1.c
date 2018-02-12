#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


//NOTES FOR TA/PROF


//We need clarification on Environmental Values


//We need clarification on prompting and how to simulate or emulate a file directory system in
//→ our own shell.


//Global definition for fget
#define buffersize 250
char * cmdname, input_redirection, output_redirection, pipe_1, pipe_2, pipe_3, background;

// checks to see if the string is a command
	int BuiltInCommand(char *line)
 {
	if (strcmp(line, "exit") == 0 || strcmp(line, "echo") == 0 || strcmp(line, "etime") == 0 || strcmp(line, "io") == 0)
		return 1;
	else
		return 0;
 }

// checks to see if the character is what we need
	int isChar(char line) {

	 if (line == '|' || line == '<' || line == '>' || line == '&' || line == '$' || line == '~')
		return 1;
	 else
		return 0;
 }

	void my_setup()
 {


 }

        char *my_read(char *x)
 {
            char *line = fgets(x, buffersize, stdin);
	return line;
 }


// gets each argument from the line
 char **parse_arguements(char *line)
 {
             	int i;
		int j = 0;
		int k = 0;
		char **args;
		args = (char **) malloc (sizeof(char **));		

                char *temp;
                temp = (char *) malloc (sizeof(char *));

		for (i = 0; i < (strlen(line) + 1); ++i) {

			if (line[i] != ' ' && line[i] != '\0'){ 
				temp[k] = line[i];
				k++;
 }

			else {
				args[j] = temp;
				j++;
				temp = (char *) malloc (sizeof(char *));
				k = 0;
		 }
	 }


                return args;
 }

// adds and removes whitespace accordingly
	char *parse_whitespace(char *line)
 {
		
		int i;
		int j = 0;
		int count = 0;
		char *white;
		white = (char *) malloc (sizeof(char *));
		
		for (i = 0; i < strlen(line); ++i) {
			
			if (line[i] != ' ')
 {
				count++;
 }
			if (count == 0 && line[i] == ' ')
 {
				continue;
 }			
			else if (line[i] == ' ' && line[i-1] == ' ')
 {
				continue;
 }	
			
			else {
				white[j] = line[i];			
				
				
				if (isChar(line[i+1]) && line[i] != ' ') {
					j++;
					white[j] = ' ';
					j++;
					continue;
  }
				else if (line[i+1] != ' ' && isChar(line[i])) {
					j++;
					white[j] = ' ';
					j++;
					continue;
  }
					j++;
  }
}
		return white;
 
}



// checks the path of the comman and parses each item in the path
	char **resolve_paths(char **args) {

	char **path_is;
	path_is = (char **) malloc (sizeof(char **));	
	char *temp;
	temp = (char *) malloc (sizeof(char **));
	int i;
	int j = 0;
	int k = 0;

	if (!BuiltInCommand(args[0])) {
		char *path = getenv("PATH");

	for (i = 0; i < strlen(path); ++i)
 {
	if (path[i] != ':') {
		temp[j] = path[i]; 
		j++;
		continue;
 }
	else
 {
		path_is[k] = temp;
		k++;
		temp = (char *) malloc (sizeof(char **));
		j = 0;
		continue;	
 }
}
}
	return path_is;
}

// checks to see if there is a match to the command call within the pathname given
	char *find_match(char **command_line, char **pathname) 
 {
	DIR* dirp;
	struct dirent *dp;
	int i, errno;
	for (i = 0; pathname[i] != NULL; ++i)
 {
	dirp = opendir(pathname[i]);
		while(dirp) {
		errno = 0;
	if ((dp = readdir(dirp)) != NULL) {
		if (strcmp(dp->d_name, command_line[0]) == 0) {
			closedir(dirp);
			printf("A match was found");
			return pathname[i];
 }
}

		else {
			if (errno = 0) {
				closedir(dirp);
				continue;
 }
	closedir(dirp);
	printf("There were no matches in the directory");
	return NULL;
 }
}
}		
}
        char **my_parse(char *line)
 {
                char **args;
                char *temp_line;

                temp_line = parse_whitespace(temp_line);
                args = parse_arguements(temp_line);


 }

//executes external processes
/*void my_execute(char **cmd) {

pid_t pid = fork();

	if (pid == -1) 
 {
		printf("Error");
		exit(1);
 }

	else if (pid == 0)
 {
		execv(cmd[0], cmd);
		fprintf("Problem executing %s\n", cmd[0]);
		exit(1);
 }

	else
 {
		waitpid(pid, &status, 0);
 }
}*/
int main()
{
        //char pointers for command line parsing
//char *line = " echo|find  ";
//char *line2 = parse_whitespace(line);
//char *line3 = "Hello my friend";
//char **line4 = parse_arguements(line3);
char **cmd;

//printf("%s\n", line2);
//printf("%s%s%s\n", line4[0], line4[1], line4[2]);


//while(1)
//{
//Setup (Environmental stuff...)
//my_setup();

        //Prompting
//my_promt();

        //Reading Input
//my_read(line);

        //Parsing Input
//cmd = my_parse(line);

        //Executing Input
//my_execute(cmd);

        //Post task clean up
//my_clean();

//}
return 0;
}	
