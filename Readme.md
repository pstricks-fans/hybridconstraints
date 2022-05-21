# Requirements

- Project Type: Game
- Project Template: Blank
- Language: C++
- Starter Content: Included
- Project Name: MyProject


# Steps To Reproduce

- Once you have successfully regenerated as well as compiled the project,<br/> 
  drag `ABallActor` on to the level.

- Set the ball position to `(0,0,100)` via the `Details` panel.

- The ball will orbit around a vertical axis passing through `(0,0,100)`.



# Expected Result

- The ball moves circularly on the horizontal plane but it also must fall due to gravity.


# Question

How to make the ball 

- move circularly on the horizontal plane only due to kinematic constraint (its `x` and `y`  positions are set by `Tick`)

- and fall due to gravity ?



# Note

Please refrain from suggesting me to set `z = g * t * t / 2` in `Tick` because it is not what I want to learn. I want to learn how to mix kinematic and dynamic constraints.