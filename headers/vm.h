/*
 * vm.h
 *
 */

#ifndef VM_H
#define VM_H

#include <stdint.h>
#include <stddef.h>

#include "args.h"

#define VM_STAT_RUN   0x00 /* Keep the VM running */
#define VM_STAT_STOP  0x01 /* Halt */
#define VM_STAT_FATAL 0x02 /* Halt and catch fire */

typedef struct s_vm t_vm;
struct s_vm
{
  uint64_t id;            /* Player ID */
  uint16_t ip;            /* instruction pointer */
  uint16_t sp;            /* Stack pointer */
  uint8_t  st;            /* Status register */
  uint8_t  flag : 1;      /* Flag register used by comparison instructions */

  uint8_t reg[4];         /* Registers */

  uint8_t *mem;           /* Memory */

  size_t mem_size;
}; 

typedef struct s_game t_game;
struct s_game
{
  uint64_t player_nb;   /* Programs to put in memory */
  size_t   player_size; /* Bytes per program */

  uint8_t *memory;      /* The memory shared by the VMs */
  t_vm    *vm;          /* The VMs themselves */
};

t_game *game_init (t_game *game, t_args *args);           /* initialize the t_game structure */
t_game *game_clear(t_game *game);                         /* clear it / free its allocated mem */

t_vm *vm_init(t_vm *vm, t_game *game, const uint64_t id); /* Initialize the t_vm structure */
int   vm_exec(t_vm *vm);                                  /* Execute on cycle on the VM */
t_vm *vm_load(t_vm *vm, const uint8_t *prog);             /* Load a program on the VM's memory field */

/* Operations */
extern uint8_t (*vm_op_tab[])(t_vm *);
uint8_t vm_op_nop    (t_vm *dxvm);
uint8_t vm_op_add    (t_vm *dxvm);
uint8_t vm_op_sub    (t_vm *dxvm);
uint8_t vm_op_xor    (t_vm *dxvm);
uint8_t vm_op_or     (t_vm *dxvm);
uint8_t vm_op_not    (t_vm *dxvm);
uint8_t vm_op_and    (t_vm *dxvm);
uint8_t vm_op_lshift (t_vm *dxvm);
uint8_t vm_op_rshift (t_vm *dxvm);
uint8_t vm_op_loada  (t_vm *dxvm);
uint8_t vm_op_loadb  (t_vm *dxvm);
uint8_t vm_op_loadc  (t_vm *dxvm);
uint8_t vm_op_loadd  (t_vm *dxvm);
uint8_t vm_op_push   (t_vm *dxvm);
uint8_t vm_op_pusha  (t_vm *dxvm);
uint8_t vm_op_pushb  (t_vm *dxvm);
uint8_t vm_op_pushc  (t_vm *dxvm);
uint8_t vm_op_pushd  (t_vm *dxvm);
uint8_t vm_op_popa   (t_vm *dxvm);
uint8_t vm_op_popb   (t_vm *dxvm);
uint8_t vm_op_popc   (t_vm *dxvm);
uint8_t vm_op_popd   (t_vm *dxvm);
uint8_t vm_op_jmp    (t_vm *dxvm);
uint8_t vm_op_cjmp   (t_vm *dxvm);
uint8_t vm_op_stop   (t_vm *dxvm);
uint8_t vm_op_eq     (t_vm *dxvm);
uint8_t vm_op_neq    (t_vm *dxvm);
uint8_t vm_op_less   (t_vm *dxvm);
uint8_t vm_op_great  (t_vm *dxvm);
uint8_t vm_op_inc    (t_vm *dxvm);
uint8_t vm_op_dec    (t_vm *dxvm);
uint8_t vm_op_hcf    (t_vm *dxvm);

#endif
