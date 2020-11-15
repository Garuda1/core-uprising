#include <stdint.h>

#include "vm.h"

uint8_t vm_op_push(t_vm *vm)
{
  if (vm->sp == 0)
    vm->sp = (vm->mem_size - 1);
  else
    --(vm->sp);

  (vm->mem)[vm->sp] = (vm->mem)[++(vm->ip)];

  return (VM_STAT_RUN);
}
