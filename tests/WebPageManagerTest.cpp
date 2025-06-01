#include "WebPageManager.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(WebPageManagerTest, ChangeWebPage) {
    WebPageManager manager;
    std::stringstream buffer;
    
    // Перенаправляем cout
    auto old_buf = std::cout.rdbuf(buffer.rdbuf());
    manager.ChangeWebPage("http://test.com");
    std::cout.rdbuf(old_buf);
    
    EXPECT_EQ(buffer.str(), "Change web page to http://test.com.\n");
}
