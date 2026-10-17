#include "diagnostics.h"

#include <math.h>

diagnostic_state_t diagnostics_evaluate_temperature(
    double temperature_celsius,
    double warning_threshold,
    double alert_threshold)
{
    if (!isfinite(temperature_celsius)
        || !isfinite(warning_threshold)
        || !isfinite(alert_threshold)
        || warning_threshold >= alert_threshold)
    {
        return DIAGNOSTIC_INVALID;
    }

    if (temperature_celsius >= alert_threshold)
    {
        return DIAGNOSTIC_ALERT;
    }

    if (temperature_celsius >= warning_threshold)
    {
        return DIAGNOSTIC_WARNING;
    }

    return DIAGNOSTIC_NORMAL;
}
