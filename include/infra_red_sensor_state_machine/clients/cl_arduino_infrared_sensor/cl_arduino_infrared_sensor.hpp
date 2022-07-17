
#ifndef CL_ARDUINO_INFRARED_SENSOR_HPP
#define CL_ARDUINO_INFRARED_SENSOR_HPP

#include <smacc/client_bases/smacc_subscriber_client.h>
#include <std_msgs/String.h>

class ClArduinoInfraredSensor 
: public smacc::client_bases::SmaccSubscriberClient<
                   std_msgs::String> {
 public:
  ClArduinoInfraredSensor(const std::string& topic_name)
      : SmaccSubscriberClient<std_msgs::String>(topic_name) {}
};


#endif  // CL_PRELOAD_H
