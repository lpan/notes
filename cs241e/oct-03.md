# Lecture 8

```
r1 = a * b
r2 = c * d
r1 = r1 + r2
r2 = e * f
r2 = r1 - r2
g = r1 + r2
```

A colouring assigns a colour (register) to each vertex so that each edge
connects different colours (registers)

Finding a minimal colouring for an arbitrary graph is NP-hard. Simple greedy
tend to work well.


```
for each vertex v {
  colour v with lowest-numbered colour not yet used by any neighbours
}
```

If graph requires more colours than registers, allocate some colours to memory
locations on stack.

## Procedures

Procedures: an abstraction that encapsulates a reusable piece of code.

* Calling code
  - transfers control to procedure (modifies PC).
  - passes arguments for procedure parameters.

* Procedure
  - transfers control back to call site.
  - returns a value.

* Calling code and procedure must agree on **conventions**
  - where (memory / register) argument / return values are found.
  - type of parameters / return values.
  - which registers procedure may modify.
  - who allocates / frees memory.

* CS241E conventions:
  - callee allocates / deallocates frame

  - Calling a procedure
    * modifies Reg.savedPC
    * preserves Reg.framePtr after the call (callee saves 29)
    * preserves Reg.stackPtr (callee saves)
    * modifies Reg.result (caller save)
    * modifies all after registers (caller-save)
    * caller allocates the parameter chunk and passes its address in
      `Reg.allocated`


### Caller

#### Code
```
LIS (Reg.targetPC)
Use(proc)
JALR(Reg.targetPC) // Reg(8)
```

#### Frame

### Callee

#### Code
```
Define(proc)
Reg.savedParamPtr = Reg.allocated
stack.allocate(frame)

dynamicLink = Reg.framePtr
savedPC = Reg.savedPC($31)

Reg.framePtr = Reg.allocated
paramPtr = Reg.savedParamPtr

..... body .....

Reg.savedPC = savedPC
Reg.framePtr = dynamicLink
stack.pop // frame
JR(Reg.savedPC)
```

#### Frame
```
------
size                                   <----- FramePtr
------
reserved
------
variables
temp vars
------
saved PC
------
Dynamic link (old frame pointer)
------
```
