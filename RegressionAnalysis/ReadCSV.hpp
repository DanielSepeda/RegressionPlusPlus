#ifndef READ_CSV
#define READ_CSV
#include "csv.hpp"
#include <Eigen/Dense>
#include <vector>


class DataFrame {
    public:
        void ReadData(const std::string& input_file);
        void SetMatrix(const Eigen::MatrixXf& M);
        std::vector<std::string> GetNames();
        Eigen::VectorXf GetVectorbyColumn(const char* name);
    private:
        Eigen::MatrixXf csv_data;
        std::vector<std::string> names;
        bool is_set{ false };

        template<typename M>
        M CSVtoEigen(const std::string& input_file)
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

};

class Reader {
public:
	void Read(const std::string& input_file);

    /**
    * @brief returns a generic Mat type which represents the csv data
    * @param input_file the path to the csv file
    * @return M Eigen::Matrix
    */
    template<typename M>
    M CSVtoEigen(const std::string& input_file)
    {
        csv::CSVReader reader(input_file);
        std::vector<std::string> col_names = reader.get_col_names();
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

};






#endif READ_CSV