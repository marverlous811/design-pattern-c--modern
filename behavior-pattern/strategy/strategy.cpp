#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
enum class OutputFormat
{
    markdown,
    html,
};

struct ListStrategy
{
    virtual ~ListStrategy() = default;
    virtual void start(ostringstream &oss)
    {
        return;
    }
    virtual void add_list_item(ostringstream &oss, const string &item){};
    virtual void end(ostringstream &oss)
    {
        return;
    }
};

struct HtmlListStrategy : ListStrategy
{
    void start(ostringstream &oss) override
    {
        oss << "<ul>\n";
    }
    void end(ostringstream &oss) override
    {
        oss << "</ul>\n";
    }
    void add_list_item(ostringstream &oss, const string &item) override
    {
        oss << "<li>" << item << "</li>\n";
    }
};

struct MarkdownListStrategy : ListStrategy
{
    void add_list_item(ostringstream &oss, const string &item) override
    {
        oss << " * " << item << endl;
    }
};

//dynamic strategy
struct TextProcessor
{
    void append_list(const vector<string> items)
    {
        list_strategy->start(oss);
        for (auto &item : items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }
    void set_output_format(const OutputFormat format)
    {
        switch (format)
        {
        case OutputFormat::markdown:
            list_strategy = make_unique<MarkdownListStrategy>();
            break;
        case OutputFormat::html:
            list_strategy = make_unique<HtmlListStrategy>();
            break;
        default:
            break;
        }
    }

    string str()
    {
        return oss.str();
    }

    void clear()
    {
        oss.str("");
        oss.clear();
    }

private:
    ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};

//static strategy
template <typename LS>
struct TextProcessor2
{
    void append_list(const vector<string> items)
    {
        list_strategy.start(oss);
        for (auto &item : items)
            list_strategy.add_list_item(oss, item);
        list_strategy.end(oss);
    }
    string str()
    {
        return oss.str();
    }

    void clear()
    {
        oss.str("");
        oss.clear();
    }

private:
    ostringstream oss;
    LS list_strategy;
};

int main()
{
    TextProcessor tp;
    tp.set_output_format(OutputFormat::markdown);
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str() << endl;

    tp.clear();

    tp.set_output_format(OutputFormat::html);
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str() << endl;

    TextProcessor2<MarkdownListStrategy> tpm;
    tpm.append_list({"foo", "bar", "baz"});
    cout << tpm.str() << endl;

    return 0;
}