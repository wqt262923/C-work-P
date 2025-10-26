#pragma once
#include "Executor.hpp"
namespace adas
{
    class ExecutorImpl final : public Executor
    {
    public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;
        ExecutorImpl(const ExecutorImpl&) = delete;
        ExecutorImpl& operator=(const ExecutorImpl&) = delete;
    public:
        void Execute(const std::string& command) noexcept override;
        Pose Query(void) const noexcept override;
    private:
         class ICommand
        {
        public:
            virtual ~ICommand() = default;
            virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
        };
        //move指令
        class MoveCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                if (executor.IsFast()) {
                executor.Move();
                }
                executor.Move();
            }
        };
        //左转指令
        class TurnLeftCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                if (executor.IsFast()) {
                executor.Move();
                }
                executor.TurnLeft();
            }
        };
        //右转指令
        class TurnRightCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                if (executor.IsFast()) {
                executor.Move();
                }
                executor.TurnRight();
            }
        };
        //F指令功能代码实现：FastCommand类建立
        class FastCommand final : public ICommand
        {
        public:
             void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                executor.Fast();
            }
        };
        void Move(void) noexcept;
        void TurnRight(void) noexcept;
        void TurnLeft(void) noexcept;
        void Fast(void) noexcept;
        bool IsFast(void) const noexcept;
    private:
        Pose pose;
        bool fast{false};
    };

void ExecutorImpl::Fast() noexcept
{
fast = !fast;
}
bool ExecutorImpl::IsFast() const noexcept
{
return fast;
}

} // namespace adas
