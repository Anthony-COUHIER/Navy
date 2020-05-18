/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** connection
*/

#include "proto.h"

void hd(int sig, siginfo_t *action, UNUSED void *ucontext)
{
    if (sig == SIGUSR1)
        my_putstr("\n\nenemy connected\n\n");
    info.enemy_pid = action->si_pid;
}

int connection(int argc, char **argv)
{
    struct sigaction act;

    act.sa_sigaction = &hd;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    info.enemy_pid = my_atoi(argv[1]);
    my_printf("%s%d", "my_pid: ", getpid());
    if (argc == 3 && my_atoi(argv[1]) != 0) {
        if (kill(my_atoi(argv[1]), SIGUSR1) == -1) {
            write(1, "\nBad pid\n", 9);
            return 84;
        } else
            my_putstr("\nsuccessfully connected\n\n");
    } else if (argc == 2) {
        my_putstr("\nwaiting for enemy connection...");
        if (sigaction(SIGUSR1, &act, NULL) < 0)
            return 84;
        pause();
    } else
        return 84;
    return 0;
}
