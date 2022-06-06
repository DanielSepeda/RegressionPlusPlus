#ifndef LINEAR_HPP
#define LINEAR_HPP
#include <Eigen/Dense>
#include <iostream>


struct SimpleLinearModel
{
	float beta_hat_0;
	float beta_hat_1;
	void operator = (const SimpleLinearModel& slm);
};

class Predictor {
public:
	//template <typename T>
	float UseSLM(const SimpleLinearModel& slm, const float x);
};

class Builder
{
public:
	SimpleLinearModel MakeSLM(const Eigen::VectorXf& x, const Eigen::VectorXf& y);
private:
	float Sxx(const Eigen::VectorXf& x);
	float Sxy(const Eigen::VectorXf& x, const Eigen::VectorXf& y);
	float BetaHat1(const Eigen::VectorXf& x, const Eigen::VectorXf& y);
	float BetaHat0(const float beta_hat1, const float mean_y, const float mean_x);
};

#endif // !1

