#include <smacc/smacc.h>

namespace sm_atomic
{
class OrInfraRedSensor : public smacc::Orthogonal<OrInfraRedSensor>
{
public:
    virtual void onInitialize() override
    {
        auto client = this->createClient<cl_ros_timer::ClRosTimer>(ros::Duration(1));
        client->initialize();
    }
};
} // namespace sm_atomic