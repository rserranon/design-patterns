#include <sstream> 
#include <vector>
#include <memory>
#include "strategy.h"

struct TextProcessor {
    void clear() {
        m_oss.str("");
        m_oss.clear();
    }
    void append_list(const std::vector<std::string>& items){
        m_list_strategy->start(m_oss);
        for (auto& item: items)
            m_list_strategy->add_list_item(m_oss, item);
        m_list_strategy->end(m_oss);
    }

    void set_output_format(const Format& format) {
        switch(format){
            case Format::Markdown:
                m_list_strategy = std::make_unique<MarkdownListStrategy>();
                break;
            case Format::HTML:
                m_list_strategy = std::make_unique<HTMLListStrategy>();
                break;
        }
    }

    std::string str() { return m_oss.str(); }

    private:
        std::ostringstream   m_oss;  
        std::unique_ptr<ListStrategy> m_list_strategy;

};
