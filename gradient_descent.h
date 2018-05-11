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

};

class hypothesis {
vector<double> thetha;
double jn1, jn2;
bool check_flag;
public:
hypothesis(long int no_of_features)
{
for(long int i=0;i<no_of_features;i++)
{
thetha.push_back(0);
}
jn1=0;jn2=10000001;
check_flag=false;
};

vector<double> cost_calculation(dataset data);
void grad_descent(long int alpha);
bool check(long int epsilon);
};

#endif
