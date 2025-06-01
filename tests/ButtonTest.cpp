#include "Button.h"
#include "Command.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h> //mock

using ::testing::_;

// Mock-команда для тестирования
class MockCommand : public Command {
public:
    MOCK_METHOD0(Execute, void());  // MOCK_METHO
};

TEST(ButtonTest, Click) {
    MockCommand mock;
    Button button(&mock);
    
    EXPECT_CALL(mock, Execute()).Times(1);
    button.Click();
}

TEST(ButtonTest, ChangeCommand) {
    MockCommand mock1, mock2;
    Button button(&mock1);
    
    EXPECT_CALL(mock1, Execute()).Times(1);
    button.Click();
    
    Command* old = button.ChangeCommand(&mock2);
    EXPECT_EQ(old, &mock1);
    
    EXPECT_CALL(mock2, Execute()).Times(1);
    button.Click();
}
