#include <iostream>
#include <memory>
#include <stack>

#include "command.h"
#include "commandmanager.h"

int main() {
    CommandManager commandManager;

    bool control_loop = true;
    char command;
    Character robert("Robert");
    while (control_loop) {
                    
        std::cout << "New position: " << robert.getlastx() << ", " << robert.getlasty() <<  std::endl;
        std::cout << "Enter command ('m' move, 'u' undo, 'r' redo, 'q' quit): "
                  << std::endl;
        std::cin >> command;

        switch (command) {
            case 'm': {
                std::shared_ptr<Command> c(new MoveCommand(robert));
                commandManager.executeCmd(robert, c);
                break;
            }
            case 'u':
                commandManager.undo();
                break;
            case 'r':
                commandManager.redo();
                break;
            case 'q':
                control_loop = false;
        }
    }
    return 0;
}
