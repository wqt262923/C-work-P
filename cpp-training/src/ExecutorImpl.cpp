#include "ExecutorImpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : pose(pose)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
     for (char command : commands) 
     {
        switch (command) 
        {
            case 'M': // 前进指令
                switch (pose.heading) 
                {
                    case 'E': pose.x += 1; break; // 向东移动
                    case 'W': pose.x -= 1; break; // 向西移动  
                    case 'N': pose.y += 1; break; // 向北移动
                    case 'S': pose.y -= 1; break; // 向南移动
                }
                break;
            case 'L': // 左转指令
                switch (pose.heading) 
                {
                    case 'E': pose.heading = 'N'; break;
                    case 'N': pose.heading = 'W'; break;
                    case 'W': pose.heading = 'S'; break;
                    case 'S': pose.heading = 'E'; break;
                }
                break;
            case 'R': //右转指令
                switch (pose.heading) 
                {
                    case 'E': pose.heading = 'S'; break;
                    case 'S': pose.heading = 'W'; break;
                    case 'W': pose.heading = 'N'; break;
                    case 'N': pose.heading = 'E'; break;
                }
                break;
        }
    }
}
Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
} // namespace adas
