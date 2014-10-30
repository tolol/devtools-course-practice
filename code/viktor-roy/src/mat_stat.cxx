// Copyright 2014 Roy Viktor
#include <../include/mat_stat.hpp>
mat_stat::mat_stat() : statisticValues_(), probabilityValues_(),
                                           countStatisticValues_(0) {
    countStatisticValues_ = 0;
    statisticValues_ = new double[countStatisticValues_];
    probabilityValues_ = new double[countStatisticValues_];
}
void mat_stat::setValues(const double *statisticValues,
                         const double *probabilityValues,
                         const int countValues) {
  countStatisticValues_ = countValues;
  statisticValues_ = new double[countStatisticValues_];
  probabilityValues_ = new double[countStatisticValues_];
  for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
      statisticValues_[valueNumber] = statisticValues[valueNumber];
      probabilityValues_[valueNumber] = probabilityValues[valueNumber];
  }
}
void mat_stat::getValues(double *statisticValues,
                         double *probabilityValues,
                         int &countValues) {
  countValues = countStatisticValues_;
  for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
      statisticValues[valueNumber] = statisticValues_[valueNumber];
      probabilityValues[valueNumber] = probabilityValues_[valueNumber];
  }
}
// подсчет мат ожидания
double mat_stat::expectedValue(const double *statisticValues,
                               const double *probabilityValues,
                               const int countValues) {
    double localExpectedValue = 0.0;
    for ( int valueNumber = 0; valueNumber < countValues; valueNumber++ ) {
        localExpectedValue += statisticValues[valueNumber] *
                              probabilityValues[valueNumber];
    }
    return localExpectedValue;
}
// подсчет дисперсии
double mat_stat::variance(const double *statisticValues,
                          const double *probabilityValues,
                          const int countValues) {
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
    delete [] statisticValues_;
    delete [] probabilityValues_;
}
