#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "command.h"

MoveCommand::MoveCommand(Character& c) : m_ch(&c) {}

void MoveCommand::execute(){
    srand(time(NULL));
    int randomx = rand() % 10;
    int randomy = rand() % 10;   
    m_x = randomx;
    m_y = randomy;
    m_old_x = m_ch->getlastx();
    m_old_y = m_ch->getlasty();
    m_ch->move(m_x, m_y);
    std::cout << "Move command" << std::endl;
};

void MoveCommand::undo(){
    m_ch->move(m_old_x, m_old_y);
    std::cout << "Undo command" << std::endl;
};

void MoveCommand::redo(){
    m_ch->move( m_x, m_y );
    std::cout << "Redo command" << std::endl;
}
