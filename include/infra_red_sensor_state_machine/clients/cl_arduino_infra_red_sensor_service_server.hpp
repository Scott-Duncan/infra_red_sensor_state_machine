#include <smacc/client_bases/smacc_service_server_client.h>

namespace fox_rt {
class ClArduinoInfraResSensorServiceServer
    : public smacc::client_bases::SmaccServiceServerClient<ros_srvs::Empty> {
  using ServiceT = fox_rt_msgs::SetName;

 public:
  ClArduinoINfraRedSersorServiceServer(const std::string& service_name)
      : smacc::client_bases::SmaccServiceServerClient<ServiceT>(service_name) {}
};
}  // namespace fox_rt

#endif