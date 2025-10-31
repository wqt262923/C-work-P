#pragma once
#include "ExecutorImpl.hpp"
namespace adas
{
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
};

