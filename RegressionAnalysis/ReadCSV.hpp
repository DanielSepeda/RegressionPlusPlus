#ifndef READ_CSV
#define READ_CSV
#include "csv.hpp"
#include <Eigen/Dense>
#include <vector>


class DataFrame {
    public:
        std::vector<std::string> GetNames();
        Eigen::VectorXf GetVectorbyColumn(const char* name);
        DataFrame(const std::string& input_file);
    private:
        //matrix representing csv_data
        Eigen::MatrixXf csv_data;
        //vector of string names to each column vector in matrix
        std::vector<std::string> names;
        //if the data frame object is initialized with a matrix
        bool is_set{ false };

        template<typename M>
        M CSVtoEigen(const std::string& input_file);

};



#endif READ_CSV