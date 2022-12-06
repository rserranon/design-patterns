#ifndef _STRATEGY_
#define _STRATEGY_


#include <string>
#include <sstream>

enum class Format { Markdown, HTML };

struct ListStrategy {
   ListStrategy() {};
   virtual ~ListStrategy() = default;
   virtual void add_list_item(std::ostringstream& oss, const std::string& item) = 0;
   virtual void start(std::ostringstream& os) {};
   virtual void end(std::ostringstream& os){};
};

struct MarkdownListStrategy: public ListStrategy {
    void add_list_item(std::ostringstream& oss, const std::string& item);
};

struct HTMLListStrategy: public ListStrategy {
    void add_list_item(std::ostringstream& oss, const std::string& item);
    void start(std::ostringstream& oss);
    void end(std::ostringstream& oss);
};

#endif
