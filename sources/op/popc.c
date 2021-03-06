#include <stdint.h>

#include "vm.h"

uint8_t vm_op_popc(t_vm *vm)
{
  (vm->reg)[2] = (vm->mem)[(vm->sp)];

  ++(vm->sp);
  if (vm->sp == vm->mem_size)
    vm->sp = 0x00;

  return (VM_STAT_RUN);
}
