#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"
#include "VehicleType.hpp"

namespace adas
{
using Cmder = std::function<void(PoseHandler& poseHandler)>;
using CmderList = std::list<Cmder>;

class CmderFactory final
{
public:
    // 移除noexcept，让编译器自动处理异常规范
    CmderFactory() = default;
    ~CmderFactory() = default;

    CmderFactory(const CmderFactory&) = delete;
    CmderFactory& operator=(const CmderFactory&) = delete;

public:
    CmderList GetCmders(const std::string& commands) const;

private:
    // 初始化map，这里可能会抛出异常（如内存分配失败）
    const std::unordered_map<char, Cmder> cmderMap{
        {'M', MoveCommand()}, {'L', TurnLeftCommand()}, {'R', TurnRightCommand()},
        {'F', FastCommand()}, {'B', ReverseCommand()},
    };
};
}  // namespace adas