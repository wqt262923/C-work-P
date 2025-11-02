#include <gtest/gtest.h>

#include "Executor.hpp"
#include "PoseEq.hpp"

namespace adas
{

TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_back_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{-1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{1, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_minus_1_given_status_is_back_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{0, -1, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_y_plus_1_given_status_is_back_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    // when
    executor->Execute("BM");
    // then
    const Pose target{0, 1, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_S_given_status_is_back_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_W_given_status_is_back_command_is_L_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_N_given_status_is_back_command_is_L_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_E_given_status_is_back_command_is_L_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BL");
    // then
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_N_given_status_is_back_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_W_given_status_is_back_command_is_R_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_S_given_status_is_back_command_is_R_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_face_E_given_status_is_back_command_is_R_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    // when
    executor->Execute("BR");
    // then
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

// B&F叠加状态测试用例
TEST(ExecutorReverseTest, should_return_x_minus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFM");
    // then
    const Pose target{-2, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_minus_1_and_face_S_given_status_is_back_and_fast_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFL");
    // then
    const Pose target{-1, 0, 'S'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_return_x_minus_1_and_face_N_given_status_is_back_and_fast_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when
    executor->Execute("BFR");
    // then
    const Pose target{-1, 0, 'N'};
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorReverseTest, should_cancel_back_status_given_double_B_commands)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    // when - 第一次B进入倒车状态，第二次B取消倒车状态
    executor->Execute("BBM");
    // then - 应该正常前进，不是后退
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(target, executor->Query());
}

}  // namespace adas