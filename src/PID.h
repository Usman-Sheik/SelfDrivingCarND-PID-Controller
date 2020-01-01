#ifndef PID_H
#define PID_H

#include <limits>
#include <vector>

class PID {
public:
  /**
   * Constructor
   */
  PID(int controller_size);

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

private:
  static constexpr int kPIndex{0};
  static constexpr int kIIndex{1};
  static constexpr int kDIndex{2};
  /**
   * PID Errors
   */
  std::vector<double> pid_errors_{};

  /**
   * PID Coefficients
   */
  std::vector<double> pid_coefficients_{};
  double best_error_{std::numeric_limits<double>::max()};
  std::size_t step_{0};
  double previous_cte_{0.};
};

#endif // PID_H
