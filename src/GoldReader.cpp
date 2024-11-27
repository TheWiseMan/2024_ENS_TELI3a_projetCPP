#include "./GoldReader.hpp"

using namespace std;

map<string, string> GoldReader::parseObject(string textToParse)
{
    map<string, string> output;
    size_t reference = 0;
    while (reference < textToParse.size())
    {
        size_t current_keyval_sep = textToParse.find("::", reference);
        size_t next_keyval_sep = textToParse.find("::", current_keyval_sep + 2);
        if (next_keyval_sep == string::npos)
        {
            string key_string = textToParse.substr(reference, current_keyval_sep - reference);
            string val_string = textToParse.substr(current_keyval_sep + 2);
            output[key_string] = val_string;
            break;
        }
        size_t keyval_end = textToParse.rfind("\n", next_keyval_sep);
        string key_string = textToParse.substr(reference, current_keyval_sep - reference);
        string val_string = textToParse.substr(current_keyval_sep + 2, keyval_end - current_keyval_sep - 2);
        output[key_string] = val_string;
        reference = keyval_end + 1;
    }
    return output;
}

list<map<string, string>> GoldReader::parseList(string textToParse)
{
    list<map<string, string>> output;

    size_t reference = 0;
    size_t block_end = textToParse.find("\n----\n");
    while (block_end != string::npos)
    {
        if (block_end)
        output.push_back(parseObject(textToParse.substr(reference, block_end)));
        reference = block_end+6;
        block_end = textToParse.find("\n----\n", reference);
    }
    output.push_back(parseObject(textToParse.substr(reference)));

    return output;
}