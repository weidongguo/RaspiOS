#ifndef CONTEXT_SWITCH_H
#define CONTEXT_SWITCH_H

struct arm_regfile_t {
  //size_t is the word size of native architecture
  //The standard 32-bit ARM calling convention allocates the 16 ARM registers as:
  // r15 is the program counter.
  // r14 is the link register. 
  // (The BL instruction, used in a subroutine call, stores the return address in this register).
  // r13 is the stack pointer. (The Push/Pop instructions in "Thumb" operating mode use this register only).
  // r12 is the Intra-Procedure-call scratch register.
  // r4 to r11: used to hold local variables.
  // r0 to r3: used to hold argument values passed to a subroutine, and also hold results returned from a subroutine.
  size_t r0; 
  size_t r1; 
  size_t r2; 
  size_t r3; 
  size_t r4; 
  size_t r5; 
  size_t r6; 
  size_t r7; 
  size_t r8;
  size_t r9;
  size_t r10;
  size_t r11;
  size_t r12;
  size_t sp;
  size_t lr;
};

#ifdef __cplusplus
extern "C" {
#endif

void ContextSwitch(arm_regfile_t *pOldRegFile, arm_regfile_t *pNewRegFile);

#ifdef __cplusplus
}
#endif

#endif
