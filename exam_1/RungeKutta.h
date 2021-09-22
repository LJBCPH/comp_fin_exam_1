#pragma once
#include "Vasicek.h"
double rungeKutta(double r_, double kappa_, double theta_, double sigma_, double T_, double step_length_);

double rungeKutta(Vasicek VasicekObject);

double rungeKuttaCir(double r_, double kappa_, double theta_, double sigma_, double T_, double step_length_);