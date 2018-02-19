#ifndef LIFT_SOFT_LEXICAL_CAST_INCLUDED
#define LIFT_SOFT_LEXICAL_CAST_INCLUDED

#include <iostream>
#include <sstream>
#include <string>

namespace lift
{
    template <typename T> T soft_lexical_cast();
    template <typename T, typename S> T soft_lexical_cast(const S&);

    template <typename T>
    T soft_lexical_cast() {
        return soft_lexical_cast<T>( std::string() );
    }

    template <typename T, typename S>
    T soft_lexical_cast(const S& source) {
        std::stringstream parser;
        parser << source;

        T result;
        parser >> result;

        // parser.good() for mixed valid and invalid characters. If removed, the
        // input "1a2b" would not loop and would instead return 1.
        std::string input;
        while ( parser.fail() || parser.good() ) {
            parser.clear();

            std::cout << "Please enter a valid input: ";
            std::cin >> input;

            parser.str(input);
            parser >> result;
        }

        return result;
    }
}

#endif // LIFT_SOFT_LEXICAL_CAST_INCLUDED
