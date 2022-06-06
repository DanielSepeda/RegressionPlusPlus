#include "ReadCSV.hpp"

DataFrame::DataFrame(const std::string& input_file)
{

    this->csv_data = this->CSVtoEigen<Eigen::MatrixXf>(input_file);
    this->is_set = true;
}


template<typename M>
M DataFrame::CSVtoEigen(const std::string& input_file)
{
    csv::CSVReader reader(input_file);
    this->names = reader.get_col_names();
    //create data vector of size of column names
    std::vector<float> temp_hold;
    for (csv::CSVRow& row : reader)
    {
        for (auto& cols : row)
        {
            temp_hold.push_back(cols.get<double>());
        }
    }
    return Eigen::Map<const Eigen::Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, Eigen::RowMajor>>
        (temp_hold.data(), reader.n_rows(), temp_hold.size() / reader.n_rows());
}


std::vector<std::string> DataFrame::GetNames()
{
    if (not this->is_set)
    {
        throw std::exception("Dataframe not set");
    }
    else
    {
        return this->names;
    }
}

Eigen::VectorXf DataFrame::GetVectorbyColumn(const char* name)
{
    if (not this->is_set)
    {
        throw std::exception("Dataframe not set");
    }
    else if (this->names.empty())
    {
        throw std::exception("Column names are empty");
    }
    else
    {
        //index of interest
        uint32_t index{ 0 };
        //loop through vector of string names
        for (size_t i = 0; i < this->names.size(); i++)
        {       
            //if found
            if (this->names.at(i) == name)
            {
                return this->csv_data.col(i);
            }
        }
        throw std::exception("Cannot find column by that string name");
  
    }
}



   