#include "Linear.hpp"

void SimpleLinearModel::operator=(const SimpleLinearModel& slm)
{
	this->beta_hat_0 = slm.beta_hat_0;
	this->beta_hat_1 = slm.beta_hat_1;
}

//template <typename T>
float Predictor::UseSLM(const SimpleLinearModel& slm, const float x)
{
	float estimated_y = slm.beta_hat_0 + (slm.beta_hat_1 * x);
	return estimated_y;
}

SimpleLinearModel Builder::MakeSLM(const Eigen::VectorXf& x, const Eigen::VectorXf& y)
{
	if (x.size() == 0 or y.size() == 0)
	{
		throw std::exception("invalid input x or y have length 0");
	}
	else if (x.size() not_eq y.size())
	{
		throw std::exception("x size not equal y size");
	}
	
	SimpleLinearModel slm;

	const float x_mean{ x.sum() / (x.size() - 1) };

	const float y_mean{ y.sum() / (y.size() - 1) };
	
	slm.beta_hat_1 = this->BetaHat1(x, y);
	
	slm.beta_hat_0 = this->BetaHat0(slm.beta_hat_1, y_mean, x_mean);

	return slm;
}


/*
*	@brief Sxx is the corrected sum of squares of x 
*	@param x indicator
*	@param y observed value
	@return the corrected sum of squares for x
*/
float Builder::Sxx(const Eigen::VectorXf& x)
{
	if (x.size() == 0 )
	{
		throw std::exception("invalid input");
	}
	else
	{
		//No op
	}
	/*this implentation uses the Sum of x^2 - (the Sum of all x )^2 / n*/
	const float sum_xx{ (x.transpose() * x).sum() };
	const float mean_sum_x_squared{ (x.sum() * x.sum()) / x.size() };
	const float s_xx{ sum_xx - mean_sum_x_squared };

	return s_xx;
}

/*
* @brief the corrected sum of cross products of x and y
* @param x indicator
* @param y observed value
* @return the corrected cross products of x and y
*
*/
float Builder::Sxy(const Eigen::VectorXf& x, const Eigen::VectorXf& y)
{
	if (x.size() == 0 or y.size() == 0)
	{
		throw std::exception("invalid input x or y have length 0");
	}
	else if (x.size() not_eq y.size())
	{
		throw std::exception("x size not equal y size");
	}
	else
	{
		//No op
	}
	
	/* this implementaion uses (x dot y)^2 minus (sum x * sum y)/n */
	const float sum_xy = (x.transpose() * y).sum();

	const float sum_x_sum_y_n=  (x.sum() * y.sum()) / x.size();
	
	const float s_xy{ sum_xy - sum_x_sum_y_n };
	
	return s_xy;
}

/*
* @brief Beta Hat 1
*  @param x indicator
*  @param y observed value
*  @return BetaHat1 (equivlently the slope)
*/
float Builder::BetaHat1(const Eigen::VectorXf& x, const Eigen::VectorXf& y)
{
	if (x.size() == 0 or y.size() == 0)
	{
		throw std::exception("invalid input x or y have length 0");
	}
	else if (x.size() not_eq y.size())
	{
		throw std::exception("x size not equal y size");
	}
	else
	{
		//No op
	}

	const float beta_hat_1 = this->Sxx(x) / this->Sxy(x,y);
	return beta_hat_1;
}

/*
** @brief 
* 
*/
float Builder::BetaHat0(const float beta_hat_1, const float mean_y, const float mean_x)
{
	const float beta_hat_0{ mean_y - (beta_hat_1 * mean_x) };
	return beta_hat_0;
}