# Types

## Definitions

* a type is a collection of values

* a type is an INTERPRETATION of sequences of bits
  * eg.
    * 1001 : UnsignedInt // -> 9
    * 1001 : 4BitTwoComplement // -> -7
    * 0100001 : ASCIIChar // -> 'A'

* a type is a computable property of a program that guarantees some property of
  its executions. (infer?)


* Machine language: memory location stores 32 bits
  * Lacs/C/Java: variable stores a value of some type

## Lacs

* Int: integer between (-2 ^ 31) and (2 ^ 31 - 1) with arithmetic modulo (2 ^
  32)
* `(type, _) => type`: function that takes arguments of specified types, returns
  value of return type.

## Definitions

* a *type system* is a set of rules that compute the type of an expression using
  the types of its sub expressions.
  * eg.
    * Int + Int = Int
    * Float + Float = Float

* a type system is *sound* if whenever it computes a type `Tao` for expression
  `e`, then `e` evaluates to a value in `Tao`.
