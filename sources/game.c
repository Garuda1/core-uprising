/*
 * game.c
 *
 */

#include <stdint.h>
#include <stdlib.h>

#include "args.h"
#include "util.h"
#include "text.h"
#include "vm.h"

t_game *game_init(t_game *game, t_args *args)
{
  size_t i;

  game->player_nb = args->player_nb;
  game->player_size = args->player_size;

  /* Allocate the memory used by the VMs */
  if ((game->memory = malloc((game->player_nb)*(game->player_size)*(sizeof(uint8_t)))) == NULL)
    return (retstr(NULL, TEXT_GAME_INIT_FAILURE, __FILE__, __LINE__));

  /* Allocate the memory for the VMs */
  if ((game->vm = malloc((game->player_nb)*(sizeof(t_vm)))) == NULL)
    return (retstr(NULL, TEXT_GAME_INIT_FAILURE, __FILE__, __LINE__));

  /* Initialize all the game's VMs */
  for (i=0; i<(game->player_size); ++i)
    vm_init(&((game->vm)[i]), game, i);

  return (game);
}

t_game *game_clear(t_game *game)
{
  free(game->memory);
  return (game);
}
