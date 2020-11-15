#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "vm.h"
#include "text.h"
#include "util.h"

t_vm *vm_init(t_vm *vm, t_game *game, const uint64_t id)
{
  /* Zero the memory field */
  memset((void*)vm, 0, sizeof(t_vm));

  vm->id   = id;
  vm->ip   = (id*(game->player_size));
  vm->sp   = (((id+1)*(game->player_size))-1);
  vm->st   = VM_STAT_RUN;
  vm->flag = 0;
  vm->mem  = game->memory;

  vm->reg[0] = 0x00;
  vm->reg[1] = 0x00;
  vm->reg[2] = 0x00;
  vm->reg[3] = 0x00;

  vm->mem_size = ((game->player_size)*(game->player_nb)*sizeof(uint8_t));

  return (vm);
}

int vm_exec(t_vm *vm)
{
  uint8_t vmstat;

  vmstat = vm_op_tab[vm->mem[vm->ip]](vm);

  switch (vmstat)
  {
    case VM_STAT_RUN:
      break;

    case VM_STAT_STOP:
      return (VM_STAT_STOP);
      break;

    case VM_STAT_FATAL:
      return (retstri(VM_STAT_FATAL, TEXT_VM_EXEC_HCF, __FILE__, __LINE__));
      break;

    default:
      break;
  }

  /* Increment the IP */
  ++(vm->ip);
  (vm->ip) %= (vm->mem_size);

  return (vmstat);
}

t_vm *vm_load(t_vm *vm, const uint8_t *prog)
{
  memcpy((char*)(vm->mem), (char*)prog, vm->mem_size);
  return (vm);
}
