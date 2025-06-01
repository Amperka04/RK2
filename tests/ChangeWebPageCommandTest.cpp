#include "ChangeWebPageCommand.h"
#include "WebPageManager.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(ChangeWebPageCommandTest, Execute) {
    WebPageManager manager;
    ChangeWebPageCommand cmd(manager, "http://command.com");
    std::stringstream buffer;
    
    auto old_buf = std::cout.rdbuf(buffer.rdbuf());
    cmd.Execute();
    std::cout.rdbuf(old_buf);
    
    EXPECT_EQ(buffer.str(), "Change web page to http://command.com.\n");
}
