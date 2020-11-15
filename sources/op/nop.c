#include <stdint.h>

#include "vm.h"

uint8_t vm_op_nop(t_vm *vm)
{
  (void)vm;
  /* Does nothing and consumes a cycle */
  return (VM_STAT_RUN);
}
