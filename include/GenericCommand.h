#pragma once

#include "Command.h"
#include <utility> //std::move
template <typename Receiver>
class GenericCommand : public Command {
public:
    explicit GenericCommand(Receiver&& receiver)
        : receiver_(std::move(receiver)) {}

    void Execute() override {
        receiver_();
    }

private:
    Receiver receiver_;
};

template <typename Receiver>
auto MakeGenericCommand(Receiver&& receiver) {
    return GenericCommand<Receiver>(std::move(receiver));
}
