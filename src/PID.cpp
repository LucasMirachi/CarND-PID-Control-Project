#include "PID.h"
#include "json.hpp"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  PID::p_error = 0.0;
  PID::i_error = 0.0;
  PID::d_error = 0.0;

  double prev_cte = 0.0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  d_error = cte - prev_cte; //derivative error
  
  p_error = cte; //proportional error

  i_error += cte; //integral error
    
  prev_cte = cte; //update previous error

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_error = - Kp * p_error - Ki * i_error - Kd * d_error;
  return total_error;  
}
