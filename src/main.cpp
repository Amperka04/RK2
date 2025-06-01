#include "WebPageManager.h"
#include "ChangeWebPageCommand.h"
#include "GenericCommand.h"
#include "Button.h"

int main() {
    WebPageManager webPageManager;
    ChangeWebPageCommand changeCmd(webPageManager, "http://taeguk.me");
    
    Button button(&changeCmd);
    button.Click();

    auto genericCmd = MakeGenericCommand([]() {
        std::cout << "This is generic command." << std::endl;
    });
    
    button.ChangeCommand(&genericCmd);
    button.Click();
}
