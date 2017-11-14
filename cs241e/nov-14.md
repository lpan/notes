```
def ID(varDefs): type = { vardef defdef E }
```

* use context to get the type from nested procedures

* all names in `varDef` `varDef!` `defdef` are distinct!

## A10

* `parse tree` + `scopes` + `types` -> code tree

* def: a syntax-directed translation generates code for each node at a tree by
  combining the code that it generated for each subtree


# Heap

* In the context of memory management.
* A heap is a data structure that manages memory so it can be allocated and
  freed (returned) at any time.

* Operations:
  * new/malloc - allocate new block of memory of given size, determined at
    runtime.
  * free/delete - returns memory to allocation pool (to be reused)

* need a data structure to allocate / deallocate for heap
