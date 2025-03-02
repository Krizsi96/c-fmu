#include <stdio.h>
#include "fmi2Functions.h"

typedef struct
{
    double time;
    double output;
} ModelData;

static ModelData model;

fmi2Component fmi2Instantiate(
    fmi2String instance_name,
    fmi2Type fmu_type,
    fmi2String fmu_guid,
    fmi2String fmu_resource_location,
    const fmi2CallbackFunctions* functions,
    fmi2Boolean visible,
    fmi2Boolean logging_on
)
{
    printf("FMU instantiated: %s\n", instance_name);
    model.time = 0.0;
    model.output = 1.0;

    return &model;
}

fmi2Status fmi2DoStep(
    fmi2Component component,
    fmi2Real current_commication_point,
    fmi2Real communication_step_size,
    fmi2Boolean no_set_fmu_state_prior_to_current_point
)
{
    ModelData* model = (ModelData*)component;
    model->time += communication_step_size;
    model->output = 1.0;
    return fmi2OK;
}

fmi2Status fmi2GetReal(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    fmi2Real value[]
)
{
    ModelData* m = (ModelData*)component;
    if (number_of_value_references > 0)
    {
        value[0] = m->output;
    }
    return fmi2OK;
}

void fmi2FreeInstance(fmi2Component component)
{
    printf("FMU instance freed.\n");
}

const char* fmi2GetTypesPlatform(void)
{
    return fmi2TypesPlatform;
}

const char* fmi2GetVersion(void)
{
    return fmi2Version;
}

fmi2Status fmi2SetDebugLogging(
    fmi2Component component,
    fmi2Boolean logging_on,
    size_t number_of_categories,
    const fmi2String categories[]
)
{
    return fmi2OK;
}

fmi2Status fmi2SetupExperiment(
    fmi2Component component,
    fmi2Boolean tolerance_defined,
    fmi2Real tolerance,
    fmi2Real start_time,
    fmi2Boolean stop_time_defined,
    fmi2Real stop_time
)
{
    return fmi2OK;
}

fmi2Status fmi2EnterInitializationMode(fmi2Component component)
{
    return fmi2OK;
}

fmi2Status fmi2ExitInitializationMode(fmi2Component component)
{
    return fmi2OK;
}

fmi2Status fmi2Terminate(fmi2Component component)
{
    return fmi2OK;
}

fmi2Status fmi2Reset(fmi2Component component)
{
    return fmi2OK;
}

fmi2Status fmi2GetInteger(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    fmi2Integer value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2GetBoolean(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    fmi2Boolean value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2GetString(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    fmi2String value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2SetReal(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    const fmi2Real value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2SetInteger(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    const fmi2Integer value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2SetBoolean(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    const fmi2Boolean value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2SetString(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    const fmi2String value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2SetRealInputDerivatives(
    fmi2Component component,
    const fmi2ValueReference value_reference[],
    size_t number_of_value_references,
    const fmi2Integer order[],
    const fmi2Real value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2GetRealOutputDerivatives(
    fmi2Component c,
    const fmi2ValueReference vr[],
    size_t nvr,
    const fmi2Integer order[],
    fmi2Real value[]
)
{
    return fmi2OK;
}

fmi2Status fmi2CancelStep(fmi2Component c)
{
    return fmi2OK;
}

fmi2Status fmi2GetStatus(
    fmi2Component c,
    const fmi2StatusKind s,
    fmi2Status* value
)
{
    return fmi2OK;
}

fmi2Status fmi2GetRealStatus(
    fmi2Component c,
    const fmi2StatusKind s,
    fmi2Real* value
)
{
    return fmi2OK;
}

fmi2Status fmi2GetIntegerStatus(
    fmi2Component c,
    const fmi2StatusKind s,
    fmi2Integer* value
)
{
    return fmi2OK;
}

fmi2Status fmi2GetBooleanStatus(
    fmi2Component c,
    const fmi2StatusKind s,
    fmi2Boolean* value
)
{
    return fmi2OK;
}

fmi2Status fmi2GetStringStatus(
    fmi2Component c,
    const fmi2StatusKind s,
    fmi2String* value
)
{
    return fmi2OK;
}

