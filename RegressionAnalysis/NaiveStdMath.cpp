#include "NaiveStdMath.hpp"

template <typename T>
static T NaiveStd::mean(const std::vector<T>& _data)
{
	if (_data.empty)
	{
		throw std::invalid_argument("DATA EMPTY");
	}
	const T sum{ std::accumulate(_data.begin,_data.end,0) };
	const T output{ sum / (_data.size() - 1) };
	return output;
}
