// Copyright 2014 Roy Viktor
#include <vector>
#pragma pack(push, 1)
class mat_stat {
 public:
    mat_stat();
    mat_stat(const mat_stat &l);
    mat_stat & operator=(const mat_stat &l);
    int expectedValue(const double *statisticValues,
                      const double *probabilityValues,
                      const int countValues,
                      double &expectedValue);
    int variance(const double *statisticValues,
                 const double *probabilityValues,
                 const int countValues,
                 double &variance);
    ~mat_stat();
};
#pragma pack(pop)
