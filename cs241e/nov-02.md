# Parsing algorithm

* parsing: CYK
* input: grammar G, string w
* output:
  * boolean: does `s =>* w`
  * generate derivation / parse tree

```
// does Alpha =>* x?
parse(alpha, x) =
  if (alpha.isEmpty) {
    return x.isEmpty
  } else if (alpha = aBeta) {
    // x starts with 'a'
    return x = az && parse(beta, z)
  } else if (alpha = a) {
    for each (A -> Gamma <- P) {
      if (parse(Gamma, x)) return true
    }
    return false
  } else {
    for each split x = x1 x2 {
      if (parse(A1, x1) and parse(Beta, x2)) return true
    }
    return false
  }
```

* `expr -> ID`
* `expr -> expr op expr`

* eg.
  * `p(expr =>* ID + ID)`

  ```
  // expr -> ID
  p(ID =>* ID + ID)
    p(epsilon =>* + ID) // false
  // expr -> expr op expr
  p(expr op expr => ID + ID)
  // epsilon, ID + ID
  | p(expr => * epsilon)
  |   // expr -> ID
  |     p(ID => *epsilon) // false
  |   // expr -> expr op expr
  |     p(expr op expr =>* epsilon)
  |       // (split empty strings)
  |       // split epsilon = epsilon, epsilon
  |       p(expr =>* epsilon) // false (memo)
  |
   --------> false

   // ID + ID
   parse(expr =>* ID)
    // expr -> ID
      parse(ID =>* ID)
        parse(epsilon =>* epsilon) // true
      parse(op expr =>* + ID)
  ```

* Running time
  * infinite (on some grammar)
  * exponential (on some grammar)

  * Use `memoization` to make it faster
    * What all possible values of `alpha` and `x`?
      * `alpha` = S (start symbol of grammar) or a suffix at  a `r.h.s.` of some
        production rule
      * `x = substring of input`
        * # of possible values:
          * alpha: O(1) for any given grammar
          * from:   O(|w|) // O(size of input)
          * length: O(|w|)
        * Memoization table
                                Alpha     from  length
          * val memo = Map[ (Seq[Symbol],  Int,   Int) ]

            1. whenever `parse/recur` returns, save the return value in the memo
               table
            2. at beginning of `parse/recur`, check wether memo table already
               has result
            3. just before starting computations in `recur`, set `memo(alpha,
               x) = false / None`

            * Complexity: O(|w|^2) space O(|w|^3) time

* We want parse trees not true/false
  * false -> can't generate a parse tree
  * true -> some parse tree....

```
// does Alpha =>* x?
parse(alpha, x) =
  if (alpha.isEmpty) {
    if x.isEmpty return Seq()
    else return None
  } else if (alpha = aBeta) {
    // x starts with 'a'
    if (x = az && parse(beta, z)) return a +: parse(Beta, z)
    else return None
  } else if (alpha = a) {
    for each (A -> Gamma <- P) {
      if (parse(Gamma, x)) return parse(Gamma, x)
    }
    return None
  } else {
    for each split x = x1 x2 {
      if (parse(A1, x1) and parse(Beta, x2)) return parse(A, x1) ++ parse(Beta, x2)
    }
    return None
  }
```
