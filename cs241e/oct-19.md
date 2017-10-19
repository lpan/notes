# Language features

## Objects

Def: an *object* is a structure that contains data (state) and
methods/procedures (behaviour)

```
class Counter {
  var value = 0
  def get() = value
  def incrementBy(amount: Int) = { value += amount }
}

val c = new Counter
c.get() // => 0

def newCounter: (() => Int, Int => Unit) = {
  var value = 0
  def get() = value
  def incrementBy(amount: Int) = { value += amount }
  return (get, incrementBy)
}

val c2 = newCounter
c2._1()   // => 0
c2._2(42)
c2._2(-5)
c2._1()
```

Def: an *object* is a collection of closures (indexed by names) that close over
a common environment.

# Tail call optimization

```
def m2() = {
  var i = 0
  var j = 0
  def loop(): Unit = {
    var k = 42
    if (i < 10) {
      i = j + 1
      j = j + i
      //k
      // free frame
      loop()
    }
    //k
  }
  loop()
  i + j
}
```

## Identifying tail calls

- a call is in tail position if it is the last thing executed before epilogue
- may be nested in if statements

eg.
```
def f() = {
  def g() = {
    // do stuffs
  }
  // tail call optimization will not be suitable since "g" may access variables
  // declared in "f"
  g()
}
```

- tail call optimization not safe if target is nested in caller

## How to perform the optimization

- Assembly code of loop procedure

Original
```
// call loop
evaluate args
allocate param chunk
write args into params
       <----------------------|
JALR                          |
                              |
// epilogue             ------|
Reg.savedPC = savedPC
Reg.fp = dynamicLink
stack.pop // frame
stack.pop // parameters
JR(31)
```

With optimization
```
evaluate args
allocate params
write args into params
Reg.savedPC = savedPC
Reg.fp = dynamicLink
stack.pop
stack.pop
stack.pop
allocate params B // again
copy params A into params B
JR
```
