#include <stdint.h>

#include "vm.h"

uint8_t vm_op_cjmp(t_vm *vm)
{
  if (vm->flag)
    vm_op_jmp(vm);
  return (VM_STAT_RUN);
}
