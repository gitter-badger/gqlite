#pragma once
#include <pegtl.hpp>

namespace gqlite {
    using namespace TAO_PEGTL_NAMESPACE;

    struct literal_word: ranges<'a', 'z', 'A', 'Z', '0', '9'>{};

    struct literal_nogql: sor<literal_word> {};

    struct GqliteGrammar : if_must< literal_nogql, eof> {};
}