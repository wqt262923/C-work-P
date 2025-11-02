#include "ExecutorImpl.hpp"
#include <memory>
#include "Command.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose);
}
ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose)
{
}
void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands) 
    {
        std::unique_ptr<ICommand> cmder;
        if (cmd == 'M') {
            //Move();
            cmder = std::make_unique<MoveCommand>();
        } 
        else if (cmd == 'L') {
            //TurnLeft();
            cmder = std::make_unique<TurnLeftCommand>();
        } 
        else if (cmd == 'R') {
            //TurnRight();
            cmder = std::make_unique<TurnRightCommand>();
        }
        else if (cmd == 'F') {
            cmder = std::make_unique<FastCommand>();
        }

        if(cmder){
            cmder->DoOperate(poseHandler);
        }
    }

    
}
Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
} // namespace adas
