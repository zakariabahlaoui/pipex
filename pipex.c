#include "pipex.h"

int ft_open_infile(const char *infile)
{
    int fd;

    fd = open(infile, O_RDONLY);
    if (fd == -1)
    {
        perror(infile);
        return -1;
    }
    return fd;
}

int ft_open_outfile(const char *outfile)
{
    int fd;

    fd = open(outfile, O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR);
    if (fd < 0)
    {
        perror(outfile);
        return -1;
    }
    return fd;
}

void exec_command(const char *cmd, char **enve)
{
    char **arg;

    arg = ft_split(cmd, ' ');

    execve(arg[0], arg, enve);
    exit(EXIT_FAILURE);
}

int exec_cmd(const char *cmd, char **enve, int out, int in)
{
    int pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork: ");
        return -1;
    }

    if (pid == 0)
    {
        dup2(out, 1);
        dup2(in, 0);
        close(in);
        close(out);

        exec_command(cmd, enve);
    }
    close(out);
    close(in);
}

int ft_exec_pipe(char **cmd, char **enve, int in_fd, int out_fd)
{

    int fdp[2];

    if (pipe(fdp) == -1)
        return -1;

    exec_cmd(cmd[2], enve, fdp[1], in_fd);
    exec_cmd(cmd[3], enve, out_fd, fdp[0]);

    wait(NULL);
    // waitpid(pid, NULL, 0);
    // waitpid(pid2, NULL, 0);

    return 1;
}

int pipex(int argc, char **argv, char **enve)
{
    int in_fd;
    int out_fd;

    in_fd = ft_open_infile(argv[1]);
    out_fd = ft_open_outfile(argv[4]);
    if (in_fd == -1 || out_fd == -1)
        return -1;

    ft_exec_pipe(argv, enve, in_fd, out_fd);
}

int main(int argc, char **argv)
{
    int err;
    char *enve[] = {NULL};
    if (argc < 5)
    {
        printf("you need more argument");
    }
    else
    {
        err = pipex(argc, argv, enve);
    }

    return 0;
}

// int main(int argc, char **argv)
// {
//     int fd;=;-
//     fd = open("fil.txt", O_WRONLY);
//     printf("%d\n", fd);
//     int id = fork();
//     // printf("teste1\n");

//     if (id == 0)
//     {
//         dup2(fd, 1);
//         close(fd);

//         // execlp("ping", "ping", "-c", "1", "google.com", NULL);
//         execlp("ls", "-1", NULL);

//         printf("test\n");
//     }
//     else
//     {
//         printf("test2\n");
//     }

// char *pth = "/usr/bin/ls";
// char *arg[] = {"ls", "-l", NULL};
// char *enve[] = {NULL};
// execve(pth, arg, enve);
// }
