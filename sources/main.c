/*
 * main.c
 *
 */

#include <stdlib.h>

#include "args.h"
#include "util.h"
#include "text.h"
#include "vm.h"

int main(int argc, char **argv)
{
  t_args args;
  t_game game;

  if (args_init(&args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (args_parse(&args, argc, argv) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (args_check(&args, argc) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (game_init(&game, &args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (args_clean(&args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (game_clear(&game) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  return (EXIT_SUCCESS);
}
