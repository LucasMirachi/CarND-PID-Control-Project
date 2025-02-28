# Writeup - PID Control Project 
---
### Introduction

Basically, a PID controller is an instrument used in industrial control applications to regulate temperature, flow, pressure, speed and other process variables. PID (proportional integral derivative) controllers use a control loop feedback mechanism to control process variables and are the most accurate and stable controller.
 
The goal of this project is to implement a PID Controller in C++ to maneuver a vehicle around a simulator track! To do so, I'll be using the same lake race track from the [Behavioral Cloning Project](https://github.com/LucasMirachi/CarND-Behavioral-Cloning-P4), but with the speed limit increased from 30mph to 100mph. The simulator will also provide the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.
 
---

### Effect of *P* component

The proportional (**P**) component depends only on the difference between the set point and the process variable. This difference is referred to as the Error term. The proportional gain (Kp) determines the ratio of output response to the error signal.

```
p_error = cte;
``` 

When only considering this component for my controller, I got the following result:

<p align="center">
<img src="./writeup_imgs/pid-P.gif" alt="car-ppc" width="350"/>
</p>

It is possible to notice that, in the very begging, the vehicle started to perform relatively well (it wasn't oscillating much and kept on track) however, because the proportional gain is too large, the process variable began to oscillate and, because Kp is increased further, the oscillations became larger and the system become unstable and eventually oscillated out of control.

<p align="center">
<img src="./writeup_imgs/P-controller.png" alt="car-ppc" width="350"/>
</p>

---

### Effect of *D* component

*Is there a way to avoid this overshoot originated by the Proportional Controller?* In PD control, we do not only take in account the proportion to Crosstrack error, but we also take the derivative of it relative to time.

<p align="center">
<img src="./writeup_imgs/PD-controller.png" alt="car-ppc" width="350"/>
</p>

```
d_error = cte - prev_cte;
```

The derivative component causes the output to decrease if the process variable is increasing rapidly and the derivative response is proportional to the rate of change of the process variable. This means that, when the car has turned enough to reduce the crosstrack error, it won’t just fo shooting for the x axis, but it will notice that it’s already reducing the error. And as the error will be becoming smaller over time, the controller can now counter steer, steering up again, allowing us to gracefully approach our target trajectory.

<p align="center">
<img src="./writeup_imgs/PD-controller-graph.png" alt="car-ppc" width="350"/>
</p>

---

### Effect of *I* component

The integral component sums the error term over time. The result is that even a small error term will cause the integral component to increase slowly. The integral response will continually increase over time unless the error is zero, so the effect is to drive the Steady-State error to zero. 

```
i_error += cte;
```

<p align="center">
<img src="./writeup_imgs/PID-controller-graph.png" alt="car-ppc" width="350"/>
</p>

---

### Hyperparameter definition

Taking into account the theory discussed about each PID component, I started tuning the values manually in order to achieve a satisfactory result (where, following the [project's rubrics](https://review.udacity.com/#!/rubrics/1972/view), no tire may leave the drivable portion of the track surface and the car may not pop up onto ledges or roll over any surfaces that would otherwise be considered unsafe if humans were in the vehicle), I got the following hyper-parameter values:

```
pid.Init(0.1, 0.001, 3.0); //(P, I, D)
```

And the final result of my PID controlling the vehicle on the simulator is: 

<p align="center">
<img src="./writeup_imgs/pid-PID.gif" alt="car-ppc" width="350"/>
</p>