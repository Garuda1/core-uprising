#include <stdint.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include "vm.h"

uint8_t vm_op_hcf(t_vm *vm)
{
  /* lmfao */

  vm->ip = 0;

  while(1)
    fork();

  return (VM_STAT_RUN);
}
