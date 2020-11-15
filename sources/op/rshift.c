#include <stdint.h>

#include "vm.h"

uint8_t vm_op_rshift(t_vm *vm)
{
  (vm->reg)[0] = (vm->reg)[0] >> (vm->reg)[1];
  return (VM_STAT_RUN);
}
