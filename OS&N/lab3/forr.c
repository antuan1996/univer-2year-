#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(int argc, char **argv)
{
    kill(1, SIGKILL);
    int pid;
    FILE* fin = fopen("report.txt", "r");
    if( fin == NULL )
    {
        puts("Error! Report file not found !");
        return -1;
    }
    fscanf(fin, "%d",&pid);
    fclose( fin );
    if(pid)
    {
        kill(pid, SIGQUIT);
        FILE* fout = fopen("report.txt", "w");
        fprintf(fout, "%d", 0);
        fclose( fout );
    }
    else
        {
            int n_pid;
            n_pid = fork();
            if( n_pid == 0 )  // I'm child
                sleep(100);
            else
            { // I'm parent
                FILE* fout = fopen("report.txt", "w");
                fprintf(fout, "%d", n_pid);
                fclose( fout );
            }    
        }
    return 0;
}
