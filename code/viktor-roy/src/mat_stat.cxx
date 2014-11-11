// Copyright 2014 Roy Viktor
#include <../include/mat_stat.hpp>
#include <vector>
mat_stat::mat_stat() {
}
double mat_stat::expectedValue(const double *statisticValues,
                               const double *probabilityValues,
                               const int countValues) {
    if ((statisticValues == 0) || (probabilityValues == 0) ||
        (countValues == 0)) {
          return 0;
        }
    double localExpectedValue = 0.0;
    for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
        localExpectedValue += statisticValues[valueNumber] *
                              probabilityValues[valueNumber];
    }
    return localExpectedValue;
}
double mat_stat::variance(const double *statisticValues,
                          const double *probabilityValues,
                          const int countValues) {
  if ((statisticValues == 0) || (probabilityValues == 0) ||
    (countValues == 0)) {
      return 0;
    }
  double localVariance = 0;
  double expectedSqrValue = 0;
  double sqrtOfExpectedValue = expectedValue(statisticValues,
                                             probabilityValues,
                                             countValues);
  for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
      expectedSqrValue += statisticValues[valueNumber] *
                          statisticValues[valueNumber] *
                          probabilityValues[valueNumber];
  }
  localVariance = expectedSqrValue - sqrtOfExpectedValue * sqrtOfExpectedValue;
  return localVariance;
}


mat_stat::~mat_stat() {
}
