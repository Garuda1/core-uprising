/*
 * args.h
 *
 */

#ifndef ARGS_H
#define ARGS_H

#include <stdint.h>

#define FLAG_PLAYER_NB       "--player"
#define FLAG_PLAYER_SIZE     "--size"

#define FLAG_ALT_PLAYER_NB   "-p"
#define FLAG_ALT_PLAYER_SIZE "-s"

typedef struct s_args t_args;
struct s_args
{
  uint64_t   player_nb;   /* How many players are to share the memory */
  size_t     player_size; /* Bytes of memory per player */
  char     **player_path; /* Path to the player programs */
};

t_args *args_init(t_args *args);                                     /* Initializes the argument structure */
t_args *args_parse(t_args *args, const int argc, char **argv);       /* Parses the arguments */
t_args *args_check(t_args *args, const int argc);                    /* Checks if they are valid */
t_args *args_clean(t_args *args);                                    /* Memory deallocation */

#endif
