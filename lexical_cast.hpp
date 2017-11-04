#ifndef LIFT_LEXICAL_CAST_INCLUDED
#define LIFT_LEXICAL_CAST_INCLUDED

namespace lift
{
    template <typename T> T lexical_cast();
    template <typename T> T lexical_cast(const std::string&);
    template <typename T> T lexical_cast(const T&, const T&);

    template <typename T> T lexical_cast() {
        std::cout << "Please enter a valid input: ";
        std::string input;
        std::cin >> input;

        return lexical_cast<T>(input);
    }

    template <typename T> T lexical_cast(const std::string& input) {
        std::istringstream parser(input);
        T result;
        parser >> result;

        //  TODO: Why does parser.good() make it work? <2017-11-04, Pratik B.>
        return ( parser.good() || parser.fail() ) ? lexical_cast<T>() : result;
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
