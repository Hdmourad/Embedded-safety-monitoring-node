#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    DIAGNOSTIC_NORMAL,
    DIAGNOSTIC_WARNING,
    DIAGNOSTIC_ALERT,
    DIAGNOSTIC_INVALID
} diagnostic_state_t;

diagnostic_state_t diagnostics_evaluate_temperature(
    double temperature_celsius,
    double warning_threshold,
    double alert_threshold
);

#ifdef __cplusplus
}
#endif

#endif
