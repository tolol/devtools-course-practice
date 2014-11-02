// Copyright 2014 Fedosov Alexander

#ifndef CODE_FEDOSOV_ALEXANDER_INCLUDE_LENGTHCONVERTER_HPP_
#define CODE_FEDOSOV_ALEXANDER_INCLUDE_LENGTHCONVERTER_HPP_
class LengthConverter {
 public:
    LengthConverter();
    double convertInchesToMeters(double length);
    double convertFootsToMeters(double length);
    double convertYardsToMeters(double length);
    double convertMilesToMeters(double length);

    double convertMetersToInches(double length);
    double convertFootsToInches(double length);
    double convertYardsToInches(double length);
    double convertMilesToInches(double length);

    double convertMetersToFoots(double length);
    double convertInchesToFoots(double length);
    double convertYardsToFoots(double length);
    double convertMilesToFoots(double length);

    double convertMetersToYards(double length);
    double convertInchesToYards(double length);
    double convertFootsToYards(double length);
    double convertMilesToYards(double length);

    double convertMetersToMiles(double length);
    double convertInchesToMiles(double length);
    double convertFootsToMiles(double length);
    double convertYardsToMiles(double length);

 private:
    static double checkLength(double length);
};
#endif
