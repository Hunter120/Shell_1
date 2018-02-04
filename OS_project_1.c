#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//NOTES FOR TA/PROF


//We need clarification on Environmental Values


//We need clarification on prompting and how to simulate or emulate a file directory system in
//→ our own shell.


//Global definition for fget
#define buffersize 250
char * cmdname, input_redirection, output_redirection, pipe_1, pipe_2, pipe_3, background;


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

	char **resolve_paths(char **args) {

        char **my_parse(char *line)
 {
                char **args;
		char *temp_line;

		temp_line = parse_whitespace(temp_line);
		args = parse_arguements(temp_line);


 }

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


	int is_command(char **args, int i) {

	//if (args[i] == arguement)
	//	return 0;

	//else if (args[i] == external command)
	//	return 1;
	
	//else if (args[i] == "cd")
	//	return 2;
	
	//else
	//	return 3;

}
	char **resolve_paths(char **args) {
	
	int i;
	for (i = 0; args[i] != NULL; i++) {
		args[i] = expand_path(args[i], is_command(args, i));
 }
	return args;
}

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
