
## Free variable
A free var is an expression is a variable that is not defined within the
expression!

eg.
- x is not free in `x => x + increment`
- x is free in `x + increment` (x declared in parent scope)

# Closure

A closure is a pair of
- the code of a function body
- an environment for the free variables in the function body

Call closure

```scala
def constructor(a: Int): (Int) => Int = {
  var b = a * 2
  def procedure(c: Int) = { a + b + c }
  procedure
}

functionValue = constructor(42)
functionValue(5) // closure call-site (call closure, target is code that
                 // evaluates to a closure code that reads variable functionValue)

```

`functionValue` must store label of procedure code. (static link to pass in)
