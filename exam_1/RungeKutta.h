#pragma once
#include "Vasicek.h"
#include "ZeroCouponBond.h"
double rungeKutta(double r_, double kappa_, double theta_, double sigma_, double T_, double step_length_);

double rungeKutta(Vasicek VasicekObject);

double rungeKutta(Vasicek VasicekObject, ZeroCouponBond ZeroCouponBondObject);

double BFunctionVasicek(double kappa_, double B);

double AFunctionVasicek(double kappa_, double theta_, double B, double sigma_);

double rungeKuttaCir(double r_, double kappa_, double theta_, double sigma_, double T_, double step_length_);