# Formal languages

Precise specification of a language

* Is it in the language?
* Is it not in the language?

Example:
// specify what is (in) / (not in) the language
* L1 = { R2D2, cat, BBQ, popsicle }

* Recognition
  * Given language `L` and word `w`:
  * Is `w` in `L`?
  * We cannot always create a decision algorithm!

* Interpretation / translation
  * Given language `L` and word `w`:
    * `w` has a meaning; that is an interpretation or translation

* Formal language analysis is Recognition + Interpretation

## Alphabets

* It can be any finite set of symbols.
* In film, frames can be alphabets.
* ex. {0, 1}, {a, ..., z}, ....

## Word (over alphabets)

* Finite sequence of symbols
* examples:
  * 1001010 over {0, 1}
  * lmao over {a, z}


## Language

* A language is a set of `words` over some `alphabets`
* May be infinite
* May be empty
* Example: All C++ programs, all binary strings.

## Classes of languages

Note:
* All finite languages are regular but not all regular languages are finite!
* All finite languages are subset of context free too

* Finite (you CAN count it)
  * L = { alpha, R2D2, cat }
  * L = all binary strings of 8 bits

* Regular
  * L = all strings consisting of only the character 'x': 'x', 'xx', ....
  * L = { alpha, R2D2, cat, bbq } + all binary strings of 8 bits.

* Context free
  * English is context sensitive: "Chicken is hot" ->
    * take chicken out for a date
    * spicy
    * high temperature

  * There is no context required.
  * L = the language of balanced brackets, (), (()), (())(), ...
  * L = { alpha, R2D2, cat, bbq }

* Undecidable
  * Languages Turing machines cannot accept

## DFAs

* A state machine that decides if a word is accepted or rejected.
* Deterministic finite automata
* "Double circle" = accepting state

* DFA is a 5-tuple, { sigma, Q, q0, A, Delta }
  * sigma - alphabets
  * Q finite set of states
  * q0 <- Q: the start state
  * A is a subset of Q: accepting states
  * Delta: Q x Sigma -> Q: transition functions
    * Delta(old state, an alphabet) -> new state

* If no transition path available then it is not valid.

* Recognition algorithm
  * Delta\*: Q\* x Sigma -> Q: extended transition function
  * Delta(q, Epsilon) = q

* A word `w` is accepted by the DFA if Delta\*(q0, w) <- `A`
  * In other words, the final state is accepting
* The language specified by the DFA is the set of all words accepted by the DFA.

## NFAs

* Non-deterministic finite automata

* Example
  * L1 = hexadecimal numbers.
  * L2 = decimal integers with no leading 0s.
  * What is the DFA of L1 Union L2

* More than one path (transition function result) for one alphabet

* Also 5 tuple, (Sigma, Q, q0, A, Delta)
  * Same as DFA but
    * Delta: Q x Sigma -> 2^Q
    * 2^Q - set of all states

* A word `w` is accepted by the NFA if Delta\*(q0, w) Intersect A != {}
  * At least one of the final state is accepting!
  * Follow all possible paths!!!!

* Recognition algorithm:
  * Delta\*: Q x Sigma\* -> 2^Q - extended transition function

## Epsilon transitions

* NFA that has transitions on nothing!
* It is forking the the DFA to get a NFA
* Go from one state to another state with no input
* Every DFA can be converted to a NFA

## Regular expression

* An alternative to all the state machine craps we just learnt

* R ::= eps
  * L(eps) = {eps}

* Alternation: R ::= R1 | R2
  * L(R1 | R2) = L(R1) U L(R2)

* R ::= R1 R2
  * TODO

* Repetition: R\*
  * L(R\*) = (x1x2x2.....xn | forall i x i <- L(R), n >= 0)

### Regular expression rules

* (A | B) contains { A, B }
* A\* contains { eps, A, AA, AAA, ... }
* (AB)\* contains { eps, AB, ABAB, ABABABAB, ... }
* AA\* contains { A, AA, AAA, ... }
* (A|B)\*AA(A|B)\* contains all strings over { A, B } containing AA

### Kleene's Theorem
