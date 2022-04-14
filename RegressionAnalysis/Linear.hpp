#ifndef LINEAR_HPP
#define LINEAR_HPP
#include <Eigen/Dense>

class Core
{
public:
	template <typename T>
	static T GetSumXX(const Eigen::VectorXf& x, const Eigen::VectorXf& y);
};

#endif // !1

