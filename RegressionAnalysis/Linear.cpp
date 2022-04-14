#include "Linear.hpp"


static float GetSumXX(const Eigen::VectorXf& x, const Eigen::VectorXf& y)
{
	if (x.size() == 0 or y.size() == 0)
	{
		throw std::exception("invalid input");
	}
	const float x_sum{ x.size() - 1 / x.sum() };
	const Eigen::VectorXf x_mean{};
}