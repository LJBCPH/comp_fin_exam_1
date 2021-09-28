#pragma once
#include "Vasicek.h"
#include "ZeroCouponBond.h"
double rungeKutta(const double r_, const double kappa_, const double theta_, const double sigma_, const double T_, const double step_length_);

double rungeKutta(Vasicek VasicekObject);

double rungeKutta(Vasicek VasicekObject, ZeroCouponBond ZeroCouponBondObject);

double BFunctionVasicek(const double kappa_, const double B);

double AFunctionVasicek(const double kappa_, const double theta_, const double B, const double sigma_);

double rungeKuttaCir(const double r_, const double kappa_, const double theta_, const double sigma_, const double T_, const double step_length_);

double BFunctionCir(const double kappa_, const double B, const double sigma_);

double AFunctionCir(const double kappa_, const double theta_, const double B);