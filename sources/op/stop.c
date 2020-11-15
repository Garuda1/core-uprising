#include <stdint.h>

#include "vm.h"

uint8_t vm_op_stop(t_vm *vm)
{
  (void)vm;
  return (VM_STAT_STOP);
}
