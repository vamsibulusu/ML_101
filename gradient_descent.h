#include<vector>
#include<string>
#ifndef gradient_descent_H
#define gradient_descent_H

using namespace std;


class dataset {
public:
vector< vector<double> > f_data;//feature data
vector<double> r_data;//result data
void populate_data(string location,long int no_rows,long int no_columns);
long int no_rows();

};

class hypothesis {
public:
vector<double> thetha,h_thetha,j_thetha;
double jn1, jn2;
bool check_flag;
void check(double epsilon);
void cost_calculation(dataset& data,long int row);
vector<double> grad_descent(double alpha,double epsilon,dataset& data,long int rows, long int columns);
};

#endif
