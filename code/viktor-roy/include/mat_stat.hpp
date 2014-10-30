// Copyright 2014 Roy Viktor
#pragma pack(push, 1)
class mat_stat {
 private:
    double *statisticValues_;    // статистическая выборка
    double *probabilityValues_;  // вероятность
    int countStatisticValues_;   // размер выборки

 public:
    mat_stat();
    mat_stat(const mat_stat &l);
    mat_stat & operator=(const mat_stat &l);
    void setValues(const double *statisticValues,
                   const double *probabilityValues,
                   const int countStatisticValues);
    void getValues(double *statisticValues,
                   double *probabilityValues,
                   int &countStatisticValues);
    // подсчет мат ожидания
    double expectedValue(const double *statisticValues,
                         const double *probabilityValues,
                         const int countStatisticValues);
    // подсчет дисперсии
    double variance(const double *statisticValues,
                     const double *probabilityValues,
                     const int countStatisticValues);
    ~mat_stat();
};
#pragma pack(pop)
