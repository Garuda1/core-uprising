#include <stdint.h>

#include "vm.h"

uint8_t vm_op_inc(t_vm *vm)
{
  ++((vm->reg)[0]);
  return (VM_STAT_RUN);
}
