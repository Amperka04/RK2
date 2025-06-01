#pragma once
#include "Command.h"

class Button {
public:
    explicit Button(Command* command);
    void Click();
    Command* ChangeCommand(Command* command);

private:
    Command* command_;
};
