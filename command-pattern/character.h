#ifndef _CHARACTER_
#define _CHARACTER_

#include <string>

struct Character {
    int m_last_x = 0;
    int m_last_y = 0;
    std::string m_name;

    Character(std::string name) : m_name(name) {}
    int getlastx() { return m_last_x; }
    int getlasty() { return m_last_y; }
    void move(int x, int y) {
        m_last_x = x;
        m_last_y = y;
    }
};

#endif
