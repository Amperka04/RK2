#include "ChangeWebPageCommand.h"
#include "WebPageManager.h"
ChangeWebPageCommand::ChangeWebPageCommand(
    WebPageManager& pageManager, 
    std::string webPage
) : pageManager_(pageManager), webPage_(std::move(webPage)) {}

void ChangeWebPageCommand::Execute() {
    pageManager_.ChangeWebPage(webPage_);
}
