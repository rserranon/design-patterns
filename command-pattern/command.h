#ifndef _COMMAND_
#define _COMMAND_

#include <stack>
#include "character.h"

class Command {
    public:
        virtual ~Command(){}
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual void redo() = 0;
};

class MoveCommand: public Command {
    public:
        MoveCommand(Character& c);
        void execute();
        void undo();
        void redo();

        Character *m_ch;
        int m_x;
        int m_y;
        int m_old_x = 0;
        int m_old_y = 0;
};

#endif
