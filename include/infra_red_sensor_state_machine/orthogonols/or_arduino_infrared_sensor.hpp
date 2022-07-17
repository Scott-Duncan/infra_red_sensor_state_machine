#ifndef OR_INFRARED_SENSOR_HPP
#define PR_INFRARED_SENSOR_HPP

#include <smacc/smacc_orthogonals.h>

namespace sm_infrared_sensor
{
class OrArduinoInfraredSensor : public smacc::Orthogonal<OrArduinoInfraredSensor>
{
public:
    virtual void onInitialize() override
    {
    }
};
} // namespace sm_atomic

#endif