  .global ContextSwitch
ContextSwitch:
  stmia r0, {r0-r14}
# can't load value to PC(r15) directly; has to go through a branch instruction.
  ldmia r1, {r0-r14}
  bx  lr
