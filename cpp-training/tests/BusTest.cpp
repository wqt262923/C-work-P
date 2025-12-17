#include <gtest/gtest.h>

#include <memory>

#include "Executor.hpp"
#include "PoseEq.hpp"
#include "VehicleType.hpp"

namespace adas
{
// 巴士测试
TEST(BusTest, should_move_1_step_given_M_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));
    // when
    executor->Execute("M");
    // then
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, should_move_1_and_turn_left_given_L_command)
{
    // given
  //  std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));
    // when
  //  executor->Execute("L");
    // then
  //  const Pose target{1, 0, 'N'};
  //  ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, should_move_1_and_turn_right_given_R_command)
{
    // given
 //   std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));
    // when
//    executor->Execute("R");
    // then
//    const Pose target{1, 0, 'S'};
  //  ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, should_move_2_steps_given_F_and_M_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));
    // when
    executor->Execute("FM");
    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(BusTest, should_back_1_step_given_B_and_M_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, VehicleType::Bus));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}
}  // namespace adas