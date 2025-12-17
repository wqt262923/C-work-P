#include "ExecutorImpl.hpp"

#include <algorithm>
#include <memory>
#include <unordered_map>

#include "CmderFactory.hpp"
#include "Singleton.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, VehicleType vehicleType) noexcept
{
    return new (std::nothrow) ExecutorImpl(pose, vehicleType);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, VehicleType vehicleType) noexcept
    : poseHandler(pose, vehicleType), vehicleType(vehicleType)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    try {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
        std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) { cmder(poseHandler); });
    } catch (...) {
        // 捕获所有异常，确保不破坏noexcept约定
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas