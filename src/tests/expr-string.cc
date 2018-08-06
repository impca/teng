/*
 * Teng -- a general purpose templating engine.
 * Copyright (C) 2004  Seznam.cz, a.s.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Seznam.cz, a.s.
 * Naskove 1, Praha 5, 15000, Czech Republic
 * http://www.seznam.cz, mailto:teng@firma.seznam.cz
 *
 *
 * $Id: $
 *
 * DESCRIPTION
 * Teng engine -- Teng expressions tests.
 *
 * AUTHORS
 * Michal Bukovsky <michal.bukovsky@firma.seznam.cz>
 *
 * HISTORY
 * 2018-06-07  (burlog)
 *             Created.
 */

#include <teng.h>

#include "catch.hpp"
#include "utils.h"

SCENARIO(
    "Numeric operator does not work for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("three", "(three)");

        WHEN("The == operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three == '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 21},
                    "Runtime: left operand of == numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The != operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three != '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 21},
                    "Runtime: left operand of == numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The <= operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three <= '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 21},
                    "Runtime: left operand of > numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The < operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three < '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 20},
                    "Runtime: left operand of >= numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The > operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three > '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 20},
                    "Runtime: left operand of > numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The >= operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three >= '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 21},
                    "Runtime: left operand of >= numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The | operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three | '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 20},
                    "Runtime: left operand of | numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The ^ operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three ^ '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 20},
                    "Runtime: left operand of ^ numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }

        WHEN("The & operator is applied on strings") {
            Teng::Error_t err;
            auto result = g(err, "${three & '(three)'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 20},
                    "Runtime: left operand of & numeric operator "
                    "is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "String =~ operator",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("two", "(two)");
        root.addVariable("three", "(three)");
        root.addVariable("tri", "(three)");

        WHEN("Variables with same value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${three =~ tri}", root);

            THEN("Result of: three =~ tri") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "1");
            }
        }

        WHEN("Variables with different value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${three =~ two}", root);

            THEN("Result of: three =~ two") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "0");
            }
        }

        WHEN("Variable and literal with same value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${'(three)' =~ three}", root);

            THEN("Result of: '(three)' =~ three") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "1");
            }
        }

        WHEN("Variable and literal with different value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${three =~ '(two)'}", root);

            THEN("Result of: three =~ '(two)'") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "0");
            }
        }
    }
}

SCENARIO(
    "String !~ operator",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("two", "(two)");
        root.addVariable("three", "(three)");
        root.addVariable("tri", "(three)");

        WHEN("Variables with same value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${three !~ tri}", root);

            THEN("Result of: three !~ tri") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "0");
            }
        }

        WHEN("Variables with different value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${three !~ two}", root);

            THEN("Result of: three !~ two") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "1");
            }
        }

        WHEN("Variable and literal with same value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${'(three)' !~ three}", root);

            THEN("Result of: '(three)' !~ three") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "0");
            }
        }

        WHEN("Variable and literal with different value are compared") {
            Teng::Error_t err;
            auto result = g(err, "${three !~ '(two)'}", root);

            THEN("Result of: three !~ '(two)'") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "1");
            }
        }
    }
}

SCENARIO(
    "Logic OR operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "");
        root.addVariable("nula", "");
        root.addVariable("three", "(three)");

        WHEN("The operator is applied to variables with same value") {
            Teng::Error_t err;
            auto result = g(err, "${zero || nula}", root);

            THEN("Result of: zero || nula") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "");
            }
        }

        WHEN("The operator is applied to variables with different value") {
            Teng::Error_t err;
            auto result = g(err, "${three || zero}", root);

            THEN("Result of: three || zero") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "(three)");
            }
        }

        WHEN("The operator is applied to variable and literal") {
            Teng::Error_t err;
            auto result = g(err, "${'' || three}", root);

            THEN("Result of: '' == three") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "(three)");
            }
        }

        WHEN("The operator is applied to variable and literal") {
            Teng::Error_t err;
            auto result = g(err, "${three || ''}", root);

            THEN("Result of: three || ''") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "(three)");
            }
        }
    }
}

