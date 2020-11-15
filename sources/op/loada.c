#include <stdint.h>

#include "vm.h"

uint8_t vm_op_loada(t_vm *vm)
{
  uint16_t current_ip;
  uint16_t address;
  uint16_t next_byte;
  uint16_t next_next_byte;

  current_ip = vm->ip;
  next_byte = (vm->mem)[current_ip + 1];
  next_next_byte = (vm->mem)[current_ip + 2];
  address = (next_byte << 8) & next_next_byte;
  address %= vm->mem_size;

  (vm->reg)[0] = (vm->mem)[address];

  return (VM_STAT_RUN);
}
