/*
 * main.c
 *
 */

#include <stdlib.h>

#include "args.h"
#include "util.h"
#include "text.h"

int main(int argc, char **argv)
{
  t_args args;

  if (args_init(&args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (args_parse(&args, argc, argv) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (args_check(&args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));

  if (args_clean(&args) == NULL)
    return (retstri(EXIT_FAILURE, TEXT_MAIN_FAILURE, __FILE__, __LINE__));


  return (EXIT_SUCCESS);
}
