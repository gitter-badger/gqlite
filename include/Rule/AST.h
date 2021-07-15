#pragma once
#include <pegtl/contrib/parse_tree.hpp>
#include "GramarRule.h"

namespace gqlite {
    namespace tpp = tao::pegtl::parse_tree;

    template< typename Rule > struct query_selector : parse_tree::selector <
        Rule
    > {};

    class AST {
    };
}