SCENARIO(
    "Logic AND operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "");
        root.addVariable("nula", "");
        root.addVariable("three", "(three)");

        WHEN("The operator is applied to variables with same value") {
            Teng::Error_t err;
            auto result = g(err, "${zero && nula}", root);

            THEN("Result of: zero && nula") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "");
            }
        }

        WHEN("The operator is applied to variables with different value") {
            Teng::Error_t err;
            auto result = g(err, "${three && zero}", root);

            THEN("Result of: three && zero") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "");
            }
        }

        WHEN("The operator is applied to variable and literal") {
            Teng::Error_t err;
            auto result = g(err, "${'' && three}", root);

            THEN("Result of: '' && three") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "");
            }
        }

        WHEN("The operator is applied to variable and literal") {
            Teng::Error_t err;
            auto result = g(err, "${three && 'abc'}", root);

            THEN("Result of: three && 'abc'") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "abc");
            }
        }
    }
}

SCENARIO(
    "The ADD operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", "3");

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero + three}", root);

            THEN("Result of: zero + three") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 15},
                    "Runtime: left operand of + numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The SUB operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", "3");

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero - three}", root);

            THEN("Result of: zero - three") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 15},
                    "Runtime: left operand of - numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The CONCAT operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", "3");

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero ++ three}", root);

            THEN("Result is concatenation of strings") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "03");
            }
        }

        WHEN("The operator is applied to variable and empty string literal") {
            Teng::Error_t err;
            auto result = g(err, "${'' ++ three}", root);

            THEN("Result is concatenation of strings") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "3");
            }
        }
    }
}

SCENARIO(
    "The MUL operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", "3");

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero * three}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 15},
                    "Runtime: left operand of * numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The DIV operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", "3");

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero / three}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 15},
                    "Runtime: left operand of / numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The MOD operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", "3");

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero % three}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 15},
                    "Runtime: left operand of % numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The REPEAT operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");
        root.addVariable("three", 3);

        WHEN("The operator is applied to variables") {
            Teng::Error_t err;
            auto result = g(err, "${zero ** three}", root);

            THEN("Result of: zero ** three") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "000");
            }
        }

        WHEN("The right operand is not int") {
            Teng::Error_t err;
            auto result = g(err, "${zero ** 'hi'}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 15},
                    "Runtime: Right operand of repeat string operator "
                    "is not int"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The NOT operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("empty", "");
        root.addVariable("three", "3");

        WHEN("The operator is applied to empty") {
            Teng::Error_t err;
            auto result = g(err, "${!empty}", root);

            THEN("Result of: !empty") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "1");
            }
        }

        WHEN("The operator is applied to three") {
            Teng::Error_t err;
            auto result = g(err, "${!three}", root);

            THEN("Result of: !three") {
                std::vector<Teng::Error_t::Entry_t> errs;
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "0");
            }
        }
    }
}

SCENARIO(
    "The BIT_NOT operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");

        WHEN("The operator is applied to zero") {
            Teng::Error_t err;
            auto result = g(err, "${~zero}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 8},
                    "Runtime: operand of bit ~ operation is not int"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The unary SUB operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");

        WHEN("The operator is applied to zero") {
            Teng::Error_t err;
            auto result = g(err, "${-zero}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 8},
                    "Runtime: right operand of - numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}

SCENARIO(
    "The unary ADD operator for strings",
    "[string][expr]"
) {
    GIVEN("Some variables in root frag set to strings") {
        Teng::Fragment_t root;
        root.addVariable("zero", "0");

        WHEN("The operator is applied to zero") {
            Teng::Error_t err;
            auto result = g(err, "${+zero}", root);

            THEN("Result is undefined") {
                std::vector<Teng::Error_t::Entry_t> errs = {{
                    Teng::Error_t::ERROR,
                    {1, 8},
                    "Runtime: right operand of + numeric operator is string"
                }};
                REQUIRE(err.getEntries() == errs);
                REQUIRE(result == "undefined");
            }
        }
    }
}


