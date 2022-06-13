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

  prev_cte = 0.0;

  // counter = 0;
  // errorSum = 0.0;
  // minError = std::numeric_limits<double>::max();
  // maxError = std::numeric_limits<double>::min();

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;

  i_error += cte;

  d_error = cte - prev_cte;
  prev_cte = cte;

  // errorSum += cte;
  // counter++;

  // if (cte > maxError){
  //   maxError = cte;
  // }
  // if (cte < minError){
  //   minError = cte;
  // }

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double total_error = p_error * Kp + i_error * Ki + d_error * Kd;
  return total_error;  // TODO: Add your total error calc here!
}

// double PID::MinError() {
//   return minError;
// }

// double PID::MaxError() {
//   return maxError;
// }