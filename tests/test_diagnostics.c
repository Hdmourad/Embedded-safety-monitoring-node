#include "diagnostics.h"

#include <math.h>
#include <stdio.h>

static int check(
    const char *name,
    diagnostic_state_t actual,
    diagnostic_state_t expected)
{
    if (actual != expected)
    {
        printf("FAIL: %s\n", name);
        return 1;
    }

    printf("PASS: %s\n", name);
    return 0;
}

int main(void)
{
    int failures = 0;

    failures += check(
        "Normal temperature",
        diagnostics_evaluate_temperature(50.0, 70.0, 80.0),
        DIAGNOSTIC_NORMAL
    );

    failures += check(
        "Warning threshold",
        diagnostics_evaluate_temperature(70.0, 70.0, 80.0),
        DIAGNOSTIC_WARNING
    );

    failures += check(
        "Alert threshold",
        diagnostics_evaluate_temperature(80.0, 70.0, 80.0),
        DIAGNOSTIC_ALERT
    );

    failures += check(
        "Invalid thresholds",
        diagnostics_evaluate_temperature(50.0, 80.0, 70.0),
        DIAGNOSTIC_INVALID
    );

    failures += check(
        "NaN temperature",
        diagnostics_evaluate_temperature(NAN, 70.0, 80.0),
        DIAGNOSTIC_INVALID
    );

    if (failures > 0)
    {
        printf("%d test(s) failed.\n", failures);
        return 1;
    }

    printf("All diagnostic tests passed.\n");
    return 0;
}
