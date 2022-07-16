#include <smacc/smacc.h>

namespace sm_calendar_week
{
// STATE DECLARATION
struct StActive : smacc::SmaccState<StActive, SmInfraRedSensor>
{
    using SmaccState::SmaccState;

// TRANSITION TABLE
    typedef mpl::list<
        
    Transition<EvKeyPressN<CbDefaultKeyboardBehavior, OrKeyboard>, MsWeekend, PREEMPT>,
    
    >reactions;

// STATE FUNCTIONS
    static void staticConfigure()
    {
        configure_orthogonal<OrInfraRedSensor,  CbInfraRedSensorListening>(5);    
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
} // namespace sm_calendar_week