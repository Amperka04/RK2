#include "GenericCommand.h"
#include <gtest/gtest.h>
#include <utility> //std::move

TEST(GenericCommandTest, Execute) {
    bool executed = false;
    auto lambda = [&]() { executed = true; };
    auto cmd = MakeGenericCommand(std::move(lambda)); //add move
    
    cmd.Execute();
    EXPECT_TRUE(executed);
}
