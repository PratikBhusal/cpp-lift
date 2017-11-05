#ifndef LIFT_LEXICAL_CAST_INCLUDED
#define LIFT_LEXICAL_CAST_INCLUDED

#include <iostream>
#include <sstream>
#include <string>

namespace lift
{
    template <typename T> T lexical_cast();
    template <typename T> T lexical_cast(std::string);
    template <typename T> T lexical_cast(const T&, const T&);

    template <typename T> T lexical_cast() {
        return lexical_cast<T>( std::string() );
    }

    template <typename T> T lexical_cast(std::string input) {
        std::stringstream parser(input);
        T result;
        parser >> result;

        // parser.good() for mixed valid and invalid characters. If removed, the
        // input "1a2b" would not loop and would instead return 1.
        while ( parser.fail() || parser.good() ) {
            // input.clear(); // Do I need this?
            parser.str( std::string() );
            parser.clear();

            std::cout << "Please enter a valid input: ";
            std::cin >> input;

            parser.str(input);
            parser >> result;
        }

        return result;
    }

    template <typename T> T lexical_cast(const T& min, const T& max) {
        T result;

        do {
            result = lexical_cast<T>();
        } while (result < min || result > max);

        return result;
    }
}

#endif // LIFT_LEXICAL_CAST_INCLUDED
