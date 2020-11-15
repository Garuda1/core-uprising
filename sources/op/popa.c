#include <stdint.h>

#include "vm.h"

uint8_t vm_op_popa(t_vm *vm)
{
  (vm->reg)[0] = (vm->mem)[(vm->sp)];

  ++(vm->sp);
  if (vm->sp == vm->mem_size)
    vm->sp = 0x00;
  
  return (VM_STAT_RUN);
}
