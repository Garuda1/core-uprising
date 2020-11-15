#include <stdint.h>

#include "vm.h"

/* okay so I'm high asf on titty skittles and need some help to work this out
 * so basically this instruction sets the instruction pointer to the next address in memory
 * the address is two bytes long so we could do like idk
 *   address = (uint16_t) (next_byte << 8) && (next_next_byte)
 * and then idfk ip = address
 * whatever let's try it out
 *
 * EDIT: shit don't forget to modulo it cause idk buffer overflow stuff like that
 */

uint8_t vm_op_jmp(t_vm *vm)
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

  vm->ip = new_ip;

  return (VM_STAT_RUN);
}
