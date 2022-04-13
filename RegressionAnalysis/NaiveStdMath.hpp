#ifndef NAIvESTDMATH_HPP
#define NAIVESTDMATH_HPP
#include <vector>
#include <math.h>
#include <numeric>	
#include <stdexcept>  

class NaiveStd
{
public:
	template <typename T>
	static T mean(const std::vector<T>& _data);

};

#endif // !NAIvESTDMATH_HPP

