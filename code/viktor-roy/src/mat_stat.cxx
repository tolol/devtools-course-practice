// Copyright 2014 Roy Viktor
#include <../include/mat_stat.hpp>
mat_stat::mat_stat() {}
int mat_stat::expectedValue(const double *statisticValues,
                            const double *probabilityValues,
                            const int countValues,
                            double &result) {
    if ((statisticValues == 0) || (probabilityValues == 0) ||
          (countValues == 0)) {
            return 1;
          }
    double localExpectedValue = 0.0;
    for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
        localExpectedValue += statisticValues[valueNumber] *
                              probabilityValues[valueNumber];
    }
    result = localExpectedValue;
    return 0;
}
int mat_stat::variance(const double *statisticValues,
                       const double *probabilityValues,
                       const int countValues,
                       double &result) {
  if ((statisticValues == 0) || (probabilityValues == 0) ||
    (countValues == 0)) {
      return 1;
    }
  double localVariance = 0;
  double expectedSqrValue = 0;
  double sqrtOfExpectedValue;
  expectedValue(statisticValues, probabilityValues, countValues,
                                             sqrtOfExpectedValue);
  for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
      expectedSqrValue += statisticValues[valueNumber] *
                          statisticValues[valueNumber] *
                          probabilityValues[valueNumber];
  }
  localVariance = expectedSqrValue - sqrtOfExpectedValue * sqrtOfExpectedValue;
  result = localVariance;
  return 0;
}


mat_stat::~mat_stat() {
}
