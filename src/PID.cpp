
#include <cmath>
#include <iostream>
#include <numeric>

#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

static constexpr double kErrorTolerance{0.0001};

PID::PID(int controller_size)
    : pid_errors_(controller_size, 0.), pid_coefficients_(controller_size, 0.) {
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  pid_coefficients_[kPIndex] = Kp_;
  pid_coefficients_[kIIndex] = Ki_;
  pid_coefficients_[kDIndex] = Kd_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  if (!step_) {
    previous_cte_ = cte;
  }

  pid_errors_[kPIndex] = cte;
  pid_errors_[kDIndex] = cte - previous_cte_;
  pid_errors_[kIIndex] += cte;

  previous_cte_ = cte;
  step_++;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return -pid_coefficients_[kPIndex] * pid_errors_[kPIndex] -
         pid_coefficients_[kDIndex] * pid_errors_[kDIndex] -
         pid_coefficients_[kIIndex] * pid_errors_[kIIndex];
}
