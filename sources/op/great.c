#include <stdint.h>

#include "vm.h"

uint8_t vm_op_great(t_vm *vm)
{
  vm->flag = ((vm->reg)[0] >= (vm->reg)[1] ? 1 : 0);
  return (VM_STAT_RUN);
}
