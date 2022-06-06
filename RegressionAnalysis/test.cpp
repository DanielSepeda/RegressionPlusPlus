#include "test.hpp"


tempTest::tempTest()
{
	//run n tests
	this->Test1();
	this->Test2();
	this->Test3();
	this->Test4();
}



void tempTest::Test1()
{
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	DataFrame df(redwine);
	std::vector<std::string> vector_names = df.GetNames();
	assert(vector_names.size() == 12);
}

void tempTest::Test2()
{
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	DataFrame df(redwine);
	std::vector<std::string> vector_names = df.GetNames();

	Eigen::VectorXf column_vector;
	for (int i = 0; i < vector_names.size(); i++)
	{
		const std::string column_vector_name = vector_names.at(i);
		std::cout << "Column name(s)\t" << column_vector_name << std::endl;
		column_vector = df.GetVectorbyColumn(column_vector_name.c_str());
		assert(column_vector.size() == 1598);
	}
}

void tempTest::Test3()
{
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	DataFrame df(redwine);
	Eigen::VectorXf quality = df.GetVectorbyColumn("quality"); //predictor
	Eigen::VectorXf citric_acid = df.GetVectorbyColumn("citric acid"); //regressor 
	Eigen::VectorXf sulphates = df.GetVectorbyColumn("sulphates"); //regressor 
	Builder build_slm;
	std::cout << "quality value at row 1\t" << quality(1) << std::endl;
	std::cout << "sulfate value at row 1\t" << sulphates(1) << std::endl;
	SimpleLinearModel slm = build_slm.MakeSLM(sulphates, quality);
	Predictor predictor;
	const float x = 0.68f;
	std::cout << "predictor should map to ~5\t" << predictor.UseSLM(slm, x) << std::endl;

}

void tempTest::Test4()
{

	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/rocketpropellent.csv" };
	DataFrame df(redwine);
	Eigen::VectorXf age = df.GetVectorbyColumn("Age Propellent(weeks)");
	Eigen::VectorXf strength = df.GetVectorbyColumn("Shear Strength(psi)");
	Builder build_slm;
	SimpleLinearModel slm = build_slm.MakeSLM(age, strength);
	const float x = 15.50;
	Predictor predictor;
	std::cout << "EXPECT EQUAL 2051.94\t" << predictor.UseSLM(slm, x) << std::endl;
}
