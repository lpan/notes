## More abstractions

### Control structures

* If statements
* While loops


#### If Statements

```
// op <- { ==, <, >=, ... }
if (e1, op, e2) T else E
```

How to generate code for the `if` construct?

```
evaluate(e1)
ti = $3
evaluate(e2)
$4 = ti
op, bne / beq, elseLabel

T
beq endLabel
Define(elseLabel)

E
Define(endLabel)
```

#### While Loops

TODO


#### Arrays

* Contiguous area of memory
* Keep track of address of element 0
* To access element i, add c * i to start address
* need to read/write memory at computed address
  - read: deref (LW)
  - write: assignToAddr (SW)

Def: register alocation assign registers / stack locations to variables

Def: a variable is live at program point p. Its value at p may be read later in
the program.

Def: the live range at a var is the set of program points where it is live.

* Variables can share a register if their live ranges are disjoint!
* The start of a live range is always after a write
* The end of a live range is always before a read
* The variable is dead
  - if it is never read in the rest of the program
  - if it will be overwritten before it is dead
