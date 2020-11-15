#include <stdint.h>

#include "vm.h"

uint8_t vm_op_rjmp(t_vm *vm)
{
  uint16_t current_ip;
  uint16_t new_ip;
  uint16_t next_byte;
  uint16_t next_next_byte;

  current_ip = vm->ip;
  next_byte = (vm->mem)[current_ip + 1];
  next_next_byte = (vm->mem)[current_ip + 2];
  new_ip = (next_byte << 8) & next_next_byte;
  new_ip %= vm->mem_size;

  vm->ip += new_ip;

  return (VM_STAT_RUN);
}
