#ifndef _COMMANDMANAGER_
#define _COMMANDMANAGER_

#include <stack>
#include "command.h"

typedef std::stack<std::shared_ptr<Command> >   commandStack_t;

class CommandManager {
    private:
        commandStack_t m_undo_stack;
        commandStack_t m_redo_stack;

    public:
        CommandManager() {}

        void executeCmd(Character& c, std::shared_ptr<Command> command) {
           m_redo_stack = commandStack_t();
           command->execute();
           m_undo_stack.push(command);
        }

        void undo() {
            if (m_undo_stack.size() <= 0)
                return;
            m_undo_stack.top()->undo();
            m_redo_stack.push(m_undo_stack.top());
            m_undo_stack.pop();
        }

        void redo() {
            if (m_redo_stack.size() <= 0)
                return;
            m_redo_stack.top()->redo();
            m_undo_stack.push(m_redo_stack.top());
            m_redo_stack.pop();
        }
};

#endif
