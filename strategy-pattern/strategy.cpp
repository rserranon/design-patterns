#include "strategy.h"

void MarkdownListStrategy::add_list_item(std::ostringstream& oss, const std::string& item) {
    oss << " - " << item << std::endl;
}

void HTMLListStrategy::start(std::ostringstream &oss) {
    oss << "<ul>" << std::endl;
}
void HTMLListStrategy::end(std::ostringstream &oss) {
    oss << "</ul>" << std::endl;
}

void HTMLListStrategy::add_list_item(std::ostringstream& oss, const std::string& item) {

    oss << "\t<li>" << item << "\t</li>" << std::endl;
}

 
