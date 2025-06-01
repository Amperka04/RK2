#include "Button.h"

Button::Button(Command* command) : command_(command) {}

void Button::Click() {
    if (command_) {
        command_->Execute();
    }
}

Command* Button::ChangeCommand(Command* command) {
    Command* old = command_;
    command_ = command;
    return old;
}
