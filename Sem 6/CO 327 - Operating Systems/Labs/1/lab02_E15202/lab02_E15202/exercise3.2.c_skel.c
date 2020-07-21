#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>

/**
 * Executes the command "cat fixtures | grep <search_term> | cut -b 1-9".
 */

#define INPUTFILE "fixtures"

int main(int argc, char **argv)
{
	int status;
	int i;

	if (argc < 2)
	{
		printf("%s: missing operand\n", argv[0]);
		printf("Usage: %s <search_term in %s>\n", argv[0],INPUTFILE);
		return 0;
	}

	// arguments for commands
	char *cat_args[] = {"cat", INPUTFILE, NULL };
	char *grep_args[] = {"grep","-i",argv[1], NULL};
	char *cut_args[] = {"cut","-b","1-9",NULL};

	// make 2 pipes (cat to grep and grep to cut); each has 2 fds

	int pipes[4];
	// sets up 1st pipe
	// TODO: ** insert your code here **
	
	if(pipe(pipes + 0)) 
	{
		perror("Pipe 1 creation");
		return -1;
	}
		




	// sets up 2nd pipe
	// TODO: ** insert your code here **
	if(pipe(pipes + 2)) 
	{
		perror("Pipe 2 creation");
		return -1;
	}
		

	// we now have 4 fds:
	// pipes[0] = read end of cat->grep pipe (read by grep)
	// pipes[1] = write end of cat->grep pipe (written by cat)
	// pipes[2] = read end of grep->cut pipe (read by cut)
	// pipes[3] = write end of grep->cut pipe (written by grep)

	// fork the first child (to execute cat)

	if (fork() == 0)
	{
		// replace cat's stdout with write part of 1st pipe
		// TODO: ** insert your code here **
		if(dup2(pipes[1],1) == -1){
			perror("dup2()");
		}

		
		// close all pipes (very important!); end we're using was safely copied
		// TODO: ** insert your code here **
		close(pipes[0]);
		close(pipes[2]);
		close(pipes[3]);

		// Execute the cat command
		// TODO: ** insert your code here **
		if(execvp("cat", cat_args) == -1){
			perror("execvp()");
		}

	}
	else
	{
		// fork second child (to execute grep)

		if (fork() == 0)
		{
			// replace grep's stdin with read end of 1st pipe
			// TODO: ** insert your code here **
			if(dup2(pipes[0],0) == -1){
				perror("dup2()");
			}

			// replace grep's stdout with write end of 2nd pipe
			// TODO: ** insert your code here **
			if(dup2(pipes[3],1) == -1){
				perror("dup2()");
			}

			// close all ends of pipes
			// TODO: ** insert your code here **
			close(pipes[1]);
			close(pipes[2]);

			// execute grep command
			// TODO: ** insert your code here **
			if(execvp("grep", grep_args) == -1){
				perror("execvp()");
			}
		}
		else
		{
			// fork third child (to execute cut)

			if (fork() == 0)
			{
				// replace cut's stdin with input read of 2nd pipe
				// TODO: ** insert your code here **
				if(dup2(pipes[2],0) == -1){
					perror("dup2()");
				}

				// close all ends of pipes
				// TODO: ** insert your code here **
				close(pipes[0]);
				close(pipes[1]);
				close(pipes[3]);


				// execute cut command
				// TODO: ** insert your code here **
				if(execvp("cut", cut_args) == -1){
					perror("execvp()");
				}
			}
		}
	}

	// only the parent gets here and waits for 3 children to finish
	// It's a good idea to close all your pipes (the parent needs none!)
	// before waiting for your children! 

	// TODO: ** insert your code here **
	close(pipes[0]);
	close(pipes[1]);
	close(pipes[2]);
	close(pipes[3]);


	// TODO: ** insert your code here **
	while (wait(&status) > 0);
}

