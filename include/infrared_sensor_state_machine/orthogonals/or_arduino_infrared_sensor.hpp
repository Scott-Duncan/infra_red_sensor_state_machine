#ifndef OR_INFRARED_SENSOR_HPP
#define OR_INFRARED_SENSOR_HPP

#include <smacc/smacc_orthogonal.h>

#include <infrared_sensor_state_machine/clients/cl_arduino_infrared_sensor/cl_arduino_infrared_sensor.hpp>

namespace sm_infrared_sensor {

class OrArduinoInfraredSensor
    : public smacc::Orthogonal<OrArduinoInfraredSensor> {
 public:
  virtual void onInitialize() override {
    auto arduino_infrared_sensor_client =
        this->createClient<ClArduinoInfraredSensor>("/sensor_activate");
    arduino_infrared_sensor_client->initialize();
  }
};
}  // namespace sm_infrared_sensor

#endif