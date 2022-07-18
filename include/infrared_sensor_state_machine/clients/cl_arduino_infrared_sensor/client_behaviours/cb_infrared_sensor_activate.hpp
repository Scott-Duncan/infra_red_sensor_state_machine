#ifndef CB_INFRARED_SENSOR_ACTIVATE_HPP
#define CB_INFRARED_SENSOR_ACTIVATE_HPP

#include <smacc/smacc_client_behavior.h>

#include <infrared_sensor_state_machine/clients/cl_arduino_infrared_sensor/cl_arduino_infrared_sensor.hpp>

namespace sm_infrared_sensor {
template <typename TSource, typename TOrthogonal>
struct EvSensorActivated : sc::event<EvSensorActivated<TSource, TOrthogonal>> {
};

class CbInfraredSensorActivated : public smacc::SmaccClientBehavior {
 public:
  void onEntry() override {
    ClArduinoInfraredSensor* cl_arduino_infrared_sensor;
    this->requiresClient(cl_arduino_infrared_sensor);
    assert(cl_arduino_infrared_sensor != nullptr && "ClRfid == nullptr");
    cl_arduino_infrared_sensor->onMessageReceived(
        &CbInfraredSensorActivated::onMessageReceived, this);
  }

  void onMessageReceived(const std_msgs::String& msg) { sensorActivated(); }

  template <typename TOrthogonal, typename TSourceObject>
  void onOrthogonalAllocation() {
    sensorActivated = [this]() {
      ROS_INFO("Sensor Activated");
      auto ev = new EvSensorActivated<TSourceObject, TOrthogonal>();
      this->postEvent(ev);
    };
  }

 private:
  std::function<void()> sensorActivated;
};
}  // namespace sm_infrared_sensor

#endif