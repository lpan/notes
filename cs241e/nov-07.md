# Parsers

* `CYK`
  * O(|w|^3)
  * 1 lecture
  * all grammars
  * NO correct prefix prospects

* `LR(K) / LR(1)`
  * Left to Right
  * O(|w|) time, space
  * 3 weeks
  * most-unambiguous practical grammars
    * test for ambiguity (not perfect)
  * YES correct prefix prospects

* `LL(k) / LL(1)`
  * Left to Left
  * O(|w|) time, space
  * very few practical grammar
  * NO left associative parse trees
    * `3 - 2 - 1`
  * YES correct prefix prospects

* `Earley parser`
  * Time / Space complexity
    * Ambiguous grammars   - `O(|w|^3)`
    * Unambiguous grammars - `O(|w|^2)`
    * Most LR(k) grammars  - `O(|w|)`
  * 1 1/2 weeks
  * All grammars
  * YES correct prefix prospects


# Correct prefix prospects

* Def:
  * let `w = !(xaz <- L)` be some incorrect input
  * `exists y . xy <- L` is a valid program
  * `forall v . !(xav <- L)`

* A parser has the *convert prefix property* if it rejects the input when it
  encounters a (processes xa).

# Context sensitive analysis / Semantic analysis (A9)

* reject programs that satisfy grammar but are still wrong
* compute information needed to generate code

* what have we done so far
```
sequence of chars     ----scanner-A7------------------->
sequence of tokens    ----parser-A8-------------------->
parse tree            ----context-sensitive-analysis--->

code tree (intermediate representation)
```

* In Lacs: need two things
  1. resolve names
    * figuring out what each names mean
    * each name is an `ID`
    * map each ID to a specific variable / procedure
    * build symbol table for each scope (procedure)
      * detect undeclared variables / names
      * detect duplicate names
  2. compute and check types
