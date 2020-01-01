# PID Components

The parameters where chosen empirically. By starting with somewhat 
reasonable values and halving then until somewhat stable performance 
could be achieved. From there the parameters where optimized manually 
one by one by analyzing the overshoots and oscillations of the car.

A more reasonable apporach would be to try out the twiddle algorithm 
(local hill-climber) for tuning the hyper parameters. 

Setting only the P component resulted in overshoot and therefore the 
vehicle was out of track. Combining it with the D component resulted in 
minimizing the overshoots and thus the car stayed in the track. The I
component however had very less effect as there was no systematic bias 
simulated in the project. Small videos are recored for each case.
