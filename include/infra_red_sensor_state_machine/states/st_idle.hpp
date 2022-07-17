#include <smacc/smacc.h>

namespace sm_infrared_sensor
{
// STATE DECLARATION
struct StActive : smacc::SmaccState<StActive, SmInfraRedSensor>
{
    using SmaccState::SmaccState;

// TRANSITION TABLE
    typedef smacc:mpl::list<
        
    smacc::Transition<EvCbSuccess<CbInfraRedSensorDetected, OrInfraRedSesor>, StActive, SUCCESS>    
    >reactions;

// STATE FUNCTIONS
    static void staticConfigure()
    {
        configure_orthogonal<OrInfraRedSensor,  CbInfraRedSensorActivate>();    
    }

    void runtimeConfigure()
    {
    }

    void onEntry()
    {
        ROS_INFO("On Entry!");
    }

    void onExit()
    {
        ROS_INFO("On Exit!");
    }
    
};
} // namespace sm_calendar_week{