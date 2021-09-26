#pragma once
#include "SABR.h"
#include "CallOption.h"
#include "MTRNG.h"

double MC_SABR(SABR SABRObj, CallOption CallOptionObj, MTRNG MTRNGObj, double steps, double paths);

double pathsNeededToMatchPrice(double eps, SABR SABRObj, CallOption CallOptionObj, MTRNG MTRNGObj, double steps);