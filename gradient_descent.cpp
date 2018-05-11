#include "gradient_descent.h"
#include<bits/stdc++.h>
using namespace std;

void dataset::populate_data(string location,long int no_rows,long int no_columns)
{
ifstream fin(location);
if(fin.is_open())
{
while(!fin.eof())
{
long int count_c=0;
long int count_r=0;
double temp;
if(count_c!=no_columns-1)
{
getline(fin,temp,',');
f_data[count_r].push_back(temp);
count_c++;
}
if(count_c==no_columns-1)
{
getline(fin,temp,'\n');
r_data.push_back(temp);
count_r++;
count_c=0;
f_data.push_back(std::vector<int>());
}
}
}
else
{
cout<<"could not open the file!";
}
}

vector<double> hypothesis::cost_calculation(dataset data)
{
vector<double> h_thetha;
for(int i=0;i<data.f_data.size();i++)
{
h_thetha.push_back(inner_product(thetha.begin(),thetha.end(),data.f_data[i].begin(),0);
}
return h_thetha;
}

void hypothesis::check(double epsilon)
{
if(abs(jn1-jn2)<=epsilon)
{
check_flag=true;
}
}




void hypothesis::grad_descent()
{
vector<double> h_thetha;
h_thetha=hypothesis::cost_calculation(data);
vector<double> j_thetha;
std::transform(h_thetha.begin(),h_thetha.end(),data.r_data.begin(),j_thetha.begin(),std::minus<int>());
vector<double> inter(j_thetha);
std::transform(j_thetha.begin(),j_thetha.end(),j_thetha.begin(), j_thetha.begin(), multiplies<double>());
jn1=std::accumulate(j_thetha.begin(), j_thetha.end(), 0);
jn1=jn1/(2*data.f_data.size());




check_flag=false;
while(check_flag==false)
{jn1=jn2;

for(long int i=0;i<thetha.size();i++)
{
double sum=0;
for(long int j=0;j<data.f_data.size();j++)
{
sum=sum+(inter[j]*data.f_data[j][i]);
}
thetha[i]=thetha[i]-(alpha*(sum));
}

h_thetha.clear();
h_thetha=hypothesis::cost_calculation(data);
j_thetha.clear();
std::transform(h_thetha.begin(),h_thetha.end(),data.r_data.begin(),j_thetha.begin(),std::minus<int>());
inter.clear();
inter(j_thetha);
std::transform(j_thetha.begin(),j_thetha.end(),j_thetha.begin(), j_thetha.begin(), multiplies<double>());
jn2=std::accumulate(j_thetha.begin(), j_thetha.end(), 0);
jn2=jn2/(2*data.f_data.size());
check(eps);
}

