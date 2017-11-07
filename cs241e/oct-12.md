# Nested procedures

```
def f() = {
  val x = 2
  val w = 5
  def g() = {
    val y = 3
    val x = 7
    return x + y + h()
  }

  def h() = {
    val z = 4
    z + w
  }

  g()
}
```

```
f() {         // 0
  g() {}      // 1
  h() {       // 1
    k() { return g }    // 2
    return k()
  }
  return h()
}

f() // -> g
```

Def static link: the frame of the statically enclosing procedure of the
currently executing procedure

Def resulting depth of a procedure: the number of procedure that it is nested
inside.

To access a variable, n = depth(current) - depth(declaring procedure of variable)

Follow static link n times, access variable in that frame.


                                                                `callee`
At a cal site, compute static link: depth(static link) = depth(call target) - 1

```
n = depth(current procedure) - depth(static link)
```

```
n = depth(current procedure) - (depth(call target) - 1)
```

```
if n = 0
  static link = frame pointer
else
  static link = follow static link `n` times
end
```

eg.
```
f calls g, n = 0, sl = fp
g calls h, n = 1, sl = g's static link
k calls g, n = 2, read k' static link, read h's static link
f calls k, n = -1 // can't happen, h >= 0 => n >= 0
```
