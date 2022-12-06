#include <iostream>
#include "strategy.h"
#include "textprocessor.h"

int main() {

    TextProcessor tp;
    tp.set_output_format(Format::Markdown);
    tp.append_list({"foo", "bar", "baz"});
    std::cout << tp.str() << std::endl;

    tp.clear();
    tp.set_output_format(Format::HTML);
    tp.append_list({"foo", "bar", "baz"});
    std::cout << tp.str() << std::endl;
    return 0;
}
