#pragma once
#include "Command.h"
#include "WebPageManager.h"
#include <utility> //move
class ChangeWebPageCommand : public Command {
public:
    ChangeWebPageCommand(WebPageManager& pageManager, std::string webPage);
    void Execute() override;

private:
    WebPageManager& pageManager_;
    std::string webPage_;
};
