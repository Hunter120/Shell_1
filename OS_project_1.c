#include <stdio.h>


//NOTES FOR TA/PROF


//We need clarification on Environmental Values


//We need clarification on prompting and how to simulate or emulate a file directory system in
//→ our own shell.


//Global definition for fget
#define buffersize 250
char * cmdname, input_redirection, output_redirection, pipe_1, pipe_2, pipe_3, background;




int main()
{
        //char pointers for command line parsing
char *line;
char **cmd;


while(1)
{
//Setup (Environmental stuff...)
my_setup();

        //Prompting
my_promt();

        //Reading Input
my_read(line);

        //Parsing Input
cmd = my_parse(line);

        //Executing Input
my_execute(cmd);

        //Post task clean up
my_clean();

}
return 0;
}


void my_setup()
{


}


void my_read(char *x)
{
fgets(x, buffersize, stdin);
}


Char **my_parse(char *line)
{
char **args;
//sscan (line,

}
