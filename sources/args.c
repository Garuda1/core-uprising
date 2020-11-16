/*
 * args.c
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "args.h"
#include "text.h"
#include "util.h"

t_args *args_init(t_args *args)
{
  args->player_nb = 0;
  args->player_size = 0;
  args->player_path = NULL;

  return (args);
}

t_args *args_parse(t_args *args, const int argc, char **argv)
{
  int    i;
  size_t current_player;

  current_player = 0;

  /* For each shell argument */
  for (i=1; i<argc; ++i)
  {
    printf("argc=%d\n", argc);
    if ((!strcmp(argv[i], FLAG_PLAYER_NB) || !strcmp(argv[i], FLAG_ALT_PLAYER_NB))  && (i+1)<argc)
    {
      args->player_nb = strtoul(argv[++i], NULL, 10);
      printf("player_nb=%ld\n", args->player_nb);
      if ((args->player_path = malloc(sizeof(char*)*(args->player_nb))) == NULL)
        return (retstr(NULL, TEXT_ARGS_PARSE_MALLOC_FAILURE, __FILE__, __LINE__));
    }

    else if ((!strcmp(argv[i], FLAG_PLAYER_SIZE) || !strcmp(argv[i], FLAG_ALT_PLAYER_SIZE)) && (i+1)<argc)
      args->player_size = strtoul(argv[++i], NULL, 10);

    /* Treat the argument as the path to a player program */
    else if (current_player < (args->player_nb))
      args->player_path[current_player++] = argv[i];

    else
    {
      printf(TEXT_ARGS_INVALIDARG, argv[i]);
      return (retstr(NULL, TEXT_ARGS_PARSE_FAILURE, __FILE__, __LINE__));
    }
  }

  return (args);
}

t_args *args_check(t_args *args, const int argc)
{
  if (args->player_nb < 2)
    return (retstr(NULL, TEXT_ARGS_CHECK_FAILURE, __FILE__, __LINE__));

  if ((uint64_t)argc != (5+(args->player_nb)))
    return (retstr(NULL, TEXT_ARGS_CHECK_FAILURE, __FILE__, __LINE__));

  if (args->player_size < 1)
    return (retstr(NULL, TEXT_ARGS_CHECK_FAILURE, __FILE__, __LINE__));

  return (args);
}

t_args *args_clean(t_args *args)
{
  free(args->player_path);
  return (args);
}
